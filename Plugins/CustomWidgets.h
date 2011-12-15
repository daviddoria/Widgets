#include "LabeledSliderPlugin.h"
#include "FloatSliderPlugin.h"
#include "CoordinateEditWidgetPlugin.h"
#include "FileSelectionWidgetPlugin.h"

#include <QtDesigner/QtDesigner>
#include <QtCore/qplugin.h>
#include <QDesignerCustomWidgetCollectionInterface>

// http://developer.qt.nokia.com/doc/qt-4.8/qdesignercustomwidgetcollectioninterface.html

class CustomWidgets: public QObject, public QDesignerCustomWidgetCollectionInterface
{
  Q_OBJECT
  Q_INTERFACES(QDesignerCustomWidgetCollectionInterface)

public:
  CustomWidgets(QObject *parent = 0);

  virtual QList<QDesignerCustomWidgetInterface*> customWidgets() const;

private:
    QList<QDesignerCustomWidgetInterface*> widgets;
};
