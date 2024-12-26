#include "ExamProject.h"
#include <QMessageBox>

ExamProject::ExamProject(Services& serv, Doctor d,QWidget *parent)
    : QMainWindow(parent),serv{serv}, d{d}
{
    ui.setupUi(this);
    // connect the check box state changed signal with update
    QObject::connect(this->ui.checkBox, &QCheckBox::stateChanged, this, &ExamProject::update);
    QObject::connect(this->ui.AddpushButton, &QPushButton::clicked, this, &ExamProject::addPatient);
    QObject::connect(this->ui.UpdatePushButton, &QPushButton::clicked, this, &ExamProject::updatePatient);
    QObject::connect(this->ui.PatientslistWidget, &QListWidget::itemSelectionChanged, this, &ExamProject::changeupdate);
    QObject::connect(this->ui.UndiagnosedlistWidget, &QListWidget::itemSelectionChanged, this, &ExamProject::changeupdateundiagnosed);
    this->setWindowTitle(QString::fromStdString(d.getName()));
    this->ui.SpecializationLabel->setText(QString::fromStdString(d.getSpecialization()));
    this->update();
}

ExamProject::~ExamProject()
{}

void ExamProject::update() {
    this->ui.PatientslistWidget->clear();
    vector<Patient> patients;
    if (this->ui.checkBox->isChecked()) {
        		for (auto p : this->serv.getPatients())
                    if (p.getSpecialization() == this->d.getSpecialization())
                    {
                        if (p.getDoctor() == this->d.getName())
                        {
                            patients.push_back(p);
					    
				        }
			}   
                sort(patients.begin(), patients.end(), [](Patient p1,Patient p2) {
					return p1.getDate() < p2.getDate();
				});

                for (auto p : patients) {
                    QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(p.getName() + '-' + p.getDate() ));
                    item->setBackground(Qt::green);
                    this->ui.PatientslistWidget->addItem(item);
                }

                return;
    }

    for (auto p : this->serv.getPatients())
        if (p.getSpecialization() == this->d.getSpecialization())
        {
            if (p.getDoctor() == this->d.getName())
            {
				QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(p.getName() + '-' + p.getDate()));
				item->setBackground(Qt::green);
				this->ui.PatientslistWidget->addItem(item);
			}
			else
				this->ui.PatientslistWidget->addItem(QString::fromStdString(p.getName() + '-' + p.getDate()));
        }

    sort(patients.begin(), patients.end(), [](Patient p1, Patient p2) {
        return p1.getDate() < p2.getDate();
        });

    for (auto p : patients) {
        QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(p.getName() + '-' + p.getDate()));
        item->setBackground(Qt::green);
        this->ui.PatientslistWidget->addItem(item);
    }
    
    patients.clear();

    this->ui.UndiagnosedlistWidget->clear();
    for(auto p: this->serv.getPatients())
        if(p.getDiagnosis()=="undiagnosed")
            patients.push_back(p);

    sort(patients.begin(), patients.end(), [](Patient p1, Patient p2) {
        return p1.getDate() < p2.getDate();
        });

    for(auto p: patients)
		this->ui.UndiagnosedlistWidget->addItem(QString::fromStdString(p.getName() + '-' + p.getDate()));
}

void ExamProject::addPatient()
{
    string name = this->ui.namelineEdit->text().toStdString();
	string diagnosis = this->ui.diagnosislineEdit->text().toStdString();
	string specialization = this->ui.specializationlineEdit->text().toStdString();
	string doctor = this->ui.doctorlineEdit->text().toStdString();
	string date = this->ui.datelineEdit->text().toStdString();
    if(diagnosis=="")
		diagnosis = "undiagnosed";
    if (name == "")
    {
        QMessageBox msgBox;
		msgBox.setText("Invalid name!");
		msgBox.exec();
    }
    if (date < "2024.06.21") {
        QMessageBox msgBox;
        msgBox.setText("Invalid admission date!");
        msgBox.exec();
		return;
    }

	this->serv.addPatient(name, diagnosis, specialization, doctor, date);
}

void ExamProject::changeupdate()
{
	if (this->ui.PatientslistWidget->selectedItems().isEmpty())
		return;
    string line = this->ui.PatientslistWidget->selectedItems().at(0)->text().toStdString();
    string name = line.substr(0, line.find('-'));
    for (auto p : this->serv.getPatients())
        if (p.getName() == name)
        {
            if (p.getDiagnosis() == "undiagnosed" || p.getDoctor() == d.getName()) {
                this->ui.UpdatePushButton->setDisabled(false);
            }
            else {
                this->ui.UpdatePushButton->setDisabled(true);
            }
			return;
		}

}	

void ExamProject::changeupdateundiagnosed()
{
    if (this->ui.UndiagnosedlistWidget->selectedItems().isEmpty())
		return;
	string line = this->ui.UndiagnosedlistWidget->selectedItems().at(0)->text().toStdString();
	string name = line.substr(0, line.find('-'));
	for (auto p : this->serv.getPatients())
        if (p.getName() == name)
        {
            if (p.getDiagnosis() == "undiagnosed" || p.getDoctor() == d.getName()) {
				this->ui.UpdatePushButton->setDisabled(false);
			}
            else {
				this->ui.UpdatePushButton->setDisabled(true);
			}
			return;
		}
}


void ExamProject::updatePatient()
{
    // only update the patient if the doctor is the same or the diagnosis is undiagnosed
    // get the name from the current selected item in patients list, name-date, only get the name, then search for the patient with that name
    string line = this->ui.PatientslistWidget->selectedItems().at(0)->text().toStdString();
    string name = line.substr(0, line.find('-'));
    string diagnosis = this->ui.diagnosislineEdit->text().toStdString();
    string specialization = this->ui.specializationlineEdit->text().toStdString();
    if (diagnosis == "" || diagnosis == "undiagnosed") {
        QMessageBox msgBox;
        msgBox.setText("Invalid diagnosis");
        msgBox.exec();
        return;
    }

    for (auto p : this->serv.getPatients())
        if (p.getName() == name)
        {
            if (specialization != d.getSpecialization()) {
                // we change the current doctor to the doctor that has the same specialization as the patient
                for (auto doc : this->serv.getDoctors())
                    if (doc.getSpecialization() == specialization)
                    {
						this->serv.updatePatient(name, diagnosis, specialization, doc.getName(), p.getDate());
						return;
					}
            }
            else {
				this->serv.updatePatient(name, diagnosis, specialization, d.getName(), p.getDate());
				return;
			}
		}

}

