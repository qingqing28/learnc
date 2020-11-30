#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<string.h>
#include<time.h>

#define MAX_SQUARE 15
//�����ַ���������ӡ���̺�����
static const char ch[11][4] = {"��","��","��","��","��","��","��","��","��","��","��" };
//��¼ÿλ�������λ��
static int Record[MAX_SQUARE][MAX_SQUARE] = { 0 };
static int Score[MAX_SQUARE][MAX_SQUARE] = { 0 };
static int Sum = 0, Renum = 0;


void setScr() {
	system("pause > nul2 > nul1");
	system("cls");
	system("c:\\windows\\system32\\mode.com con cols=43 lines=20");
	system("color 8f");
}

int menu() {
	system("cls");
	system("c:\\windows\\system32\\mode.com con cols=56 lines=20");
	system("color 8f");
	system("title ��������Ϸ");
	printf("��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��\n");
	printf("��            ��������             ��\n");
	printf("��[1]��������Ϸ                      ��\n");
	printf("��[2]��˫����Ϸ                      ��\n");
	printf("��[3]����Ϸ����                      ��\n");
	printf("��[4]���˳�                          ��\n");
	printf("��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��  ��\n");
	printf("��ѡ��");
	int choice;
	scanf("%d",&choice);
	return choice;
}
void Victory(int number) {
	system("cls");
	system("c:\\windows\\system32\\mode.com con cols=43 lines=20");
	//system("color 8f");
	if (number == 1) {
		system("color 3f");
		printf("��                                     ��\n");
		printf("��        ��ϲ���1[����]��ʤ��        ��\n");
		printf("��                                     ��\n");
		printf("��[ʤ�����]:���1                     ��\n");
		printf("��[��������]:����                      ��\n");
		printf("��[ף��]:��ϲ��Ӯ����ʤ����            ��\n");
		printf("��                                     ��\n");
		printf("��                                     ��\n");
	}
	else if (number == 2) {
		system("color 6f");
		printf("��                                     ��\n");
		printf("��        ��ϲ���2[����]��ʤ��        ��\n");
		printf("��                                     ��\n");
		printf("��[ʤ�����]:���2                     ��\n");
		printf("��[��������]:����                      ��\n");
		printf("��[ף��]:��ϲ��Ӯ����ʤ����            ��\n");
		printf("��                                     ��\n");
		printf("��                                     ��\n");
	}
	else if (number == 3) {
		system("color 9f");
		printf("��                                     ��\n");
		printf("��        ��ϲ�����ʤ����ʤ��         ��\n");
		printf("��                                     ��\n");
		printf("��[ʤ�����]:�Լ�                      ��\n");
		printf("��[��������]:����                      ��\n");
		printf("��[ף��]:��ϲ��Ӯ����ʤ����            ��\n");
		printf("��                                     ��\n");
		printf("��                                     ��\n");
	}
	else if (number == 4) {
		system("color Bf");
		printf("��                                     ��\n");
		printf("��           ���ź������ˣ�            ��\n");
		printf("��                                     ��\n");
		printf("��[ʤ�����]:����                      ��\n");
		printf("��[��������]:����                      ��\n");
		printf("��[ף��]:���ź�������                  ��\n");
		printf("��                                     ��\n");
		printf("��                                     ��\n");
	}
	else {
		system("color Cf");
		printf("��                                     ��\n");
		printf("��                                     ��\n");
		printf("��[ʤ�����]:�ޣ�ƽ�֣�                ��\n");
		printf("��[��������]:��ɫ���ɫ                ��\n");
		printf("��[ף��]:���̾�Ȼ������ƽ�֣�          ��\n");
		printf("��                                     ��\n");
		printf("��                                     ��\n");
	}
	printf("�밴���������......");
	system("pause>nul2>nul");
}

void empty(int value[MAX_SQUARE][MAX_SQUARE], int Default[MAX_SQUARE][MAX_SQUARE]) {
	int i, j;
	for (i = 0; i < MAX_SQUARE; i++) {
		for (j = 0; j < MAX_SQUARE; j++) {
			value[i][j] = Default[i][j];
		}
	}
}

