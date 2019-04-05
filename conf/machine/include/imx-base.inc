# Provides the i.MX common settings
# Based on imx-base.inc from meta-freescale
# Reduced to minimum requirements to make use of the NXP BSP

# Set specific make target and binary suffix

PREFERRED_PROVIDER_virtual/xserver ??= "xserver-xorg"
XSERVER_DRIVER ??= "xf86-video-fbdev"
XSERVER_DRIVER_imxgpu2d ??= "xf86-video-imx-vivante"
XSERVER_DRIVER_vf ??= "xf86-video-modesetting"
XSERVER_DRIVER_use-mainline-bsp ??= "xf86-video-armada"
XSERVER ??= "xserver-xorg \
           xf86-input-evdev \
           ${XSERVER_DRIVER}"

INHERIT += "machine-overrides-extender"

MACHINEOVERRIDES_EXTENDER_mx25   = "use-mainline-bsp"
MACHINEOVERRIDES_EXTENDER_mx6q   = "imxfbdev:imxipu:imxvpu:imxgpu:imxgpu2d:imxgpu3d"
MACHINEOVERRIDES_EXTENDER_mx6dl  = "imxfbdev:imxpxp:imxipu:imxvpu:imxgpu:imxgpu2d:imxgpu3d:imxepdc"
MACHINEOVERRIDES_EXTENDER_mx6sx  = "imxfbdev:imxpxp:imxgpu:imxgpu2d:imxgpu3d"
MACHINEOVERRIDES_EXTENDER_mx6sl  = "imxfbdev:imxpxp:imxgpu:imxgpu2d:imxepdc"
MACHINEOVERRIDES_EXTENDER_mx6sll = "imxfbdev:imxpxp:imxepdc"
MACHINEOVERRIDES_EXTENDER_mx6ul  = "imxfbdev:imxpxp"
MACHINEOVERRIDES_EXTENDER_mx6ull = "imxfbdev:imxpxp:imxepdc"
MACHINEOVERRIDES_EXTENDER_mx7d   = "imxfbdev:imxpxp:imxepdc"
MACHINEOVERRIDES_EXTENDER_mx7ulp = "imxfbdev:imxpxp:imxgpu:imxgpu2d:imxgpu3d"
MACHINEOVERRIDES_EXTENDER_mx8qm  = "imxdrm:imxdpu:imxgpu:imxgpu2d:imxgpu3d"
MACHINEOVERRIDES_EXTENDER_mx8mm  = "imxdrm:imxvpu:imxgpu:imxgpu2d:imxgpu3d"
MACHINEOVERRIDES_EXTENDER_mx8mq  = "imxdrm:imxvpu:imxgpu:imxgpu3d"
MACHINEOVERRIDES_EXTENDER_mx8qxp = "imxdrm:imxdpu:imxgpu:imxgpu2d:imxgpu3d"

MACHINEOVERRIDES_EXTENDER_FILTER_OUT_use-mainline-bsp = " \
    mx6 \
    mx6q \
    mx6dl \
    mx6sx \
    mx6sl \
    mx6sll \
    mx6ul \
    mx6ull \
    \
    mx7 \
    mx7d \
    mx7ulp \
    \
    mx8 \
    mx8qm \
    mx8mm \
    mx8mq \
    mx8qxp \
"

# Sub-architecture support
MACHINE_SOCARCH_SUFFIX ?= ""
MACHINE_SOCARCH_SUFFIX_mx23 = "-mxs"
MACHINE_SOCARCH_SUFFIX_mx28 = "-mxs"
MACHINE_SOCARCH_SUFFIX_mx51 = "-mx5"
MACHINE_SOCARCH_SUFFIX_mx53 = "-mx5"
MACHINE_SOCARCH_SUFFIX_mx6q = "-mx6qdl"
MACHINE_SOCARCH_SUFFIX_mx6dl = "-mx6qdl"
MACHINE_SOCARCH_SUFFIX_mx6sx = "-mx6sx"
MACHINE_SOCARCH_SUFFIX_mx6sl = "-mx6sl"
MACHINE_SOCARCH_SUFFIX_mx6sll= "-mx6sll"
MACHINE_SOCARCH_SUFFIX_mx7d = "-mx7d"
MACHINE_SOCARCH_SUFFIX_mx7ulp = "-mx7ulp"
MACHINE_SOCARCH_SUFFIX_vf60 = "-vf60"
MACHINE_SOCARCH_SUFFIX_vf50 = "-vf50"
MACHINE_SOCARCH_SUFFIX_mx6ul  = "-mx6ul"
MACHINE_SOCARCH_SUFFIX_mx6ull = "-mx6ul"
MACHINE_SOCARCH_SUFFIX_mx8qm  = "-mx8"
MACHINE_SOCARCH_SUFFIX_mx8mm  = "-mx8mm"
MACHINE_SOCARCH_SUFFIX_mx8mq  = "-mx8m"
MACHINE_SOCARCH_SUFFIX_mx8qxp = "-mx8"
MACHINE_SOCARCH_SUFFIX_use-mainline-bsp = "-imx"

