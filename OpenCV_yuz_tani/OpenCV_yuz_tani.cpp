#include <opencv2/opencv.hpp>         // OpenCV'nin temel özellikleri için
#include <opencv2/highgui.hpp>       // Görüntü ve video gösterimi için
#include <opencv2/imgproc.hpp>       // Görüntü işleme işlemleri için
#include <opencv2/core.hpp>          // Temel veri yapıları ve işlevler için
#include <opencv2/objdetect.hpp>     // Nesne algılama, yüz tanıma için (Haar Cascade ve benzeri
using namespace cv;
using namespace std;
//haarcascade_frontalface_default.xml
int main() {
	CascadeClassifier yuz;
	vector<Rect> yuz_tanima;
	yuz.load("haarcascade_frontalface_default.xml");
	Mat resim = imread("messi.jpg");
	Mat gri;
	cvtColor(resim, gri, COLOR_BGR2GRAY);
	yuz.detectMultiScale(gri, yuz_tanima);
	for (int i = 0; i < yuz_tanima.size();i++) {
		rectangle(resim, yuz_tanima[i], Scalar(0, 0, 255), 3);
	}
	imshow("pencere1", resim);
	waitKey(0);
}