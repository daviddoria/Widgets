CONFIG      += designer plugin

TARGET      = $$qtLibraryTarget($$TARGET)

TEMPLATE    = lib

QTDIR_build:DESTDIR     = $$QT_BUILD_TREE/plugins/designer

INCLUDEPATH += $$PWD/..

# Note: $$PWD is where the .pro file is located

HEADERS     = $$PWD/../LabeledSlider.h \
              LabeledSliderPlugin.h
SOURCES     = $$PWD/../LabeledSlider.cpp \
              LabeledSliderPlugin.cpp
FORMS       = $$PWD/../LabeledSlider.ui

# install
target.path = $$[QT_INSTALL_PLUGINS]/designer
sources.files = $$SOURCES $$HEADERS *.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/designer/LabeledSliderPlugin
INSTALLS += target sources

symbian: include($$QT_SOURCE_TREE/examples/symbianpkgrules.pri)
