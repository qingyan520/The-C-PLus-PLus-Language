#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int k[9];
Mat MeanSmoothing = (Mat_<double>(3, 3) <<
	1.0 / 9, 1.0 / 9, 1.0 / 9,
	1.0 / 9, 1.0 / 9, 1.0 / 9,
	1.0 / 9, 1.0 / 9, 1.0 / 9);


void Convlution1(Mat  InputImage, Mat  OutputImage, Mat kernel)
{
	//卷积核半径
	int sub_x = kernel.cols / 2;
	int sub_y = kernel.rows / 2;
	//遍历图片
	for (int image_y = 0; image_y < InputImage.rows - 2 * sub_y; image_y++)
	{
		for (int image_x = 0; image_x < InputImage.cols - 2 * sub_x; image_x++)
		{
			int pix_value = 0;
			for (int kernel_y = 0; kernel_y < kernel.rows; kernel_y++)
			{
				for (int kernel_x = 0; kernel_x < kernel.cols; kernel_x++)
				{
					double  weihgt = kernel.at<double>(kernel_y, kernel_x);
					int value = (double)InputImage.at<uchar>(image_y + kernel_y, image_x + kernel_x);
					pix_value += weihgt * value;
				}
			}
			OutputImage.at<uchar>(image_y + sub_y, image_x + sub_x) = saturate_cast<uchar>((double)pix_value);
		}
	}
}

//=======快速排序算法↓↓↓=========
int Partition(int r[9], int first, int end)
{
	int i = first, j = end;
	while (i < j)
	{
		while (i < j && r[i] <= r[j])
		{
			j--;
		}
		if (i < j)
		{
			int temp = r[i];
			r[i] = r[j];
			r[j] = temp;
			i++;
		}
		while (i < j && r[i] <= r[j])
		{
			i++;
		}
		if (i < j)
		{
			int temp = r[i];
			r[i] = r[j];
			r[j] = temp;
			j--;
		}
	}
	return i;
}
void QuickSort(int r[9], int first, int end)
{
	int pivot;
	if (first < end)
	{
		pivot = Partition(r, first, end);
		QuickSort(r, first, pivot);
		QuickSort(r, pivot + 1, end);
	}
}
//=======快速排序算法↑↑↑=========

void Convlution2(Mat  InputImage, Mat  OutputImage)
{
	int count = 0;
	//遍历图片  
	for (int image_y = 0; image_y < InputImage.rows - 2; image_y++)
	{
		for (int image_x = 0; image_x < InputImage.cols - 2; image_x++)
		{
			int pix_value = 0;
			for (int kernel_y = 0; kernel_y < 3; kernel_y++)
			{
				for (int kernel_x = 0; kernel_x < 3; kernel_x++)
				{
					k[count] = (double)InputImage.at<uchar>(image_y + kernel_y, image_x + kernel_x);
					count++;
				}
			}
			count = 0;
			QuickSort(k, 0, 8);
			OutputImage.at<uchar>(image_y + 1, image_x + 1) = saturate_cast<uchar>((double)k[4]);
			for (int i = 0; i < 8; i++)
			{
				k[i] = 0;
			}
		}
	}
}


int main()
{
	Mat InputImage = imread("test.jpg", 0);
	namedWindow("orgin",WINDOW_NORMAL);
	imshow("orgin", InputImage);                            //原图

	Mat OutputImage = imread("test.jpg", 0);
	Convlution1(InputImage, OutputImage, MeanSmoothing);    //领域平均处理后的图
	namedWindow("meanFilter", WINDOW_NORMAL);
	imshow("meanFilter", OutputImage);

	Convlution2(InputImage, OutputImage);                   //中值滤波处理后的图
	namedWindow("medianFilter",WINDOW_NORMAL);
	imshow("medianFilter", OutputImage);
	waitKey(0);
	return 0;

}