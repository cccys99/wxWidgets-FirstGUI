#include "MainFrame.h"
#include <wx/wx.h>
//#include <wx/spinctrl.h>

//enum IDs
//{
//	BUTTON_ID = 2,
//	SLIDER_ID = 3,
//	TEXT_ID = 4
//};

////宏将确保每当文本控件中的文本发生变化时 我们的事件处理程序就会被调用
//wxBEGIN_EVENT_TABLE(MainFrame,wxFrame)
//	EVT_BUTTON(BUTTON_ID,MainFrame::OnButtonClicked)
//	EVT_SLIDER(SLIDER_ID,MainFrame::OnSliderChanged)
//	EVT_TEXT(TEXT_ID,MainFrame::OnTextChanged)
//wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title) :wxFrame(nullptr, wxID_ANY, title)
{
	//面板 下面这些控件都在面板上
	wxPanel* panel = new wxPanel(this);

	wxButton* button1 = new wxButton(panel, wxID_ANY, "Button 1", wxPoint(300, 275), wxSize(200, 50)); //这里id改回wxID_ANY
	wxButton* button2 = new wxButton(panel, wxID_ANY, "Button 2", wxPoint(300, 350), wxSize(200, 50));

	//wxSlider* slider = new wxSlider(panel, wxID_ANY, 0, 0, 100, wxPoint(300, 200), wxSize(200, -1));
	//wxTextCtrl* text = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(300, 370), wxSize(200, -1));

	//动态事件处理
	//事件标签通常被称为与事件宏相同的东西 是以wx为前缀的
	//this->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);

	//slider->Bind(wxEVT_SLIDER, &MainFrame::OnSliderChanged, this);
	//text->Bind(wxEVT_TEXT, &MainFrame::OnTextChanged, this);

	//解除绑定的方法 用unbind
	//button->Unbind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
	
	//事件传播
	//将Bind前的button  改成this or panel 依然奏效
	//button->panel->Frame  有这种关系
	this->Bind(wxEVT_BUTTON, &MainFrame::OnAnyButtonClicked, this);
	this->Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnClose, this);
	button1->Bind(wxEVT_BUTTON, &MainFrame::OnButton1Clicked, this);
	button2->Bind(wxEVT_BUTTON, &MainFrame::OnButton2Clicked, this);

	CreateStatusBar();

	//下面这些是一些控件的熟悉
	////按钮
	//wxButton* button = new wxButton(panel, wxID_ANY, "Button", wxPoint(150, 50), wxSize(100, 30), wxBU_LEFT);

	////勾选框
	//wxCheckBox* checkBox = new wxCheckBox(panel, wxID_ANY, "CheckBox",
	//	wxPoint(550, 55), wxDefaultSize, wxCHK_3STATE | wxCHK_ALLOW_3RD_STATE_FOR_USER);

	////不可编辑的文本
	//wxStaticText* staticText = new wxStaticText(panel, wxID_ANY, "StaticText - NOT editable",
	//	wxPoint(0, 150), wxSize(400, -1), wxALIGN_CENTER_HORIZONTAL);
	//staticText->SetBackgroundColour(*wxLIGHT_GREY);

	////可编辑的文本
	//wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, "TextCtrl - editable",
	//	wxPoint(500, 145), wxSize(200, -1), wxTE_PASSWORD);

	////滑块
	//wxSlider* slider = new wxSlider(panel, wxID_ANY, 25, 0, 100,
	//	wxPoint(100, 250), wxSize(200, -1), wxSL_VALUE_LABEL);

	////进度条
	//wxGauge* gauge = new wxGauge(panel, wxID_ANY, 100, wxPoint(500, 255), wxSize(200, -1));
	//gauge->SetValue(75);

	////下拉菜单
	//wxArrayString choices;
	//choices.Add("Item C");
	//choices.Add("Item A");
	//choices.Add("Item B");

	//wxChoice* choice = new wxChoice(panel, wxID_ANY, wxPoint(150, 375), wxSize(100, -1), choices, wxCB_SORT);
	//choice->Select(0); //默认就是Item A

	//wxSpinCtrl* spinCtrl = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(550, 375), wxSize(100, -1), wxSP_WRAP);
	//
	//wxListBox* listBox = new wxListBox(panel, wxID_ANY, wxPoint(150, 475), wxSize(100, -1), choices);

	//wxRadioBox* radioBox = new wxRadioBox(panel, wxID_ANY, "RadioBox", wxPoint(485, 475), wxDefaultSize, choices);

}

//如果不加evtskip 程序就关闭不了 
//因为MainFram->wxFrame 子类已经处理了 wxFrame没有接收到我们要关闭它
void MainFrame::OnClose(wxCloseEvent& evt)
{
	wxLogMessage("Frame Closed");
	evt.Skip(); 
}

void MainFrame::OnAnyButtonClicked(wxCommandEvent& evt)
{
	wxLogMessage("Button Clicked");
}

//事件在传播到达主机之前就被处理了 不希望传播停止的话 需要调用evt.skip
void MainFrame::OnButton1Clicked(wxCommandEvent& evt)
{
	wxLogStatus("Button 1 Clicked");
	evt.Skip();
}

void MainFrame::OnButton2Clicked(wxCommandEvent& evt)
{
	wxLogStatus("Button 2 Clicked");
	evt.Skip();
}

//void MainFrame::OnSliderChanged(wxCommandEvent& evt)
//{
//	wxString str = wxString::Format("Slider Value: %d", evt.GetInt());
//	wxLogStatus(str);
//}
//
//void MainFrame::OnTextChanged(wxCommandEvent& evt)
//{
//	wxString str = wxString::Format("Text: %s", evt.GetString());
//	wxLogStatus(str);
//}