///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb  1 2013)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "NPRFrame.h"

///////////////////////////////////////////////////////////////////////////

NPR_Frame::NPR_Frame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 410,210 ), wxDefaultSize );

	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("NPR Module") ), wxVERTICAL );

	m_panel2 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer1->AddGrowableCol( 1 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );

	m_staticText1 = new wxStaticText( m_panel2, wxID_ANY, wxT("Search Term"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	fgSizer1->Add( m_staticText1, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_textCtrl1 = new wxTextCtrl( m_panel2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_LEFT );
	m_textCtrl1->SetMinSize( wxSize( 250,-1 ) );

	fgSizer1->Add( m_textCtrl1, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText2 = new wxStaticText( m_panel2, wxID_ANY, wxT("Number of stories"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	fgSizer1->Add( m_staticText2, 0, wxALL, 5 );

	m_textCtrl2 = new wxTextCtrl( m_panel2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_LEFT );
	fgSizer1->Add( m_textCtrl2, 0, wxALL|wxEXPAND, 5 );

	bSizer3->Add( fgSizer1, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );

	Connect_Button = new wxButton( m_panel2, wxID_ANY, wxT("Connect"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( Connect_Button, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	Exit_Button = new wxButton( m_panel2, wxID_ANY, wxT("Exit"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( Exit_Button, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	bSizer3->Add( bSizer2, 0, wxALL|wxALIGN_RIGHT, 5 );

	m_panel2->SetSizer( bSizer3 );
	m_panel2->Layout();
	bSizer3->Fit( m_panel2 );
	sbSizer1->Add( m_panel2, 1, wxEXPAND | wxALL, 5 );

	this->SetSizer( sbSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_textCtrl1->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( NPR_Frame::OnTextEnter ), NULL, this );
	Connect_Button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NPR_Frame::Connect_OnButtonClick ), NULL, this );
	Exit_Button->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NPR_Frame::Exit_OnButtonClick ), NULL, this );
}

NPR_Frame::~NPR_Frame()
{
	// Disconnect Events
	m_textCtrl1->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( NPR_Frame::OnTextEnter ), NULL, this );
	Connect_Button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NPR_Frame::Connect_OnButtonClick ), NULL, this );
	Exit_Button->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( NPR_Frame::Exit_OnButtonClick ), NULL, this );

}
