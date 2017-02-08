#pragma once
#include <QObject>
#include <QSharedPointer>
#include <QString>
#include <QList>
#include <QEnableSharedFromThis>

#include "CollectionProxy.h"
///--------------------------------------------------------------------------------------




namespace DataSource
{
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
				public QEnableSharedFromThis<ADataSource>,
				public DataProxy::IInterface_receiv
	{
		Q_OBJECT

	public:
		ADataSource();
		virtual ~ADataSource();


		const DataProxy::PCollectionProxy streamData;


		virtual QString title() const	= 0; //возвратим имя источника данных
		virtual void	show()			= 0; //покажем диалог информации по источнику данных


	protected:

		//команды
		void command_dataBegin() override;	//команда начало сбора данных
		void command_dataEnd() override;	//команда конца сбора данных
		void command_dataReceive(const QVariant &value) override{};  //прием данных
	private:

		

	public slots:

		void slot_show(); //покажем диалог информации по источнику данных
	};
	///--------------------------------------------------------------------------------------




		
	///--------------------------------------------------------------------------------------
	typedef QSharedPointer<ADataSource> PDataSource;
	///--------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------
}//namespace

