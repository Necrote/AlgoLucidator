#define SORTANIMATIONH

extern void Init(float, float, float, int ,int);
extern void Init(float, float, float);

void ALdelay()
{
	for(int i=0; i<300000000; ++i);
}

void shiftHighlightBlob(int x1, int y1, int x2, int y2, float radius, bool flag=true)
{
	if(flag)
	{
		drawFilledBlob((float)x1,(float)y1,radius, 0.65f, 0.75f, 0.70f, 0.65f, 0.75f, 0.70f,false);
		ALdelay();
	}
	drawFilledBlob((float)x2,(float)y2,radius,0.05, 0.4, 0.7);	
	ALdelay();
}

void shiftBlob(int x1, int y1, int x2, int y2, float radius)
{
	drawFilledBlob((float)x1,(float)y1,radius, 0.65f, 0.75f, 0.70f, 0.65f, 0.75f, 0.70f,false);
	ALdelay();
	drawFilledBlob((float)x2,(float)y2,radius);
	ALdelay();
}

void insertionSort()
{
	int i,j, n=b1.bv.size();
	float xBegin=(-(n-1)*b1.max), gap=2*b1.max;
	blobs temp;
	for (i = 1; i < n; i++)
	{
		Highlight("insertionsort.txt",1);
		ALdelay();
		temp.radius = b1.bv[i].radius;
		Highlight("insertionsort.txt",2);
		ALdelay();
		shiftHighlightBlob(xBegin+gap*(i),0, xBegin+gap*(i), -gap, 0, false);
		shiftHighlightBlob(xBegin+gap*(i),0, xBegin+gap*(i), -gap, temp.radius);
		j = i-1;
		Highlight("insertionsort.txt",4);
		ALdelay();

		while (j>=0 && b1.bv[j] > temp)
		{
			Highlight("insertionsort.txt",5);
			ALdelay();
			b1.bv[j+1].radius = b1.bv[j].radius;
			Highlight("insertionsort.txt",4);
			shiftBlob(xBegin+gap*(j),0, xBegin+gap*(j+1), 0, b1.bv[j].radius);
			Highlight("insertionsort.txt",5);
			ALdelay();
			j = j-1;
			Highlight("insertionsort.txt",6);
			ALdelay();
		}
		b1.bv[j+1].radius = temp.radius;
		Highlight("insertionsort.txt",7);
		ALdelay();
		shiftHighlightBlob(xBegin+gap*(i),-gap, xBegin+gap*(j+1), -gap, temp.radius);
		shiftHighlightBlob(xBegin+gap*(j+1),-gap, xBegin+gap*(j+1), 0, temp.radius);
		shiftBlob(xBegin+gap*(j+1), 0, xBegin+gap*(j+1), 0, temp.radius);
	}
}

void drawInsertionSort()
{
	int CurrWindowWidth=glutGet(GLUT_WINDOW_WIDTH);
	int CurrWindowHeight=glutGet(GLUT_WINDOW_HEIGHT);
	int blobs_num= b1.bv.size();

	if(blobs_num > 1)
	{
		int req_width=std::max(CurrWindowWidth, (int)std::ceil(2*b1.max*blobs_num) );
		int req_height=std::max(CurrWindowHeight, (int)std::ceil(2*b1.max) );
		float xc=(-(blobs_num-1)*b1.max), gap=2*b1.max, r;
		Init(0.65f, 0.75f, 0.70f, req_width/2, req_height/2);
		
		for(int i=0; i<blobs_num; ++i)
		{
			r=b1.bv[i].radius;
			drawFilledBlob(xc,0,r);
			glFlush();
			xc+=gap;
			ALdelay();
		}
		insertionSort();
	}
	else
	{
		std::string msg="Already Sorted!!";
		printText(1, 0, 0, -4*msg.size(), CurrWindowHeight-50, msg);
	}
	glutSetWindow(subWindow1);
	Init(0.80f, 0.80f, 0.60f);	
	glutSetWindow(subWindow2);
}

void printb(char c[], int x, int y)
{
	glRasterPos2i(x, y);
	for(int i=0; i<strlen(c); i++){
		glColor3f(0.0, 0.0, 0.0);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,c[i]);
	}
	glFlush();
}

