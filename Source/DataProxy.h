#pragma once
#include <QSharedPointer>
#include <QWeakPointer>
#include <QEnableSharedFromThis>
///--------------------------------------------------------------------------------------

namespace DataProxy
{
	///--------------------------------------------------------------------------------------




	///--------------------------------------------------------------------------------------
	class ACollectionProxy;
	///--------------------------------------------------------------------------------------





	 ///=====================================================================================
	///
	/// ѕроксирование данных между источниками
	/// 
	/// 
	///--------------------------------------------------------------------------------------
	class ADataProxy
		: 
			public QEnableSharedFromThis<ADataProxy>
	{


	public:
		ADataProxy();
		

		virtual ~ADataProxy();


		bool connect(const QSharedPointer<ACollectionProxy> &source);
		void disconnect(); //отключаем источник данных


		//команды
		bool command_dataOpen();	//команда начало сбора данных
		bool command_dataClose();   //команда конец сбора данных
		bool command_dataSend(const QVariant &value);  //передача данных
		void command_dataError(const QString &error);  //передача ошибки

		QWeakPointer<ACollectionProxy> first() const; //первый источник данных
		QWeakPointer<ACollectionProxy> second() const; //второй источник данных

	private:

		QWeakPointer<ACollectionProxy> mSourceFirst;
		QWeakPointer<ACollectionProxy> mSourceSecond;

	};
	///--------------------------------------------------------------------------------------




		
	///--------------------------------------------------------------------------------------
	typedef QSharedPointer<ADataProxy> PDataProxy;
	///--------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------
}//namespace

