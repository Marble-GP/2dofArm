#pragma once
#include "MyGLBaseCanvas.h"
class ArmCanvas :
    public MyGLBaseCanvas
{
public:
	const float base_r = 0.1, arm_len = 0.6f;
	const GLfloat base[2] = { 0.0, -0.9 };
	const GLfloat node1[2] = { 0.0, 0.0 };
	const GLfloat node2[2] = { arm_len,  0.0 };

	float q1 = 45, q2 = 0;
	bool debugmode = false;

	using MyGLBaseCanvas::MyGLBaseCanvas;
private:

	const GLint arm_width = 12;
	void ArgUpdate();
	void Render();
};

