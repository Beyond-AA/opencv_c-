// test01.cpp: 定义应用程序的入口点。
//

#include "test01.h"

using namespace std;


int main()
{

	//cv::Mat img = cv::imread("C:/Users/Administrator/Desktop/Beyond.jpg");
	//cv::imshow("img", img);
	//cv::waitKey();
	//cv::destroyAllWindows();
	//cv::namedWindow();
	cv::Mat img = gen_img();
	//cv::imshow("img", img);
	//cv::waitKey();
	//cv::destroyAllWindows();
	cv::imwrite("C:/Users/Administrator/Desktop/gen_img.jpg",img);
	return 0;
}

cv::Mat gen_img() {
	cv::Mat img = cv::Mat(200, 300, CV_8UC3);
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			img.at<cv::Vec3b>(i, j)[0] = 255;
			img.at<cv::Vec3b>(i, j)[1] = 0;
			img.at<cv::Vec3b>(i, j)[2] = 0;
		}
	}

	//cv::Mat img = cv::Mat(200, 300, CV_8UC3, cv::Scalar(0, 0, 0));
	//for (int i = 0; i < img.rows; i++)
	//{
	//	for (int j = 0; j < img.cols; j++)
	//	{
	//		img.at<cv::Vec3b>(i, j)[0] = 255;
	//		img.at<cv::Vec3b>(i, j)[1] = 0;
	//		img.at<cv::Vec3b>(i, j)[2] = 0;
	//	}
	//}
	return img;
}







