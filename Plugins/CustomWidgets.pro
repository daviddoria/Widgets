CONFIG      += designer plugin

TARGET      = $$qtLibraryTarget($$TARGET)

TEMPLATE    = lib

QTDIR_build:DESTDIR     = $$QT_BUILD_TREE/plugins/designer

INCLUDEPATH += $$PWD/..

# .so files end up here: /usr/lib/i386-linux-gnu/qt4/plugins/designer
# Headers etc end up here /usr/lib/qt4/examples/designer/CustomPlugins

HEADERS     = $$PWD/../FloatSlider.h \
              FloatSliderPlugin.h \
              LabeledSliderPlugin.h \
              CustomWidgets.h \
              $$PWD/../LabeledSlider.h
SOURCES     = $$PWD/../FloatSlider.cpp \
              $$PWD/../LabeledSlider.cpp \
              FloatSliderPlugin.cpp \
              LabeledSliderPlugin.cpp \
              CustomWidgets.cpp
FORMS       = $$PWD/../LabeledSlider.ui # The widget layout for FloatSlider is exactly the same as LabeledSlider

# There can be only one Q_EXPORT_PLUGIN macro (or you will get
#  multiple definition of `qt_plugin_query_verification_data'
# Use QDesignerCustomWidgetCollectionInterface instead

# install
target.path = $$[QT_INSTALL_PLUGINS]/designer
sources.files = $$SOURCES $$HEADERS *.pro
sources.path = $$[QT_INSTALL_EXAMPLES]/designer/CustomPlugins
INSTALLS += target sources

symbian: include($$QT_SOURCE_TREE/examples/symbianpkgrules.pri)
