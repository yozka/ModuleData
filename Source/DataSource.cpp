﻿#include "DataSource.h"
#include <QVariant>
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
ADataSource :: ADataSource ()
	:
	streamData(DataProxy::PCollectionProxy(new DataProxy::ACollectionProxy(this))),
	mActive(false),
	mRefOpen(0)
{


}
///--------------------------------------------------------------------------------------







 ///=====================================================================================
///
/// Destructor
/// 
/// 
///--------------------------------------------------------------------------------------
ADataSource :: ~ADataSource ()
{
	clear();
}
///--------------------------------------------------------------------------------------






 ///=====================================================================================
///
/// принудительно закрытие данных
/// 
/// 
///--------------------------------------------------------------------------------------
void ADataSource :: close()
{
	if (mActive)
	{
		mActive = false;
		onClose();
		mRefOpen = 0;
	}
}
///--------------------------------------------------------------------------------------






 ///=====================================================================================
///
/// покажем диалог информации по источнику данных
/// 
/// 
///--------------------------------------------------------------------------------------
void ADataSource :: slot_show()
{
	show();
}
///--------------------------------------------------------------------------------------








 ///=====================================================================================
///
/// команда начало сбора данных
/// 
/// 
///--------------------------------------------------------------------------------------
bool ADataSource :: command_dataOpen()
{
	if (!mActive)
	{
		mActive = true;
		onOpen();
	}

	if (mActive)
	{
		mRefOpen++;
	}
	return mActive;
}
///--------------------------------------------------------------------------------------






 ///=====================================================================================
///
/// команда конца сбора данных
/// 
/// 
///--------------------------------------------------------------------------------------
bool ADataSource :: command_dataClose()
{
	mRefOpen--;
	if (mRefOpen < 0)
	{
		mRefOpen = 0;
	}

	if (mRefOpen == 0)
	{
		close();
	}
	return true;
}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// очистка всего
/// 
/// 
///--------------------------------------------------------------------------------------
void ADataSource :: clear()
{
	close();
	streamData->disconnectAll();
}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// возвратим активность источника
/// 
/// 
///--------------------------------------------------------------------------------------
bool ADataSource :: isActive() const
{
	return mActive;
}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// законнектился
/// 
/// 
///--------------------------------------------------------------------------------------
void ADataSource :: command_connect	(IInterface_receiv *obj)
{
	onConnect();
}
///--------------------------------------------------------------------------------------





 ///=====================================================================================
///
/// расконнектились
/// 
/// 
///--------------------------------------------------------------------------------------
void ADataSource :: command_disconnect	()
{
	if (mActive && streamData->count() == 0)
	{
		close();
	}
	onDisconnect();
}
