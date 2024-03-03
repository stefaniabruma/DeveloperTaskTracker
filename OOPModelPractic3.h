#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_OOPModelPractic3.h"

class OOPModelPractic3 : public QMainWindow
{
    Q_OBJECT

public:
    OOPModelPractic3(QWidget *parent = nullptr);
    ~OOPModelPractic3();

private:
    Ui::OOPModelPractic3Class ui;
};
