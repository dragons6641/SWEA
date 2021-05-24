// KJOSW1949.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

/*
#include "pch.h"
#include <iostream>
*/

#include <stdio.h>

#define MAX_N 8
#define MAX_START 5

int n = 0;
int k = 0;
int ans = 0;
int max_height = 0;
int index = 0;

int matrix[MAX_N][MAX_N] = { 0 };
int isVisited[MAX_N][MAX_N] = { 0 };
int start_pos[MAX_START][2] = { 0 };

void dfs(int cur_row, int cur_col, int cnt, int chk)
{
	int cur_height = matrix[cur_row][cur_col];
	int next_height = 0;

	// 여기 나중에 초기화 해줘야 함
	isVisited[cur_row][cur_col] = 1;

	// printf("(%d, %d), cnt = %d, chk = %d\n", cur_row, cur_col, cnt, chk);

	if ((cur_row - 1 >= 0) && (isVisited[cur_row - 1][cur_col] == 0))
	{
		next_height = matrix[cur_row - 1][cur_col];

		if (cur_height > next_height)
		{
			dfs(cur_row - 1, cur_col, cnt + 1, chk);
		}
		else if ((chk == 0) && ((next_height - cur_height + 1) <= k))
		{
			// 여기 나중에 초기화 해줘야 함
			matrix[cur_row - 1][cur_col] = cur_height - 1;

			dfs(cur_row - 1, cur_col, cnt + 1, chk + 1);

			matrix[cur_row - 1][cur_col] = next_height;
		}
	}

	if ((cur_col - 1 >= 0) && (isVisited[cur_row][cur_col - 1] == 0))
	{
		next_height = matrix[cur_row][cur_col - 1];

		if (cur_height > next_height)
		{
			dfs(cur_row, cur_col - 1, cnt + 1, chk);
		}
		else if ((chk == 0) && ((next_height - cur_height + 1) <= k))
		{
			// 여기 나중에 초기화 해줘야 함
			matrix[cur_row][cur_col - 1] = cur_height - 1;

			dfs(cur_row, cur_col - 1, cnt + 1, chk + 1);

			matrix[cur_row][cur_col - 1] = next_height;
		}
	}

	if ((cur_row + 1 <= n - 1) && (isVisited[cur_row + 1][cur_col] == 0))
	{
		next_height = matrix[cur_row + 1][cur_col];

		if (cur_height > next_height)
		{
			dfs(cur_row + 1, cur_col, cnt + 1, chk);
		}
		else if ((chk == 0) && ((next_height - cur_height + 1) <= k))
		{
			// 여기 나중에 초기화 해줘야 함
			matrix[cur_row + 1][cur_col] = cur_height - 1;

			dfs(cur_row + 1, cur_col, cnt + 1, chk + 1);

			matrix[cur_row + 1][cur_col] = next_height;
		}
	}

	if ((cur_col + 1 <= n - 1) && (isVisited[cur_row][cur_col + 1] == 0))
	{
		next_height = matrix[cur_row][cur_col + 1];

		if (cur_height > next_height)
		{
			dfs(cur_row, cur_col + 1, cnt + 1, chk);
		}
		else if ((chk == 0) && ((next_height - cur_height + 1) <= k))
		{
			// 여기 나중에 초기화 해줘야 함
			matrix[cur_row][cur_col + 1] = cur_height - 1;

			dfs(cur_row, cur_col + 1, cnt + 1, chk + 1);

			matrix[cur_row][cur_col + 1] = next_height;
		}
	}

	isVisited[cur_row][cur_col] = 0;

	if (cnt > ans)
	{
		ans = cnt;
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
		ans = 0;
		max_height = 0;
		index = 0;
		
		for (int row = 0; row < MAX_N; row++)
		{
			for (int col = 0; col < MAX_N; col++)
			{
				matrix[row][col] = 0;
				isVisited[row][col] = 0;
			}
		}

		for (int row = 0; row < MAX_START; row++)
		{
			for (int col = 0; col < MAX_START; col++)
			{
				start_pos[row][col] = 0;
			}
		}

		scanf("%d %d", &n, &k);

		// printf("n = %d, k = %d\n", n, k);

		for (int row = 0; row < n; row++)
		{
			for (int col = 0; col < n; col++)
			{
				scanf("%d", &matrix[row][col]);

				if (matrix[row][col] > max_height)
				{
					max_height = matrix[row][col];
				}
			}
		}

		for (int row = 0; row < n; row++)
		{
			for (int col = 0; col < n; col++)
			{
				if (matrix[row][col] == max_height)
				{
					start_pos[index][0] = row;
					start_pos[index][1] = col;

					index += 1;
				}
			}
		}

		/*
		for (int row = 0; row < n; row++)
		{
			for (int col = 0; col < n; col++)
			{
				printf("%d ", matrix[row][col]);
			}

			printf("\n");
		}

		for (int row = 0; row < n; row++)
		{
			for (int col = 0; col < n; col++)
			{
				printf("%d ", isVisited[row][col]);
			}

			printf("\n");
		}
		*/

		/*
		printf("max_height = %d\n", max_height);

		for (int j = 0; j < index; j++)
		{
			printf("%d %d\n", start_pos[j][0], start_pos[j][1]);
		}
		*/

		for (int j = 0; j < index; j++)
		{
			dfs(start_pos[j][0], start_pos[j][1], 1, 0);

			// printf("#%d %d\n", i + 1, ans);
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
