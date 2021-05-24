// KJOSW5656.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

/*
#include "pch.h"
#include <iostream>
*/

#include <stdio.h>

#define MAX_W 12
#define MAX_H 15
#define MAX_ANS (MAX_W * MAX_H)
#define MAX_N 4

typedef struct brick
{
	int num = 0;
	int isRemoved = 0;
} BRICK;

int n = 0;
int w = 0;
int h = 0;
int ans = MAX_ANS;
int isFinished = 0;
int start_row = -1;
int start_col = -1;

BRICK matrix[MAX_N + 1][MAX_H][MAX_W];

void remove_brick(int cur_row, int cur_col, int depth)
{
	matrix[depth][cur_row][cur_col].isRemoved = 1;

	// printf("remove_brick : cur_row = %d, cur_col = %d, depth = %d\n", cur_row, cur_col, depth);

	/*
	printf("remove_brick : cur_row = %d, cur_col = %d, depth = %d\n", cur_row, cur_col, depth);

	for (int row = 0; row < h; row++)
	{
		for (int col = 0; col < w; col++)
		{
			printf("%d ", matrix[0][row][col].isRemoved);
		}

		printf("\n");
	}

	printf("\n");
	*/

	int cur_num = (matrix[depth][cur_row][cur_col].num - 1);
	int min_row = 0;
	int max_row = h - 1;
	int min_col = 0;
	int max_col = w - 1;

	if (cur_row - cur_num > min_row)
	{
		min_row = cur_row - cur_num;
	}

	if (cur_row + cur_num < max_row)
	{
		max_row = cur_row + cur_num;
	}

	if (cur_col - cur_num > min_col)
	{
		min_col = cur_col - cur_num;
	}

	if (cur_col + cur_num < max_col)
	{
		max_col = cur_col + cur_num;
	}

	// printf("cur_num = %d, min_row = %d, max_row = %d, min_col = %d, max_col = %d\n", cur_num, min_row, max_row, min_col, max_col);

	// 연쇄 마지막일 경우 종료
	if (cur_num == 0)
	{
		return;
	}
	// 연쇄 마지막이 아닐 경우 재귀 호출
	else
	{
		// 상
		for (int row = cur_row - 1; row >= min_row; row--)
		{
			if ((matrix[depth][row][cur_col].num > 0) && (matrix[depth][row][cur_col].isRemoved == 0))
			{
				matrix[depth][row][cur_col].isRemoved = 1;

				remove_brick(row, cur_col, depth);
			}
		}

		// 하
		for (int row = cur_row + 1; row <= max_row; row++)
		{
			if ((matrix[depth][row][cur_col].num > 0) && (matrix[depth][row][cur_col].isRemoved == 0))
			{
				matrix[depth][row][cur_col].isRemoved = 1;

				remove_brick(row, cur_col, depth);
			}
		}

		// 좌
		for (int col = cur_col - 1; col >= min_col; col--)
		{
			if ((matrix[depth][cur_row][col].num > 0) && (matrix[depth][cur_row][col].isRemoved == 0))
			{
				matrix[depth][cur_row][col].isRemoved = 1;

				remove_brick(cur_row, col, depth);
			}
		}

		// 우
		for (int col = cur_col + 1; col <= max_col; col++)
		{
			if ((matrix[depth][cur_row][col].num > 0) && (matrix[depth][cur_row][col].isRemoved == 0))
			{
				matrix[depth][cur_row][col].isRemoved = 1;

				remove_brick(cur_row, col, depth);
			}
		}
	}

	return;
}

void drop_brick(int depth)
{
	/*
	printf("drop_brick : cur_row = %d, cur_col = %d, depth = %d\n", start_row, start_col, depth);

	for (int row = 0; row < h; row++)
	{
		for (int col = 0; col < w; col++)
		{
			printf("%d ", matrix[depth][row][col].isRemoved);
		}

		printf("\n");
	}

	printf("\n");
	*/

	int row_index = h - 1;

	for (int col = 0; col < w; col++)
	{
		row_index = h - 1;

		for (int row = h - 1; row >= 0; row--)
		{
			// 제거되지 않은 벽돌만 남기기
			if (matrix[depth][row][col].num > 0)
			{
				if (matrix[depth][row][col].isRemoved == 0)
				{
					// printf("row = %d, col = %d, row_index = %d\n", row, col, row_index);

					matrix[depth + 1][row_index][col].num = matrix[depth][row][col].num;

					row_index -= 1;
				}
				// isRemoved 초기화
				else
				{
					matrix[depth][row][col].isRemoved = 0;
				}
			}	
		}
	}

	return;
}

