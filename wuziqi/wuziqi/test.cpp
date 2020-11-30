#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<string.h>
#include<time.h>

#define MAX_SQUARE 15
//特殊字符，用作打印棋盘和棋子
static const char ch[11][4] = {"┌","┬","┐","├","┼","└","┴","┤","┘","●","○" };
//记录每位玩家下棋位置
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
	system("title 五子棋游戏");
	printf("┌  ─  ─  ─  ─  ─  ─  ─  ─  ─  ─  ─  ┐\n");
	printf("│            简单五子棋             │\n");
	printf("│[1]、单机游戏                      │\n");
	printf("│[2]、双人游戏                      │\n");
	printf("│[3]、游戏介绍                      │\n");
	printf("│[4]、退出                          │\n");
	printf("└  ─  ─  ─  ─  ─  ─  ─  ─  ─  ─  ─  ┘\n");
	printf("请选择：");
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
		printf("┌                                     ┐\n");
		printf("│        恭喜玩家1[黑棋]得胜！        │\n");
		printf("│                                     │\n");
		printf("│[胜利玩家]:玩家1                     │\n");
		printf("│[所属棋子]:黑子                      │\n");
		printf("│[祝福]:恭喜您赢得了胜利！            │\n");
		printf("│                                     │\n");
		printf("└                                     ┘\n");
	}
	else if (number == 2) {
		system("color 6f");
		printf("┌                                     ┐\n");
		printf("│        恭喜玩家2[白棋]得胜！        │\n");
		printf("│                                     │\n");
		printf("│[胜利玩家]:玩家2                     │\n");
		printf("│[所属棋子]:白子                      │\n");
		printf("│[祝福]:恭喜您赢得了胜利！            │\n");
		printf("│                                     │\n");
		printf("└                                     ┘\n");
	}
	else if (number == 3) {
		system("color 9f");
		printf("┌                                     ┐\n");
		printf("│        恭喜您获得胜利得胜！         │\n");
		printf("│                                     │\n");
		printf("│[胜利玩家]:自己                      │\n");
		printf("│[所属棋子]:黑子                      │\n");
		printf("│[祝福]:恭喜您赢得了胜利！            │\n");
		printf("│                                     │\n");
		printf("└                                     ┘\n");
	}
	else if (number == 4) {
		system("color Bf");
		printf("┌                                     ┐\n");
		printf("│           很遗憾您输了！            │\n");
		printf("│                                     │\n");
		printf("│[胜利玩家]:电脑                      │\n");
		printf("│[所属棋子]:白子                      │\n");
		printf("│[祝福]:很遗憾您输了                  │\n");
		printf("│                                     │\n");
		printf("└                                     ┘\n");
	}
	else {
		system("color Cf");
		printf("┌                                     ┐\n");
		printf("│                                     │\n");
		printf("│[胜利玩家]:无（平局）                │\n");
		printf("│[所属棋子]:黑色或白色                │\n");
		printf("│[祝福]:棋盘竟然出现了平局！          │\n");
		printf("│                                     │\n");
		printf("└                                     ┘\n");
	}
	printf("请按任意键继续......");
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