//------���岢��ӡ����-----//
/*
*	��playerΪ���1������[x,y]��λ���������1���壻
*   ��playerΪ���2������[x,y]��λ���������2���壻
*   ��player��Ϊ���1Ҳ��Ϊ���2����ִ�������ж���
*   ��ӡ����
*/
void PrintBoard(int* x, int* y, int value[MAX_SQUARE][MAX_SQUARE], int player) {
	system("cls");
	if (player == 1) {
		value[*x][*y] = 10;
	}
	else if (player == 2) {
		value[*x][*y] = 9;
	}

	printf("    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4\n");
	for (int i = 0; i < MAX_SQUARE; i++) {
		if (i != 0) {
			printf(" %d", i % 10);
		}
		else {
			printf(" 0");
		}
		for (int j = 0; j < MAX_SQUARE; j++) {
			if (j != 0 && (value[i][j-1] == 9 || value[i][j-1] == 10) ) {
				printf("%s", ch[value[i][j]]);
			}
			else {
				printf(" %s", ch[value[i][j]]);
			}
				
		}
		printf("\n");
	}
}
//����������ҵ����������1�������2���������һ����1����������٣�
//���1��������壬����Ӧ��2���������
int nextPlayer() {
	int player1 = 0, player2 = 0;
	for (int i = 0; i < MAX_SQUARE; i++) {
		for (int j = 0; j < MAX_SQUARE; j++) {
			if (Record[i][j] == 1) {
				player1++;
			}
			else if (Record[i][j] == 2) {
				player2++;
			}
		}
	}
	if (player1 <= player2) {
		return 1;
	}
	else {
		return 2;
	}
}

//-------�ж�����λ���Ƿ����--------//
/*
* ���겻���������򷵻�1
* ����λ���Ѿ������򷵻�2
* ���������λ����Ч������0
*/

int position(int* x , int* y ) {
	if (*x < 0 || *x >= 15 || *y < 0 || *y >= 15) {
		return 1;
	}
	else if (Record[*x][*y] == 1 || Record[*x][*y] == 2) {
		return 2;
	}
	else {
		return 0;
	}
}

