#define DRAWH
#ifndef MATHH
	#include <cmath>
#endif
#define MATHH
#ifndef SSTREAMH
	#include <sstream>
#endif
#define SSTREAMH
#ifndef STRINGH
	#include <string>
#endif
#define STRINGH
#ifndef VECTORH
	#include <vector>
#endif
#define VECTORH
#include <iostream>

int xi, yi, xf, yf, max_r, pointer = 0, base_radius = 20;
std::ostringstream ss;
blobvector b1;

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

void Init2(float r, float g, float b)
{
	int CurrWindowWidth=glutGet(GLUT_WINDOW_WIDTH);
	int CurrWindowHeight=glutGet(GLUT_WINDOW_HEIGHT);
	
	glClearColor(r,g,b,0.80f);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, CurrWindowWidth,0, CurrWindowHeight);
	drawTitle2(CurrWindowWidth, CurrWindowHeight);
}

void onClick2(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		int CurrWindowWidth=glutGet(GLUT_WINDOW_WIDTH);
		int CurrWindowHeight=glutGet(GLUT_WINDOW_HEIGHT);
		switch(pointer)
		{
			case 0:
			base_radius = 20;
			xi = mx;  
			yi = CurrWindowHeight - my;
			drawFilledCircle(xi, yi, base_radius);
			ss << base_radius;
			printText(0.2, 0.5, 0.6, xi, yi, ss.str());
			ss.str(std::string());
			pointer = 1;
			break;
			default:
			xf = mx;  
			yf = CurrWindowHeight - my;
			if(xf == xi && yf == yi)
			{
				base_radius += 1;
				drawFilledCircle(xi, yi, base_radius);
				ss << base_radius;
				printText(0.2, 0.5, 0.6, xf, yf, ss.str());
				ss.str(std::string());
			}
			else
			{
				blobs b;
				b.radius = base_radius;
				b1.bv.push_back(b);
				pointer = 0;
			}
			break;
		}  
	}
}
