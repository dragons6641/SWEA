// KJOSW5650.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

/*
#include "pch.h"
#include <iostream>
*/

#include <stdio.h>

#define MAX_N 100
#define MAX_WORMS 5

typedef struct worm
{
	int index = 0;
	int r = 0;
	int c = 0;
}WORM;

int n = 0;
int ans = 0;
int result = 0;
int worms = 0;
int tmp = 0;

int matrix[MAX_N + 2][MAX_N + 2] = { 5 };
WORM worm_list[MAX_WORMS * 2];

int simulate(int start_row, int start_col, int start_dir)
{
	int cnt = 0;
	int cur_row = start_row;
	int cur_col = start_col;
	int cur_dir = start_dir;
	int cur_val = matrix[cur_row][cur_col];

	while (true)
	{
		/*
		printf("row = %d, col = %d, dir = %d\n", cur_row, cur_col, cur_dir);
		// printf("start_row = %d, start_col = %d, cnt = %d\n", start_row, start_col, cnt);
		*/

		cur_val = matrix[cur_row][cur_col];

		// 블랙홀
		if (cur_val == -1)
		{
			return cnt;
		}
		// 보통 칸
		else if (cur_val == 0)
		{
			// 상
			if (cur_dir == 1)
			{
				cur_row -= 1;
			}
			// 하
			else if (cur_dir == 2)
			{
				cur_row += 1;
			}
			// 좌
			else if (cur_dir == 3)
			{
				cur_col -= 1;
			}
			// 우
			else if (cur_dir == 4)
			{
				cur_col += 1;
			}
		}
		// 1번 블록
		else if (cur_val == 1)
		{
			cnt += 1;

			// 아래에서 부딪혔을 경우 아래쪽으로
			if (cur_dir == 1)
			{
				cur_row += 1;
				cur_dir = 2;
			}
			// 위에서 부딪혔을 경우 오른쪽으로
			else if (cur_dir == 2)
			{
				cur_col += 1;
				cur_dir = 4;
			}
			// 오른쪽에서 부딪혔을 경우 위쪽으로
			else if (cur_dir == 3)
			{
				cur_row -= 1;
				cur_dir = 1;
			}
			// 왼쪽에서 부딪혔을 경우 왼쪽으로
			else if (cur_dir == 4)
			{
				cur_col -= 1;
				cur_dir = 3;
			}
		}
		// 2번 블록
		else if (cur_val == 2)
		{
			cnt += 1;

			// 아래에서 부딪혔을 경우 오른쪽으로
			if (cur_dir == 1)
			{
				cur_col += 1;
				cur_dir = 4;
			}
			// 위에서 부딪혔을 경우 위쪽으로
			else if (cur_dir == 2)
			{
				cur_row -= 1;
				cur_dir = 1;
			}
			// 오른쪽에서 부딪혔을 경우 아래쪽으로
			else if (cur_dir == 3)
			{
				cur_row += 1;
				cur_dir = 2;
			}
			// 왼쪽에서 부딪혔을 경우 왼쪽으로
			else if (cur_dir == 4)
			{
				cur_col -= 1;
				cur_dir = 3;
			}
		}
		// 3번 블록
		else if (cur_val == 3)
		{
			cnt += 1;

			// 아래에서 부딪혔을 경우 왼쪽으로
			if (cur_dir == 1)
			{
				cur_col -= 1;
				cur_dir = 3;
			}
			// 위에서 부딪혔을 경우 위쪽으로
			else if (cur_dir == 2)
			{
				cur_row -= 1;
				cur_dir = 1;
			}
			// 오른쪽에서 부딪혔을 경우 오른쪽으로
			else if (cur_dir == 3)
			{
				cur_col += 1;
				cur_dir = 4;
			}
			// 왼쪽에서 부딪혔을 경우 아래쪽으로
			else if (cur_dir == 4)
			{
				cur_row += 1;
				cur_dir = 2;
			}
		}
		// 4번 블록
		else if (cur_val == 4)
		{
			cnt += 1;

			// 아래에서 부딪혔을 경우 아래쪽으로
			if (cur_dir == 1)
			{
				cur_row += 1;
				cur_dir = 2;
			}
			// 위에서 부딪혔을 경우 왼쪽으로
			else if (cur_dir == 2)
			{
				cur_col -= 1;
				cur_dir = 3;
			}
			// 오른쪽에서 부딪혔을 경우 오른쪽으로
			else if (cur_dir == 3)
			{
				cur_col += 1;
				cur_dir = 4;
			}
			// 왼쪽에서 부딪혔을 경우 위쪽으로
			else if (cur_dir == 4)
			{
				cur_row -= 1;
				cur_dir = 1;
			}
		}
		// 5번 블록
		else if (cur_val == 5)
		{
			cnt += 1;

			// 아래에서 부딪혔을 경우 아래쪽으로
			if (cur_dir == 1)
			{
				cur_row += 1;
				cur_dir = 2;
			}
			// 위에서 부딪혔을 경우 위쪽으로
			else if (cur_dir == 2)
			{
				cur_row -= 1;
				cur_dir = 1;
			}
			// 오른쪽에서 부딪혔을 경우 오른쪽으로
			else if (cur_dir == 3)
			{
				cur_col += 1;
				cur_dir = 4;
			}
			// 왼쪽에서 부딪혔을 경우 왼쪽으로
			else if (cur_dir == 4)
			{
				cur_col -= 1;
				cur_dir = 3;
			}
		}
		// 웜홀
		else if ((cur_val >= 6) && (cur_val <= 10))
		{
			for (int j = 0; j < worms; j++)
			{
				// 번호 같은 다른 위치의 웜홀로
				if ((worm_list[j].index == cur_val))
				{
					if ((worm_list[j].r != cur_row) || (worm_list[j].c != cur_col))
					{
						cur_row = worm_list[j].r;
						cur_col = worm_list[j].c;

						// 상
						if (cur_dir == 1)
						{
							cur_row -= 1;
						}
						// 하
						else if (cur_dir == 2)
						{
							cur_row += 1;
						}
						// 좌
						else if (cur_dir == 3)
						{
							cur_col -= 1;
						}
						// 우
						else if (cur_dir == 4)
						{
							cur_col += 1;
						}

						break;
					}
				}
			}
		}

		// 시작 위치
		if ((cur_row == start_row) && (cur_col == start_col))
		{
			return cnt;
		}
	}

	return 0;
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
		ans = 0;
		result = 0;
		worms = 0;
		tmp = 0;

		for (int row = 0; row <= MAX_N + 1; row++)
		{
			for (int col = 0; col <= MAX_N + 1; col++)
			{
				matrix[row][col] = 5;
			}
		}

		for (int j = 0; j < MAX_WORMS * 2; j++)
		{
			worm_list[j].index = 0;
			worm_list[j].r = 0;
			worm_list[j].c = 0;
		}

		scanf("%d", &n);

		// printf("n = %d\n", n);

		for (int row = 1; row <= n; row++)
		{
			for (int col = 1; col <= n; col++)
			{
				scanf("%d", &tmp);

				matrix[row][col] = tmp;

				if ((tmp >= 6) && (tmp <= 10))
				{
					worm_list[worms].index = tmp;
					worm_list[worms].r = row;
					worm_list[worms].c = col;

					worms += 1;
				}
			}
		}

		/*
		for (int row = 0; row <= n + 1; row++)
		{
			for (int col = 0; col <= n + 1; col++)
			{
				printf("%d ", matrix[row][col]);
			}

			printf("\n");
		}
		*/

		/*
		for (int j = 0; j < worms; j++)
		{
			printf("%d %d %d\n", worm_list[j].index, worm_list[j].r, worm_list[j].c);
		}
		*/

		for (int row = 1; row <= n; row++)
		{
			for (int col = 1; col <= n; col++)
			{
				if (matrix[row][col] == 0)
				{
					// 상 : 1, 하 : 2, 좌 : 3, 우 : 4
					for (int dir = 1; dir <= 4; dir++)
					{
						result = simulate(row, col, dir);

						/*
						printf("start_row = %d, start_col = %d, start_dir = %d\n", row, col, dir);
						printf("result = %d, ans = %d\n", result, ans);
						*/

						if (result > ans)
						{
							ans = result;
						}
					}
				}
			}
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
