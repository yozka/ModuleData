#include "ModuleData.h"

#include <QVariant>

#include "DSRandomGenerator.h"
#include "DSManualControl.h"
#include "DSComPort.h"

#include "ChartTabs.h"
#include "DataProxy.h"
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
	ui.setupUi(this);

	mMarkings = Marking::PMarkingContainer::create();
	
	mData = DataSource::PDataSourceContainer::create();
	connect(mData.data(), &DataSource::ADataSourceContainer::signal_change, this, &AModuleData::slot_refreshDataSource);

	mChart = Chart::PChartContainer::create();
	connect(mChart.data(), &Chart::AChartContainer::signal_change, this, &AModuleData::slot_refreshChart);
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
	auto data = DataSource::PRandomGenerator::create();
	mData->append(data);

	
	//диаграма
	auto chart = Chart::PChart::create();

	chart->setMarking(mMarkings);	//маркировачные закладки



	//свяжем источник данных с приемником
	auto proxy = DataProxy::PDataProxy::create();
	bool b1 = data	->streamData->connect(proxy);
	bool b2 = chart	->streamData->connect(proxy);


	mChart->append(chart);

	Chart::AChartTabs chartTabs(mChart, ui.tabWidget);
	chartTabs.setCurrentChart(chart);
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
	mChart->remove(chart);
	chart->clear();
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
	auto mn = new QMenu();
	const int count = mData->count();
	for (int i = 0; i < count; i++)
	{
		auto item = mData->item(i);
		mn->addAction(item->title(), item.data(), SLOT(slot_show()));
	}
	ui.actionDataView->setMenu(mn);
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
	mData->append(DataSource::PRandomGenerator::create());
}
	