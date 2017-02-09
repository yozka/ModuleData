#pragma once
#include <QObject>
#include <QSharedPointer>
#include <QWeakPointer>
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

		void clear(); //очистка всего

		bool isActive() const; //возвратим активность источника

	protected:

		//команды
		void command_dataOpen		() override;	//команда начало сбора данных
		void command_dataClose		() override;	//команда конца сбора данных
		void command_dataReceive	(const QVariant &value) override{};  //прием данных
		void command_connect		(IInterface_receiv *obj) override; //законнектился
		void command_disconnect		() override; //расконнектились


		virtual void onOpen(){};	//открытие данных
		virtual void onClose(){};	//закрытие данных
		virtual void onConnect(){};	//ктоо подсоеденился
		virtual void onDisconnect(){};//ктото отсоединлся

		void close();//принудительно закрытие данных

	private:

		
		bool	mActive;	//активность источника данных
		int		mRefOpen;	//количество открытых сылок


	public slots:

		void slot_show(); //покажем диалог информации по источнику данных
	};
	///--------------------------------------------------------------------------------------




		
	///--------------------------------------------------------------------------------------
	typedef QSharedPointer<ADataSource> PDataSource;
	typedef QWeakPointer<ADataSource>	PWDataSource;
	///--------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------
}//namespace

