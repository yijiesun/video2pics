#include <fstream>
#include <conio.h>
#include <iostream>
#include <sstream>
#include <string>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	//����Ƶ�ļ�
	VideoCapture capture("E:\\SIMIT\\2020_new_project\\zsxl\\dataset\\1\\1.mp4");
	std::string saveAddress = "E:\\SIMIT\\2020_new_project\\zsxl\\dataset\\1\\1\\";
	//isOpen�ж���Ƶ�Ƿ�򿪳ɹ�
	if (!capture.isOpened())
	{
		cout << "Movie open Error" << endl;
		return -1;
	}
	int position = 0;
	//���ò��ŵ���һ֡����������Ϊ��0֡
	capture.set(CV_CAP_PROP_POS_FRAMES, position);
	int frameCnt = capture.get(CV_CAP_PROP_FRAME_COUNT);
	Mat src;
	int cnt = 0;
	while (true)
	{
		if (cnt >= frameCnt)
			break;
		cout << cnt << "/" << frameCnt << endl;
		std::stringstream ss;
		ss << cnt++;
		std::string s = ss.str();
		
		std::string imgName = saveAddress;
		imgName += s;
		imgName += ".bmp";

		capture >> src;
		imwrite(imgName.c_str(), src);
		waitKey(30);
	}
	capture.release();
	return 0;
}
