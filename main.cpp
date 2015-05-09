#include <iostream>
#include <algorithm>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/video/background_segm.hpp"
#include "opencv2/video/video.hpp"

using namespace std;
using namespace cv;

int lowerb =0, higherb=0;
int backgroundFrame = 500;
int splitIndx = 0;
//Ptr<BackgroundSubtractor> bg;
void onTrackbarLower(int, void*)
{

}
void onTrackbarHigher(int, void*)
{

}

int main()
{
//    mog = createBac
    // Otwarcie filmu
    VideoCapture capture(0);
    // Obecna klatka
    Mat frame;
    Mat back;
    Mat fore;
    BackgroundSubtractorMOG2 bg;
//    bg = new BackgroundSubtractorMOG2();
    bg.set("nmixtures",3);
    bg.set("detectShadows",false);
    namedWindow("window");
    while(!capture.read(frame));


//    createTrackbar("lower", "window", &splitIndx, 2, onTrackbarLower);
//    createTrackbar("higher", "window", &higherb, 255, onTrackbarHigher);

    while(true)
    {
        if(!capture.read(frame)) continue;
        vector<Mat> frame_split;
        split(frame,frame_split);

        Mat channel = frame;

//        if(backgroundFrame>0)
        {bg.operator ()(frame,fore,10);backgroundFrame--;}
//        else
//        {bg.operator()(frame,fore,0);}

        //Get background image to display it
        bg.getBackgroundImage(back);
//        medianBlur(fore,fore,5);
        Mat kelner = getStructuringElement(CV_SHAPE_ELLIPSE,Size(3,3));
        erode(fore,fore,kelner);


//        dilate(fore,fore,kelner);

        imshow("back", back);
        imshow("fore", fore);
//        imshow( "Video", frame );
        // Czekanie na klawisz 33 ms
        char c = waitKey( 33 );
        // Jezeli wcisnieto spacje - koniec
        if( c == 27 ) break;
    }

    waitKey(0);
    return 0;
}