//---------�ж�����Ƿ��ʤ�����Ƿ��������������------------//
/*
* ����һ��ʤ�����򷵻�1
* ����ƽ�֣���������Ϊ���̵������򷵻�-1
* ���򷵻�0
*/
int Win(int* x, int* y, int player ) {
	int i, j, k;
	int number = 0;
	int Sumchess = 0;
	//i j���Կ��������жϸ����Ƕȵ��������
	for (i = -1; i <= 1; i++) {
		for (j = -1; j <= 1; j++) {
			if (i != 0 || j != 0) {
				//ͳ�����������߷������ͳ������������
				for (k = 1; k < 5; k++) {
					if (*x + k * i >= 0 && *y + k * i <= 14
						&& *y + k * j >= 0 && *y + k * j <= 14
						&& Record[*x + k * i][*y + k * j] == player) {
						number++;
					}
					else {
						break;
					}
				}
				//ͳ����һ�������������߷������ͳ������������
				for (k = -1; k > -5; k--) {
					if (*x + k * i >= 0 && *y + k * i <= 14
						&& *y + k * j >= 0 && *y + k * j <= 14
						&& Record[*x + k * i][*y + k * j] == player) {
						number++;
					}
					else {
						break;
					}
				}
				if (number >= 4) {
					return 1;
				}
				else {
					number = 0;
				}
			}
		}
	}
	for (i = 0; i < 15; i++) {
		for (j = 0; j < 15; j++) {
			if (Record[i][j] == 1 || Record[i][j] == 2) {
				Sumchess++;
			}
		}
	}
	if (Sumchess >= MAX_SQUARE * MAX_SQUARE) {
		return -1;
	}
	return 0;
}
//--------����-------//
void Retract(int& x1, int& y1 , int& x2, int& y2, int value[MAX_SQUARE][MAX_SQUARE])
{
	if (Sum >= 1)
	{
		Sum--;
	}
	if ((x1 == -1) && (y1 == -1) && (x2 == -1) && (y2 == -1))
	{
		printf("��ǰ�޷����壬������û������\n");
		printf("�밴���������......");
		system("pause>nul");
	}
	else if (Renum >= 6)
	{
		printf("���峬��6�Σ�Ϊ�˹�ƽ���������ٴλ��壡\n");
		printf("�밴���������......");
		system("pause>nul");
	}else
	{
		Renum++;
		if (x1 == 0 && y1 == 0)
		{
			value[x1][y1] = 0;
			Record[x1][y1] = 0;
		}
		else if (x1 == 0 && y1 == 14)
		{
			value[x1][y1] = 2;
			Record[x1][y1] = 0;
		}
		else if (x1 == 14 && y1 == 0)
		{
			value[x1][y1] = 5;
			Record[x1][y1] = 0;
		}
		else if (x1 == 14 && y1 == 14)
		{
			value[x1][y1] = 8;
			Record[x1][y1] = 0;
		}
		else if (x1 == 14 && (y1 > 0 && y1 < 14))
		{
			value[x1][y1] = 6;
			Record[x1][y1] = 0;
		}
		else if (y1 == 14 && (x1 > 0 && x1 < 14))
		{
			value[x1][y1] = 7;
			Record[x1][y1] = 0;
		}
		else if (x1 == 0 && (y1 > 0 && y1 < 14))
		{
			value[x1][y1] = 1;
			Record[x1][y1] = 0;
		}
		else if (y1 == 0 && (x1 > 0 && x1 < 14))
		{
			value[x1][y1] = 3;
			Record[x1][y1] = 0;
		}
		else
		{
			value[x1][y1] = 4;
			Record[x1][y1] = 0;
		}
		if (x2 == 0 && y2 == 0)
		{
			value[x2][y2] = 0;
			Record[x2][y2] = 0;
		}
		else if (x2 == 0 && y2 == 14)
		{
			value[x2][y2] = 2;
			Record[x2][y2] = 0;
		}
		else if (x2 == 14 && y2 == 0)
		{
			value[x2][y2] = 5;
			Record[x2][y2] = 0;
		}
		else if (x2 == 14 && y2 == 14)
		{
			value[x2][y2] = 8;
			Record[x2][y2] = 0;
		}
		else if (x2 == 14 && (y2 > 0 && y2 < 14))
		{
			value[x2][y2] = 6;
			Record[x2][y2] = 0;
		}
		else if (y2 == 0 && (x2 > 0 && x2 < 14))
		{
			value[x2][y2] = 3;
			Record[x2][y2] = 0;
		}
		else if (x2 == 0 && (y2 > 0 && y2 < 14))
		{
			value[x2][y2] = 1;
			Record[x2][y2] = 0;
		}
		else if (y2 == 14 && (x2 > 0 && x2 < 14))
		{
			value[x2][y2] = 7;
			Record[x2][y2] = 0;
		}
		else
		{
			value[x2][y2] = 4;
			Record[x2][y2] = 0;
		}
		printf("ÿ��������������6�Σ������ֻ�ܻص���һ����\n");
		printf("�밴���������......");
		system("pause>nul");
	}
}

