#define SORTANIMATIONH

extern void Init(float, float, float, int ,int);

void ALdelay()
{
	for(int i=0; i<300000; ++i);
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
		Init(0.65f, 0.75f, 0.70f, req_width, req_height);
		
		for(int i=0; i<blobs_num; ++i)
		{
			drawFilledCircle((i+1)*b1.max, 0, b1.bv[i].radius);
			ALdelay();
		}
	}
	else
	{
		std::string msg="Already Sorted!!";
		printText(1, 0, 0, -(10*msg.size()), CurrWindowHeight-70, msg);
	}
}