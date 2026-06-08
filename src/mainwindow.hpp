#ifndef UNITCONVERTER_SRC_MAINWINDOW_HPP_
#define UNITCONVERTER_SRC_MAINWINDOW_HPP_

#include <QMainWindow>

#include "core/service.hpp"

QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
    Q_DISABLE_COPY_MOVE(MainWindow)

   public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

   private:
    Ui::MainWindow* ui;

    UnitService service;
};

#endif
