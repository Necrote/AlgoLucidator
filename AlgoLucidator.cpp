#include <GL/freeglut.h>
#include <AL/debug.hpp>
#include <AL/config.hpp>
#include <AL/blobs.hpp>
#include <AL/fonts.hpp>
#include <AL/draw.hpp>
#include <AL/highlight.hpp>
#include <AL/animation.hpp>

unsigned short mainWindow,subWindow1,subWindow2;

void Init(float, float, float);
void Init(float, float, float, int ,int);
void mainInit();
void display();
void onClick(int, int, int, int);
void keyPress(unsigned char,int, int);

int main(int argc, char **argv)
{
#ifdef DEBUG
  mode="InsertionSort";
  b1.bv.resize(7,blobs());
  int rad[7]={28,32,20,28,36,45,31};
  for(int p=0; p<7; p++)
    b1.bv[p].radius=(float)rad[p];
  b1.min=20;
  b1.max=45;
#endif

 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
 glutInitWindowSize(WindowWidth, WindowHeight);
 std::string title="AlgoLucidator " + AL_VERSION;
 mainWindow = glutCreateWindow(title.c_str());
 glutPositionWindow(WIN_POS_X, WIN_POS_Y);
 mainInit();
 glutMouseFunc(onClick);
 glutKeyboardFunc(keyPress);

 subWindow1 = glutCreateSubWindow(mainWindow,0,0,WindowWidth/4,WindowHeight);
 Init(0.80f, 0.80f, 0.60f);
 glutKeyboardFunc(keyPress);
 glutDisplayFunc(display);

 subWindow2 = glutCreateSubWindow(mainWindow,WindowWidth/4,0,3*WindowWidth/4,WindowHeight);
 Init(0.65f, 0.75f, 0.70f);
 std::string mainInstruct="Press 1. InsertionSort   2. BubbleSort   3. Dijkstra";
 printText(0,0,0, -(5*mainInstruct.size()), 540, mainInstruct);
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
  glClearColor(r,g,b,1);
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(-CurrWindowWidth, CurrWindowWidth,-CurrWindowHeight,CurrWindowHeight);
  drawTitle(CurrWindowWidth, CurrWindowHeight);
}

void Init(float r, float g, float b, int width, int height)
{
  glClearColor(r,g,b,1);
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
    case 13:  if(b1.pushreq)
              {
                b1.bv.push_back(blobs((float)base_radius));
              }
              if(activeWindow!=subWindow2)
                glutSetWindow(subWindow2);                                                                                
              if(mode=="InsertionSort")
              {
                drawInsertionSort();
              }
              else if(mode=="BubbleSort")
              {
                drawBubbleSort();
              }
              break;

    case 27:  glutDestroyWindow(mainWindow);  //Esc
              break;

    case 49:  mode="InsertionSort";
              b1.reset();
              glutSetWindow(subWindow2);
              glutMouseFunc(onClick2);
              Init2(0.65f, 0.75f, 0.70f);
              drawTitle3(960,640);
              break;

    case 50:  mode="BubbleSort";
              glutSetWindow(subWindow2);
              glutMouseFunc(onClick3);
              glutIdleFunc(display);
              Init3(0.65f, 0.75f, 0.70f);
              drawTitle4(960,640);
              break;

    case 51:  mode="Dijkstra";
              glutSetWindow(subWindow2);
              djk();
              break;

    default:  ;
  }
}
