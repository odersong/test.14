#include "game.h"
void c(char a[row][col], int q, int e)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < q; i++)
	{
		for (j = 0; j < e; j++)
		{
			a[i][j] = ' ';
		}
	}
}


//��Ҫ�Ż������·��Ż�
//void d(char a[row][col], int q, int e)
//{
//	int r = 0;
//	for (r = 0; r < row; r++)
//	{
//		printf(" %c | %c | %c \n",a[r][0],a[r][1],a[r][2]);
//		if(r<row-1)
//		printf("---|---|---\n");
//	}
//}

void d(char a[row][col], int q, int e)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < q; i++)
	{
		for (j = 0; j < e; j++)
		{
			printf(" %c ", a[i][j]);
			if (j < e - 1)
				printf("|");
		}
		printf("\n");
		if (i < q - 1)
		{
			for (j = 0; j < e; j++)
			{
				printf("---");
				if(j<e-1)
					printf("|");
			}
			printf("\n");
		}
	}
}


void playmove(char a[row][col], int q, int e)
{
	int x = 0;
	int y = 0;
	printf("����ߣ�\n");
	printf("������Ҫ�µ����꣺\n");
	while (1)
	{
		scanf_s("%d%d", &x, &y);
		if (x >= 1 && x <= q && y >= 1 && y <= e)
		{
			if (a[x - 1][y - 1] == ' ')
			{
				a[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("�����걻ռ��\n");
		}
		else
			printf("��������ȷ����\n");
	}
}

void computermove(char a[row][col], int q, int e)
{
	int x = 0;
	int y = 0;
	printf("������\n");
	while (1)
	{
		x = rand() % q;
		y = rand() % e;
		if (a[x][y] == ' ')
		{
			a[x][y] = '#';
			break;
		}
	}
}

//����һ��ʾ��������
//����0��ʾ����û��
int isfull(char a[row][col], int q, int e)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < q; i++)
	{
		for (j = 0; j < e; j++)
		{
			if (a[i][j] == ' ')
			{
				return 0;//û��
			}
		}
	}
	return 1;//����
}

char iswin(char a[row][col], int q, int e)
{
	int i = 0;
	//������
	for (i = 0; i < q; i++)
	{
		if (a[i][0] == a[i][1] && a[i][1] == a[i][2] && a[i][1] != ' ')
		{
			return a[i][1];
		}
	}
	//������
	for (i = 0; i < e; i++)
	{
		if (a[0][i] == a[1][i] && a[1][i] == a[2][i] && a[1][i] != ' ')
		{
			return a[1][i];
		}
	}
	//�����Խ���
	if (a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[1][1] != ' ')
	{
		return a[1][1];
	}
	if (a[0][2] == a[1][1] && a[1][1] == a[2][0] && a[1][1] != ' ')
	{
		return a[1][1];
	}
	//�ж��Ƿ�ƽ��
	if (1 == isfull(a, q, e))
	{
		return 'q';
	}
	return 'C';
}