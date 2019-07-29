#include <iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat img = imread("3.jpg");
	namedWindow("Original Image", WINDOW_NORMAL);
	imshow("Original Image", img);
	waitKey(0);

	//Erosion
	Mat img_erode;
	float k[5][5];
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			k[i][j] = 1;
		}
	}
	cv::Mat kernel(5, 5, CV_32FC1, k);
	erode(img, img_erode, kernel, { -1,-1 }, 5);
	namedWindow("Eroded Image", WINDOW_NORMAL);
	imshow("Eroded Image",img_erode);
	waitKey(0);
	if (img_erode.empty())
	{
		cout << "Could not erode image";
	}
	else
	{
		imwrite("Erodedimage.jpg", img_erode);
	}

	//Dilation
	Mat img_dilate;
	//We can use the same kernel as that used for erosion
	dilate(img, img_dilate, kernel, { -1,-1 }, 5);
	namedWindow("Dilated Image", WINDOW_NORMAL);
	imshow("Dilated Image", img_dilate);
	waitKey(0);
	imwrite("dilatedimage.jpg", img_dilate);

	//Opening
	Mat img_open;
	//We can use the same kernel as previously used
	morphologyEx(img, img_open, MORPH_OPEN, kernel, { -1,-1 }, 5);
	namedWindow("Opened Image", WINDOW_NORMAL);
	imshow("Opened Image", img_open);
	waitKey(0);
	imwrite("Openedimage.jpg", img_open);

	//Closing
	Mat img_close;
	//We can use the same kernel
	morphologyEx(img, img_close, MORPH_CLOSE, kernel, { -1,-1 }, 5);
	namedWindow("Closed Image", WINDOW_NORMAL);
	imshow("Closed Image", img_close);
	waitKey(0);
	imwrite("Closedemage.jpg", img_close);

	//Morphological Gradient
	Mat img_gradient;
	//We can use the same kernel
	morphologyEx(img, img_gradient, MORPH_GRADIENT, kernel, { -1,-1 }, 5);
	namedWindow("Morphological Gradient on an Image", WINDOW_NORMAL);
	imshow("Morphological Gradient on an  Image", img_gradient);
	waitKey(0);
	imwrite("Morphologicalimage.jpg", img_gradient);

	//Top-Hat
	Mat img_tophat;
	//We can use the same kernel
	morphologyEx(img, img_tophat, MORPH_TOPHAT, kernel, { -1,-1 }, 10);
	namedWindow("Top Hat Image", WINDOW_NORMAL);
	imshow("Top Hat Image", img_tophat);
	waitKey(0);
	imwrite("Tophatimage.jpg", img_tophat);

	//Black-Hat
	Mat img_blackhat;
	//We can use the same kernel
	morphologyEx(img, img_blackhat, MORPH_BLACKHAT, kernel, { -1,-1 }, 10);
	namedWindow("Black Hat Image", WINDOW_NORMAL);
	imshow("Black Hat Image", img_blackhat);
	waitKey(0);
	imwrite("Blackhat.jpg", img_blackhat);
}