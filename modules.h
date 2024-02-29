//#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define cls system("cls")
#define pause system("pause")

struct student
{
    int m_Num;//学号
    char m_Name[51];//姓名
    char m_Class[21];//班级
    int m_TotalScore;//总成绩
    double m_TotalCredit;//总GPA
    
    int m_Score[11];//课程成绩，共有10门课程
    double m_Credit[11];//课程学分，对应10门课程
};

#pragma region
void score_input(struct student stu[], int num);//录入                                                          //GzLxz190614
void score_search(struct student stu[], int num);//查询                                                         //GzLxz190614
void score_sort(struct student stu[], int num);//排序                                                           //子鸣妹妹
void score_sta(struct student stu[], int size, int sub);//统计                                                  //GzLxz190614
void gpa_cal(struct student stu[], int num);//GPA计算                                                           //GzLxz190614
void gpa_sort(struct student stu[], int num);//GPA排序                                                          //GzLxz190614
void score_high(struct student stu[], int n, int i);//最高                                                      //顶坤非酋
void score_low(struct student stu[], int n, int i);//最低                                                       //顶坤非酋
void score_ave(struct student stu[], int n, int i);//平均                                                       //顶坤非酋
void score_high_cla(struct student stu[], int num, char cla[], int sub);//班最高                                //子鸣妹妹,GzLxz190614,AF_s
void score_low_cla(struct student stu[], int num, char cla[], int sub);//班最低                                 //子鸣妹妹,GzLxz190614,AF_s
void score_ave_cla(struct student stu[], int num, char cla[], int sub);//班平均                                 //子鸣妹妹,GzLxz190614,AF_s
void file_ex(struct student stu[], int num, bool statu);//文件操作                                              //场外支援:来自BUCM的子鸣妹妹,NEU的AF_s
void menu();//菜单                                                                                              //GzLxz190614
void menu_sub(int *i);//科目输入                                                                                //GzLxz190614
void menu_cla(char *i);//班级输入                                                                               //GzLxz190614
void swap(struct student *stu1, struct student *stu2, struct student* stut);//交换                              //子鸣妹妹,GzLxz190614
#pragma endregion