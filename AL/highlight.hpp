#define HIGHLIGHTH
#ifndef MATHH
	#include <cmath>
#endif
#define MATHH
#ifndef FSTREAMH
  #include <fstream>
#endif
#define FSTREAMH

#ifndef STRINGH
	#include <string>
#endif
#define STRINGH
#ifndef VECTORH
	#include <vector>
#endif
#define VECTORH
using namespace std;

std::vector<std::string>v; // TO STORE LINES OF PSEUDO CODE IN EACH STRING INDEX 
extern unsigned short mainWindow,subWindow1,subWindow2;
void printTextHighlight(float r, float g, float b, float posx, float posy, std::string desc)
{
 glColor3f(r,g,b);     
 glRasterPos2f(posx,posy);
 for(int i = 0; i < desc.size(); ++i) 
  glutBitmapCharacter(GLUT_BITMAP_9_BY_15, desc[i]);
}

void HighlightLines(int l) // function to highlight single line
{
  float xwin= -300;
  float ywin= -400;

   //cout<<"1"<<endl;
  for(int i=v.size()-1;i>=0;i--)
  {
    if(i==l-1)
    {   	
     printTextHighlight(1, 0, 0, xwin, ywin , v[i]);
     ywin+=45;

   }
   else
   {
     printTextHighlight(0, 0, 0, xwin, ywin , v[i]);
     ywin+=45;
   }
 }  
 glFlush();
}

void HighlightLines(std::vector<int> &l)
{
  float xwin= -300;
  float ywin= -400;

  // cout<<"2"<<endl;
  int k=l.size()-1;
  for(int i=v.size()-1;i>=0;i--)
  {
    cout<<l[k]<<endl;
    if(i==l[k]-1 && k!=-1)
    {
     k--;      
     printTextHighlight(1, 0, 0, xwin, ywin , v[i]);
     ywin+=45;
   }
   else
   {
     printTextHighlight(0, 0, 0, xwin, ywin , v[i]);
     ywin+=45;
   }
 }
 glFlush();
}

void Highlight(const char* fname, int l)
{
  std::string line;
  std::ifstream file(fname);
  while(getline(file,line))
   v.push_back(line);
 file.close();

 glutSetWindow(subWindow1);
 HighlightLines(l);
 glutSetWindow(subWindow2);
 v.clear();
}

void Highlight(const char* fname, vector<int> &lnum)
{
  std::string line;
  std::ifstream file(fname);
  while(getline(file,line))
   v.push_back(line);
 file.close();

 glutSetWindow(subWindow1);
 HighlightLines(lnum);
 glutSetWindow(subWindow2);
 v.clear();
}