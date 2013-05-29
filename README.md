Widgets
=======

Custom Qt widgets that are reusable.

Compatibility
=============
A user reported that in VS 2010 he is seeing:

"Error 29 error C2491: 'LabeledSlider::staticMetaObjectExtraData' : definition of dllimport static data member not allowed      Widgets\moc_LabeledSlider.cxx 72"

On this line:
"const QMetaObjectExtraData LabeledSlider::staticMetaObjectExtraData = {
    0,  qt_static_metacall };"

I have only tried to build these widgets on Linux+gcc, so I can't comment on a fix for this. If anyone has one, I'm all ears :)

By removing the tag "QDESIGNER_WIDGET_EXPORT" from the definition of the classes FloatSlider, LabeledSlider, and CoordinateEditWidget 
(in their correspondent header files, e.g. "FloatSlider.h"), the repository will build, but the widgets will not be available in the QtDesigner GUI. 
