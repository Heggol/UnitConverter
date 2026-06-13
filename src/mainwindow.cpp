#include "mainwindow.hpp"

#include <QDoubleValidator>
#include <QGraphicsDropShadowEffect>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    const auto units = service.units("length");

    for (const auto& id : units | std::views::keys) {
        QString currentUnit = QString::fromStdString(id);
        currentUnit[0] = currentUnit[0].toUpper();
        ui->unitDropdownR->addItem(currentUnit);
        ui->unitDropdownL->addItem(currentUnit);
    }
    ui->unitDropdownR->setCurrentIndex(1);

    ui->categoryList->hide();
    connect(ui->sidebarButton, &QPushButton::toggled, ui->categoryList, &QWidget::setVisible);
    auto* shadowEffect = new QGraphicsDropShadowEffect();
    shadowEffect->setBlurRadius(12);
    shadowEffect->setOffset(4, 4);
    shadowEffect->setColor(QColor(5, 5, 5, 100));
    ui->categoryList->setGraphicsEffect(shadowEffect);

    const auto categories = service.categories();

    for (const auto& category : categories) {
        QString currentCategory = QString::fromStdString(category);
        currentCategory[0] = currentCategory[0].toUpper();
        ui->categoryList->addItem(currentCategory);
    }

    connect(ui->categoryList, &QListWidget::currentTextChanged, this, [this](const QString& categoryName) {
        if (categoryName.isEmpty()) return;

        ui->labelCategoryTitle->setText(categoryName);

        ui->unitDropdownL->blockSignals(true);
        ui->unitDropdownR->blockSignals(true);
        ui->unitDropdownR->clear();
        ui->unitDropdownL->clear();

        const auto units = service.units(categoryName.toLower().toStdString());

        for (const auto& id : units | std::views::keys) {
            ui->unitDropdownR->addItem(QString::fromStdString(id));
            ui->unitDropdownL->addItem(QString::fromStdString(id));
        }
        ui->unitDropdownR->setCurrentIndex(1);
        ui->unitDropdownL->blockSignals(false);
        ui->unitDropdownR->blockSignals(false);

        ui->categoryList->hide();
        ui->sidebarButton->setChecked(false);
        ui->inputL->clear();
        ui->inputR->clear();
    });

    connect(ui->unitDropdownL, &QComboBox::currentTextChanged, this, [this]() {
        const auto fromUnit = ui->unitDropdownR->currentText().toLower().toStdString();
        const auto toUnit = ui->unitDropdownL->currentText().toLower().toStdString();
        if (fromUnit.empty() || toUnit.empty()) return;
        const auto value = ui->inputR->text().toDouble();
        const auto result = service.convert(value, fromUnit, toUnit);
        ui->inputL->blockSignals(true);
        ui->inputL->setText(QString::number(result, 'g', 10));
        ui->inputL->blockSignals(false);
    });
    connect(ui->unitDropdownR, &QComboBox::currentTextChanged, this, [this]() {
        const auto fromUnit = ui->unitDropdownL->currentText().toLower().toStdString();
        const auto toUnit = ui->unitDropdownR->currentText().toLower().toStdString();
        if (fromUnit.empty() || toUnit.empty()) return;
        const auto value = ui->inputL->text().toDouble();
        const auto result = service.convert(value, fromUnit, toUnit);
        ui->inputR->blockSignals(true);
        ui->inputR->setText(QString::number(result, 'g', 10));
        ui->inputR->blockSignals(false);
    });

    const auto inputValidator = new QDoubleValidator(0.0, std::numeric_limits<double>::max(), 10);
    ui->inputL->setValidator(inputValidator);
    ui->inputR->setValidator(inputValidator);

    connect(ui->inputR, &QLineEdit::textChanged, this, [this](const QString& inputString) {
        const auto fromUnit = ui->unitDropdownR->currentText().toLower().toStdString();
        const auto toUnit = ui->unitDropdownL->currentText().toLower().toStdString();
        if (fromUnit.empty() || toUnit.empty()) return;
        const auto value = inputString.toDouble();
        const auto result = service.convert(value, fromUnit, toUnit);
        ui->inputL->blockSignals(true);
        ui->inputL->setText(QString::number(result, 'g', 10));
        ui->inputL->blockSignals(false);
    });
    connect(ui->inputL, &QLineEdit::textChanged, this, [this](const QString& inputString) {
        const auto fromUnit = ui->unitDropdownL->currentText().toLower().toStdString();
        const auto toUnit = ui->unitDropdownR->currentText().toLower().toStdString();
        if (fromUnit.empty() || toUnit.empty()) return;
        const auto value = inputString.toDouble();
        const auto result = service.convert(value, fromUnit, toUnit);
        ui->inputR->blockSignals(true);
        ui->inputR->setText(QString::number(result, 'g', 10));
        ui->inputR->blockSignals(false);
    });
}

MainWindow::~MainWindow() { delete ui; }
