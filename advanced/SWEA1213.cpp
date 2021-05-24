// KJOSW1213.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#define TESTCASE 10
#define SENTENCE_LENGTH 1000
#define STRING_LENGTH 10

/*
#include "pch.h"
#include <iostream>
*/

#include <stdio.h>
#include <string.h>

int main()
{
    // std::cout << "Hello World!\n"; 

	int num = 0;

	char string_list[STRING_LENGTH + 1] = { "" };
	char sentence_list[SENTENCE_LENGTH + 1] = { "" };
	char temp_list[STRING_LENGTH + 1] = { "" };

	for (int t = 1; t <= TESTCASE; t++)
	{
		scanf("%d", &num);
		
		/*
		fgets(string_list, sizeof(string_list), stdin);
		fgets(sentence_list, sizeof(sentence_list), stdin);

		puts(string_list);
		puts(sentence_list);
		*/

		scanf("%s", &string_list);
		scanf("%s", &sentence_list);

		/*
		printf("%s\n", string_list);
		printf("%s\n", sentence_list);
		*/

		int a = strlen(string_list);
		int b = strlen(sentence_list);
		int ans = 0;

		// printf("string_list_length = %d, sentence_list_length = %d\n", a, b);

		for (int i = 0; i <= b - a; i++)
		{
			int cnt = 0;

			for (int j = 0; j < a; j++)
			{
				// printf("string = %c, sentence = %c\n", string_list[j], sentence_list[i + j]);

				if (string_list[j] != sentence_list[i + j])
				{
					break;
				}
				else
				{
					cnt += 1;
				}
			}

			if (cnt == a)
			{
				ans += 1;

				// printf("ans = %d\n", ans);
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
