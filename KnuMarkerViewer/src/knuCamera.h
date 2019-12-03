#ifndef KNGCAMERA_H
#define KNGCAMERA_H

#include <opencv2/opencv.hpp>
#include <glm/glm.hpp>

class KCvCamera {
	private:
		cv::VideoCapture mCapture;
		glm::mat4 mCamPose;
	protected:
		bool getCamImage(cv::Mat &img);
		bool getArucoRTVectors(cv::Mat img, cv::Mat &tvec, cv::Mat &rvec);
	public:
		KCvCamera();
		virtual ~KCvCamera();

		bool init(int camNum, bool bThreadMode = false);
		void close();
		bool isOpened() { return mCapture.isOpened(); }
		bool getMarkerPose(int markId, glm::mat4 &camPose, cv::Mat &img, int cols = 320);
};

class KGlCamera {
	private:
	protected:
	public:
		KGlCamera();
		virtual ~KGlCamera();
};

#endif
