#include <QApplication>

#include "HistogramWidget.h"

int main( int argc, char **argv )
{
  QApplication app(argc, argv);

  HistogramWidget histogramWidget;
  histogramWidget.show();

  std::vector<float> histogram;
  for(unsigned int i = 0; i < 10; ++i)
  {
    histogram.push_back(i);
  }
  
  histogramWidget.SetVector(histogram);
  
  return app.exec();
}
