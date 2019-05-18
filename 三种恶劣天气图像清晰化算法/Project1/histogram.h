#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <opencv2\opencv.hpp>

#include <iostream>
#include <string>

class Histogram
{
public:
	int histSize[3];        //ֱ��ͼ�����ӵ�����
	float hranges[2];       //ֵ��Χ
	const float * ranges[3];        //ֵ��Χ��ָ��
	int channels[3];        //Ҫ����ͨ������


	Histogram();
	cv::Mat getHistogram(const cv::Mat & image);
	std::vector<cv::Mat> getHistogramImage(const cv::Mat & image, int zoom = 1);
	static std::vector<cv::Mat> getImageOfHistogram(const cv::Mat & hist, int zoom);
};

#endif
