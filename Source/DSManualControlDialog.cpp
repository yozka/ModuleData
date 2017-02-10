#include "DSManualControlDialog.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QPushButton>
#include <QHeaderView>
#include <QWindow>
#include <QTime>

#include "DSManualControl.h"
#include "ModuleData.h"
///--------------------------------------------------------------------------------------



///--------------------------------------------------------------------------------------
using namespace DataSource;
///--------------------------------------------------------------------------------------






 ///=====================================================================================
///
/// Constructor
/// 
/// 
///--------------------------------------------------------------------------------------
AManualControlDialog :: AManualControlDialog ()
{
	setParent(AModuleData::main());
	setWindowFlags(Qt::Dialog);
	///setWindowFlags(Qt::Window);
	
	//setAttribute(Qt::WA_DeleteOnClose, true);
	setAttribute(Qt::WA_Resized, false);
	createUI(this);


}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// Destructor
/// 
/// 
///--------------------------------------------------------------------------------------
AManualControlDialog :: ~AManualControlDialog ()
{


}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// показать диалог редактирования
/// 
/// 
///--------------------------------------------------------------------------------------
void AManualControlDialog :: show(const QWeakPointer<AManualControl> &dataSource)
{
	mDataSource = dataSource;
	
	raise();
	activateWindow();
	refresh();

	QDialog::show();
}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// создание диалога
/// 
/// 
///--------------------------------------------------------------------------------------
void AManualControlDialog :: createUI(QWidget *form)
{
	int width = 300;
	int height = 200;

	form->setMinimumSize(QSize(width, height));
    form->setMaximumSize(QSize(width, height));


    form->resize(width, height);
  

    auto label = new QLabel(form);
	label->setText(QApplication::translate("random", "Status:", 0));
    label->setGeometry(QRect(20, 20, 91, 16));
    label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    label = new QLabel(form);
	label->setText(QApplication::translate("random", "Interval:", 0));
    label->setGeometry(QRect(20, 50, 91, 16));
    label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
    
	label = new QLabel(form);
	label->setText(QApplication::translate("random", "Count using:", 0));
    label->setGeometry(QRect(20, 80, 91, 16));
    label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

    mStatus = new QLabel(form);
    mStatus->setGeometry(QRect(120, 20, 171, 16));

    mCount = new QLabel(form);
    mCount->setGeometry(QRect(120, 80, 171, 16));

	mInterval = new QLineEdit(form);
    mInterval->setGeometry(QRect(120, 50, 161, 20));


	mDataCurrent = new QLabel(form);
    mDataCurrent->setGeometry(QRect(120, 105, 171, 16));

	mData = new QSlider(form);
    mData->setGeometry(QRect(10, 130, width - 20, 30));
	mData->setMinimum(settings::min);
	mData->setMaximum(settings::max);
    mData->setSingleStep(10);
    mData->setOrientation(Qt::Horizontal);
    mData->setTickPosition(QSlider::TicksBothSides);
    mData->setTickInterval(10);

	
	auto butHide = new QPushButton(form);
    butHide->setText(QApplication::translate("random", "Hide", 0));
	butHide->setGeometry(QRect(width - 80, height - 30, 75, 23));

	//
	connect(mData,		&QSlider::valueChanged, this, &AManualControlDialog::slot_editData);
	connect(butHide,	&QPushButton::clicked, this, &QDialog::close);
	//

    QMetaObject::connectSlotsByName(form);
}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// обновить данные
/// 
/// 
///--------------------------------------------------------------------------------------
void AManualControlDialog :: refresh()
{
	if (mDataSource.isNull())
	{
		setWindowTitle("Broken");
		mStatus->setText("-");
		mCount->setText("-");
		mInterval->setText("-");
		mInterval->setEnabled(false);
		mData->setValue(0);
		mDataCurrent->setText("-");
		return;
	}

	AManualControl *data = mDataSource.data();

	QString status = "stop";
	const bool run = data->isActive();
	if (run)
	{
		QTime time(0,0,0);
		time = time.addMSecs(data->lastTimeMS());
		status = QString("RUN - ") + time.toString("HH:mm:ss:zzz");
	}
	//mInterval->setEnabled(run);
	//mData->setEnabled(run);



	setWindowTitle(data->title());
	mStatus->setText(status);
	mCount->setText(QString::number(data->streamData->count()));
	mInterval->setText(QString::number(data->interval()));
	mDataCurrent->setText(QString::number(data->data()));
}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// завершили редактировать интервал данных
/// 
/// 
///--------------------------------------------------------------------------------------
void AManualControlDialog :: slot_editData(int value)
{
	mDataCurrent->setText(QString::number(value));
	if (!mDataSource.isNull())
	{
		AManualControl *data = mDataSource.data();
		if (data->isActive())
		{
			data->setInterval(mInterval->text().toInt());
			data->setData(value);
		}
	}
}