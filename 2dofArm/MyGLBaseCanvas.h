#pragma once
#include <wx/wx.h>
#include <wx/glcanvas.h>
#include <GL/glut.h>

class MyGLBaseCanvas :
    public wxGLCanvas
{
public:
    MyGLBaseCanvas(wxWindow* parent,
        wxWindowID id = wxID_ANY,
        const int* attribList = NULL,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = 0,
        const wxString& name = wxGLCanvasName,
        const wxPalette& palette = wxNullPalette);

    ~MyGLBaseCanvas();

private:

    virtual void GLinit();
    virtual void Render();
    virtual void OnPaint(wxPaintEvent& event);
    virtual void OnKey(wxKeyEvent& event);
    
};

