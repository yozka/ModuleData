﻿#pragma once
#include <QObject>
#include <QSharedPointer>
#include <QList>
#include "Chart.h"
///--------------------------------------------------------------------------------------

namespace Chart
{
	///--------------------------------------------------------------------------------------









	 ///=====================================================================================
	///
	/// Контейнер диаграм
	/// 
	/// 
	///--------------------------------------------------------------------------------------
	class AChartContainer
			: 
				public QObject
	{
		Q_OBJECT

	public:
		AChartContainer();
		virtual ~AChartContainer();


		int count() const; //количество элементов в контейнере
		PChart item(const int index); //возвратим данные в контейнере
		void append(const PChart &chart); //добовляем данные
		void remove(const PChart &chart); //удаляем данные

		bool isContains(const PChart &chart); //проверка, есть даныне или нет в контейнере

	signals:
	
		void signal_change(); //данные поменялись, сигнал


	private:


		QList<PChart> mCharts; //данные


	private slots:

		void slot_change(const AChart* chart); //изменение данных
	};
	///--------------------------------------------------------------------------------------




		
	///--------------------------------------------------------------------------------------
	typedef QSharedPointer<AChartContainer> PChartContainer;
	///--------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------
}//namespace

