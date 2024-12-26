#pragma once

#include <QMainWindow>
#include "ui_QtWidgetsClass.h"
#include "Services.h"
#include <QPainter>

class QtWidgetsClass : public QMainWindow
{
	Q_OBJECT

public:
	QtWidgetsClass(Services& serv,QWidget *parent = nullptr);
	~QtWidgetsClass();
	Services& serv;

private:
	Ui::QtWidgetsClassClass ui;
	void paintEvent(QPaintEvent* ev) override;

};
