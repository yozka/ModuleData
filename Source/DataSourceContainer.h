#pragma once
#include <QObject>
#include <QSharedPointer>
#include <QList>
#include "DataSource.h"
///--------------------------------------------------------------------------------------

namespace DataSource
{
	///--------------------------------------------------------------------------------------









	 ///=====================================================================================
	///
	/// Контейнер источников данных
	/// 
	/// 
	///--------------------------------------------------------------------------------------
	class ADataSourceContainer
			: 
				public QObject
	{
		Q_OBJECT

	public:
		ADataSourceContainer();
		virtual ~ADataSourceContainer();


		int count() const; //количество элементов в контейнере
		PDataSource item(const int index); //возвратим данные в контейнере
		void append(const PDataSource &data); //добовляем данные
		void remove(const PDataSource &data); //удаляем данные

	signals:
	
		void signal_change(); //данные поменялись, сигнал


	private:


		QList<PDataSource> mDatas; //данные


	private slots:

		void slot_change(const ADataSource* data); //изменение данных
	};
	///--------------------------------------------------------------------------------------




		
	///--------------------------------------------------------------------------------------
	typedef QSharedPointer<ADataSourceContainer> PDataSourceContainer;
	///--------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------
}//namespace

