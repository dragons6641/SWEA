// KJOSW1247.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#define MAX_X 100
#define MAX_Y 100
#define MAX_N 10
#define INF 1000000000

/*
#include "pch.h"
#include <iostream>
*/

#include <stdio.h>

typedef struct d2 {
	int x = -1;
	int y = -1;
	int isVisited = 0;
} D2;

D2 customer[MAX_N];

int ans = 1000000000;
int n = 0;
int company_x = -1;
int company_y = -1;
int home_x = -1;
int home_y = -1;

int calc_dist(int a1, int b1, int a2, int b2)
{
	int result = 0;

	if (a1 > a2)
	{
		result += (a1 - a2);
	}
	else
	{
		result += (a2 - a1);
	}

	if (b1 > b2)
	{
		result += (b1 - b2);
	}
	else
	{
		result += (b2 - b1);
	}

	return result;
}

void backtrack(int cur, int cnt, int dist)
{
	int cur_x = customer[cur].x;
	int cur_y = customer[cur].y;
	int result = 0;

	// 방문한 고객 표시
	customer[cur].isVisited = 1;

	// printf("cur = %d, cnt = %d, dist = %d, ans = %d, x = %d, y = %d, isVisited = %d\n", cur, cnt, dist, ans, cur_x, cur_y, customer[cur].isVisited);
	
	for (int i = 0; i < n; i++)
	{
		// 아직 방문하지 않은 고객이 있다면
		if (customer[i].isVisited == 0)
		{
			backtrack(i, cnt + 1, dist + calc_dist(cur_x, cur_y, customer[i].x, customer[i].y));
		}
	}

	customer[cur].isVisited = 0;

	// 총 거리 계산
	if (cnt == n)
	{
		result = dist + calc_dist(cur_x, cur_y, home_x, home_y);

		// 계산한 거리가 더 짧다면
		if (result < ans)
		{
			ans = result;
		}
	}

	// printf("cnt = %d, n = %d, result = %d, ans = %d\n", cnt, n, result, ans);

	return;
}

int main()
{
    // std::cout << "Hello World!\n"; 

	int testcase = 0;

	scanf("%d", &testcase);

	for (int t = 1; t <= testcase; t++)
	{
		for (int i = 0; i < MAX_N; i++)
		{
			customer[i].x = -1;
			customer[i].y = -1;
			customer[i].isVisited = 0;
		}

		ans = 1000000000;
		n = 0;

		company_x = -1;
		company_y = -1;
		home_x = -1;
		home_y = -1;

		scanf("%d", &n);

		// 회사 좌표
		scanf("%d %d", &company_x, &company_y);

		// 집 좌표
		scanf("%d %d", &home_x, &home_y);

		// 고객들 좌표
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d", &customer[i].x, &customer[i].y);
		}

		/*
		printf("%d %d\n", company_x, company_y);

		for (int i = 0; i < n; i++)
		{
			printf("%d %d\n", customer[i].x, customer[i].y);
		}

		printf("%d %d\n", home_x, home_y);
		*/

		for (int i = 0; i < n; i++)
		{
			// 방문 기록 초기화
			for (int j = 0; j < n; j++)
			{
				customer[j].isVisited = 0;
			}

			// 완전 탐색
			backtrack(i, 1, calc_dist(company_x, company_y, customer[i].x, customer[i].y));
		}

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
