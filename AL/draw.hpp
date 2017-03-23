#define DRAWH
#ifndef MATHH
	#include <cmath>
#endif
#define MATHH

void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius)
{
	int triangleAmount = 1000;
	GLfloat twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(x, y); 
	for(int i = 0; i <= triangleAmount;i++) 
	{ 
		glVertex2f(
			x + (radius * cos(i *  twicePi / triangleAmount)), 
			y + (radius * sin(i * twicePi / triangleAmount))
			);
	}
	glEnd();
	glFlush();
}

