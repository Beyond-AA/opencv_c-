#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/opencv.hpp"
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	
	cv::Mat img = cv::imread("D:/Dep_gram/c++_project/test04/test04/5.jpg");
	cv::Mat gray_img, bin_img;
	cv::cvtColor(img,gray_img,cv::COLOR_BGR2GRAY);
	cv::threshold(gray_img, bin_img, 127, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);

	vector<vector<cv::Point>>contours;
	vector<cv::Vec4i>vec_4f;
	cv::findContours(bin_img,contours,vec_4f,cv::RETR_TREE,cv::CHAIN_APPROX_SIMPLE);


	vector<vector<cv::Point>>hull(contours.size());
	cout << "contours.size:"<< int(size(contours));
	for (int i = 0; i<(int(size(contours))); i++)
	{
		cv::convexHull(contours.at(i), hull.at(i));
		cout << cv::isContourConvex(contours.at(i)) << "" << cv::isContourConvex(contours.at(i)) << endl;
		cv::drawContours(img, hull, i, cv::Scalar(0, 0, 255), 3);
		cv::imshow("img"+i, img);
	}
	//cv::convexHull(contours.at(0),hull.at(0));
	//cout << cv::isContourConvex(contours.at(0)) << "" << cv::isContourConvex(contours.at(0)) << endl;

	//cv::drawContours(img, contours, -1, cv::Scalar(0, 0, 255), 3);

	//cv::imshow("img",img);
	cv::waitKey(0);
	//cv::destroyAllWindows();
	
	return 0;
}