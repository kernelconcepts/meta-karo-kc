SUMMARY = "Linux Kernel for Ka-Ro electronics TX6 Computer-On-Modules"

require recipes-kernel/linux/linux-imx.inc

DEPENDS += "lzop-native bc-native"

SRCBRANCH = "linux-4.14.y"
SRCREV = "v4.14.24"
KERNEL_SRC = "git://git.kernel.org/pub/scm/linux/kernel/git/stable/linux-stable.git"
FILESEXTRAPATHS_prepend := "${THISDIR}/${BP}/patches:${THISDIR}/${BP}:"

SRC_URI = "${KERNEL_SRC};branch=${SRCBRANCH} \
           file://defconfig \
           ${@bb.utils.contains('KERNEL_FEATURES',"wifi","file://cfg/wifi.cfg","",d)} \
           ${@bb.utils.contains('KERNEL_FEATURES',"debian","file://cfg/debian.cfg","",d)} \
           file://0001-patch-for-edt-m12.diff \
           file://0002-karo-dtbs.patch \
           file://imx6ull-bugfix.patch \
           file://txul-phy-reset.patch \
           file://txul-enet-sleep.patch \
           file://fec-enet-reset.patch \
           file://busformat-override.patch \
           file://pixclk-polarity-override.patch \
           file://display-support.patch \
"

LOCALVERSION = "-stable"
KERNEL_IMAGETYPE = "uImage"

KERNEL_FEATURES_append = "${@bb.utils.contains('DISTRO_FEATURES',"wifi"," wifi","",d)}"

COMPATIBLE_MACHINE  = "(tx6[qsu]-.*|txul-.*|imx6.*-tx.*)"

# returns all the elements from the src uri that are .cfg files
def find_cfgs(d):
    sources=src_patches(d, True)
    sources_list=[]
    for s in sources:
        if s.endswith('.cfg'):
            sources_list.append(s)

    return sources_list

do_configure_prepend () {
    for f in ${@" ".join(find_cfgs(d))};do
        cat $f >> ${B}/.config
    done

    cp -r ${THISDIR}/${P}/dts/* ${S}/arch/arm/boot/dts/
}

do_install_append () {
    set -x
    install -v -d -m 0755 ${D}${FW_PATH}
    for f in ${FW_FILES};do
        src="${f//file:\//${WORKDIR}}"
        subdir="$(dirname "${src##*/firmware/}")"
        [ "${subdir##/*}" = "$subdir" ] || exit 1
        if [ "$subdir" != "." ];then
                install -v -d -m 0755 "${D}${FW_PATH}/$subdir"
        fi
        install -v -m 0644 "${src}" "${D}${FW_PATH}/$subdir"
    done
}

# prefer for mainline bsp
DEFAULT_PREFERENCE = "-1"
DEFAULT_PREFERENCE_use-mainline-bsp = "1"
