#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <stdio.h>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	int CAM_ID = 0;
	Mat frame1;

	// 카메라 생성 및 확인 
	VideoCapture cap(CAM_ID); 
	if(!cap.isOpened()){ 
		printf("Can't open the CAM(%d)\n",CAM_ID);
		return -1;
	}

	// 해상도 정보 출력
	double width = cap.get(CV_CAP_PROP_FRAME_WIDTH);
	double height = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
	printf("[%f, %f]\n",width, height);

	// 윈도우 생성 및 사이즈 설정
	namedWindow("OPENCV_CAM", WINDOW_AUTOSIZE);

	while(1){
		// 카메라에서 이미지 얻어오기
		cap >> frame1;
		// 얻은 이미지 표시
		imshow("OPENCV_CAM", frame1);
		// 10ms 키 입력 대기
		if(waitKey(10) >= 0) break;
	}

	// 창닫기
	destroyWindow("OPENCV_CAM");

	return 0;
}
