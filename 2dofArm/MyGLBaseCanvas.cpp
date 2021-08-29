#include "MyGLBaseCanvas.h"

MyGLBaseCanvas::MyGLBaseCanvas(wxWindow* parent,
    wxWindowID id,const int* attribList,const wxPoint& pos,const wxSize& size,long style,const wxString& name,const wxPalette& palette)
    :wxGLCanvas(parent, id, attribList, pos, size, style, name, palette)
{
    int argc = 1;
    char* argv[1] = { 0 };
    glutInit(&argc, argv);

    this->Connect(wxEVT_PAINT, wxPaintEventHandler(MyGLBaseCanvas::OnPaint));
    if (parent != NULL)
    {
        parent->Connect(wxEVT_KEY_DOWN, wxKeyEventHandler(MyGLBaseCanvas::OnKey));
    }
    
}

MyGLBaseCanvas::~MyGLBaseCanvas()
{
    this->Disconnect(wxEVT_PAINT);
}

void MyGLBaseCanvas::OnKey(wxKeyEvent& event)
{
    event.Skip();
}

void MyGLBaseCanvas::OnPaint(wxPaintEvent& event)
{
    static auto glc = wxGLContext(this);

    wxPaintDC(this);
    SetCurrent(glc);
    GLinit();
    Render();
    SwapBuffers();
}

void MyGLBaseCanvas::GLinit()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0, 0, (GLint)GetSize().x, (GLint)GetSize().y);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void MyGLBaseCanvas::Render()
{
    glFlush();
}
