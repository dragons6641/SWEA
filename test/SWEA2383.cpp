// KJOSW2383.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

/*
#include "pch.h"
#include <iostream>
*/

#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <cstring>

#define MAX_N 10
#define MAX_HUMANS 10
#define MAX_STAIRS 2
#define MAX_ONSTAIR 3
#define MAX_ANS 1000

using namespace std;

typedef struct hs
{
	int index = 0;
	int dist_A = 0;
	int dist_B = 0;
	int diff = 0;
} HS;

typedef struct time
{
	int index = 0;
	int on = 0;
	int off = 0;
} TIME;

int n = 0;
int ans = MAX_ANS;
int humans = 0;
int stairs = 0;

int matrix[MAX_N][MAX_N] = { 0 };
// index, row, col
int human_list[MAX_HUMANS][3] = { 0 };
// index, row, col, length
int stair_list[MAX_STAIRS][4] = { 0 };
HS distance_list[MAX_HUMANS];

int selected[MAX_HUMANS] = { 0 };

bool compare_diff(const HS& x, const HS& y)
{
	int len_a = stair_list[0][3];
	int len_b = stair_list[1][3];

	if (x.diff < y.diff)
	{
		return true;
	}
	else if (x.diff > y.diff)
	{
		return false;
	}
	else
	{
		if (len_a < len_b)
		{
			if (x.dist_A > y.dist_A)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			if (x.dist_B > y.dist_B)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

bool compare_dist_A(const HS& x, const HS& y)
{
	if (x.dist_A < y.dist_A)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool compare_dist_B(const HS& x, const HS& y)
{
	if (x.dist_B < y.dist_B)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool compare_on(const TIME& x, const TIME& y)
{
	if (x.on < y.on)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void distance_calculate()
{
	int human_row = 0;
	int human_col = 0;
	int stair_row = 0;
	int stair_col = 0;

	for (int h = 0; h < humans; h++)
	{
		human_row = human_list[h][1];
		human_col = human_list[h][2];

		for (int s = 0; s < stairs; s++)
		{
			stair_row = stair_list[s][1];
			stair_col = stair_list[s][2];

			if (s == 0)
			{
				distance_list[h].dist_A = abs(human_row - stair_row) + abs(human_col - stair_col);
			}
			else if (s == 1)
			{
				distance_list[h].dist_B = abs(human_row - stair_row) + abs(human_col - stair_col);
			}
		}

		distance_list[h].index = h + 1;
		distance_list[h].diff = distance_list[h].dist_A - distance_list[h].dist_B;
	}

	return;
}

int solve()
{
	int max = 0;
	int max_A = 0;
	int max_B = 0;
	int min = MAX_ANS;
	int max_cnt = 0;
	int dist_A = 0;
	int dist_B = 0;
	int a = 0;
	int b = 0;

	int humans_A = 0;
	int humans_B = 0;
	int index = 0;
	int cur_off = 0;
	int next_on = 0;
	int cur_time = 0;
	int start_check = 0;
	int tmp = 0;

	HS copy_list_A[MAX_HUMANS];
	HS copy_list_B[MAX_HUMANS];

	if (humans <= MAX_ONSTAIR)
	{
		for (int h = 0; h < humans; h++)
		{
			dist_A = distance_list[h].dist_A + stair_list[0][3] + 1;
			dist_B = distance_list[h].dist_B + stair_list[1][3] + 1;

			if (dist_A < dist_B)
			{
				max_cnt = dist_A;
			}
			else
			{
				max_cnt = dist_B;
			}

			if (max_cnt > max)
			{
				max = max_cnt;
			}
		}

		return max;
	}
	else
	{
		for (a = 0; a <= humans; a++)
		{
			max_A = 0;
			max_B = 0;

			// sort(distance_list, distance_list + humans, compare_diff_A);
			memcpy(copy_list_A, distance_list, sizeof(distance_list));

			// sort(distance_list, distance_list + humans, compare_diff_B);
			memcpy(copy_list_B, distance_list, sizeof(distance_list));

			b = humans - a;

			// printf("%d %d\n", a, b);

			// 계단 a에 보낸다
			if (a <= MAX_ONSTAIR)
			{
				for (int h = 0; h < a; h++)
				{
					dist_A = distance_list[h].dist_A + stair_list[0][3] + 1;

					if (dist_A > max_A)
					{
						max_A = dist_A;
					}
				}
			}
			else
			{
				sort(copy_list_A, copy_list_A + a, compare_dist_A);

				humans_A = 0;
				index = 0;
				cur_off = 0;
				next_on = copy_list_A[index].dist_A + 1;
				cur_time = 0;
				start_check = 0;

				// printf("a = %d\n", a);

				while (index < a)
				{
					/*
					printf("humans_A = %d, index = %d, cur_off = %d, next_on = %d\n", humans_A, index, cur_off, next_on);
					printf("cur_time = %d, start_check = %d, stair_length = %d\n", cur_time, start_check, stair_list[0][3]);
					printf("\n");
					*/

					if (next_on > cur_time)
					{
						cur_time += 1;

						for (int h = start_check; h < index; h++)
						{
							tmp = copy_list_A[h].dist_A + stair_list[0][3] + 1;

							if (tmp <= cur_time)
							{
								humans_A -= 1;
								start_check += 1;
							}
						}
					}
					else
					{
						if (humans_A < MAX_ONSTAIR)
						{
							humans_A += 1;
							index += 1;
							cur_off = next_on + stair_list[0][3];

							if (index != a)
							{
								tmp = copy_list_A[index].dist_A + 1;

								if (tmp > cur_time)
								{
									next_on = tmp;
								}
								else
								{
									next_on = cur_time;
								}
							}
							else
							{
								max_A = cur_off;

								// printf("max_A = %d\n", max_A);

								break;
							}
						}
						else
						{
							next_on += 1;
						}
					}
				}
			}

			// 계단 b에 보낸다
			if (b <= MAX_ONSTAIR)
			{
				for (int h = a; h < humans; h++)
				{
					dist_B = distance_list[h].dist_B + stair_list[1][3] + 1;

					if (dist_B > max_B)
					{
						max_B = dist_B;
					}
				}
			}
			else
			{
				sort(copy_list_B + a, copy_list_B + humans, compare_dist_B);

				humans_B = 0;
				index = a;
				cur_off = 0;
				next_on = copy_list_B[index].dist_B + 1;
				cur_time = 0;
				start_check = a;

				// printf("a = %d\n", a);

				while (index < humans)
				{
					/*
					printf("humans_B = %d, index = %d, cur_off = %d, next_on = %d\n", humans_B, index, cur_off, next_on);
					printf("cur_time = %d, start_check = %d, stair_length = %d\n", cur_time, start_check, stair_list[1][3]);
					printf("\n");
					*/

					if (next_on > cur_time)
					{
						cur_time += 1;

						for (int h = start_check; h < index; h++)
						{
							tmp = copy_list_B[h].dist_B + stair_list[1][3] + 1;

							if (tmp <= cur_time)
							{
								humans_B -= 1;
								start_check += 1;
							}
						}
					}
					else
					{
						if (humans_B < MAX_ONSTAIR)
						{
							humans_B += 1;
							index += 1;
							cur_off = next_on + stair_list[1][3];

							if (index != humans)
							{
								tmp = copy_list_B[index].dist_B + 1;

								if (tmp > cur_time)
								{
									next_on = tmp;
								}
								else
								{
									next_on = cur_time;
								}
							}
							else
							{
								max_B = cur_off;

								// printf("max_B = %d\n", max_B);

								break;
							}
						}
						else
						{
							next_on += 1;
						}
					}
				}
			}

			if (max_A > max_B)
			{
				max_cnt = max_A;
			}
			else
			{
				max_cnt = max_B;
			}

			if (max_cnt < min)
			{
				min = max_cnt;
			}

			/*
			printf("%d %d\n", a, b);
			printf("max_A = %d\n", max_A);
			printf("max_B = %d\n", max_B);
			printf("max_cnt = %d\n", max_cnt);
			printf("min = %d\n", min);
			*/
		}
	}

	return min;
}

int simulate()
{
	int a = 0;
	int b = 0;
	int on_A = 0;
	int on_B = 0;
	int cnt_A = 0;
	int cnt_B = 0;

	int index = 0;
	int cur_time = 0;
	int next_on = 0;
	int start_check = 0;

	TIME info_A[MAX_HUMANS];
	TIME info_B[MAX_HUMANS];

	for (int i = 0; i < humans; i++)
	{
		if (selected[i] == 0)
		{
			info_A[a].index = i;
			info_A[a].on = distance_list[i].dist_A + 1;
			info_A[a].off = info_A[a].on + stair_list[selected[i]][3];

			a += 1;
		}
		else if (selected[i] == 1)
		{
			info_B[b].index = i;
			info_B[b].on = distance_list[i].dist_B + 1;
			info_B[b].off = info_B[b].on + stair_list[selected[i]][3];

			b += 1;
		}
	}

	sort(info_A, info_A + a, compare_on);
	sort(info_B, info_B + b, compare_on);

	/*
	printf("info_A\n");

	for (int i = 0; i < a; i++)
	{
		printf("%d %d %d\n", info_A[i].index, info_A[i].on, info_A[i].off);
	}

	printf("info_B\n");

	for (int i = 0; i < b; i++)
	{
		printf("%d %d %d\n", info_B[i].index, info_B[i].on, info_B[i].off);
	}
	*/

	// printf("stair A\n");

	// 계단 a로 보낸다
	while (index < a)
	{
		// 도착 시간 갱신
		for (int i = index; i < a; i++)
		{
			if (info_A[i].on < cur_time)
			{
				info_A[i].on += 1;
				info_A[i].off += 1;
			}
		}

		next_on = info_A[index].on;

		// printf("index = %d, next_on = %d, start_check = %d, cur_time = %d, on_B = %d\n", index, next_on, start_check, cur_time, on_A);
		
		// 계단 내려가기를 완료한 경우
		for (int i = start_check; i < a; i++)
		{
			// printf("off = %d, cur_time = %d\n", info_A[i].off, cur_time);

			if (info_A[i].off <= cur_time)
			{
				on_A -= 1;
				start_check += 1;
			}
		}

		// 아직 계단에 오지 않은 경우
		if (next_on > cur_time)
		{
			cur_time += 1;
		}
		// 계단에 도착한 경우
		else
		{
			// 계단을 내려갈 수 있는 경우
			if (on_A < MAX_ONSTAIR)
			{
				on_A += 1;

				if (index == a - 1)
				{
					cnt_A = info_A[index].off;
				}

				index += 1;
			}
			// 계단이 꽉 찬 경우
			else
			{
				info_A[index].on += 1;
				info_A[index].off += 1;
			}
		}
	}

	index = 0;
	cur_time = 0;
	next_on = 0;
	start_check = 0;

	// printf("stair B\n");

	// 계단 b로 보낸다
	while (index < b)
	{
		// 도착 시간 갱신
		for (int i = index; i < b; i++)
		{
			if (info_B[i].on < cur_time)
			{
				info_B[i].on += 1;
				info_B[i].off += 1;
			}
		}

		next_on = info_B[index].on;

		// printf("index = %d, next_on = %d, start_check = %d, cur_time = %d, on_A = %d\n", index, next_on, start_check, cur_time, on_B);

		// 계단 내려가기를 완료한 경우
		for (int i = start_check; i < b; i++)
		{
			// printf("off = %d, cur_time = %d\n", info_B[i].off, cur_time);

			if (info_B[i].off <= cur_time)
			{
				on_B -= 1;
				start_check += 1;
			}
		}

		// 아직 계단에 오지 않은 경우
		if (next_on > cur_time)
		{
			cur_time += 1;
		}
		// 계단에 도착한 경우
		else
		{
			// 계단을 내려갈 수 있는 경우
			if (on_B < MAX_ONSTAIR)
			{
				on_B += 1;

				if (index == b - 1)
				{
					cnt_B = info_B[index].off;
				}

				index += 1;
			}
			// 계단이 꽉 찬 경우
			else
			{
				info_B[index].on += 1;
				info_B[index].off += 1;
			}
		}
	}

	// printf("cnt_A = %d, cnt_B = %d\n", cnt_A, cnt_B);

	if (cnt_A > cnt_B)
	{
		return cnt_A;
	}
	else
	{
		return cnt_B;
	}
}

void solve_upgrade(int depth)
{
	int cnt = 0;
	int a = 0;
	int b = 0;

	if (depth == humans)
	{
		/*
		for (int i = 0; i < humans; i++)
		{
			printf("%d ", selected[i]);
		}

		printf("\n");
		*/

		cnt = simulate();

		// printf("cnt = %d, ans = %d\n", cnt, ans);

		if (cnt < ans)
		{
			ans = cnt;
		}

		return;
	}

	for (int i = 0; i < stairs; i++)
	{
		selected[depth] = i;

		solve_upgrade(depth + 1);
	}
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
		ans = MAX_ANS;
		humans = 0;
		stairs = 0;

		for (int row = 0; row < MAX_N; row++)
		{
			for (int col = 0; col < MAX_N; col++)
			{
				matrix[row][col] = 0;
			}
		}

		for (int row = 0; row < MAX_HUMANS; row++)
		{
			for (int col = 0; col < 3; col++)
			{
				human_list[row][col] = 0;
			}
		}

		for (int row = 0; row < MAX_STAIRS; row++)
		{
			for (int col = 0; col < 3; col++)
			{
				stair_list[row][col] = 0;
			}
		}

		for (int j = 0; j < MAX_HUMANS; j++)
		{
			distance_list[j].index = 0;
			distance_list[j].dist_A = 0;
			distance_list[j].dist_B = 0;
			distance_list[j].diff = 0;
		}

		for (int j = 0; j < MAX_HUMANS; j++)
		{
			selected[j] = 0;
		}

		scanf("%d", &n);

		// printf("n = %d\n", n);

		for (int row = 0; row < n; row++)
		{
			for (int col = 0; col < n; col++)
			{
				scanf("%d", &matrix[row][col]);

				if (matrix[row][col] == 1)
				{
					human_list[humans][0] = humans + 1;
					human_list[humans][1] = row;
					human_list[humans][2] = col;

					humans += 1;
				}
				else if (matrix[row][col] > 1)
				{
					stair_list[stairs][0] = stairs + 1;
					stair_list[stairs][1] = row;
					stair_list[stairs][2] = col;
					stair_list[stairs][3] = matrix[row][col];

					stairs += 1;
				}
			}
		}

		distance_calculate();

		/*
		for (int row = 0; row < n; row++)
		{
			for (int col = 0; col < n; col++)
			{
				printf("%d ", matrix[row][col]);
			}

			printf("\n");
		}
		*/

		/*
		printf("humans = %d\n", humans);

		for (int row = 0; row < humans; row++)
		{
			for (int col = 0; col < 3; col++)
			{
				printf("%d ", human_list[row][col]);
			}

			printf("\n");
		}
		*/

		/*
		printf("stairs = %d\n", stairs);

		for (int row = 0; row < stairs; row++)
		{
			for (int col = 0; col < 4; col++)
			{
				printf("%d ", stair_list[row][col]);
			}

			printf("\n");
		}
		*/

		// sort(distance_list, distance_list + humans, compare_diff);

		/*
		for (int j = 0; j < humans; j++)
		{
			printf("%d %d %d %d\n", distance_list[j].index, distance_list[j].dist_A, distance_list[j].dist_B, distance_list[j].diff);
		}
		*/

		// ans = solve();

		solve_upgrade(0);

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
