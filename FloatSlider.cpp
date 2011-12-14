#include <iostream>

#include "FloatSlider.h"

#include <QDoubleValidator>

//FloatSlider::FloatSlider(QWidget *parent) : LabeledSlider(parent)
FloatSlider::FloatSlider(QWidget *parent) : LabeledSlider(parent)
{
  this->horizontalSlider->setMinimum(0);
  this->horizontalSlider->setMaximum(100);

  this->MinValue = 0.0f;
  this->txtMin->setText(QString::number(this->MinValue));
  
  this->MaxValue = 10.0f;
  this->txtMax->setText(QString::number(this->MaxValue));

  this->lblCurrent->setText(QString::number(GetValue()));

  this->Validator = new QDoubleValidator(0.0d, 10000.0d, 2, this);
  this->txtMin->setValidator(this->Validator);
  this->txtMax->setValidator(this->Validator);
}
  
float FloatSlider::GetValue()
{
  return this->MinValue + (this->MaxValue - this->MinValue) * static_cast<float>(this->horizontalSlider->value()) / 100.0f;
}

void FloatSlider::setMinimum(const float value)
{
  this->MinValue = value;
  this->txtMin->setText(QString::number(this->MinValue));
  this->lblCurrent->setText(QString::number(GetValue()));
}

void FloatSlider::setMaximum(const float value)
{
  this->MaxValue = value;
  this->txtMax->setText(QString::number(this->MaxValue));
  this->lblCurrent->setText(QString::number(GetValue()));
}

void FloatSlider::slot_horizontalSlider_valueChanged(int value)
{
  //std::cout << "FloatSlider::SliderValueChanged" << std::endl;
  this->lblCurrent->setText(QString::number(GetValue()));
  emit valueChanged(GetValue());
}


void FloatSlider::on_txtMin_textEdited( const QString & text )
{
  this->MinValue = text.toFloat();
  this->lblCurrent->setText(QString::number(GetValue()));
}

void FloatSlider::on_txtMax_textEdited( const QString & text )
{
  this->MaxValue = text.toFloat();
  this->lblCurrent->setText(QString::number(GetValue()));
}
