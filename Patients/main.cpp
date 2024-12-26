#include "ExamProject.h"
#include <QtWidgets/QApplication>
#include "QtWidgetsClass.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repository repo;
    Services serv{ repo };
    vector <Doctor> docs = serv.getDoctors();
    for (auto d : docs) {
        ExamProject* w = new ExamProject{ serv,d };
        repo.addObserver(w);
        w->show();
    }
    QtWidgetsClass* w = new QtWidgetsClass{ serv };
    w->show();

    return a.exec();
}
