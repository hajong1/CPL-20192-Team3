#include "knuCamera.h"

KCvCamera::KCvCamera() {
}

KCvCamera::~KCvCamera() {
}

void KCvCamera::close() {
}

bool KCvCamera::init(int camNum, bool bThreadMode) {
	return false;
}

bool KCvCamera::getCamImage(cv::Mat &img) {
	return false;
}

bool KCvCamera::getArucoRTVectors(cv::Mat img, cv::Mat &tvec, cv::Mat &rvec) {
	if(img.empty()) return false;

	return false;
}

bool KCvCamera::getMarkerPose(int markId, glm::mat4 &camPose, cv::Mat &img, int cols) {
	cv::Mat imgOri;
	cv::Mat matRvec, matTvec, matR;

	if(!getCamImage(imgOri) || imgOri.empty()) return false;
	if(!getArucoRTVectors(imgOri, matTvec, matRvec)) return false;

	cv::Rodrigues(matRvec, matR);
	cv::Mat T = cv::Mat::eye(4, 4, matR.type()); // T is 4x4 unit matrix.
	for(unsigned int row=0; row<3; ++row) {
		for(unsigned int col=0; col<3; ++col) {
			T.at<double>(row, col) = matR.at<double>(row, col);
		}
		T.at<double>(row, 3) = matTvec.at<double>(row, 0);
	}
	//std::cout << "T" << std::endl << T << std::endl;

	//Convert CV to GL
	cv::Mat cvToGl = cv::Mat::zeros(4, 4, CV_64F);
	cvToGl.at<double>(0, 0) =  1.0f;
	cvToGl.at<double>(1, 1) = -1.0f; // Invert the y axis
	cvToGl.at<double>(2, 2) = -1.0f; // invert the z axis
	cvToGl.at<double>(3, 3) =  1.0f;
	T = cvToGl * T;

	//Convert to cv::Mat to glm::mat4.
	for(int i=0; i < T.cols; i++) {
		for(int j=0; j < T.rows; j++) {
			camPose[j][i] = *T.ptr<double>(i, j);
		}
	}

	return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

KGlCamera::KGlCamera() {
}

KGlCamera::~KGlCamera() {
}

