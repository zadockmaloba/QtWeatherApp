#include "qtweatherapp.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("Fusion");
    QtWeatherApp w;
    w.setAttribute(Qt::WidgetAttribute::WA_WState_WindowOpacitySet);
    w.show();
    return a.exec();
}
