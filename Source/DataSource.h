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





		
	///--------------------------------------------------------------------------------------
	namespace settings
	{
		const int min			= -200;
		const int max			= 200;

		const int interval		= 300;
		const int intervalMin	= 100;
		const int intervalMax	= 10000;
	}
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
		bool command_dataOpen		() override;	//команда начало сбора данных
		bool command_dataClose		() override;	//команда конца сбора данных
		bool command_dataReceive	(const QVariant &value) override{ return false;};  //прием данных
		void command_connect		(IInterface_receiv *obj) override; //законнектился
		void command_disconnect		() override; //расконнектились


		virtual bool onOpen()		{return false;};	//открытие данных
		virtual bool onClose()		{return false;};	//закрытие данных
		virtual void onConnect()	{};					//ктоо подсоеденился
		virtual void onDisconnect()	{};					//ктото отсоединлся

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

