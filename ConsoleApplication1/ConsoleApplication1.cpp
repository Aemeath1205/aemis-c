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
