#pragma once
#include <QSharedPointer>
#include <QTimer>
#include "DataSource.h"
///--------------------------------------------------------------------------------------

namespace DataSource
{
	///--------------------------------------------------------------------------------------




	namespace settings
	{
		const int min		= -200;
		const int max		= 200;
		const int interval	= 100;
	}






	 ///=====================================================================================
	///
	/// Источник данных
	/// 
	/// 
	///--------------------------------------------------------------------------------------
	class ARandomGenerator
			: 
				public ADataSource
	{


	public:
		ARandomGenerator();
		

		virtual ~ARandomGenerator();


		QString	title() const override; //возвратим имя источника данных
		void	show() override; //покажем диалог информации по источнику данных



	protected:
		
		void onOpen() override;		//открытие данных
		void onClose() override;	//закрытие данных

	private:

		int		mNumber; //номер генератора

		int		mInterval; //скорость работы таймера

		QTimer*	mTimer;

		qint64	mBeginMs; //время, начальный отчет

		void	update(); //обновление таймера

	};
	///--------------------------------------------------------------------------------------




		
	///--------------------------------------------------------------------------------------
	typedef QSharedPointer<ARandomGenerator> PRandomGenerator;
	///--------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------
}//namespace

