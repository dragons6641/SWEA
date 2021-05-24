// KJOSW2117.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

/*
#include "pch.h"
#include <iostream>
*/

#include <stdio.h>

#define MAX_N 20

int n = 0;
int m = 0;
int ans = 0;
int cnt_all = 0;

int matrix[MAX_N][MAX_N] = { 0 };

int solve()
{
	int distance = 0;
	int remain = 0;
	int start_row = 0;
	int end_row = 0;
	int start_col = 0;
	int end_col = 0;
	int cnt_safe = 0;
	int income = 0;
	int expense = 0;
	int profit = 0;
	int cur_ans = 0;

	for (int k = 1; k <= n; k++)
	{
		expense = (k * k) + (k - 1) * (k - 1);

		for (int center_row = 0; center_row < n; center_row++)
		{
			for (int center_col = 0; center_col < n; center_col++)
			{
				cnt_safe = 0;

				if ((center_row - k + 1) >= 0)
				{
					start_row = (center_row - k + 1);
				}
				else
				{
					start_row = 0;
				}

				if ((center_row + k - 1) <= n - 1)
				{
					end_row = (center_row + k - 1);
				}
				else
				{
					end_row = n - 1;
				}

				for (int cur_row = start_row; cur_row <= end_row; cur_row++)
				{
					if (cur_row < center_row)
					{
						distance = center_row - cur_row;
					}
					else
					{
						distance = cur_row - center_row;
					}

					remain = k - distance;

					if ((center_col - remain + 1) >= 0)
					{
						start_col = (center_col - remain + 1);
					}
					else
					{
						start_col = 0;
					}

					if ((center_col + remain - 1) <= n - 1)
					{
						end_col = (center_col + remain - 1);
					}
					else
					{
						end_col = n - 1;
					}

					for (int cur_col = start_col; cur_col <= end_col; cur_col++)
					{
						/*
						printf("k = %d, center = (%d, %d)\n", k, center_row, center_col);
						printf("cur = (%d, %d)\n", cur_row, cur_col);
						*/

						if (matrix[cur_row][cur_col] == 1)
						{
							cnt_safe += 1;
						}
					}
				}

				income = m * cnt_safe;
				profit = income - expense;

				if ((cnt_safe > cur_ans) && (profit >= 0))
				{
					cur_ans = cnt_safe;

					/*
					printf("k = %d, (%d, %d)\n", k, center_row, center_col);
					printf("cur_ans = %d, profit = %d\n", cur_ans, profit);
					*/
				}

				if (cur_ans == cnt_all)
				{
					return cur_ans;
				}
			}
		}
	}

	return cur_ans;
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
		m = 0;
		ans = 0;
		cnt_all = 0;

		for (int row = 0; row < MAX_N; row++)
		{
			for (int col = 0; col < MAX_N; col++)
			{
				matrix[row][col] = 0;
			}
		}

		scanf("%d %d", &n, &m);

		// printf("n = %d, m = %d\n", n, m);

		for (int row = 0; row < n; row++)
		{
			for (int col = 0; col < n; col++)
			{
				scanf("%d", &matrix[row][col]);

				if (matrix[row][col] == 1)
				{
					cnt_all += 1;
				}
			}
		}

		// printf("cnt_all = %d\n", cnt_all);

		/*
		for (int row = 0; row < n; row++)
		{
			for (int col = 0; col < n; col++)
			{
				printf("%d ", matrix[row][col]);
			}

			printf("\n");
		}
		*/

		if ((cnt_all == 1) || (cnt_all == (n * n)))
		{
			ans = cnt_all;
		}
		else
		{
			ans = solve();
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
