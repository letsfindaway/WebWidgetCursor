#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QGraphicsScene;
class QWebEngineView;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    bool eventFilter(QObject *obj, QEvent *ev) override;

private:
    Ui::MainWindow *ui;

    QGraphicsScene* scene;
    QGraphicsProxyWidget* proxy;
    QWebEngineView* view;
};
#endif // MAINWINDOW_H
