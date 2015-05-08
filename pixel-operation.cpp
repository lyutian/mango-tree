#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{
	Mat img;
	img = imread(argv[1], 1);
	if( argc != 2 || !img.data )
	{
		cout<<"No image data."<<endl;
		return -1;
	}
	namedWindow( "Original Image", WINDOW_AUTOSIZE);
	imshow("Original Image", img);
	waitKey(0);
}
