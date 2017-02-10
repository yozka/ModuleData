#include "CollectionProxy.h"
#include "DataProxy.h"
///--------------------------------------------------------------------------------------



///--------------------------------------------------------------------------------------
using namespace DataProxy;
///--------------------------------------------------------------------------------------










 ///=====================================================================================
///
/// Constructor
/// 
/// 
///--------------------------------------------------------------------------------------
ACollectionProxy :: ACollectionProxy (IInterface_receiv *parent)
	:
	mParent(parent)
{

}
///--------------------------------------------------------------------------------------







 ///=====================================================================================
///
/// Destructor
/// 
/// 
///--------------------------------------------------------------------------------------
ACollectionProxy :: ~ACollectionProxy ()
{
	disconnectAll();
}
///--------------------------------------------------------------------------------------






 ///=====================================================================================
///
/// ���������� �����������
/// 
/// 
///--------------------------------------------------------------------------------------
int ACollectionProxy :: count() const
{
	return mDataProxy.count();
}
///--------------------------------------------------------------------------------------






 ///=====================================================================================
///
/// 
/// 
/// 
///--------------------------------------------------------------------------------------
bool ACollectionProxy :: connect(const QSharedPointer<ADataProxy> &dataProxy)
{
	if (dataProxy.isNull())
	{
		return false;
	}

	if (mDataProxy.contains(dataProxy))
	{
		return true;
	}

	mDataProxy.append(dataProxy);
	return dataProxy->connect(sharedFromThis());
}
///--------------------------------------------------------------------------------------







 ///=====================================================================================
///
/// ��������� �������� ������
/// 
/// 
///--------------------------------------------------------------------------------------
bool ACollectionProxy :: disconnect(const QSharedPointer<ADataProxy> &dataProxy)
{
	if (!mDataProxy.contains(dataProxy))
	{
		return false;
	}
	auto old = PDataProxy(dataProxy);
	mDataProxy.removeAll(dataProxy);
	mParent->command_disconnect();	
	old->disconnect();
	return true;
}
///--------------------------------------------------------------------------------------







 ///=====================================================================================
///
/// �������� ��� ����������
/// 
/// 
///--------------------------------------------------------------------------------------
void ACollectionProxy :: disconnectAll()
{
	while (!mDataProxy.isEmpty())
	{
		disconnect(mDataProxy.last());
	}
}
///--------------------------------------------------------------------------------------







 ///=====================================================================================
///
/// ������� ������ ����� ������
/// 
/// 
///--------------------------------------------------------------------------------------
bool ACollectionProxy :: command_dataOpen()
{
	bool ret = false;
	for (auto item = mDataProxy.cbegin(); item != mDataProxy.cend(); ++item)
	{
		auto dataProxy = *item;
		if (dataProxy.isNull())
		{
			continue;
		}
		if (dataProxy->command_dataOpen())
		{
			ret = true;
		}
	}
	return ret;
}
///--------------------------------------------------------------------------------------







 ///=====================================================================================
///
/// ������� ����� ����� ������
/// 
/// 
///--------------------------------------------------------------------------------------
bool ACollectionProxy :: command_dataClose()
{
	bool ret = false;
	for (auto item = mDataProxy.cbegin(); item != mDataProxy.cend(); ++item)
	{
		auto dataProxy = *item;
		if (dataProxy.isNull())
		{
			continue;
		}
		if (dataProxy->command_dataClose())
		{
			ret = true;
		}
	}
	return ret;
}
///--------------------------------------------------------------------------------------







 ///=====================================================================================
///
/// �������� ������
/// 
/// 
///--------------------------------------------------------------------------------------
bool ACollectionProxy :: command_dataSend(const QVariant &value)
{
	bool ret = false;
	for (auto item = mDataProxy.cbegin(); item != mDataProxy.cend(); ++item)
	{
		auto dataProxy = *item;
		if (dataProxy.isNull())
		{
			continue;
		}
		if (dataProxy->command_dataSend(value))
		{
			ret = true;
		}
	}
	return ret;
}
///--------------------------------------------------------------------------------------







 ///=====================================================================================
///
/// ������� ���� �������� � �����������
/// 
/// 
///--------------------------------------------------------------------------------------
QList<IInterface_receiv*> ACollectionProxy :: childs() const
{
	QList<IInterface_receiv*> list;
	list.append(mParent);
	for (auto item = mDataProxy.constBegin(); item != mDataProxy.constEnd(); ++item)
	{
		auto dataProxy = *item;
		if (dataProxy.isNull())
		{
			continue;
		}

		QWeakPointer<ACollectionProxy> first = dataProxy->first();
		if (!first.isNull() && !list.contains(first.data()->mParent))
		{
			list.append(first.data()->mParent);
		}

		QWeakPointer<ACollectionProxy> second = dataProxy->second();
		if (!second.isNull() && !list.contains(second.data()->mParent))
		{
			list.append(second.data()->mParent);
		}

	}
	return list;
}

