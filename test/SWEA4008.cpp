// KJOSW4008.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#define MAX_N 12
#define INF 1000000000

/*
#include "pch.h"
#include <iostream>
*/

#include <stdio.h>

int n = 0;
int adds = 0;
int subs = 0;
int muls = 0;
int divs = 0;
int min = INF;
int max = -INF;
int ans = 0;

int operand_list[MAX_N] = { 0 };

void init()
{
	min = INF;
	max = -INF;
	ans = 0;

	for (int i = 0; i < MAX_N; i++)
	{
		operand_list[i] = 0;
	}

	return;
}

void print_operand()
{
	printf("operand_list : \n");

	for (int i = 0; i < n; i++)
	{
		printf("%d ", operand_list[i]);
	}

	printf("\n");

	return;
}

void backtrack(int depth, int value)
{
	int cur_num = operand_list[depth];

	// printf("num = %d, depth = %d, value = %d, (%d, %d, %d, %d)\n", cur_num, depth, value, adds, subs, muls, divs);

	// 연산자 모두 썼으면
	if (depth == n)
	{
		// 최솟값 갱신
		if (value < min)
		{
			min = value;
		}

		// 최댓값 갱신
		if (value > max)
		{
			max = value;
		}
	}

	// 덧셈 남아있으면
	if (adds > 0)
	{
		// 기호 하나 써주고
		adds -= 1;

		// 완전탐색
		backtrack(depth + 1, value + cur_num);

		// 복구
		adds += 1;
	}

	// 뺄셈 남아있으면
	if (subs > 0)
	{
		// 기호 하나 써주고
		subs -= 1;

		// 완전탐색
		backtrack(depth + 1, value - cur_num);

		// 복구
		subs += 1;
	}

	// 곱셈 남아있으면
	if (muls > 0)
	{
		// 기호 하나 써주고
		muls -= 1;

		// 완전탐색
		backtrack(depth + 1, value * cur_num);

		// 복구
		muls += 1;
	}

	// 나눗셈 남아있으면
	if (divs > 0)
	{
		// 기호 하나 써주고
		divs -= 1;

		// 완전탐색
		backtrack(depth + 1, value / cur_num);

		// 복구
		divs += 1;
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

		scanf("%d", &n);

		scanf("%d %d %d %d", &adds, &subs, &muls, &divs);

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &operand_list[i]);
		}

		// print_operand();

		backtrack(1, operand_list[0]);

		// 정답 갱신
		ans = max - min;

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