//--------------�����˵ĵ�һ������----------//
void ChessOne(int& x, int& y, int value[MAX_SQUARE][MAX_SQUARE]) {
	int i, j;
	srand((unsigned)time(NULL));
	for (i = 0; i < MAX_SQUARE; i++) {
		for (j = 0; j < MAX_SQUARE; j++) {
			if (Record[i][j] == 1) {
				int lx = rand() % 8;
				if (lx == 0) {
					x = i + 1;
					y = j + 1;
					if (position(&x, &y) == 0) {
						break;
					}
				}
				else if (lx == 1) {
					x = i + 1;
					y = j - 1;
					if (position(&x, &y) == 0) {
						break;
					}
				}
				else if (lx == 2) {
					x = i + 1;
					y = j ;
					if (position(&x, &y) == 0) {
						break;
					}
				}
				else if (lx == 3) {
					x = i ;
					y = j + 1;
					if (position(&x, &y) == 0) {
						break;
					}
				}
				else if (lx == 4) {
					x = i ;
					y = j-1 ;
					if (position(&x, &y) == 0) {
						break;
					}
				}
				else if (lx == 5) {
					x = i - 1 ;
					y = j ;
					if (position(&x, &y) == 0) {
						break;
					}
				}
				else if (lx == 6) {
					x = i - 1;
					y = j + 1;
					if (position(&x, &y) == 0) {
						break;
					}
				}
				else {
					x = i - 1;
					y = j - 1 ;
					if (position(&x, &y) == 0) {
						break;
					}
				}
			}
		}
	}

}
void ChessScore() {
	int x, y, i, j, k;
	int number1 = 0, number2 = 0;
	int empty = 0;
	memset(Score, 0, sizeof(Score));
	for (x = 0; x < MAX_SQUARE; x++)
	{
		for (y = 0; y < MAX_SQUARE; y++)
		{
			if (Record[x][y] == 0)
			{
				for (i = -1; i <= 1; i++)
				{
					for (j = -1; j <= 1; j++)
					{
						if (i != 0 || j != 0)
						{
							for (k = 1; k <= 4; k++)
							{
								if (x + k * i >= 0 && x + k * i <= 14 
									&& y + k * j >= 0 && y + k * j <= 14
									&& Record[x + k * i][y + k * j] == 1) 
								{ number1++; }
								else if (Record[x + k * i][y + k * j == 0]) {
									empty++;
									break;
								}
								else {
									break;
								}
							}
							for (k = -1; k >= -4; k--)
							{
								if (x + k * i >= 0 && x + k * i <= 14
									&& y + k * j >= 0 && y + k * j <= 14
									&& Record[x + k * i][y + k * j] == 1)
								{
									number1++;
								}
								else if (Record[x + k * i][y + k * j == 0]) {
									empty++;
									break;
								}
								else {
									break;
								}
							}
							if (number1 == 1) {
								Score[x][y] += 1;
							}
							else if (number1 == 2) {
								if (empty == 1) {
									Score[x][y] += 5;
								}
								else if (empty == 2) {
									Score[x][y] += 10;
								}
							}
							else if (number1 == 3) {
								if (empty == 1) {
									Score[x][y] += 20;
								}
								else if (empty == 2) {
									Score[x][y] += 100;
								}
							}
							else if (number1 >= 4) {								
									Score[x][y] += 1000;	
								
								
							}
							empty = 0;
							for (k = 1; k <= 4; k++) {
								if (x + k * i >= 0 && x + k * i <= 14
									&& y + k * j >= 0 && y + k * j <= 14
									&& Record[x + k * i][y + k * j] == 2) {
									number2++;
								}
								else if (Record[x + k * i][y + k * j] == 0) {
									empty++; 
									break;
								}
								else {
									break;
								}
							}
							for (k = -1; k >= -4; k--)
							{
								if (x + k * i >= 0 && x + k * i <= 14 
									&& y + k * j >= 0 && y + k * j <= 14 
									&& Record[x + k * i][y + k * j] == 2) {
									number2++; 
								}
								else if (Record[x + k * i][y + k * j ]== 0) { 
									empty++; 
									break; 
								}
								else { 
									break;
								}
							}
							if (number2 == 0) { 
								Score[x][y] += 1;
							}
							else if (number2 == 1) {
								Score[x][y] += 2;
							}
							else if (number2 == 2)
							{
								if (empty == 1) { 
									Score[x][y] += 8; 
								}
								else if (empty == 2) { 
									Score[x][y] += 30; 
								}
							}
							else if (number2 == 3)
							{
								if (empty == 1) { 
									Score[x][y] += 50;
								}
								else if (empty == 2) { 
									Score[x][y] += 200; }
							}
							else if (number2 >= 4) { 
								Score[x][y] += 10000; 
							}
							number1 = 0;
							number2 = 0;
							empty = 0;
							
						}
					}
				}
			}
		}
	}
}
void Findscore(int& x, int& y) {
	srand((unsigned)time(NULL));
	int i, j, x1, x2, y1, y2, lx;
	int max = 0;
	ChessScore();
	for (i = 0; i < MAX_SQUARE; i++) {
		for (j = 0; j < MAX_SQUARE; j++) {
			if (Score[i][j] > max) {
				max = Score[i][j];
				x1 = i;
				y1 = j;
			}
		}
	}
	x2 = x1;
	y2 = y1;
	for (i = 0; i < MAX_SQUARE; i++) {
		for (j = 0; j < MAX_SQUARE; j++) {
			if (Score[i][j] == max && i!= x2 && j != y2) {
				lx = rand() % 10;
				if (lx < 5) {
					x2 = i;
					y2 = j;
					break;
				}
			}
		}
	}
	if (x2 != x1 || y2 != y1) {
		lx = rand() % 10;
		if (lx > 6) {
			x = x1;
			y = y1;
		}
		else {
			x = x2;
			y = y2;
		}
	}
	else {
		x = x1;
		y = y1;
	}
	max = 0;
	Record[x][y] = 2;
}
//----------���������Ӻ���-----------//
void Robot(int* x, int* y, int value[MAX_SQUARE][MAX_SQUARE]) {
	int flag = 1;
	if (Sum == 1) {
		while (flag) {
			ChessOne(*x, *y, value);
			if (position(x, y) == 0) {
				flag = 0;
			}
		}
		Record[*x][*y] = 2;
	}
	else {
		Findscore(*x, *y);
	}
}

