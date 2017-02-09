#pragma once
#include <QSharedPointer>
#include <QWeakPointer>
#include <QEnableSharedFromThis>
///--------------------------------------------------------------------------------------

namespace DataProxy
{
	///--------------------------------------------------------------------------------------




	///--------------------------------------------------------------------------------------
	class ACollectionProxy;
	///--------------------------------------------------------------------------------------





	 ///=====================================================================================
	///
	/// ������������� ������ ����� �����������
	/// 
	/// 
	///--------------------------------------------------------------------------------------
	class ADataProxy
		: 
			public QEnableSharedFromThis<ADataProxy>
	{


	public:
		ADataProxy();
		

		virtual ~ADataProxy();


		bool connect(const QSharedPointer<ACollectionProxy> &source);
		void disconnect(); //��������� �������� ������


		//�������
		void command_dataOpen();	//������� ������ ����� ������
		void command_dataClose();   //������� ����� ����� ������
		void command_dataSend(const QVariant &value);  //�������� ������

	private:

		QWeakPointer<ACollectionProxy> mSourceFirst;
		QWeakPointer<ACollectionProxy> mSourceSecond;

	};
	///--------------------------------------------------------------------------------------




		
	///--------------------------------------------------------------------------------------
	typedef QSharedPointer<ADataProxy> PDataProxy;
	///--------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------
}//namespace

