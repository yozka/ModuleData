#include "ModuleData.h"

#include <QVariant>

#include "DSRandomGenerator.h"
#include "DSManualControl.h"
#include "DSComPort.h"
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
}
///--------------------------------------------------------------------------------------






   
 ///=====================================================================================
///
/// �������������� ����������� �������� �������
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
/// ���������� ����� ��������
/// 
/// 
///--------------------------------------------------------------------------------------
void AModuleData :: on_actionChartNew_triggered()
{
	//�������� ������
	auto data = DataSource::PRandomGenerator::create();
	mData->append(data);

	
	//��������
	auto chart = Chart::PChart::create();

	
	/*
	chart->setDataSource(data);		//�������� ������
	chart->setMarking(mMarkings);	//������������� ��������
	*/

	mChart->append(chart);
}
///--------------------------------------------------------------------------------------






 ///=====================================================================================
///
/// ���������� �������, ��������� ��������� ��������
/// 
/// 
///--------------------------------------------------------------------------------------
void AModuleData :: slot_refreshChart()
{
	auto tabs = ui.tabWidget;

	//������� ����, ������� ����������� � ���������
	//��������� �� ��������� ��������� � ��������� ��� ������ "chart"
	for (int i = 0; i < tabs->count(); i++)
	{
		const auto tab = tabs->widget(i);
		const auto prop = tab->property("chart");
		const auto chart = prop.value<Chart::PChart>();
		if (mChart->isContains(chart))
		{
			continue;
		}
		tabs->removeTab(i);
		i = 0;
	}


	
	QWidget *frame = new QWidget();
	ui.tabWidget->addTab(frame, "test");
}
///--------------------------------------------------------------------------------------






 ///=====================================================================================
///
/// ���������� ��������� ������
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
/// ���������� ���������� ��������� �����
/// 
/// 
///--------------------------------------------------------------------------------------
void AModuleData :: on_actionRandomGenerator_triggered()
{
	mData->append(DataSource::PRandomGenerator::create());
}
	