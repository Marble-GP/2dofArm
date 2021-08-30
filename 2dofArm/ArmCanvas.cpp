#include <wx/wx.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include "MyGLproc.h"
#include "robotarm.h"
#include "ArmCanvas.h"


void ArmCanvas::Render()
{
    //基本的な描画の手順
    //アフィン変換で移動等を定義→グローバル座標中心に描く→変換適用

    //固定端の描画
    glPushMatrix();
    {
        glTranslatef(base[0], base[1], 0.0f);
    }
    Draw2DPolygonf(6, base_r);
    glPopMatrix();

    //第1アーム部+第2関節描画
    //変換は下から順にpopされるので注意
    glPushMatrix();
    {
        glTranslatef(base[0], base[1], 0.0f);
        glRotatef(q1, 0.0, 0.0, 1.0);       
    }
    glLineWidth(arm_width);
    glColor3fv(RGBA_redf);
    glBegin(GL_LINES);
    glVertex2fv(node1);
    glVertex2fv(node2);
    glEnd();
    Draw2DPolygonf(12, 0.02f, (GLfloat*)node2);
    glPopMatrix();//一括で移動

    //第2アーム部描画
    glPushMatrix();
    {
        glTranslatef(base[0]+arm_len*cos((float)(q1*(float)M_PI/180.0f)), base[1] + arm_len * sin((float)(q1 * (float)M_PI / 180.0f)), 0.0f);
        glRotatef(q1+q2, 0.0, 0.0, 1.0);//第1アームを基準線として角度なのでq1+q2
    }
    glLineWidth(arm_width);
    glColor3fv(RGBA_greenf);
    glBegin(GL_LINES);
    glVertex2fv(node1);
    glVertex2fv(node2);
    glEnd();
    glPopMatrix();

    if (debugmode)
    {
        char strbuf[256] = { 0 };
        float x1, x2, y1, y2;
        x1 = arm_len * cos(q1*(float)M_PI/180.0f);
        y1 = arm_len * sin(q1 * (float)M_PI / 180.0f);
        x2 = arm_len * cos((q1+q2) * (float)M_PI / 180.0f) + x1;
        y2 = arm_len * sin((q1+q2) * (float)M_PI / 180.0f) + y1;
        snprintf(strbuf, 256, "q1: %f\nq2: %f\nx1: %f\ny1: %f\nx2: %f\n y2: %f\n\0",
            q1, q2, x1, y1, x2, y2);
        glRasterPos2f(-0.9, 0.9);
        glutBitmapString(GLUT_BITMAP_HELVETICA_18, (unsigned char*)strbuf);
    }

    glFlush();
}
