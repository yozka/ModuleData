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
AChartTabs :: AChartTabs (const PChartContainer &charts, QTabWidget *tabs)
	:
	mCharts(charts),
	mTabs(tabs)
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
/// синхронизация диаграм с табами
/// 
/// 
///--------------------------------------------------------------------------------------
void AChartTabs :: syncWidget()
{
	
	//удалить табы, которые непривязаны к диаграмам
	//указатель на диаграмах находится в свойствах под именем "chart"
	for (int i = 0; i < mTabs->count(); i++)
	{
		const auto tab = mTabs->widget(i);
		const auto prop = tab->property("chart");
		const auto chart = qSharedPointerFromVariant<AChart>(prop);
		if (mCharts->isContains(chart))
		{
			continue;
		}
		
		tab->setProperty("chart", QVariant());
		mTabs->removeTab(i);
		delete tab;
		i = 0;
	}

	//добавление табов, для новых диаграм
	for (int i = 0; i < mCharts->count(); i++)
	{
		auto chart = mCharts->item(i);
		if (isContaintTabs(chart))
		{
			//вкладка уже такая есть
			continue;
		}

		//добавляем вкладку
		QWidget *frame = chart->createWidget();
		const int tabIndex = mTabs->addTab(frame, chart->title());
		
		auto tab = mTabs->widget(tabIndex);
		tab->setProperty("chart",  qVariantFromValue<PChart>(chart));
	}
	
	
}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// проверка, есть данный диаграма в вкладках таба
/// 
/// 
///--------------------------------------------------------------------------------------
bool AChartTabs :: isContaintTabs(const PChart &chartCheck) const
{
	for (int i = 0; i < mTabs->count(); i++)
	{
		const auto tab = mTabs->widget(i);
		const auto prop = tab->property("chart");
		const auto chart = qSharedPointerFromVariant<AChart>(prop);
		if (chart == chartCheck)
		{
			return true;
		}
	}
	return false;
}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// возвратим текущию выбранную диаграму
/// 
/// 
///--------------------------------------------------------------------------------------
PChart AChartTabs :: currentChart() const
{
	const int index = mTabs->currentIndex();
	const auto tab = mTabs->widget(index);
	if (tab == nullptr)
	{
		return PChart();
	}
	const auto prop = tab->property("chart");
	const auto chart = qSharedPointerFromVariant<AChart>(prop);
	return chart;
}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// поставим текущий диаграмму
/// 
/// 
///--------------------------------------------------------------------------------------
void AChartTabs :: setCurrentChart(const PChart &chart)
{
	for (int i = 0; i < mTabs->count(); i++)
	{
		const auto tab = mTabs->widget(i);
		const auto prop = tab->property("chart");
		const auto chartFind = qSharedPointerFromVariant<AChart>(prop);
		if (chartFind == chart)
		{
			mTabs->setCurrentIndex(i);
			return;
		}
	}
}