//----------����ģʽ-----------//
void AIGame(int value[MAX_SQUARE][MAX_SQUARE]) {
	printf("��ѡ���˵���ģʽ\n");
	printf("�밴���������......");
	setScr();
	system("title ������-����ģʽ");
	int x = -1, y = -1;
	int x1 = -1, y1 = -1 , x2 = -1 , y2 = -1;
	int player = 0;
	Sum = 0;
	Renum = 0;

	//��ӡ��ʼ����
	PrintBoard(&x, &y, value, player);//��ӡ������
	memset(Record, 0, sizeof(Record));//�Ȱ����������
	int flag = 1;
	while (flag) {
		printf("����������\n");
		printf("��[���]��������[-1 -1����ʾ����]");
		scanf("%d %d", &x, &y);
		int check = position(&x, &y);
		if (x == -1 && y == -1) {
			//����
			Retract(x1 , y1 , x2 , y2 , value);
			PrintBoard(&x, &y, value, 0);//��ӡ����������
			flag = 1;
		}
		else if (check == 1) {
			printf("�Բ�������������겻��ȷ������������!\n");
			continue;
		}
		else if (check == 2) {
			printf("������������Ѿ����ӣ����������룡\n");
		}
		else {
			PrintBoard(&x, &y, value, 1);
			Record[x][y] = 1;
			x1 = x;
			y1 = y;
			Sum++;
			if (Win(&x, &y, 1) == 1) {
				printf("��ϲ[���]���ʤ��\n");
				printf("������Ϸ�����������������......\n");
				system("pause>nul2>nul");
				Victory(3);
				flag = 0;
			}
			else if (Win(&x, &y, 1) == -1) {
				printf("�ѷֳ�ʤ������������\n");
				printf("������Ϸ�����������������......\n");
				system("pause>nul 2>nul");
				Victory(5);
				flag = 0;
			}
			else if (Win(&x, &y, 1) == 0) {
				Robot(&x, &y, value);
				PrintBoard(&x, &y, value, 2);
				x2 = x;
				y2 = y;
				printf("�����������%d\n", Sum);
				printf("[����]������������[X:%d] [Y:%d]\n", x, y);
				if (Win(&x, &y, 2) == 1) {
					printf("���ź������Ի�ʤ�ˣ�\n");
					printf("������Ϸ������������λ�ü���......\n");
					system("pause>nul2>nul");
					Victory(4);
					flag = 0;
				}
				else if (Win(&x, &y, 2) == -1) {
					printf("�ѷֳ�ʤ��������������\n");
					printf("������Ϸ������������λ�ü���......\n");
					system("pause>nul2>nul");
					Victory(5);
					flag = 0;
				}
				else {
					flag = 1;
				}

			}
		}
	}
	
}

//-----------˫��ģʽ-------------//
void doubleGame(int value[MAX_SQUARE][MAX_SQUARE]) {

	printf("��ѡ����˫��ģʽ\n" );
	printf("�밴���������......");
	setScr();
	system("title ������-˫��ģʽ");
	
	int x = -1 , y = -1 ;
	int player = 0;
	//��ӡ��ʼ����
	PrintBoard(&x , &y , value , player);
	memset(Record, 0, sizeof(Record));
	int flag = 1;
	while (flag) {
		//�ж�Ӧ�����ĸ���Ҹ���
		//�ж���������Ƿ�Ϸ���������Ϸ�������쳣���������������
		//�ж��Ƿ�ʤ����ʤ���������������������ѭ��
		player = nextPlayer();
		printf("��[���%d]�������꣨�ÿո������:" , player);
		scanf("%d %d" , &x , &y);
		int check = position(&x, &y);
		if (check == 1) {
			printf("�Բ�������������겻��ȷ������������!\n");
			flag = 1;
			continue;
		}
		else if (check == 2) {
			printf("������������Ѿ����ӣ����������룡\n");
			flag = 1;
		}
		else {
			PrintBoard(&x, &y, value, player);
			Record[x][y] = player;
			printf("���[%d]�����������ˣ�[X:%d] [Y:%d]\n" , player , x , y);
			//�ж�����Ƿ��ʤ�����ǻ�ʤ�򷵻�1
			//����ƽ���򷵻�-1
			//���򷵻�0
			int result = Win(&x, &y, player);
			if (result == -1) {
				printf("��Ϸ�����ˣ�û�ֳ�ʤ��������������\n");
				printf("������Ϸ�����������������......\n");
				system("pause>nul2>nul");
				Victory(5);
				flag = 0;
			}
			else if (result == 1) {
				printf("��ϲ[���%d]Ӯ��ʤ����\n",player);
				printf("������Ϸ�����������������......\n");
				system("pause>nul2>nul");
				Victory(player);
				flag = 0;
			}
			else {
				flag = 1;
			}

		}
	}
}

