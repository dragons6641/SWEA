// KJOSW1209.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#define TESTCASE 10
#define ROWS 100
#define COLS 100

/*
#include "pch.h"
#include <iostream>
*/

#include <stdio.h>

int main()
{
    // std::cout << "Hello World!\n"; 

	int num = 0;

	int number_list[ROWS][COLS] = { 0 };

	for (int t = 1; t <= TESTCASE; t++)
	{
		int temp1_sum = 0;
		int temp2_sum = 0;
		int ans = 0;

		scanf("%d", &num);

		for (int row = 0; row < ROWS; row++)
		{
			int row_sum = 0;

			for (int col = 0; col < COLS; col++)
			{
				scanf("%d", &number_list[row][col]);

				row_sum += number_list[row][col];
			}

			if (row_sum > ans)
			{
				ans = row_sum;
			}
		}

		for (int col = 0; col < COLS; col++)
		{
			int col_sum = 0;

			for (int row = 0; row < ROWS; row++)
			{
				col_sum += number_list[row][col];

				if (row == col)
				{
					temp1_sum += number_list[row][col];
				}

				if (row + col == ROWS - 1)
				{
					temp2_sum += number_list[row][col];
				}
			}

			if (col_sum > ans)
			{
				ans = col_sum;
			}
		}

		if (temp1_sum > ans)
		{
			ans = temp1_sum;
		}

		if (temp2_sum > ans)
		{
			ans = temp2_sum;
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
