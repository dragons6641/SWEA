// KJOSW1225.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#define TESTCASE 10
#define PASSWORD_LENGTH 8
#define CYCLE_COUNT 5

/*
#include "pch.h"
#include <iostream>
*/

#include <stdio.h>
#include <queue>

using namespace std;

int password_list[PASSWORD_LENGTH] = { 0 };

void cycle()
{
	queue<int> q;

	int cur = 0;

	for (int i = 0; i < PASSWORD_LENGTH; i++)
	{
		q.push(password_list[i]);
	}

	while (1)
	{
		// 한 사이클
		for (int j = 1; j <= CYCLE_COUNT; j++)
		{
			cur = q.front();

			q.pop();

			//넣을 값이 0보다 큰 경우
			if (cur - j > 0)
			{
				// 값을 큐에 push
				q.push(cur - j);
			}
			//넣을 값이 0 이하인 경우
			else
			{
				// 0을 큐에 push
				q.push(0);

				for (int k = 0; k < PASSWORD_LENGTH; k++)
				{
					password_list[k] = q.front();

					q.pop();
				}

				// 암호 생성 종료
				return;
			}
		}
	}

	return;
}

int main()
{
    // std::cout << "Hello World!\n"; 

	int num = 0;

	for (int t = 1; t <= TESTCASE; t++)
	{
		scanf("%d", &num);

		for (int i = 0; i < PASSWORD_LENGTH; i++)
		{
			scanf("%d", &password_list[i]);
		}

		cycle();

		printf("#%d ", t);

		for (int i = 0; i < PASSWORD_LENGTH; i++)
		{
			printf("%d ", password_list[i]);
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
