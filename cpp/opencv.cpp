/*
 * @Copyright: https://github.com/yangjam-cn/algorithm
 * @File name: 文件名
 * @Description: 
 * @Author: yangjam
 * @Version: 1.0
 * @Date: 2020-08-23 15:22:55
 * @History: 修改历史列表，每条修改记录应包括修改日期、修改者及修改内容简述
 * @LastEditTime: 2020-08-23 15:41:06
 */
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(void)
{
    Mat grayim(600, 800, CV_8UC1);
    Mat colorim(600, 800, CV_8UC3);

    for (int i = 0; i < grayim.rows; ++i)
        for (int j = 0; j < grayim.cols; ++j)
            grayim.at<uchar>(i, j) = (i + j) % 255;
    
    for (int i = 0; i < colorim.rows; ++i) 
        for (int j = 0; j < colorim.cols; ++j)
        {
            Vec3b pixel;
            pixel[0] = i % 255;
            pixel[1] = j % 255;
            pixel[2] = 0;
            colorim.at<Vec3b>(i, j) = pixel;
        }

    imshow("grayim", grayim);
    imshow("colorim", colorim);
    waitKey(0);
        
    return 0;
}