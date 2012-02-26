#include "HistogramWidget.h"

// STL
#include <algorithm>
#include <iostream>

// Qt
#include <QColor>
#include <QGraphicsScene>
#include <QPen>

// NOTE: You MUST call the parent constructor, or QtDesigner will crash.
HistogramWidget::HistogramWidget(QWidget *parent) : QWidget(parent)
{
  this->setupUi(this);
}

void HistogramWidget::resizeEvent ( QResizeEvent * event )
{
  if(Vector.size() > 0)
  {
    DrawHistogram();
  }
}

void HistogramWidget::SetBarColor(const QColor& color)
{
  BarColor = color;
  DrawHistogram();
}


void HistogramWidget::DrawHistogram()
{
  QGraphicsScene* scene = new QGraphicsScene();

  // Find the max value in the vector
  float maxValue = *(std::max_element(Vector.begin(), Vector.end()));

  // Make one column for every entry in the vector
  const unsigned int maxHeight = 100;
  //scene->setSceneRect(0, 0, vec.size(), maxHeight);
  QRectF sceneRect(0, 0, Vector.size(), maxHeight);
  scene->setSceneRect(sceneRect);

  QPen pen;
  pen.setColor(BarColor);
  
  for(unsigned int i = 0; i < Vector.size(); ++i)
  {
    float barHeight = maxHeight * Vector[i]/maxValue;
    QLineF line(i, maxHeight, i, maxHeight - barHeight);
    scene->addLine(line, pen);
  }

  this->graphicsView->setScene(scene);
  this->graphicsView->fitInView(sceneRect);
}

void HistogramWidget::SetVector(const std::vector<float>& vec)
{
  Vector = vec;
  DrawHistogram();
}
