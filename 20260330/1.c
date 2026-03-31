#define _CRT_SECURE_NO_WARNINGS
//1. 概念与改错题
//请回答下列问题。（1）简述“结构体类型”和“结构体变量”的区别。（2）下面哪些写法正确，哪些错误？错误的请改正。（3）说明.和->的区别，并举一个最简单的例子。
//struct Student { int num; char name[20]; };
//struct Student;
//Student s1;
//struct Student s2;
//scanf("%d", &s2);
//printf("%d", s2);
//printf("%d", s2.num);
//
//2. 编写程序：输入 10 个整数，使用指针遍历数组，求出这 10 个数的最大值、最小值、平均值
//要求：1.定义一个函数 void analyze(int* p, int n, int* max, int* min, double* avg); 形参p指向数组首元素，n表示数组长度或元素个数，max回传最大值，min回传最小值，avg回传平均值，在函数中通过指针完成数组访问；2.主函数输出结果。
//
//3. 编写程序：输入一行字符串，再输入一个字符，编写函数统计该字符在字符串中出现的次数。
//要求：1.函数原型可设为int count_char(char* p, char ch); 2.例如输入 "banana" 和 'a'，输出 3
//
//4. 定义结构体 Student，包含：学号 num、姓名 name、三门课成绩 score[3]、平均分 avg，编写程序完成1.输入1名学生的信息；2.计算平均分；3.输出该学生的完整信息
//要求：可以用结构体变量作函数参数，也可以用结构体指针作函数参数
//
//5. 定义结构体 Student，包含：学号、姓名、成绩，输入 5 名学生的信息，按成绩从高到低排序后输出。
//要求：1.使用结构体数组完成；2.排序时交换整个结构体变量，而不是只交换某一个成员；3.输出格式示例：排名、学号、姓名、成绩

//truct Student{ int num; char name[20]; };  // 正确，定义结构体类型
//struct Student;  // 错误，这只是声明了结构体类型，但没有定义变量，单独这样写没有实际意义，可删除
//Student s1;  // 错误，在C语言中，使用结构体类型定义变量时，需要加上struct关键字，应改为 struct Student s1;
//struct Student s2;  // 正确，定义结构体变量
//scanf("%d", &s2);  // 错误，s2是结构体变量，不能直接用scanf输入，应指定具体成员，改为 scanf("%d", &s2.num);
//printf("%d", s2);  // 错误，s2是结构体变量，不能直接用printf输出，应指定具体成员，改为 printf("%d", s2.num);
//printf("%d", s2.num);  // 正确，输出结构体变量的成员

//
//#include <stdio.h>
//
//struct Student {
//    int num;
//    char name[20];
//};
//
//int main() {
//    struct Student s;
//    struct Student* p = &s;
//
//    s.num = 1;  // 使用 . 访问结构体变量的成员
//    p->num = 2;  // 使用 -> 访问结构体指针指向的结构体的成员
//
//    printf("s.num = %d\n", s.num);
//    return 0;
//}


#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//void analyze(int* p, int n, int* max, int* min, double* avg) {
//    *max = *p;
//    *min = *p;
//    int sum = 0;
//    for (int i = 0; i < n; i++) {
//        if (*(p + i) > *max) {
//            *max = *(p + i);
//        }
//        if (*(p + i) < *min) {
//            *min = *(p + i);
//        }
//        sum += *(p + i);
//    }
//    *avg = (double)sum / n;
//}
//
//int main() {
//    int arr[10];
//    int max, min;
//    double avg;
//
//    printf("请输入10个整数：\n");
//    for (int i = 0; i < 10; i++) {
//        scanf("%d", &arr[i]);
//    }
//
//    analyze(arr, 10, &max, &min, &avg);
//
//    printf("最大值：%d\n", max);
//    printf("最小值：%d\n", min);
//    printf("平均值：%.2f\n", avg);
//
//    return 0;
//}

//#include <stdio.h>
//
//int count_char(char* p, char ch) {
//    int count = 0;
//    while (*p != '\0') {
//        if (*p == ch) {
//            count++;
//        }
//        p++;
//    }
//    return count;
//}
//
//int main() {
//    char str[100];
//    char ch;
//
//    printf("请输入一行字符串：");
//    scanf("%s", str);
//    printf("请输入一个字符：");
//    scanf(" %c", &ch);
//
//    int result = count_char(str, ch);
//    printf("%d\n", result);
//
//    return 0;
//}


//#include <stdio.h>
//
//struct Student {
//    int num;
//    char name[20];
//    float score[3];
//    float avg;
//};
//
//void inputStudent(struct Student* s) {
//    printf("请输入学号：");
//    scanf("%d", &s->num);
//    printf("请输入姓名：");
//    scanf("%s", s->name);
//    printf("请输入三门课成绩：");
//    for (int i = 0; i < 3; i++) {
//        scanf("%f", &s->score[i]);
//    }
//}
//
//void calculateAvg(struct Student* s) {
//    float sum = 0;
//    for (int i = 0; i < 3; i++) {
//        sum += s->score[i];
//    }
//    s->avg = sum / 3;
//}
//
//void outputStudent(struct Student s) {
//    printf("学号：%d\n", s.num);
//    printf("姓名：%s\n", s.name);
//    printf("三门课成绩：%.2f %.2f %.2f\n", s.score[0], s.score[1], s.score[2]);
//    printf("平均分：%.2f\n", s.avg);
//}
//
//int main() {
//    struct Student s;
//    inputStudent(&s);
//    calculateAvg(&s);
//    outputStudent(s);
//
//    return 0;
//}


//#include <stdio.h>
//
//struct Student {
//    int num;
//    char name[20];
//    float score;
//};
//
//void sortStudents(struct Student students[], int n) {
//    for (int i = 0; i < n - 1; i++) {
//        for (int j = 0; j < n - i - 1; j++) {
//            if (students[j].score < students[j + 1].score) {
//                struct Student temp = students[j];
//                students[j] = students[j + 1];
//                students[j + 1] = temp;
//            }
//        }
//    }
//}
//
//int main() {
//    struct Student students[5];
//
//    printf("请输入5名学生的信息：\n");
//    for (int i = 0; i < 5; i++) {
//        printf("第 %d 名学生：\n", i + 1);
//        printf("学号：");
//        scanf("%d", &students[i].num);
//        printf("姓名：");
//        scanf("%s", students[i].name);
//        printf("成绩：");
//        scanf("%f", &students[i].score);
//    }
//
//    sortStudents(students, 5);
//
//    printf("排名\t学号\t姓名\t成绩\n");
//    for (int i = 0; i < 5; i++) {
//        printf("%d\t%d\t%s\t%.2f\n", i + 1, students[i].num, students[i].name, students[i].score);
//    }
//
//    return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//
//    int a = 0 ;
//    scanf("%d", &a);
//    if (a >= 140) 
//        printf("%s\n", "genius"); 
//    return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    int a = 0;
//    int b = 0;
//    scanf("%d\n", &a);
//    scanf("%d\n", &b);
//    int c = a / b;
//    int d = a % b;
//    printf("%d\n", c);
//    printf("%d\n", d);
//    return 0;
//}


#include <stdio.h>
int main()
{
    int a = 0;
    int b = 0;
    scanf("%d%d", a, b);
    if (a > b)
        printf("%d\n", a);
    else if (a = b)
            printf("%s\n", "a=b");
    else
            printf("%d\n", b);
    return 0;
}