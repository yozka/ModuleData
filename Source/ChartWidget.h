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
	/// »сточник данных
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


	private:

		Marking::PMarkingContainer	mMarking; //закладки


		//информационные значени€
		QLabel *mInfoTime;
		QLabel *mInfoValue;
		QLabel *mInfoDescription;

		QTreeWidget *mTreeMarkings; //искользуемые метки

		QCustomPlot *mPlot; //диаграмма
		QCustomPlot *mPlotTimer; //временна€ шкала

		void createUI(QWidget *parentWidget); //создание виджета 


		QWidget* createHeader(); //создание заголовка
		QWidget* createCharts(); //создание диаграмм

		void test();

	public slots:


	};
	///--------------------------------------------------------------------------------------




	


//-------------------------------------------------------------------------------------------
}//namespace

