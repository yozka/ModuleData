#include "TimeTicker.h"



ATimeTicker :: ATimeTicker()
	:
	mZeroTime(0,0,0)
{

}


QString ATimeTicker :: getTickLabel(double tick, const QLocale &locale, QChar formatChar, int precision)
{
	const QTime time = mZeroTime.addMSecs(tick);
	return time.toString("HH:mm:ss");
}