// KJOSW1245.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#define MAX_OBJECTS 10
#define MAX_REPEATS 100

/*
#include "pch.h"
#include <iostream>
*/

#include <stdio.h>
#include <math.h>

typedef struct ms {
	int x = 0;
	int m = 0;
} MS;

int objects = 0;

MS object[MAX_OBJECTS];

double binary_search(int index)
{
	int cnt = 0;
	double left = object[index].x;
	double right = object[index + 1].x;
	double mid = (left + right) / 2;

	while (cnt <= MAX_REPEATS)
	{
		double f_left = 0;
		double f_right = 0;
		double f_left_round = 0;
		double f_right_round = 0;
		double d = 0;

		cnt += 1;
		mid = (left + right) / 2;

		// 왼쪽 힘 구하기
		for (int i = 0; i <= index; i++)
		{
			d = mid - object[i].x;

			f_left += object[i].m / (d * d);
		}

		// 오른쪽 힘 구하기
		for (int i = index + 1; i < objects; i++)
		{
			d = object[i].x - mid;

			f_right += object[i].m / (d * d);
		}

		// printf("f_left = %.10f, f_right = %.10f\n", f_left, f_right);

		// 오른쪽 힘이 더 크면
		if (f_left < f_right)
		{
			// 균형점을 왼쪽에서 찾는다
			right = mid;
		}
		// 왼쪽 힘이 더 크면
		else if (f_left > f_right)
		{
			// 균형점을 오른쪽에서 찾는다
			left = mid;
		}
		// 두 힘이 서로 같으면
		else
		{
			// 균형점 출력
			return mid;
		}
	}

	// 균형점 출력
	return mid;
}

int main()
{
    // std::cout << "Hello World!\n"; 

	int testcase = 0;

	scanf("%d", &testcase);

	for (int t = 1; t <= testcase; t++)
	{
		double ans = 0;

		objects = 0;

		scanf("%d", &objects);

		for (int i = 0; i < MAX_OBJECTS; i++)
		{
			object[i].x = 0;
			object[i].m = 0;
		}

		for (int i = 0; i < objects; i++)
		{
			scanf("%d", &object[i].x);
		}

		for (int i = 0; i < objects; i++)
		{
			scanf("%d", &object[i].m);
		}

		/*
		for (int i = 0; i < objects; i++)
		{
			printf("%d %d\n", object[i].x, object[i].m);
		}
		*/

		printf("#%d ", t);

		for (int i = 0; i < objects - 1; i++)
		{
			ans = binary_search(i);

			printf("%.10f ", ans);
		}

		printf("\n");
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
