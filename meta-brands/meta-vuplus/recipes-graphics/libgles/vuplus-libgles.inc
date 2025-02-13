SUMMARY = "libgles for ${MACHINE}"
SECTION = "base"
PRIORITY = "required"
LICENSE = "CLOSED"
PACKAGE_ARCH = "${MACHINE_ARCH}"
require conf/license/license-close.inc

PV="15.1"
PR="${SRCDATE}.${SRCDATE_PR}"

PROVIDES = "virtual/libgles1 virtual/libgles2 virtual/egl libgles"
RPROVIDES:${PN} = "virtual/libgles1 virtual/libgles2 virtual/egl libEGL.so libGLESv2.so libgles"

SRC_URI = "http://code.vuplus.com/download/release/libgles/libgles-${MACHINE}-${PV}-${PR}.tar.gz"

S = "${WORKDIR}/libgles-${MACHINE}"

INSANE_SKIP:${PN} += "already-stripped dev-so ldflags"
INHIBIT_PACKAGE_STRIP = "1"
PRIVATE_LIBS:${PN} = "libEGL.so \
libv3ddriver.so \
libGLESv2.so"

do_install() {
    install -d ${D}/usr/lib/
    install -m 0755 ${S}/lib/*.so ${D}/usr/lib/
    ln -s libv3ddriver.so ${D}/usr/lib/libEGL.so
    ln -s libv3ddriver.so ${D}/usr/lib/libGLESv2.so
    install -d ${D}/usr/include
    cp -a ${S}/include/* ${D}/usr/include/
}

do_package_qa() {
}

FILES:${PN} = "/usr/lib/*"
FILES:${PN}-dev = "/usr/include/*"
