#include"modules.h"

void score_input(struct student stu[], int num)//¼��
{
    int sub = 0, i = 0, j = 0;
    for (i = 1; i <= num; i++)
    {
        printf("ѧ��:");
        scanf("%d", &stu[i].m_Num);
        fflush( stdin );
        printf("����:");
        scanf("%s", &stu[i].m_Name);
        fflush( stdin );
        printf("�༶:");
        scanf("%s", &stu[i].m_Class);
        for (j = 1; j <= 10; j++)
        {
            printf("��Ŀ%d:", j);
            scanf("%d", &stu[i].m_Score[j]);
        }
        cls;
    }
    gpa_cal(stu, num);
    file_ex(stu, num, 1);
}

void score_search(struct student stu[], int num)//��ѯ
{
    int num_stu = 0, i = 0, j = 0;
    printf("�����ѯ��ѧ��ѧ��:");
    scanf("%d", &num_stu);
    for (i = 1; i <= num; i++)
    {
        if (stu[i].m_Num == num_stu)
            break;
    }
    printf("ѧ��:%d\n����:%s\n�༶:%s\n", stu[i].m_Num, stu[i].m_Name, stu[i].m_Class);
    for (j = 1; j <= 10; j++)
    {
        printf("��Ŀ%d:%d\n", j, stu[i].m_Score[j]);
    }
    pause;
    cls;
}

void score_sort(struct student stu[], int num)//��ѧ�Ƴɼ�����   //��������
{
    //�ȼ����ܷ�
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= 10; j++)//�ܹ���ʮ�ſ�
        {
            stu[i].m_TotalScore += stu[i].m_Score[j];
        }
    }

    //ð������
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

void score_sta(struct student stu[], int size, int sub)//ͳ��
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

void gpa_cal(struct student stu[], int num)//GPA����     //GzLxz190614
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

void gpa_sort(struct student stu[], int num)//GPA����    //GzLxz190614
{
    int i = 0, j = 0;

    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= 10; j++)//�ܹ���ʮ�ſ�
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

void score_high(struct student stu[], int n, int i)//���       //��������
{
    int max = 0;
    for (int j = 1; j <= n; j++)
    {
        if (stu[j].m_Score[i] > max)
        {
            max = stu[j].m_Score[i];
        }
    }
    printf("��%d�ſγ̵���߷֣�\n", i + 1);
    for (int k = 1; k <= n; k++)
    {
        if (stu[k].m_Score[i] == max)
        {
            printf("    ѧ�ţ�%d \n    ������%s\n     ������%d\n", stu[k].m_Num, stu[k].m_Name, stu[k].m_Score[i]);
        }
    }
}

void score_low(struct student stu[], int n, int i)//���        //��������
{
    int min = 1000;
    for (int j = 1; j <= n; j++)
    {
        if (stu[j].m_Score[i] < min)
        {
            min = stu[j].m_Score[i];
        }
    }
    printf("��%d�ſγ̵���ͷ֣�\n", i + 1);
    for (int k = 1; k <= n; k++)
    {
        if (stu[k].m_Score[i] == min)
        {
            printf("    ѧ�ţ�%d \n    ������%s\n     ������%d\n", stu[k].m_Num, stu[k].m_Name, stu[k].m_Score[i]);
        }
    }
}

void score_ave(struct student stu[], int n, int i)//ƽ��        //��������
{
    int sum = 0;
    for (int j = 1; j <= n; j++)
    {
        sum += stu[j].m_Score[i];
    }
    printf("��%d�ſγ̵�ƽ������%f \n", i, 1.0 * sum / n);
}

void score_high_cla(struct student stu[], int num, char cla[], int sub)//�����
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
            printf("ѧ�ţ�%d\n������%s\n�ɼ���%d\n",stu[i].m_Num,stu[i].m_Name,stu[i].m_Score[sub]);
        }
    }
    pause;
}

void score_low_cla(struct student stu[], int num, char cla[], int sub)//�����
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
            printf("ѧ�ţ�%d\n������%s\n�ɼ���%d\n",stu[i].m_Num,stu[i].m_Name,stu[i].m_Score[sub]);
        }
    }
    pause;
}

void score_ave_cla(struct student stu[], int num, char cla[], int sub)//��ƽ��
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
    printf("%s��ƽ����:%lf\n",cla, sum);
    pause;
}

void menu()//�˵�                                        //GzLxz190614
{
    printf("******���ܲ˵�******\n");
    printf("**                **\n");
    printf("**0.   ��    ��   **\n");
    printf("**1.   �ɼ�¼��   **\n");
    printf("**2.   �ɼ���ѯ   **\n");
    printf("**3.   �ɼ�����   **\n");
    printf("**4.   �ɼ�ͳ��   **\n");
    printf("**5.   �������   **\n");
    printf("**6.   ��������   **\n");
    printf("**7.   �� �� ��   **\n");
    printf("**8.   �� �� ��   **\n");
    printf("**9.   ƽ �� ��   **\n");
    printf("**10.  ����߷�   **\n");
    printf("**11.  ����ͷ�   **\n");
    printf("**12.  ��ƽ����   **\n");
    printf("**15.  �� �� ��   **\n");
    printf("**        19      **\n");
    printf("**                **\n");
    printf("********************\n");
}

void file_ex(struct student stu[], int num,bool statu)//�ļ�����                                    //����֧Ԯ:��������,AF_s
{
    /*
    �������ܣ���ѧ�������ݴ�����
    ͬʱ��һ���ܱ���������ѧ����
    ���ӹ���
    ͨ���༶��ѧ�����༶Ϊ�ļ�������ͳ�Ƹ���ɼ�
	1��ѧ������ѧ���ɼ��༶
    2
    */
    if(statu)
    {
		FILE* pfile = fopen("stu.db", "a+");
		for (int i = 1; i <= num; i++)//���ļ�д��
		{
			if (pfile == NULL)
			{
				printf("�ļ���ʧ�ܣ��q(�s^�t)�r");
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
        for(int i=1;i<=num;i++)//���ļ�����
        {
			if (pfile == NULL)
			{
				printf("�ļ���ʧ�ܣ��q(�s^�t)�r");
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

void menu_sub(int* i)//��Ŀ����                             //GzLxz190614
{
    printf("�����Ŀ���:");
    scanf("%d", i);
}

void menu_cla(char* i)//�༶����                             //GzLxz190614
{
    printf("����༶���:");
    scanf("%s", i);
}

void swap(struct student* stu1, struct student* stu2, struct student* stut)//����    //��������,GzLxz190614
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