#define BLOBSH
#ifndef VECTOR
	#include <vector>
#endif
#define VECTOR

class blobs
{
	float radius;

	public:
	blobs()
	{
		radius=0.0f;
	}
	bool operator< (const blobs&);
	bool operator== (const blobs&);
	bool operator> (const blobs&);
};

class blobvector
{
	public:
	std::vector <blobs> bv;
	float min, max;

	blobvector()
	{
		min=-INF;
		max=INF;
	}
};

bool blobs::operator< (const blobs& b1)
{
	if(this->radius < b1.radius)
		return true;

	return false;
}

bool blobs::operator> (const blobs& b1)
{
	if(this->radius > b1.radius)
		return true;
	
	return false;
}

bool blobs::operator== (const blobs& b1)
{
	if((this->radius-b1.radius) < EPS)
		return true;
	
	return false;
}