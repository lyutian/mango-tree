#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

// adding salt noise
void salt(Mat &image, int n)
{
	for (int k=0; k<n; k++)
	{
		int i = rand() % image.cols;
		int j = rand() % image.rows;

		if (image.channels() == 1)
		{
			image.at<uchar>(j,i) = 255;
		}
		else if (image.channels() ==3)
		{
			// Mat::at() method
			image.at<Vec3b>(j,i)[0] = 255;
			image.at<Vec3b>(j,i)[1] = 255;
			image.at<Vec3b>(j,i)[2] = 255;
		}
	}
}

// scaning image by using point
void colorReduce(Mat &image, int div)
{
	int nr = image.rows;
	int nc = image.cols;

	for (int j=0; j<nr; j++)
	{
		uchar* pdata = image.ptr<uchar>(j);
		for (int i=0; i<nc; i++)
		{
			if (image.channels() == 1)
			{
				pdata[i] = pdata[i]/div*div + div/2;
			}
			else if (image.channels() == 3)
			{
				pdata[3*i] = pdata[3*i]/div*div + div/2;
				pdata[3*i+1] = pdata[3*i+1]/div*div + div/2;
				pdata[3*i+2] = pdata[3*i+2]/div*div + div/2;
			}
		}
	}
}

int main(int argc, char *argv[])
{
	Mat img_origin, img;
	img = imread(argv[1], 1);
	img.copyTo(img_origin);

	if( argc != 2 || !img.data )
	{
		cout<<"No image data."<<endl;
		return -1;
	}
	namedWindow("Original Image", WINDOW_AUTOSIZE);
	imshow("Original Image", img);
	
	salt(img, 1000);
	namedWindow("Salt Noise", WINDOW_AUTOSIZE);
	imshow("Salt Noise", img);

	img_origin.copyTo(img);
	colorReduce(img, 128);
	namedWindow("Reduce color image", WINDOW_AUTOSIZE);
	imshow("Reduce color image", img);
	waitKey(0);
}
