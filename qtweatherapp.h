#pragma once

#include <QtWidgets/QWidget>
#include <qstring.h>
#include <string>
#include "ui_qtweatherapp.h"
#include "NETcurl.h"

class QtWeatherApp : public QWidget
{
    Q_OBJECT

public:
    QtWeatherApp(QWidget *parent = Q_NULLPTR);
public slots:
    void updateWeatherData();
private:
    Ui::QtWeatherAppClass ui;
    void searchCity();
};
