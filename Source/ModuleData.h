#pragma once
#include <QMainWindow>
#include "ui_ModuleData.h"
///--------------------------------------------------------------------------------------


#include "MarkingContainer.h"
#include "MarkingEditorDialog.h"
#include "DataSourceContainer.h"
///--------------------------------------------------------------------------------------






 ///=====================================================================================
///
/// основное окно
/// 
/// 
///--------------------------------------------------------------------------------------
class AModuleData 
		: 
			public QMainWindow
{
	Q_OBJECT

public:
	AModuleData(QWidget *parent = 0);
	virtual ~AModuleData();



private:
	Ui::AModuleDataClass				ui;

	Marking::PMarkingContainer			mMarkings;		//метки
	Marking::PMarkingEditorDialog		mMarkingEditor; //редактор меток

	DataSource::PDataSourceContainer	mData;			//данны которые приходят извне

private slots:

	//EDIT
	void on_actionMarking_triggered(); //редактирование справочника закладок событий

	//DATA
	void on_actionRandomGenerator_triggered(); //добавление генератора случайных чисел
	void slot_refreshDataSource(); //обновление источника данных
};


