#include "qtweatherapp.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("Fusion");
    QtWeatherApp w;
    w.show();
    return a.exec();
}
