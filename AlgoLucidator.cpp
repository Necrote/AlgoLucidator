#include <GL/freeglut.h>
#include <AL/debug.hpp>
#include <AL/config.hpp>
#include <AL/blobs.hpp>
#include <AL/fonts.hpp>
#include <AL/draw.hpp>
#include <AL/sortanimation.hpp>

unsigned short mainWindow,subWindow1,subWindow2;

void Init(float, float, float);
void Init(float, float, float, int ,int);
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

void Init(float r, float g, float b, int width, int height)
{
  glClearColor(r,g,b,0.80f);
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(-width, width,-height,height);
  drawTitle(width, height);
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
  int activeWindow=glutGetWindow();
  switch(key)
  {
    case 13:  if(activeWindow!=subWindow2)
                  glutSetWindow(subWindow2);
              if(mode=="InsertionSort")
              {
                drawInsertionSort();
              }
              break;

    case 27:  glutDestroyWindow(mainWindow);  //Esc
              break;

    case 49:  mode="InsertionSort";
              b1.reset();
              glutSetWindow(subWindow2);
              glutMouseFunc(onClick2);
              Init2(0.65f, 0.75f, 0.70f);
              break;

    default:  ;
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
