///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/combobox.h>
#include <wx/spinctrl.h>
#include <wx/tglbtn.h>
#include <wx/sizer.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

#include "ArmCanvas.h"

///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame
{
private:

protected:
	ArmCanvas* glpanel;
	wxStaticText* m_staticText1;
	wxComboBox* m_comboBox1;
	wxStaticText* arg1;
	wxSpinCtrlDouble* m_spinCtrlDouble1;
	wxStaticText* arg2;
	wxSpinCtrlDouble* m_spinCtrlDouble2;
	wxStaticText* x_ref;
	wxSpinCtrlDouble* m_spinCtrlDouble3;
	wxStaticText* y_ref;
	wxSpinCtrlDouble* m_spinCtrlDouble4;
	wxStaticText* m_staticText4;
	wxToggleButton* m_toggleBtn1;

	// Virtual event handlers, overide them in your derived class
	virtual void OnModechange(wxCommandEvent& event);
	virtual void OnRefchanged(wxSpinDoubleEvent& event);
	virtual void OnDebugmode(wxCommandEvent& event);


public:

	MyFrame1(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("2DoF Robot Arm"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(1080, 720), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

	~MyFrame1();

};

