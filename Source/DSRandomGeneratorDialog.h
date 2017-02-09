#pragma once
#include <QObject>
#include <QWeakPointer>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>




///--------------------------------------------------------------------------------------
#include "DSRandomGenerator.h"
///--------------------------------------------------------------------------------------


namespace DataSource
{
	///--------------------------------------------------------------------------------------






	 ///=====================================================================================
	///
	/// Контейнер меток
	/// 
	/// 
	///--------------------------------------------------------------------------------------
	class ARandomGeneratorDialog
			: 
			public QDialog
	{
		Q_OBJECT

	public:
		ARandomGeneratorDialog();
		virtual ~ARandomGeneratorDialog();



		void show(const QWeakPointer<ARandomGenerator> &dataSource); //показать диалог
		void refresh(); //обновить данные



	private:

		QWeakPointer<ARandomGenerator>	mDataSource;	//данные
		QLabel*				mStatus;		//статуст генератора
		QLabel*				mCount;			//количество подцепленных приемников
		QLineEdit*			mInterval;		//интервал

		void createUI(QWidget *form);//создание диалога

	private slots:

		void slot_editInterval(const QString &text); //завершили редактировать интервал данных
	};
	///--------------------------------------------------------------------------------------





	
	
	///--------------------------------------------------------------------------------------
	typedef QSharedPointer<ARandomGeneratorDialog> PRandomGeneratorDialog;
	///--------------------------------------------------------------------------------------





//-------------------------------------------------------------------------------------------
}//namespace

