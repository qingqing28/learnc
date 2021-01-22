#define MAX_SQUARE 15
//特殊字符，用作打印棋盘和棋子
static const char ch[11][4] = { "┌","┬","┐","├","┼","└","┴","┤","┘","●","○" };
//记录每位玩家下棋位置
static int Record[MAX_SQUARE][MAX_SQUARE] = { 0 };//Record记录每个位置由哪个玩家下棋
static int Score[MAX_SQUARE][MAX_SQUARE] = { 0 };//记录每个位置下棋的迫切需求
//Score中分值越大则越应该下在该位置
static int Sum = 0, Renum = 0;//Sum表示玩家下棋个数,Renum表示玩家悔棋次数
typedef void(*fun)(int value[MAX_SQUARE][MAX_SQUARE]);


//-------菜单-------//
int menu();
void endGame();
void empty(int value[MAX_SQUARE][MAX_SQUARE], int Default[MAX_SQUARE][MAX_SQUARE]);
void setScr();

//------单机游戏------//
void Robot(int* x, int* y, int value[MAX_SQUARE][MAX_SQUARE]);
void AIGame(int value[MAX_SQUARE][MAX_SQUARE]);
void PrintBoard(int* x, int* y, int value[MAX_SQUARE][MAX_SQUARE], int player);
int position(int* x, int* y);
void Retract(int& x1, int& y1, int& x2, int& y2, int value[MAX_SQUARE][MAX_SQUARE]);
int Win(int* x, int* y, int player);
void ChessOne(int& x, int& y, int value[MAX_SQUARE][MAX_SQUARE]);
void Findscore(int& x, int& y);
void ChessScore();
void Victory(int number);

//-----双人游戏------//
int nextPlayer();
void doubleGame(int value[MAX_SQUARE][MAX_SQUARE]);
