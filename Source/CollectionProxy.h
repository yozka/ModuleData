#pragma once
#include <QSharedPointer>
#include <QWeakPointer>
#include <QEnableSharedFromThis>
#include <QList>
///--------------------------------------------------------------------------------------

namespace DataProxy
{
	///--------------------------------------------------------------------------------------




	///--------------------------------------------------------------------------------------
	class ADataProxy;
	typedef QList<QSharedPointer<ADataProxy>> AListProxy;
	///--------------------------------------------------------------------------------------





	

	 ///=====================================================================================
	///
	/// ���������
	/// 
	/// 
	///--------------------------------------------------------------------------------------
	class IInterface_receiv
	{
	public:
		virtual void command_dataBegin() = 0; //������� ������ ����� ������
		virtual	void command_dataEnd() = 0;   //������� ����� ����� ������
		virtual void command_dataReceive(const QVariant &value) = 0;  //����� ������
	};
	///--------------------------------------------------------------------------------------






	 ///=====================================================================================
	///
	/// ���������� ������������ ������
	/// 
	/// 
	///--------------------------------------------------------------------------------------
	class ACollectionProxy
		: 
			public QEnableSharedFromThis<ACollectionProxy>
	{


	public:
		ACollectionProxy(IInterface_receiv *parent);
		virtual ~ACollectionProxy();

		IInterface_receiv*	parent() const {return mParent;};


		bool connect	(const QSharedPointer<ADataProxy> &dataProxy);
		bool disconnect	(const QSharedPointer<ADataProxy> &dataProxy); //��������� �������� ������
		void disconnectAll(); //�������� ��� ����������

		//�������
		void command_dataBegin(); //������� ������ ����� ������
		void command_dataEnd();   //������� ����� ����� ������
		void command_dataSend(const QVariant &value);  //�������� ������

	private:

		AListProxy			mDataProxy;
		IInterface_receiv*	mParent;

	};
	///--------------------------------------------------------------------------------------




		
	///--------------------------------------------------------------------------------------
	typedef QSharedPointer<ACollectionProxy> PCollectionProxy;
	///--------------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------
}//namespace

