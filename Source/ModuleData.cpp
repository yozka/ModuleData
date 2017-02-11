#include "ModuleData.h"

#include <QVariant>
#include <QMessageBox>


#include "DataSource.h"
#include "DSRandomGenerator.h"
#include "DSManualControl.h"
#include "DSComPort.h"

#include "ChartTabs.h"
#include "DataProxy.h"
///--------------------------------------------------------------------------------------



   
 ///=====================================================================================
///
/// возвратим галвное окно
/// 
/// 
///--------------------------------------------------------------------------------------
QWidget* gMain = nullptr;
QWidget* AModuleData :: main()
{
	return gMain;
}
///--------------------------------------------------------------------------------------




   
 ///=====================================================================================
///
/// constructor
/// 
/// 
///--------------------------------------------------------------------------------------
AModuleData :: AModuleData(QWidget *parent)
	: 
		QMainWindow(parent)
{
	gMain = this;
	ui.setupUi(this);

	mMarkings = Marking::PMarkingContainer::create();
	
	mData = DataSource::PDataSourceContainer::create();
	connect(mData.data(), &DataSource::ADataSourceContainer::signal_change, this, &AModuleData::slot_refreshDataSource);

	mChart = Chart::PChartContainer::create();
	connect(mChart.data(), &Chart::AChartContainer::signal_change, this, &AModuleData::slot_refreshChart);

	slot_refreshDataSource();
	slot_refreshChart();
}
///--------------------------------------------------------------------------------------






   
 ///=====================================================================================
///
/// Destructor
/// 
/// 
///--------------------------------------------------------------------------------------
AModuleData :: ~AModuleData()
{
	mMarkings = Marking::PMarkingContainer();
	mData = DataSource::PDataSourceContainer();
	mChart = Chart::PChartContainer();
}
///--------------------------------------------------------------------------------------






   
 ///=====================================================================================
///
/// редактирование справочника закладок событий
/// 
/// 
///--------------------------------------------------------------------------------------
void AModuleData :: on_actionMarking_triggered()
{
	if (mMarkingEditor.isNull())
	{
		mMarkingEditor = Marking::PMarkingEditorDialog::create();
	}
	mMarkingEditor->show(mMarkings);
}
///--------------------------------------------------------------------------------------





   
 ///=====================================================================================
///
/// добавление новой диаграмы
/// 
/// 
///--------------------------------------------------------------------------------------
void AModuleData :: on_actionChartNew_triggered()
{
	//источник данных
	//auto data = DataSource::PRandomGenerator::create();
	auto data = DataSource::PComPort::create();
	data->setPortInfo(QSerialPortInfo::availablePorts()[0]);


	mData->append(data);

	
	//диаграма
	auto chart = Chart::PChart::create();

	chart->setMarking(mMarkings);	//маркировачные закладки


	//свяжем источник данных с приемником
	auto proxy = DataProxy::PDataProxy::create();
	data	->streamData->connect(proxy);
	chart	->streamData->connect(proxy);


	mChart->append(chart);

	Chart::AChartTabs chartTabs(mChart, ui.tabWidget);
	chartTabs.setCurrentChart(chart);



	/*
	тест с двумия диаграммами
	auto chart2 = Chart::PChart::create();
	chart2->setMarking(mMarkings);	//маркировачные закладки
	
	auto proxy2 = DataProxy::PDataProxy::create();
	data	->streamData->connect(proxy2);
	chart2	->streamData->connect(proxy2);
	mChart	->append(chart2);
	*/
}
///--------------------------------------------------------------------------------------






 ///=====================================================================================
///
/// закрытие диаграммы
/// 
/// 
///--------------------------------------------------------------------------------------
void AModuleData :: on_actionChartClose_triggered()
{
	Chart::AChartTabs chartTabs(mChart, ui.tabWidget);
	auto chart = chartTabs.currentChart();
	if (chart.isNull())
	{
		return;
	}
	const auto ret = QMessageBox::question(this, "Warning!", "Confirm close chart", QMessageBox::Yes|QMessageBox::No);
	if (ret == QMessageBox::Yes)
	{
		mChart->remove(chart);
		chart->clear();

	}
}
///--------------------------------------------------------------------------------------






 ///=====================================================================================
///
/// запуск сбор данных
/// 
/// 
///--------------------------------------------------------------------------------------
void AModuleData :: on_actionChartPlay_triggered()
{
	Chart::AChartTabs chartTabs(mChart, ui.tabWidget);
	auto chart = chartTabs.currentChart();
	if (chart.isNull())
	{
		return;
	}

	chart->play();
}
///--------------------------------------------------------------------------------------






 ///=====================================================================================
