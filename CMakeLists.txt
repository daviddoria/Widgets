cmake_minimum_required(VERSION 2.6)

FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})

# Let Qt find it's MOCed files
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

QT4_WRAP_UI(CustomWidgetsUISrcs
LabeledSlider.ui
ExampleWidget.ui
FileSelectionWidget.ui
CoordinateEditWidget.ui
HistogramWidget.ui)

QT4_WRAP_CPP(CustomWidgetsMOCSrcs
LabeledSlider.h
FloatSlider.h
ExampleWidget.h
FileSelectionWidget.h
CoordinateEditWidget.h
HistogramWidget.h)

add_library(libCustomWidgets
FloatSlider.cpp
LabeledSlider.cpp
FileSelectionWidget.cpp
CoordinateEditWidget.cpp
HistogramWidget.cpp
${CustomWidgetsUISrcs} ${CustomWidgetsMOCSrcs})

add_executable(Example Example.cpp ExampleWidget.cpp ${CustomWidgetsUISrcs} ${CustomWidgetsMOCSrcs})
target_link_libraries(Example libCustomWidgets ${QT_LIBRARIES})

add_subdirectory(Tests)