void endGame() {
	system("cls");
	system("c:\\windows\\system32\\mode.com con cols=43 lines=20");
	system("color 8f");
	printf("��                                     ��\n");
	printf("��         ��л��ʹ�ã�������          ��\n");
	printf("��                                     ��\n");
	printf("��[��Ϸ����]:������ ����ٻ �߳��      ��\n");
	printf("��[QQ]:1596957557                      ��\n");
	printf("��[˵��]:��Ϸ���棬��л����ʹ�ã�      ��\n");
	printf("��                                     ��\n");
	printf("��л����ʹ�ã���������˳�����\n");
	system("pause>nul>nul 2>nul");
}

void notice(int value[MAX_SQUARE][MAX_SQUARE]) {
	system("cls");
	system("c:\\windows\\system32\\mode.com con cols=43 lines=20");
	system("color 8f");
	printf("��                                       ��\n");
	printf("��           ��л��ʹ�ã�������          ��\n");
	printf("��                                       ��\n");
	printf("��[�˻�]: �������������                 ��\n");
	printf("��[��Ҷ�ս]:˫�˶�ս                    ��\n");
	printf("��[�ر���ʾ]:����;�˳�����Ctrl+C���жϣ���\n");
	printf("��                                       ��\n");
	printf("��л����ʹ�ã���������˳�����\n");
	system("pause>nul>nul 2>nul");
}

typedef void(*fun)(int value[MAX_SQUARE][MAX_SQUARE]);



int main() {
	//Ĭ������
	int Default[MAX_SQUARE][MAX_SQUARE] = {
						   0,1,1,1,1,1,1,1,1,1,1,1,1,1,2,
						   3,4,4,4,4,4,4,4,4,4,4,4,4,4,7,
						   3,4,4,4,4,4,4,4,4,4,4,4,4,4,7,
						   3,4,4,4,4,4,4,4,4,4,4,4,4,4,7,
						   3,4,4,4,4,4,4,4,4,4,4,4,4,4,7,
						   3,4,4,4,4,4,4,4,4,4,4,4,4,4,7,
						   3,4,4,4,4,4,4,4,4,4,4,4,4,4,7,
						   3,4,4,4,4,4,4,4,4,4,4,4,4,4,7,
						   3,4,4,4,4,4,4,4,4,4,4,4,4,4,7,
						   3,4,4,4,4,4,4,4,4,4,4,4,4,4,7,
						   3,4,4,4,4,4,4,4,4,4,4,4,4,4,7,
						   3,4,4,4,4,4,4,4,4,4,4,4,4,4,7,
						   3,4,4,4,4,4,4,4,4,4,4,4,4,4,7,
						   3,4,4,4,4,4,4,4,4,4,4,4,4,4,7,
						   5,6,6,6,6,6,6,6,6,6,6,6,6,6,8 };
	//���Ų������Ӷ��ڲ��ϱ仯������
	int value[MAX_SQUARE][MAX_SQUARE] = { 0 };
	fun funcs[] = {
		NULL,
		AIGame,
		doubleGame,
		notice
	};
	while (1) {
		int choice = menu();
		if (choice < 1 && choice > sizeof(funcs)/sizeof(funcs[1])){
			printf("�ܱ�Ǹ���������������������");
			continue;
		}else if (choice == 4) {
			endGame();
			break;
		}
		else {
			empty(value, Default);
			funcs[choice](value);
		}	
	}
	return 0;
}
 