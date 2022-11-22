#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QGraphicsProxyWidget>
#include <QQuickWidget>
#include <QtWebEngine>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QtWebEngine::initialize();

    QGraphicsScene* scene = new QGraphicsScene();
    QGraphicsProxyWidget* proxy = new QGraphicsProxyWidget();

    const QUrl url(QStringLiteral("qrc:/webview.qml"));
    QQuickWidget* qmlWidget = new QQuickWidget(url);

    proxy->setWidget(qmlWidget);
    scene->addItem(proxy);
    proxy->setPos(-400, -300);
    proxy->resize(800, 600);
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

