FILESEXTRAPATHS_prepend := "${THISDIR}/linux-karo:"

SRC_URI += " \
			file://bootlogo.png \
"

do_configure_prepend () {
    # convert and copy custom logo
	pngtopnm ${WORKDIR}/bootlogo.png | ppmquant 224 | pnmnoraw > ${WORKDIR}/bootlogo.ppm

    if [ -e ${WORKDIR}/bootlogo.ppm ]; then
        install -m 0644 ${WORKDIR}/bootlogo.ppm ${S}/drivers/video/logo/logo_linux_clut224.ppm
        kernel_conf_variable LOGO y
        kernel_conf_variable LOGO_LINUX_CLUT224 y
	else
		echo Error: Logo conversion failed
		exit 1
    fi
}

MACHINE_USES_VIVANTE_KERNEL_DRIVER_MODULE = "1"

