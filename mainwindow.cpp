#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopWidget>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mTable = new QTableWidget(this);
    mTable->setRowCount(10);
    mTable->setColumnCount(3);

    QStringList header;
    header << "#" << "Name" << "Text";
    mTable->setHorizontalHeaderLabels(header);

    // These next 2 lines are either/or
    mTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    mTable->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents); // Resize cells to content

    mTable->verticalHeader()->setVisible(true);
    mTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    mTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    mTable->setSelectionMode(QAbstractItemView::SingleSelection);
    mTable->setShowGrid(true);
    mTable->setStyleSheet("QTableView {selection-background-color: red;}");

//    mTable->setGeometry(QApplication::desktop()->availableGeometry(mTable));
    setCentralWidget(mTable);

    // Add some stuff
    mTable->setItem(0, 1, new QTableWidgetItem("blurdel"));
    mTable->setItem(0, 2, new QTableWidgetItem("Really long entry"));

    connect(mTable, SIGNAL(cellDoubleClicked(int,int)),
            this, SLOT(cellSelected(int,int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::cellSelected(int row, int col)
{
    QMessageBox::information(this, "QTable",
                             "Cell at row " + QString::number(row) +
                             " column " + QString::number(col) +
                             " was double clicked."
                             );
}
