// KJOSW2382.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

/*
#include "pch.h"
#include <iostream>
*/

#include <stdio.h>

#define MAX_K 1000

int n = 0;
int m = 0;
int k = 0;
int ans = 0;

int row_list[MAX_K] = { 0 };
int col_list[MAX_K] = { 0 };
int cnt_list[MAX_K] = { 0 };
int dir_list[MAX_K] = { 0 };

void move()
{
	for (int i = 0; i < k; i++)
	{
		if (cnt_list[i] > 0)
		{
			// 상
			if (dir_list[i] == 1)
			{
				row_list[i] -= 1;
			}
			// 하
			else if (dir_list[i] == 2)
			{
				row_list[i] += 1;
			}
			// 좌
			else if (dir_list[i] == 3)
			{
				col_list[i] -= 1;
			}
			// 우
			else if (dir_list[i] == 4)
			{
				col_list[i] += 1;
			}
		}
	}

	return;
}

void kill()
{
	for (int i = 0; i < k; i++)
	{
		if (cnt_list[i] > 0)
		{
			if ((row_list[i] == 0) || (row_list[i] == n - 1) || (col_list[i] == 0) || (col_list[i] == n - 1))
			{
				cnt_list[i] /= 2;

				// 상 -> 하
				if (dir_list[i] == 1)
				{
					dir_list[i] = 2;
				}
				// 하 -> 상
				else if (dir_list[i] == 2)
				{
					dir_list[i] = 1;
				}
				// 좌 -> 우
				else if (dir_list[i] == 3)
				{
					dir_list[i] = 4;
				}
				// 우 -> 좌
				else if (dir_list[i] == 4)
				{
					dir_list[i] = 3;
				}
			}
		}
	}

	return;
}

void unit()
{
	for (int i = 0; i < k; i++)
	{
		int max_index = i;
		int max_cnt = cnt_list[i];
		int max_sum = cnt_list[i];
		int max_dir = dir_list[i];
		int unit_cnt = 1;

		int unit_list[MAX_K] = { 0 };

		unit_list[0] = i;

		if (cnt_list[i] > 0)
		{
			// 같은 것들 체크
			for (int j = i + 1; j < k; j++)
			{
				// printf("i = %d, j = %d, unit_cnt = %d\n", i, j, unit_cnt);

				if (cnt_list[j] > 0)
				{
					if ((row_list[i] == row_list[j]) && (col_list[i] == col_list[j]))
					{
						unit_list[unit_cnt] = j;

						unit_cnt += 1;

						/*
						for (int b = 0; b < unit_cnt; b++)
						{
							printf("%d ", unit_list[b]);
						}

						printf("\n");
						*/

						if (cnt_list[j] > max_cnt)
						{
							max_index = j;
							max_cnt = cnt_list[j];
							max_dir = dir_list[j];
						}

						max_sum += cnt_list[j];
					}
				}
			}
		}

		if (unit_cnt > 1)
		{
			// 합치기
			for (int j = 0; j < unit_cnt; j++)
			{
				if (cnt_list[unit_list[j]] > 0)
				{
					if (unit_list[j] == max_index)
					{
						cnt_list[unit_list[j]] = max_sum;
					}
					else
					{
						cnt_list[unit_list[j]] = 0;
					}
				}
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

	// printf("t = %d\n", t);

	for (int i = 0; i < t; i++)
	{
		n = 0;
		m = 0;
		k = 0;
		ans = 0;

		for (int j = 0; j < MAX_K; j++)
		{
			row_list[j] = { 0 };
			col_list[j] = { 0 };
			cnt_list[j] = { 0 };
			dir_list[j] = { 0 };
		}

		scanf("%d %d %d", &n, &m, &k);

		// printf("n = %d, m = %d, k = %d\n", n, m, k);

		for (int j = 0; j < k; j++)
		{
			scanf("%d %d %d %d", &row_list[j], &col_list[j], &cnt_list[j], &dir_list[j]);
		}

		/*
		for (int j = 0; j < k; j++)
		{
			printf("row = %d, col = %d, cnt = %d, dir = %d\n", row_list[j], col_list[j], cnt_list[j], dir_list[j]);
		}

		printf("\n");
		*/

		for (int j = 0; j < m; j++)
		{
			move();
			kill();
			unit();

			/*
			for (int a = 0; a < k; a++)
			{
				printf("row = %d, col = %d, cnt = %d, dir = %d\n", row_list[a], col_list[a], cnt_list[a], dir_list[a]);
			}

			printf("\n");
			*/
		}

		for (int j = 0; j < k; j++)
		{
			ans += cnt_list[j];
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
