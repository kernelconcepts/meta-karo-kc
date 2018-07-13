# Copyright (C) 2013-2016 Freescale Semiconductor
# Copyright 2017 NXP
# Released under the MIT license (see COPYING.MIT for the terms)

SUMMARY = "Linux Kernel provided and supported by NXP"
DESCRIPTION = "Linux Kernel provided and supported by NXP with focus on \
i.MX Family Reference Boards. It includes support for many IPs such as GPU, VPU and IPU."

require recipes-kernel/linux/linux-imx.inc
inherit fsl-vivante-kernel-driver-handler

SRC_URI = "git://source.codeaurora.org/external/imx/linux-imx;protocol=https;branch=${SRCBRANCH} \
           file://set-enet_ref_clk-to-50-mhz.patch \
           file://edt-ft5x06-make-distinction-between.patch \
           file://edt-ft5x06-fixes.patch \
           file://add-support-for-edt-m12-touch.patch \
           file://ethernet-update-driver.patch \
           file://defconfig \
"

DEPENDS += "lzop-native bc-native"

SRCBRANCH = "imx_4.9.11_1.0.0_ga"
LOCALVERSION = "-1.0.0"
SRCREV = "c27010d99a3d91703ea2d1a3f9630a9dedc3f86f"

KERNEL_EXTRA_ARGS += "LOADADDR=${UBOOT_ENTRYPOINT}"

COMPATIBLE_MACHINE  = "(tx6[qus]-.*)"

FILESEXTRAPATHS_prepend = "${THISDIR}/${P}/txbase/${TXBASE}:"

KERNEL_IMAGETYPE = "uImage"

# Add NXP binary blob driver for the Vivante GPU to the kernel image.
# Otherwise settings in the Kernel defconfig are actively delete or ignored and
# the required external LKM ([RFS]/lib/modules/<kernel-version>/extra) is not
# available at all ( exception being if specific images are being "bitbaked"
# like: fsl-image-multimedia-full )

# Add Vivante GPU driver support
# Handle Vivante kernel driver setting:
#   0 - machine does not have Vivante GPU driver support
#   1 - machine has Vivante GPU driver support
MACHINE_HAS_VIVANTE_KERNEL_DRIVER_SUPPORT ?= "1"

# Use Vivante kernel driver module:
#   0 - enable the builtin kernel driver module
#   1 - enable the external kernel module
MACHINE_USES_VIVANTE_KERNEL_DRIVER_MODULE ?= "0"

# Add TX6 module specific DT file(s)
SRC_URI += "file://imx6qdl-tx6.dtsi;subdir=git/arch/arm/boot/dts \
	    file://imx6qdl-tx6-gpio.h;subdir=git/include/dt-bindings/gpio \
	   "

# Add baseboard dtsi file(s)
SRC_URI += "file://txbase-${TXBASE}.dtsi;subdir=git/arch/arm/boot/dts"

# Add TX6 (machine) specific DTS file(s)
SRC_URI += "file://${TXTYPE}-${TXNVM}-${TXBASE}.dts;subdir=git/arch/arm/boot/dts"

KERNEL_DEVICETREE = "${TXTYPE}-${TXNVM}-${TXBASE}.dtb"

# prevent debug module from automatic loading
KERNEL_MODULE_PROBECONF_mx6 += "evbug"
module_conf_evbug_mx6 = "blacklist evbug"
