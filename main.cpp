#include "qtweatherapp.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtWeatherApp w;
    w.show();
    return a.exec();
}
