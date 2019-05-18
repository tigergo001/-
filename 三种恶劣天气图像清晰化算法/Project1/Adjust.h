#include <opencv2\opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;

class Adjustment
{
public:
	int histSize[3];        //ֱ��ͼ�����ӵ�����
	float hranges[2];       //ֵ��Χ
	const float * ranges[3];        //ֵ��Χ��ָ��
	int channels[3];        //Ҫ����ͨ������

	/*ȥɳ�Ǳ��л�ʹ�õ�����*/
	cv::Mat hist_b, hist_g, hist_r;    // ԭʼͼ�����ͨ������
	//�õ��ܵ����ص���������������
	int num, r, c;
	cv::Mat finalImg;       //�õ�������ͼ�����
	double x[3];
	double y[3];             //��ͨ���ľ�ֵ�ͱ�׼��Ĺ���ֵ
	cv::Mat aimg;           //��һ�׶κ�ͼ�����



	//���캯��
	Adjustment();


			/*�ϳ�һ���㷨*/
	Mat de_all(cv::Mat  image, IplImage *Image1);


			/*ȥɳ�Ǳ��ܷ���*/
	Mat de_sand(cv::Mat  image, IplImage *Image1,int flag);
	//ͨ��ֱ��ͼ������ͨ����Ӧ����ֵ
	Mat getvalue2(const cv::Mat  image , IplImage *Image1);
	//ȥɳ����������ȡ��һ�׶�ͼ�����
	void getaImg(IplImage *Image1, std::vector<cv::Mat> rgbChannels);
	//ȥɳ����������ȡ����ͼ�����
	void getfinalImg();
	//ȥɳ��������SVDͼ����ǿ
	Mat SVD_de_sand(Mat rec, Mat sec_hist);


			/*ȥ����*/
	Mat defog(Mat image,int flag );//��ͨ������

	Mat defog_2(Mat image);//�Ҷ����췽��
	Mat grayStretch(cv::Mat src, double lowcut, double highcut);

	Mat defog_3(Mat image,int flag);//����˲�����
	Mat Adaptive_contrast(Mat img);

	Mat defog_4(Mat image, int flag);


			/*��������ǿ*/
	//��������ǿ(ȥ������
	Mat ad_light(Mat image) ;
	//��������ǿ������Log������
	Mat ad_light_Log(Mat image);
	//��������
	Mat drop_light(Mat image);

};
