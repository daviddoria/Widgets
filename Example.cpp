#include <QProgressDialog>
#include <QApplication>

#include "ExampleWidget.h"

#include "LabeledSlider.h"
#include "FloatSlider.h"
#include "FileSelectionWidget.h"

int main( int argc, char **argv )
{
  QApplication app(argc, argv);

  //ExampleWidget exampleWidget;
  //exampleWidget.show();

  LabeledSlider* labeledSlider = new LabeledSlider;
  labeledSlider->show();

  FloatSlider* floatSlider = new FloatSlider;
  floatSlider->show();

  FileSelectionWidget* fileSelectionWidget = new FileSelectionWidget;
  fileSelectionWidget->show();

//   QVBoxLayout* VLayout = new QVBoxLayout;
//   VLayout->addWidget(labeledSlider);
//   VLayout->addWidget(floatSlider);
//   VLayout->addWidget(fileSelectionWidget);
// 
//   this->setLayout(VLayout);
//   this->show();
  
  return app.exec();
}
