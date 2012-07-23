cmake_minimum_required(VERSION 2.6)

FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})

# Let Qt find it's MOCed files
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

if(NOT ${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
  set(Widgets_includes ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR} PARENT_SCOPE)
endif()

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

add_library(CustomWidgets
FloatSlider.cpp
LabeledSlider.cpp
FileSelectionWidget.cpp
CoordinateEditWidget.cpp
HistogramWidget.cpp
${CustomWidgetsUISrcs} ${CustomWidgetsMOCSrcs})

add_executable(Example Example.cpp ExampleWidget.cpp ${CustomWidgetsUISrcs} ${CustomWidgetsMOCSrcs})
target_link_libraries(Example CustomWidgets ${QT_LIBRARIES})

SET(Widgets_BuildTests OFF CACHE BOOL "Widgets_BuildTests")
if(Widgets_BuildTests)
  add_subdirectory(Tests)
endif()
