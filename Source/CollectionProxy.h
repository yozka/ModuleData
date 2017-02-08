#pragma once
#include <QSharedPointer>
#include <QWeakPointer>
#include <QEnableSharedFromThis>
#include <QList>
///--------------------------------------------------------------------------------------

namespace DataProxy
{
	///--------------------------------------------------------------------------------------




	///--------------------------------------------------------------------------------------
	class ADataProxy;
	typedef QList<QSharedPointer<ADataProxy>> AListProxy;
	///--------------------------------------------------------------------------------------





	

	 ///=====================================================================================
	///
	/// Интерфейс
	/// 
	/// 
	///--------------------------------------------------------------------------------------
	class IInterface_receiv
	{
	public:
		virtual void command_dataBegin() = 0; //команда начало сбора данных
		virtual	void command_dataEnd() = 0;   //команда конец сбора данных
		virtual void command_dataReceive(const QVariant &value) = 0;  //прием данных
	};
	///--------------------------------------------------------------------------------------






	 ///=====================================================================================
	///
	/// Колллекция проксируемых данных
	/// 
	/// 
	///--------------------------------------------------------------------------------------
	class ACollectionProxy
		: 
			public QEnableSharedFromThis<ACollectionProxy>
	{


	public:
		ACollectionProxy(IInterface_receiv *parent);
		virtual ~ACollectionProxy();

		IInterface_receiv*	parent() const {return mParent;};


		bool connect	(const QSharedPointer<ADataProxy> &dataProxy);
		bool disconnect	(const QSharedPointer<ADataProxy> &dataProxy); //отключаем источник данных
		void disconnectAll(); //отключим все соеденения

		//команды
		void command_dataBegin(); //команда начало сбора данных
		void command_dataEnd();   //команда конец сбора данных
		void command_dataSend(const QVariant &value);  //передача данных

	private:

		AListProxy			mDataProxy;
		IInterface_receiv*	mParent;

	};
	///--------------------------------------------------------------------------------------




		
	///--------------------------------------------------------------------------------------
	typedef QSharedPointer<ACollectionProxy> PCollectionProxy;
	///--------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------
}//namespace

