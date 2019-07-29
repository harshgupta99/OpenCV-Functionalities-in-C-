#include <iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat img;
	Mat img_masked;
	img = imread("cat.jpg");
	float k[17][17];
	for (int i = 0; i < 17; i++)
	{
		for (int j = 0; j < 17; j++)
		{
			k[i][j] = 0.00346020761; //(1 / 289 = 0.00346020761)
		}
	}
	cv::Mat kernel(17, 17, CV_32FC1, k);
	filter2D(img, img_masked, -1, kernel);
	namedWindow("Masked Image", WINDOW_NORMAL);
	imshow("Masked Image", img_masked);
	waitKey(0);
	if (img_masked.empty())
	{
		cout << "Could not mask image";
	}
	else
	{
		imwrite("maskedimage.jpg", img_masked);
	}
}
