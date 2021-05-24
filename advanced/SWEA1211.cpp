// KJOSW1211.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#define TESTCASE 10
#define ROWS 100
#define COLS 100
#define INF 100000

/*
#include "pch.h"
#include <iostream>
*/

#include <stdio.h>

int main()
{
	// std::cout << "Hello World!\n";

	int num = 0;
	/*
	int cur_row = ROWS - 1;
	int cur_col = -1;
	int cur_dir = -1;
	*/

	int col_list[COLS] = { -1 };
	int dist_list[COLS] = { -1 };
	int ladder_list[ROWS][COLS] = { 0 };

	for (int t = 1; t <= TESTCASE; t++)
	{
		int min_dist = INF;
		int ans = 0;
		int cnt = 0;
		int index = -1;

		for (int col = 0; col < COLS; col++)
		{
			col_list[col] = -1;
			dist_list[col] = -1;
		}

		scanf("%d", &num);

		for (int row = 0; row < ROWS; row++)
		{
			for (int col = 0; col < COLS; col++)
			{
				scanf("%d", &ladder_list[row][col]);

				if (row == 0)
				{
					/*
					if (ladder_list[row][col] == 2)
					{
						index = cnt;
					}
					*/

					if (ladder_list[row][col] >= 1)
					{
						col_list[cnt] = col;
						cnt += 1;
					}
				}
			}
		}

		/*
		for (int col = 0; col < cnt; col++)
		{
			printf("%d ", col_list[col]);
		}

		printf("\n");
		*/

		/*
		while (cur_row > 0)
		{
			// 왼쪽 확인
			if ((ladder_list[cur_row][cur_col - 1] == 1) && (cur_dir != 3))
			{
				cur_col -= 1;
				cur_dir = 9;
			}
			// 오른쪽 확인
			else if ((ladder_list[cur_row][cur_col + 1] == 1) && (cur_dir != 9))
			{
				cur_col += 1;
				cur_dir = 3;
			}
			// 양쪽 없으면 위쪽으로
			else
			{
				cur_row -= 1;
				cur_dir = 12;
			}
		}
		*/

		for (int col = 0; col < cnt; col++)
		{
			int temp_dist = 0;

			index = col;

			for (int row = 0; row < ROWS; row++)
			{
				temp_dist += 1;

				// 왼쪽 확인
				if ((col_list[index] > 0) && (ladder_list[row][col_list[index] - 1] == 1))
				{
					temp_dist += (col_list[index] - col_list[index - 1]);
					index -= 1;
				}
				// 오른쪽 확인
				else if ((col_list[index] < ROWS - 1) && (ladder_list[row][col_list[index] + 1] == 1))
				{
					temp_dist += (col_list[index + 1] - col_list[index]);
					index += 1;
				}
				// 양쪽 없으면 아래쪽으로
				else
				{
					continue;
				}

				// printf("row = %d, col = %d\n", row, col_list[index]);

				// printf("dist = %d\n", temp_dist);
			}

			dist_list[col] = temp_dist;

			// printf("col = %d, dist = %d\n", col_list[col], temp_dist);

			if (temp_dist < min_dist)
			{
				min_dist = temp_dist;
				ans = col_list[col];
			}

			// printf("min = %d\n", ans);
		}

		/*
		for (int col = 0; col < cnt; col++)
		{
			printf("%d ", dist_list[col]);
		}

		printf("\n");
		*/

		printf("#%d %d\n", t, ans);
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
