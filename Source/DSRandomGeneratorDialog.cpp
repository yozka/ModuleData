#include "DSRandomGeneratorDialog.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QPushButton>
#include <QHeaderView>
#include <QWindow>
#include <QTime>

#include "DSRandomGenerator.h"
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
ARandomGeneratorDialog :: ARandomGeneratorDialog ()
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
ARandomGeneratorDialog :: ~ARandomGeneratorDialog ()
{


}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// показать диалог редактирования
/// 
/// 
///--------------------------------------------------------------------------------------
void ARandomGeneratorDialog :: show(const QWeakPointer<ARandomGenerator> &dataSource)
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
void ARandomGeneratorDialog :: createUI(QWidget *form)
{
    int width = 350;
	int height = 132;
	setMinimumSize(QSize(width, height));
    setMaximumSize(QSize(width, height));
	
	form->resize(width, height);
	auto butHide = new QPushButton(form);
    butHide->setText(QApplication::translate("random", "Hide", 0));
	butHide->setGeometry(QRect(width - 82, height - 30, 75, 23));

  

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

	//
	connect(mInterval,	&QLineEdit::textEdited, this, &ARandomGeneratorDialog::slot_editInterval);
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
void ARandomGeneratorDialog :: refresh()
{
	if (mDataSource.isNull())
	{
		setWindowTitle("Broken");
		mStatus->setText("-");
		mCount->setText("-");
		mInterval->setText("-");
		mInterval->setEnabled(false);
		return;
	}

	ARandomGenerator *data = mDataSource.data();

	QString status = "stop";
	const bool run = data->isActive();
	if (run)
	{
		QTime time(0,0,0);
		time = time.addMSecs(data->lastTimeMS());
		status = QString("RUN - ") + time.toString("HH:mm:ss:zzz");
	}
	mInterval->setEnabled(!run);

	setWindowTitle(data->title());
	mStatus->setText(status);
	mCount->setText(QString::number(data->streamData->count()));
	mInterval->setText(QString::number(data->interval()));
}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// завершили редактировать интервал данных
/// 
/// 
///--------------------------------------------------------------------------------------
void ARandomGeneratorDialog :: slot_editInterval(const QString &text)
{
	if (!mDataSource.isNull())
	{
		mDataSource.data()->setInterval(text.toInt());
	}
}