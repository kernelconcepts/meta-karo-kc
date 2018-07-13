# revert commit fb66d5010363083ea8d84160b74c62dad67f9a13 im meta-freescale

SRC_URI = "${FSL_MIRROR}/xserver-xorg-video-imx-viv-${PV}.tar.gz \
            file://rc.autohdmi"
SRC_URI[md5sum] = "8acbdddd51c9b1b0fd25137eeabd786d"
SRC_URI[sha256sum] = "3eed38193e31bb5ba8d2c817bd9b4f6e2fe7540d2cab36de9098cb4f11946a9f" 
S = "${WORKDIR}/xserver-xorg-video-imx-viv-${PV}/"