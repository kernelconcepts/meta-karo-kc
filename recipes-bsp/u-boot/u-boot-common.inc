require u-boot-env.inc
inherit pythonnative

DEPENDS_append = " python dtc-native"

LICENSE = "GPLv2+"
LIC_FILES_CHKSUM = "file://Licenses/gpl-2.0.txt;md5=b234ee4d69f5fce4486a80fdaf4a4263"

S = "${WORKDIR}/git"

inherit fsl-u-boot-localversion

LOCALVERSION ?= "-${SRCBRANCH}"

PACKAGE_ARCH = "${MACHINE_ARCH}"

# enable Hush shell per default
do_configure_prepend () {
	cfgfile=$( echo ${UBOOT_MACHINE} | sed 's/_config/_defconfig/g' )
	echo CFGFIILE $cfgfile
	echo "CONFIG_HUSH_PARSER=y" >> ${S}/configs/${cfgfile}
	echo "CONFIG_SYS_HUSH_PARSER=y" >> ${S}/configs/${cfgfile}
}
