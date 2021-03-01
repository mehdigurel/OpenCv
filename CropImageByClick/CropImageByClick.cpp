
#include<opencv2\opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;
bool flag = false;
Mat image;
void mousecallback(int event, int x, int y, int flags, void* userdata);
int main(int argc, char* argv[])
{
	namedWindow("imageshow", 0);
	image = imread("C:\\mehdi.jpg");
	if (!image.data)
	{
		cout << "the image is error" << endl;
		return 0;
	}
	imshow("imageshow", image);

	cv::setMouseCallback("imageshow", mousecallback, 0);
	waitKey(0);
}


void mousecallback(int event, int x, int y, int flags, void* userdata)
{

	switch (event)
	{
	case EVENT_LBUTTONDOWN:
	{
		flag = true;
	}
	break;
	case EVENT_LBUTTONUP:
	{
		if (flag)
		{
			cout << "x :" << x << "\n" << "y :" << y << "\n" << "*******\n";


			int sizeX = 100;
			int sizeY = 100;

			x = x - sizeX / 2;
			y = y - sizeY / 2;

			if (x <= 0)
				x = 0;
			if (y <= 0)
				y = 0;


			if (x + sizeX >= image.cols)
				x = (x - sizeX / 2);

			if (y + sizeY >= image.rows)
				y = (y - sizeY / 2);


			Rect roi(x, y, sizeX, sizeY);
			image = image(roi).clone();
			imwrite("C:\\Users\\LENOVO\\Desktop\\resim.jpg", image);
			imshow("mehdi", image);
			image.release();
			image = imread("C:\\mehdi.jpg");

			//cropedImage = image(Rect(xvalue, yvalue, 100, 100));
		}
	}
	break;
	}

}
