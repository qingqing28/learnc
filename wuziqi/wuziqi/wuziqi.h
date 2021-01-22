#define MAX_SQUARE 15
//�����ַ���������ӡ���̺�����
static const char ch[11][4] = { "��","��","��","��","��","��","��","��","��","��","��" };
//��¼ÿλ�������λ��
static int Record[MAX_SQUARE][MAX_SQUARE] = { 0 };//Record��¼ÿ��λ�����ĸ��������
static int Score[MAX_SQUARE][MAX_SQUARE] = { 0 };//��¼ÿ��λ���������������
//Score�з�ֵԽ����ԽӦ�����ڸ�λ��
static int Sum = 0, Renum = 0;//Sum��ʾ����������,Renum��ʾ��һ������
typedef void(*fun)(int value[MAX_SQUARE][MAX_SQUARE]);


//-------�˵�-------//
int menu();
void endGame();
void empty(int value[MAX_SQUARE][MAX_SQUARE], int Default[MAX_SQUARE][MAX_SQUARE]);
void setScr();

//------������Ϸ------//
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

//-----˫����Ϸ------//
int nextPlayer();
void doubleGame(int value[MAX_SQUARE][MAX_SQUARE]);
