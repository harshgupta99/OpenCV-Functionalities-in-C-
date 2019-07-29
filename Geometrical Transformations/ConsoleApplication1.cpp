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
	Mat img_scaled;
	Size dsize;
	dsize = size(img);
	// Scaling an image
	resize(img, img_scaled,dsize,300, 300, INTER_LINEAR);
	namedWindow("image", WINDOW_NORMAL);
	imshow("image", img);
	waitKey(0);
	namedWindow("Scaled image", WINDOW_NORMAL);
	imshow("scaled image", img_scaled);
	if (img_scaled.empty())
	{
		cout << "Could not scale image \n";
	}
	else
	{
		imwrite("scaledimage.jpg", img_scaled);
	}
	waitKey(0);

	//Translation of an image
	int x = 100;
	Mat img_translated;
	int y = 150;
	double a[2][3] = {{1,0,x},{0,1,y}}; 
	cv::Mat M(2, 3, CV_64F, a);
	warpAffine(img, img_translated, M, dsize,INTER_LINEAR,BORDER_CONSTANT,Scalar());
	namedWindow("Translated Image", WINDOW_NORMAL);
	imshow("Translated Image", img_translated);
	imwrite("Translatedimage.jpg", img_translated);
	waitKey(0);

	//Rotation of an image
	Mat img_rotated;
	int alpha = 90;
	int scaling_factor = 1;
	Point2f center = Point(img.cols / 2, img.rows / 2);
	Mat rot = getRotationMatrix2D(center, alpha, scaling_factor);
	warpAffine(img, img_rotated, rot, dsize, INTER_LINEAR, BORDER_CONSTANT, Scalar());
	namedWindow("Rotated Image", WINDOW_NORMAL);
	imshow("Rotated Image", img_rotated);
	imwrite("Rotatedimage.jpg", img_rotated);
	waitKey(0);

	//Perspective Transformation
	Mat img_pers;
	float b[4][2] = {{56,65},{368,52},{28,287},{389,390}};
	//double b[4][2] = { 56, 65, 368, 52, 28, 287, 389, 390 };
	cv::Mat M2(4, 2, CV_32F, b);
	//double c[4][1] = { 0,0,300,0,0,300,300,300 };
	float c[4][2] = { {0,0},{300,0},{0,300},{300,300} };
	cv::Mat M3(4, 2, CV_32F, c);
	Mat pers = getPerspectiveTransform(M2, M3);
	warpPerspective(img, img_pers, pers, dsize,INTER_LINEAR, BORDER_CONSTANT, Scalar());
	namedWindow("Perspectively transformed image", WINDOW_NORMAL);
	imshow("Perspectively transformed Image", img_pers);
	imwrite("PerspectivellytransformedImage.jpg", img_pers);
	waitKey(0);
	return 0;
}
