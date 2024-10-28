#include <opencv2/opencv.hpp> 
#include "streamer.h"
using cv::Mat;

int main(int argc, char **argv){
  cv::VideoCapture cap(0);

     double width = 1280;
     double height = 960;
     double fps = 30;
     if( !width || !height || !fps ){
         std::cerr<<"camera launch failed"<<std::endl;
         exit(0);
     }

     Streamer streamer;
     if(!streamer.streamer_init(width, height, fps)){
         std::cerr<<"streamer init failed"<<std::endl;
         exit(0);
     }
  while(cap.isOpend()){
    Mat frame;
    cap>>frame;
    streamer.matToRTSP(frame);

  }
    return 0;
}
