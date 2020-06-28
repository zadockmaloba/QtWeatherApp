#include "qtweatherapp.h"

QtWeatherApp::QtWeatherApp(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    //image.load("1a.png");
    //ui.graphicsView->scene()->addPixmap(image);
    QImage img;
    img.load("1a.png");
    QGraphicsScene* scene = new QGraphicsScene();
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(img));
    scene->addItem(item);
    ui.graphicsView->setScene(scene);
    ui.graphicsView->setDragMode(QGraphicsView::DragMode::NoDrag);
    QObject::connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(updateWeatherData()));
}

void QtWeatherApp::updateWeatherData()
{
    std::string cityName = ui.lineEdit->text().toStdString();
    netc.getURL(cityName);
    std::string maxt = netc.getData("max_t"), mint = netc.getData("min_t"), town=netc.getData("town");
    ui.lineEdit_2->setText(QString::fromStdString(town));
    ui.lineEdit_3->setText(QString::fromStdString(maxt));
    ui.lineEdit_4->setText(QString::fromStdString(mint));
}

void QtWeatherApp::searchCity()
{
    std::string cityName = ui.lineEdit->text().toStdString();
}
