// KJOSW1228.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#define TESTCASE 10
#define MAX_PRINT 10

/*
#include "pch.h"
#include <iostream>
*/

#include <stdio.h>
#include <list>

using namespace std;

int main()
{
	int msg_len = 0;
	int cmd_len = 0;
	int cur_int = 0;
	int x = 0;
	int y = 0;
	int s = 0;
	int iter_cnt = 0;
	char cur_ch = 0;

	for (int t = 1; t <= TESTCASE; t++)
	{
		list<int> lt;
		list<int> ::iterator iter;

		// 암호문의 길이
		scanf("%d", &msg_len);

		// printf("msg_len = %d\n", msg_len);

		// 암호문 입력
		for (int i = 0; i < msg_len; i++)
		{
			scanf("%d", &cur_int);

			lt.push_back(cur_int);
		}

		// 명령어의 길이
		scanf("%d", &cmd_len);

		// printf("cmd_len = %d\n", cmd_len);

		// 명령어 입력
		for (int i = 0; i < cmd_len; i++)
		{
			// printf("i = %d\n", i);

			getchar();

			scanf("%c", &cur_ch);

			// printf("cur_ch = %c\n", cur_ch);

			// 삽입
			if (cur_ch == 'I')
			{
				scanf("%d %d", &x, &y);

				// printf("x = %d, y = %d\n", x, y);

				iter_cnt = 0;

				for (iter = lt.begin(); iter != lt.end(); iter++)
				{
					iter_cnt += 1;

					if (iter_cnt > x)
					{
						break;
					}
				}

				for (int j = 0; j < y; j++)
				{
					scanf("%d", &s);

					// printf("s = %d\n", s);

					lt.insert(iter, s);
				}

				/*
				printf("list = ");

				for (iter = lt.begin(); iter != lt.end(); iter++)
				{
					printf("%d ", *iter);
				}

				printf("\n");
				*/
			}
		}

		/*
		printf("list = ");

		for (iter = lt.begin(); iter != lt.end(); iter++)
		{
			printf("%d ", *iter);
		}

		printf("\n");
		*/

		printf("#%d ", t);

		iter_cnt = 0;

		for (iter = lt.begin(); iter != lt.end(); iter++)
		{
			printf("%d ", *iter);

			iter_cnt += 1;

			if (iter_cnt >= MAX_PRINT)
			{
				break;
			}
		}

		printf("\n");
	}

    // std::cout << "Hello World!\n"; 

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