void backtrack(int cur_row, int cur_col, int depth)
{
	// printf("cur_row = %d, cur_col = %d, depth = %d\n", cur_row, cur_col, depth);

	/*
	printf("cur_row = %d, cur_col = %d, depth = %d\n", cur_row, cur_col, depth);

	for (int row = 0; row < h; row++)
	{
		for (int col = 0; col < w; col++)
		{
			printf("%d ", matrix[depth][row][col].num);
		}

		printf("\n");
	}

	printf("\n");
	*/

	if (isFinished == 1)
	{
		return;
	}

	for (int row = 0; row < MAX_H; row++)
	{
		for (int col = 0; col < MAX_W; col++)
		{
			matrix[depth + 1][row][col].num = 0;
			matrix[depth + 1][row][col].isRemoved = 0;
		}
	}

	int cnt = 0;

	start_row = -1;
	start_col = -1;

	// 제거할 벽돌 표시
	remove_brick(cur_row, cur_col, depth);

	// 떨어지는 벽돌 처리
	drop_brick(depth);

	// 정답 갱신
	for (int row = 0; row < h; row++)
	{
		for (int col = 0; col < w; col++)
		{
			if (matrix[depth + 1][row][col].num > 0)
			{
				cnt += 1;
			}
		}
	}

	// printf("cnt = %d, ans = %d\n", cnt, ans);

	if (cnt < ans)
	{
		// printf("cnt = %d, ans = %d\n", cnt, ans);

		ans = cnt;
	}

	if (ans == 0)
	{
		isFinished = 1;
	}

	// 구슬을 모두 떨어뜨렸을 경우 종료
	if ((depth + 1 == n) || (isFinished == 1))
	{
		/*
		printf("depth = %d\n", depth + 1);

		for (int row = 0; row < h; row++)
		{
			for (int col = 0; col < w; col++)
			{
				printf("%d ", matrix[depth + 1][row][col].num);
			}

			printf("\n");
		}

		printf("\n");
		*/

		return;
	}
	// 구슬이 남아있는 경우 재귀 호출
	else
	{
		for (int col = 0; col < w; col++)
		{
			start_col = col;

			for (int row = 0; row < h; row++)
			{
				// 제거 시작 위치 찾기
				if (matrix[depth + 1][row][col].num > 0)
				{
					start_row = row;

					break;
				}
			}

			if (start_row != -1)
			{
				backtrack(start_row, start_col, depth + 1);
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
		w = 0;
		h = 0;
		ans = MAX_ANS;
		isFinished = 0;
		start_row = -1;
		start_col = -1;

		for (int row = 0; row < MAX_H; row++)
		{
			for (int col = 0; col < MAX_W; col++)
			{
				matrix[0][row][col].num = 0;
				matrix[0][row][col].isRemoved = 0;
			}
		}

		scanf("%d %d %d", &n, &w, &h);

		// printf("n = %d, w = %d, h = %d\n", n, w, h);

		for (int row = 0; row < h; row++)
		{
			for (int col = 0; col < w; col++)
			{
				scanf("%d", &matrix[0][row][col].num);
			}
		}

		/*
		for (int row = 0; row < h; row++)
		{
			for (int col = 0; col < w; col++)
			{
				printf("%d ", matrix[0][row][col].num);
			}

			printf("\n");
		}
		*/

		///*
		for (int col = 0; col < w; col++)
		{
			if (isFinished == 1)
			{
				break;
			}

			start_col = col;

			for (int row = 0; row < h; row++)
			{
				// 제거 시작 위치 찾기
				if (matrix[0][row][col].num > 0)
				{
					start_row = row;

					break;
				}
			}

			if (start_row != -1)
			{
				backtrack(start_row, start_col, 0);

				/*
				remove_brick(start_row, start_col, 0);

				drop_brick(0);

				printf("main : cur_row = %d, cur_col = %d, depth = %d\n", start_row, start_col, 0);

				for (int row = 0; row < h; row++)
				{
					for (int col = 0; col < w; col++)
					{
						printf("%d ", matrix[1][row][col].num);
					}

					printf("\n");
				}

				printf("\n");
				*/
			}
		}
		//*/

		/*
		remove_brick(1, 2, 0);

		drop_brick(0);

		printf("main : cur_row = %d, cur_col = %d, depth = %d\n", 1, 2, 0);

		for (int row = 0; row < h; row++)
		{
			for (int col = 0; col < w; col++)
			{
				printf("%d ", matrix[1][row][col].num);
			}

			printf("\n");
		}

		printf("\n");

		remove_brick(2, 2, 1);

		drop_brick(1);

		printf("main : cur_row = %d, cur_col = %d, depth = %d\n", 2, 2, 1);

		for (int row = 0; row < h; row++)
		{
			for (int col = 0; col < w; col++)
			{
				printf("%d ", matrix[2][row][col].num);
			}

			printf("\n");
		}

		printf("\n");

		remove_brick(8, 6, 2);

		drop_brick(2);

		printf("main : cur_row = %d, cur_col = %d, depth = %d\n", 8, 6, 2);

		for (int row = 0; row < h; row++)
		{
			for (int col = 0; col < w; col++)
			{
				printf("%d ", matrix[3][row][col].num);
			}

			printf("\n");
		}

		printf("\n");
		*/

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
