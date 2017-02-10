#pragma once
#include <QObject>
#include <QSharedPointer>
#include <QWeakPointer>
#include <QString>
///--------------------------------------------------------------------------------------

namespace Marking
{
	///--------------------------------------------------------------------------------------









	 ///=====================================================================================
	///
	/// Одна метка
	/// 
	/// 
	///--------------------------------------------------------------------------------------
	class AMarking
			: 
				public QObject
	{
		Q_OBJECT

	public:
		AMarking();
		AMarking(const int value, const QString &description);

		virtual ~AMarking();


		int value() const;				//значение метки
		QString description() const;	//пояснение метки

		bool isCheck(const int value) const; //проверка, данное число подходит к закладке илил нет

	private:

		int mValue;
		QString mDescription;


	private slots:

		//void slot_change(const AMarking* marking); //изменение данных
	};
	///--------------------------------------------------------------------------------------




		
	///--------------------------------------------------------------------------------------
	typedef QSharedPointer<AMarking> PMarking;
	typedef QWeakPointer<AMarking> PWMarking;
	///--------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------
}//namespace

