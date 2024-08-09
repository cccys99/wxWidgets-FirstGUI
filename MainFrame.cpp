#include "MainFrame.h"
#include <wx/wx.h>
#include <wx/spinctrl.h>

MainFrame::MainFrame(const wxString& title) :wxFrame(nullptr, wxID_ANY, title)
{
	//面板 下面这些控件都在面板上
	wxPanel* panel = new wxPanel(this);

	//按钮
	wxButton* button = new wxButton(panel, wxID_ANY, "Button", wxPoint(150, 50), wxSize(100, 30), wxBU_LEFT);

	//勾选框
	wxCheckBox* checkBox = new wxCheckBox(panel, wxID_ANY, "CheckBox",
		wxPoint(550, 55), wxDefaultSize, wxCHK_3STATE | wxCHK_ALLOW_3RD_STATE_FOR_USER);

	//不可编辑的文本
	wxStaticText* staticText = new wxStaticText(panel, wxID_ANY, "StaticText - NOT editable",
		wxPoint(0, 150), wxSize(400, -1), wxALIGN_CENTER_HORIZONTAL);
	staticText->SetBackgroundColour(*wxLIGHT_GREY);

	//可编辑的文本
	wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, "TextCtrl - editable",
		wxPoint(500, 145), wxSize(200, -1), wxTE_PASSWORD);

	//滑块
	wxSlider* slider = new wxSlider(panel, wxID_ANY, 25, 0, 100,
		wxPoint(100, 250), wxSize(200, -1), wxSL_VALUE_LABEL);

	//进度条
	wxGauge* gauge = new wxGauge(panel, wxID_ANY, 100, wxPoint(500, 255), wxSize(200, -1));
	gauge->SetValue(75);

	//下拉菜单
	wxArrayString choices;
	choices.Add("Item C");
	choices.Add("Item A");
	choices.Add("Item B");

	wxChoice* choice = new wxChoice(panel, wxID_ANY, wxPoint(150, 375), wxSize(100, -1), choices, wxCB_SORT);
	choice->Select(0); //默认就是Item A

	wxSpinCtrl* spinCtrl = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(550, 375), wxSize(100, -1), wxSP_WRAP);
	
	wxListBox* listBox = new wxListBox(panel, wxID_ANY, wxPoint(150, 475), wxSize(100, -1), choices);

	wxRadioBox* radioBox = new wxRadioBox(panel, wxID_ANY, "RadioBox", wxPoint(485, 475), wxDefaultSize, choices);

}