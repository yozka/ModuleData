#pragma once
#include <QObject>
#include <QSharedPointer>
#include <QWeakPointer>
#include "Marking.h"
///--------------------------------------------------------------------------------------



namespace Chart
{
	///--------------------------------------------------------------------------------------











	 ///=====================================================================================
	///
	/// Метка одна
	/// 
	/// 
	///--------------------------------------------------------------------------------------
	class AMark
			: 
				public QObject
	{
		Q_OBJECT
	public:

		AMark(const double time, const double value, const Marking::PWMarking &marking);
		virtual ~AMark();

		Marking::PWMarking marking() const; //возвратим указатель на метку 


		QString description() const; //возратим описание
		QString time() const; //время
		QString value() const; //значение

	private:

		double	mTime; //время в милисикундах
		double	mValue;

		Marking::PWMarking mMarking;
	};
	///--------------------------------------------------------------------------------------




		
	///--------------------------------------------------------------------------------------
	typedef QSharedPointer<AMark> PMark;
	///--------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------
}//namespace

