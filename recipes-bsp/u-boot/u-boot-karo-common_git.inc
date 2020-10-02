require u-boot-common.inc

PV = "v2015.10-rc2+git${SRCPV}"

SRCREV = "63652ce377ee8ce60a6217aefe238313d0989c60"
SRCBRANCH = "master"

SRC_URI = "git://github.com/karo-electronics/karo-tx-uboot.git;branch=${SRCBRANCH} \
           file://mx6-soc-l2en.patch \
           file://mx6-clock-div.patch \
           file://0001-Disable-Werror-for-default-build-useless-for-all-oth.patch \
           file://0001-u-boot-merge-u-boot-use-packed-structure-for-net.patch \
"

COMPATIBLE_MACHINE  = "(tx6[qsu]-.*|txul-.*|imx6.*-tx.*)"

do_configure_append() {
    cp ${S}/include/linux/compiler-gcc5.h ${S}/include/linux/compiler-gcc6.h 
    cp ${S}/include/linux/compiler-gcc5.h ${S}/include/linux/compiler-gcc7.h 
    cp ${S}/include/linux/compiler-gcc5.h ${S}/include/linux/compiler-gcc8.h 
    cp ${S}/include/linux/compiler-gcc5.h ${S}/include/linux/compiler-gcc9.h 
}
