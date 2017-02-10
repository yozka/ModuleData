#include "DataProxy.h"
#include "CollectionProxy.h"
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
ADataProxy :: ADataProxy ()
{

}
///--------------------------------------------------------------------------------------







 ///=====================================================================================
///
/// Destructor
/// 
/// 
///--------------------------------------------------------------------------------------
ADataProxy :: ~ADataProxy ()
{
	disconnect();
}
///--------------------------------------------------------------------------------------










 ///=====================================================================================
///
/// 
/// 
/// 
///--------------------------------------------------------------------------------------
bool ADataProxy :: connect(const QSharedPointer<ACollectionProxy> &source)
{
	if (source.isNull())
	{
		return false;
	}

	if (mSourceFirst == source || mSourceSecond == source)
	{
		//������������ ��� ����
		return true;
	}

	if (mSourceFirst.isNull())
	{
		mSourceFirst = source;
	}
	else
		if (mSourceSecond.isNull())
		{
			mSourceSecond = source;
		}
		else
		{
			//��� ���� ��� ���������
			return false;
		}

	const bool ret = source->connect(sharedFromThis());

	if (ret)
	{
		if (!mSourceSecond.isNull() && !mSourceFirst.isNull())
		{
			mSourceSecond.data()->parent()->command_connect(mSourceFirst.data()->parent());
			mSourceFirst.data()->parent()->command_connect(mSourceSecond.data()->parent());
		}
		
	}

	return ret;

}
///--------------------------------------------------------------------------------------







 ///=====================================================================================
///
/// ��������� �������� ������
/// 
/// 
///--------------------------------------------------------------------------------------
void ADataProxy :: disconnect()
{
	if (!mSourceFirst.isNull())
	{
		mSourceFirst.data()->disconnect(sharedFromThis());
		mSourceFirst = PCollectionProxy();
	}

	if (!mSourceSecond.isNull())
	{
		mSourceSecond.data()->disconnect(sharedFromThis());
		mSourceSecond = PCollectionProxy();
	}
}
///--------------------------------------------------------------------------------------







 ///=====================================================================================
///
/// ������� ������ ����� ������
/// 
/// 
///--------------------------------------------------------------------------------------
bool ADataProxy :: command_dataOpen()
{
	bool ret = false;
	if (!mSourceFirst.isNull())
	{
		if (mSourceFirst.data()->parent()->command_dataOpen())
		{
			ret = true;
		}
	}

	if (!mSourceSecond.isNull())
	{
		if (mSourceSecond.data()->parent()->command_dataOpen())
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
bool ADataProxy :: command_dataClose()
{
	bool ret = false;
	if (!mSourceFirst.isNull())
	{
		if (mSourceFirst.data()->parent()->command_dataClose())
		{
			ret = true;
		}
	}

	if (!mSourceSecond.isNull())
	{
		if (mSourceSecond.data()->parent()->command_dataClose())
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
bool ADataProxy :: command_dataSend(const QVariant &value)
{
	bool ret = false;
	if (!mSourceFirst.isNull())
	{
		if (mSourceFirst.data()->parent()->command_dataReceive(value))
		{
			ret = true;
		}
	}

	if (!mSourceSecond.isNull())
	{
		if (mSourceSecond.data()->parent()->command_dataReceive(value))
		{
			ret = true;
		}
	}
	return ret;
}
///--------------------------------------------------------------------------------------







 ///=====================================================================================
///
/// ������ �������� ������
/// 
/// 
///--------------------------------------------------------------------------------------
QWeakPointer<ACollectionProxy> ADataProxy :: first() const
{
	return mSourceFirst;
}
///--------------------------------------------------------------------------------------







 ///=====================================================================================
///
/// ������ �������� ������
/// 
/// 
///--------------------------------------------------------------------------------------
QWeakPointer<ACollectionProxy> ADataProxy :: second() const
{
	return mSourceSecond;
}
