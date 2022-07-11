
//Minimal Browser is a C++ and QT5 browser.
//Copyright (c) 2020 JJ Posti <techtimejourney.net>
//This is free software, and you are welcome to redistribute it under GPL Version 2, June 1991″
//This is version 2.5 beta(July 2022).

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QString>
#include <QWebView>
#include <QtWidgets>
#include <QUrl>
#include <QtPrintSupport>
#include <QPrintDialog>
#include <QPrinter>
#include <QPageLayout>
#include <QWebInspector>
#include <QCoreApplication>
#include <QProcess>
#include <form.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->addTab(new Form(), QString("Tab %0").arg(ui->tabWidget->count() +1));
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count() -1);

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    if(index > 0){
    ui->tabWidget->removeTab(index);}
}

void MainWindow::on_tabWidget_tabBarDoubleClicked()
{
    ui->tabWidget->addTab(new Form(), QString("Tab %0").arg(ui->tabWidget->count() +1));
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count() -1);
}
