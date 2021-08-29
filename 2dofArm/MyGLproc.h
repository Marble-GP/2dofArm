#pragma once
#include <GL/glut.h>
#include <wx/math.h>

const GLfloat RGBA_redf[4] = { 1.0f, 0.0f, 0.0f, 1.0f };
const GLfloat RGBA_greenf[4] = { 0.0f, 1.0f, 0.0f, 1.0f };
const GLfloat RGBA_bluef[4] = { 0.0f, 0.0f, 1.0f, 1.0f };
const GLfloat RGBA_cyanf[4] = { 0.0f, 1.0f, 1.0f, 1.0f };
const GLfloat RGBA_magentaf[4] = { 1.0f, 0.0f, 1.0f, 1.0f };
const GLfloat RGBA_yellowf[4] = { 1.0f, 1.0f, 0.0f, 1.0f };
const GLfloat RGBA_whitef[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat RGBA_grayf[4] = { 0.5f, 0.5f, 0.5f, 1.0f };
const GLfloat RGBA_blackf[4] = { 0.0f, 0.0f, 0.0f, 1.0f };

void Draw2DPolygonf(GLuint n, GLfloat r_outer, GLfloat* cpos = NULL, const GLfloat* colorv = NULL, GLfloat angle0 = 0);

void Draw2DFramef(GLfloat width, GLfloat height, GLfloat* cpos = NULL, const GLfloat* colorv = NULL);

void Draw2DTrianglef(GLfloat d, GLfloat* cpos = NULL, const GLfloat* colorv = NULL);

void DrawString(float x, float y, char* str);
