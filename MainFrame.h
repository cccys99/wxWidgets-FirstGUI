#pragma once
#include <wx/wx.h>

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);

private:
	void OnAnyButtonClicked(wxCommandEvent& evt); 
	//void OnSliderChanged(wxCommandEvent& evt);
	//void OnTextChanged(wxCommandEvent& evt);
	void OnButton1Clicked(wxCommandEvent& evt);
	void OnButton2Clicked(wxCommandEvent& evt);
	void OnClose(wxCloseEvent& evt);

	//wxDECLARE_EVENT_TABLE();


};

