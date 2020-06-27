#include "qtweatherapp.h"

QtWeatherApp::QtWeatherApp(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    QObject::connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(updateWeatherData()));
}

void QtWeatherApp::updateWeatherData()
{
    NETcurl netc;
    std::string cityName = ui.lineEdit->text().toStdString();
    netc.getURL(cityName);
    std::string maxt = netc.getData("max_t"), mint = netc.getData("min_t");
    ui.lineEdit_2->setText(QString::fromStdString(maxt));
    ui.lineEdit_3->setText(QString::fromStdString(mint));

}

void QtWeatherApp::searchCity()
{
    std::string cityName = ui.lineEdit->text().toStdString();
}
