#pragma once
#include <QObject>
#include <QSharedPointer>
#include <QString>
#include <QWidget>
#include <QList>

#include "MarkingContainer.h"
#include "CollectionProxy.h"
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

		void		play(); //запуск сбора данных


	protected:

		//команды
		void command_dataBegin() override{}; //команда начало сбора данных
		void command_dataEnd() override{}; //
		void command_dataReceive(const QVariant &value) override;  //прием данных

	private:

		int mNumber; //тестовый номер диаграмы

		Marking::PMarkingContainer	mMarking; //закладки

		QList<AChartWidget*>		mWidgets; //список привязанных виджетов

	private slots:


		void slot_destroyedWidget(QObject *obj); //удаление виджета
	};
	///--------------------------------------------------------------------------------------




		
	///--------------------------------------------------------------------------------------
	typedef QSharedPointer<AChart> PChart;
	///--------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------
}//namespace

