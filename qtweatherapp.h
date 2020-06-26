#pragma once

#include <QtWidgets/QWidget>
#include "ui_qtweatherapp.h"

class QtWeatherApp : public QWidget
{
    Q_OBJECT

public:
    QtWeatherApp(QWidget *parent = Q_NULLPTR);

private:
    Ui::QtWeatherAppClass ui;
};
