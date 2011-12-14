#ifndef LabeledSlider_H
#define LabeledSlider_H

#include <QSlider>
#include <QtDesigner/QDesignerExportWidget>

#include "ui_LabeledSlider.h"

class QIntValidator;

class QDESIGNER_WIDGET_EXPORT LabeledSlider : public QWidget, public Ui::LabeledSlider
{
Q_OBJECT
Q_PROPERTY( QString name READ name WRITE setName DESIGNABLE true)
//Q_PROPERTY( int number READ lblName->text WRITE lblName->setText DESIGNABLE true)
signals:
  void valueChanged(int);
  
public slots:
  virtual void slot_horizontalSlider_valueChanged(int); // We can't use the named slot autoconnect here because we want to connect to a different slot in a subclass
  virtual void on_txtMin_textEdited( const QString & text );
  virtual void on_txtMax_textEdited( const QString & text );
  
public:
  LabeledSlider(QWidget *parent = 0);

  unsigned int value();

  void setMinimum(const unsigned int);
  void setMaximum(const unsigned int);
  
  QString name()
  {
    return m_name;
  }
  
  void setName(const QString& name_in)
  {
    m_name = name_in;
    lblName->setText(m_name);
  }
  
protected:
  QIntValidator* Validator;

  QString m_name;
};

#endif
