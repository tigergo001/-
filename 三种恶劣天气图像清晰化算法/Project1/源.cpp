#include <iostream> 
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>
#include<string>
#include "histogram.h"
#include"Adjust.h"

using namespace cv;
using namespace std;
int main() {

	const int num = 670;
	char filename[250];
	char windowname[250];
	Adjustment ad;

	vector<int> compression_params;
	compression_params.push_back(CV_IMWRITE_JPEG_QUALITY);  //ѡ��jpeg
	compression_params.push_back(100); //�����������Ҫ��ͼƬ����


	for (int i = 1; i <= 2038; i++) {
		sprintf_s(filename,250, "C:\\Users\\Desktop\\ͼƬ�ز����ݿ�\\����\\����%d.jpg", i);
		// 00001.jpg ��00002.jpg�ȣ�����D:/test/�ļ�����  		
		sprintf_s(windowname, 250,"C:\\Users\\Desktop\\ͼƬ�ز����ݿ�\\����_�Լ����㷨\\%d.jpg", i);  //��ͼƬ��������
		string file = filename;
		string wind = windowname;

		cout << filename << endl;
		cout << windowname << endl;
		//waitKey(0);

		
		Mat image = imread(file);//����ͼƬ 

		//imshow("image",image);

		Mat dst;

		IplImage *Imagel = cvLoadImage(filename, 1);
		dst = ad.de_all(image, Imagel);
		//flip(image,dst,1);	
		//namedWindow(windowname,1);  
		dst.convertTo(dst, CV_8UC3,255,0);
		//imshow(wind,dst);//��ʾͼƬ 		
		imwrite(wind, dst, compression_params);
		cout << wind << "�����" << endl;
		waitKey(100);



	}



