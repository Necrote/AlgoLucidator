#define SORTANIMATIONH

extern void Init(float, float, float, int ,int);

void ALdelay()
{
	for(int i=0; i<300000000; ++i);
}

void shiftHighlightBlob(int x1, int y1, int x2, int y2, float radius)
{
	drawFilledBlob((float)x1,(float)y1,radius, 0.65f, 0.75f, 0.70f, 0.65f, 0.75f, 0.70f);
	ALdelay();
	drawFilledBlob((float)x2,(float)y2,radius,0.05, 0.4, 0.7);	
	ALdelay();
}

void shiftBlob(int x1, int y1, int x2, int y2, float radius)
{
	drawFilledBlob((float)x1,(float)y1,radius, 0.65f, 0.75f, 0.70f, 0.65f, 0.75f, 0.70f);
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
		temp.radius = b1.bv[i].radius;
		shiftHighlightBlob(xBegin+gap*(i),0, xBegin+gap*(i), -gap, 0);
		shiftHighlightBlob(xBegin+gap*(i),0, xBegin+gap*(i), -gap, temp.radius);
		j = i-1;

		while (j>=0 && b1.bv[j] > temp)
		{
			b1.bv[j+1].radius = b1.bv[j].radius;
			shiftBlob(xBegin+gap*(j),0, xBegin+gap*(j+1), 0, b1.bv[j].radius);
			j = j-1;
		}
		b1.bv[j+1].radius = temp.radius;
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
}