#@TYPE: Machine
#@NAME: Ka-Ro electronics NXP i.MX8MM TX8M Computer-On-Module
#@SOC: i.MX8MM
#@DESCRIPTION: Machine configuration for Ka-Ro electronics TX8M Computer-On-Module
#@MAINTAINER: Ka-Ro electronics GmbH <support@karo-electronics.com>
#@VERSION: 1
#@DATE: 2019-04-12

MACHINEOVERRIDES =. "mx8:mx8m:mx8mm:tx8m:"

require conf/machine/include/imx-base.inc
require conf/machine/include/arm/arch-arm64.inc

MACHINE_FEATURES += " optee qca9377 qca6174"
MACHINE_FEATURES += " pci wifi bluetooth"

MACHINE_USES_VIVANTE_KERNEL_DRIVER_MODULE = "0"
MACHINE_HAS_VIVANTE_KERNEL_DRIVER_SUPPORT = "1"

XSERVER_DRIVER_use-mainline-bsp = "xf86-video-fbdev"
XSERVER ?= "xserver-xorg \
           xf86-input-evdev \
           ${XSERVER_DRIVER}"

UBOOT_CONFIG ??= "default"
UBOOT_CONFIG[default] = "tx8m-1610_defconfig"
UBOOT_CONFIG[noenv] = "tx8m-1610_noenv_config"
UBOOT_CONFIG[mfg] = "tx8m-1610_mfg_config"
UBOOT_CONFIG[secure-boot] = "tx8m-1610_sec_config"

SPL_BINARY = "spl/u-boot-spl.bin"

# Set DDR FIRMWARE
DDR_FIRMWARE_NAME = "ddr3_imem_1d.bin ddr3_dmem_1d.bin"

# Set imx-mkimage boot target
IMXBOOT_TARGETS = "flash_tx8m"

# Set Serial console
SERIAL_CONSOLE = "115200 ttymxc0"

IMAGE_BOOTLOADER = "imx-boot"

BOOT_SPACE = "65536"

LOADADDR = ""
UBOOT_SUFFIX = "bin"
UBOOT_MAKE_TARGET = ""
IMX_BOOT_SEEK = "33"

# Set U-Boot DTB
UBOOT_DTB_NAME = "imx8mm-tx8m-1610.dtb"

# Kernel Configs
PREFERRED_VERSION_linux-imx ?= "4.14.78%"

KERNEL_IMAGETYPE = "Image"

DL_DIR ?= "${BSPDIR}/downloads/"
