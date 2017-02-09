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
		void command_dataOpen();	//команда начало сбора данных
		void command_dataClose();   //команда конец сбора данных
		void command_dataSend(const QVariant &value);  //передача данных

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

