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
	Mat img_edge;
	Canny(img, img_edge, 50, 100);
	namedWindow("Edge Detetcted Image", WINDOW_NORMAL);
	imshow("Edge Detected Image", img_edge);
	waitKey(0);
	if (img_edge.empty())
	{
		cout << "could not detect edges";
	}
	else
	{
		imwrite("Edges.jpg", img_edge);
	}
}