///
/// приастановка сбора данных
/// 
/// 
///--------------------------------------------------------------------------------------
void AModuleData :: on_actionChartPause_triggered()
{
	Chart::AChartTabs chartTabs(mChart, ui.tabWidget);
	auto chart = chartTabs.currentChart();
	if (chart.isNull())
	{
		return;
	}

	chart->pause();
}
///--------------------------------------------------------------------------------------






 ///=====================================================================================
///
/// оастновка сбора данных
/// 
/// 
///--------------------------------------------------------------------------------------
void AModuleData :: on_actionChartStop_triggered()
{
	Chart::AChartTabs chartTabs(mChart, ui.tabWidget);
	auto chart = chartTabs.currentChart();
	if (chart.isNull())
	{
		return;
	}

	chart->stop();
}
///--------------------------------------------------------------------------------------











 ///=====================================================================================
///
/// обновление диаграм, появилась удалилась диаграма
/// 
/// 
///--------------------------------------------------------------------------------------
void AModuleData :: slot_refreshChart()
{
	Chart::AChartTabs chartTabs(mChart, ui.tabWidget);
	chartTabs.syncWidget();
}
///--------------------------------------------------------------------------------------






 ///=====================================================================================
///
/// обновление источника данных
/// 
/// 
///--------------------------------------------------------------------------------------
void AModuleData :: slot_refreshDataSource()
{
	ui.menuData->clear();
	auto menu = ui.menuData;

	//create
	auto mnCreate = menu->addMenu("Create");
	mnCreate->addAction("Random generator...", this, SLOT(on_actionRandomGenerator_triggered()));
	mnCreate->addAction("Manual control...", this, SLOT(on_actionManualControl_triggered()));
	mnCreate->addAction("Com port...", this, SLOT(on_actionComPort_triggered()));
	///
	menu->addSeparator();


	const int count = mData->count();
	for (int i = 0; i < count; i++)
	{
		auto item = mData->item(i);
		auto mnData = menu->addMenu(item->title());
		mnData->addAction("Show...",	item.data(), SLOT(slot_show()));
		auto actSelect = mnData->addAction("Install");
		mnData->addSeparator();
		auto actDelete = mnData->addAction("Delete");
		
		actSelect->setProperty("ID",	i);
		actSelect->setProperty("TYPE",	1);

		actDelete->setProperty("ID",	i);
		actDelete->setProperty("TYPE",	2);


		connect(mnData, &QMenu::triggered, this, &AModuleData::slot_menuDataSource);
	}





}
///--------------------------------------------------------------------------------------






 ///=====================================================================================
///
/// удаление одного источника
/// 
/// 
///--------------------------------------------------------------------------------------
void AModuleData :: slot_menuDataSource(QAction *action)
{
	auto data = mData->item(action->property("ID").toInt());
	if (data.isNull())
	{
		return;
	}
	int type = action->property("TYPE").toInt();
	
	//delete
	if (type == 2)
	{
	
		const auto ret = QMessageBox::question(this, "Warning!", "Confirm delete data source", QMessageBox::Yes|QMessageBox::No);
		if (ret == QMessageBox::Yes)
		{
			mData->remove(data);
			data->clear();
		}
		return;
	}
	////


	//select
	if (type != 1)
	{
		return;
	}
	Chart::AChartTabs chartTabs(mChart, ui.tabWidget);
	auto chart = chartTabs.currentChart();
	if (chart.isNull())
	{
		return;
	}

	const auto ret = QMessageBox::question(this, "Warning!", "Confirm select to chart", QMessageBox::Yes|QMessageBox::No);
	if (ret != QMessageBox::Yes)
	{
		return;
	}

	chart->streamData->disconnectAll();

	auto proxy = DataProxy::PDataProxy::create();
	data->streamData->connect(proxy);
	chart->streamData->connect(proxy);
}
///--------------------------------------------------------------------------------------
	




   




 ///=====================================================================================
///
/// добавление генератора случайных чисел
/// 
/// 
///--------------------------------------------------------------------------------------
void AModuleData :: on_actionRandomGenerator_triggered()
{
	auto data = DataSource::PRandomGenerator::create();
	mData->append(data);
	data->show();
}
///--------------------------------------------------------------------------------------
	




   




 ///=====================================================================================
///
/// добавление ручного источника данных
/// 
/// 
///--------------------------------------------------------------------------------------
void AModuleData :: on_actionManualControl_triggered()
{
	auto data = DataSource::PManualControl::create();
	mData->append(data);
	data->show();
}
///--------------------------------------------------------------------------------------
	




   




 ///=====================================================================================
///
/// добавление компорта
/// 
/// 
///--------------------------------------------------------------------------------------
void AModuleData :: on_actionComPort_triggered()
{
	auto data = DataSource::PComPort::create();
	mData->append(data);
	data->show();
}

