// KJOSW1208.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#define TESTCASE 10
#define WIDTH 100
#define HEIGHTS 100

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
		int num = 0;
		int height = 0;
		int min_height = 0;
		int max_height = HEIGHTS;
		int diff = HEIGHTS;

		int height_list[HEIGHTS + 1] = { 0 };

		scanf("%d", &num);

		for (int i = 0; i < WIDTH; i++)
		{
			scanf("%d", &height);

			height_list[height] += 1;
		}

		for (int i = 1; i <= HEIGHTS; i++)
		{
			if (height_list[i] > 0)
			{
				max_height = i;

				if (min_height == 0)
				{
					min_height = i;
				}
			}
		}
		
		for (int i = 0; i < num; i++)
		{
			height_list[max_height] -= 1;
			height_list[max_height - 1] += 1;

			height_list[min_height] -= 1;
			height_list[min_height + 1] += 1;

			if (height_list[max_height] == 0)
			{
				max_height -= 1;
			}

			if (height_list[min_height] == 0)
			{
				min_height += 1;
			}

			diff = max_height - min_height;

			if (diff <= 1)
			{
				break;
			}
		}

		printf("#%d %d\n", t, diff);
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
