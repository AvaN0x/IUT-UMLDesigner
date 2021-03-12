#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>

#include <QMainWindow>

#include "models/Attribute.hpp"
#include "models/Method.hpp"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void handleNewClass(QString, std::vector<iut_cpp::Attribute>, bool, bool, std::vector<iut_cpp::Method>, int);
private slots:
    void handleNewClick();
    void handleOpenClick();
    void handleSaveClick();
    void handleSaveToClick();
    void handleExportClick();
private:
    void saveFile();
    Ui::MainWindow *ui;
    QString savePath;
};
#endif // MAINWINDOW_H
