///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "robotarm.h"

///////////////////////////////////////////////////////////////////////////

MyFrame1::MyFrame1(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	this->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENU));
	this->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENU));

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer(wxHORIZONTAL);

	glpanel = new ArmCanvas(this, wxID_ANY, NULL, wxDefaultPosition, wxSize(700,700));
	bSizer1->Add(glpanel, 5, wxEXPAND | wxALL, 5);

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer(wxVERTICAL);

	m_staticText1 = new wxStaticText(this, wxID_ANY, wxT("mode"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText1->Wrap(-1);
	bSizer2->Add(m_staticText1, 0, wxALL, 5);

	m_comboBox1 = new wxComboBox(this, wxID_ANY, wxT("a"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0);
	m_comboBox1->Append(wxT("coord reference"));
	m_comboBox1->Append(wxT("joint angle mode"));
	m_comboBox1->SetSelection(1);
	m_comboBox1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOWTEXT));

	bSizer2->Add(m_comboBox1, 0, wxALL, 5);

	arg1 = new wxStaticText(this, wxID_ANY, wxT("angle1"), wxDefaultPosition, wxDefaultSize, 0);
	arg1->Wrap(-1);
	bSizer2->Add(arg1, 0, wxALL, 5);

	m_spinCtrlDouble1 = new wxSpinCtrlDouble(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 180, 45, 1);
	m_spinCtrlDouble1->SetDigits(1);
	bSizer2->Add(m_spinCtrlDouble1, 0, wxALL, 5);

	arg2 = new wxStaticText(this, wxID_ANY, wxT("angle2"), wxDefaultPosition, wxDefaultSize, 0);
	arg2->Wrap(-1);
	bSizer2->Add(arg2, 0, wxALL, 5);

	m_spinCtrlDouble2 = new wxSpinCtrlDouble(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, -90, 180, 0, 1);
	m_spinCtrlDouble2->SetDigits(1);
	bSizer2->Add(m_spinCtrlDouble2, 0, wxALL, 5);

	x_ref = new wxStaticText(this, wxID_ANY, wxT("x pos"), wxDefaultPosition, wxDefaultSize, 0);
	x_ref->Wrap(-1);
	bSizer2->Add(x_ref, 0, wxALL, 5);

	m_spinCtrlDouble3 = new wxSpinCtrlDouble(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, -1.2, 1.2, 0.9, 0.1);
	m_spinCtrlDouble3->SetDigits(2);
	bSizer2->Add(m_spinCtrlDouble3, 0, wxALL, 5);

	y_ref = new wxStaticText(this, wxID_ANY, wxT("y pos"), wxDefaultPosition, wxDefaultSize, 0);
	y_ref->Wrap(-1);
	bSizer2->Add(y_ref, 0, wxALL, 5);

	m_spinCtrlDouble4 = new wxSpinCtrlDouble(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, -1.2, 1.2, 0.5, 0.1);
	m_spinCtrlDouble4->SetDigits(2);
	bSizer2->Add(m_spinCtrlDouble4, 0, wxALL, 5);

	m_staticText4 = new wxStaticText(this, wxID_ANY, wxT("debug mode"), wxDefaultPosition, wxDefaultSize, 0);
	m_staticText4->Wrap(-1);
	bSizer2->Add(m_staticText4, 0, wxALL, 5);

	m_toggleBtn1 = new wxToggleButton(this, wxID_ANY, wxT("Debug"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer2->Add(m_toggleBtn1, 0, wxALL, 5);


	bSizer1->Add(bSizer2, 1, wxEXPAND, 5);


	this->SetSizer(bSizer1);
	this->Layout();

	this->Centre(wxBOTH);

	m_spinCtrlDouble1->Enable();
	m_spinCtrlDouble2->Enable();
	m_spinCtrlDouble3->Disable();
	m_spinCtrlDouble4->Disable();

	// Connect Events
	m_comboBox1->Connect(wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler(MyFrame1::OnModechange), NULL, this);
	m_spinCtrlDouble1->Connect(wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler(MyFrame1::OnRefchanged), NULL, this);
	m_spinCtrlDouble2->Connect(wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler(MyFrame1::OnRefchanged), NULL, this);
	m_spinCtrlDouble3->Connect(wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler(MyFrame1::OnRefchanged), NULL, this);
	m_spinCtrlDouble4->Connect(wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler(MyFrame1::OnRefchanged), NULL, this);
	m_toggleBtn1->Connect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(MyFrame1::OnDebugmode), NULL, this);
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	m_comboBox1->Disconnect(wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler(MyFrame1::OnModechange), NULL, this);
	m_spinCtrlDouble1->Disconnect(wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler(MyFrame1::OnRefchanged), NULL, this);
	m_spinCtrlDouble2->Disconnect(wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler(MyFrame1::OnRefchanged), NULL, this);
	m_spinCtrlDouble3->Disconnect(wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler(MyFrame1::OnRefchanged), NULL, this);
	m_spinCtrlDouble4->Disconnect(wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler(MyFrame1::OnRefchanged), NULL, this);
	m_toggleBtn1->Disconnect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(MyFrame1::OnDebugmode), NULL, this);

}
