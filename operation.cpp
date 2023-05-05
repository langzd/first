#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h >
using namespace std;
//习题结构
struct test
{
	char text;
	int b, c;
	int result;
}t[10];

int maketitle(int x, int num, int type)
{
	int a = type, b, c, y = 0;
	srand((unsigned)time(NULL));
	int i = 0;
	for (i = 0; i<num; i++)
	{
		if (type == 5)
		{
			a = rand();
		}
		switch (a % 4)
		{

		case 1:											//随机加法运算
		{
			c = rand() % x;
			b = rand() % x;
			while (c<0 || b<0 || c + b>x)
			{
				c = rand() % x;
				b = rand() % x;
			}
			t[i].text = '+';
			t[i].b = b;
			t[i].c = c;
			t[i].result = b + c;
			break;
		}
		case 0:											 //随机除法运算
		{
			c = rand() % x;
			b = rand() % x;
			while (b<0 || c <= 0 || b*c>x)
			{
				b = rand() % x;
				c = rand() % x;
			}
			t[i].result = b;
			t[i].b = b*c;
			t[i].c = c;
			t[i].text = '/';
			break;
		}
		case 2:											 //随机减法运算
		{
			b = rand() % x;
			while (b<0)
			{
				b = rand() % x;
			}
			c = rand() % x;
			while (c<0)
			{
				c = rand() % x;
			}
			if (b<c)
			{
				y = b;
				b = c;
				c = y;
			}
			t[i].b = b;
			t[i].c = c;
			t[i].text = '-';
			t[i].result = b - c;
			break;
		}
		case 3:											//随机生成乘法运算
		{
			b = rand() % x;
			c = rand() % x;
			while (b<0 || c<0 || b*c>x)
			{
				b = rand() % x;
				c = rand() % x;
			}
			t[i].result = b*c;
			t[i].b = b;
			t[i].c = c;
			t[i].text = 'X';
			break;
		}
		}
	}
	return 0;
}

int selecttitle()											//选择难度
{
	int kind, type,judge;
	int num;
	printf("\n\n");
	printf("===============================选择出题信息==================================\n\n");
	printf("             *请选择范围");
	printf("(如10以内,100以内,100以内,写数字即可):");
	judge = scanf_s("%d", &kind);
	while (judge == 0 || kind % 10 != 0)
	{
		if (judge != 0)
		{
			printf("             *选择范围不正确,只能为10的整数倍\n             *请重新输入: ");
			judge = scanf_s("%d", &kind);
		}
		while (judge == 0)
		{
			printf("             *输入格式错误\n             *请输入数字：");
			fflush(stdin);
			judge = scanf_s("%d", &kind);
		}
	}
	printf("             *请设置题目数量:");
	judge = scanf_s("%d", &num);
	while (judge == 0 || num<1)
	{
		if (judge != 0)
		{
			printf("             *输入数量不正确,请重新输入：");
			judge = scanf_s("%d", &num);
		}
		while (judge == 0)
		{
			printf("             *输入格式错误\n             *请输入数字：");
			fflush(stdin);
			judge = scanf_s("%d", &num);
		}
	}
	printf("             *请选择运算类型(请填编号)\n");
	printf("1、加法运算  2、减法运算  3、乘法运算  4、除法运算  5、混合运算\n             *");
	judge = scanf_s("%d", &type);
	while (judge == 0 || type<1 || type>5)
	{
		if (judge != 0)
		{
			printf("             *输入值错误,请重新输入：");
			judge = scanf_s("%d", &type);
		}
		while (judge == 0)
		{
			printf("             *输入格式错误\n             *请输入数字：");
			fflush(stdin);
			judge = scanf_s("%d", &type);
		}
	}
	maketitle(kind, num, type);
	return num;
}

int userinterface(int num)//用户界面
{
		FILE *px;

		errno_t err;
	
	err=fopen_s(&px,"wr.txt", "w");
	int i = 0;
	int judge;
	int trueNum = 0, result;
	printf("===============================选择完毕=====================================\n");
	printf("                           点击任意键继续\n\n");
	_getch();
	system("cls");
	printf("===============================注意事项=====================================\n\n");
	printf("请各位同学认真作答!");
	printf("(结果只能为整数，若有除法，则必须除尽)\n\n                           点击任意键继续\n\n");
	fprintf(px, "        请各位同学认真作答!");
	fprintf(px, "(结果只能为整数，若有除法，则必须除尽)\n");
	_getch();
	system("cls");
	printf("\n");
	printf("===============================开始答题(共有%d道题）=====================================\n\n",num);
	while (i<num)
	{
		printf("             *第%d道题:\n             *%d%c%d=", i + 1, t[i].b, t[i].text, t[i].c);
		fprintf(px, "第%d道题:\n    %d%c%d=\n", i + 1, t[i].b, t[i].text, t[i].c);
		judge = scanf_s("%d", &result);
		while (judge == 0)
		{
			printf("             *不要出现字符\n             *请认真答题!\n");
			fflush(stdin);
			printf("             *第%d道题:\n             *%d%c%d=", i + 1, t[i].b, t[i].text, t[i].c);
			judge = scanf_s("%d", &result);
		}
		if (result == t[i].result)
		{
			trueNum += 1;
			printf("right\n");
		}
		else
		{
			printf("wrong\n");
		}
		_getch();
		i += 1;
	}
	printf("             *共%d道题，答对%d道，正确率：%d%%", num, trueNum, trueNum * 100 / num);
	fprintf(px, "分割线---------------------------------------------------------\n");
	fprintf(px, "参考答案\n");
	i = 0;
	while (i<num)
	{
		fprintf(px, "%d、%d       ", i + 1, t[i].result);
		i += 1;
		if (i % 5 == 0)
		{
			fprintf(px, "\n");
		}
	}
	fclose(px);
	return 0;
}

int main()//主函数
{
	int num;
	printf("                                                                       \n");
	printf("                                                                       \n");
	printf("               ===============================================         \n");
	printf("                  *     欢迎使用四则运算题目生成系统      *            \n");
	printf("               *==============================================*        \n");
	printf("               *               作者：郎振东                   *        \n");
	printf("               *                                              *        \n");
	printf("               *            学号：203401010128                *        \n");
	printf("               *                                              *        \n");
	printf("               *==============================================*        \n\n");
	printf("===============================进入主程序==================================\n\n");
	printf("                           点击任意键继续\n\n");
	_getch();
	system("cls");
	num = selecttitle();
	userinterface(num);
}