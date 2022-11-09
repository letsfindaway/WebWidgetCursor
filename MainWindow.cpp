#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDebug>
#include <QTimer>
#include <QGraphicsProxyWidget>
#include <QWebEnginePage>
#include <QWebEngineView>
#include <QWebEngineScript>
#include <QWebEngineScriptCollection>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsScene* scene = new QGraphicsScene();
    QGraphicsProxyWidget* proxy = new QGraphicsProxyWidget();
    QWebEngineView* view = new QWebEngineView();
    proxy->setWidget(view);
    scene->addItem(proxy);
    proxy->setPos(-400, -300);
    proxy->resize(800, 600);
    ui->graphicsView->setScene(scene);
    view->load(QUrl("https://www.w3schools.com/cssref/tryit.php?filename=trycss_cursor"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

