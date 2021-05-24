// KJOSW1215.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#define TESTCASE 10
#define ROWS 8
#define COLS 8

/*
#include "pch.h"
#include <iostream>
*/

#include <stdio.h>

int main()
{
    // std::cout << "Hello World!\n"; 

	int num = 0;

	for (int t = 1; t <= TESTCASE; t++)
	{
		int ans = 0;

		char board[ROWS + 1][COLS + 1] = { "D" };

		scanf("%d", &num);

		for (int row = 0; row < ROWS; row++)
		{
			scanf("%s", &board[row]);
		}

		/*
		for (int row = 0; row < ROWS; row++)
		{
			for (int col = 0; col < COLS; col++)
			{
				printf("%c", board[row][col]);
			}

			printf("\n");
		}
		*/

		// printf("num = %d\n", num);

		for (int row = 0; row < ROWS; row++)
		{
			for (int col = 0; col <= COLS - num; col++)
			{
				// printf("row = %d, col = %d\n", row, col);

				int cnt = 0;
				int tmp = (int)(num / 2);

				for (int k = 0; k < tmp; k++)
				{
					if (board[row][col + k] != board[row][col + num - k - 1])
					{
						break;
					}
					else
					{
						cnt += 1;
					}
				}

				if (cnt == tmp)
				{
					ans += 1;

					// printf("ans = %d\n", ans);
				}
			}
		}

		for (int col = 0; col < COLS; col++)
		{
			for (int row = 0; row <= ROWS - num; row++)
			{
				// printf("row = %d, col = %d\n", row, col);

				int cnt = 0;
				int tmp = (int)(num / 2);

				for (int k = 0; k < tmp; k++)
				{
					if (board[row + k][col] != board[row + num - k - 1][col])
					{
						break;
					}
					else
					{
						cnt += 1;
					}
				}

				if (cnt == tmp)
				{
					ans += 1;

					// printf("ans = %d\n", ans);
				}
			}
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
