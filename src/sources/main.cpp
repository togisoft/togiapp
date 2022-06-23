#include "main.hpp"
#include "Login.hpp"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    LoginFrame *login = new LoginFrame(wxT("Giriş"), wxDefaultPosition, wxSize(900, 500));
    login->SetMaxSize(wxSize(900, 500));
    login->SetMinSize(wxSize(900, 500));
    login->Show(true);

    return true;
}