#include <iostream>
#include <algorithm>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/video/background_segm.hpp"

using namespace std;
using namespace cv;

int lowerb =0, higherb=0;
void onTrackbarLower(int, void*)
{

}
void onTrackbarHigher(int, void*)
{

}

int main()
{
    // Otwarcie filmu
    VideoCapture capture(0);
    // Obecna klatka
    Mat frame;
    Mat back;
    Mat fore;
    BackgroundSubtractorMOG2 bg;
    bg.set("nmixtures",3);
    bg.set("detectShadows",false);
    namedWindow("window");
    int backgroundFrame = 500;
    createTrackbar("lower", "window", &lowerb, 255, onTrackbarLower);
    createTrackbar("higher", "window", &higherb, 255, onTrackbarHigher);

    while(true)
    {
        // Sprawdzenie czy jest koniec filmu

        if(!capture.read(frame)) continue;
        if(backgroundFrame>0)
        {
            bg.operator ()(frame,fore);backgroundFrame--;
        }
        else
        {
            bg.operator()(frame,fore,0);
        }
        bg.getBackgroundImage(back);
        imshow("back", back);
        imshow("fore", fore);

        imshow( "Video", frame );
        // Czekanie na klawisz 33 ms
        char c = waitKey( 33 );
        // Jezeli wcisnieto spacje - koniec
        if( c == 27 ) break;
    }

    waitKey(0);
    return 0;
}


