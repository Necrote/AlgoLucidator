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
/*
void drawTitle(const int CurrWindowWidth,const int CurrWindowHeight)
{
  int index=glutGetWindow()-2;
  printText(0.05f, 0.05f, 0.05f, -(8*sign.size()), -CurrWindowHeight+20, sign);
  if(index>=0)
    printText(0.05f, 0.50f, 0.05f, -(10*projecttitle[index].size()), CurrWindowHeight-50, projecttitle[index]);
  glFlush();
}
*/