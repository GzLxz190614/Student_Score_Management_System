//#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define cls system("cls")
#define pause system("pause")

struct student
{
    int m_Num;//ѧ��
    char m_Name[51];//����
    char m_Class[21];//�༶
    int m_TotalScore;//�ܳɼ�
    double m_TotalCredit;//��GPA
    
    int m_Score[11];//�γ̳ɼ�������10�ſγ�
    double m_Credit[11];//�γ�ѧ�֣���Ӧ10�ſγ�
};

#pragma region
void score_input(struct student stu[], int num);//¼��                                                          //GzLxz190614
void score_search(struct student stu[], int num);//��ѯ                                                         //GzLxz190614
void score_sort(struct student stu[], int num);//����                                                           //��������
void score_sta(struct student stu[], int size, int sub);//ͳ��                                                  //GzLxz190614
void gpa_cal(struct student stu[], int num);//GPA����                                                           //GzLxz190614
void gpa_sort(struct student stu[], int num);//GPA����                                                          //GzLxz190614
void score_high(struct student stu[], int n, int i);//���                                                      //��������
void score_low(struct student stu[], int n, int i);//���                                                       //��������
void score_ave(struct student stu[], int n, int i);//ƽ��                                                       //��������
void score_high_cla(struct student stu[], int num, char cla[], int sub);//�����                                //��������,GzLxz190614,AF_s
void score_low_cla(struct student stu[], int num, char cla[], int sub);//�����                                 //��������,GzLxz190614,AF_s
void score_ave_cla(struct student stu[], int num, char cla[], int sub);//��ƽ��                                 //��������,GzLxz190614,AF_s
void file_ex(struct student stu[], int num, bool statu);//�ļ�����                                              //����֧Ԯ:����BUCM����������,NEU��AF_s
void menu();//�˵�                                                                                              //GzLxz190614
void menu_sub(int *i);//��Ŀ����                                                                                //GzLxz190614
void menu_cla(char *i);//�༶����                                                                               //GzLxz190614
void swap(struct student *stu1, struct student *stu2, struct student* stut);//����                              //��������,GzLxz190614
#pragma endregion