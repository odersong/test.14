#include"game.h"
void menu()
{
	printf("*********************\n");
	printf("****1.play 0.exit****\n");
	printf("*********************\n");
}

void game()
{
	char a[row][col] = { 0 };
	c(a,row,col);//���庯��
	d(a, row, col);//���庯��
	char ret = 0;
	while (1)
	{
		//�������
		playmove(a, row, col);//���庯��
		d(a, row, col);//���庯������ӡ
		//�ж�����Ƿ�Ӯ
		ret = iswin(a, row, col);//���庯��
		if(ret != 'C')
		{
			break;
		}
		//��������
		computermove(a, row, col);//���庯��
		d(a, row, col);
		//�жϵ����Ƿ�Ӯ
		ret = iswin(a, row, col);//���庯��
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}

void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;;
	do
	{
		menu();
		printf("��ѡ��");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
		}
	} while(input);
}
int main()
{
	test();
	return 0;
}