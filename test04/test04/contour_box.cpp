#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/opencv.hpp"
#include<iostream>
#include<vector>
using namespace std;


int main()
{

	//int c[3][4] = {
	//{0, 1, 2, 3} ,   /*  初始化索引号为 0 的行 */
	//{4, 5, 6, 7} ,   /*  初始化索引号为 1 的行 */
	//{8, 9, 10, 11}   /*  初始化索引号为 2 的行 */
	//};
	//cout << c[0][0] << endl; //取出第1行第2列的值
	//cout << c[1] << endl;//取出第1行第一个元素的指针

	cv::Mat img = cv::imread("D:/Dep_gram/c++_project/test04/test04/16.jpg");
	cv::Mat gray_img, bin_img;
	cv::cvtColor(img, gray_img, cv::COLOR_BGR2GRAY);
	cv::threshold(gray_img, bin_img, 127, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);

	vector<vector<cv::Point>>contours;
	vector<cv::Vec4i>vec_4f;
	cv::findContours(bin_img, contours, vec_4f, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
	cout << "contours:" << int(size(contours)) << endl;

	{
		//外接矩形
		for (int i = 0; i < (int(size(contours))); i++)
		{
			cv::Rect rect = cv::boundingRect(contours.at(i));
			cv::rectangle(img, cv::Point(rect.x, rect.y), cv::Point(rect.x + rect.width, rect.y + rect.height),
				cv::Scalar(0, 0, 255), 2);
			cv::imshow("img"+i, img);
		}
		
	
	}
	
	{
		//最小外接矩形
		for (int i = 0; i < (int(size(contours))); i++)
		{
			//cv::minAreaRect 返回4个点的坐标
			cv::RotatedRect minRect = cv::minAreaRect(contours.at(i));
			//cout << "minrect:" << minRect[0] << endl;
			cv::Point2f vs[4];
			minRect.points(vs);
			//cout << "vs:" << *vs << endl;
			vector<cv::Point>contour;
			contour.push_back(vs[0]);
			contour.push_back(vs[1]);
			contour.push_back(vs[2]);
			contour.push_back(vs[3]);
			cv::polylines(img, contour, true, cv::Scalar(0, 0, 255), 3);
			cout << "contour:" << contour << endl;
			cv::imshow("img" + i, img);

		}
		
	}

	{
		//最小外接圆
		for (int i = 0; i < (int(size(contours))); i++)
		{
			cv::Point2f center;
			float radius;
			cv::minEnclosingCircle(contours[i],center,radius);
			cv::circle(img,center,radius,cv::Scalar(0,0,255),3);
			cv::imshow("img" + i, img);
		}
	}
	
	//cv::imshow("img",img);
	cv::waitKey(0);
	cv::destroyAllWindows();

	return 0;
}