MACHINE_ARCH_FILTER = "virtual/kernel"
MACHINE_SOCARCH_FILTER_append_imx = " \
    alsa-lib \
    weston \
"
MACHINE_SOCARCH_FILTER_append_imxvpu = " \
    imx-codec \
    imx-parser \
    imx-vpuwrap \
    libimxvpuapi \
    virtual/imxvpu \
"
MACHINE_SOCARCH_FILTER_append_imxgpu = " \
    virtual/egl \
    virtual/mesa \
    virtual/libopenvg \
    libdrm \
    cairo \
    gstreamer1.0-plugins-bad \
    libgal-imx \
    pango \
"
MACHINE_SOCARCH_FILTER_append_imxgpu2d = " \
    virtual/libg2d \
"
MACHINE_SOCARCH_FILTER_append_imxgpu3d = " \
    virtual/libgl \
    virtual/libgles1 \
    virtual/libgles2 \
"
MACHINE_SOCARCH_FILTER_append_use-mainline-bsp = " \
    virtual/egl \
    virtual/libopenvg \
    virtual/libg2d \
    virtual/libgl \
    virtual/libgles1 \
    virtual/libgles2 \
    virtual/mesa \
    cairo \
    pango \
    qtbase \
"
MACHINE_SOCARCH_FILTER_append_mx6q = " \
    virtual/opencl-icd \
    opencl-headers \
"
MACHINE_SOCARCH_FILTER_append_mx8 = " \
    virtual/opencl-icd \
    opencl-headers \
"
MACHINE_SOCARCH_FILTER_append_mx8qm = " \
    virtual/libopenvx \
"

INHERIT += "fsl-dynamic-packagearch"

SIGGEN_EXCLUDE_SAFE_RECIPE_DEPS_append = " \
    imx-gpu-viv->kernel-module-imx-gpu-viv \
    libimxvpuapi->virtual/imxvpu \
    imx-vpuwrap->virtual/imxvpu \
    imx-codec->virtual/imxvpu \
    imx-test->virtual/imxvpu \
"

# Firmware
MACHINE_FIRMWARE ?= ""
MACHINE_FIRMWARE_append_mx25 = " firmware-imx-sdma-imx25"
MACHINE_FIRMWARE_append_mx7d = " linux-firmware-imx-sdma-imx7d firmware-imx-epdc"
MACHINE_FIRMWARE_append_mx6 = " linux-firmware-imx-sdma-imx6q"
MACHINE_FIRMWARE_append_mx6q = " firmware-imx-vpu-imx6q"
MACHINE_FIRMWARE_append_mx6dl = " firmware-imx-vpu-imx6d firmware-imx-epdc"
MACHINE_FIRMWARE_append_mx6sl = " firmware-imx-epdc"
MACHINE_FIRMWARE_append_mx6sll = " firmware-imx-epdc"
MACHINE_FIRMWARE_append_mx6ull = " firmware-imx-epdc"
MACHINE_FIRMWARE_append_mx53 = " firmware-imx-vpu-imx53 firmware-imx-sdma-imx53"
MACHINE_FIRMWARE_append_mx51 = " firmware-imx-vpu-imx51 firmware-imx-sdma-imx51"
MACHINE_FIRMWARE_append_mx8qxp = " firmware-imx-vpu-imx8qxp"
MACHINE_FIRMWARE_append_use-mainline-bsp = " linux-firmware-imx-sdma-imx6q linux-firmware-imx-sdma-imx7d firmware-imx-vpu-imx6q firmware-imx-vpu-imx6d"

# FIXME: Needs addition of firmware-imx of official BSPs
#MACHINE_FIRMWARE_append_mx27 = " firmware-imx-vpu-imx27"

MACHINE_EXTRA_RRECOMMENDS += "${MACHINE_FIRMWARE}"

