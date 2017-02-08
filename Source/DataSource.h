﻿#pragma once
#include <QObject>
#include <QSharedPointer>
#include <QString>
#include <QList>
#include <QEnableSharedFromThis>
///--------------------------------------------------------------------------------------




namespace DataSource
{
	///--------------------------------------------------------------------------------------





	///--------------------------------------------------------------------------------------
	class AAdapter;
	typedef QList<QSharedPointer<AAdapter>> AListAdapters;
	///--------------------------------------------------------------------------------------






	 ///=====================================================================================
	///
	/// Источник данных
	/// 
	/// 
	///--------------------------------------------------------------------------------------
	class ADataSource
			: 
				public QObject,
				public QEnableSharedFromThis<ADataSource>
	{
		Q_OBJECT

	public:
		ADataSource();
		

		virtual ~ADataSource();


		virtual QString title() const	= 0; //возвратим имя источника данных
		virtual void	show()			= 0; //покажем диалог информации по источнику данных


		void connectAdapter		(const QSharedPointer<AAdapter> &adapter); //подключаем адаптер для передачи данных
		void disconnectAdapter	(const QSharedPointer<AAdapter> &adapter); //отключаем адаптер для передачи данных

	private:

		AListAdapters mAdapters;
		

	public slots:

		void slot_show(); //покажем диалог информации по источнику данных
	};
	///--------------------------------------------------------------------------------------




		
	///--------------------------------------------------------------------------------------
	typedef QSharedPointer<ADataSource> PDataSource;
	///--------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------
}//namespace

