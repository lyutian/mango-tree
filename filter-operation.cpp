#include<opencv2/opencv.hpp>
using namespace cv;

void averageFilter(const Mat &image, Mat &result)
{
	Mat kernel(3,3,CV_32F,Scalar(0));
	kernel.at<float>(0,0) = 1.0/9.0;
	kernel.at<float>(0,1) = 1.0/9.0;
	kernel.at<float>(0,2) = 1.0/9.0;
	kernel.at<float>(1,0) = 1.0/9.0;
	kernel.at<float>(1,1) = 1.0/9.0;
	kernel.at<float>(1,2) = 1.0/9.0;
	kernel.at<float>(2,0) = 1.0/9.0;
	kernel.at<float>(2,1) = 1.0/9.0;
	kernel.at<float>(2,2) = 1.0/9.0;

	filter2D(image, result, image.depth(), kernel);
}

int main(int argc, char* argv[])
{
	Mat img_origin, img;
	img = imread(argv[1],1);
	if(argc != 2 || !img.data)
	{
		std::cout<<"Read image error."<<std::endl;
		return -1;
	}
	img.copyTo(img_origin);
	namedWindow("Original Image", WINDOW_AUTOSIZE);
	imshow("Original Image", img_origin);

	averageFilter(img_origin, img);
	namedWindow("average filter opration", WINDOW_AUTOSIZE);
	imshow("average filter opration",img);

	waitKey(0);
	return 0;
} 
