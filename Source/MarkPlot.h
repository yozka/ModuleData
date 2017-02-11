#pragma once
#include <QObject>
#include <QSharedPointer>
#include <QWeakPointer>
#include "Mark.h"

#include "qcustomplot-source\qcustomplot.h"
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
	class AMarkPlot
	{
	public:

		AMarkPlot();
		virtual ~AMarkPlot();

		
		void createLabel(const PMark &mark, QCustomPlot *plot);

		void destroy();

	private:
		
		QCPItemText *mTextLabel;
		QCPItemLine *mArrow;
		//QCPItemCurve *mArrow;


	};
	///--------------------------------------------------------------------------------------




		
	///--------------------------------------------------------------------------------------
	typedef QSharedPointer<AMarkPlot> PMarkPlot;
	///--------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------
}//namespace

