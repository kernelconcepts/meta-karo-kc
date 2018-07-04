# Provides the i.MX common settings
# Based on imx-base.inc from meta-freescale
# Reduced to minimum requirements to make use of the NXP BSP

# Set specific make target and binary suffix

PREFERRED_PROVIDER_virtual/xserver ??= "xserver-xorg"
XSERVER_DRIVER ??= "xf86-video-fbdev"
XSERVER_DRIVER_imxgpu2d ??= "xf86-video-imxfb-vivante"
XSERVER_DRIVER_vf ??= "xf86-video-modesetting"
XSERVER_DRIVER_use-mainline-bsp ??= "xf86-video-armada"
XSERVER ??= "xserver-xorg \
           xf86-input-evdev \
           ${XSERVER_DRIVER}"

INHERIT += "machine-overrides-extender"

MACHINEOVERRIDES_EXTENDER_mx25  = "use-mainline-bsp"
MACHINEOVERRIDES_EXTENDER_mx6q  = "imxipu:imxvpu:imxgpu2d:imxgpu3d"
MACHINEOVERRIDES_EXTENDER_mx6dl = "imxpxp:imxipu:imxvpu:imxgpu2d:imxgpu3d:imxepdc"
MACHINEOVERRIDES_EXTENDER_mx6sx = "imxpxp:imxgpu2d:imxgpu3d"
MACHINEOVERRIDES_EXTENDER_mx6sl = "imxpxp:imxgpu2d:imxepdc"
MACHINEOVERRIDES_EXTENDER_mx6sll  = "imxpxp:imxepdc"
MACHINEOVERRIDES_EXTENDER_mx6ul = "imxpxp"
MACHINEOVERRIDES_EXTENDER_mx6ull = "imxpxp:imxepdc"
MACHINEOVERRIDES_EXTENDER_mx7d  = "imxpxp:imxepdc"
MACHINEOVERRIDES_EXTENDER_mx7ulp  = "imxpxp:imxgpu2d:imxgpu3d"

MACHINEOVERRIDES_EXTENDER_FILTER_OUT_use-mainline-bsp = " \
    mx6 \
    mx6q \
    mx6dl \
    mx6sx \
    mx6sl \
    mx6ul \
    mx6ull \
    \
    mx7 \
    mx7d \
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
MACHINE_SOCARCH_SUFFIX_use-mainline-bsp = "-imx"

MACHINE_ARCH_FILTER = "virtual/kernel"
MACHINE_SOCARCH_FILTER_append_imx = " alsa-lib"
MACHINE_SOCARCH_FILTER_append_imxvpu = " imx-vpu libimxvpuapi imx-codec imx-vpuwrap imx-parser"
MACHINE_SOCARCH_FILTER_append_imxgpu2d = " virtual/libopenvg virtual/libgles1 virtual/libgles2 virtual/egl virtual/mesa virtual/libgl virtual/libg2d cairo pango weston gstreamer1.0-plugins-bad"
MACHINE_SOCARCH_FILTER_append_imxpxp = " imx-codec imx-parser"
MACHINE_SOCARCH_FILTER_append_use-mainline-bsp = " \
    qtbase \
    virtual/libopenvg virtual/libgles1 virtual/libgles2 virtual/egl virtual/mesa virtual/libgl virtual/libg2d cairo pango \
"

INHERIT += "fsl-dynamic-packagearch"

SIGGEN_EXCLUDE_SAFE_RECIPE_DEPS_append = " \
    imx-gpu-viv->kernel-module-imx-gpu-viv \
    libimxvpuapi->imx-vpu \
    imx-vpuwrap->imx-vpu \
    imx-codec->imx-vpu \
    imx-test->imx-vpu \
"

