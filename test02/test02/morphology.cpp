#include"opencv2/highgui/highgui.hpp"
#include"opencv2/imgproc/imgproc.hpp"
#include"opencv2/opencv.hpp"
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	cv::Mat img = cv::imread("C:/Users/Administrator/Desktop/1.jpg");

	cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
	cout << kernel << endl;
	cv::Mat dst1,dst2,dst3;

	//cv::dilate(img, dst1, kernel);
	//cv::erode(img, dst2, kernel);
	//cv::morphologyEx(img, dst1, cv::MORPH_OPEN, kernel); //¿ª
	//cv::morphologyEx(img, dst2, cv::MORPH_CLOSE, kernel); //±Õ
	cv::morphologyEx(img, dst1, cv::MORPH_GRADIENT, kernel); //ÌÝ¶È
	cv::morphologyEx(img, dst2, cv::MORPH_TOPHAT, kernel); //¶¥Ã±
	cv::morphologyEx(img, dst3, cv::MORPH_BLACKHAT, kernel); //ºÚÃ±

	cv::namedWindow("img", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("dst1", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("dst2", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("dst3", cv::WINDOW_AUTOSIZE);
	cv::imshow("img",img);
	cv::imshow("dst1", dst1);
	cv::imshow("dst2", dst2);
	cv::imshow("dst3", dst3);
	cv::waitKey(0);
	cv::destroyAllWindows();
	
	//system("pause");
	return 0;
}