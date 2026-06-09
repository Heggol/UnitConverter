#include "mainwindow.hpp"

#include <format>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    const auto units = service.units("length");

    for (const auto& [id, symbol] : units) {
        ui->unitList->addItem(QString::fromStdString(std::format("{} ({})", id, symbol)));
    }

    ui->categoryList->hide();
    connect(ui->sidebarButton, &QPushButton::toggled, ui->categoryList, &QWidget::setVisible);

    const auto categories = service.categories();

    for (const auto& category : categories) {
        ui->categoryList->addItem(QString::fromStdString(category));
    }
    connect(ui->categoryList, &QListWidget::currentTextChanged, this, [this](const QString& categoryName) {
        ui->labelCategoryTitle->setText(categoryName);
        ui->unitList->clear();

        const auto units = service.units(categoryName.toStdString());

        for (const auto& [id, symbol] : units) {
            ui->unitList->addItem(QString::fromStdString(std::format("{} ({})", id, symbol)));
        }
        ui->categoryList->hide();
        ui->sidebarButton->setChecked(false);
    });
}

MainWindow::~MainWindow() { delete ui; }
