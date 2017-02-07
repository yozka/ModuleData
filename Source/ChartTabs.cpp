#include "ChartTabs.h"
#include <QVariant>
#include <QSharedPointer>
///--------------------------------------------------------------------------------------



///--------------------------------------------------------------------------------------
using namespace Chart;
///--------------------------------------------------------------------------------------






 ///=====================================================================================
///
/// Constructor
/// 
/// 
///--------------------------------------------------------------------------------------
AChartTabs :: AChartTabs (const PChartContainer &chart)
	:
	mChart(chart)
{


}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// Destructor
/// 
/// 
///--------------------------------------------------------------------------------------
AChartTabs :: ~AChartTabs ()
{


}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// ������������� ������� � ������
/// 
/// 
///--------------------------------------------------------------------------------------
void AChartTabs :: syncWidget(QTabWidget *tabs)
{
	
	//������� ����, ������� ����������� � ���������
	//��������� �� ��������� ��������� � ��������� ��� ������ "chart"
	for (int i = 0; i < tabs->count(); i++)
	{
		const auto tab = tabs->widget(i);
		//const auto chart = dynamic_cast<PChart>(tab->userData(0));
		
		const auto prop = tab->property("chart");
		const auto chart = qSharedPointerFromVariant<AChart>(prop);
		if (mChart->isContains(chart))
		{
			continue;
		}
		tabs->removeTab(i);
		i = 0;
	}

	//���������� �����, ��� ����� �������
	for (int i = 0; i < mChart->count(); i++)
	{
		auto chart = mChart->item(i);
		if (isContaint(chart, tabs))
		{
			//������� ��� ����� ����
			continue;
		}

		//��������� �������
		QWidget *frame = chart->createWidget();
		const int tabIndex = tabs->addTab(frame, chart->title());
		
		auto tab = tabs->widget(tabIndex);
		tab->setProperty("chart",  qVariantFromValue<PChart>(chart));
	}
	
	
}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// ��������, ���� ������ �������� � �������� ����
/// 
/// 
///--------------------------------------------------------------------------------------
bool AChartTabs :: isContaint(const PChart &chartCheck, const QTabWidget *tabs) const
{
	for (int i = 0; i < tabs->count(); i++)
	{
		const auto tab = tabs->widget(i);
		const auto prop = tab->property("chart");
		const auto chart = qSharedPointerFromVariant<AChart>(prop);
		if (chart == chartCheck)
		{
			return true;
		}
	}
	return false;
}