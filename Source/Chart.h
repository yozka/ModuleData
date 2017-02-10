#pragma once
#include <QObject>
#include <QSharedPointer>
#include <QString>
#include <QWidget>
#include <QList>
#include <QVector>

#include "MarkingContainer.h"
#include "CollectionProxy.h"
#include "DataSource.h"
///--------------------------------------------------------------------------------------

namespace Chart
{
	///--------------------------------------------------------------------------------------





	///--------------------------------------------------------------------------------------
	class AChartWidget;
	///--------------------------------------------------------------------------------------






	 ///=====================================================================================
	///
	/// ОДин график
	/// 
	/// 
	///--------------------------------------------------------------------------------------
	class AChart
			: 
				public QObject,
				public DataProxy::IInterface_receiv
	{
		Q_OBJECT

	public:
		AChart();
		virtual ~AChart();


		const DataProxy::PCollectionProxy streamData;


		QString		title() const;		//возвратим название диаграмы
		QWidget*	createWidget();		//создание представление данных
		
		void		clear();			//очистка всей диаграммы, уберание всех зависемостей
		void		setMarking(const Marking::PMarkingContainer &marking); //установка действующих закладок

		void		play();		//запуск сбора данных
		void		pause();	//пауза для сбора данных
		void		stop();		//остановка для сбора данных

		void		reset();	//удаление сброс всех данных
		void		refreshWidgets(); //обновим информацию у виджетах

		DataSource::PDataSource currentDataSource() const; //возвратим текущий подключенный источник

	protected:

		//команды
		bool command_dataOpen		() override{ return false;}; //команда начало сбора данных
		bool command_dataClose		() override{ return false;}; //
		bool command_dataReceive	(const QVariant &value) override;  //прием данных
		void command_connect		(IInterface_receiv *obj) override; //законнектился
		void command_disconnect		() override; //расконнектились

	private:

		int mNumber; //тестовый номер диаграмы

		Marking::PMarkingContainer	mMarking; //закладки
		AChartWidget*				mChartWidget; //список привязанных виджетов

		bool	mRun; //режим, запуска
		bool	mInitTime; //нужно или нет инциализировать время
		double	mZeroTime; //нулевая точка времени, для отчета

		QVector<double> mContentTime; //время
		QVector<double> mContentData; //данные


		void append(const double time, const double data); //добавить данные в виджеты


	private slots:


		void slot_destroyedWidget(QObject *obj); //удаление виджета
	};
	///--------------------------------------------------------------------------------------




		
	///--------------------------------------------------------------------------------------
	typedef QSharedPointer<AChart> PChart;
	///--------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------
}//namespace

