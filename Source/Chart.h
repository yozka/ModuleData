#pragma once
#include <QObject>
#include <QSharedPointer>
#include <QString>
///--------------------------------------------------------------------------------------

namespace Chart
{
	///--------------------------------------------------------------------------------------









	 ///=====================================================================================
	///
	/// ���� ������
	/// 
	/// 
	///--------------------------------------------------------------------------------------
	class AChart
			: 
				public QObject
	{
		Q_OBJECT

	public:
		AChart();


		virtual ~AChart();




	private:



	private slots:

		//void slot_change(const AMarking* marking); //��������� ������
	};
	///--------------------------------------------------------------------------------------




		
	///--------------------------------------------------------------------------------------
	typedef QSharedPointer<AChart> PChart;
	///--------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------
}//namespace

