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
		virtual void command_dataOpen		() = 0; //������� ������ ����� ������
		virtual	void command_dataClose		() = 0;   //������� ����� ����� ������
		virtual void command_dataReceive	(const QVariant &value) = 0;  //����� ������
		virtual void command_connect		(IInterface_receiv *obj) = 0; //����������� � ��������� ������
		virtual void command_disconnect		() = 0; //���������� �� ��������� ������
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
		int count() const; //���������� �����������


		//�������
		void command_dataOpen();	//������� ������ ����� ������
		void command_dataClose();   //������� ����� ����� ������
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

