#define FONTSH
#ifndef STRINGH
	#include <string>
#endif
#define STRINGH

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
  if(index>0)
    {
      printText(0.05f, 0.05f, 0.05f, -(5*sign.size()), -CurrWindowHeight+10, sign);
      printText(0.05f, 0.50f, 0.05f, -(5*projecttitle[index].size()), CurrWindowHeight-40, projecttitle[index]);
    }
  else if(!index)
    printText(0.05f, 0.50f, 0.05f, -(5*projecttitle[index].size()), CurrWindowHeight-40, projecttitle[index]);
  glFlush();
}

void drawTitle2(const int CurrWindowWidth,const int CurrWindowHeight)
{
  int index=glutGetWindow()-2;
  printText(0.05f, 0.05f, 0.05f, CurrWindowWidth/2 - (4*sign.size()), 10, sign);
  if(index>=0)
    printText(0.05f, 0.50f, 0.05f, CurrWindowWidth/2 - (5*projecttitle[index].size()), CurrWindowHeight-25, projecttitle[index]);
  glFlush();
}

void drawTitle3(const int CurrWindowWidth,const int CurrWindowHeight)
{
  std::string title="Insertion Sort";
  std::string instruct="Click anywhere to create blob element and make it grow";
  std::string instruct2="Press Enter to sort";

  int index=glutGetWindow()-2;
  printText(0.05f, 0.05f, 0.05f, CurrWindowWidth/2 - (4*sign.size()), 10, sign);
  if(index>=0)
    printText(0.05f, 0.50f, 0.05f, CurrWindowWidth/2 - (5*projecttitle[index].size()), CurrWindowHeight-25, projecttitle[index]);
 
  printText(0.95f, 0.30f, 0.05f, CurrWindowWidth/2 - (4*title.size()), CurrWindowHeight-50, title);
  printText(0,0,0, CurrWindowWidth/2 - (4*instruct.size()), CurrWindowHeight-70, instruct);
  printText(0,0,0, CurrWindowWidth/2 - (4*instruct2.size()), CurrWindowHeight-90, instruct2);
  glFlush();
}

void drawTitle4(const int CurrWindowWidth,const int CurrWindowHeight)
{
  std::string title="Bubble Sort";
  std::string instruct="Start Clicking from RHS at regular intervals with req. height to create bar elements";
  std::string instruct2="Press Enter to sort";
  int index=glutGetWindow()-2;
  printText(0.05f, 0.05f, 0.05f, CurrWindowWidth/2 - (4*sign.size()), 10, sign);
  if(index>=0)
    printText(0.05f, 0.50f, 0.05f, CurrWindowWidth/2 - (5*projecttitle[index].size()), CurrWindowHeight-25, projecttitle[index]);

  printText(0.95f, 0.30f, 0.05f, CurrWindowWidth/2 - (4*title.size()), CurrWindowHeight-50, title);
  printText(0,0,0, CurrWindowWidth/2 - (4*instruct.size()), CurrWindowHeight-70, instruct);
  printText(0,0,0, CurrWindowWidth/2 - (4*instruct2.size()), CurrWindowHeight-90, instruct2);
  glFlush();
}

void drawTitle5(const int CurrWindowWidth,const int CurrWindowHeight)
{
  std::string title="Dijkstra";
  std::string instruct="Input edge weights in console";
  int index=glutGetWindow()-2;
  printText(0.05f, 0.05f, 0.05f, CurrWindowWidth/2 - (4*sign.size()), 10, sign);
  if(index>=0)
    printText(0.05f, 0.50f, 0.05f, CurrWindowWidth/2 - (5*projecttitle[index].size()), CurrWindowHeight-25, projecttitle[index]);

  printText(0.95f, 0.30f, 0.05f, CurrWindowWidth/2 - (8*title.size()), CurrWindowHeight-50, title);
  printText(0,0,0, CurrWindowWidth/2 - (4*instruct.size()), CurrWindowHeight-70, instruct);
  glFlush();
}