# Firmware
MACHINE_FIRMWARE ?= ""
MACHINE_FIRMWARE_append_mx25 = " firmware-imx-sdma-imx25"
MACHINE_FIRMWARE_append_mx7d = " linux-firmware-imx-sdma-imx7d firmware-imx-epdc"
MACHINE_FIRMWARE_append_mx6q = " linux-firmware-imx-sdma-imx6q firmware-imx-vpu-imx6q"
MACHINE_FIRMWARE_append_mx6dl = " linux-firmware-imx-sdma-imx6q firmware-imx-vpu-imx6d firmware-imx-epdc"
MACHINE_FIRMWARE_append_mx6sl = " firmware-imx-epdc"
MACHINE_FIRMWARE_append_mx6sll = " firmware-imx-epdc"
MACHINE_FIRMWARE_append_mx6ull = " firmware-imx-epdc"
MACHINE_FIRMWARE_append_mx53 = " firmware-imx-vpu-imx53 firmware-imx-sdma-imx53"
MACHINE_FIRMWARE_append_mx51 = " firmware-imx-vpu-imx51 firmware-imx-sdma-imx51"
MACHINE_FIRMWARE_append_use-mainline-bsp = " linux-firmware-imx-sdma-imx6q linux-firmware-imx-sdma-imx7d firmware-imx-vpu-imx6q firmware-imx-vpu-imx6d"

# FIXME: Needs addition of firmware-imx of official BSPs
#MACHINE_FIRMWARE_append_mx27 = " firmware-imx-vpu-imx27"

MACHINE_EXTRA_RRECOMMENDS += "${MACHINE_FIRMWARE}"

# Extra audio support
# FIXME: Add support for ALL SoC families
MACHINE_EXTRA_RRECOMMENDS_append_mx6dl = " ${@bb.utils.contains('DISTRO_FEATURES', 'alsa', 'imx-alsa-plugins', '', d)}"
MACHINE_EXTRA_RRECOMMENDS_append_mx6q = " ${@bb.utils.contains('DISTRO_FEATURES', 'alsa', 'imx-alsa-plugins', '', d)}"
MACHINE_EXTRA_RRECOMMENDS_append_mx6sl = " ${@bb.utils.contains('DISTRO_FEATURES', 'alsa', 'imx-alsa-plugins', '', d)}"
MACHINE_EXTRA_RRECOMMENDS_append_mx6sll = " ${@bb.utils.contains('DISTRO_FEATURES', 'alsa', 'imx-alsa-plugins', '', d)}"
MACHINE_EXTRA_RRECOMMENDS_append_mx6sx = " ${@bb.utils.contains('DISTRO_FEATURES', 'alsa', 'imx-alsa-plugins', '', d)}"
MACHINE_EXTRA_RRECOMMENDS_append_mx6ul = " ${@bb.utils.contains('DISTRO_FEATURES', 'alsa', 'imx-alsa-plugins', '', d)}"
MACHINE_EXTRA_RRECOMMENDS_append_mx6ull = " ${@bb.utils.contains('DISTRO_FEATURES', 'alsa', 'imx-alsa-plugins', '', d)}"
MACHINE_EXTRA_RRECOMMENDS_append_mx7d = " ${@bb.utils.contains('DISTRO_FEATURES', 'alsa', 'imx-alsa-plugins', '', d)}"
MACHINE_EXTRA_RRECOMMENDS_append_mx7ulp = " ${@bb.utils.contains('DISTRO_FEATURES', 'alsa', 'imx-alsa-plugins', '', d)}"

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
SOC_HAS_VIVANTE_KERNEL_DRIVER_SUPPORT       = "0"
SOC_HAS_VIVANTE_KERNEL_DRIVER_SUPPORT_mx6q  = "1"
SOC_HAS_VIVANTE_KERNEL_DRIVER_SUPPORT_mx6dl = "1"
SOC_HAS_VIVANTE_KERNEL_DRIVER_SUPPORT_mx6sx = "1"
SOC_HAS_VIVANTE_KERNEL_DRIVER_SUPPORT_mx6sl = "1"
SOC_HAS_VIVANTE_KERNEL_DRIVER_SUPPORT_mx7ulp = "1"

