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
	c(a,row,col);//定义函数
	d(a, row, col);//定义函数
	char ret = 0;
	while (1)
	{
		//玩家下棋
		playmove(a, row, col);//定义函数
		d(a, row, col);//定义函数，打印
		//判断玩家是否赢
		ret = iswin(a, row, col);//定义函数
		if(ret != 'C')
		{
			break;
		}
		//电脑下棋
		computermove(a, row, col);//定义函数
		d(a, row, col);
		//判断电脑是否赢
		ret = iswin(a, row, col);//定义函数
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
}

void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;;
	do
	{
		menu();
		printf("请选择：");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
		}
	} while(input);
}
int main()
{
	test();
	return 0;
}