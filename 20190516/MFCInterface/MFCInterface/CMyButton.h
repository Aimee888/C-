#pragma once
#include <afxwin.h>
class CMyButton : public CButton
{
	//DECLARE_DYNAMIC(CMyButton)

public:
	CMyButton();

	virtual ~CMyButton();

	//��ť����ͼ��
	CImage m_imgButton;

	//��ťpng·�����������㣬����������3��״̬
	CString m_strImgPath;

	//�����ڱ���ͼƬ����·����͸��png��Ҫʹ��
	CString m_strImgParentPath;

	//���ð�ť����ͼƬ·���������ڱ���ͼƬ·��
	void SetImagePath(CString strImgPath, CString strParentImgPath);

	//��ʼ����ť����Ҫ�ǵ�����ť��λ�ã�����͸��ɫ
	bool InitMyButton(int nX/*���Ͻ�X����*/, int nY/*���Ͻ�Y����*/, int nW/*ͼ���*/, int nH/*ͼ���*/, bool bIsPng/*�Ƿ���PNGͼƬ*/);

	//�Ի��ƺ���
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
//
//protected:
//	DECLARE_MESSAGE_MAP()
};

