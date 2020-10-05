FILESEXTRAPATHS_prepend := "${THISDIR}/env:"

SRC_URI_append = " file://env.txt"

do_deploy_append () {
	cp ${WORKDIR}/env.txt ${DEPLOY_DIR_IMAGE}/u-boot-${MACHINE}.env
}
