//#include <opencv2/opencv.hpp>
//using namespace cv;
//
//int main() {
//    Mat img = imread("C:/C++_text/aemis/ConsoleApplication1/test.jpg.png");
//    imshow("原图", img);
//    waitKey(0); 
//    return 0;
//}
//#include <opencv2/opencv.hpp>
//using namespace cv;
//using namespace std;
//
//int main() {
//    // 1. 读取彩色图像（替换为你本地图片路径）
//    Mat src = imread("C:/C++_text/aemis/ConsoleApplication1/test.jpg.png");
//    if (src.empty()) {
//        cout << "错误：无法读取图像文件，请检查路径是否正确！" << endl;
//        return -1;
//    }
//
//    // 2. 显示原始彩色图像
//    imshow("原始彩色图像", src);
//
//    // 3. 将彩色图像转换为灰度图
//    Mat gray_image;
//    cvtColor(src, gray_image, COLOR_BGR2GRAY);
//    imshow("转换后灰度图像", gray_image);
//
//    // 4. 调整图像大小（示例：将宽度缩至640像素，高度按比例自动计算）
//    Mat resized_image;
//    int new_width = 640;
//    int new_height = (new_width * src.rows) / src.cols;
//    resize(gray_image, resized_image, Size(new_width, new_height));
//    imshow("调整尺寸后的灰度图像", resized_image);
//
//    // 5. 保存处理后的图像
//    imwrite("gray_resized_output.jpg", resized_image);
//    cout << "处理完成，结果已保存为 gray_resized_output.jpg" << endl;
//
//    waitKey(0); // 等待用户按下任意键关闭窗口
//    destroyAllWindows();
//    return 0;
//}
//#include <opencv2/opencv.hpp>
//using namespace cv;
//using namespace std;
//
//int main() {
//    // 1. 读取彩色图像
//    Mat src = imread("C:/C++_text/aemis/ConsoleApplication1/test.jpg.png");
//    if (src.empty()) {
//        cout << "错误：无法读取图像文件，请检查路径是否正确！" << endl;
//        return -1;
//    }
//
//    // 2. 显示原始图像
//    imshow("原始彩色图像", src);
//
//    // 3. 提取图像轮廓：先转灰度→高斯模糊去噪→Canny边缘检测
//    Mat gray, blurred, edges;
//    cvtColor(src, gray, COLOR_BGR2GRAY);
//    GaussianBlur(gray, blurred, Size(5, 5), 0); // 5×5高斯核降噪，减少误检
//    Canny(blurred, edges, 50, 150);            // 双阈值50/150提取边缘
//    imshow("提取的图像轮廓", edges);
//
//    // 4. 顺时针旋转图像90度
//    Mat rotated;
//    rotate(src, rotated, ROTATE_90_CLOCKWISE); // OpenCV内置顺时针90度旋转
//    imshow("旋转90度后的图像", rotated);
//
//    // 5. 保存处理结果
//    imwrite("contour_result.jpg", edges);
//    imwrite("rotated_result.jpg", rotated);
//    cout << "处理完成，轮廓结果保存为 contour_result.jpg，旋转结果保存为 rotated_result.jpg" << endl;
//
//    waitKey(0);
//    destroyAllWindows();
//    return 0;
//}
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

// 全局变量定义（按照实验要求）
cv::Mat src, grayImg, resultImg;
int threshold1Value = 50;
int threshold2Value = 150;
int minAreaValue = 100;
const std::string WINDOW_NAME = "你的学号+你的姓名";

// 回调函数声明
void updateImage(int, void*);

int main()
{
    // 1. 读取图像
    src = cv::imread("C:/C++_text/aemis/ConsoleApplication1/test.png");

    if (src.empty())
    {
        std::cout << "图像读取失败，请检查 test.jpg 是否在程序工作目录中。" << std::endl;
        return -1;
    }

    // 2. 转换为灰度图
    cv::cvtColor(src, grayImg, cv::COLOR_BGR2GRAY);

    // 3. 创建窗口
    cv::namedWindow(WINDOW_NAME, cv::WINDOW_AUTOSIZE);

    // 4. 创建滑动条
    cv::createTrackbar(
        "Threshold1",
        WINDOW_NAME,
        &threshold1Value,
        255,
        updateImage
    );

    cv::createTrackbar(
        "Threshold2",
        WINDOW_NAME,
        &threshold2Value,
        255,
        updateImage
    );

    cv::createTrackbar(
        "MinArea",
        WINDOW_NAME,
        &minAreaValue,
        5000,
        updateImage
    );

    // 初始处理一次
    updateImage(0, 0);

    while (true)
    {
        char key = (char)cv::waitKey(30);

        if (key == 's')
        {
            if (!resultImg.empty())
            {
                cv::imwrite("contour_result.jpg", resultImg);
                std::cout << "轮廓提取结果已保存为 contour_result.jpg" << std::endl;
            }
        }
        else if (key == 'q' || key == 27)
        {
            break;
        }
    }

    cv::destroyAllWindows();
    return 0;
}

// 回调函数实现（按照实验要求）
void updateImage(int, void*)
{
    cv::Mat blurImg, edgeImg;
    // a. 高斯平滑滤波
    cv::GaussianBlur(grayImg, blurImg, cv::Size(5, 5), 0);
    // b. Canny边缘检测
    cv::Canny(blurImg, edgeImg, threshold1Value, threshold2Value);
    // c. 查找轮廓
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::findContours(
        edgeImg.clone(),
        contours,
        hierarchy,
        cv::RETR_EXTERNAL,
        cv::CHAIN_APPROX_SIMPLE
    );
    // d. 绘制过滤后的轮廓
    resultImg = src.clone();
    for (size_t i = 0; i < contours.size(); i++)
    {
        double area = cv::contourArea(contours[i]);
        // 过滤小面积噪声轮廓
        if (area < minAreaValue)
        {
            continue;
        }
        cv::drawContours(
            resultImg,
            contours,
            (int)i,
            cv::Scalar(0, 0, 255),
            2
        );
    }
    // e. 显示结果
    cv::imshow(WINDOW_NAME, resultImg);
}