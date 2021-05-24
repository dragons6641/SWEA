// KJOSW2112.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

/*
#include "pch.h"
#include <iostream>
*/

#include <stdio.h>
#include <string.h>

#define MAX_D 13
#define MAX_W 20
#define MAX_K 13

int d = 0;
int w = 0;
int k = 0;
int tmp = 0;
int ans = 0;
int cnt = 0;
int isFinished = 0;

int matrix[MAX_D][MAX_W] = { 0 };
int copy[MAX_D][MAX_W] = { 0 };
int combi_list[MAX_K] = { 0 };
int row_list[MAX_D] = { 0 };
int permu_repeat_list[MAX_K] = { 0 };
int chemical_list[2] = { 0, 1 };

int test()
{
	/*
	printf("\n");

	for (int row = 0; row < d; row++)
	{
		for (int col = 0; col < w; col++)
		{
			printf("%d ", copy[row][col]);
		}

		printf("\n");
	}
	*/

	for (int col = 0; col < w; col++)
	{
		int cur = 0;
		int prev = 0;
		int cnt = 0;
		int isSafe = 0;

		for (int row = 0; row < d; row++)
		{
			if (row == 0)
			{
				cur = copy[row][col];
				cnt = 1;
			}
			else
			{
				cur = copy[row][col];
				prev = copy[row - 1][col];

				if (cur == prev)
				{
					cnt += 1;
				}
				else
				{
					cnt = 1;
				}
			}

			/*
			printf("(%d, %d)\n", row, col);
			printf("prev = %d, cur = %d, cnt = %d\n", prev, cur, cnt);
			*/

			if (cnt >= k)
			{
				isSafe = 1;

				break;
			}
			else if ((cnt + d - row - 1) < k)
			{
				return -1;
			}
		}

		if (!isSafe)
		{
			return -1;
		}
	}

	return 0;
}

void permu_repeat(int depth)
{
	int cur_row = 0;
	int result = 0;

	if (cnt == depth)
	{
		/*
		for (int i = 0; i < cnt; i++)
		{
			printf("%d ", permu_repeat_list[i]);
		}

		printf("\n");
		*/

		for (int i = 0; i < cnt; i++)
		{
			cur_row = combi_list[i];

			// 약품 A 투입
			if ((permu_repeat_list[i]) == 0)
			{
				for (int col = 0; col < w; col++)
				{
					copy[cur_row][col] = 0;
				}
			}
			// 약품 B 투입
			else
			{
				for (int col = 0; col < w; col++)
				{
					copy[cur_row][col] = 1;
				}
			}
		}

		result = test();

		if (result == 0)
		{
			ans = cnt;
			isFinished = 1;
		}

		memcpy(©, &matrix, sizeof(matrix));

		return;
	}

	for (int i = 0; i <= 1; i++)
	{
		permu_repeat_list[depth] = i;

		if (isFinished == 0)
		{
			permu_repeat(depth + 1);
		}
	}
}

void combi(int nn, int rr)
{
	if (rr == 0)
	{
		/*
		for (int i = 0; i < cnt; i++)
		{
			printf("%d ", combi_list[i]);
		}

		printf("\n");
		*/

		if (isFinished == 0)
		{
			permu_repeat(0);
		}

		return;
	}
	else if (nn < rr)
	{
		return;
	}
	else
	{
		combi_list[rr - 1] = row_list[nn - 1];

		if (isFinished == 0)
		{
			combi(nn - 1, rr - 1);
			combi(nn - 1, rr);
		}
	}

	return;
}

void solve()
{
	for (int r = 1; r < k; r++)
	{
		// printf("r = %d, d = %d\n", r, d);

		cnt = r;

		if (isFinished == 0)
		{
			combi(d, r);
		}
	}

	return;
}

int main()
{
    // std::cout << "Hello World!\n"; 

	for (int i = 0; i < MAX_D; i++)
	{
		row_list[i] = i;
	}

	int t = 0;

	scanf("%d", &t);

	// printf("t = %d\n", t);

	for (int i = 0; i < t; i++)
	{
		d = 0;
		w = 0;
		k = 0;
		tmp = 0;
		ans = 0;
		cnt = 0;
		isFinished = 0;

		for (int row = 0; row < MAX_D; row++)
		{
			for (int col = 0; col < MAX_W; col++)
			{
				matrix[row][col] = 0;
				copy[row][col] = 0;
			}

			row_list[row] = row;
		}

		for (int j = 0; j < MAX_K; j++)
		{
			combi_list[j] = 0;
			permu_repeat_list[j] = 0;
		}

		scanf("%d %d %d", &d, &w, &k);

		// printf("d = %d, w = %d, k = %d\n", d, w, k);

		for (int row = 0; row < d; row++)
		{
			for (int col = 0; col < w; col++)
			{
				scanf("%d", &tmp);

				matrix[row][col] = tmp;
				copy[row][col] = tmp;
			}
		}

		/*
		for (int row = 0; row < d; row++)
		{
			for (int col = 0; col < w; col++)
			{
				printf("%d ", matrix[row][col]);
			}

			printf("\n");
		}
		*/

		/*
		for (int row = 0; row < d; row++)
		{
			for (int col = 0; col < w; col++)
			{
				printf("%d ", copy[row][col]);
			}

			printf("\n");
		}
		*/

		/*
		for (int row = 0; row < d; row++)
		{
			printf("%d ", row_list[row]);
		}

		printf("\n");
		*/

		ans = test();

		if (ans == -1)
		{
			solve();
		}

		if (ans == -1)
		{
			ans = k;
		}

		printf("#%d %d\n", i + 1, ans);
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