# Extra audio support
MACHINE_EXTRA_RRECOMMENDS_append_mx6 = " ${@bb.utils.contains('DISTRO_FEATURES', 'alsa', 'imx-alsa-plugins', '', d)}"
MACHINE_EXTRA_RRECOMMENDS_append_mx7 = " ${@bb.utils.contains('DISTRO_FEATURES', 'alsa', 'imx-alsa-plugins', '', d)}"
MACHINE_EXTRA_RRECOMMENDS_append_mx8 = " ${@bb.utils.contains('DISTRO_FEATURES', 'alsa', 'imx-alsa-plugins', '', d)}"

# Extra udev rules
MACHINE_EXTRA_RRECOMMENDS += "udev-rules-imx"

# GStreamer 1.0 plugins
MACHINE_GSTREAMER_1_0_PLUGIN ?= ""
MACHINE_GSTREAMER_1_0_PLUGIN_mx6dl ?= "gstreamer1.0-plugins-imx-meta"
MACHINE_GSTREAMER_1_0_PLUGIN_mx6q ?= "gstreamer1.0-plugins-imx-meta"
MACHINE_GSTREAMER_1_0_PLUGIN_mx6sl ?= "gstreamer1.0-plugins-imx-meta"
MACHINE_GSTREAMER_1_0_PLUGIN_mx6sx ?= "gstreamer1.0-plugins-imx-meta"
MACHINE_GSTREAMER_1_0_PLUGIN_mx6ul ?= "gstreamer1.0-plugins-imx-meta"
MACHINE_GSTREAMER_1_0_PLUGIN_mx6ull ?= "gstreamer1.0-plugins-imx-meta"
MACHINE_GSTREAMER_1_0_PLUGIN_mx7d ?= "gstreamer1.0-plugins-imx-meta"

# Determines if the SoC has support for Vivante kernel driver
SOC_HAS_VIVANTE_KERNEL_DRIVER_SUPPORT        = "0"
SOC_HAS_VIVANTE_KERNEL_DRIVER_SUPPORT_imxgpu = "1"

# Handle Vivante kernel driver setting:
#   0 - machine does not have Vivante GPU driver support
#   1 - machine has Vivante GPU driver support
MACHINE_HAS_VIVANTE_KERNEL_DRIVER_SUPPORT ?= "${SOC_HAS_VIVANTE_KERNEL_DRIVER_SUPPORT}"

# Graphics libraries
PREFERRED_PROVIDER_virtual/egl      ?= "mesa"
PREFERRED_PROVIDER_virtual/libgl    ?= "mesa"
PREFERRED_PROVIDER_virtual/libgles1 ?= "mesa"
PREFERRED_PROVIDER_virtual/libgles2 ?= "mesa"

PREFERRED_PROVIDER_virtual/egl_imxgpu        ?= "imx-gpu-viv"
PREFERRED_PROVIDER_virtual/libgl_imxgpu3d    ?= "imx-gpu-viv"
PREFERRED_PROVIDER_virtual/libgles1_imxgpu3d ?= "imx-gpu-viv"
PREFERRED_PROVIDER_virtual/libgles2_imxgpu3d ?= "imx-gpu-viv"
PREFERRED_PROVIDER_virtual/libg2d            ?= "imx-gpu-g2d"

PREFERRED_VERSION_weston_mx6 ?= "4.0.0.imx"
PREFERRED_VERSION_weston_mx7 ?= "4.0.0.imx"
PREFERRED_VERSION_weston_mx8 ?= "4.0.0.imx"

PREFERRED_VERSION_wayland-protocols_mx6 ?= "1.13.imx"
PREFERRED_VERSION_wayland-protocols_mx7 ?= "1.13.imx"
PREFERRED_VERSION_wayland-protocols_mx8 ?= "1.13.imx"

# Use i.MX libdrm Version
PREFERRED_VERSION_libdrm_mx6 ?= "2.4.91.imx"
PREFERRED_VERSION_libdrm_mx7 ?= "2.4.91.imx"
PREFERRED_VERSION_libdrm_mx8 ?= "2.4.91.imx"

SERIAL_CONSOLE ?= "115200 ttymxc0"
SERIAL_CONSOLE_mxs ?= "115200 ttyAMA0"

KERNEL_IMAGETYPE ?= "zImage"
KERNEL_IMAGETYPE_aarch64 ?= "Image"

MACHINE_FEATURES ?= "usbgadget usbhost vfat alsa touchscreen"

# Add the ability to specify _imx machines
MACHINEOVERRIDES =. "imx:"

HOSTTOOLS_NONFATAL_append_mx8x = " sha384sum"

