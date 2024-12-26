#include "QtWidgetsClass.h"

QtWidgetsClass::QtWidgetsClass(Services& serv, QWidget *parent)
	: QMainWindow(parent), serv{ serv }
{
	ui.setupUi(this);
	paintEvent(nullptr);
}

QtWidgetsClass::~QtWidgetsClass()
{}

void QtWidgetsClass::paintEvent(QPaintEvent* ev)
{
	// use proportional circle/ rectangles to represent the number of patients for each specialization

    QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);
	int x = 50, y = 50;
	int R = 50;
	vector<string> specializations;
	// get the specializations from doctors
	for (auto d : this->serv.getDoctors())
	{
		specializations.push_back(d.getSpecialization());
	}
	// remove duplicates
	sort(specializations.begin(), specializations.end());
	specializations.erase(unique(specializations.begin(), specializations.end()), specializations.end());
	// draw the circles
	// get the number of patients for each specialization
	
	for (auto s : specializations)
	{
		int count = 0;
		for (auto p : this->serv.getPatients())
			if (p.getSpecialization() == s)
				count++;
		painter.setBrush(Qt::green);
		painter.drawEllipse(QPoint(x, y), count*4, count*4);
		painter.drawText(QPoint(x - 10, y - 10), QString::fromStdString(s + " " + to_string(count)));
		x += 2 * R;
	}

	


}
