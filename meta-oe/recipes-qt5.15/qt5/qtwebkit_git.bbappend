FILESEXTRAPATHS:prepend := "${THISDIR}/qtwebkit-git:"
# package is machine specific
PACKAGE_ARCH := "${MACHINE_ARCH}"

DEPENDS += " libwebp qtsensors qtlocation patchelf-native"
RDEPENDS:${PN} += " qtdeclarative qtsensors qtlocation"

SRC_URI += " \
    file://0001-Qtwebkit-platform-setting.patch \
    file://0002-Qtwebkit-without-x11.patch \
    ${@bb.utils.contains('MACHINE_FEATURES', 'noopengl', 'file://0003-Qtwebkit-without-opengl.patch', '', d)} \
"

# HACK Close libEGL.so issue fix rpatch
do_install:append() {
    patchelf --remove-needed ${PKG_CONFIG_SYSROOT_DIR}${libdir}/libEGL.so ${D}${libdir}/libQt5WebKit.so.5.212.0
    patchelf --add-needed libEGL.so ${D}${libdir}/libQt5WebKit.so.5.212.0
}

SRCREV = "ac8ebc6c3a56064f88f5506e5e3783ab7bee2456"

PACKAGECONFIG = " "

CXXFLAGS:append:osmini4k = " -Wno-deprecated-copy -DBROADCOM_PLATFORM"

INSANE_SKIP:${PN} += "file-rdeps"
