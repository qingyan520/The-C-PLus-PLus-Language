#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int main()
{
	namedWindow("hello", WINDOW_NORMAL);

	waitKey(0);
	destroyWindow("hello");
	return 0;
}