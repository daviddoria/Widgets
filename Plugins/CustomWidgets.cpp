#include "CustomWidgets.h"

CustomWidgets::CustomWidgets(QObject *parent) : QObject(parent)
 {
  widgets.append(new LabeledSliderPlugin(this));
  widgets.append(new FloatSliderPlugin(this));
  widgets.append(new CoordinateEditWidgetPlugin(this));
  widgets.append(new FileSelectionWidgetPlugin(this));
}

QList<QDesignerCustomWidgetInterface*> CustomWidgets::customWidgets() const
 {
    return widgets;
}

Q_EXPORT_PLUGIN2(customwidgetsplugin, CustomWidgets)