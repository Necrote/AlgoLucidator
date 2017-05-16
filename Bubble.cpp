#include <stdio.h>
#include <math.h>
#include <string.h>
#include <GL/glut.h>
#include <unistd.h>


int winIdMain;
int baseX = 75, baseY = 20;
int yy[11], bdX[11];

void printb(char c[], int x, int y){
	glRasterPos2i(x, y);
	for(int i=0; i<strlen(c); i++){
		glColor3f(0.0, 0.0, 0.0);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,c[i]);
	}
	glFlush();
}


// Generates a bar
void createBar(int bsx, int bsy, int d){
	glColor3f(0.05,0.80,0.20); //Bar color - same as in AlgoLucidator
	glBegin(GL_POLYGON);
	glVertex2i(bsx, bsy);
	glVertex2i(bsx+20, bsy);
	glVertex2i(bsx+20, d);
	glVertex2i(bsx, d);
	glEnd();
	char c[5];
	sprintf(c, "%d", d-20);
	printb(c, bsx+23, d+5);
}


void swap(int pos1, int pos2){
	glClear(GL_COLOR_BUFFER_BIT);
	int temp = yy[pos1];
	yy[pos1] = yy[pos2];
	yy[pos2] = temp;
	for(int i=0;i<11; i++){
		createBar(bdX[i], baseY, yy[i]+20);
	}
	usleep(80000);
}

void BubbleSort(){
	int temp;
	int i,j;
	for(i = 0; i < 10; i++) {
		for(j = 0; j < 10-i; j++) {
			if(yy[j] > yy[j+1]) {
				swap(j, j+1);
			}
		}
	}
}


//Mouse-Click
void mouse(int button, int state, int x, int y){
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
		if(x >= 25 && x <= 90){
			yy[0] = 675-(y+20);
			bdX[0] = baseX;
			createBar(bdX[0], baseY,675-(y));
		}
		else if(x >= 165 && x <= 220){
			yy[1] = 675-(y+20);
			bdX[1] = baseX+110;
			createBar(bdX[1], baseY, 675-(y));
		}
		else if(x >= 275 && x <= 330){
			yy[2] = 675-(y+20);
			bdX[2] = baseX+220;
			createBar(bdX[2], baseY, 675-(y));
		}
		else if(x >= 385 && x <= 440){
			yy[3] = 675-(y+20);
			bdX[3] = baseX+330;
			createBar(bdX[3], baseY, 675-(y));
		}
		else if(x >= 495 && x <= 550){
			yy[4] = 675-(y+20);
			bdX[4] = baseX+440;
			createBar(bdX[4], baseY, 675-(y));
		}
		else if(x >= 605 && x <= 660){
			yy[5] = 675-(y+20);
			bdX[5] = baseX+550;
			createBar(bdX[5], baseY, 675-(y));
		}
		else if(x >= 715 && x <= 770){
			yy[6] = 675-(y+20);
			bdX[6] = baseX+660;
			createBar(bdX[6], baseY, 675-(y));
		}
		else if(x >= 825 && x <= 880){
			yy[7] = 675-(y+20);
			bdX[7] = baseX+770;
			createBar(bdX[7], baseY, 675-(y));
		}
		else if(x >= 935 && x <= 990){
			yy[8] = 675-(y+20);
			bdX[8] = baseX+880;
			createBar(bdX[8], baseY, 675-(y));
		}
		else if(x >= 1045 && x <= 1100){
			yy[9] = 675-(y+20);
			bdX[9] = baseX+990;
			createBar(bdX[9], baseY, 675-(y));
		}
		else if(x >= 1155 && x <= 1210){
			yy[10] = 675-(y+20);
			bdX[10] = baseX+1100;
			createBar(bdX[10], baseY, 675-(y));
		}

	}
	if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN){
		BubbleSort();
	}
	glutPostRedisplay();
}

void display(){
    glutSwapBuffers();
}

void init(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.65, 0.75, 0.70, 1); //background color - same as in AlgoLucidator
	glColor3f(0.0, 0.0, 0.0); 
	glOrtho(0, 1350, 0, 675, -1.0, 1.0);
	glViewport(0, 0, 1350, 675);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}

int main(int argc, char **argv){
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition (0, 0);
	glutInitWindowSize (1350, 675);
	winIdMain = glutCreateWindow ("The OpenGL");
	init();
	glClear(GL_COLOR_BUFFER_BIT);
	glutMouseFunc(mouse);
	glutIdleFunc(display);
	glutMainLoop();
}