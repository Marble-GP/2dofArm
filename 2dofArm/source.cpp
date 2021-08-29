#include <wx/wx.h>
#include <wx/glcanvas.h>
#include <GL/glut.h>
#include "robotarm.h"
#include "MyGLBaseCanvas.h"
#include "MyGLproc.h"

class MyApp : public wxApp
{
    virtual bool OnInit();
};

IMPLEMENT_APP(MyApp)

void MyFrame1::OnModechange(wxCommandEvent& event)
{
    if (m_comboBox1->GetSelection())//角度指令モード
    {
        m_spinCtrlDouble1->Enable();
        m_spinCtrlDouble2->Enable();
        m_spinCtrlDouble3->Disable();
        m_spinCtrlDouble4->Disable();
    }
    else
    {
        m_spinCtrlDouble1->Disable();
        m_spinCtrlDouble2->Disable();
        m_spinCtrlDouble3->Enable();
        m_spinCtrlDouble4->Enable();
    }
}


void MyFrame1::OnRefchanged(wxSpinDoubleEvent& event)
{
    if (m_comboBox1->GetSelection())//角度指令モード
    {
        glpanel->q1 = m_spinCtrlDouble1->GetValue();
        glpanel->q2 = m_spinCtrlDouble2->GetValue();
    }
    else//2自由度リンク機構 逆運動学ソルバーをそのまま適用
    {
        float x, y,l, q1, q2;
        x = m_spinCtrlDouble3->GetValue();
        y = m_spinCtrlDouble4->GetValue();
        l = glpanel->arm_len;
        q1 = acos((x * x + y * y) / (2 * l * sqrt(x * x + y * y))) + atan2(y, x);
        q2 = atan2((y - l * sin(q1)), (x - l * cos(q1)));
        glpanel->q1 = q1 * 180.0f / (float)M_PI;
        glpanel->q2 = q2 * 180.0f / (float)M_PI;
    }
    glpanel->Refresh();
}

void MyFrame1::OnDebugmode(wxCommandEvent& event)
{
    glpanel->debugmode = m_toggleBtn1->GetValue();
    glpanel->Refresh();
}

bool MyApp::OnInit()
{
    auto frame = new MyFrame1(NULL);
    frame->Show(true);
    return true;
}