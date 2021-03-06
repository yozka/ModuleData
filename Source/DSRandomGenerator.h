﻿#pragma once
#include <QSharedPointer>
#include <QTimer>
#include "DataSource.h"
///--------------------------------------------------------------------------------------

namespace DataSource
{
	///--------------------------------------------------------------------------------------








	///--------------------------------------------------------------------------------------
	class ARandomGeneratorDialog;
	///--------------------------------------------------------------------------------------





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

		int interval() const; //возвратим интервал таймера
		void setInterval(const int value); //установим интервал таймера

		int lastTimeMS() const; //возвратим последнее время

	protected:
		
		bool onOpen() override;		//открытие данных
		bool onClose() override;	//закрытие данных
		void onConnect() override;	//ктоо подсоеденился
		void onDisconnect() override;//ктото отсоединлся
		
	private:

		int		mNumber; //номер генератора

		int		mInterval; //скорость работы таймера

		QTimer*	mTimer;

		qint64	mBeginMs; //время, начальный отчет
		int		mLastTime; //последие значения времени в милисикундах

		void	update(); //обновление таймера


		QSharedPointer<ARandomGeneratorDialog> mWidget;


		void refreshWidget();//обновим виджет
	};
	///--------------------------------------------------------------------------------------




		
	///--------------------------------------------------------------------------------------
	typedef QSharedPointer<ARandomGenerator> PRandomGenerator;
	///--------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------
}//namespace

