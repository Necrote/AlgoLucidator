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

int xi, yi, xf, yf, max_r, pointer = 0, base_radius = 20;
std::ostringstream ss;
blobvector b1;

void drawFilledBlob(GLfloat x, GLfloat y, GLfloat radius, float r=0.05, float g=0.8 ,float b=0.2, float r2=0.4, float g2=0.1, float b2=0.1)
{
	int triangleAmount = 1000;
	GLfloat twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(r,g,b);
	glVertex2f(x, y); 
	for(int i = 0; i <= triangleAmount;i++) 
	{ 
		glVertex2f(
			x + (radius * cos(i *  twicePi / triangleAmount)), 
			y + (radius * sin(i * twicePi / triangleAmount))
			);
	}
	glEnd();
	ss << radius;
	printText(r2,g2,b2, x-10, y-5, ss.str());
	ss.str(std::string());
	glutSwapBuffers();
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
			drawFilledBlob(xi, yi, base_radius);
			pointer = 1;
			break;
			default:
			xf = mx;  
			yf = CurrWindowHeight - my;
			if(xf == xi && yf == yi)
			{
				base_radius += 1;
				drawFilledBlob(xi, yi, base_radius);
			}
			else
			{
				blobs b;
				b.radius = base_radius;

				if(base_radius > b1.max)
					b1.max=base_radius;
				if(base_radius < b1.min)
					b1.min=base_radius;

				trace3(base_radius, b1.min, b1.max);
				b1.bv.push_back(b);
				pointer = 0;
			}
			break;
		}  
	}
}