void createBar(int bsx, int bsy, int d)
{
	glColor3f(0.05,0.80,0.20);
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

void swap(int pos1, int pos2)
{
	int temp = yy[pos1];
	yy[pos1] = yy[pos2];
	yy[pos2] = temp;

	Init3(0.65f, 0.75f, 0.70f);
	for(int i=0; i<8; i++){
		createBar(bdX[i], baseY, yy[i]+20);
	}
	// usleep(800000);
}

void drawBubbleSort()
{
	int temp;
	int i,j;
	for(i = 0; i < 7; i++) 
	{
		Highlight("bubblesort.txt",1);
		ALdelay();
		for(j = 0; j < 7-i; j++) 
		{
			Highlight("bubblesort.txt",2);
			ALdelay();

			Highlight("bubblesort.txt",3);
			ALdelay();

			if(yy[j] > yy[j+1]) 
			{
				Highlight("bubblesort.txt",4);
				ALdelay();
				swap(j, j+1);
			}
		}
		Highlight("bubblesort.txt",5);
		ALdelay();
	}
	Highlight("bubblesort.txt",6);
	ALdelay();

	glutSetWindow(subWindow1);
	Init(0.80f, 0.80f, 0.60f);	
	glutSetWindow(subWindow2);
}

void delay() {
	int bx, ax;
	bx = 100;
	label1: ax = 2000;
	label2: ax--;
	if (ax != 0) {
		goto label2;
	}
	bx--;
	if (bx != 0) {
		goto label1;
	}
}

int n = 5;
long dist[GRAPHSIZE][GRAPHSIZE];
long d[GRAPHSIZE];
int prev[GRAPHSIZE];
int dummypath[GRAPHSIZE];
int path[GRAPHSIZE];
int getPath[GRAPHSIZE];
long getDistance[GRAPHSIZE][GRAPHSIZE];
float x = 0, y = 0;
int arr[10];
float m[GRAPHSIZE][GRAPHSIZE] = {
	{
		0,
		1.33,
		0.56,
		-1.33,
		-0.55
	},
	{
		1.33,
		0,
		0,
		-10.6,
		-1.76
	},
	{
		0.56,
		-0.25,
		0,
		1.76,
		-10.6
	},
	{-1.33,
		-10.6,
		1.76,
		0,
		0
	},
	{-0.55,
		-1.76,
		-10.6,
		0.15,
		0
	}
};

int i = 0, j = 0, k = 0;
int a, b, flag = 0;

void destpath(int g) {
	int i, j, w;
	i = 0;
	j = n;
	w = g;
	while (j != 0) {

		if (prev[w] != -1) {
			dummypath[i] = prev[w];
			w = dummypath[i];
			i++;
		}
		j--;
	}
	j = 0;
	i--;
	while (i != -1) {
		path[j] = dummypath[i];
		i--;
		j++;
	}
	path[j] = g;
}

void dijkstra(int s) {
Highlight("dijkstra.txt",1);
delay();
int i, k, mini;
int visited[GRAPHSIZE];
Highlight("dijkstra.txt",3);
delay();

for (i = 1; i <= n; ++i) {
Highlight("dijkstra.txt",5);
delay();
d[i] = INFINITY;
Highlight("dijkstra.txt",6);
delay();
prev[i] = -1;
Highlight("dijkstra.txt",7);
delay();
visited[i] = 0;
Highlight("dijkstra.txt",8);
delay();
dummypath[i] = -1;
}

d[s] = 0;
Highlight("dijkstra.txt",10);
delay();

for (k = 1; k <= n; ++k) {
mini = -1;
for (i = 1; i <= n; ++i)
if (!visited[i] && ((mini == -1) || (d[i] < d[mini])))
mini = i;
Highlight("dijkstra.txt",13);
delay();
visited[mini] = 1;
Highlight("dijkstra.txt",14);
delay();

for (i = 1; i <= n; ++i)
{
Highlight("dijkstra.txt",16);
delay();
if (dist[mini][i]) 
{
	Highlight("dijkstra.txt",17);
	delay();
	Highlight("dijkstra.txt",18);
	delay();
	if (d[mini] + dist[mini][i] < d[i]) 
	{
		Highlight("dijkstra.txt",19);
		delay();
		d[i] = d[mini] + dist[mini][i];
		Highlight("dijkstra.txt",20);
		delay();
		prev[i] = mini;
	}
}
}
}
Highlight("dijkstra.txt",22);
delay();

glutSetWindow(subWindow1);
Init(0.80f, 0.80f, 0.60f);	
glutSetWindow(subWindow2);
}
void callPath(int a, int b) {
int i, j, k;
int u, v, w, dest, src;

src = a;
dest = b;

dijkstra(src);

destpath(dest);

k = 0;
while (path[k] != '\0') {
getPath[k] = path[k];
k++;
}

}
void distanceMatrix(int arr[]) {
int i, j;
for (i = 1; i <= n; ++i)
for (j = 1; j <= n; ++j)
dist[i][j] = 0;

n = 5;
dist[1][2] = arr[0];
dist[1][4] = arr[1];
dist[2][3] = arr[2];
dist[2][4] = arr[3];
dist[3][5] = arr[4];
dist[4][2] = arr[5];
dist[4][3] = arr[6];
dist[4][5] = arr[7];
dist[5][1] = arr[8];
dist[5][3] = arr[9];

for (i = 1; i <= n; ++i)
for (j = 1; j <= n; ++j)
	getDistance[i][j] = dist[i][j];
}
void rev(char s[]) {
int i, j;
char c;

for (i = 0; j = strlen(s) - 1, i < j; i++, j--) {
	c = s[i];
	s[i] = s[j];
	s[j] = c;
}
}
void my_itoa(int n, char s[]) {
int i, sign;

if ((sign == n) < 0)
	n = -n;

i = 0;
do {
	s[i++] = n % 10 + '0';
} while ((n /= 10) > 0);
if (sign < 0)
	s[i++] = '-';

s[i] = '\0';
rev(s);
}

void drawString(float x, float y, float z, char * string) {
char * c;
glRasterPos3f(x, y, z);
for (c = string; * c != '\0'; c++) {
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, * c);
}
}
void drawString1(float x, float y, float z, char * string) {
char * c;
glRasterPos3f(x, y, z);
for (c = string; * c != '\0'; c++) {
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, * c);
}
}
void drawString2(float x, float y, float z, char * string) {
char * c;
glRasterPos3f(x, y, z);
for (c = string; * c != '\0'; c++) {
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, * c);
}
}

