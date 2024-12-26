#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ExamProject.h"
#include "Observer.h"
#include "Services.h"

class ExamProject : public QMainWindow, public Observer
{
    Q_OBJECT

public:
    ExamProject(Services& serv, Doctor d, QWidget * parent = nullptr);
    ~ExamProject();
    Services& serv;
    Doctor d;
private:
    Ui::ExamProjectClass ui;
    void update() override;
    void addPatient();
    void changeupdate();
    void changeupdateundiagnosed();
    void updatePatient();
};
