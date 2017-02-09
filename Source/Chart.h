#pragma once
#include <QObject>
#include <QSharedPointer>
#include <QString>
#include <QWidget>
#include <QList>
#include <QVector>

#include "MarkingContainer.h"
#include "CollectionProxy.h"
///--------------------------------------------------------------------------------------

namespace Chart
{
	///--------------------------------------------------------------------------------------





	///--------------------------------------------------------------------------------------
	class AChartWidget;
	///--------------------------------------------------------------------------------------



	///--------------------------------------------------------------------------------------
	typedef QVector<int> TListData;
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

		void		refreshWidgets(); //обновим информацию у виджетах

	protected:

		//команды
		void command_dataOpen		() override{}; //команда начало сбора данных
		void command_dataClose		() override{}; //
		void command_dataReceive	(const QVariant &value) override;  //прием данных
		void command_connect		(IInterface_receiv *obj) override; //законнектился
		void command_disconnect		() override; //расконнектились

	private:

		int mNumber; //тестовый номер диаграмы

		Marking::PMarkingContainer	mMarking; //закладки
		QList<AChartWidget*>		mWidgets; //список привязанных виджетов

		bool mRun; //режим, запуска


		TListData mDatas; //данные


	private slots:


		void slot_destroyedWidget(QObject *obj); //удаление виджета
	};
	///--------------------------------------------------------------------------------------




		
	///--------------------------------------------------------------------------------------
	typedef QSharedPointer<AChart> PChart;
	///--------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------
}//namespace

