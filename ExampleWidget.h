#ifndef ExampleWidget_H
#define ExampleWidget_H

#include <QMainWindow>

#include <ui_ExampleWidget.h>

// This slider should always be set from min = 0 to max = 100.
// This then lets us interpret the difference between the min and max
// as a percentage.
class ExampleWidget : public QMainWindow, public Ui::ExampleWidget
{
Q_OBJECT

public:
  ExampleWidget(QWidget *parent = 0);

public slots:
  // CoordinateEdit
  //void on_coordinateEdit_coordinateChanged(std::vector<double> coord);
  void slot_coordinateEdit_coordinateChanged(QVector<double> coord);
};

#endif
