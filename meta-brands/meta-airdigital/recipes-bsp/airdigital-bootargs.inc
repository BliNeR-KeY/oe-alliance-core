SUMMARY = "${MACHINE} bootargs files"
SECTION = "base"
PRIORITY = "required"
LICENSE = "CLOSED"
PR = "${SRCDATE}"
PACKAGE_ARCH = "${MACHINE_ARCH}"

inherit deploy

SRC_URI = "http://source.mynonpublic.com/zgemma/zgemma-bootargs-${HICHIPSET}-${SRCDATE}.zip"

S = "${WORKDIR}"

ALLOW_EMPTY:${PN} = "1"
do_configure[nostamp] = "1"

do_install() {
    install -d ${D}/usr/share
    install -m 0755 ${WORKDIR}/update_bootargs_${MACHINE}.bin ${D}/usr/share/bootargs.bin
}

do_deploy() {
    install -d ${DEPLOY_DIR_IMAGE}/zgemma-partitions-${MACHINE}/${MACHINE}
    install -m 0755 ${WORKDIR}/rescue_bootargs_${MACHINE}.bin ${DEPLOY_DIR_IMAGE}/zgemma-partitions-${MACHINE}/bootargs.bin
    install -m 0755 ${WORKDIR}/update_bootargs_${MACHINE}.bin ${DEPLOY_DIR_IMAGE}/zgemma-partitions-${MACHINE}/update_bootargs_${MACHINE}.bin
    install -m 0755 ${WORKDIR}/bootargs_${MACHINE}.bin ${DEPLOY_DIR_IMAGE}/zgemma-partitions-${MACHINE}/${MACHINE}/bootargs.bin
}

addtask deploy before do_build after do_install

INSANE_SKIP:${PN} += "already-stripped"

FILES:${PN} = "/usr/share"
