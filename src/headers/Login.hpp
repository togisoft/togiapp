#ifndef _LOGIN_
#include <wx/wx.h>
#include <wx/frame.h>
#include <wx/textctrl.h>
#include"Connection.hpp"
#include "Dashboard.hpp"

class LoginFrame : public wxFrame
{
    wxPanel *l_panel;
    wxBoxSizer *sizer;
    wxPanel *r_panel;
    wxStaticBitmap *logo;

    wxStaticText *usernameLbl;
    wxTextCtrl *usernameTxt;
    wxStaticText *passwordLbl;
    wxTextCtrl *passwordTxt;

    wxButton *loginButton;

public:
    LoginFrame(const wxString &title, const wxPoint &pos, const wxSize &size);
    ~LoginFrame(){
        std::cerr << "Login Bellek Temizlendi" << std::endl;
    }
private:
    void OnLogin(wxCommandEvent &event);
    wxDECLARE_EVENT_TABLE();
};

#define _LOGIN_
#endif