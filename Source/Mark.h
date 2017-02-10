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
	/// ����� ����
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

		Marking::PWMarking marking() const; //��������� ��������� �� ����� 


		QString description() const; //�������� ��������
		QString time() const; //�����
		QString value() const; //��������

	private:

		double	mTime; //����� � ������������
		double	mValue;

		Marking::PWMarking mMarking;
	};
	///--------------------------------------------------------------------------------------




		
	///--------------------------------------------------------------------------------------
	typedef QSharedPointer<AMark> PMark;
	///--------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------
}//namespace

