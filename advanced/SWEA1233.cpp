// KJOSW1232.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#define TESTCASE 10

/*
#include "pch.h"
#include <iostream>
*/

#include <stdio.h>

int main()
{
    // std::cout << "Hello World!\n"; 

	for (int t = 1; t <= TESTCASE; t++)
	{
		int cnt = 0;
		int ans = 1;

		scanf("%d\n", &cnt);

		for (int i = 1; i <= cnt; i++)
		{
			int num = 0;
			char ch = '\0';
			int left = 0;
			int right = 0;

			scanf("%d ", &num);

			if ((i * 2) < cnt)
			{
				scanf("%c %d %d\n", &ch, &left, &right);
			}
			else if ((i * 2) == cnt)
			{
				scanf("%c %d\n", &ch, &left);
			}
			else
			{
				scanf("%c\n", &ch);
			}

			// printf("%d %c %d %d\n", num, ch, left, right);

			// 숫자일 경우
			if(((ch - '0') >= 0) && ((ch - '0') <= 9))
			{
				// printf("%c는 숫자입니다.\n", ch);

				// 양쪽 트리 중 하나라도 있다면
				if ((left > 0) || (right > 0))
				{
					ans = 0;

					// printf("%d %c %d %d\n", num, ch, left, right);
				}
			}

			// 연산자일 경우
			else
			{
				// printf("%c는 연산자입니다.\n", ch);

				// 양쪽 트리 중 하나라도 없다면
				if ((left <= 0) || (right <= 0))
				{
					ans = 0;

					// printf("%d %c %d %d\n", num, ch, left, right);
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
