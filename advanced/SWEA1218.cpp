// KJOSW1218.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#define TESTCASE 10
#define STRING_LENGTH 1000

/*
#include "pch.h"
#include <iostream>
*/

#include <stdio.h>
#include <stack>

using namespace std;

int num = 0;

char bracket_list[STRING_LENGTH] = {' '};

int bracket_check()
{
	stack<char> s;

	for (int i = 0; i < num; i++)
	{
		char cur = bracket_list[i];

		// printf("i = %d, cur = %c\n", i, cur);

		// 현재 값이 여는 괄호이면
		if ((cur == '(') || (cur == '[') || (cur == '{') || (cur == '<'))
		{
			// 스택에 푸쉬
			s.push(cur);
		}
		// 현재 값이 여는 괄호가 아니라면
		else
		{
			// 스택이 비어있으면
			if (s.size() == 0)
			{
				// 유효하지 않음
				return 0;
			}
			// 스택이 비어있지 않다면
			else
			{
				char top = s.top();

				// 닫는 괄호일 경우
				if (cur == ')')
				{
					// 짝이 맞으면
					if (top == '(')
					{
						// 여는 괄호짝을 스택에서 꺼냄
						s.pop();
					}
					// 짝이 맞지 않으면
					else
					{
						// 유효하지 않음
						return 0;
					}
				}
				else if (cur == ']')
				{
					if (top == '[')
					{
						s.pop();
					}
					else
					{
						return 0;
					}
				}
				else if (cur == '}')
				{
					if (top == '{')
					{
						s.pop();
					}
					else
					{
						return 0;
					}
				}
				else if (cur == '>')
				{
					if (top == '<')
					{
						s.pop();
					}
					else
					{
						return 0;
					}
				}
				// 괄호 문자가 아닐 경우
				else
				{
					// 유효하지 않음
					return 0;
				}
			}
		}
	}

	// 스택이 비어있다면
	if (s.size() == 0)
	{
		// 유효함
		return 1;
	}
	// 스택이 비어있지 않다면
	else
	{
		// 유효하지 않음
		return 0;
	}
}

int main()
{
	// std::cout << "Hello World!\n"; 

	int ans = 0;

	for (int t = 1; t <= TESTCASE; t++)
	{
		scanf("%d", &num);

		scanf("%s", &bracket_list);

		/*
		for (int i = 0; i < num; i++)
		{
			printf("%c", bracket_list[i]);
		}

		printf("\n");
		*/

		ans = bracket_check();

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
