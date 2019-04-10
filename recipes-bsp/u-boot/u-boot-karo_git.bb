require recipes-bsp/u-boot/u-boot.inc

DESCRIPTION = "Das U-Boot for Ka-Ro electronics TX Computer-On-Modules."
LICENSE = "GPLv2+"
LIC_FILES_CHKSUM = "file://Licenses/README;md5=0507cd7da8e7ad6d6701926ec9b84c95"

PV = "v2015.10-rc2+git${SRCPV}"

SRCREV = "63652ce377ee8ce60a6217aefe238313d0989c60"
SRCBRANCH = "master"

SRC_URI = "git://github.com/karo-electronics/karo-tx-uboot.git;branch=${SRCBRANCH} \
           file://mx6-soc-l2en.patch \
           file://mx6-clock-div.patch \
           file://0001-Disable-Werror-for-default-build-useless-for-all-oth.patch \
           file://0001-u-boot-merge-u-boot-use-packed-structure-for-net.patch \
"

S = "${WORKDIR}/git"

PACKAGE_ARCH = "${MACHINE_ARCH}"

COMPATIBLE_MACHINE  = "(tx6[qsu]-.*|txul-.*|imx6.*-tx.*)"

do_configure_append() {
    cp ${S}/include/linux/compiler-gcc5.h ${S}/include/linux/compiler-gcc6.h 
    cp ${S}/include/linux/compiler-gcc5.h ${S}/include/linux/compiler-gcc7.h 
}

# enable Hush shell per default
do_configure_prepend () {
	cfgfile=$( echo ${UBOOT_MACHINE} | sed 's/_config/_defconfig/g' )
	echo CFGFIILE $cfgfile
	echo "CONFIG_HUSH_PARSER=y" >> ${S}/configs/${cfgfile}
	echo "CONFIG_SYS_HUSH_PARSER=y" >> ${S}/configs/${cfgfile}
}
