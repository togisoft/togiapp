#ifndef _Dashboard_

#include <wx/wx.h>
#include <wx/frame.h>
#include <wx/wxprec.h>
class Dashboard : public wxFrame
{
public:
    Dashboard(const wxString &title, const wxPoint &pos, const wxSize &size);
    ~Dashboard();

private:
};

#define _Dashboard_
#endif