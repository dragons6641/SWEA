// KJOSW2477.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#define MAX_N 9
#define MAX_M 9
#define MAX_K 1000
#define MAX_A MAX_N
#define MAX_B MAX_M
#define MAX_AI 20
#define MAX_BJ 20
#define MAX_TK 1000

typedef struct node {
	int nn = 0;
	int tt = 0;
	int ff = 0;
} NODE;

/*
#include "pch.h"
#include <iostream>
*/

#include <stdio.h>
#include <queue>

using namespace std;

int n = 0;
int m = 0;
int k = 0;
int a = 0;
int b = 0;
int ans = 0;

int ai_list[MAX_AI + 1] = { -1 };
int bj_list[MAX_BJ + 1] = { -1 };
int tk_list[MAX_TK + 1] = { -1 };

NODE a_desk[MAX_N + 1];
NODE b_desk[MAX_M + 1];

queue<NODE> aq;
queue<NODE> bq;

void init()
{
	ans = 0;

	for (int i = 1; i <= MAX_AI; i++)
	{
		ai_list[i] = -1;
	}

	for (int i = 1; i <= MAX_BJ; i++)
	{
		bj_list[i] = -1;
	}

	for (int i = 1; i <= MAX_TK; i++)
	{
		tk_list[i] = -1;
	}

	for (int i = 1; i <= MAX_A; i++)
	{
		a_desk[i].nn = -1;
		a_desk[i].tt = -1;
		a_desk[i].ff = -1;
	}

	for (int i = 1; i <= MAX_B; i++)
	{
		b_desk[i].nn = -1;
		b_desk[i].tt = -1;
		b_desk[i].ff = -1;
	}

	while (!(aq.empty()))
	{
		aq.pop();
	}

	while (!(bq.empty()))
	{
		bq.pop();
	}

	return;
}

void print_ai()
{
	printf("ai_list : \n");

	for (int i = 1; i <= n; i++)
	{
		printf("%d ", ai_list[i]);
	}

	printf("\n");

	return;
}

void print_bj()
{
	printf("bj_list : \n");

	for (int i = 1; i <= m; i++)
	{
		printf("%d ", bj_list[i]);
	}

	printf("\n");

	return;
}

void print_tk()
{
	printf("tk_list : \n");

	for (int i = 1; i <= k; i++)
	{
		printf("%d ", tk_list[i]);
	}

	printf("\n");

	return;
}

void print_a()
{
	printf("a_desk : \n");

	for (int i = 1; i <= n; i++)
	{
		printf("%d %d %d\n", a_desk[i].nn, a_desk[i].tt, a_desk[i].ff);
	}

	printf("\n");

	return;
}

void print_b()
{
	printf("b_desk : \n");

	for (int i = 1; i <= m; i++)
	{
		printf("%d %d %d\n", b_desk[i].nn, b_desk[i].tt, b_desk[i].ff);
	}

	printf("\n");

	return;
}

int reception(int index, int cur_time)
{
	int cur_num = -1;
	int empty_cnt = 0;

	NODE cur;
	NODE next;

	// printf("reception tk = %d, time = %d\n", tk_list[index], cur_time);

	// 먼저 창구를 비운다
	for (int i = 1; i <= n; i++)
	{
		/*
		printf("비우기 전 : \n");
		print_a();
		*/

		// 처리 끝났으면
		if (a_desk[i].tt == cur_time)
		{
			// 고객을 정비 창구로 보내고
			next.nn = a_desk[i].nn;
			next.tt = cur_time;
			next.ff = i;

			bq.push(next);

			// 비워주자
			a_desk[i].nn = -1;
			a_desk[i].tt = -1;
			a_desk[i].ff = -1;

			/*
			printf("비운 후 : \n");
			print_a();
			*/
		}

		// 비어있다면
		if (a_desk[i].nn == -1)
		{
			// 빈 창구 개수 추가
			empty_cnt += 1;
		}
	}

	/*
	// 다 끝났으면
	if (index > k)
	{
		printf("인덱스 초과\n");

		// 접수 불가
		return 0;
	}
	*/

	// 만약 고객이 왔으면
	if (tk_list[index] == cur_time)
	{
		cur.nn = index;
		cur.tt = cur_time;
		cur.ff = -1;

		// 일단 대기 큐에는 넣어줘야 함
		aq.push(cur);
	}

	/*
	// 빈 창구가 없다면
	if (empty_cnt == 0)
	{
		printf("빈 창구 없음\n");

		// 접수 되긴 함
		return 1;
	}
	*/

	// 고객 상대할 수 있을때만 pop
	for (int i = 1; i <= n; i++)
	{
		// 대기 중인 고객이 있을 경우
		if (!(aq.empty()))
		{
			// 창구가 비어있다면
			if (a_desk[i].nn == -1)
			{
				cur = aq.front();
				aq.pop();

				cur_num = cur.nn;

				// printf("aq num = %d, time = %d, from = %d, i = %d, empty_cnt = %d\n", cur_num, cur.tt, cur.ff, i, empty_cnt);

				// 창구 배정
				a_desk[i].nn = cur_num;
				a_desk[i].tt = cur_time + ai_list[i];
				a_desk[i].ff = -1;

				empty_cnt -= 1;

				/*
				printf("넣은 후 : \n");
				print_a();
				*/

				// 빈 창구가 없다면
				if (empty_cnt == 0)
				{
					// 끝!
					break;
				}
			}
		}
		// 고객 없으면
		else
		{
			// 끝!
			break;
		}
	}

	if (tk_list[index] != cur_time)
	{
		// 아직 접수는 안됐음
		return 0;
	}
	else
	{
		// 접수 되긴 함
		return 1;
	}
}

