///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb  1 2013)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __NPRFrame__
#define __NPRFrame__

#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/statbox.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class NPRFrame
///////////////////////////////////////////////////////////////////////////////
class NPR_Frame : public wxFrame
{
	private:

	protected:
		wxPanel* m_panel2;
		wxStaticText* m_staticText1;
		wxTextCtrl* m_textCtrl1;
		wxStaticText* m_staticText2;
		wxTextCtrl* m_textCtrl2;
		wxButton* Connect_Button;
		wxButton* Exit_Button;

		// Virtual event handlers, overide them in your derived class
		virtual void OnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void Connect_OnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void Exit_OnButtonClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		NPR_Frame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("NPR News Reader"), const wxPoint& pos = wxPoint( -1,-1 ), const wxSize& size = wxSize( 410,200 ), long style = wxDEFAULT_FRAME_STYLE|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxTAB_TRAVERSAL );
		~NPR_Frame();

};

#endif //__NPR_Frame__
