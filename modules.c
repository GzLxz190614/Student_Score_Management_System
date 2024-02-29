#include"modules.h"

void score_input(struct student stu[], int num)//录入
{
    int sub = 0, i = 0, j = 0;
    for (i = 1; i <= num; i++)
    {
        printf("学号:");
        scanf("%d", &stu[i].m_Num);
        fflush( stdin );
        printf("姓名:");
        scanf("%s", &stu[i].m_Name);
        fflush( stdin );
        printf("班级:");
        scanf("%s", &stu[i].m_Class);
        for (j = 1; j <= 10; j++)
        {
            printf("科目%d:", j);
            scanf("%d", &stu[i].m_Score[j]);
        }
        cls;
    }
    gpa_cal(stu, num);
    file_ex(stu, num, 1);
}

void score_search(struct student stu[], int num)//查询
{
    int num_stu = 0, i = 0, j = 0;
    printf("输入查询的学生学号:");
    scanf("%d", &num_stu);
    for (i = 1; i <= num; i++)
    {
        if (stu[i].m_Num == num_stu)
            break;
    }
    printf("学号:%d\n姓名:%s\n班级:%s\n", stu[i].m_Num, stu[i].m_Name, stu[i].m_Class);
    for (j = 1; j <= 10; j++)
    {
        printf("科目%d:%d\n", j, stu[i].m_Score[j]);
    }
    pause;
    cls;
}

void score_sort(struct student stu[], int num)//按学科成绩排序   //子鸣妹妹
{
    //先计算总分
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= 10; j++)//总共有十门课
        {
            stu[i].m_TotalScore += stu[i].m_Score[j];
        }
    }

    //冒泡排序
    struct student temp = { 0 };
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= num - i; j++)
        {
            if (stu[j].m_TotalScore < stu[j + 1].m_TotalScore)
            {
                swap(&stu[j], &stu[j + 1], &temp);
            }
        }
    }

    for (int i = 1; i <= num; i++)
    {
        printf("%d ", stu[i].m_Num);
    }
}

void score_sta(struct student stu[], int size, int sub)//统计
{
    int count_90_100 = 0;
    int count_80_89 = 0;
    int count_70_79 = 0;
    int count_60_69 = 0;
    int count_0_59 = 0;

    for (int i = 1; i <= size; i++)
    {
        if (stu[i].m_Score[sub] >= 90 && stu[i].m_Score[sub] <= 100) {
            count_90_100++;
        }
        else if (stu[i].m_Score[sub] >= 80 && stu[i].m_Score[sub] <= 89) {
            count_80_89++;
        }
        else if (stu[i].m_Score[sub] >= 70 && stu[i].m_Score[sub] <= 79) {
            count_70_79++;
        }
        else if (stu[i].m_Score[sub] >= 60 && stu[i].m_Score[sub] <= 69) {
            count_60_69++;
        }
        else {
            count_0_59++;
        }
    }

    printf("90~100: %d\n", count_90_100);
    printf("80~89: %d\n", count_80_89);
    printf("70~79: %d\n", count_70_79);
    printf("60~69: %d\n", count_60_69);
    printf("0~59: %d\n", count_0_59);
    pause;
    cls;
}

void gpa_cal(struct student stu[], int num)//GPA计算     //GzLxz190614
{
    int i = 0, j = 0;
    for (i = 1; i <= num; i++)
    {
        for (j = 1; j <= 10; j++)
        {
            stu[i].m_Credit[j] = (((stu[i].m_Score[j] - 50) * 1.0) / 10);
        }
    }
}

void gpa_sort(struct student stu[], int num)//GPA排序    //GzLxz190614
{
    int i = 0, j = 0;

    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= 10; j++)//总共有十门课
        {
            stu[i].m_TotalCredit += stu[i].m_Credit[j];
        }
    }

    struct student temp = { 0 };
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= num - i; j++)
        {
            if (stu[j].m_TotalCredit < stu[j + 1].m_TotalCredit)
            {
                swap(&stu[j], &stu[j + 1], &temp);
            }
        }
    }

    for (int i = 1; i <= num; i++)
    {
        printf("%d ", stu[i].m_Num);
    }
    pause;
}

void score_high(struct student stu[], int n, int i)//最高       //顶坤非酋
{
    int max = 0;
    for (int j = 1; j <= n; j++)
    {
        if (stu[j].m_Score[i] > max)
        {
            max = stu[j].m_Score[i];
        }
    }
    printf("第%d门课程的最高分：\n", i + 1);
    for (int k = 1; k <= n; k++)
    {
        if (stu[k].m_Score[i] == max)
        {
            printf("    学号：%d \n    姓名：%s\n     分数：%d\n", stu[k].m_Num, stu[k].m_Name, stu[k].m_Score[i]);
        }
    }
}

void score_low(struct student stu[], int n, int i)//最低        //顶坤非酋
{
    int min = 1000;
    for (int j = 1; j <= n; j++)
    {
        if (stu[j].m_Score[i] < min)
        {
            min = stu[j].m_Score[i];
        }
    }
    printf("第%d门课程的最低分：\n", i + 1);
    for (int k = 1; k <= n; k++)
    {
        if (stu[k].m_Score[i] == min)
        {
            printf("    学号：%d \n    姓名：%s\n     分数：%d\n", stu[k].m_Num, stu[k].m_Name, stu[k].m_Score[i]);
        }
    }
}

