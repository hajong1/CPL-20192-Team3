#ifndef KNGCAMERA_H
#define KNGCAMERA_H

#include <opencv2/opencv.hpp>
#include <glm/glm.hpp>

class KCvCamera {
	private:
		glm::mat4 mCamPose;
	protected:
	public:
		KCvCamera();
		virtual ~KCvCamera();
};

class KGlCamera {
	private:
	protected:
	public:
		KGlCamera();
		virtual ~KGlCamera();
};

#endif
