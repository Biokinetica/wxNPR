///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb  1 2013)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __LogWindow__
#define __LogWindow__

#include <wx/html/htmlwin.h>
#include <wx/gdicmn.h>
#include <wx/notebook.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/frame.h>
#include <json/json.h>
#include <fstream>
#include <tuple>
#include <boost/regex.hpp>
///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class StoryWindow
///////////////////////////////////////////////////////////////////////////////
class StoryWindow : public wxFrame
{
	private:
    wxPanel* CreatePanel();
    wxHtmlWindow* CreateWindow(wxPanel* panel);
    wxStaticBoxSizer* CreateSizer(wxPanel* panel);
    void HandlingIt(Json::Value &value);
    void CreateNprWindow(std::tuple<wxPanel*,wxStaticBoxSizer*,wxHtmlWindow*,wxString,wxString> &windowComponents);
    //void CreateWebView(std::tuple<wxPanel*,wxStaticBoxSizer*,wxWebView*,wxString,wxString> &webViewComponents);
    const char *pagefilename;
    std::string input;
    std::string input1;
    std::string url;
    std::string converter;
    std::string holder;
    std::string err;
    std::vector<Json::Value> ob;
    wxPanel* panel;
    wxStaticBoxSizer* sizer;
    wxHtmlWindow* windows;
    //wxWebView* content;

    wxString wx, storyName;
    Json::Value value;
    Json::Reader file_parser;
    FILE* pagefile;
    std::tuple<wxPanel*,wxStaticBoxSizer*,wxHtmlWindow*,wxString,wxString> blob;
    boost::regex e;
    std::string get_file_contents(const char *filename);

	protected:

		wxNotebook* m_notebook1;
		wxPanel* m_panel2;
		wxHtmlWindow* m_htmlWin1;

		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }


	public:

	    int GetStory(wxString searchTerm, wxString numResults);
        bool worker();
		StoryWindow( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("NPR Monitor"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~StoryWindow();

};

#endif //__LogWindow__
