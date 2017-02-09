#pragma once
#include <QWidget>
#include <QString>
#include <QLabel>
#include <QTreeWidget>

#include "qcustomplot-source\qcustomplot.h"
#include "MarkingContainer.h"
///--------------------------------------------------------------------------------------

namespace Chart
{
	///--------------------------------------------------------------------------------------









	 ///=====================================================================================
	///
	/// Источник данных
	/// 
	/// 
	///--------------------------------------------------------------------------------------
	class AChartWidget
			: 
				public QWidget
	{
		Q_OBJECT

	public:
		AChartWidget();
		virtual ~AChartWidget();

		void clear(); //очистка всех зависемостей
		void setMarking(const Marking::PMarkingContainer &marking); //установка действующих закладок



		//void refresh(const QVector<int> &data); //обнолвение виджета
		void append(const double time, const double data); //добавить данные в виджеты

	private:

		Marking::PMarkingContainer	mMarking; //закладки


		//информационные значения
		QLabel *mInfoTime;
		QLabel *mInfoValue;
		QLabel *mInfoDescription;

		QTreeWidget *mTreeMarkings; //искользуемые метки

		QCustomPlot *mPlot; //диаграмма
		QCustomPlot *mPlotTimer; //временная шкала

		QCPGraph *mPlotGraph; //основные данные


		void createUI(QWidget *parentWidget); //создание виджета 


		QWidget* createHeader(); //создание заголовка
		QWidget* createCharts(); //создание диаграмм

		void initPlot();

	public slots:


	};
	///--------------------------------------------------------------------------------------




	


//-------------------------------------------------------------------------------------------
}//namespace

