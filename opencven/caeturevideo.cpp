#include"cv.h"
#include"highgui.h"
#include<Windows.h>
#include<ctype.h>
#include<stdio.h>
#include<iostream>
#include<strstream>
#include<sstream>
#include<string>
using namespace std;
int main(int argc,char** argv)
{
IplImage* frame;
CvCapture* capture=0;
capture=cvCaptureFromCAM(0);
if(!capture)
{
fprintf(stderr,"Could not initialize capturing...\n");
return -1;
}
frame = cvCreateImage(cvSize(320, 240), IPL_DEPTH_16U, 3);
cvNamedWindow("Window 0", 0);

int FrameNumber=0;//����֡�ű���
int p[3];
p[0]=CV_IMWRITE_JPEG_QUALITY;
p[1]=60;//����ֵ��0-100��100��ʾ�������
p[2]=0;
//ѭ����׽,֪���û�����ѭ��
while(capture)
{
	if(FrameNumber==1500)

  FrameNumber=0;//�ﵽ1500֡�����������ü���

frame=cvQueryFrame(capture);
cvShowImage("Window 0",frame);
char filename[26];
sprintf_s(filename,"z:/opencvbuffer/%d.jpg",FrameNumber);
cvSaveImage(filename,frame,p);//��jpeg��ʽ�洢֡,pΪ־��ֵ
printf("%s\n",filename);
Sleep(20);
FrameNumber++;
if(cvWaitKey(1)==27)
break;
}
cvReleaseCapture(&capture);
cvDestroyWindow("Window 0");
return 0;
}
