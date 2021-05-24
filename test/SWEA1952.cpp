// KJOSW1952.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#define MONTHS 12

/*
#include "pch.h"
#include <iostream>
*/

#include <stdio.h>

int price_d1 = 0;
int price_m1 = 0;
int price_m3 = 0;
int price_y1 = 0;
int ans = 0;

int day_list[MONTHS + 1] = { 0 };

void init()
{
	for (int i = 1; i <= MONTHS; i++)
	{
		day_list[i] = 0;
	}

	return;
}

void print_day()
{
	printf("day_list : \n");

	for (int i = 1; i <= MONTHS; i++)
	{
		printf("%d ", day_list[i]);
	}

	printf("\n");

	return;
}

void backtrack(int start_month, int cur_price)
{
	int isEnd = 1;

	// 시작 위치 정하기
	for (int i = start_month; i <= MONTHS; i++)
	{
		// 그 달에 하루라도 나가면
		if (day_list[i])
		{
			// 그 달로 시작
			start_month = i;

			// 아직 끝나지 않았음
			isEnd = 0;

			break;
		}
	}

	// printf("month : %d, price : %d, ans = %d, isEnd = %d\n", start_month, cur_price, ans, isEnd);

	// 이용권 배분 끝났으면
	if (isEnd)
	{
		// 가격이 최저가라면
		if (cur_price < ans)
		{
			ans = cur_price;
		}

		// 돌아가자
		return;
	}

	// 이미 답이 될 수 없다면
	if (cur_price >= ans)
	{
		return;
	}

	// 3달 이용권 끊어보자
	// 10월 이전이면 예외 없음
	if (start_month <= MONTHS - 2)
	{
		// 세 달 동안 이용이 한 번이라도 있으면
		if ((day_list[start_month]) || day_list[start_month + 1] || day_list[start_month + 2])
		{
			// 완전탐색
			backtrack(start_month + 3, cur_price + price_m3);
		}
	}
	// 11월이면
	else if (start_month == MONTHS - 1)
	{
		// 두 달 동안 이용이 한 번이라도 있으면
		if ((day_list[start_month]) || day_list[start_month + 1])
		{
			// 완전탐색
			backtrack(start_month + 2, cur_price + price_m3);
		}
	}
	// 12월이면
	else if (start_month == MONTHS)
	{
		// 한 달 동안 이용이 한 번이라도 있으면
		if (day_list[start_month])
		{
			// 완전탐색
			backtrack(start_month + 1, cur_price + price_m3);
		}
	}

	// 1달 이용권으로 채우기
	// 이번 달 이용 있으면
	if (day_list[start_month])
	{
		// 완전탐색
		backtrack(start_month + 1, cur_price + price_m1);
	}

	// 1일 이용권으로 채우기
	// 이번 달 이용 있으면
	if (day_list[start_month])
	{
		// 완전탐색
		backtrack(start_month + 1, cur_price + (price_d1 * day_list[start_month]));
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

		scanf("%d %d %d %d", &price_d1, &price_m1, &price_m3, &price_y1);

		for (int i = 1; i <= MONTHS; i++)
		{
			scanf("%d", &day_list[i]);
		}

		/*
		printf("%d %d %d %d\n", price_d1, price_m1, price_m3, price_y1);
		print_day();
		*/

		// 1년 이용권으로 기본 설정
		ans = price_y1;

		backtrack(0, 0);

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
