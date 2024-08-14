#include "MainFrame.h"
#include <wx/wx.h>
//#include <wx/spinctrl.h>

//enum IDs
//{
//	BUTTON_ID = 2,
//	SLIDER_ID = 3,
//	TEXT_ID = 4
//};

////�꽫ȷ��ÿ���ı��ؼ��е��ı������仯ʱ ���ǵ��¼��������ͻᱻ����
//wxBEGIN_EVENT_TABLE(MainFrame,wxFrame)
//	EVT_BUTTON(BUTTON_ID,MainFrame::OnButtonClicked)
//	EVT_SLIDER(SLIDER_ID,MainFrame::OnSliderChanged)
//	EVT_TEXT(TEXT_ID,MainFrame::OnTextChanged)
//wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title) :wxFrame(nullptr, wxID_ANY, title)
{
	//��� ������Щ�ؼ����������
	wxPanel* panel = new wxPanel(this);

	wxButton* button1 = new wxButton(panel, wxID_ANY, "Button 1", wxPoint(300, 275), wxSize(200, 50)); //����id�Ļ�wxID_ANY
	wxButton* button2 = new wxButton(panel, wxID_ANY, "Button 2", wxPoint(300, 350), wxSize(200, 50));

	//wxSlider* slider = new wxSlider(panel, wxID_ANY, 0, 0, 100, wxPoint(300, 200), wxSize(200, -1));
	//wxTextCtrl* text = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(300, 370), wxSize(200, -1));

	//��̬�¼�����
	//�¼���ǩͨ������Ϊ���¼�����ͬ�Ķ��� ����wxΪǰ׺��
	//this->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);

	//slider->Bind(wxEVT_SLIDER, &MainFrame::OnSliderChanged, this);
	//text->Bind(wxEVT_TEXT, &MainFrame::OnTextChanged, this);

	//����󶨵ķ��� ��unbind
	//button->Unbind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);
	
	//�¼�����
	//��Bindǰ��button  �ĳ�this or panel ��Ȼ��Ч
	//button->panel->Frame  �����ֹ�ϵ
	this->Bind(wxEVT_BUTTON, &MainFrame::OnAnyButtonClicked, this);
	this->Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnClose, this);
	button1->Bind(wxEVT_BUTTON, &MainFrame::OnButton1Clicked, this);
	button2->Bind(wxEVT_BUTTON, &MainFrame::OnButton2Clicked, this);

	CreateStatusBar();

	//������Щ��һЩ�ؼ�����Ϥ
	////��ť
	//wxButton* button = new wxButton(panel, wxID_ANY, "Button", wxPoint(150, 50), wxSize(100, 30), wxBU_LEFT);

	////��ѡ��
	//wxCheckBox* checkBox = new wxCheckBox(panel, wxID_ANY, "CheckBox",
	//	wxPoint(550, 55), wxDefaultSize, wxCHK_3STATE | wxCHK_ALLOW_3RD_STATE_FOR_USER);

	////���ɱ༭���ı�
	//wxStaticText* staticText = new wxStaticText(panel, wxID_ANY, "StaticText - NOT editable",
	//	wxPoint(0, 150), wxSize(400, -1), wxALIGN_CENTER_HORIZONTAL);
	//staticText->SetBackgroundColour(*wxLIGHT_GREY);

	////�ɱ༭���ı�
	//wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, "TextCtrl - editable",
	//	wxPoint(500, 145), wxSize(200, -1), wxTE_PASSWORD);

	////����
	//wxSlider* slider = new wxSlider(panel, wxID_ANY, 25, 0, 100,
	//	wxPoint(100, 250), wxSize(200, -1), wxSL_VALUE_LABEL);

	////������
	//wxGauge* gauge = new wxGauge(panel, wxID_ANY, 100, wxPoint(500, 255), wxSize(200, -1));
	//gauge->SetValue(75);

	////�����˵�
	//wxArrayString choices;
	//choices.Add("Item C");
	//choices.Add("Item A");
	//choices.Add("Item B");

	//wxChoice* choice = new wxChoice(panel, wxID_ANY, wxPoint(150, 375), wxSize(100, -1), choices, wxCB_SORT);
	//choice->Select(0); //Ĭ�Ͼ���Item A

	//wxSpinCtrl* spinCtrl = new wxSpinCtrl(panel, wxID_ANY, "", wxPoint(550, 375), wxSize(100, -1), wxSP_WRAP);
	//
	//wxListBox* listBox = new wxListBox(panel, wxID_ANY, wxPoint(150, 475), wxSize(100, -1), choices);

	//wxRadioBox* radioBox = new wxRadioBox(panel, wxID_ANY, "RadioBox", wxPoint(485, 475), wxDefaultSize, choices);

}

//�������evtskip ����͹رղ��� 
//��ΪMainFram->wxFrame �����Ѿ������� wxFrameû�н��յ�����Ҫ�ر���
void MainFrame::OnClose(wxCloseEvent& evt)
{
	wxLogMessage("Frame Closed");
	evt.Skip(); 
}

void MainFrame::OnAnyButtonClicked(wxCommandEvent& evt)
{
	wxLogMessage("Button Clicked");
}

//�¼��ڴ�����������֮ǰ�ͱ������� ��ϣ������ֹͣ�Ļ� ��Ҫ����evt.skip
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