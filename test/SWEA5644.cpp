// KJOSW5644.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

/*
#include "pch.h"
#include <iostream>
*/

#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <cstring>

using namespace std;

#define HUMANS 2
#define INFOS 4
#define MAX_M 100
#define MAX_A 8
#define A_START_ROW 1
#define A_START_COL 1
#define B_START_ROW 10
#define B_START_COL 10

typedef struct bc
{
	int x = 0;
	int y = 0;
	int c = 0;
	int p = 0;
} BC;

int m = 0;
int a = 0;
int ans = 0;
int row_a = A_START_ROW;
int col_a = A_START_COL;
int row_b = B_START_ROW;
int col_b = B_START_COL;

// rows = a, b
int move_list[HUMANS][MAX_M] = { 0 };
BC bc_list[MAX_A];

bool compare_p(const BC &a, const BC &b)
{
	if (a.p > b.p)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int dist_calc(int start_row, int start_col, int end_row, int end_col)
{
	return (abs(start_row - end_row) + abs(start_col - end_col));
}

void move(int index, int dir)
{
	// 이동 없음
	if (dir == 0)
	{
		return;
	}
	// 상
	else if (dir == 1)
	{
		if (index == 0)
		{
			row_a -= 1;
		}
		else if (index == 1)
		{
			row_b -= 1;
		}
	}
	// 우
	else if (dir == 2)
	{
		if (index == 0)
		{
			col_a += 1;
		}
		else if (index == 1)
		{
			col_b += 1;
		}
	}
	// 하
	else if (dir == 3)
	{
		if (index == 0)
		{
			row_a += 1;
		}
		else if (index == 1)
		{
			row_b += 1;
		}
	}
	// 좌
	else if (dir == 4)
	{
		if (index == 0)
		{
			col_a -= 1;
		}
		else if (index == 1)
		{
			col_b -= 1;
		}
	}

	return;
}

int solve()
{
	int total_cnt = 0;
	int max_cnt = 0;
	int cur_cnt = 0;
	int dir = 0;
	int dist_a = 0;
	int dist_b = 0;
	int charge_a = 0;
	int charge_b = 0;

	int a_list[MAX_A] = { 0 };
	int b_list[MAX_A] = { 0 };

	row_a = A_START_ROW;
	col_a = A_START_COL;
	row_b = B_START_ROW;
	col_b = B_START_COL;

	// 처음 위치
	for (int j = 0; j < a; j++)
	{
		dist_a = dist_calc(row_a, col_a, bc_list[j].y, bc_list[j].x);
		dist_b = dist_calc(row_b, col_b, bc_list[j].y, bc_list[j].x);

		// printf("dist_a = %d, dist_b = %d, bc = %d\n", dist_a, dist_b, bc_list[j].c);

		if (dist_a <= bc_list[j].c)
		{
			a_list[j] = bc_list[j].p;
		}
		else
		{
			a_list[j] = 0;
		}

		if (dist_b <= bc_list[j].c)
		{
			b_list[j] = bc_list[j].p;
		}
		else
		{
			b_list[j] = 0;
		}
	}

	for (int aa = 0; aa < a; aa++)
	{
		charge_a = a_list[aa];

		for (int bb = 0; bb < a; bb++)
		{
			charge_b = b_list[bb];

			if (aa == bb)
			{
				cur_cnt = (charge_a + charge_b) / 2;
			}
			else
			{
				cur_cnt = charge_a + charge_b;
			}

			if (cur_cnt > max_cnt)
			{
				max_cnt = cur_cnt;
			}
		}
	}

	total_cnt += max_cnt;

	// 나머지 위치
	for (int i = 0; i < m; i++)
	{
		max_cnt = 0;
		cur_cnt = 0;

		dir = move_list[0][i];

		move(0, dir);

		// printf("A %dth move, (%d, %d)\n", i + 1, col_a, row_a);

		dir = move_list[1][i];

		move(1, dir);

		// printf("B %dth move, (%d, %d)\n", i + 1, col_b, row_b);

		for (int j = 0; j < a; j++)
		{
			dist_a = dist_calc(row_a, col_a, bc_list[j].y, bc_list[j].x);
			dist_b = dist_calc(row_b, col_b, bc_list[j].y, bc_list[j].x);

			// printf("dist_a = %d, dist_b = %d, bc = %d\n", dist_a, dist_b, bc_list[j].c);

			if (dist_a <= bc_list[j].c)
			{
				a_list[j] = bc_list[j].p;
			}
			else
			{
				a_list[j] = 0;
			}

			if (dist_b <= bc_list[j].c)
			{
				b_list[j] = bc_list[j].p;
			}
			else
			{
				b_list[j] = 0;
			}
		}

		for (int aa = 0; aa < a; aa++)
		{
			charge_a = a_list[aa];

			for (int bb = 0; bb < a; bb++)
			{
				charge_b = b_list[bb];

				if ((aa == bb) && (charge_a > 0) && (charge_b > 0))
				{
					cur_cnt = (charge_a + charge_b) / 2;
				}
				else
				{
					cur_cnt = charge_a + charge_b;
				}

				if (cur_cnt > max_cnt)
				{
					max_cnt = cur_cnt;
				}
			}
		}

		total_cnt += max_cnt;
	}

	return total_cnt;
}

int main()
{
    // std::cout << "Hello World!\n"; 

	int t = 0;

	scanf("%d", &t);

	// printf("t = %d\n", t);

	for (int i = 0; i < t; i++)
	{
		m = 0;
		a = 0;
		ans = 0;

		for (int row = 0; row < HUMANS; row++)
		{
			for (int col = 0; col < MAX_M; col++)
			{
				move_list[row][col] = 0;
			}
		}

		for (int row = 0; row < MAX_A; row++)
		{
			bc_list[row].x = 0;
			bc_list[row].y = 0;
			bc_list[row].c = 0;
			bc_list[row].p = 0;
		}

		scanf("%d %d", &m, &a);

		// printf("m = %d, a = %d\n", m, a);

		for (int row = 0; row < HUMANS; row++)
		{
			for (int col = 0; col < m; col++)
			{
				scanf("%d", &move_list[row][col]);
			}
		}

		/*
		for (int row = 0; row < HUMANS; row++)
		{
			for (int col = 0; col < m; col++)
			{
				printf("%d ", move_list[row][col]);
			}

			printf("\n");
		}
		*/

		for (int row = 0; row < a; row++)
		{
			scanf("%d", &bc_list[row].x);
			scanf("%d", &bc_list[row].y);
			scanf("%d", &bc_list[row].c);
			scanf("%d", &bc_list[row].p);
		}

		sort(bc_list, bc_list + a, compare_p);

		/*
		for (int row = 0; row < a; row++)
		{
			printf("%d ", bc_list[row].x);
			printf("%d ", bc_list[row].y);
			printf("%d ", bc_list[row].c);
			printf("%d \n", bc_list[row].p);
		}
		*/

		ans = solve();

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
