#ifndef MODULEDATA_H
#define MODULEDATA_H

#include <QtWidgets/QMainWindow>
#include "ui_ModuleData.h"

class AModuleData : public QMainWindow
{
	Q_OBJECT

public:
	AModuleData(QWidget *parent = 0);
	~AModuleData();

private:
	Ui::AModuleDataClass ui;

private slots:

	void on_actionMarking_triggered(); //редактирование справочника закладок событий
};

#endif // MODULEDATA_H
