#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h >
using namespace std;
//ϰ��ṹ
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

		case 1:											//����ӷ�����
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
		case 0:											 //�����������
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
		case 2:											 //�����������
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
		case 3:											//������ɳ˷�����
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

int selecttitle()											//ѡ���Ѷ�
{
	int kind, type,judge;
	int num;
	printf("\n\n");
	printf("===============================ѡ�������Ϣ==================================\n\n");
	printf("             *��ѡ��Χ");
	printf("(��10����,100����,100����,д���ּ���):");
	judge = scanf_s("%d", &kind);
	while (judge == 0 || kind % 10 != 0)
	{
		if (judge != 0)
		{
			printf("             *ѡ��Χ����ȷ,ֻ��Ϊ10��������\n             *����������: ");
			judge = scanf_s("%d", &kind);
		}
		while (judge == 0)
		{
			printf("             *�����ʽ����\n             *���������֣�");
			fflush(stdin);
			judge = scanf_s("%d", &kind);
		}
	}
	printf("             *��������Ŀ����:");
	judge = scanf_s("%d", &num);
	while (judge == 0 || num<1)
	{
		if (judge != 0)
		{
			printf("             *������������ȷ,���������룺");
			judge = scanf_s("%d", &num);
		}
		while (judge == 0)
		{
			printf("             *�����ʽ����\n             *���������֣�");
			fflush(stdin);
			judge = scanf_s("%d", &num);
		}
	}
	printf("             *��ѡ����������(������)\n");
	printf("1���ӷ�����  2����������  3���˷�����  4����������  5���������\n             *");
	judge = scanf_s("%d", &type);
	while (judge == 0 || type<1 || type>5)
	{
		if (judge != 0)
		{
			printf("             *����ֵ����,���������룺");
			judge = scanf_s("%d", &type);
		}
		while (judge == 0)
		{
			printf("             *�����ʽ����\n             *���������֣�");
			fflush(stdin);
			judge = scanf_s("%d", &type);
		}
	}
	maketitle(kind, num, type);
	return num;
}

int userinterface(int num)//�û�����
{
		FILE *px;

		errno_t err;
	
	err=fopen_s(&px,"wr.txt", "w");
	int i = 0;
	int judge;
	int trueNum = 0, result;
	printf("===============================ѡ�����=====================================\n");
	printf("                           ������������\n\n");
	_getch();
	system("cls");
	printf("===============================ע������=====================================\n\n");
	printf("���λͬѧ��������!");
	printf("(���ֻ��Ϊ���������г�������������)\n\n                           ������������\n\n");
	fprintf(px, "        ���λͬѧ��������!");
	fprintf(px, "(���ֻ��Ϊ���������г�������������)\n");
	_getch();
	system("cls");
	printf("\n");
	printf("===============================��ʼ����(����%d���⣩=====================================\n\n",num);
	while (i<num)
	{
		printf("             *��%d����:\n             *%d%c%d=", i + 1, t[i].b, t[i].text, t[i].c);
		fprintf(px, "��%d����:\n    %d%c%d=\n", i + 1, t[i].b, t[i].text, t[i].c);
		judge = scanf_s("%d", &result);
		while (judge == 0)
		{
			printf("             *��Ҫ�����ַ�\n             *���������!\n");
			fflush(stdin);
			printf("             *��%d����:\n             *%d%c%d=", i + 1, t[i].b, t[i].text, t[i].c);
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
	printf("             *��%d���⣬���%d������ȷ�ʣ�%d%%", num, trueNum, trueNum * 100 / num);
	fprintf(px, "�ָ���---------------------------------------------------------\n");
	fprintf(px, "�ο���\n");
	i = 0;
	while (i<num)
	{
		fprintf(px, "%d��%d       ", i + 1, t[i].result);
		i += 1;
		if (i % 5 == 0)
		{
			fprintf(px, "\n");
		}
	}
	fclose(px);
	return 0;
}

int main()//������
{
	int num;
	printf("                                                                       \n");
	printf("                                                                       \n");
	printf("               ===============================================         \n");
	printf("                  *     ��ӭʹ������������Ŀ����ϵͳ      *            \n");
	printf("               *==============================================*        \n");
	printf("               *               ���ߣ�����                   *        \n");
	printf("               *                                              *        \n");
	printf("               *            ѧ�ţ�203401010128                *        \n");
	printf("               *                                              *        \n");
	printf("               *==============================================*        \n\n");
	printf("===============================����������==================================\n\n");
	printf("                           ������������\n\n");
	_getch();
	system("cls");
	num = selecttitle();
	userinterface(num);
}