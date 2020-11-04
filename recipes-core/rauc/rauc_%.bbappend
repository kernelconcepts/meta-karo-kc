FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

#install service that unlocks env on boot
#note that this service is highly device dependant
SRC_URI_append_tx8m-1620 = " \
                  file://uboot-env-unlock.service \
                 "

do_install_append_tx8m-1620() {
	install -m 0644 ${WORKDIR}/uboot-env-unlock.service ${D}${systemd_unitdir}/system/
}

PACKAGES_tx8m-1620 += " ${PN}-uboot-env-unlock "
FILES_${PN}-uboot-env-unlock = " ${systemd_unitdir}/system/ "
SYSTEMD_SERVICE_${PN}-uboot-env-unlock = " uboot-env-unlock.service "
SYSTEMD_PACKAGES_tx8m-1620 += " ${PN}-uboot-env-unlock "
RDEPENDS_${PN}-uboot-env-unlock.service = "systemd"
#RRECOMMENDS_${PN}_append_tx8m-1620 = " ${PN}-uboot-env-unlock"

#tar is needed to install updates
RDEPENDS_${PN} += " \
                    tar \
	                gzip \
                  "

