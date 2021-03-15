#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>

#include <QMainWindow>

#include "models/Attribute.hpp"
#include "models/Method.hpp"
#include "models/Class.hpp"

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
    void handleNewClass(QString, QString, std::vector<iut_cpp::Attribute>, bool, bool, std::vector<iut_cpp::Method>, int);
private slots:
    void handleNewClick();
    void handleEditClass();
    void handleExportClick();
    void showContextMenu(const QPoint &);
private:
    void saveFile();
    Ui::MainWindow *ui;
    std::vector<iut_cpp::Class> *classes;
    int classToExport = -1;
};
#endif // MAINWINDOW_H