//------出棋并打印棋盘-----//
/*
*	若player为玩家1，则在[x,y]的位置上下玩家1的棋；
*   若player为玩家2，则在[x,y]的位置上下玩家2的棋；
*   若player不为玩家1也不为玩家2，则执行下棋行动；
*   打印棋盘
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
//计算两个玩家的棋数，如果1号玩家与2号玩家棋数一样或1号玩家棋数少，
//则该1号玩家下棋，否则应该2号玩家下棋
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

//-------判断落子位置是否合理--------//
/*
* 坐标不在棋盘上则返回1
* 坐标位置已经落子则返回2
* 输入坐标的位置有效，返回0
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

//---------判断玩家是否获胜，即是否有五子连接情况------------//
/*
* 若玩家获得胜利，则返回1
* 若是平局，即下子数为棋盘点数，则返回-1
* 否则返回0
*/
int Win(int* x, int* y, int player ) {
	int i, j, k;
	int number = 0;
	int Sumchess = 0;
	//i j可以控制棋盘判断各个角度的连子情况
	for (i = -1; i <= 1; i++) {
		for (j = -1; j <= 1; j++) {
			if (i != 0 || j != 0) {
				//统计沿棋子射线方向进行统计连续落子数
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
				//统计另一方向沿棋子射线方向进行统计连续落子数
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
//--------悔棋-------//
void Retract(int& x1, int& y1 , int& x2, int& y2, int value[MAX_SQUARE][MAX_SQUARE])
{
	if (Sum >= 1)
	{
		Sum--;
	}
	if ((x1 == -1) && (y1 == -1) && (x2 == -1) && (y2 == -1))
	{
		printf("当前无法悔棋，棋盘上没有棋子\n");
		printf("请按任意键继续......");
		system("pause>nul");
	}
	else if (Renum >= 6)
	{
		printf("悔棋超过6次，为了公平，您不能再次悔棋！\n");
		printf("请按任意键继续......");
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
		printf("每个人最多允许悔棋6次，且最多只能回到上一步！\n");
		printf("请按任意键继续......");
		system("pause>nul");
	}
}

//--------------机器人的第一次落子----------//
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
//----------机器人落子函数-----------//
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

//----------单机模式-----------//
void AIGame(int value[MAX_SQUARE][MAX_SQUARE]) {
	printf("您选择了单机模式\n");
	printf("请按任意键继续......");
	setScr();
	system("title 五子棋-单机模式");
	int x = -1, y = -1;
	int x1 = -1, y1 = -1 , x2 = -1 , y2 = -1;
	int player = 0;
	Sum = 0;
	Renum = 0;

	//打印初始棋盘
	PrintBoard(&x, &y, value, player);//打印空棋盘
	memset(Record, 0, sizeof(Record));//先把落子数清空
	int flag = 1;
	while (flag) {
		printf("黑棋代表玩家\n");
		printf("请[玩家]输入坐标[-1 -1键表示悔棋]");
		scanf("%d %d", &x, &y);
		int check = position(&x, &y);
		if (x == -1 && y == -1) {
			//悔棋
			Retract(x1 , y1 , x2 , y2 , value);
			PrintBoard(&x, &y, value, 0);//打印悔棋后的棋面
			flag = 1;
		}
		else if (check == 1) {
			printf("对不起，您输入的坐标不正确，请重新输入!\n");
			continue;
		}
		else if (check == 2) {
			printf("您输入的坐标已经落子，请重新输入！\n");
		}
		else {
			PrintBoard(&x, &y, value, 1);
			Record[x][y] = 1;
			x1 = x;
			y1 = y;
			Sum++;
			if (Win(&x, &y, 1) == 1) {
				printf("恭喜[玩家]获得胜利\n");
				printf("本次游戏结束，按任意键继续......\n");
				system("pause>nul2>nul");
				Victory(3);
				flag = 0;
			}
			else if (Win(&x, &y, 1) == -1) {
				printf("难分出胜负，都很厉害\n");
				printf("本次游戏结束，按任意键继续......\n");
				system("pause>nul 2>nul");
				Victory(5);
				flag = 0;
			}
			else if (Win(&x, &y, 1) == 0) {
				Robot(&x, &y, value);
				PrintBoard(&x, &y, value, 2);
				x2 = x;
				y2 = y;
				printf("玩家棋子数：%d\n", Sum);
				printf("[电脑]的棋子落在了[X:%d] [Y:%d]\n", x, y);
				if (Win(&x, &y, 2) == 1) {
					printf("很遗憾，电脑获胜了！\n");
					printf("本次游戏结束，按任意位置继续......\n");
					system("pause>nul2>nul");
					Victory(4);
					flag = 0;
				}
				else if (Win(&x, &y, 2) == -1) {
					printf("难分出胜负，都很厉害！\n");
					printf("本次游戏结束，按任意位置继续......\n");
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

//-----------双人模式-------------//
void doubleGame(int value[MAX_SQUARE][MAX_SQUARE]) {

	printf("您选择了双人模式\n" );
	printf("请按任意键继续......");
	setScr();
	system("title 五子棋-双人模式");
	
	int x = -1 , y = -1 ;
	int player = 0;
	//打印初始棋盘
	PrintBoard(&x , &y , value , player);
	memset(Record, 0, sizeof(Record));
	int flag = 1;
	while (flag) {
		//判断应该是哪个玩家该走
		//判断玩家落子是否合法，如果不合法则进行异常处理，否则进行落子
		//判断是否胜出，胜出或和棋则结束，否则继续循环
		player = nextPlayer();
		printf("请[玩家%d]输入坐标（用空格隔开）:" , player);
		scanf("%d %d" , &x , &y);
		int check = position(&x, &y);
		if (check == 1) {
			printf("对不起，您输入的坐标不正确，请重新输入!\n");
			flag = 1;
			continue;
		}
		else if (check == 2) {
			printf("您输入的坐标已经落子，请重新输入！\n");
			flag = 1;
		}
		else {
			PrintBoard(&x, &y, value, player);
			Record[x][y] = player;
			printf("玩家[%d]的棋子落在了：[X:%d] [Y:%d]\n" , player , x , y);
			//判断玩家是否获胜，若是获胜则返回1
			//若是平局则返回-1
			//否则返回0
			int result = Win(&x, &y, player);
			if (result == -1) {
				printf("游戏和棋了，没分出胜负，都很厉害！\n");
				printf("本次游戏结束，按任意键继续......\n");
				system("pause>nul2>nul");
				Victory(5);
				flag = 0;
			}
			else if (result == 1) {
				printf("恭喜[玩家%d]赢得胜利！\n",player);
				printf("本次游戏结束，按任意键继续......\n");
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
	printf("┌                                     ┐\n");
	printf("│         感谢您使用：五子棋          │\n");
	printf("│                                     │\n");
	printf("│[游戏制作]:彭晴晴 唐亚倩 高晨楠      │\n");
	printf("│[QQ]:1596957557                      │\n");
	printf("│[说明]:游戏界面，感谢您的使用！      │\n");
	printf("└                                     ┘\n");
	printf("感谢您的使用！按任意键退出……\n");
	system("pause>nul>nul 2>nul");
}

void notice(int value[MAX_SQUARE][MAX_SQUARE]) {
	system("cls");
	system("c:\\windows\\system32\\mode.com con cols=43 lines=20");
	system("color 8f");
	printf("┌                                       ┐\n");
	printf("│           感谢您使用：五子棋          │\n");
	printf("│                                       │\n");
	printf("│[人机]: 计算机不够智能                 │\n");
	printf("│[玩家对战]:双人对战                    │\n");
	printf("│[特别提示]:若中途退出，按Ctrl+C可中断！│\n");
	printf("└                                       ┘\n");
	printf("感谢您的使用！按任意键退出……\n");
	system("pause>nul>nul 2>nul");
}

typedef void(*fun)(int value[MAX_SQUARE][MAX_SQUARE]);



int main() {
	//默认棋盘
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
	//随着不断落子而在不断变化的棋盘
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
			printf("很抱歉，您输出有误，请重新输入");
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
 