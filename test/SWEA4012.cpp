// KJOSW4012.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#define MAX_T 50
#define MAX_N 16
#define INF 1000000000

/*
#include "pch.h"
#include <iostream>
*/

#include <stdio.h>
#include <cmath>

using namespace std;

int t = 0;
int n = 0;
int ans = INF;

int matrix[MAX_N][MAX_N] = { 0 };
int team[MAX_N] = { 0 };

void init()
{
	ans = INF;

	for (int row = 0; row < MAX_N; row++)
	{
		for (int col = 0; col < MAX_N; col++)
		{
			matrix[row][col] = 0;
		}
	}

	for (int i = 0; i < MAX_N; i++)
	{
		team[i] = 0;
	}

	return;
}

void print_matrix()
{
	printf("matrix : \n");

	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; col++)
		{
			printf("%d ", matrix[row][col]);
		}

		printf("\n");
	}

	printf("\n");

	return;
}

void print_team()
{
	printf("team : \n");

	for (int i = 0; i < n; i++)
	{
		printf("%d ", team[i]);
	}

	printf("\n");

	return;
}

int calc_diff(int a, int b)
{
	return abs(a - b);
}

void calc_syn()
{
	int taste_0 = 0;
	int taste_1 = 0;
	int result = 0;

	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; col++)
		{
			// 같지 않은 경우에만
			if (row != col)
			{
				// 고른 쪽
				if ((team[row] == 1) && (team[col] == 1))
				{
					// 맛 더하기
					taste_1 += matrix[row][col];
				}
				// 고르지 않은 쪽
				else if ((team[row] == 0) && (team[col] == 0))
				{
					// 맛 더하기
					taste_0 += matrix[row][col];
				}

				/*
				printf("row = %d, col = %d\n", row, col);
				printf("%d : %d\n", taste_0, taste_1);
				*/
			}
		}
	}

	result = calc_diff(taste_0, taste_1);

	if (result < ans)
	{
		ans = result;
	}

	return;
}

void backtrack(int start, int depth)
{
	// 반으로 나누었으면
	if (depth == n / 2)
	{
		// print_team();

		// 시너지 계산
		calc_syn();

		return;
	}

	for (int i = start; i < n; i++)
	{
		// 고르지 않았다면
		if (team[i] == 0)
		{
			// 골라주고
			team[i] = 1;

			// 완전탐색
			backtrack(i + 1, depth + 1);

			// 초기화
			team[i] = 0;
		}
	}

	return;
}

int main()
{
    // std::cout << "Hello World!\n"; 

	scanf("%d", &t);

	for (int tc = 1; tc <= t; tc++)
	{
		init();

		scanf("%d", &n);

		for (int row = 0; row < n; row++)
		{
			for (int col = 0; col < n; col++)
			{
				scanf("%d", &matrix[row][col]);
			}
		}

		/*
		print_matrix();
		print_team();
		*/

		backtrack(0, 0);

		printf("#%d %d\n", tc, ans);
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
