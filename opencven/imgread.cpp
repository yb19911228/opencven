#include <string>
#include<opencv2\opencv.hpp>
#include<stdio.h>
#include<windows.h>
using namespace cv;
using namespace std;
int main()
{
	
	//��������
	 namedWindow("image",1);
	 int i=0;
	 for(int i=0;i<50;i++)
	 {
	 char imagename[30];
		sprintf_s(imagename,"d:/opencvbuffer/%d.jpg",i);
		printf("%s",imagename);
		Mat img =imread(imagename);
		if(img.empty())
		{
			return -1;
		}
		//��ʾͼ��
		imshow("image",img);
		waitKey(30);//���ڸ�highgui��ͼʱ�䣬��Ȼ�޷���ʾͼ��
		Sleep(100);
		if(i==49)
			i=0;
	 }
	return 0;
	  
	
}