﻿#include "ChartContainer.h"
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
AChartContainer :: AChartContainer ()
{


}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// Destructor
/// 
/// 
///--------------------------------------------------------------------------------------
AChartContainer :: ~AChartContainer ()
{


}
///--------------------------------------------------------------------------------------






 ///=====================================================================================
///
/// количество элементов в контейнере
/// 
/// 
///--------------------------------------------------------------------------------------
int AChartContainer :: count() const
{
	return mCharts.count();
}
///--------------------------------------------------------------------------------------







 ///=====================================================================================
///
/// возвратим данные в контейнере
/// 
/// 
///--------------------------------------------------------------------------------------
PChart AChartContainer :: item(const int index)
{
	if (index < 0 || index >= mCharts.count())
	{
		return PChart();
	}
	return mCharts[index];
}
///--------------------------------------------------------------------------------------






 ///=====================================================================================
///
/// добовляем данныех
/// 
/// 
///--------------------------------------------------------------------------------------
void AChartContainer :: append(const PChart &chart)
{
	if (chart.isNull())
	{
		return;
	}

	mCharts.append(chart);
	connect(chart.data(), &AChart::signal_change, this, &AChartContainer::slot_change);

	emit signal_change();
}
///--------------------------------------------------------------------------------------







 ///=====================================================================================
///
/// удаляем данные
/// 
/// 
///--------------------------------------------------------------------------------------
void AChartContainer :: remove(const PChart &chart)
{
	if (chart.isNull())
	{
		return;
	}

	if (!mCharts.contains(chart))
	{
		return;
	}

	mCharts.removeAll(chart);
	emit signal_change();
}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// изменение данных
/// 
/// 
///--------------------------------------------------------------------------------------
void AChartContainer :: slot_change()
{
	emit signal_change();
}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// проверка, есть даныне или нет в контейнере
/// 
/// 
///--------------------------------------------------------------------------------------
bool AChartContainer :: isContains(const PChart &chart)
{
	return mCharts.contains(chart);
}