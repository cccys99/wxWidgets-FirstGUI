#include "MainFrame.h"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& title) :wxFrame(nullptr, wxID_ANY, title)
{
	
	/* 鼠标事件
	wxPanel* panel = new wxPanel(this);
	wxButton* button = new wxButton(panel, wxID_ANY, "Button", wxPoint(300, 250), wxSize(200, 100));

	wxStatusBar* statusBar = CreateStatusBar();
	statusBar->SetDoubleBuffered(true); //这样可以解决左下角闪烁的问题

	//panel->Bind(wxEVT_LEFT_DOWN, &MainFrame::OnMouseEvent, this);
	//wxEVT_RIGHT_DOWN右键被按下  wxEVT_MIDDLE_DOWN中间滚轮被按下 wxEVT_LEFT_DCLCK左键双击

	panel->Bind(wxEVT_MOTION, &MainFrame::OnMouseEvent, this);
	//将光标移动到button上时 状态栏中的光标位置就不更新了 加上下面的bind
	button->Bind(wxEVT_MOTION, &MainFrame::OnMouseEvent, this);
	*/
	
	wxPanel* panel = new wxPanel(this);

	panel->Bind(wxEVT_KEY_DOWN, &MainFrame::OnKeyEvent, this);

	CreateStatusBar();
}

//鼠标事件
/*
void MainFrame::OnMouseEvent(wxMouseEvent& evt)
{
	//此时在panel上时 xy坐标是相对于panel的 在button上时 xy坐标是相对于button的
	//因为获取位置的方法evt.GetPosition()返回wxwidgets调用的客户端位置
	//这种情况下位置是相对于控件的
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
		int KeyCode = evt.GetKeyCode(); //显示它的keycode
		wxLogStatus("Key Event %d", KeyCode);
	}
	else
	{
		wxLogStatus("Key Event %c", KeyChar);
	}	
}

