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
#include "MarkPlot.h"
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
		void setRun(const bool enabled); //установка, запущен источник или нет
		void setTimeRun(const int timeMS); //устновка текущего времи запуска

	private:

		Marking::PWMarkingContainer	mMarking; //закладки
		bool	mRun;					//флаг, запущена или нет
		int		mTimeRun;				//общее время запуска

		double	mZoomFactor;			//количество помещаемых данных на графике
		bool	mAutoTrackerEnabled;	//флаг, что размеры меняет автотрекер
		int		mMaxTime;				//время максимальное
		bool	mTimeValueChanged;		//временное положение было изменено
		bool	mRangeSetSkip;			//пропуск изменения области просмотра у графика
		bool	mTimeValueSkip;			//пропуск изменния временго шкалы

		//виджеты
		QTreeWidget *mTreeMarkings;		//дерево искользуемые метки

		QCheckBox	*mAutoTracker;		//автоматическй проматывать график
		QSlider		*mScrollTime;		//время шкала
		QLabel		*mScrollTimeLabel;	//время текст
		QLabel		*mStatusLabel;		//текущея информация по запуску

		QCustomPlot *mPlot;				//диаграмма
		QCPGraph	*mPlotGraph;		//основные данные
		QCPGraph	*mPlotGraphMark;	//закладки

		//текущая подсвеченная метка
		PMarkPlot	mMarkLabel;			//метка на графике

		void createUI(QWidget *parentWidget); //создание виджета 


		QWidget* createMarking(); //создание закладок виджета
		QWidget* createCharts(); //создание диаграмм

		void initPlot();


		void appendMark(const PMark &mark); //добавить закладки
		QTreeWidgetItem* findItemMark(const Marking::PWMarking &marking) const; //поиск закладки  

		void showMark(const PMark &mark); //показать закладку на графике и других контролах
		void refreshTimeLabel(); //обновление меток

	public slots:

		void slot_rangeChanged(const QCPRange &newRange);//изменение размеров
		void slot_timeChanged(const int value); //изменение времени
		void slot_treeChanged(QTreeWidgetItem * current, QTreeWidgetItem * previous); //изменили текущую выбор элемента в дереве меток
		void slot_graphClicked(QCPAbstractPlottable *plottable, int dataIndex);
	};
	///--------------------------------------------------------------------------------------




	


//-------------------------------------------------------------------------------------------
}//namespace

