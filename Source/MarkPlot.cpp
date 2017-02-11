#include "MarkPlot.h"
#include "Marking.h"

///--------------------------------------------------------------------------------------



///--------------------------------------------------------------------------------------
using namespace Chart;
///--------------------------------------------------------------------------------------














 ///=====================================================================================
///
/// Constructor
/// 
/// 
///--------------------------------------------------------------------------------------
AMarkPlot :: AMarkPlot ()
	:
	mTextLabel(nullptr),
	mArrow(nullptr)
{

}
///--------------------------------------------------------------------------------------









 ///=====================================================================================
///
/// Destructor
/// 
/// 
///--------------------------------------------------------------------------------------
AMarkPlot :: ~AMarkPlot ()
{

}
///--------------------------------------------------------------------------------------









 ///=====================================================================================
///
/// 
/// 
/// 
///--------------------------------------------------------------------------------------
void AMarkPlot :: createLabel(const PMark &mark, QCustomPlot *plot)
{
	destroy();

	QStringList caption;
	caption << mark->description();
	caption << "Value: " + mark->valueToString();
	caption << "Time: " + mark->timeToString();

	// add the text label at the top:
	mTextLabel = new QCPItemText(plot);
	
	mTextLabel->setPositionAlignment(Qt::AlignTop|Qt::AlignHCenter);
	mTextLabel->position->setType(QCPItemPosition::ptAxisRectRatio);
	mTextLabel->position->setCoords(0.35f, 0.01f); // place position at center/top of axis rect
	mTextLabel->setPadding(QMargins(8, 8, 8, 8));

	mTextLabel->setText(caption.join("\n"));
	mTextLabel->setFont(QFont(QFont().family(), 10)); // make font a bit larger
	mTextLabel->setColor(QColor(191, 123, 76, 255));

	//color
	QPen pen;
	pen.setColor(QColor(255, 133, 50, 200));
	pen.setWidthF(3);
	mTextLabel->setPen(pen);
	mTextLabel->setBrush(QBrush(QColor(255,255,255,200)));


	// add the arrow:
	mArrow = new QCPItemLine(plot);
	mArrow->setPen(pen);
	mArrow->start->setParentAnchor(mTextLabel->bottom);
	mArrow->end->setCoords(mark->time(), mark->value()); 
	mArrow->setHead(QCPLineEnding::esSpikeArrow);



	plot->replot();
}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// 
/// 
/// 
///--------------------------------------------------------------------------------------
void AMarkPlot :: destroy()
{
	if (mArrow)
	{
		auto *parent = mArrow->parentPlot();
		if (parent != nullptr)
		{
			parent->removeItem(mArrow);
		}
		else
		{
			delete mArrow;
		}
		mArrow = nullptr;
	}

	if (mTextLabel)
	{
		auto *parent = mTextLabel->parentPlot();
		if (parent != nullptr)
		{
			parent->removeItem(mTextLabel);
		}
		else
		{
			delete mTextLabel;
		}
		mTextLabel= nullptr;
	}
}
///--------------------------------------------------------------------------------------






 ///=====================================================================================
///
/// возвратим, это корневая ссылка или нет
/// 
/// 
///--------------------------------------------------------------------------------------
/*
bool AMarkPlot :: isRoot() const
{
	return mRoot;
}*/
///--------------------------------------------------------------------------------------


