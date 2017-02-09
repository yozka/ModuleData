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
void ADataProxy :: command_dataOpen()
{
	if (!mSourceFirst.isNull())
	{
		mSourceFirst.data()->parent()->command_dataOpen();
	}

	if (!mSourceSecond.isNull())
	{
		mSourceSecond.data()->parent()->command_dataOpen();
	}
}
///--------------------------------------------------------------------------------------







 ///=====================================================================================
///
/// ������� ����� ����� ������
/// 
/// 
///--------------------------------------------------------------------------------------
void ADataProxy :: command_dataClose()
{
	if (!mSourceFirst.isNull())
	{
		mSourceFirst.data()->parent()->command_dataClose();
	}

	if (!mSourceSecond.isNull())
	{
		mSourceSecond.data()->parent()->command_dataClose();
	}
}
///--------------------------------------------------------------------------------------







 ///=====================================================================================
///
/// �������� ������
/// 
/// 
///--------------------------------------------------------------------------------------
void ADataProxy :: command_dataSend(const QVariant &value)
{
	if (!mSourceFirst.isNull())
	{
		mSourceFirst.data()->parent()->command_dataReceive(value);
	}

	if (!mSourceSecond.isNull())
	{
		mSourceSecond.data()->parent()->command_dataReceive(value);
	}
}


