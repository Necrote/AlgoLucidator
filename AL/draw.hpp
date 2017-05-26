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

#ifndef CSTRINGH
	#include <cstring>
#endif
#define CSTRINGH

#ifndef CSTDIO
	#include <cstdio>
#endif
#define CSTDIOH

#ifndef CSTDLIB
	#include <cstdlib>
#endif
#define CSTDLIBH

#ifndef UNISTD
	#include <unistd.h>
#endif
#define UNISTD

int xi, yi, xf, yf, max_r, pointer = 0, base_radius = 20;
std::ostringstream ss;
blobvector b1;

int baseX = 75, baseY = 20;
int yy[8], bdX[8];
extern void createBar(int bsx, int bsy, int d);
extern void printb(char c[], int x, int y);
extern void swap(int pos1, int pos2);

void drawFilledBlob(GLfloat x, GLfloat y, GLfloat radius, float r=0.05, float g=0.8 ,float b=0.2, float r2=0.4, float g2=0.1, float b2=0.1, bool flag=true)
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
	if(flag)
		printText(r2,g2,b2, x-10, y-5, ss.str());
	ss.str(std::string());
	glFlush();
}

void Init2(float r, float g, float b)
{
	int CurrWindowWidth=glutGet(GLUT_WINDOW_WIDTH);
	int CurrWindowHeight=glutGet(GLUT_WINDOW_HEIGHT);

	glClearColor(r,g,b,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, CurrWindowWidth,0, CurrWindowHeight);
	drawTitle3(CurrWindowWidth, CurrWindowHeight);
}

void Init3(float r, float g, float b)
{
	glClearColor(r,g,b, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 960, 0, 640);
	drawTitle4(960, 640);
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
			b1.pushreq=true;
			pointer = 1;
			break;
			default:
			xf = mx;  
			yf = CurrWindowHeight - my;
			if(xf == xi && yf == yi)
			{
				base_radius += 1;
				drawFilledBlob(xi, yi, base_radius);
				b1.pushreq=true;
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
				b1.pushreq=false;
				pointer = 0;
			}
			break;
		}  
	}
}

void onClick3(int button, int state, int x, int y)
{
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		if(x >= 25 && x <= 90){
			yy[0] = 640-(y+20);
			bdX[0] = baseX;
			createBar(bdX[0], baseY,640-(y));
		}
		else if(x >= 165 && x <= 220){
			yy[1] = 640-(y+20);
			bdX[1] = baseX+110;
			createBar(bdX[1], baseY, 640-(y));
		}
		else if(x >= 275 && x <= 330){
			yy[2] = 640-(y+20);
			bdX[2] = baseX+220;
			createBar(bdX[2], baseY, 640-(y));
		}
		else if(x >= 385 && x <= 440){
			yy[3] = 640-(y+20);
			bdX[3] = baseX+330;
			createBar(bdX[3], baseY, 640-(y));
		}
		else if(x >= 495 && x <= 550){
			yy[4] = 640-(y+20);
			bdX[4] = baseX+440;
			createBar(bdX[4], baseY, 640-(y));
		}
		else if(x >= 605 && x <= 660){
			yy[5] = 640-(y+20);
			bdX[5] = baseX+550;
			createBar(bdX[5], baseY, 640-(y));
		}
		else if(x >= 715 && x <= 770){
			yy[6] = 640-(y+20);
			bdX[6] = baseX+660;
			createBar(bdX[6], baseY, 640-(y));
		}
		else if(x >= 825 && x <= 880){
			yy[7] = 640-(y+20);
			bdX[7] = baseX+770;
			createBar(bdX[7], baseY, 640-(y));
		}
		/*else if(x >= 935 && x <= 990){
			yy[8] = 640-(y+20);
			bdX[8] = baseX+880;
			createBar(bdX[8], baseY, 640-(y));
		}
		else if(x >= 1045 && x <= 1100){
			yy[9] = 640-(y+20);
			bdX[9] = baseX+990;
			createBar(bdX[9], baseY, 640-(y));
		}
		else if(x >= 1155 && x <= 1210){
			yy[10] = 640-(y+20);
			bdX[10] = baseX+1100;
			createBar(bdX[10], baseY, 640-(y));
		}*/
	}
	glFlush();
}