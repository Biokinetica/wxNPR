///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb  1 2013)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif //WX_PRECOMP

#include "LogWindow.h"
#include <iostream>
#include <json/json.h>
#include <fstream>
#include <vector>
#include <system_error>
#include <boost/regex.hpp>
#include "mongo/client/dbclient.h"
#include <tuple>
#include <curl/curl.h>
///////////////////////////////////////////////////////////////////////////
StoryWindow::StoryWindow( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 500,350 ), wxDefaultSize );

	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("News Stories") ), wxVERTICAL );

	m_notebook1 = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	sbSizer1->Add( m_notebook1, 1, wxEXPAND | wxALL, 5 );

	this->SetSizer( sbSizer1 );
	this->Layout();
	sbSizer1->Fit( this );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( StoryWindow::OnClose ) );
}

StoryWindow::~StoryWindow()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( StoryWindow::OnClose ) );

}

wxPanel* StoryWindow::CreatePanel()
{
    wxPanel* panel = new wxPanel(m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
    return panel;
}

wxHtmlWindow* StoryWindow::CreateWindow(wxPanel* panel)
{
    wxHtmlWindow* window = new wxHtmlWindow(panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHW_SCROLLBAR_AUTO);
    window->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
    window->SetMinSize( wxSize( 1920,1080 ) );
    return window;
}

wxStaticBoxSizer* StoryWindow::CreateSizer(wxPanel* panel)
{
   wxStaticBoxSizer* sbSizer = new wxStaticBoxSizer( new wxStaticBox( panel, wxID_ANY, wxEmptyString ), wxVERTICAL );

    return sbSizer;
}

void StoryWindow::HandlingIt(Json::Value &value)
{
    wxString err = value.get("message","No Message")[0].get("text","wtf").get("$text","wtf").asString();
    wxMessageDialog *dial = new wxMessageDialog(NULL,err, wxT("Error"), wxOK | wxICON_ERROR);
    dial->ShowModal();
}

/*void wxHtmlWindow::OnLinkClicked(const wxHtmlLinkInfo& Link)
{
    wxLaunchDefaultBrowser(Link.GetHref());
}*/

std::string StoryWindow::get_file_contents(const char* filename)
{
  std::ifstream in(filename, std::ios::in | std::ios::binary);
  if (in)
  {
    in.seekg(0, std::ios::end);
    holder.resize(in.tellg());
    in.seekg(0, std::ios::beg);
    in.read(&holder[0], holder.size());
    in.close();
    return(holder);
  }
  throw(errno);
}

void StoryWindow::CreateNprWindow(std::tuple<wxPanel*,wxStaticBoxSizer*,wxHtmlWindow*,wxString,wxString> &windowComponents)
{
	   std::get<0>(windowComponents) = CreatePanel();
	   std::get<1>(windowComponents) = CreateSizer(std::get<0>(windowComponents));
	   std::get<0>(windowComponents)->SetSizer( std::get<1>(windowComponents) );
	   std::get<0>(windowComponents)->Layout();
	   std::get<1>(windowComponents)->Fit( std::get<0>(windowComponents) );
	   std::get<2>(windowComponents) = CreateWindow(std::get<0>(windowComponents));
	   std::get<1>(windowComponents)->Add( std::get<2>(windowComponents), 0, wxALL, 5 );
	   m_notebook1->AddPage(std::get<0>(windowComponents), std::get<4>(windowComponents), false );
	   std::get<2>(windowComponents)->SetPage(std::get<3>(windowComponents));
}
/*void StoryWindow::CreateWebView(std::tuple<wxPanel*,wxStaticBoxSizer*,wxWebView*,wxString,wxString> &webViewComponents)
{

}*/
int StoryWindow::GetStory(wxString searchTerm, wxString numResults)
{

    input = searchTerm.mb_str();

    if(input.empty())
    input = "1001";

    if(numResults.IsEmpty())
        numResults.assign("10");

     input1 = "&numResults=";

    input1.append(numResults.mb_str());

    e = "\\s";

    input = boost::regex_replace(input,e,"%20");

    url = "http://api.npr.org/query?searchTerm=";
    url.append(input).append(input1).append("&requiredAssets=text&dateType=story&output=JSON&apiKey=MDEwODE3NjMxMDEzNTk0NTk5NjU4ZTk3NA001");

    input.append(".json");
    pagefilename = input.c_str();

    CURLcode ret;

    CURL *hnd = curl_easy_init();
    curl_easy_setopt(hnd, CURLOPT_URL, url.c_str());
    curl_easy_setopt(hnd, CURLOPT_NOPROGRESS, 1L);
    curl_easy_setopt(hnd, CURLOPT_USERAGENT, "curl/7.27.0 (x86_64-redhat-linux-gnu) libcurl/7.27.0 NSS/3.13.5.0 zlib/1.2.5 libidn/1.22 libssh2/1.2.7");
    curl_easy_setopt(hnd, CURLOPT_SSH_KNOWNHOSTS, "/home/brenton/.ssh/known_hosts");
    curl_easy_setopt(hnd, CURLOPT_MAXREDIRS, 50L);
    curl_easy_setopt(hnd, CURLOPT_WRITEFUNCTION, NULL);

  pagefile = fopen(pagefilename, "wb");



  curl_easy_setopt(hnd, CURLOPT_WRITEDATA, pagefile);

  if (pagefile != NULL) {
  ret = curl_easy_perform(hnd);
  fclose(pagefile);

  curl_easy_cleanup(hnd);

  converter = numResults.mb_str();
  }
  return (ret);
}

bool StoryWindow::worker()
{


    get_file_contents(pagefilename);
    file_parser.parse(holder,value);


if(value.isMember("message"))
{
    HandlingIt(value);
    return 0;
}


bson::bo obj;

/*mongo::DBClientConnection conn;
conn.connect("ds035498.mongolab.com:35498", err);

    bool ok = conn.auth("projects","DixieFlatline","panthermodern",err);
    if ( ! ok )
        std::cout << "DIDN'T WORK" << std::endl;
    MONGO_verify( ok );*/
wx = "";

blob = std::make_tuple(panel,sizer,windows,wx,storyName);
/*std::tuple<wxPanel*,wxStaticBoxSizer*,wxWebView*,wxString,wxString> blob1;
blob1 = std::make_tuple(panel,sizer,content,wx,storyName);*/

Show();


for(int i = 0 ; i < std::stoi(converter) ; i++){
ob.push_back(value.get("list","No info available").get("story","No strories available")[i]);
}
    for(int i = 0; i < std::stoi(converter); i++){

	/*if(ob[i].isMember("fullText")){
	    std::get<4>(blob) = ob[i].get("title","No Title for Article").get("$text","No Title for Article").asString();

	   std::get<3>(blob) = ob[i].get("fullText","No HTML article available").get("$text","No story present").asString();

	   CreateNprWindow(blob);

	   //conn.insert("projects.NPR_Stories", BSON("article" << std::get<3>(blob).mb_str()));


	   std::get<3>(blob).Clear();
	}
	else */if(ob[i].isMember("textWithHtml"))
	{
	    std::get<4>(blob) = ob[i].get("title","No Title for Article").get("$text","No Title for Article").asString();
	    std::get<3>(blob) += "<div></div><div></div>";
	    for( unsigned int j=0 ; j != ob[i].get("textWithHtml","No HTML article available").get("paragraph","No Paragraph array").size() ; j++)
        {
            std::get<3>(blob) += ob[i].get("textWithHtml","No HTML article available").get("paragraph","No Paragraph array")[j].get("$text","No paragraph present").asString();

            std::get<3>(blob) += "<div></div><div></div>";

        }

	   CreateNprWindow(blob);

	   //conn.insert("projects.NPR_Stories", BSON("article" << std::get<3>(blob).mb_str()));

        std::get<3>(blob).Clear();
	}
}

//conn.logout("projects",obj);
return 1;
}
