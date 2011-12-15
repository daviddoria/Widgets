#include <iostream>

#include "ExampleWidget.h"


#include "LabeledSlider.h"
#include "FloatSlider.h"
#include "FileSelectionWidget.h"
#include "CoordinateEditWidget.h"

ExampleWidget::ExampleWidget(QWidget *parent)
{
  this->setupUi(this);

  //   LabeledSlider* labeledSlider = new LabeledSlider;
//   labeledSlider->show();
//
//   FloatSlider* floatSlider = new FloatSlider;
//   floatSlider->show();

//   FileSelectionWidget* fileSelectionWidget = new FileSelectionWidget;
//   fileSelectionWidget->show();

  CoordinateEditWidget* coordinateEditWidget = new CoordinateEditWidget;
  coordinateEditWidget->show();
  connect(coordinateEditWidget, SIGNAL(coordinateChanged(QVector<double>)), this, SLOT(slot_coordinateEdit_coordinateChanged(QVector<double>)));

//   QVBoxLayout* VLayout = new QVBoxLayout;
//   VLayout->addWidget(labeledSlider);
//   VLayout->addWidget(floatSlider);
//   VLayout->addWidget(fileSelectionWidget);
//
//   this->setLayout(VLayout);
//   this->show();
}

//void ExampleWidget::on_coordinateEdit_coordinateChanged(std::vector<double> coord)
void ExampleWidget::slot_coordinateEdit_coordinateChanged(QVector<double> coord)
{
  std::cout << coord[0] << " " << coord[1] << " " << coord[2] << std::endl;
}
