#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDebug>
#include <QGraphicsProxyWidget>
#include <QWebEnginePage>
#include <QWebEngineView>
#include <QWindow>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene();
    proxy = new QGraphicsProxyWidget();
    view = new QWebEngineView();

    proxy->setWidget(view);
    scene->addItem(proxy);
    proxy->resize(800, 600);
    ui->graphicsView->setScene(scene);

    QWindow* window = view->windowHandle();
    window->installEventFilter(this);

    view->load(QUrl("https://www.w3schools.com/cssref/tryit.php?filename=trycss_cursor"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *obj, QEvent *ev)
{
    if (ev->type() == QEvent::CursorChange)
    {
        QWindow* window = dynamic_cast<QWindow*>(obj);

        if (window)
        {
            proxy->setCursor(window->cursor());
        }
    }

    return QMainWindow::eventFilter(obj, ev);
}

