DESCRIPTION = "Resize Rootfs"
require conf/license/license-gplv2.inc

COMPATIBLE_MACHINE = "^hd51$|^vs1500$|^hd60$|^hd61$"
PACKAGE_ARCH = "${MACHINE_ARCH}"

RDEPENDS:${PN} = "e2fsprogs-resize2fs"
PV = "1.0"
PR = "r1"

SRC_URI = "file://resizerootfs"

inherit update-rc.d

INITSCRIPT_NAME = "resizerootfs"
INITSCRIPT_PARAMS = "start 7 S ."

do_install () {
    install -m 0755 -d ${D}${sysconfdir}/init.d
    install -m 0755 ${WORKDIR}/resizerootfs ${D}${sysconfdir}/init.d/resizerootfs
}
