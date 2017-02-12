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
		virtual bool command_dataOpen		() = 0; //команда начало сбора данных
		virtual	bool command_dataClose		() = 0;   //команда конец сбора данных
		virtual bool command_dataReceive	(const QVariant &value) = 0;  //прием данных
		virtual void command_dataError		(const QString &error) = 0;	//произошла ошибка

		virtual void command_connect		(IInterface_receiv *obj) = 0; //подключение к источнику данных
		virtual void command_disconnect		() = 0; //отлкючение от источника данных
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
		int count() const; //количество подключений


		//команды
		bool command_dataOpen();	//команда начало сбора данных
		bool command_dataClose();   //команда конец сбора данных
		bool command_dataSend(const QVariant &value);  //передача данных
		void command_dataError(const QString &error); //ошибка в потоке данных

		QList<IInterface_receiv*> childs() const;//возьмем всех потомков с интерфейсом

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

