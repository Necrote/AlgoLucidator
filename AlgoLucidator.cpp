#include <GL/freeglut.h>
#include <iostream>
#include <string>
#include <cmath>
#include <AL/debug.hpp>
#include <AL/config.hpp>

extern std::string AL_VERSION, projecttitle[2], sign;
unsigned short mainWindow,subWindow1,subWindow2;

void printText(float, float, float, float, float, std::string);
void drawTitle(const int,const int);
void Init(float, float, float);
void mainInit();
void display();
void onClick(int, int, int, int);
void keyPress(unsigned char,int, int);
void reshaper(GLsizei, GLsizei);

int main(int argc, char **argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_ALPHA);
 glutInitWindowSize(WindowWidth, WindowHeight);
 std::string title="AlgoLucidator " + AL_VERSION;
 mainWindow = glutCreateWindow(title.c_str());
 glutPositionWindow(WIN_POS_X, WIN_POS_Y);
 mainInit();
 glutReshapeFunc(reshaper);
 glutMouseFunc(onClick);
 glutKeyboardFunc(keyPress);

 subWindow1 = glutCreateSubWindow(mainWindow,0,0,WindowWidth/4,WindowHeight);
 Init(0.80f, 0.80f, 0.60f);
 glutMouseFunc(onClick);
 glutKeyboardFunc(keyPress);
 glutDisplayFunc(display);

 subWindow2 = glutCreateSubWindow(mainWindow,WindowWidth/4,0,3*WindowWidth/4,WindowHeight);
 Init(0.65f, 0.75f, 0.70f);
 glutMouseFunc(onClick);
 glutKeyboardFunc(keyPress);
 glutDisplayFunc(display);
 glutMainLoop();

 return 0;         
}

void printText(float r, float g, float b, float posx, float posy, std::string desc)
{
  glColor3f(r,g,b);     
  glRasterPos2f(posx,posy);
  for (int i = 0; i < desc.size(); ++i) 
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, desc[i]);
}

void drawTitle(const int CurrWindowWidth,const int CurrWindowHeight)
{
  int index=glutGetWindow()-2;
  printText(0.05f, 0.05f, 0.05f, -(8*sign.size()), -CurrWindowHeight+20, sign);
  if(index>=0)
    printText(0.05f, 0.50f, 0.05f, -(10*projecttitle[index].size()), CurrWindowHeight-50, projecttitle[index]);
  glFlush();
}

void Init(float r, float g, float b)
{
  int CurrWindowWidth=glutGet(GLUT_WINDOW_WIDTH);
  int CurrWindowHeight=glutGet(GLUT_WINDOW_HEIGHT);
  glClearColor(r,g,b,0.80f);
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(-CurrWindowWidth, CurrWindowWidth,-CurrWindowHeight,CurrWindowHeight);
  drawTitle(CurrWindowWidth, CurrWindowHeight);
}

void mainInit()
{
  int CurrWindowWidth=glutGet(GLUT_WINDOW_WIDTH);
  int CurrWindowHeight=glutGet(GLUT_WINDOW_HEIGHT);
  glLoadIdentity();
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0, CurrWindowWidth,0,CurrWindowHeight);
  glClearColor(0,0,0,0.80f);
  glClear(GL_COLOR_BUFFER_BIT);
}

void display() 
{
  glFlush();
}

void onClick(int button, int state, int oldx, int oldy)
{}

void keyPress(unsigned char key,int x,int y)
{
  switch(key)
  {
    case 27:  glutDestroyWindow(mainWindow);  //Esc

    default:  break;
  }
}

void reshaper(GLsizei width, GLsizei height)
{
  mainInit();
  glutSetWindow(subWindow1);
  glutReshapeWindow(width/4, height);
  Init(0.80f, 0.80f, 0.60f);
  glutPositionWindow(0,0);
  glutPostRedisplay();
  
  glutSetWindow(subWindow2);
  glutReshapeWindow(3*width/4, height);
  Init(0.65f, 0.75f, 0.70f);
  glutPositionWindow(width/4, 0);
  glutPostRedisplay();
}
