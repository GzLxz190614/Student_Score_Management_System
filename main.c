#include"modules.h"

int main()
{
    int i = 0, num_fun = 0, sub = 0, p, num = 10, cho = 0;
    char cla[21] = "\0";
    menu();
    struct student stu[100] = { 0 };
    while (scanf("%d", &i))
    {
        switch (i)
        {
        case 0:
        {
            printf("����1��ȷ���˳�\n");
            scanf("%d", &i);
            if (i == 1)
            {
                return 0;
            }
            cls;
            break;
        }

        case 1://¼��
        {
            cls;
            printf("����ѧ��������");
            scanf("%d",&num);
            score_input(stu, num);
            pause;
            cls;
            break;
        }

        case 2://��ѯ
        {
            cls;
            score_search(stu, num);
            pause;
            cls;
            break;
        }

        case 3://����
        {
            cls;
            score_sort(stu, num);
            pause;
            cls;
            break;
        }

        case 4://ͳ��
        {
            cls;
            menu_sub(&sub);
            score_sta(stu, num, sub);
            pause;
            cls;
            break;
        }

        case 5://GPA����
        {
            cls;
            menu_sub(&sub);
            gpa_cal(stu, num);
            pause;
            cls;
            break;
        }

        case 6://GPA����
        {
            cls;
            menu_sub(&sub);
            gpa_sort(stu, num);
            pause;
            cls;
            break;
        }

        case 7://���
        {
            cls;
            menu_sub(&sub);
            score_high(stu, num, sub);
            pause;
            cls;
            break;
        }

        case 8://���
        {
            cls;
            menu_sub(&sub);
            score_low(stu, num, sub);
            pause;
            cls;
            break;
        }

        case 9://ƽ��
        {
            cls;
            menu_sub(&sub);
            score_ave(stu, num, sub);
            pause;
            cls;
            break;
        }

        case 10://�����
        {
            cls;
            menu_sub(&sub);
            menu_cla(cla);
            score_high_cla(stu,num,cla,sub);
            pause;
            cls;
            break;
        }

        case 11://�����
        {
            cls;
            menu_sub(&sub);
            menu_cla(cla);
            score_low_cla(stu, num, cla, sub);
            pause;
            cls;
            break;
        }

        case 12://��ƽ��
        {
            cls;
            menu_sub(&sub);
            menu_cla(cla);
            score_ave_cla(stu, num, cla, sub);
            pause;
            cls;
            break;
        }

        case 15://�ļ���ȡ
        {
            cls;
            file_ex(stu, num, 0);
            pause;
            cls;
            break;
        }

        case 19://�²�
        {
            cls;
            printf("Credit\n��ܴ:GzLxz190614\n��ܴָ��:��������,AF_s\n���ܱ�д:������԰NEUͻ���ֶ���\n����Ԯ��:��������,AF_s\n\n");
            printf("������,�Ժ��������ܲ������Լ�һ��������\nNMD���������������,�����ܲ��ܸ����Ѷ�?\nNMD΢�����ܲ��ܰ�Live ShareŪ�ã��ҵ��ļ���ô��ʧ�ˣ�\n�ṹ�彻����ô�����ú����������������b���⺦���ǵ���һ��Сʱ\nC?������ѧ!����C++)\n          ----GzLxz190614\n");//Gz
            printf("�ˣ��Ͷ�����ѧ�������ͻ������ԣ�C��C��C++��C++����Ҫ�ܰ�C��C++����������ô��ȥ2000���أ��q(�s^�t)�rC?������ѧ\n          ����������������\n");//��������
            printf("�ˣ��Ͷ�����bug�Ĳ��𣬾ͱ�д����ǯ����ǯ��з����з�У���Ҫ�ܰ���ǯ��з�У���������ô������Hello World�Ա�ѽ��,C?������ѧ!!!!!!!!!\n��ȥѧpython,�������,����python\n          ��������AF_s\n");//AF_s
            pause;
            cls;
            break;
        }

        default:
        {
            cls;
            num_fun++;
            if (num_fun == 6 || num_fun == 114514 || num_fun == 1919)
            {
                printf("\n");
            }
            else
            {
                printf("?\n");
            }
            pause;
            cls;
            break;
        }
        }
        fflush( stdin );
        menu();
    }
    return 0;
}