﻿#include "Chart.h"
///--------------------------------------------------------------------------------------



///--------------------------------------------------------------------------------------
using namespace Chart;
///--------------------------------------------------------------------------------------




///--------------------------------------------------------------------------------------
int gNumberChart = 0;
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// Constructor
/// 
/// 
///--------------------------------------------------------------------------------------
AChart :: AChart ()
	
{
	gNumberChart++;
	mNumber = gNumberChart;

}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// Destructor
/// 
/// 
///--------------------------------------------------------------------------------------
AChart :: ~AChart ()
{


}
///--------------------------------------------------------------------------------------







 ///=====================================================================================
///
/// возвратим название диаграмы
/// 
/// 
///--------------------------------------------------------------------------------------
QString AChart :: title() const
{
	return "Chart mn - " + QString::number(mNumber);
}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// создание представление данных
/// 
/// 
///--------------------------------------------------------------------------------------
QWidget* AChart :: createWidget()
{
	QWidget *frame = new QWidget();

	return frame;
}
///--------------------------------------------------------------------------------------






