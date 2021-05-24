// KJOSW5658.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

/*
#include "pch.h"
#include <iostream>
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
// #include <algorithm>
// #include <string>

#define SIDES 4
#define MAX_ROTATE 7
#define MAX_N (MAX_ROTATE * SIDES)
#define MAX_NUMS (MAX_ROTATE * MAX_ROTATE)

// using namespace std;

int n = 0;
int k = 0;
int dec_ans = 0;
int r = 0;
int num_index = 0;

///*
char digit_list[MAX_N + MAX_ROTATE + 1] = { '\0' };
char num_list[MAX_NUMS][MAX_ROTATE + 1] = { '\0' };
char hex_ans[MAX_ROTATE + 1] = { '\0' };
//*/

/*
string digit_list = '\0';
string num_list[MAX_NUMS] = { '\0' };
*/

void num_make()
{
	int start_index = 0;

	num_index = 0;

	// rotate 횟수만큼 확인하고 돌린다
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < SIDES; j++)
		{
			start_index = i + (j * r);

			for (int k = 0; k < r; k++)
			{
				// printf("%3d", start_index + k);

				num_list[num_index][k] = digit_list[start_index + k];
			}

			num_index += 1;

			// printf("\n");
		}
	}

	/*
	for (int i = 0; i < num_index; i++)
	{
		printf("%s\n", num_list[i]);
	}
	*/

	return;
}

void num_sort()
{
	char tmp[MAX_ROTATE + 1] = { '\0' };

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (strcmp(num_list[j], num_list[j + 1]) < 0)
			{
				strcpy(tmp, num_list[j]);
				strcpy(num_list[j], num_list[j + 1]);
				strcpy(num_list[j + 1], tmp);
			}
		}
	}

	/*
	for (int i = 0; i < num_index; i++)
	{
		printf("%s\n", num_list[i]);
	}
	*/

	return;
}

void num_find()
{
	int find_index = 0;

	if (k == 1)
	{
		strcpy(hex_ans, num_list[0]);

		// printf("hex_ans = %s\n", hex_ans);

		return;
	}
	else
	{
		for (int i = 1; i < num_index; i++)
		{
			// printf("%s %s\n", num_list[i - 1], num_list[i]);

			if (strcmp(num_list[i - 1], num_list[i]) != 0)
			{
				find_index += 1;
			}

			// printf("find_index = %d, i = %d\n\n", find_index, i);

			if (find_index == k - 1)
			{
				strcpy(hex_ans, num_list[i]);

				// printf("hex_ans = %s\n", hex_ans);

				return;
			}
		}
	}

	return;
}

void hex_to_dec()
{
	int cipher = (int)(pow(16, r - 1));
	int digit = 0;

	for (int i = 0; i < r; i++)
	{
		if (hex_ans[i] >= 'A')
		{
			digit = ((int)(hex_ans[i] - 'A') + 10);
		}
		else
		{
			digit = (int)(hex_ans[i] - '0');
		}

		// printf("cipher = %d, digit = %d\n", cipher, digit);

		dec_ans += (cipher * digit);

		cipher /= 16;
	}

	return;
}

int main()
{
    // std::cout << "Hello World!\n"; 

	int t = 0;

	scanf("%d", &t);

	// printf("t = %d\n", t);

	for (int i = 0; i < t; i++)
	{
		n = 0;
		k = 0;
		dec_ans = 0;
		r = 0;
		num_index = 0;

		///*
		for (int j = 0; j < MAX_N + 1; j++)
		{
			digit_list[j] = '\0';
		}

		for (int row = 0; row < MAX_NUMS; row++)
		{
			for (int col = 0; col < MAX_ROTATE + 1; col++)
			{
				num_list[row][col] = '\0';
			}
		}
		//*/

		/*
		digit_list = '\0';

		for (int j = 0; j < MAX_NUMS; j++)
		{
			num_list[j] = '\0';
		}
		*/

		scanf("%d %d", &n, &k);

		r = n / 4;

		// printf("n = %d, k = %d\n", n, k);

		/*
		for (int j = 0; j < n; j++)
		{
			scanf("%c", &digit_list[j]);
		}
		*/

		scanf("%s", &digit_list);

		for (int j = 0; j < r; j++)
		{
			digit_list[j + n] = digit_list[j];
		}

		/*
		for (int j = 0; j < n; j++)
		{
			printf("%c ", digit_list[j]);
		}

		printf("\n");
		*/

		// printf("%s\n", digit_list);

		num_make();

		num_sort();

		num_find();

		hex_to_dec();

		printf("#%d %d\n", i + 1, dec_ans);
	}

	return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