void getCube1() {
glBegin(GL_POLYGON);
glColor3f(1.0, 1.0, 0.0);
glVertex3f(25, 225, 0);
glVertex3f(25, 265, 0);
glVertex3f(75, 265, 0);
glVertex3f(75, 225, 0);
glVertex3f(25, 225, 0);
glVertex3f(75, 225, 0);
glVertex3f(100, 250, 0);
glVertex3f(100, 290, 0);
glVertex3f(50, 290, 0);
glVertex3f(25, 265, 0);
glEnd();
glFlush();

glColor3f(1.0, 0.0, 0.0);
glBegin(GL_LINE_STRIP);
glVertex3f(75, 225, 0);
glVertex3f(25, 225, 0);
glVertex3f(25, 265, 0);
glVertex3f(75, 265, 0);
glVertex3f(75, 225, 0);
glVertex3f(100, 250, 0);
glVertex3f(100, 290, 0);
glVertex3f(50, 290, 0);
glVertex3f(25, 265, 0);
glVertex3f(75, 265, 0);
glVertex3f(100, 290, 0);
glEnd();
glFlush();
glColor3f(0.0, 0.0, 0.0);
drawString(35, 245, 0, "Node 1");
glFlush();
}
void getCube2() {
glBegin(GL_POLYGON);
glColor3f(1.0, 1.0, 0.0);
glVertex3f(125, 430, 0);
glVertex3f(125, 390, 0);
glVertex3f(175, 390, 0);
glVertex3f(175, 430, 0);
glVertex3f(175, 390, 0);
glVertex3f(200, 415, 0);
glVertex3f(200, 455, 0);
glVertex3f(150, 455, 0);
glVertex3f(125, 430, 0);
glEnd();
glFlush();

glColor3f(1.0, 0.0, 0.0);
glBegin(GL_LINE_STRIP);
glVertex3f(175, 390, 0);
glVertex3f(125, 390, 0);
glVertex3f(125, 430, 0);
glVertex3f(175, 430, 0);
glVertex3f(175, 390, 0);
glVertex3f(200, 415, 0);
glVertex3f(200, 455, 0);
glVertex3f(150, 455, 0);
glVertex3f(125, 430, 0);
glVertex3f(175, 430, 0);
glVertex3f(200, 455, 0);
glEnd();
glFlush();
glColor3f(0.0, 0.0, 0.0);
drawString(135, 410, 0, "Node 2");
glFlush();
}
void getCube3() {
glBegin(GL_POLYGON);
glColor3f(1.0, 1.0, 0.0);
glVertex3f(300, 430, 0);
glVertex3f(300, 390, 0);
glVertex3f(350, 390, 0);
glVertex3f(350, 430, 0);
glVertex3f(350, 390, 0);
glVertex3f(375, 415, 0);
glVertex3f(375, 455, 0);
glVertex3f(325, 455, 0);
glVertex3f(300, 430, 0);
glEnd();
glFlush();

glColor3f(1.0, 0.0, 0.0);
glBegin(GL_LINE_STRIP);
glVertex3f(350, 390, 0);
glVertex3f(300, 390, 0);
glVertex3f(300, 430, 0);
glVertex3f(350, 430, 0);
glVertex3f(350, 390, 0);
glVertex3f(375, 415, 0);
glVertex3f(375, 455, 0);
glVertex3f(325, 455, 0);
glVertex3f(300, 430, 0);
glVertex3f(350, 430, 0);
glVertex3f(375, 455, 0);
glEnd();
glFlush();
glColor3f(0.0, 0.0, 0.0);
drawString(310, 410, 0, "Node 3");
glFlush();
}
void getCube4() {

glBegin(GL_POLYGON);
glColor3f(1.0, 1.0, 0.0);
glVertex3f(125, 100, 0);
glVertex3f(125, 60, 0);
glVertex3f(175, 60, 0);
glVertex3f(175, 100, 0);
glVertex3f(175, 60, 0);
glVertex3f(200, 85, 0);
glVertex3f(200, 125, 0);
glVertex3f(150, 125, 0);
glVertex3f(125, 100, 0);
glEnd();
glFlush();

glColor3f(1.0, 0.0, 0.0);
glBegin(GL_LINE_STRIP);
glVertex3f(175, 60, 0);
glVertex3f(125, 60, 0);
glVertex3f(125, 100, 0);
glVertex3f(175, 100, 0);
glVertex3f(175, 60, 0);
glVertex3f(200, 85, 0);
glVertex3f(200, 125, 0);
glVertex3f(150, 125, 0);
glVertex3f(125, 100, 0);
glVertex3f(175, 100, 0);
glVertex3f(200, 125, 0);
glEnd();
glFlush();
glColor3f(0.0, 0.0, 0.0);
drawString(135, 80, 0, "Node 4");
glFlush();
}
void getCube5() {
glBegin(GL_POLYGON);
glColor3f(1.0, 1.0, 0.0);
glVertex3f(300, 100, 0);
glVertex3f(300, 60, 0);
glVertex3f(350, 60, 0);
glVertex3f(350, 100, 0);
glVertex3f(350, 60, 0);
glVertex3f(375, 85, 0);
glVertex3f(375, 125, 0);
glVertex3f(325, 125, 0);
glVertex3f(300, 100, 0);
glEnd();
glFlush();

glColor3f(1.0, 0.0, 0.0);
glBegin(GL_LINE_STRIP);
glVertex3f(350, 60, 0);
glVertex3f(300, 60, 0);
glVertex3f(300, 100, 0);
glVertex3f(350, 100, 0);
glVertex3f(350, 60, 0);
glVertex3f(375, 85, 0);
glVertex3f(375, 125, 0);
glVertex3f(325, 125, 0);
glVertex3f(300, 100, 0);
glVertex3f(350, 100, 0);
glVertex3f(375, 125, 0);
glEnd();
glFlush();
glColor3f(0.0, 0.0, 0.0);
drawString(310, 80, 0, "Node 5");
glFlush();
}
void drawLine(int x, int y, int w) {
char z[5];

my_itoa(w, z);
switch (x) {
	case 1:
	if (y == 2) {
		glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(100, 290);
		glVertex2f(137, 340);
		glVertex2f(132, 340);
		glVertex2f(137, 340);
		glVertex2f(137, 333);
		glVertex2f(137, 340);
		glVertex2f(137, 340);
		glVertex2f(175, 390);
		glEnd();
		glFlush();
		drawString(135, 345, 0, z);
		glFlush();
	} else if (y == 3) {
		glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(100, 250);
		glVertex2f(225, 320);
		glVertex2f(220, 322);
		glVertex2f(225, 320);
		glVertex2f(225, 313);
		glVertex2f(225, 320);
		glVertex2f(225, 320);
		glVertex2f(350, 390);
		glEnd();
		glFlush();
		drawString(223, 325, 0, z);
		glFlush();
	} else if (y == 4) {
		glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(75, 225);
		glVertex2f(112, 175);
		glVertex2f(107, 175);
		glVertex2f(112, 175);
		glVertex2f(112, 182);
		glVertex2f(112, 175);
		glVertex2f(112, 175);
		glVertex2f(150, 125);
		glEnd();
		glFlush();
		drawString(108, 182, 0, z);
		glFlush();
	} else {
		glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(75, 225);
		glVertex2f(187, 162);
		glVertex2f(187, 169);
		glVertex2f(187, 162);
		glVertex2f(182, 162);
		glVertex2f(187, 162);
		glVertex2f(187, 162);
		glVertex2f(300, 100);
		glEnd();
		glFlush();
		drawString(185, 167, 0, z);
		glFlush();
	}
	break;

	case 2:
	if (y == 1) {
		glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(125, 390);
		glVertex2f(87, 340);
		glVertex2f(92, 340);
		glVertex2f(87, 340);
		glVertex2f(87, 347);
		glVertex2f(87, 340);
		glVertex2f(87, 340);
		glVertex2f(50, 290);
		glEnd();
		glFlush();
		drawString(83, 345, 0, z);
		glFlush();
	} else if (y == 3) {
		glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(200, 455);
		glVertex2f(262, 455);
		glVertex2f(258, 460);
		glVertex2f(262, 455);
		glVertex2f(258, 450);
		glVertex2f(262, 455);
		glVertex2f(262, 455);
		glVertex2f(325, 455);
		glEnd();
		glFlush();
		drawString(260, 460, 0, z);
		glFlush();
	} else if (y == 4) {
		glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(125, 390);
		glVertex2f(137, 257);
		glVertex2f(133, 262);
		glVertex2f(137, 257);
		glVertex2f(141, 262);
		glVertex2f(137, 257);
		glVertex2f(137, 257);
		glVertex2f(150, 125);
		glEnd();
		glFlush();
		drawString(130, 262, 0, z);
		glFlush();
	} else {
		glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(175, 390);
		glVertex2f(250, 257);
		glVertex2f(245, 257);
		glVertex2f(250, 257);
		glVertex2f(250, 263);
		glVertex2f(250, 257);
		glVertex2f(250, 257);
		glVertex2f(325, 125);
		glEnd();
		glFlush();
		drawString(248, 246, 0, z);
		glFlush();
	}
	break;

	case 3:
	if (y == 1) {
		glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(300, 390);
		glVertex2f(200, 340);
		glVertex2f(202, 348);
		glVertex2f(200, 340);
		glVertex2f(205, 336);
		glVertex2f(200, 340);
		glVertex2f(200, 340);
		glVertex2f(100, 290);
		glEnd();
		glFlush();
		drawString(204, 345, 0, z);
		glFlush();
	} else if (y == 2) {
		glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(300, 390);
		glVertex2f(250, 402);
		glVertex2f(255, 408);
		glVertex2f(250, 402);
		glVertex2f(252, 394);
		glVertex2f(250, 402);
		glVertex2f(250, 402);
		glVertex2f(200, 415);
		glEnd();
		glFlush();
		drawString(248, 407, 0, z);
		glFlush();
	} else if (y == 4) {
		glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(300, 390);
		glVertex2f(225, 257);
		glVertex2f(225, 265);
		glVertex2f(225, 257);
		glVertex2f(230, 257);
		glVertex2f(225, 257);
		glVertex2f(225, 257);
		glVertex2f(150, 125);
		glEnd();
		glFlush();
		drawString(232, 260, 0, z);
		glFlush();
	} else {
		glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(300, 390);
		glVertex2f(312, 257);
		glVertex2f(316, 262);
		glVertex2f(312, 257);
		glVertex2f(308, 262);
		glVertex2f(312, 257);
		glVertex2f(312, 257);
		glVertex2f(325, 125);
		glEnd();
		glFlush();
		drawString(315, 262, 0, z);
		glFlush();
	}
	break;

	case 4:
	if (y == 1) {
		glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(125, 100);
		glVertex2f(75, 162);
		glVertex2f(80, 162);
		glVertex2f(75, 162);
		glVertex2f(75, 155);
		glVertex2f(75, 162);
		glVertex2f(75, 162);
		glVertex2f(25, 225);
		glEnd();
		glFlush();
		drawString(73, 167, 0, z);
		glFlush();
	} else if (y == 2) {
		glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(200, 125);
		glVertex2f(187, 257);
		glVertex2f(191, 253);
		glVertex2f(187, 257);
		glVertex2f(183, 252);
		glVertex2f(187, 257);
		glVertex2f(187, 257);
		glVertex2f(175, 390);
		glEnd();
		glFlush();
		drawString(180, 262, 0, z);
		glFlush();
	} else if (y == 3) {
		glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(200, 125);
		glVertex2f(275, 257);
		glVertex2f(270, 257);
		glVertex2f(275, 257);
		glVertex2f(275, 250);
		glVertex2f(275, 257);
		glVertex2f(275, 257);
		glVertex2f(350, 390);
		glEnd();
		glFlush();
		drawString(273, 262, 0, z);
		glFlush();
	} else {
		glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(175, 60);
		glVertex2f(237, 60);
		glVertex2f(233, 65);
		glVertex2f(237, 60);
		glVertex2f(233, 55);
		glVertex2f(237, 60);
		glVertex2f(237, 60);
		glVertex2f(300, 60);
		glEnd();
		glFlush();
		drawString(235, 65, 0, z);
		glFlush();
	}
	break;

	case 5:
	if (y == 1) {
		glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(325, 125);
		glVertex2f(212, 187);
		glVertex2f(217, 189);
		glVertex2f(212, 187);
		glVertex2f(212, 180);
		glVertex2f(212, 187);
		glVertex2f(212, 187);
		glVertex2f(100, 250);
		glEnd();
		glFlush();
		drawString(210, 192, 0, z);
		glFlush();
	} else if (y == 2) {
		glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(375, 125);
		glVertex2f(287, 270);
		glVertex2f(292, 270);
		glVertex2f(287, 270);
		glVertex2f(287, 263);
		glVertex2f(287, 270);
		glVertex2f(287, 270);
		glVertex2f(200, 415);
		glEnd();
		glFlush();
		drawString(289, 246, 0, z);
		glFlush();
	} else if (y == 3) {
		glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(375, 125);
		glVertex2f(362, 257);
		glVertex2f(366, 252);
		glVertex2f(362, 257);
		glVertex2f(358, 252);
		glVertex2f(362, 257);
		glVertex2f(362, 257);
		glVertex2f(350, 390);
		glEnd();
		glFlush();
		drawString(365, 262, 0, z);
		glFlush();
	} else {
		glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(300, 100);
		glVertex2f(250, 92);
		glVertex2f(254, 99);
		glVertex2f(250, 92);
		glVertex2f(254, 88);
		glVertex2f(250, 92);
		glVertex2f(250, 92);
		glVertex2f(200, 85);
		glEnd();
		glFlush();
		drawString(247, 94, 0, z);
		glFlush();
	}
	break;
	default:
	break;
}
glFlush();
}
void getLines() {
int i, j, w;

glLineWidth(1);

for (i = 1; i <= n; i++) {
	for (j = 1; j <= n; j++) {
		if (dist[i][j] != 0) {
			w = dist[i][j];

			drawLine(i, j, w);
		}
	}
}
}
void mydisp2() {
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glClearColor(0.65, 0.75, 0.70, 1);
drawTitle2(640, 499);
getCube1();
getCube2();
getCube3();
getCube4();
getCube5();
getLines();

glColor3f(0.0, 0.0, 1.0);
drawString2(385, 235, 0, "Press the E or e to RUN");

glFlush();
}
void mydisp1() {
mydisp2();
}
void getFinalCube1() {
glBegin(GL_POLYGON);
glColor3f(0.0, 1.0, 0.0);
glVertex3f(25, 225, 0);
glVertex3f(25, 265, 0);
glVertex3f(75, 265, 0);
glVertex3f(75, 225, 0);
glVertex3f(25, 225, 0);
glVertex3f(75, 225, 0);
glVertex3f(100, 250, 0);
glVertex3f(100, 290, 0);
glVertex3f(50, 290, 0);
glVertex3f(25, 265, 0);
glEnd();
glFlush();

glColor3f(1.0, 0.0, 0.0);
glBegin(GL_LINE_STRIP);
glVertex3f(75, 225, 0);
glVertex3f(25, 225, 0);
glVertex3f(25, 265, 0);
glVertex3f(75, 265, 0);
glVertex3f(75, 225, 0);
glVertex3f(100, 250, 0);
glVertex3f(100, 290, 0);
glVertex3f(50, 290, 0);
glVertex3f(25, 265, 0);
glVertex3f(75, 265, 0);
glVertex3f(100, 290, 0);
glEnd();
glFlush();
glColor3f(0.0, 0.0, 0.0);
drawString(35, 245, 0, "Node 1");
glFlush();
}
void getFinalCube2() {
glBegin(GL_POLYGON);
glColor3f(0.0, 1.0, 0.0);
glVertex3f(125, 430, 0);
glVertex3f(125, 390, 0);
glVertex3f(175, 390, 0);
glVertex3f(175, 430, 0);
glVertex3f(175, 390, 0);
glVertex3f(200, 415, 0);
glVertex3f(200, 455, 0);
glVertex3f(150, 455, 0);
glVertex3f(125, 430, 0);
glEnd();
glFlush();

glColor3f(1.0, 0.0, 0.0);
glBegin(GL_LINE_STRIP);
glVertex3f(175, 390, 0);
glVertex3f(125, 390, 0);
glVertex3f(125, 430, 0);
glVertex3f(175, 430, 0);
glVertex3f(175, 390, 0);
glVertex3f(200, 415, 0);
glVertex3f(200, 455, 0);
glVertex3f(150, 455, 0);
glVertex3f(125, 430, 0);
glVertex3f(175, 430, 0);
glVertex3f(200, 455, 0);
glEnd();
glFlush();
glColor3f(0.0, 0.0, 0.0);
drawString(135, 410, 0, "Node 2");
glFlush();
}
void getFinalCube3() {
glBegin(GL_POLYGON);
glColor3f(0.0, 1.0, 0.0);
glVertex3f(300, 430, 0);
glVertex3f(300, 390, 0);
glVertex3f(350, 390, 0);
glVertex3f(350, 430, 0);
glVertex3f(350, 390, 0);
glVertex3f(375, 415, 0);
glVertex3f(375, 455, 0);
glVertex3f(325, 455, 0);
glVertex3f(300, 430, 0);
glEnd();
glFlush();

glColor3f(1.0, 0.0, 0.0);
glBegin(GL_LINE_STRIP);
glVertex3f(350, 390, 0);
glVertex3f(300, 390, 0);
glVertex3f(300, 430, 0);
glVertex3f(350, 430, 0);
glVertex3f(350, 390, 0);
glVertex3f(375, 415, 0);
glVertex3f(375, 455, 0);
glVertex3f(325, 455, 0);
glVertex3f(300, 430, 0);
glVertex3f(350, 430, 0);
glVertex3f(375, 455, 0);
glEnd();
glFlush();
glColor3f(0.0, 0.0, 0.0);
drawString(310, 410, 0, "Node 3");
glFlush();
}
void getFinalCube4() {

glBegin(GL_POLYGON);
glColor3f(0.0, 1.0, 0.0);
glVertex3f(125, 100, 0);
glVertex3f(125, 60, 0);
glVertex3f(175, 60, 0);
glVertex3f(175, 100, 0);
glVertex3f(175, 60, 0);
glVertex3f(200, 85, 0);
glVertex3f(200, 125, 0);
glVertex3f(150, 125, 0);
glVertex3f(125, 100, 0);
glEnd();
glFlush();

glColor3f(1.0, 0.0, 0.0);
glBegin(GL_LINE_STRIP);
glVertex3f(175, 60, 0);
glVertex3f(125, 60, 0);
glVertex3f(125, 100, 0);
glVertex3f(175, 100, 0);
glVertex3f(175, 60, 0);
glVertex3f(200, 85, 0);
glVertex3f(200, 125, 0);
glVertex3f(150, 125, 0);
glVertex3f(125, 100, 0);
glVertex3f(175, 100, 0);
glVertex3f(200, 125, 0);
glEnd();
glFlush();
glColor3f(0.0, 0.0, 0.0);
drawString(135, 80, 0, "Node 4");
glFlush();
}
void getFinalCube5() {
glBegin(GL_POLYGON);
glColor3f(0.0, 1.0, 0.0);
glVertex3f(300, 100, 0);
glVertex3f(300, 60, 0);
glVertex3f(350, 60, 0);
glVertex3f(350, 100, 0);
glVertex3f(350, 60, 0);
glVertex3f(375, 85, 0);
glVertex3f(375, 125, 0);
glVertex3f(325, 125, 0);
glVertex3f(300, 100, 0);
glEnd();
glFlush();

glColor3f(1.0, 0.0, 0.0);
glBegin(GL_LINE_STRIP);
glVertex3f(350, 60, 0);
glVertex3f(300, 60, 0);
glVertex3f(300, 100, 0);
glVertex3f(350, 100, 0);
glVertex3f(350, 60, 0);
glVertex3f(375, 85, 0);
glVertex3f(375, 125, 0);
glVertex3f(325, 125, 0);
glVertex3f(300, 100, 0);
glVertex3f(350, 100, 0);
glVertex3f(375, 125, 0);
glEnd();
glFlush();
glColor3f(0.0, 0.0, 0.0);
drawString(310, 80, 0, "Node 5");
glFlush();
}
void mydisp4() {

if (a == b) {
	if (a == 1) {
		getFinalCube1();
		glColor3f(0.0, 0.0, 1.0);
		drawString(10, 295, 0, "Source");
		drawString(10, 210, 0, "Destination");
		glFlush();
	} else if (a == 2) {
		getFinalCube2();
		glColor3f(0.0, 0.0, 1.0);
		drawString(110, 460, 0, "Source");
		drawString(110, 375, 0, "Destination");
		glFlush();
	} else if (a == 3) {
		getFinalCube3();
		glColor3f(0.0, 0.0, 1.0);
		drawString(285, 460, 0, "Source");
		drawString(285, 375, 0, "Destination");
		glFlush();
	} else if (a == 4) {
		getFinalCube4();
		glColor3f(0.0, 0.0, 1.0);
		drawString(110, 130, 0, "Source");
		drawString(110, 45, 0, "Destination");
		glFlush();
	} else {
		getFinalCube5();
		glColor3f(0.0, 0.0, 1.0);
		drawString(285, 130, 0, "Source");
		drawString(285, 45, 0, "Destination");
		glFlush();
	}
	glFlush();
} else {
	glColor3f(0.0, 0.0, 1.0);
	if (a == 1)
		drawString(10, 295, 0, "Source");
	else if (a == 2)
		drawString(110, 460, 0, "Source");
	else if (a == 3)
		drawString(285, 460, 0, "Source");
	else if (a == 4)
		drawString(110, 130, 0, "Source");
	else if (a == 5)
		drawString(285, 130, 0, "Source");

	if (b == 1)
		drawString(10, 210, 0, "Destination");
	else if (b == 2)
		drawString(110, 375, 0, "Destination");
	else if (b == 3)
		drawString(285, 375, 0, "Destination");
	else if (b == 4)
		drawString(110, 45, 0, "Destination");
	else if (b == 5)
		drawString(285, 45, 0, "Destination");

	i = 0;
	while (getPath[i + 1] != '\0') {
		if (getPath[i] == 1) {
			getFinalCube1();
			glFlush();
			if (getPath[i + 1] == 2) {
				x = 0;
				y = 0;
				x = m[i][i + 1] * y;
				for (j = 0; j < 125; j = j + 60) {
					glBegin(GL_POLYGON);
					glColor3f(1.0, 0.0, 0.0);
					glVertex3f(110 + x, 290 + y, 0);
					glVertex3f(125 + x, 307.5 + y, 0);
					glVertex3f(130 + x, 302.5 + y, 0);
					glVertex3f(115 + x, 285 + y, 0);
					glVertex3f(110 + x, 290 + y, 0);
					y = y + 33;
					x = x + 25;

					glFlush();
					glEnd();
					for (k = 0; k <= 100; k++) {
						delay();
					}
					glFlush();
				}
				getFinalCube2();
				glFlush();
			} else if (getPath[i + 1] == 3) {
				x = 0;
				y = 0;
				x = m[i][i + 1] * y;
				for (j = 0; j < 125; j = j + 31) {
					glBegin(GL_POLYGON);
					glColor3f(1.0, 0.0, 0.0);
					glVertex3f(112.5 + x, 250 + y, 0);
					glVertex3f(135 + x, 265 + y, 0);
					glVertex3f(137.5 + x, 260 + y, 0);
					glVertex3f(115 + x, 245 + y, 0);
					glVertex3f(112.5 + x, 250 + y, 0);
					y = y + 25;
					x = x + 48;

					glFlush();
					glEnd();
					for (k = 0; k <= 100; k++) {
						delay();
					}
					glFlush();
				}

				getFinalCube3();
				glFlush();
			} else if (getPath[i + 1] == 4) {
				x = 0;
				y = 0;
				x = m[i][i + 1] * y;
				for (j = 0; j < 125; j = j + 60) {
					glBegin(GL_POLYGON);
					glColor3f(1.0, 0.0, 0.0);
					glVertex3f(65 + x, 220 + y, 0);
					glVertex3f(80 + x, 200 + y, 0);
					glVertex3f(75 + x, 195 + y, 0);
					glVertex3f(60 + x, 215 + y, 0);
					glVertex3f(65 + x, 220 + y, 0);
					y = y - 33;
					x = x + 25;

					glFlush();
					glEnd();
					for (k = 0; k <= 300; k++) {
						delay();
					}
					glFlush();
				}
				getFinalCube4();
				glFlush();
			} else {
				x = 0;
				y = 0;
				x = m[i][i + 1] * y;
				for (j = 0; j < 125; j = j + 40) {
					glBegin(GL_POLYGON);
					glColor3f(1.0, 0.0, 0.0);
					glVertex3f(95 + x, 210 + y, 0);
					glVertex3f(117.5 + x, 197.5 + y, 0);
					glVertex3f(115 + x, 192.5 + y, 0);
					glVertex3f(92.5 + x, 205 + y, 0);
					glVertex3f(95 + x, 210 + y, 0);
					y = y - 32;
					x = x + 56;

					glFlush();
					glEnd();
					for (k = 0; k <= 300; k++) {
						delay();
					}
					glFlush();
				}

				getFinalCube5();
				glFlush();
			}
			glFlush();
		} else if (getPath[i] == 2) {
			getFinalCube2();
			glFlush();
			if (getPath[i + 1] == 1) {
				x = 0;
				y = 0;
				x = m[i][i + 1] * y;
				for (j = 0; j < 125; j = j + 60) {
					glBegin(GL_POLYGON);
					glColor3f(1.0, 0.0, 0.0);
					glVertex3f(120 + x, 375 + y, 0);
					glVertex3f(125 + x, 370 + y, 0);
					glVertex3f(110 + x, 350 + y, 0);
					glVertex3f(105 + x, 355 + y, 0);
					glVertex3f(120 + x, 375 + y, 0);
					y = y - 25;
					x = x - 18;

					glFlush();
					glEnd();
					for (k = 0; k <= 100; k++) {
						delay();
					}
					glFlush();
				}
				getFinalCube1();
				glFlush();
			} else if (getPath[i + 1] == 3) {
				x = 0;
				y = 0;
				x = m[i][i + 1] * y;
				for (j = 0; j < 125; j = j + 50) {
					glBegin(GL_POLYGON);
					glColor3f(1.0, 0.0, 0.0);
					glVertex3f(212.5 + x, 445 + y, 0);
					glVertex3f(237.5 + x, 445 + y, 0);
					glVertex3f(237.5 + x, 438 + y, 0);
					glVertex3f(212.5 + x, 438 + y, 0);
					glVertex3f(212.5 + x, 445 + y, 0);
					y = y;
					x = x + 30;

					glFlush();
					glEnd();
					for (k = 0; k <= 300; k++) {
						delay();
					}
					glFlush();
				}
				getFinalCube3();
				glFlush();
			} else if (getPath[i + 1] == 4) {
				x = 0;
				y = 0;
				x = m[i][i + 1] * y;
				for (j = 0; j < 125; j = j + 35) {
					glBegin(GL_POLYGON);
					glColor3f(1.0, 0.0, 0.0);
					glVertex3f(135 + x, 380 + y, 0);
					glVertex3f(137.5 + x, 355 + y, 0);
					glVertex3f(142.5 + x, 359 + y, 0);
					glVertex3f(140 + x, 383.5 + y, 0);
					glVertex3f(135 + x, 380 + y, 0);
					y = y - 70;
					x = x + 5;

					glFlush();
					glEnd();
					for (k = 0; k <= 300; k++) {
						delay();
					}
					glFlush();
				}
				getFinalCube4();

				glFlush();
			} else {
				x = 0;
				y = 0;
				x = m[i][i + 1] * y;
				for (j = 0; j < 125; j = j + 31) {
					glBegin(GL_POLYGON);
					glColor3f(1.0, 0.0, 0.0);
					glVertex3f(182.5 + x, 367.5 + y, 0);
					glVertex3f(195 + x, 345 + y, 0);
					glVertex3f(190 + x, 342.5 + y, 0);
					glVertex3f(177.5 + x, 365 + y, 0);
					glVertex3f(182.5 + x, 367.5 + y, 0);
					y = y - 66;
					x = x + 37;

					glFlush();
					glEnd();
					for (k = 0; k <= 100; k++) {
						delay();
					}
					glFlush();
				}
				getFinalCube5();
				glFlush();
			}
			glFlush();
		} else if (getPath[i] == 3) {
			getFinalCube3();
			glFlush();
			if (getPath[i + 1] == 1) {
				x = 0;
				y = 0;
				x = m[i][i + 1] * y;
				for (j = 0; j < 125; j = j + 31) {
					glBegin(GL_POLYGON);
					glColor3f(1.0, 0.0, 0.0);
					glVertex3f(297.5 + x, 382.5 + y, 0);
					glVertex3f(275 + x, 372.5 + y, 0);
					glVertex3f(277.5 + x, 367.5 + y, 0);
					glVertex3f(300 + x, 377.5 + y, 0);
					glVertex3f(297.5 + x, 382.5 + y, 0);
					y = y - 25;
					x = x - 50;

					glFlush();
					glEnd();
					for (k = 0; k <= 100; k++) {
						delay();
					}
					glFlush();
				}
				getFinalCube1();
				glFlush();
			} else if (getPath[i + 1] == 2) {
				x = 0;
				y = 0;
				x = m[i][i + 1] * y;
				for (j = 0; j < 125; j = j + 60) {
					glBegin(GL_POLYGON);
					glColor3f(1.0, 0.0, 0.0);
					glVertex3f(290 + x, 385 + y, 0);
					glVertex3f(287.5 + x, 380 + y, 0);
					glVertex3f(265 + x, 387.5 + y, 0);
					glVertex3f(267.5 + x, 392.5 + y, 0);
					glVertex3f(290 + x, 385 + y, 0);
					y = y + 6.25;
					x = x - 30;

					glFlush();
					glEnd();
					for (k = 0; k <= 100; k++) {
						delay();
					}
					glFlush();
				}
				getFinalCube2();
				glFlush();
			} else if (getPath[i + 1] == 4) {
				x = 0;
				y = 0;
				x = m[i][i + 1] * y;
				for (j = 0; j < 125; j = j + 31) {
					glBegin(GL_POLYGON);
					glColor3f(1.0, 0.0, 0.0);
					glVertex3f(295 + x, 372.5 + y, 0);
					glVertex3f(282.5 + x, 350 + y, 0);
					glVertex3f(287.5 + x, 347.5 + y, 0);
					glVertex3f(300 + x, 370 + y, 0);
					glVertex3f(295 + x, 372.5 + y, 0);
					y = y - 66.25;
					x = x - 37.5;

					glFlush();
					glEnd();
					for (k = 0; k <= 100; k++) {
						delay();
					}
					glFlush();
				}
				getFinalCube4();
				glFlush();
			} else {
				x = 0;
				y = 0;
				x = m[i][i + 1] * y;
				for (j = 0; j < 125; j = j + 35) {
					glBegin(GL_POLYGON);
					glColor3f(1.0, 0.0, 0.0);
					glVertex3f(310 + x, 385 + y, 0);
					glVertex3f(313 + x, 360 + y, 0);
					glVertex3f(317.5 + x, 362.5 + y, 0);
					glVertex3f(315 + x, 387.5 + y, 0);
					glVertex3f(310 + x, 385 + y, 0);
					y = y - 70;
					x = x + 5;

					glFlush();
					glEnd();
					for (k = 0; k <= 300; k++) {
						delay();
					}
					glFlush();
				}
				getFinalCube5();

				glFlush();
			}
			glFlush();
		} else if (getPath[i] == 4) {
			getFinalCube4();
			glFlush();
			if (getPath[i + 1] == 1) {
				x = 0;
				y = 0;
				x = m[i][i + 1] * y;
				for (j = 0; j < 125; j = j + 45) {
					glBegin(GL_POLYGON);
					glColor3f(1.0, 0.0, 0.0);
					glVertex3f(127.5 + x, 115 + y, 0);
					glVertex3f(112.5 + x, 135 + y, 0);
					glVertex3f(107.5 + x, 132.5 + y, 0);
					glVertex3f(122.5 + x, 112.5 + y, 0);
					glVertex3f(127.5 + x, 115 + y, 0);
					y = y + 31.25;
					x = x - 25;

					glFlush();
					glEnd();
					for (k = 0; k <= 300; k++) {
						delay();
					}
					glFlush();
				}
				getFinalCube1();
				glFlush();
			} else if (getPath[i + 1] == 2) {
				x = 0;
				y = 0;
				x = m[i][i + 1] * y;
				for (j = 0; j < 125; j = j + 35) {
					glBegin(GL_POLYGON);
					glColor3f(1.0, 0.0, 0.0);
					glVertex3f(210 + x, 125 + y, 0);
					glVertex3f(207.5 + x, 155 + y, 0);
					glVertex3f(212.5 + x, 157.5 + y, 0);
					glVertex3f(215 + x, 127.5 + y, 0);
					glVertex3f(210 + x, 125 + y, 0);
					y = y + 70;
					x = x - 5;

					glFlush();
					glEnd();
					for (k = 0; k <= 300; k++) {
						delay();
					}
					glFlush();
				}
				getFinalCube2();
				glFlush();
			} else if (getPath[i + 1] == 3) {
				x = 0;
				y = 0;
				x = m[i][i + 1] * y;
				for (j = 0; j < 125; j = j + 22) {
					glBegin(GL_POLYGON);
					glColor3f(1.0, 0.0, 0.0);
					glVertex3f(210 + x, 125 + y, 0);
					glVertex3f(222.5 + x, 145 + y, 0);
					glVertex3f(226 + x, 138 + y, 0);
					glVertex3f(215 + x, 120 + y, 0);
					glVertex3f(210 + x, 125 + y, 0);
					y = y + 45;
					x = x + 25;

					glFlush();
					glEnd();
					for (k = 0; k <= 300; k++) {
						delay();
					}
					glFlush();
				}

				getFinalCube3();
				glFlush();
			} else {
				x = 0;
				y = 0;
				x = m[i][i + 1] * y;
				for (j = 0; j < 125; j = j + 50) {
					glBegin(GL_POLYGON);
					glColor3f(1.0, 0.0, 0.0);
					glVertex3f(180 + x, 50 + y, 0);
					glVertex3f(205 + x, 50 + y, 0);
					glVertex3f(205 + x, 42.5 + y, 0);
					glVertex3f(180 + x, 42.5 + y, 0);
					glVertex3f(180 + x, 50 + y, 0);
					y = y;
					x = x + 40;

					glFlush();
					glEnd();
					for (k = 0; k <= 300; k++) {
						delay();
					}
					glFlush();
				}
				getFinalCube5();
				glFlush();
			}
			glFlush();
		} else {
			getFinalCube5();
			glFlush();
			if (getPath[i + 1] == 1) {
				x = 0;
				y = 0;
				x = m[i][i + 1] * y;
				for (j = 0; j < 125; j = j + 30) {
					glBegin(GL_POLYGON);
					glColor3f(1.0, 0.0, 0.0);
					glVertex3f(315 + x, 120 + y, 0);
					glVertex3f(287.5 + x, 132.5 + y, 0);
					glVertex3f(282.5 + x, 127.5 + y, 0);
					glVertex3f(310 + x, 115 + y, 0);
					glVertex3f(315 + x, 120 + y, 0);
					y = y + 25;
					x = x - 45;

					glFlush();
					glEnd();
					for (k = 0; k <= 300; k++) {
						delay();
					}
					glFlush();
				}

				getFinalCube1();
				glFlush();
			} else if (getPath[i + 1] == 2) {
				x = 0;
				y = 0;
				x = m[i][i + 1] * y;
				for (j = 0; j < 125; j = j + 30) {
					glBegin(GL_POLYGON);
					glColor3f(1.0, 0.0, 0.0);
					glVertex3f(362.5 + x, 130 + y, 0);
					glVertex3f(350 + x, 150 + y, 0);
					glVertex3f(345 + x, 147.5 + y, 0);
					glVertex3f(357.5 + x, 127.5 + y, 0);
					glVertex3f(362.5 + x, 130 + y, 0);
					y = y + 60;
					x = x - 35;

					glFlush();
					glEnd();
					for (k = 0; k <= 300; k++) {
						delay();
					}
					glFlush();
				}

				getFinalCube2();
				glFlush();
			} else if (getPath[i + 1] == 3) {
				x = 0;
				y = 0;
				x = m[i][i + 1] * y;
				for (j = 0; j < 125; j = j + 35) {
					glBegin(GL_POLYGON);
					glColor3f(1.0, 0.0, 0.0);
					glVertex3f(385 + x, 125 + y, 0);
					glVertex3f(382.5 + x, 155 + y, 0);
					glVertex3f(387.5 + x, 157.5 + y, 0);
					glVertex3f(390 + x, 127.5 + y, 0);
					glVertex3f(385 + x, 125 + y, 0);
					y = y + 70;
					x = x - 5;

					glFlush();
					glEnd();
					for (k = 0; k <= 300; k++) {
						delay();
					}
					glFlush();
				}
				getFinalCube3();
				glFlush();
			} else {
				x = 0;
				y = 0;
				x = m[i][i + 1] * y;
				for (j = 0; j < 125; j = j + 60) {
					glBegin(GL_POLYGON);
					glColor3f(1.0, 0.0, 0.0);
					glVertex3f(295 + x, 95 + y, 0);
					glVertex3f(270 + x, 90 + y, 0);
					glVertex3f(272.5 + x, 85 + y, 0);
					glVertex3f(297.5 + x, 90 + y, 0);
					glVertex3f(295 + x, 95 + y, 0);
					y = y - 5;
					x = x - 35;

					glFlush();
					glEnd();
					for (k = 0; k <= 300; k++) {
						delay();
					}
					glFlush();
				}

				getFinalCube4();
				glFlush();
			}
			glFlush();
		}
		i++;
		glFlush();
	}
}
glFlush();
}
void mydisp3() {

callPath(a, b);
/*
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glClearColor(0.65, 0.75, 0.70, 1);
drawTitle2(640, 499);
*/ 
getCube1();
getCube2();
getCube3();
getCube4();
getCube5();
getLines();

mydisp4();

}
void mykey4(unsigned char key, int x, int y) {

if ((key == 'E' || key == 'e') && flag == 0) {
	flag = 1;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.65, 0.75, 0.70, 1);
	drawTitle2(640, 499);
	getCube1();
	getCube2();
	getCube3();
	getCube4();
	getCube5();
	getLines();
	glColor3f(0.0, 0.0, 1.0);
	drawString2(360, 310, 0, " Enter the number for Source Node");
	drawString2(360, 280, 0, " 1, 2, 3, 4, 5");

	glFlush();
} else if (key == '1' || key == '2' || key == '3' || key == '4' || key == '5') {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.65, 0.75, 0.70, 1);
	drawTitle2(640, 499);
	getCube1();
	getCube2();
	getCube3();
	getCube4();
	getCube5();
	getLines();
	glColor3f(0.0, 0.0, 1.0);

	if (flag == 1) {
		flag = 2;
		drawString2(360, 310, 0, " Enter the number for Destination");
		drawString2(360, 290, 0, " Node:  1, 2, 3, 4, 5");

		if (key == '1') {
			a = 1;
		} else if (key == '2') {
			a = 2;
		} else if (key == '3') {
			a = 3;
		} else if (key == '4') {
			a = 4;
		} else {
			a = 5;
		}

	} else if (flag == 2) {
		if (key == '1') {
			b = 1;
		} else if (key == '2') {
			b = 2;
		} else if (key == '3') {
			b = 3;
		} else if (key == '4') {
			b = 4;
		} else {
			b = 5;
		}

		mydisp3();
	} else {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glFlush();
		glClearColor(0.65, 0.75, 0.70, 1);
		glFlush();
		glColor3f(0.0, 0.0, 1.0);
		drawString1(100, 400, 0, " Invalid Key Pressed ");
		glFlush();
		for (i = 0; i <= 500; i++) {
			delay();
		}
		for (i = 0; i <= 500; i++) {
			delay();
		}
		exit(0);
	}
	glFlush();
} else {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glFlush();
	glClearColor(0.65, 0.75, 0.70, 1);
	glFlush();
	glColor3f(0.0, 0.0, 1.0);
	drawString1(100, 400, 0, " Invalid Key Pressed ");
	glFlush();
	for (i = 0; i <= 500; i++) {
		delay();
	}
	for (i = 0; i <= 500; i++) {
		delay();
	}
	exit(0);
}
}
void mydisp() {
int k=0;
cout<<"Enter Edge weight from Node 1 to Node 2"<<endl;
cin>>arr[k];k++;
cout<<"Enter Edge weight from Node 1 to Node 4"<<endl;
cin>>arr[k];k++;
cout<<"Enter Edge weight from Node 2 to Node 3"<<endl;
cin>>arr[k];k++;
cout<<"Enter Edge weight from Node 2 to Node 4"<<endl;
cin>>arr[k];k++;
cout<<"Enter Edge weight from Node 3 to Node 5"<<endl;
cin>>arr[k];k++;
cout<<"Enter Edge weight from Node 4 to Node 2"<<endl;
cin>>arr[k];k++;
cout<<"Enter Edge weight from Node 4 to Node 3"<<endl;
cin>>arr[k];k++; 
cout<<"Enter Edge weight from Node 4 to Node 5"<<endl;
cin>>arr[k];k++; 
cout<<"Enter Edge weight from Node 5 to Node 1"<<endl;
cin>>arr[k];k++; 
cout<<"Enter Edge weight from Node 5 to Node 3"<<endl;
cin>>arr[k];k++; 
/*
arr[0]=2;
arr[1]=4;
arr[2]=2;
arr[3]=4;
arr[4]=7;
arr[5]=5;
arr[6]=4;
arr[7]=1;
arr[8]=14;
arr[9]=3;
*/
distanceMatrix(arr);
mydisp1();

}

void reshape4(int w, int h) {
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0, 499, 0, 499);
glMatrixMode(GL_MODELVIEW);
glutPostRedisplay();
}
void init() {
glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
glClearColor(0.65, 0.75, 0.70, 1);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0, 499, 0, 499);
drawTitle5(640, 499);   
glMatrixMode(GL_MODELVIEW);
glutPostRedisplay();

}

int djk() {
init();
glutDisplayFunc(mydisp);
glutReshapeFunc(reshape4);
glutKeyboardFunc(mykey4);
}
