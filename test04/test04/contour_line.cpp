#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/opencv.hpp"
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	cv::Mat img = cv::imread("D:/Dep_gram/c++_project/test04/test04/16.jpg");
	cv::Mat gray_img, bin_img;
	cv::cvtColor(img, gray_img, cv::COLOR_BGR2GRAY);
	cv::threshold(gray_img, bin_img, 127, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);

	vector<vector<cv::Point>>contours;
	vector<cv::Vec4i>vec_4f;
	cv::findContours(bin_img, contours, vec_4f, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

	cout << "contours[0]:" << contours[0] << "contours[1]:" << contours[1] << endl;
	//椭圆拟合
	for (int i = 0; i<(int(size(contours))); i++)
	{
		cv::RotatedRect ellipse = cv::fitEllipse(contours.at(0));
		//cv::RotatedRect ellipse = cv::fitEllipse(contours[0]);
		cv::ellipse(img, ellipse, cv::Scalar(0, 0, 255), 3);
		cv::imshow("img"+i,img);
	}

	//直线拟合
	for (int i = 0; i < (int(size(contours))); i++)
	{
		float w = img.size[0], h = img.size[1];
		//cv::Vec4f二维直线类型，cv::Vec6f三维直线类型，line[0]、line[1]直线方向，后两个直线上一点
		cv::Vec4f line;

		/*
		void cv::fitLine(
		cv::InputArray points, // 二维点的数组或vector
		cv::OutputArray line, // 输出直线,Vec4f (2d)或Vec6f (3d)的vector
		int distType, // 距离类型
		double param, // 距离参数
		double reps, // 径向的精度参数
		double aeps // 角度精度参数
		);
		*/
		cv::fitLine(contours.at(i),line,cv::DIST_L2,0,0.01,0.01);
		float vx = line[0], vy = line[1], x = line[2], y = line[3];
		float left_y = (-x * vy / vx) + y;
		float right_y = ((w-x) * vy / vx) + y;
		cv::line(img, cv::Point2f(w - 1, right_y), cv::Point2f(0, left_y), cv::Scalar(0, 0, 255), 2);
		cv::imshow("img" + i, img);
	}

	
	cv::waitKey(0);
	cv::destroyAllWindows();

	return 0;
}