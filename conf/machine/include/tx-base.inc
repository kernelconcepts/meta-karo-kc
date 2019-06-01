# Set specific make target and binary suffix
PREFERRED_PROVIDER_u-boot ??= "u-boot-karo"
PREFERRED_PROVIDER_virtual/bootloader ??= "u-boot-karo"
include imx-base.inc

UBOOT_MAKE_TARGET ??= "u-boot.bin"
UBOOT_SUFFIX ??= "bin"

UBOOT_ENTRYPOINT_mx6  = "0x10008000"
UBOOT_ENTRYPOINT_mx6ul = "0x80008000"
# since the lines above break mainline for mx6 we add this default
# but it leaves us to set a correct entrypoint for txul machines
# using mainline bsp
UBOOT_ENTRYPOINT_use-mainline-bsp = "0x10008000"

# 'cortexa9-neon' 'cortexa9hf-neon'
DEFAULTTUNE_mx6 ?= "cortexa9hf-neon"
DEFAULTTUNE_mx6ul ?= "cortexa7hf-neon"

PREFERRED_PROVIDER_virtual/kernel ??= "linux-karo"
KERNEL_IMAGETYPE ?= "uImage"

MACHINE_FEATURES ?= " \
                 alsa \
                 rtc \
                 serial \
                 touchscreen \
                 usbgadget \
                 usbhost \
                 vfat \
"

# Add the ability to specify _imx machines
MACHINEOVERRIDES =. "imx:"


# Default baseboard name
TXBASE_DEFAULT_mx6 ?= "mb7"
TXBASE_DEFAULT_mx6ul ?= "evalkit"

TXBASE ?= "${TXBASE_DEFAULT}"