void score_ave(struct student stu[], int n, int i)//平均        //顶坤非酋
{
    int sum = 0;
    for (int j = 1; j <= n; j++)
    {
        sum += stu[j].m_Score[i];
    }
    printf("第%d门课程的平均分是%f \n", i, 1.0 * sum / n);
}

void score_high_cla(struct student stu[], int num, char cla[], int sub)//班最高
{
    int max = -1;
    for (int i = 1; i <= num; i++)
    {
        if (strcmp(stu[i].m_Class, cla) == 0)
        {
            if (max < stu[i].m_Score[sub])
            {
                max = stu[i].m_Score[sub];
            }
        }
    }
    for (int i = 1; i <= num; i++)
    {
        if (stu[i].m_Score[sub] == max)
        {
            printf("学号：%d\n姓名：%s\n成绩：%d\n",stu[i].m_Num,stu[i].m_Name,stu[i].m_Score[sub]);
        }
    }
    pause;
}

void score_low_cla(struct student stu[], int num, char cla[], int sub)//班最低
{
    int min=9999999;
    int temp = 0;
    for (int i = 1; i <= num; i++)
    {
        if(strcmp(stu[i].m_Class, cla) == 0)
        {
            if (min > stu[i].m_Score[sub])
		    {
                min = stu[i].m_Score[sub];
            }
        }
    }
    for (int i = 1; i <= num; i++)
    {
        if (stu[i].m_Score[sub] == min)
        {
            printf("学号：%d\n姓名：%s\n成绩：%d\n",stu[i].m_Num,stu[i].m_Name,stu[i].m_Score[sub]);
        }
    }
    pause;
}

void score_ave_cla(struct student stu[], int num, char cla[], int sub)//班平均
{
    double sum = 0;
    int count = 0;
    for(int i=1;i<=num;i++)
    {
        if(strcmp(stu[i].m_Class, cla) == 0)
        {
			sum += stu[i].m_Score[sub];
            count++;
        }
    }
    sum/=count;
    printf("%s班平均分:%lf\n",cla, sum);
    pause;
}

void menu()//菜单                                        //GzLxz190614
{
    printf("******功能菜单******\n");
    printf("**                **\n");
    printf("**0.   退    出   **\n");
    printf("**1.   成绩录入   **\n");
    printf("**2.   成绩查询   **\n");
    printf("**3.   成绩排序   **\n");
    printf("**4.   成绩统计   **\n");
    printf("**5.   绩点计算   **\n");
    printf("**6.   绩点排名   **\n");
    printf("**7.   最 高 分   **\n");
    printf("**8.   最 低 分   **\n");
    printf("**9.   平 均 分   **\n");
    printf("**10.  班最高分   **\n");
    printf("**11.  班最低分   **\n");
    printf("**12.  班平均分   **\n");
    printf("**15.  测 试 中   **\n");
    printf("**        19      **\n");
    printf("**                **\n");
    printf("********************\n");
}

void file_ex(struct student stu[], int num,bool statu)//文件操作                                    //场外支援:子鸣妹妹,AF_s
{
    /*
    基础功能：把学生的数据存起来
    同时有一个总表（便于搜索学生）
    复杂功能
    通过班级分学生（班级为文件名），统计各班成绩
	1按学号搜索学生成绩班级
    2
    */
    if(statu)
    {
		FILE* pfile = fopen("stu.db", "a+");
		for (int i = 1; i <= num; i++)//向文件写入
		{
			if (pfile == NULL)
			{
				printf("文件打开失败！╭(╯^╰)╮");
                break;
			}
			fprintf(pfile, "%d %s %s ", stu[i].m_Num, stu[i].m_Name, stu[i].m_Class);
			for (int j = 1; j <= 10; j++)
			{
				fprintf(pfile, "%d ", stu[i].m_Score[j]);
			}
			for (int j = 1; j <= 10; j++)
			{
				fprintf(pfile, "%lf ", stu[i].m_Credit[j]);
			}
			fprintf(pfile, "\n");
		}
        fclose(pfile);
    }
    else
    {
		FILE* pfile = fopen("stu.db", "a+");
        for(int i=1;i<=num;i++)//从文件读入
        {
			if (pfile == NULL)
			{
				printf("文件打开失败！╭(╯^╰)╮");
				break;
			}
            fscanf(pfile, "%d %s %s ", &stu[i].m_Num, &stu[i].m_Name, &stu[i].m_Class);
			for (int j = 1; j <= 10; j++)
			{
			    fscanf(pfile, "%d ", &stu[i].m_Score[j]);
			}
			for (int j = 1; j <= 10; j++)
			{
				fscanf(pfile, "%lf ", &stu[i].m_Credit[j]);
			}
        }
		//fscanf(pfile, "\n");
        score_search(stu, num);
    }
    pause;
    cls;
}

void menu_sub(int* i)//科目输入                             //GzLxz190614
{
    printf("输入科目编号:");
    scanf("%d", i);
}

void menu_cla(char* i)//班级输入                             //GzLxz190614
{
    printf("输入班级编号:");
    scanf("%s", i);
}

void swap(struct student* stu1, struct student* stu2, struct student* stut)//交换    //子鸣妹妹,GzLxz190614
{
    //struct student stut = { 0 };
    
    memcpy(stut, stu2,sizeof(struct student));
    memcpy(stu2, stu1,sizeof(struct student));
	memcpy(stu1, stut, sizeof(struct student));
    /*
    *stut = *stu1;
    *stu1 = *stu2;
    *stu2 = *stut;
    */
}