void repair(int cur_time)
{
	int cur_num = -1;
	int cur_from = -1;
	int empty_cnt = 0;

	NODE cur;

	// printf("repair tk = %d, time = %d\n", tk_list[index], cur_time);

	// 먼저 창구를 비운다
	for (int i = 1; i <= m; i++)
	{
		// 처리 끝났으면
		if (b_desk[i].tt == cur_time)
		{
			// printf("customer %d, (%d, %d)\n", b_desk[i].nn, b_desk[i].ff, i);

			// 같은 창구 번호라면
			if ((b_desk[i].ff == a) && (i == b))
			{
				// 고객 번호 정답에 추가
				ans += b_desk[i].nn;

				// printf("added = %d\n", b_desk[i].nn);
			}

			// 비워주자
			b_desk[i].nn = -1;
			b_desk[i].tt = -1;
			b_desk[i].ff = -1;
		}

		// 비어있다면
		if (b_desk[i].nn == -1)
		{
			// 빈 창구 개수 추가
			empty_cnt += 1;
		}
	}

	// 대기 중인 고객이 없으면
	if (bq.empty())
	{
		// 할거 없는데요;;;
		return;
	}

	// 빈 창구가 없으면
	if (empty_cnt == 0)
	{
		// 정비 불가능
		return;
	}
	
	// 고객 상대할 수 있을때만 pop
	for (int i = 1; i <= m; i++)
	{
		// 대기 중인 고객이 있을 경우
		if (!(bq.empty()))
		{
			// 창구가 비어있다면
			if (b_desk[i].nn == -1)
			{
				cur = bq.front();
				bq.pop();

				cur_num = cur.nn;
				cur_from = cur.ff;

				// printf("bq num = %d, time = %d, from = %d, i = %d, empty_cnt = %d\n", cur_num, cur.tt, cur_from, i, empty_cnt);

				// 창구 배정
				b_desk[i].nn = cur_num;
				b_desk[i].tt = cur_time + bj_list[i];
				b_desk[i].ff = cur_from;

				empty_cnt -= 1;

				// print_b();

				// 빈 창구가 없다면
				if (empty_cnt == 0)
				{
					// 끝!
					break;
				}
			}
		}
		// 고객 없으면
		else
		{
			// 끝!
			break;
		}
	}

	return;
}

void simulate()
{
	int index = 1;
	int time = 0;
	int isReserved = 0;
	int isFinished = 1;

	NODE next;

	while (1)
	{
		/*
		printf("index = %d, time = %d\n", index, time);
		printf("reception : %d\n", aq.size());
		*/

		isFinished = 1;

		for (int i = index; i <= k + 1; i++)
		{
			isReserved = reception(i, time);

			// printf("i = %d, isReserved = %d, index = %d\n", i, isReserved, index);

			// 접수되었다면
			if ((isReserved) && (index <= k))
			{
				// 다음 고객으로
				index += 1;
			}

			///*
			// 접수 안된다면
			else
			{
				// 접수는 끝
				break;
			}
			//*/
		}

		// print_a();

		/*
		printf("repair : %d\n", bq.size());
		printf("\n\n");
		*/

		repair(time);

		// 모든 고객 접수했으면
		if (index == k + 1)
		{
			// 모든 작업이 끝날 시
			for (int i = 1; i <= n; i++)
			{
				// 아직 있으면
				if (a_desk[i].nn >= 0)
				{
					isFinished = 0;

					break;
				}
			}

			// 모든 작업이 끝날 시
			for (int i = 1; i <= m; i++)
			{
				// 아직 있으면
				if (b_desk[i].nn >= 0)
				{
					isFinished = 0;

					break;
				}
			}

			if (isFinished)
			{
				break;
			}
		}

		// print_b();

		time += 1;
	}

	return;
}

int main()
{
    // std::cout << "Hello World!\n"; 

	int t = 0;

	scanf("%d", &t);

	for (int tc = 1; tc <= t; tc++)
	{
		init();

		scanf("%d %d %d %d %d", &n, &m, &k, &a, &b);

		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &ai_list[i]);
		}

		for (int i = 1; i <= m; i++)
		{
			scanf("%d", &bj_list[i]);
		}

		for (int i = 1; i <= k; i++)
		{
			scanf("%d", &tk_list[i]);
		}

		/*
		print_ai();
		print_bj();
		print_tk();
		*/

		simulate();

		if (ans == 0)
		{
			ans = -1;
		}

		printf("#%d %d\n", tc, ans);
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
