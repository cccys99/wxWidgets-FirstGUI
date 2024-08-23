#include "MainFrame.h"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title) :wxFrame(nullptr, wxID_ANY, title)
{
	
	/* ����¼�
	wxPanel* panel = new wxPanel(this);
	wxButton* button = new wxButton(panel, wxID_ANY, "Button", wxPoint(300, 250), wxSize(200, 100));

	wxStatusBar* statusBar = CreateStatusBar();
	statusBar->SetDoubleBuffered(true); //�������Խ�����½���˸������

	//panel->Bind(wxEVT_LEFT_DOWN, &MainFrame::OnMouseEvent, this);
	//wxEVT_RIGHT_DOWN�Ҽ�������  wxEVT_MIDDLE_DOWN�м���ֱ����� wxEVT_LEFT_DCLCK���˫��

	panel->Bind(wxEVT_MOTION, &MainFrame::OnMouseEvent, this);
	//������ƶ���button��ʱ ״̬���еĹ��λ�þͲ������� ���������bind
	button->Bind(wxEVT_MOTION, &MainFrame::OnMouseEvent, this);
	*/
	
	wxPanel* panel = new wxPanel(this);

	panel->Bind(wxEVT_KEY_DOWN, &MainFrame::OnKeyEvent, this);

	CreateStatusBar();
}

//����¼�
/*
void MainFrame::OnMouseEvent(wxMouseEvent& evt)
{
	//��ʱ��panel��ʱ xy�����������panel�� ��button��ʱ xy�����������button��
	//��Ϊ��ȡλ�õķ���evt.GetPosition()����wxwidgets���õĿͻ���λ��
	//���������λ��������ڿؼ���
	//wxPoint mousePos = evt.GetPosition();

	wxPoint mousePos = wxGetMousePosition();
	mousePos = this->ScreenToClient(mousePos);
	wxString message = wxString::Format("Mouse Event Detected! (x=%d y=%d)", mousePos.x, mousePos.y);
	wxLogStatus(message);
}
*/

void MainFrame::OnKeyEvent(wxKeyEvent& evt)
{
	wxChar KeyChar = evt.GetUnicodeKey();
	if (KeyChar == WXK_NONE)
	{
		int KeyCode = evt.GetKeyCode(); //��ʾ����keycode
		wxLogStatus("Key Event %d", KeyCode);
	}
	else
	{
		wxLogStatus("Key Event %c", KeyChar);
	}	
}

