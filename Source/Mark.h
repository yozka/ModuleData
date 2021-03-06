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

		AMark(const Marking::PWMarking &marking);
		AMark(const double time, const double value, const Marking::PWMarking &marking);
		virtual ~AMark();

		Marking::PWMarking marking() const; //��������� ��������� �� ����� 


		QString description() const; //�������� ��������
		QString timeToString() const; //�����
		double	time() const; //�����
		QString valueToString() const; //��������
		double  value() const; //��������

		bool isRoot() const; //���������, ��� �������� ������ ��� ���

	private:
		bool	mRoot; //�������� ����
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

