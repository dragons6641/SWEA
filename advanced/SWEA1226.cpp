// KJOSW1226.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#define TESTCASE 10
#define ROWS 16
#define COLS 16

/*
#include "pch.h"
#include <iostream>
*/

#include <stdio.h>
#include <queue>

using namespace std;

typedef struct pos {
	int r = 0;
	int c = 0;
} POS;

int matrix[ROWS][COLS] = { 0 };
int isVisited[ROWS][COLS] = { 0 };

int start_row = -1;
int start_col = -1;
int end_row = -1;
int end_col = -1;

int bfs()
{
	queue<POS> q;

	int cur_row = start_row;
	int cur_col = start_col;

	POS cur;
	POS next;

	cur.r = cur_row;
	cur.c = cur_col;

	q.push(cur);

	while (!q.empty())
	{
		cur = q.front();

		q.pop();

		cur_row = cur.r;
		cur_col = cur.c;

		// 방문 표시
		isVisited[cur_row][cur_col] = 1;

		// printf("cur = (%d, %d)\n", cur_row, cur_col);

		// 종료 조건
		if ((cur_row == end_row) && (cur_col == end_col))
		{
			// 해답 있음
			return 1;
		}

		// 상
		if ((cur_row > 0) && (matrix[cur_row - 1][cur_col] != 1) && (isVisited[cur_row - 1][cur_col] == 0))
		{
			next.r = cur_row - 1;
			next.c = cur_col;

			q.push(next);
		}
		// 하
		if ((cur_row < ROWS - 1) && (matrix[cur_row + 1][cur_col] != 1) && (isVisited[cur_row + 1][cur_col] == 0))
		{
			next.r = cur_row + 1;
			next.c = cur_col;

			q.push(next);
		}
		// 좌
		if ((cur_col > 0) && (matrix[cur_row][cur_col - 1] != 1) && (isVisited[cur_row][cur_col - 1] == 0))
		{
			next.r = cur_row;
			next.c = cur_col - 1;

			q.push(next);
		}
		// 우
		if ((cur_col < COLS - 1) && (matrix[cur_row][cur_col + 1] != 1) && (isVisited[cur_row][cur_col + 1] == 0))
		{
			next.r = cur_row;
			next.c = cur_col + 1;

			q.push(next);
		}
	}

	// 해답 없음
	return 0;
}

int main()
{
    // std::cout << "Hello World!\n"; 

	int num = 0;
	int tmp = 0;
	int ans = -1;

	for (int t = 1; t <= TESTCASE; t++)
	{
		scanf("%d", &num);

		for (int row = 0; row < ROWS; row++)
		{
			for (int col = 0; col < COLS; col++)
			{
				scanf("%1d", &tmp);

				// printf("tmp = %d\n", tmp);

				matrix[row][col] = tmp;
				isVisited[row][col] = 0;

				if (tmp == 2)
				{
					start_row = row;
					start_col = col;
				}
				else if (tmp == 3)
				{
					end_row = row;
					end_col = col;
				}
			}
		}

		// printf("start = (%d, %d), end = (%d, %d)\n", start_row, start_col, end_row, end_col);

		ans = bfs();

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
