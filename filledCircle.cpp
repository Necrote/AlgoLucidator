#include <GL/freeglut.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <cmath>
#define PI 3.1415926

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

void display(){
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	drawFilledCircle(0.0, 0.0, 1.0);
}


int main(int argc, char** argv) {
   glutInit(&argc, argv);  
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(640, 480);   
   glutInitWindowPosition(50, 50); 
   glutCreateWindow("window");         
   glutDisplayFunc(display);       
   glutMainLoop();                
   return 0;
}


