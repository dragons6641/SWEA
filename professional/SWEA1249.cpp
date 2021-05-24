// KJOSW1249.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#define MAX_N 100

/*
#include "pch.h"
#include <iostream>
*/

#include <stdio.h>
#include <queue>

using namespace std;

typedef struct node {
	// 총 소요시간
	int t = 0;

	// row
	int r = 0;

	// column
	int c = 0;

	// 진행 방향
	int d = 0;

	// 비교 대상 설정
	node(int t) : t(t), r(0), c(0), d(0) {

	}
} NODE;

// 오름차순 정렬
struct cmp {
	bool operator() (node a, node b) {
		return a.t > b.t;
	}
};

int n = 0;

int matrix[MAX_N][MAX_N] = { 0 };
int isVisited[MAX_N][MAX_N] = { 0 };

int bfs()
{
	priority_queue<NODE, vector<NODE>, cmp> pq;

	NODE cur = 0;

	int cur_row = 0;
	int cur_col = 0;
	int cur_time = matrix[cur_row][cur_col];
	int cur_dir = 0;
	
	cur.t = cur_time;
	cur.r = cur_row;
	cur.c = cur_col;
	cur.d = cur_dir;

	pq.push(cur);

	while (1)
	{
		// 가장 소요 시간이 적은 곳을 pop
		cur = pq.top();
		pq.pop();

		cur_time = cur.t;
		cur_row = cur.r;
		cur_col = cur.c;
		cur_dir = cur.d;

		// printf("time = %d, row = %d, col = %d, dir = %d\n", cur_time, cur_row, cur_col, cur_dir);

		// 방문 표시
		isVisited[cur_row][cur_col] = 1;

		// 종료 지점에 도달했을 경우
		if ((cur_row == n - 1) && (cur_col == n - 1))
		{
			return cur_time;
		}

		// 탐색
		// 상
		// if ((cur_row > 0) && (cur_dir != 6))
		if ((cur_row > 0) && (isVisited[cur_row - 1][cur_col] == 0))
		{
			cur.t = (cur_time + matrix[cur_row - 1][cur_col]);
			cur.r = cur_row - 1;
			cur.c = cur_col;
			cur.d = 12;

			pq.push(cur);

			// printf("상\n");
		}
		// 하
		// if ((cur_row < n - 1) && (cur_dir != 12))
		if ((cur_row < n - 1) && (isVisited[cur_row + 1][cur_col] == 0))
		{
			cur.t = (cur_time + matrix[cur_row + 1][cur_col]);
			cur.r = cur_row + 1;
			cur.c = cur_col;
			cur.d = 6;

			pq.push(cur);

			// printf("하\n");
		}
		// 좌
		// if ((cur_col > 0) && (cur_dir != 3))
		if ((cur_col > 0) && (isVisited[cur_row][cur_col - 1] == 0))
		{
			cur.t = (cur_time + matrix[cur_row][cur_col - 1]);
			cur.r = cur_row;
			cur.c = cur_col - 1;
			cur.d = 9;

			pq.push(cur);

			// printf("좌\n");
		}
		// 우
		// if ((cur_col < n - 1) && (cur_dir != 9))
		if ((cur_col < n - 1) && (isVisited[cur_row][cur_col + 1] == 0))
		{
			cur.t = (cur_time + matrix[cur_row][cur_col + 1]);
			cur.r = cur_row;
			cur.c = cur_col + 1;
			cur.d = 3;

			pq.push(cur);

			// printf("우\n");
		}
	}

	return -1;
}

int main()
{
    // std::cout << "Hello World!\n"; 

	int testcase = 0;

	scanf("%d", &testcase);

	for (int t = 1; t <= testcase; t++)
	{
		// 배열 초기화
		for (int row = 0; row < MAX_N; row++)
		{
			for (int col = 0; col < MAX_N; col++)
			{
				matrix[row][col] = 0;
				isVisited[row][col] = 0;
			}
		}

		int ans = 0;

		scanf("%d", &n);

		for (int row = 0; row < n; row++)
		{
			for (int col = 0; col < n; col++)
			{
				scanf("%1d", &matrix[row][col]);
			}
		}

		/*
		for (int row = 0; row < n; row++)
		{
			for (int col = 0; col < n; col++)
			{
				printf("%d", matrix[row][col]);
			}

			printf("\n");
		}
		*/

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
