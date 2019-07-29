#include <iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("cat.jpg");

	//Blurring the image
	Mat img_blur;
	Size ksize = { 9, 9 };
	blur(img, img_blur, ksize);
	namedWindow("Blurred Image", WINDOW_NORMAL);
	imshow("Blurred Image", img_blur);
	waitKey(0);
	if (img_blur.empty())
	{
		cout << "Could not blur image";
	}
	else
	{
		imwrite("Blurredimage.jpg", img_blur);
	}

	//Gaussian Blurring
	Mat img_gaussian;
	GaussianBlur(img, img_gaussian, ksize, 1, 1);
	namedWindow("Gaussian blurred Image", WINDOW_NORMAL);
	imshow("Gaussian blurred Image", img_gaussian);
	waitKey(0);
	imwrite("Gaussianblurredimage.jpg", img_gaussian);

	//Median blurring
	Mat img_median;
	medianBlur(img, img_median, 17);
	namedWindow("Median blurred Image", WINDOW_NORMAL);
	imshow("Median blurred Image", img_median);
	waitKey(0);
	imwrite("Medianblurredimage.jpg", img_median);

	//Bilateral Filtering
	Mat img_bilateral;
	bilateralFilter(img, img_bilateral, 3, 60, 60);
	namedWindow("Bilaterally filtered Image", WINDOW_NORMAL);
	imshow("Bilaterally filtered Image", img_bilateral);
	waitKey(0);
	imwrite("Bilateralfiltering.jpg", img_bilateral);

	//Sharpening
	Mat img_sharpened;
	float sharp[3][3] = { {-1,-1,-1},{-1,9,-1},{-1,-1,-1} };
	cv::Mat sharpened(3, 3, CV_32FC1, sharp);
	filter2D(img, img_sharpened, -1, sharpened);
	namedWindow("Sharpened Image", WINDOW_NORMAL);
	imshow("Sharpened Image", img_sharpened);
	waitKey(0);
	imwrite("Sharpened.jpg", img_sharpened);
}