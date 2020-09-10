#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QMessageBox>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void cellSelected(int row, int col);

private:
    Ui::MainWindow *ui;
    QTableWidget *mTable;
};

#endif // MAINWINDOW_H
