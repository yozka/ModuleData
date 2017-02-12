#include "ModuleData.h"

#include <QVariant>
#include <QMessageBox>
#include <QDebug>

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
	connect(ui.tabWidget, &QTabWidget::currentChanged, this, &AModuleData::slot_tabCurrentChanged);


	//создадим туллбар
	ui.mainToolBar->addAction(ui.actionChartPlay);
	ui.mainToolBar->addAction(ui.actionChartPause);
	ui.mainToolBar->addAction(ui.actionChartStop);
	ui.mainToolBar->addSeparator();
	ui.mainToolBar->addAction(ui.actionChartData);

	mDataSourceLink = new QComboBox(ui.mainToolBar);
	mDataSourceLink->setMinimumWidth(200);
	ui.mainToolBar->addWidget(mDataSourceLink);
	connect(mDataSourceLink, SIGNAL(currentIndexChanged(int)), this, SLOT(slot_dataSourceLinkChanged(int)));

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
	auto data = DataSource::PRandomGenerator::create();
	
	/*
	auto data = DataSource::PComPort::create();
	auto ports = QSerialPortInfo::availablePorts();
	if (!ports.isEmpty())
	{
		data->setPortInfo(ports[0]);
	}
	*/
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
/// покажем источник данных
/// 
/// 
///--------------------------------------------------------------------------------------
void AModuleData :: on_actionChartData_triggered()
{
	Chart::AChartTabs chartTabs(mChart, ui.tabWidget);
	auto chart = chartTabs.currentChart();
	if (chart.isNull())
	{
		return;
	}

	auto data = chart->currentDataSource();
	if (!data.isNull())
	{
		data->show();
	}
}
///--------------------------------------------------------------------------------------




 ///=====================================================================================
///
/// обновим действия
/// 
/// 
///--------------------------------------------------------------------------------------
void AModuleData :: updateActions()
{
	mDataSourceLink->blockSignals(true);
	mDataSourceLink->clear();
	mDataSourceLink->blockSignals(false);

	Chart::AChartTabs chartTabs(mChart, ui.tabWidget);
	auto chart = chartTabs.currentChart();
	if (chart.isNull())
	{
		//нету текуще выбранной диаграмы, заблокируем часть меню
		ui.actionChartPlay	->setEnabled(false);
		ui.actionChartPause	->setEnabled(false);
		ui.actionChartStop	->setEnabled(false);
		ui.actionChartClose	->setEnabled(false);
		ui.actionChartData	->setEnabled(false);
		mDataSourceLink		->setEnabled(false);
		return;
	}

	const bool run = chart->isRun();
	ui.actionChartPlay	->setEnabled(!run);
	ui.actionChartPause	->setEnabled(run);
	ui.actionChartStop	->setEnabled(run);

	ui.actionChartClose	->setEnabled(true);
	ui.actionChartData	->setEnabled(true);
	
	//источник данных
	mDataSourceLink->setEnabled(true);
	if (!mData.isNull())
	{
		int index = -1;
		const auto currentData = chart->currentDataSource();
		QStringList list;
		const int count = mData->count();
		for (int i = 0; i < count; i++)
		{
			const auto data = mData->item(i);
			list.append(data->title());
			if (data == currentData)
			{
				index = i;
			}
		}
		mDataSourceLink->blockSignals(true);
		mDataSourceLink->insertItems(0, list);
		mDataSourceLink->setCurrentIndex(index);
		mDataSourceLink->blockSignals(false);
	}
}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// изменение выбора в источнике данных
/// 
/// 
///--------------------------------------------------------------------------------------
void AModuleData :: slot_dataSourceLinkChanged(int index)
{
	Chart::AChartTabs chartTabs(mChart, ui.tabWidget);
	auto chart = chartTabs.currentChart();
	if (chart.isNull())
	{
		return;
	}

	auto data = mData->item(index);
	if (data.isNull())
	{
		updateActions();
		return;
	}

	if (data == chart->currentDataSource())
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
/// обновление диаграм, появилась удалилась диаграма
/// 
/// 
///--------------------------------------------------------------------------------------
void AModuleData :: slot_refreshChart()
{
	Chart::AChartTabs chartTabs(mChart, ui.tabWidget);
	chartTabs.syncWidget();
	updateActions();
}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// сменили текущий табулятор
/// 
/// 
///--------------------------------------------------------------------------------------
void AModuleData :: slot_tabCurrentChanged(int index)
{
	updateActions();
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
	auto mnCreate = menu->addMenu(QIcon(":/Icons/Icons/sq_plus.png"), "Create");
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
		mnData->addAction(QIcon(":/Icons/Icons/db.png"), "Show...",	item.data(), SLOT(slot_show()));
		auto actSelect = mnData->addAction(QIcon(":/Icons/Icons/link.png"), "Install");
		mnData->addSeparator();
		auto actDelete = mnData->addAction(QIcon(":/Icons/Icons/sq_minus.png"), "Delete");
		
		actSelect->setProperty("ID",	i);
		actSelect->setProperty("TYPE",	1);

		actDelete->setProperty("ID",	i);
		actDelete->setProperty("TYPE",	2);


		connect(mnData, &QMenu::triggered, this, &AModuleData::slot_menuDataSource);
	}




	updateActions();
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

