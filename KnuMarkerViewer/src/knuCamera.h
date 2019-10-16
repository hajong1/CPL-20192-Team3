#ifndef KNGCAMERA_H
#define KNGCAMERA_H

#include <opencv2/opencv.hpp>
#include <glm/glm.hpp>

class KCvCamera {
	private:
		cv::VideoCapture mCapture;
		glm::mat4 mCamPose;
	protected:
	public:
		KCvCamera();
		virtual ~KCvCamera();

		bool init(int camNum);
		void close();
		bool isOpened() { return mCapture.isOpened(); }
		bool getMarkerPose(int markId, glm::mat4 &camPose);
};

class KGlCamera {
	private:
	protected:
	public:
		KGlCamera();
		virtual ~KGlCamera();
};

#endif
