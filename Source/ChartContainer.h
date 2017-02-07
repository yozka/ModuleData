#pragma once
#include <QObject>
#include <QSharedPointer>
#include <QList>
#include "Chart.h"
///--------------------------------------------------------------------------------------

namespace Chart
{
	///--------------------------------------------------------------------------------------









	 ///=====================================================================================
	///
	/// ��������� �������
	/// 
	/// 
	///--------------------------------------------------------------------------------------
	class AChartContainer
			: 
				public QObject
	{
		Q_OBJECT

	public:
		AChartContainer();
		virtual ~AChartContainer();


		int count() const; //���������� ��������� � ����������
		PChart item(const int index); //��������� ������ � ����������
		void append(const PChart &chart); //��������� ������

		bool isContains(const PChart

	signals:
	
		void signal_change(); //������ ����������, ������


	private:


		QList<PChart> mCharts; //������


	private slots:

		void slot_change(const AChart* chart); //��������� ������
	};
	///--------------------------------------------------------------------------------------




		
	///--------------------------------------------------------------------------------------
	typedef QSharedPointer<AChartContainer> PChartContainer;
	///--------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------
}//namespace

