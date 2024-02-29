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
            printf("输入1来确定退出\n");
            scanf("%d", &i);
            if (i == 1)
            {
                return 0;
            }
            cls;
            break;
        }

        case 1://录入
        {
            cls;
            printf("输入学生数量：");
            scanf("%d",&num);
            score_input(stu, num);
            pause;
            cls;
            break;
        }

        case 2://查询
        {
            cls;
            score_search(stu, num);
            pause;
            cls;
            break;
        }

        case 3://排序
        {
            cls;
            score_sort(stu, num);
            pause;
            cls;
            break;
        }

        case 4://统计
        {
            cls;
            menu_sub(&sub);
            score_sta(stu, num, sub);
            pause;
            cls;
            break;
        }

        case 5://GPA计算
        {
            cls;
            menu_sub(&sub);
            gpa_cal(stu, num);
            pause;
            cls;
            break;
        }

        case 6://GPA排序
        {
            cls;
            menu_sub(&sub);
            gpa_sort(stu, num);
            pause;
            cls;
            break;
        }

        case 7://最高
        {
            cls;
            menu_sub(&sub);
            score_high(stu, num, sub);
            pause;
            cls;
            break;
        }

        case 8://最低
        {
            cls;
            menu_sub(&sub);
            score_low(stu, num, sub);
            pause;
            cls;
            break;
        }

        case 9://平均
        {
            cls;
            menu_sub(&sub);
            score_ave(stu, num, sub);
            pause;
            cls;
            break;
        }

        case 10://班最高
        {
            cls;
            menu_sub(&sub);
            menu_cla(cla);
            score_high_cla(stu,num,cla,sub);
            pause;
            cls;
            break;
        }

        case 11://班最低
        {
            cls;
            menu_sub(&sub);
            menu_cla(cla);
            score_low_cla(stu, num, cla, sub);
            pause;
            cls;
            break;
        }

        case 12://班平均
        {
            cls;
            menu_sub(&sub);
            menu_cla(cla);
            score_ave_cla(stu, num, cla, sub);
            pause;
            cls;
            break;
        }

        case 15://文件读取
        {
            cls;
            file_ex(stu, num, 0);
            pause;
            cls;
            break;
        }

        case 19://吐槽
        {
            cls;
            printf("Credit\n框架搭构:GzLxz190614\n框架搭构指导:子鸣妹妹,AF_s\n功能编写:翻斗花园NEU突破手丁真\n场外援助:子鸣妹妹,AF_s\n\n");
            printf("红温了,以后这玩意能不能我自己一个人整完\nNMD你们上网查就算了,你们能不能给我搜对?\nNMD微软你能不能把Live Share弄好，我的文件怎么消失了？\n结构体交换怎么不能拿函数里的来整，就这b玩意害我们调了一个小时\nC?狗都不学!不如C++)\n          ----GzLxz190614\n");//Gz
            printf("菜，就多练，学不懂，就换新语言，C是C，C++是C++，你要总把C当C++，哥们你怎么不去2000年呢？╭(╯^╰)╮C?狗都不学\n          ————子鸣妹妹\n");//子鸣妹妹
            printf("菜，就多练，bug改不起，就别写，蚁钳是蚁钳，蟹仔是蟹仔，你要总把蚁钳当蟹仔，哥们你怎么不拿你Hello World对比呀？,C?狗都不学!!!!!!!!!\n快去学python,人生苦短,我用python\n          ————AF_s\n");//AF_s
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