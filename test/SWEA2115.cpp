// KJOSW2115.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#define MAX_N 10
#define MAX_M 5
#define MAX_C 30
#define WORKERS 2

/*
#include "pch.h"
#include <iostream>
*/

#include <stdio.h>

int n = 0;
int m = 0;
int c = 0;
int ans = 0;
int tmp = 0;
int result = 0;

int matrix[MAX_N][MAX_N] = { 0 };
int selected[WORKERS][MAX_M] = { 0 };

void init()
{
	ans = 0;
	tmp = 0;
	result = 0;

	for (int row = 0; row < MAX_N; row++)
	{
		for (int col = 0; col < MAX_N; col++)
		{
			matrix[row][col] = 0;
		}
	}

	for (int i = 0; i < WORKERS; i++)
	{
		for (int j = 0; j < MAX_M; j++)
		{
			selected[i][j] = 0;
		}
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

void print_selected()
{
	printf("selected : \n");

	for (int i = 0; i < WORKERS; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", selected[i][j]);
		}

		printf("\n");
	}

	printf("\n");

	return;
}

void sell(int start_index, int cur_price, int remain, int worker)
{
	// printf("start : %d, price : %d, remain : %d, worker : %d\n", start_index, cur_price, remain, worker);

	// 채취 불가능한 경우라면
	if (remain < 0)
	{
		// printf("불가능!\n");

		return;
	}

	// 모두 선택 완료했다면
	if (start_index == m)
	{
		// printf("price : %d, tmp = %d\n", cur_price, tmp);

		if (cur_price > tmp)
		{
			tmp = cur_price;
		}

		return;
	}

	// 여기도 완전탐색
	for (int i = start_index; i < m; i++)
	{
		// 선택하고 탐색
		sell(i + 1, cur_price + (selected[worker][i] * selected[worker][i]), remain - selected[worker][i], worker);

		// 선택하지 않고 탐색
		sell(i + 1, cur_price, remain, worker);
	}

	return;
}

void backtrack(int start_r, int start_c, int depth)
{
	// printf("start = (%d, %d), depth = %d\n", start_r, start_c, depth);

	// 모두 배분했다면
	if (depth == WORKERS)
	{
		// print_selected();

		result = 0;

		// 일꾼마다 선택
		for (int i = 0; i < WORKERS; i++)
		{
			tmp = 0;

			sell(0, 0, c, i);

			result += tmp;
		}

		if (result > ans)
		{
			ans = result;
		}

		return;
	}

	for (int r = start_r; r < n; r++)
	{
		for (int c = 0; c <= n - m; c++)
		{
			// printf("cur = (%d, %d)\n", r, c);

			// 시작 row의 경우
			if (r == start_r)
			{
				// 이미 탐색한 col이라면
				if (c < start_c)
				{
					// 넘어가자
					continue;
				}
			}

			// 마지막 col이라면
			if (c == n - m - 1)
			{
				// 선택한 결과를 저장하고
				for (int k = 0; k < m; k++)
				{
					selected[depth][k] = matrix[r][c + k];
				}

				// 다음 줄부터 탐색
				backtrack(r + 1, 0, depth + 1);
			}
			// 나머지 경우는
			else
			{
				// 선택한 결과를 저장하고
				for (int k = 0; k < m; k++)
				{
					selected[depth][k] = matrix[r][c + k];
				}

				// 그 줄에서 계속 탐색
				backtrack(r, c + m, depth + 1);
			}
		}
	}

	return;
}

int main()
{
    // std::cout << "Hello World!\n"; 

	int t = 0;

	scanf("%d", &t);

	for (int tc = 1; tc <= t; tc++)
	{
		init();

		scanf("%d %d %d", &n, &m, &c);

		for (int row = 0; row < n; row++)
		{
			for (int col = 0; col < n; col++)
			{
				scanf("%d", &matrix[row][col]);
			}
		}

		// print_matrix();

		backtrack(0, 0, 0);

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
