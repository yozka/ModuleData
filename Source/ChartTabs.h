#pragma once
#include <QString>
#include <QTabWidget>

#include "Chart.h"
#include "ChartContainer.h"
///--------------------------------------------------------------------------------------

namespace Chart
{
	///--------------------------------------------------------------------------------------









	 ///=====================================================================================
	///
	/// Утилита для синхронизации с табами
	/// 
	/// 
	///--------------------------------------------------------------------------------------
	class AChartTabs
	{


	public:
		AChartTabs(const PChartContainer &charts, QTabWidget *tabs);
		virtual ~AChartTabs();

		void syncWidget(); //синхронизация диаграм с табами
		bool isContaintTabs(const PChart &chartCheck) const; //проверка, есть данный диаграма в вкладках таба
		PChart currentChart() const; //возвратим текущию выбранную диаграму
		void setCurrentChart(const PChart &chart); //поставим текущий диаграмму

	private:

		PChartContainer mCharts;	//список диаграм
		QTabWidget*		mTabs;		//табулятор

		int indexTabs(const PChart &chartCheck) const; //возвратим индекс вкладки
	};
	///--------------------------------------------------------------------------------------




	

//-------------------------------------------------------------------------------------------
}//namespace

