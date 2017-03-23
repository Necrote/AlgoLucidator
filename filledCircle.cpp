#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <AL/fonts.hpp>
#include <AL/debug.hpp>
#include <AL/config.hpp>
#include <AL/blobs.hpp>

#define PI 3.1415926


int xi, yi, xf, yf, max_r, pointer = 0, base_radius = 20;
int window_w = 640, window_h = 480;
std::ostringstream ss;
blobvector vec;


/*
	This method renders a circle.
	args: x-coordinate of center, y-coordinate of center, radius
*/
void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius){
	int triangleAmount = 1000; //num of triangles used
	GLfloat twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f(x, y); 
		for(int i = 0; i <= triangleAmount;i++) { 
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)), 
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	glFlush();
}

void mouse(int button, int state, int mx, int my){
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        	switch(pointer){
			case 0:
				base_radius = 20;
				xi = mx;  
	        		yi = window_h - my;
				drawFilledCircle(xi, yi, base_radius);
				//ss << base_radius;
				//printText(0.2, 0.5, 0.6, xi, yi, ss.str());
				pointer = 1;
				break;
			default:
 	     			xf = mx;  
	        	        yf = window_h - my;
				if(xf == xi && yf == yi){
					base_radius += 1;
					drawFilledCircle(xi, yi, base_radius);
					//ss << base_radius;
					//printText(0.2, 0.5, 0.6, xf, yf, ss.str());
				} else{
					blobs b;
					b.radius = base_radius;
					vec.bv.push_back(b);
					pointer = 0;
				}
	        	        break;
        	}  
    	}
}


void display(){  
	glClearColor(0.0, 0.0, 0.0, 1);  
        glColor3f(0.5, 0.35, 0.87);  
        glClear(GL_COLOR_BUFFER_BIT); 
        glFlush();  
}   


void myinit_func(){  
	glViewport(100, 100, 640, 480);  
        glMatrixMode(GL_PROJECTION);  
        glLoadIdentity(); 
        gluOrtho2D(0, window_w, 0, window_h);  
        glMatrixMode(GL_MODELVIEW);  
}  

int main(int argc, char** argv){
	glutInit(&argc, argv);  
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(window_w, window_h);   
	glutInitWindowPosition(50, 50); 
	glutCreateWindow("window");
	glutDisplayFunc(display);
	myinit_func();          
	glutMouseFunc(mouse);	      
	glutMainLoop();                
	return 0;
}


