#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int main()
{
	int c;
	scanf("%d", &c);
	switch (c) {
	default:printf("default"); break;
	case 1:printf("%d", c); break;
	case 2:printf("%d", c); break;
	}
		
	system("pause");
	return 0;
}