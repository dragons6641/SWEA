// KJOSW1244.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#define MAX_DIGIT 6
#define DECIMAL 10

/*
#include "pch.h"
#include <iostream>
*/

#include <stdio.h>

int digit[MAX_DIGIT] = { 0 };
int check[DECIMAL] = { 0 };

void int_swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;

	return;
}

int to_digit(int q)
{
	int index = MAX_DIGIT;

	while (1)
	{
		index -= 1;

		// 나머지
		digit[index] = q % 10;

		// 몫
		q /= 10;

		if (q == 0)
		{
			break;
		}
	}

	for (int i = index; i < MAX_DIGIT; i++)
	{
		check[digit[i]] += 1;
	}

	/*
	for (int i = 0; i < MAX_DIGIT; i++)
	{
		printf("%d", digit[i]);
	}

	printf("\nindex = %d\n", index);
	*/

	return index;
}

void greedy_change(int s, int c)
{
	int remain_turn = c;
	int isSame = 0;

	for (int i = 0; i < DECIMAL; i++)
	{
		// 중복되는 자릿수가 있다면 표시
		if (check[i] > 1)
		{
			isSame = 1;

			break;
		}
	}

	// 선택 정렬
	for (int i = s; i < MAX_DIGIT; i++)
	{
		int max_index = i;
		int max_value = digit[i];

		for (int j = i + 1; j < MAX_DIGIT; j++)
		{
			int cur_index = j;
			int cur_value = digit[j];

			/*
			printf("cur_index = %d, cur_value = %d\n", cur_index, cur_value);
			printf("max_index = %d, max_value = %d\n", max_index, max_value);
			*/

			if (cur_value >= max_value)
			{
				max_index = cur_index;
				max_value = cur_value;
			}
		}

		// 교환
		if (digit[i] < digit[max_index])
		{
			remain_turn -= 1;

			if (digit[max_index] == digit[max_index - remain_turn])
			{
				int_swap(&digit[i], &digit[max_index - remain_turn]);
			}
			else
			{
				int_swap(&digit[i], &digit[max_index]);
			}
		}

		/*
		for (int j = s; j < MAX_DIGIT; j++)
		{
			printf("%d", digit[j]);
		}

		printf("\nremain_turn = %d\n\n", remain_turn);
		*/

		// 남은 교환 횟수가 0이면 
		if (remain_turn == 0)
		{
			return;
		}
	}

	// printf("remain_turn = %d\n", remain_turn);

	// 중복되는 것이 없고 남은 교환횟수가 홀수인 경우에만
	if ((!isSame) && (remain_turn % 2))
	{
		// 끝 두자리 한 번 교환
		int_swap(&digit[MAX_DIGIT - 2], &digit[MAX_DIGIT - 1]);
	}

	return;
}

int main()
{
    // std::cout << "Hello World!\n"; 

	int testcase = 0;

	scanf("%d", &testcase);

	for (int t = 1; t <= testcase; t++)
	{
		int num = 0;
		int change = 0;
		int start_pos = 0;

		for (int i = 0; i < MAX_DIGIT; i++)
		{
			digit[i] = 0;
		}

		for (int i = 0; i < DECIMAL; i++)
		{
			check[i] = 0;
		}

		scanf("%d %d", &num, &change);

		// 각각 자릿수 추출, 시작 위치 반환
		start_pos = to_digit(num);

		// 위치 바꾸기
		greedy_change(start_pos, change);

		printf("#%d ", t);

		for (int i = start_pos; i < MAX_DIGIT; i++)
		{
			printf("%d", digit[i]);
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
