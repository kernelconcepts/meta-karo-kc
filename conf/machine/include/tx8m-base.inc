MACHINEOVERRIDES =. "mx8:mx8m:tx8m:"

KBUILD_BUILD_USER := "support"
KBUILD_BUILD_HOST := "karo-electronics.de"

require conf/machine/include/imx-base.inc
require conf/machine/include/tune-cortexa53.inc

MACHINE_USES_VIVANTE_KERNEL_DRIVER_MODULE = "0"
MACHINE_HAS_VIVANTE_KERNEL_DRIVER_SUPPORT = "1"

XSERVER_DRIVER_use-mainline-bsp = "xf86-video-fbdev"
XSERVER ?= "xserver-xorg \
           xf86-input-evdev \
           ${XSERVER_DRIVER}"

UBOOT_CONFIG ??= "default"

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

# Kernel Configs
PREFERRED_VERSION_linux-imx ?= "5.4"

# Remove some image types we don't need
IMAGE_FSTYPES_remove = "sdcard.bz2"

PREFERRED_PROVIDER_ptpd = "ptpd"

# Use correct VPU
PREFERRED_PROVIDER_virtual/imxvpu = "imx-vpu-hantro"

PREFERRED_PROVIDER_u-boot = "u-boot-imx"
PREFERRED_PROVIDER_u-boot-fw-utils = "u-boot-fw-utils-imx"
PREFERRED_PROVIDER_u-boot-tools = "u-boot-tools-imx"

PREFERRED_VERSION_u-boot-imx = "2018.03"
PREFERRED_VERSION_u-boot-fw-utils-imx = "2018.03"
PREFERRED_VERSION_u-boot-tools-imx = "2018.03"
