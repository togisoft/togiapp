#include "Login.hpp"
#include "Prefs.hpp"

wxBEGIN_EVENT_TABLE(LoginFrame, wxFrame)
    EVT_BUTTON(ID_LOGIN, LoginFrame::OnLogin)
        wxEND_EVENT_TABLE()

            LoginFrame::LoginFrame(const wxString &title, const wxPoint &pos, const wxSize &size) : wxFrame(NULL, wxID_ANY, title, pos, size)
{

    //****************************************************
    // Left Panel
    //****************************************************
    l_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(420, 500));
    l_panel->SetBackgroundColour(wxColor(DEFAULT_COLOR));

    logo = new wxStaticBitmap(l_panel, wxID_ANY, wxBitmap("resources/logo.png", wxBITMAP_TYPE_PNG), wxPoint(50, 100));
    logo->Center();
    //****************************************************
    // Right Panel
    //****************************************************

    r_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(420, 500));

    sizer = new wxBoxSizer(wxHORIZONTAL);
    sizer->Add(l_panel, 1, wxEXPAND | wxLEFT | wxTop, 0);
    sizer->Add(r_panel, 1, wxEXPAND | wxRIGHT | wxTOP, 0);

    // @r_panel (Right Panel) Vertical Box
    wxBoxSizer *r_vbox = new wxBoxSizer(wxVERTICAL);

    // *****UserName BoxSizer********
    wxBoxSizer *hbox1 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer *hbox2 = new wxBoxSizer(wxHORIZONTAL);
    // *****UserName BoxSizer End *****

    // *****Password BoxSizer********
    wxBoxSizer *hbox3 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer *hbox4 = new wxBoxSizer(wxHORIZONTAL);
    // *****Password BoxSizer End********

    // *****Login Button BoxSizer********
    wxBoxSizer *hbox5 = new wxBoxSizer(wxHORIZONTAL);
    // *****Login Button BoxSizer End********

    // Username Label
    usernameLbl = new wxStaticText(r_panel, wxID_ANY, wxT("Username:"));
    hbox1->Add(usernameLbl, 0, wxRIGHT | wxLEFT, 40);

    // Username Textbox
    usernameTxt = new wxTextCtrl(r_panel, wxID_ANY, wxT(""), wxPoint(-1, -1), wxSize(-1, -1));
    hbox2->Add(usernameTxt, wxID_ANY, wxEXPAND | wxRIGHT | wxLEFT, 40);

    // Password Label
    passwordLbl = new wxStaticText(r_panel, wxID_ANY, wxT("Password:"));
    hbox3->Add(passwordLbl, wxID_ANY, wxEXPAND | wxRIGHT | wxLEFT, 40);

    // Password Textbox
    passwordTxt = new wxTextCtrl(r_panel, wxID_ANY, wxT(""), wxPoint(-1, -1), wxSize(-1, -1), wxTE_PASSWORD);
    hbox4->Add(passwordTxt, wxID_ANY, wxEXPAND | wxRIGHT | wxLEFT, 40);

    // Login Button
    loginButton = new wxButton(r_panel, ID_LOGIN, wxT("Login"));
    loginButton->SetBackgroundColour(wxColor(DEFAULT_COLOR));
    loginButton->SetForegroundColour(wxColor(WHITE));
    hbox5->Add(loginButton, wxID_ANY, wxEXPAND | wxRIGHT | wxLEFT, 40);

    r_vbox->Add(hbox1, 0, wxEXPAND | wxTOP, 150);
    r_vbox->Add(hbox2, 0, wxEXPAND | wxTOP, 8);
    r_vbox->Add(hbox3, 0, wxEXPAND | wxTOP, 20);
    r_vbox->Add(hbox4, 0, wxEXPAND | wxTOP, 8);
    r_vbox->Add(hbox5, 0, wxEXPAND | wxTOP, 30);

    this->SetSizerAndFit(sizer);
    r_panel->SetSizerAndFit(r_vbox);
    CreateStatusBar();
    Connections con;

    SetStatusText(con.connect);
}

void LoginFrame::OnLogin(wxCommandEvent &event)
{
    std::string usrname = usernameTxt->GetValue().ToStdString();
    std::string password = passwordTxt->GetValue().ToStdString();
    try
    {
        Connections *connection = new Connections();
        connection->psSelect = connection->conn->prepareStatement("SELECT USERNAME,USER_PASSWORD FROM USERS");
        connection->rs = connection->psSelect->executeQuery();

        while (connection->rs->next())
        {
            // If login is success open @Dashoard Frame @LoginFrame Close
            if (connection->rs->getString(1).operator==(usrname) && connection->rs->getString(2).operator==(password))
            {
                Dashboard *dashboard = new Dashboard(L"Dashboard", wxDefaultPosition, wxSize(1200, 800));
                dashboard->Maximize(true);
                dashboard->Show(true);
                this->Close(true);
                break;
            }
            else
            {
                SetStatusText(L"Please check your username or password.");
                wxMessageDialog *dialog = new wxMessageDialog(this, wxT("Please check your username or password."), wxT("Invalid Information!"), wxOK | wxICON_AUTH_NEEDED);
                dialog->ShowModal();
                break;
            }
        }
    }
    catch (const odbc::Exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}