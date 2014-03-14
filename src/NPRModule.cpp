#include "NPRModule.h"



NPR_Module::NPR_Module( wxWindow* parent )
:
NPR_Frame( parent )
{

}

void NPR_Module::OnTextEnter( wxCommandEvent& event )
{
Connect_OnButtonClick(event);// TODO: Implement OnTextEnter
}

void NPR_Module::Connect_OnButtonClick( wxCommandEvent& event )
{
    StoryWindow* log = new StoryWindow(this);
    wxString searchTerm(m_textCtrl1->GetValue()), numResults(m_textCtrl2->GetValue());
    log->GetStory(searchTerm, numResults);
    log->worker();
}

void NPR_Module::Exit_OnButtonClick( wxCommandEvent& event )
{
    system("rm *.json wxhtml*");
    Destroy();
}
