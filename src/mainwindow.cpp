#include "mainwindow.hpp"

#include <QDebug>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    qDebug() << "10 meters to miles:\n" << service.convert(10, "meter", "mile") << "\n";
    const auto categories = service.categories();
    qDebug() << service.categories() << "\n";

    for (const auto& cat : categories) {
        qDebug() << service.units(cat) << "\n";
    }

    ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }
