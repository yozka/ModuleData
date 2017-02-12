#pragma once
#include <QMainWindow>
#include <QComboBox>
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

static QWidget* main(); //возвратим галвное окно


private:
	Ui::AModuleDataClass				ui;

	Marking::PMarkingContainer			mMarkings;		//метки
	Marking::PMarkingEditorDialog		mMarkingEditor; //редактор меток

	DataSource::PDataSourceContainer	mData;			 //данны которые приходят извне
	Chart::PChartContainer				mChart;			 //диаграмы
	QComboBox*							mDataSourceLink; //комббобокс для выбора источника данных

	void updateActions(); //обновим действия
private slots:

	//CHART
	void on_actionMarking_triggered();		//редактирование справочника закладок событий
	void on_actionChartNew_triggered();		//добавление новой диаграмы
	void on_actionChartClose_triggered();	//закрытие диаграммы
	void slot_refreshChart();				//обновление диаграм, появилась удалилась диаграма
	void slot_tabCurrentChanged(int index); //сменили текущий табулятор

	void on_actionChartPlay_triggered();	//запуск сбор данных
	void on_actionChartPause_triggered();	//приастановка сбора данных
	void on_actionChartStop_triggered();	//оастновка сбора данных
	void on_actionChartData_triggered();				//покажем источник данных

	//DATA
	void on_actionRandomGenerator_triggered(); //добавление генератора случайных чисел
	void on_actionManualControl_triggered(); //добавление ручного источника данных
	void on_actionComPort_triggered(); //добавление компорта
	void slot_refreshDataSource(); //обновление источника данных
	void slot_menuDataSource(QAction *action); //обработка меню
	void slot_dataSourceLinkChanged(int index); //изменение выбора в источнике данных
};


