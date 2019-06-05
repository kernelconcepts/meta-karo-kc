# this is kind of ugly but allows device specific xorg.conf for i.mx8
# devices using mainline-bsp mode - overrides override in meta-freescale
FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}/${MACHINE}:"
