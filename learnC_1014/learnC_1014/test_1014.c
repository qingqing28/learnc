#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<windows.h>

int main1() {
	//编写代码，演示多个字符从两端移动，向中间汇聚
	/*char str1[] = "I love gaochennan";
	char str2[] = "#################";

	int left = 0;
	int right = strlen(str2) - 1;
	printf("%s\n", str2);
	while (left <= right) {
		Sleep(500);
		str2[left] = str1[left];
		str2[right] = str1[right];
		left++;
		right--;
		system("cls");
		printf("%s\n" , str2);
	}*/


	//love 和gaochennan同时打完
	/*char str1[] = "I love gaochennan";
	char str2[17] = "#################";
	
	str2[0] = str1[0];
	int left = 1;
	int right = strlen(str2) - 1;
	printf("%s\n", str2);
	while (left <= right) {
		Sleep(500);
		str2[left] = str1[left];
		str2[right] = str1[right];
		left++;
		right--;
		str2[right] = str1[right];
		right--;
		system("cls");
		printf("%s\n", str2);
	}
	int str4 = { "\0" };
	int k = 1;
	while (k) {
		if (k % 2 == 0) {
			Sleep(500);
			system("cls");
			printf("%s", str4);
		}
		else {
			Sleep(500);
			system("cls");
			printf("%s", str2);
		}
		k++;
	}*/


	//模拟用户登录，最多输入三次错误
	/*char input[20] = { 0 };
	char password[20] = "888888";
	for (int i = 0; i < 3; i++) {
		printf("请输入密码：");
		scanf("%s", input);
		if (strcmp(input, password) == 0) {
			printf("登录成功！\n");
			break;
		}
		else {
			printf("登录失败！\n");
		}
	}*/
	
	//在一个普通数组中查找具体的某个数字n，返回n对应下标值
	/*int arr[] = { 9 , 6 , 3 , 7 , 2 , 5 , 1 };
	int toFind = 0;
	int i;
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		if (arr[i] == toFind) {
			printf("找到了tofind的结果，下标为：%d\n", i);
			break;
		}
	}
	if (i >= sizeof(arr) / sizeof(arr[0])) {
		printf("该数组中不存在要查找的数\n");
	}*/

	//在升序数组中查找具体的某个数字n，返回对用数组的下标
	//使用折半查找法，二分查找法
	int arr[] = { 1 , 2 , 3 , 4 , 5 , 6 , 7 };
	int toFind = 0;
	//使用[left , right]来表示要查找的区间
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]);
	//比较中间值与要查找值，删去半个区间
	//如果中间值比要查找的值小，则下一个要查找的区间为[mid+1 , right]
	//如果中间值比要查找的值大，则下一个要查找的区间为[left , mid - 1]
	while (left <= right) {
		int mid = (left + right) / 2;
		if (arr[mid] < toFind) {
			left = mid + 1;
		}
		else if (arr[mid] > toFind) {
			right = mid - 1;
		}
		else {
			printf("找到要查找的值，其下标为：%d\n", mid);
			break;
		}
	}
	if (right < left) {
		printf("该数组中不存在要查找的数\n");
	}
	
	system("pause");
	return 0;
}