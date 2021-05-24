// KJOSW1240.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#define MAX_N 50
#define MAX_M 100
#define CODE_NUM 8
#define CODE_DIGIT 7
#define CODE_LENGTH (CODE_NUM * CODE_DIGIT)

/*
#include "pch.h"
#include <iostream>
*/

#include <stdio.h>
#include <string.h>

int main()
{
    // std::cout << "Hello World!\n"; 

	int testcase = 0;

	scanf("%d", &testcase);

	for (int t = 1; t <= testcase; t++)
	{
		int n = 0;
		int m = 0;
		int start_row = -1;
		int start_col = -1;
		int end_row = MAX_N + 1;
		int end_col = MAX_M + 1;
		int ans = 0;

		int num[CODE_NUM] = { 0 };
		char digit[CODE_DIGIT + 1] = { '\0' };
		char matrix[MAX_N][MAX_M + 1] = { '\0' };

		scanf("%d %d", &n, &m);

		for (int row = 0; row < n; row++)
		{
			scanf("%s", &matrix[row]);
		}

		/*
		for (int row = 0; row < n; row++)
		{
			for (int col = 0; col < m; col++)
			{
				printf("%c", matrix[row][col]);
			}

			printf("\n");
		}
		*/

		// 전체 반복
		for (int row = 0; row < n; row++)
		{
			for (int col = 0; col < m; col++)
			{
				// 암호 코드가 있는 줄일 때
				if (matrix[row][col] == '1')
				{
					// 시작 위치가 아직 정해지지 않았다면
					if ((start_row == -1) && (start_col == -1))
					{
						// 시작 위치 설정
						start_row = row;
						start_col = col;
					}

					// 끝 위치 설정
					end_row = row;
					end_col = col;
				}
			}
		}

		start_col = end_col - CODE_LENGTH + 1;

		/*
		printf("start = (%d, %d)\n", start_row, start_col);
		printf("end = (%d, %d)\n", end_row, end_col);
		*/

		// 암호코드만 반복
		for (int row = start_row; row <= end_row; row++)
		{
			int index = 0;
			int sum = 0;

			for (int col = start_col; col <= end_col; col += CODE_DIGIT)
			{
				for (int k = 0; k < CODE_DIGIT; k++)
				{
					digit[k] = matrix[row][col + k];
				}

				// printf("digit = %s\n", digit);

				// 0
				if (!strcmp(digit, "0001101"))
				{
					num[index] = 0;
				}
				// 1
				else if (!strcmp(digit, "0011001"))
				{
					num[index] = 1;
				}
				// 2
				else if (!strcmp(digit, "0010011"))
				{
					num[index] = 2;
				}
				// 3
				else if (!strcmp(digit, "0111101"))
				{
					num[index] = 3;
				}
				// 4
				else if (!strcmp(digit, "0100011"))
				{
					num[index] = 4;
				}
				// 5
				else if (!strcmp(digit, "0110001"))
				{
					num[index] = 5;
				}
				// 6
				else if (!strcmp(digit, "0101111"))
				{
					num[index] = 6;
				}
				// 7
				else if (!strcmp(digit, "0111011"))
				{
					num[index] = 7;
				}
				// 8
				else if (!strcmp(digit, "0110111"))
				{
					num[index] = 8;
				}
				// 9
				else if (!strcmp(digit, "0001011"))
				{
					num[index] = 9;
				}
				// error
				else
				{
					num[index] = -1;
				}

				index += 1;
			}

			/*
			printf("num = ");

			for (int j = 0; j < CODE_NUM; j++)
			{
				printf("%d", num[j]);
			}

			printf("\n");
			*/

			// 검증
			for (int j = 0; j < CODE_NUM - 1; j++)
			{
				// 짝수번째
				if (j % 2)
				{
					sum += num[j];
				}
				// 홀수번째
				else
				{
					sum += (num[j] * 3);
				}
			}

			// 검증코드가 옳지 않을 경우
			if (((sum + num[CODE_NUM - 1]) % 10))
			{
				ans = 0;
			}
			// 검증코드가 옳을 경우
			else
			{
				sum = 0;

				for (int k = 0; k < CODE_NUM; k++)
				{
					sum += num[k];
				}

				ans = sum;
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
