#pragma once
#include <QWidget>
#include <QString>
#include <QLabel>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QScrollBar>
#include <QCheckBox>

#include "qcustomplot-source\qcustomplot.h"
#include "MarkingContainer.h"
#include "Mark.h"
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
		void setMarking(const Marking::PWMarkingContainer &marking); //установка действующих закладок


		void append(const double time, const double data); //добавить данные в виджеты
		void reset(); //удалить все данные

		void setNameDataSource(const QString &caption); //установим текущее название источника

	private:

		Marking::PWMarkingContainer	mMarking; //закладки

		double	mZoomFactor;
		bool	mAutoTrackerEnabled; //флаг, что размеры меняет автотрекер
		int		mMaxTime; //время максимальное
		bool	mTimeValueChanged; //временное положение было изменено

		QSlider		*mScrollTime; //время шкала
		QTreeWidget *mTreeMarkings; //искользуемые метки
		QCheckBox	*mAutoTracker;	//автоматическй проматывать график

		QCustomPlot *mPlot;			//диаграмма
		QCustomPlot *mPlotTimer;	//временная шкала

		QCPGraph *mPlotGraph;	//основные данные
		QCPGraph *mPlotGraphMark;	//закладки

		void createUI(QWidget *parentWidget); //создание виджета 


		QWidget* createMarking(); //создание закладок виджета
		QWidget* createCharts(); //создание диаграмм

		void initPlot();


		void appendMark(const PMark &mark); //добавить закладки
		QTreeWidgetItem* findItemMark(const Marking::PWMarking &marking) const; //поиск закладки  

	public slots:

		void slot_rangeChanged(const QCPRange &newRange);//изменение размеров

	};
	///--------------------------------------------------------------------------------------




	


//-------------------------------------------------------------------------------------------
}//namespace

