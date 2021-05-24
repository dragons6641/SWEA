// KJOSW1953.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

/*
#include "pch.h"
#include <iostream>
*/

#include <stdio.h>
#include <queue>

#define MAX_NM 50

using namespace std;

typedef struct contents {
	int a = 0;
	int b = 0;
	int cnt = 0;
} CONTENTS;

int n = 0;
int m = 0;
int r = 0;
int c = 0;
int l = 0;
int ans = 0;

int matrix[MAX_NM][MAX_NM] = { 0 };
int isVisited[MAX_NM][MAX_NM] = { 0 };

void bfs()
{
	int cur_row = 0;
	int cur_col = 0;
	int cur_cnt = 0;

	CONTENTS cur_node;
	cur_node.a = r;
	cur_node.b = c;
	cur_node.cnt = 1;

	CONTENTS next_node;

	queue<CONTENTS> q;

	q.push(cur_node);

	while (!q.empty())
	{
		cur_node = q.front();
		q.pop();

		cur_row = cur_node.a;
		cur_col = cur_node.b;
		cur_cnt = cur_node.cnt;

		// printf("(%d, %d), cnt = %d, ans = %d\n", cur_row, cur_col, cur_cnt, ans);

		if (cur_cnt > l)
		{
			continue;
		}

		else if (isVisited[cur_row][cur_col] == 0)
		{
			isVisited[cur_row][cur_col] = 1;
			ans += 1;
		}

		if ((matrix[cur_row][cur_col] == 1) || (matrix[cur_row][cur_col] == 2) || (matrix[cur_row][cur_col] == 4) || (matrix[cur_row][cur_col] == 7))
		{
			// 상
			if ((cur_row - 1 >= 0) && (isVisited[cur_row - 1][cur_col] == 0))
			{
				if ((matrix[cur_row - 1][cur_col] == 1) || (matrix[cur_row - 1][cur_col] == 2) || (matrix[cur_row - 1][cur_col] == 5) || (matrix[cur_row - 1][cur_col] == 6))
				{
					next_node.a = cur_row - 1;
					next_node.b = cur_col;
					next_node.cnt = cur_cnt + 1;

					q.push(next_node);
				}
			}
		}

		if ((matrix[cur_row][cur_col] == 1) || (matrix[cur_row][cur_col] == 3) || (matrix[cur_row][cur_col] == 6) || (matrix[cur_row][cur_col] == 7))
		{
			// 좌
			if ((cur_col - 1 >= 0) && (isVisited[cur_row][cur_col - 1] == 0))
			{
				if ((matrix[cur_row][cur_col - 1] == 1) || (matrix[cur_row][cur_col - 1] == 3) || (matrix[cur_row][cur_col - 1] == 4) || (matrix[cur_row][cur_col - 1] == 5))
				{
					next_node.a = cur_row;
					next_node.b = cur_col - 1;
					next_node.cnt = cur_cnt + 1;

					q.push(next_node);
				}
			}
		}

		if ((matrix[cur_row][cur_col] == 1) || (matrix[cur_row][cur_col] == 2) || (matrix[cur_row][cur_col] == 5) || (matrix[cur_row][cur_col] == 6))
		{
			// 하
			if ((cur_row + 1 <= n - 1) && (isVisited[cur_row + 1][cur_col] == 0))
			{
				if ((matrix[cur_row + 1][cur_col] == 1) || (matrix[cur_row + 1][cur_col] == 2) || (matrix[cur_row + 1][cur_col] == 4) || (matrix[cur_row + 1][cur_col] == 7))
				{
					next_node.a = cur_row + 1;
					next_node.b = cur_col;
					next_node.cnt = cur_cnt + 1;

					q.push(next_node);
				}
			}
		}

		if ((matrix[cur_row][cur_col] == 1) || (matrix[cur_row][cur_col] == 3) || (matrix[cur_row][cur_col] == 4) || (matrix[cur_row][cur_col] == 5))
		{
			// 우
			if ((cur_col + 1 <= m - 1) && (isVisited[cur_row][cur_col + 1] == 0))
			{
				if ((matrix[cur_row][cur_col + 1] == 1) || (matrix[cur_row][cur_col + 1] == 3) || (matrix[cur_row][cur_col + 1] == 6) || (matrix[cur_row][cur_col + 1] == 7))
				{
					next_node.a = cur_row;
					next_node.b = cur_col + 1;
					next_node.cnt = cur_cnt + 1;

					q.push(next_node);
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
		r = 0;
		c = 0;
		l = 0;
		ans = 0;

		for (int row = 0; row < MAX_NM; row++)
		{
			for (int col = 0; col < MAX_NM; col++)
			{
				matrix[row][col] = 0;
				isVisited[row][col] = 0;
			}
		}

		scanf("%d %d %d %d %d", &n, &m, &r, &c, &l);

		// printf("n = %d, m = %d, r = %d, c = %d, l = %d\n", n, m, r, c, l);

		for (int row = 0; row < n; row++)
		{
			for (int col = 0; col < m; col++)
			{
				scanf("%d", &matrix[row][col]);
			}
		}

		/*
		for (int row = 0; row < n; row++)
		{
			for (int col = 0; col < m; col++)
			{
				printf("%d ", matrix[row][col]);
			}

			printf("\n");
		}
		*/

		/*
		for (int row = 0; row < n; row++)
		{
			for (int col = 0; col < m; col++)
			{
				printf("%d ", isVisited[row][col]);
			}

			printf("\n");
		}
		*/

		bfs();

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
