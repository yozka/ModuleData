#include "TimeTicker.h"

QTime ATimeTicker :: mZeroTime(0,0,0);

ATimeTicker :: ATimeTicker()
{

}


QString ATimeTicker :: getTickLabel(double tick, const QLocale &locale, QChar formatChar, int precision)
{
	if (tick < 0)
	{
		return "";
	}
	
	const QTime time = mZeroTime.addMSecs(tick);
	return time.toString("HH:mm:ss");
}



QString ATimeTicker :: timeToString(const int tick)
{
	const QTime time = mZeroTime.addMSecs(tick);
	return time.toString("HH:mm:ss");
}