#ifndef HistogramWidget_H
#define HistogramWidget_H

#include <QtDesigner/QDesignerExportWidget>

#include "ui_HistogramWidget.h"

// STL
#include <vector>

class QDESIGNER_WIDGET_EXPORT HistogramWidget : public QWidget, public Ui::HistogramWidget
{
Q_OBJECT

signals:

public:
  HistogramWidget(QWidget *parent = 0);

  void SetVector(const std::vector<float>& vec);

  void SetBarColor(const QColor& color);
  
public slots:

private:

  void resizeEvent ( QResizeEvent * event );
  
  QColor BarColor;
  std::vector<float> Vector;

  void DrawHistogram();

};

#endif
