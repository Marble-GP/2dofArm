#include "MyGLproc.h"

void Draw2DPolygonf(GLuint n, GLfloat r_outer, GLfloat* cpos, const GLfloat* colorv, GLfloat angle0 )
{
	GLfloat x,y;
	if (cpos != NULL)
		x = cpos[0], y = cpos[1];
	else
		x = 0, y = 0;
	
	if (colorv != NULL)
		glColor3fv(colorv);
	else
		glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_POLYGON);
	for (GLuint i = 0; i < n; ++i)
	{
		glVertex2f(x + r_outer * cosf(2 * M_PI * (GLfloat)(i) / (GLfloat)(n)+angle0), y + r_outer * sinf(2 * M_PI * (GLfloat)(i) / (GLfloat)(n)+angle0));
	}
	glEnd();
}

void Draw2DFramef(GLfloat width, GLfloat height, GLfloat* cpos, const GLfloat* colorv)
{
	GLfloat x, y;
	if (cpos != NULL)
		x = cpos[0], y = cpos[1];
	else
		x = 0, y = 0;

	if (colorv != NULL)
		glColor3fv(colorv);
	else
		glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x - width / 2.0f, y - height / 2.0f);
	glVertex2f(x + width / 2.0f, y - height / 2.0f);
	glVertex2f(x + width / 2.0f, y + height / 2.0f);
	glVertex2f(x - width / 2.0f, y + height / 2.0f);
	glEnd();

}

void Draw2DTrianglef(GLfloat d, GLfloat* cpos, const GLfloat* colorv)
{
	GLfloat x, y;
	if (cpos != NULL)
		x = cpos[0], y = cpos[1];
	else
		x = 0, y = 0;

	if (colorv != NULL)
		glColor3fv(colorv);
	else
		glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_LINES);
	glVertex3f(x + 0.5f * d, y - 0.5f * d * tan(30.0f * (float)M_PI / 180.0f), 0.0f);
	glVertex3f(x, y + 0.5f * d / cos(30.0f * (float)M_PI / 180.0f), 0.0f);
	glVertex3f(x - 0.5f * d, y - 0.5f * d * tan(30.0f * (float)M_PI / 180.0f), 0.0f);
	glEnd();

}

//https://osyo-manga.hatenadiary.org/entry/20110827/1314417606
void DrawString(float x, float y, char* str)
{
	float z = -1.0f;
	glRasterPos3f(x, y, z);
	while (str)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *str);
		++str;
	}
}