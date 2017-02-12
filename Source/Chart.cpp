﻿#include "Chart.h"
#include "ChartWidget.h"
#include "DataSource.h"
#include <QVariant>
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
		:
	streamData(DataProxy::PCollectionProxy(new DataProxy::ACollectionProxy(this))),
	mRun(false),
	mChartWidget(nullptr),
	mZeroTime(0),
	mInitTime(false),
	mTimer(nullptr),
	mBeginMs(0)
	
	

{
	gNumberChart++;
	mNumber = gNumberChart;

	mTimer = new QTimer(this);
	connect(mTimer, &QTimer::timeout, this, &AChart::updateTime);
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
	clear();
	delete mTimer;
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
	QString sRun = mRun ? " [RUN]" : QString();
	return "Chart mn - " + QString::number(mNumber) + sRun;
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
	if (mChartWidget != nullptr)
	{
		delete mChartWidget;
		mChartWidget = nullptr;
	}

	mChartWidget = new AChartWidget();
	connect(mChartWidget, &QObject::destroyed, this, &AChart::slot_destroyedWidget);

	mChartWidget->setMarking(mMarking);
	refreshWidgets();
	return mChartWidget;
}
///--------------------------------------------------------------------------------------






 ///=====================================================================================
///
/// даление виджета
/// 
/// 
///--------------------------------------------------------------------------------------
void AChart :: slot_destroyedWidget(QObject *obj)
{
	auto frame = static_cast<AChartWidget*>(obj);
	if (frame != nullptr && frame == mChartWidget)
	{
		mChartWidget = nullptr;
	}
}
///--------------------------------------------------------------------------------------






 ///=====================================================================================
///
/// очистка всей диаграммы, уберание всех зависемостей
/// 
/// 
///--------------------------------------------------------------------------------------
void AChart :: clear()
{
	mMarking = Marking::PMarkingContainer();
	if (mChartWidget != nullptr)
	{
		mChartWidget->clear();
	}
	reset();
}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// установка действующих закладок
/// 
/// 
///--------------------------------------------------------------------------------------
void AChart :: setMarking(const Marking::PMarkingContainer &marking)
{
	mMarking = marking;
}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// запуск сбора данных
/// 
/// 
///--------------------------------------------------------------------------------------
void AChart :: play()
{
	if (mRun)
	{
		return;
	}
	mRun = true;

	mBeginMs = QDateTime::currentMSecsSinceEpoch();
	mTimer->start(100);

	const int reservSize = 1000 * 60 * 60; 
	mContentTime.reserve(reservSize);
	mContentData.reserve(reservSize);

	mInitTime = true;

	mRun = streamData->command_dataOpen();
	refreshWidgets();
	
	emit signal_change();
}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// приастоновка сбора данных
/// 
/// 
///--------------------------------------------------------------------------------------
void AChart :: pause()
{
	if (!mRun)
	{
		return;
	}
	streamData->command_dataClose();
	mRun = false;
	refreshWidgets();
	emit signal_change();
}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// перезапуск сбора данных
/// 
/// 
///--------------------------------------------------------------------------------------
void AChart :: stop()
{
	if (mRun)
	{
		streamData->command_dataClose();
		mRun = false;
	}

	//очистка всех буферов данных
	reset();
	emit signal_change();
}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// прием данных
/// 
/// 
///--------------------------------------------------------------------------------------
bool AChart :: command_dataReceive(const QVariant &value)
{
	if (!mRun)
	{
		return false;
	}
	
	const auto ds = qvariant_cast<QList<int>>(value);
	if (ds.count() != 2)
	{
		return false;
	}

	const double dTime = ds[0];
	const double dData = ds[1];

	if (mInitTime)
	{
		mZeroTime = dTime;
		if (!mContentTime.isEmpty())
		{
			mZeroTime -= mContentTime.last();
		}
		mInitTime = false;
	}


	append(dTime - mZeroTime, dData);
	return true;
}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// законнектился
/// 
/// 
///--------------------------------------------------------------------------------------
void AChart :: command_connect(IInterface_receiv *obj)
{
	const auto data = dynamic_cast<DataSource::ADataSource*>(obj);
	if (data == nullptr)
	{
		return;
	}

	QString title = data->title();

	refreshWidgets();
	emit signal_change();
}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// расконнектились
/// 
/// 
///--------------------------------------------------------------------------------------
void AChart :: command_disconnect()
{
	pause();
	refreshWidgets();
	emit signal_change();
}
///--------------------------------------------------------------------------------------






 ///=====================================================================================
///
/// произошла ошибка
/// 
/// 
///--------------------------------------------------------------------------------------
void AChart :: command_dataError (const QString &error)
{
	pause();
}
///--------------------------------------------------------------------------------------






 ///=====================================================================================
///
/// удаление сброс всех данных
/// 
/// 
///--------------------------------------------------------------------------------------
void AChart :: reset()
{
	mContentTime.clear();
	mContentData.clear();
	if (mRun)
	{
		streamData->command_dataClose();
		mRun = false;
	}

	if (mChartWidget != nullptr)
	{
		mChartWidget->reset();
	}
	refreshWidgets();
	emit signal_change();
}
///--------------------------------------------------------------------------------------







 ///=====================================================================================
///
/// расконнектились
/// 
/// 
///--------------------------------------------------------------------------------------
void AChart :: refreshWidgets()
{
	if (mChartWidget == nullptr)
	{
		return;
	}

	auto dataSource = currentDataSource();
	mChartWidget->setNameDataSource(dataSource.isNull() ? "[none]" : dataSource->title());
	mChartWidget->setRun(mRun);
	//mChartWidget->

}
///--------------------------------------------------------------------------------------







 ///=====================================================================================
///
/// добавить данные в виджеты
/// 
/// 
///--------------------------------------------------------------------------------------
void AChart :: append(const double time, const double data)
{
	mContentTime.append(time);
	mContentData.append(data);

	
	if (mChartWidget != nullptr)
	{
		mChartWidget->append(time, data);
	}
}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// возвратим текущий подключенный источник
/// 
/// 
///--------------------------------------------------------------------------------------
DataSource::PDataSource AChart :: currentDataSource() const
{
	auto childs = streamData->childs();
	for (auto item = childs.constBegin(); item != childs.constEnd(); ++item)
	{
		auto *obj = *item;
		auto *source = dynamic_cast<DataSource::ADataSource*>(obj);
		if (source == nullptr)
		{
			continue;
		}
		return source->sharedFromThis();
	}
	return DataSource::PDataSource();
}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// проверка, запущенно или нет
/// 
/// 
///--------------------------------------------------------------------------------------
bool AChart :: isRun() const
{
	return mRun;
}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// время обновления
/// 
/// 
///--------------------------------------------------------------------------------------
void AChart :: updateTime()
{
	if (!mRun)
	{
		mTimer->stop();
		return;
	}

	const int timeMs = QDateTime::currentMSecsSinceEpoch() - mBeginMs;
	if (mChartWidget == nullptr)
	{
		return;
	}
	mChartWidget->setTimeRun(timeMs);
}