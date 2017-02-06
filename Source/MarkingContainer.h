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
	/// ��������� �����
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


		int count() const; //���������� ��������� � ����������
		PMarking item(const int index); //��������� ������ � ����������
		void append(const PMarking &marking); //��������� ������


	signals:
	
		void signal_change(); //������ ����������, ������


	private:


		QList<PMarking> mMarkings; //������


	private slots:

		void slot_change(const AMarking* marking); //��������� ������
	};
	///--------------------------------------------------------------------------------------




		
	///--------------------------------------------------------------------------------------
	typedef QSharedPointer<AMarkingContainer> PMarkingContainer;
	///--------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------
}//namespace

