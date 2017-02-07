#pragma once
#include <QObject>
#include <QSharedPointer>
#include <QList>
#include "Marking.h"
///--------------------------------------------------------------------------------------

namespace Marking
{
	///--------------------------------------------------------------------------------------









	 ///=====================================================================================
	///
	/// Контейнер меток
	/// 
	/// 
	///--------------------------------------------------------------------------------------
	class AMarkingContainer
			: 
				public QObject
	{
		Q_OBJECT

	public:
		AMarkingContainer();
		virtual ~AMarkingContainer();


		int count() const; //количество элементов в контейнере
		PMarking item(const int index); //возвратим данные в контейнере
		void append(const PMarking &marking); //добовляем данные


	signals:
	
		void signal_change(); //данные поменялись, сигнал


	private:


		QList<PMarking> mMarkings; //данные


	private slots:

		void slot_change(const AMarking* marking); //изменение данных
	};
	///--------------------------------------------------------------------------------------




		
	///--------------------------------------------------------------------------------------
	typedef QSharedPointer<AMarkingContainer> PMarkingContainer;
	///--------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------
}//namespace

