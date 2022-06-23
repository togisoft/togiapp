#include "Dashboard.hpp"

Dashboard::Dashboard(const wxString &title, const wxPoint &pos, const wxSize &size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    CreateStatusBar();
    SetStatusText("Dashboard");
}

Dashboard::~Dashboard()
{
}