# Handle Vivante kernel driver setting:
#   0 - machine does not have Vivante GPU driver support
#   1 - machine has Vivante GPU driver support
MACHINE_HAS_VIVANTE_KERNEL_DRIVER_SUPPORT ?= "${SOC_HAS_VIVANTE_KERNEL_DRIVER_SUPPORT}"

# mx6 GPU libraries
PREFERRED_PROVIDER_virtual/egl_mx6q ?= "imx-gpu-viv"
PREFERRED_PROVIDER_virtual/egl_mx6dl ?= "imx-gpu-viv"
PREFERRED_PROVIDER_virtual/egl_mx6sx ?= "imx-gpu-viv"
PREFERRED_PROVIDER_virtual/egl_mx6sl ?= "imx-gpu-viv"
PREFERRED_PROVIDER_virtual/egl_mx6sll ?= "mesa"
PREFERRED_PROVIDER_virtual/egl_mx6ul ?= "mesa"
PREFERRED_PROVIDER_virtual/egl_mx6ull ?= "mesa"
PREFERRED_PROVIDER_virtual/egl_mx7ulp ?= "imx-gpu-viv"

PREFERRED_PROVIDER_virtual/libgles1_mx6q ?= "imx-gpu-viv"
PREFERRED_PROVIDER_virtual/libgles1_mx6dl ?= "imx-gpu-viv"
PREFERRED_PROVIDER_virtual/libgles1_mx6sx ?= "imx-gpu-viv"
PREFERRED_PROVIDER_virtual/libgles1_mx6sl ?= "mesa"
PREFERRED_PROVIDER_virtual/libgles1_mx6sll ?= "mesa"
PREFERRED_PROVIDER_virtual/libgles1_mx6ul ?= "mesa"
PREFERRED_PROVIDER_virtual/libgles1_mx6ull ?= "mesa"
PREFERRED_PROVIDER_virtual/libgles1_mx7ulp ?= "imx-gpu-viv"

PREFERRED_PROVIDER_virtual/libgles2_mx6q ?= "imx-gpu-viv"
PREFERRED_PROVIDER_virtual/libgles2_mx6dl ?= "imx-gpu-viv"
PREFERRED_PROVIDER_virtual/libgles2_mx6sx ?= "imx-gpu-viv"
PREFERRED_PROVIDER_virtual/libgles2_mx6sl ?= "mesa"
PREFERRED_PROVIDER_virtual/libgles2_mx6sll ?= "mesa"
PREFERRED_PROVIDER_virtual/libgles2_mx6ul ?= "mesa"
PREFERRED_PROVIDER_virtual/libgles2_mx6ull ?= "mesa"
PREFERRED_PROVIDER_virtual/libgles2_mx7ulp ?= "imx-gpu-viv"

PREFERRED_PROVIDER_virtual/libgl_mx6q ?= "imx-gpu-viv"
PREFERRED_PROVIDER_virtual/libgl_mx6dl ?= "imx-gpu-viv"
PREFERRED_PROVIDER_virtual/libgl_mx6sx ?= "imx-gpu-viv"
PREFERRED_PROVIDER_virtual/libgl_mx6sl ?= "mesa"
PREFERRED_PROVIDER_virtual/libgl_mx6sll ?= "mesa"
PREFERRED_PROVIDER_virtual/libgl_mx6ul ?= "mesa"
PREFERRED_PROVIDER_virtual/libgl_mx6ull ?= "mesa"
PREFERRED_PROVIDER_virtual/libgl_mx7ulp ?= "imx-gpu-viv"

PREFERRED_PROVIDER_virtual/libg2d_mx6 ?= "imx-gpu-viv"
PREFERRED_PROVIDER_virtual/libg2d_mx6sll ?= ""
PREFERRED_PROVIDER_virtual/libg2d_mx6ul = ""
PREFERRED_PROVIDER_virtual/libg2d_mx6ull = ""
PREFERRED_PROVIDER_virtual/libg2d_mx7ulp ?= "imx-gpu-viv"

# Add the ability to specify _imx machines
MACHINEOVERRIDES =. "imx:"
