QT4_WRAP_UI(TestHistogramWidgetUISrcs ../HistogramWidget.ui)

QT4_WRAP_CPP(TestHistogramWidgetMOCSrcs ../HistogramWidget.h)

add_executable(TestHistogramWidget TestHistogramWidget.cpp
../HistogramWidget.cpp ${TestHistogramWidgetUISrcs} ${TestHistogramWidgetMOCSrcs})
target_link_libraries(TestHistogramWidget ${QT_LIBRARIES})
