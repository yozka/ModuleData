#pragma once
#include <QMainWindow>
#include "ui_ModuleData.h"
///--------------------------------------------------------------------------------------


#include "MarkingContainer.h"
#include "MarkingEditorDialog.h"
#include "DataSourceContainer.h"
#include "ChartContainer.h"
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
	Chart::PChartContainer				mChart;			//диаграмы

private slots:

	//CHART
	void on_actionMarking_triggered();		//редактирование справочника закладок событий
	void on_actionChartNew_triggered();		//добавление новой диаграмы
	void on_actionChartClose_triggered();	//закрытие диаграммы
	void slot_refreshChart();				//обновление диаграм, появилась удалилась диаграма

	void on_actionChartPlay_triggered();	//запуск сбор данных

	//DATA
	void on_actionRandomGenerator_triggered(); //добавление генератора случайных чисел
	void slot_refreshDataSource(); //обновление источника данных
};


