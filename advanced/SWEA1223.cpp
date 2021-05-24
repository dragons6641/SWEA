// KJOSW1223.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
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

char infix[STRING_LENGTH] = { '\0' };
char postfix[STRING_LENGTH] = { '\0' };

int convert(int len)
{
	char cur = '\0';
	int index = 0;

	stack<char> s;

	for (int i = 0; i < len; i++)
	{
		cur = infix[i];

		// + 연산자일 경우
		if (cur == '+')
		{
			// 스택이 비어있지 않다면
			while (!s.empty())
			{
				// 남은 연산자를 모두 pop
				postfix[index] = s.top();
				index += 1;

				s.pop();
			}

			// 자신을 스택에 push
			s.push(cur);
		}
		// * 연산자일 경우
		else if (cur == '*')
		{
			// 스택이 비어있지 않다면
			if (!s.empty())
			{
				// 스택에 있는 것을 확인하여 비교
				char tmp = s.top();

				// 비교할 연산자가 +일 경우
				if (tmp == '+')
				{
					// 작업 필요 없음
				}
				// 비교할 연산자가 *일 경우
				else if (tmp == '*')
				{
					// 연산자를 꺼내어 배열에 보관
					postfix[index] = tmp;
					index += 1;

					s.pop();
				}
			}
			// 자신을 스택에 push
			s.push(cur);
		}
		// 정수일 경우
		else
		{
			// 연산식에 추가
			postfix[index] = cur;
			index += 1;
		}

		/*
		printf("index = %d, stack_size = %d\n", index, s.size());
		printf("%s\n", postfix);
		*/
	}

	// 스택이 비어있지 않다면
	while (!s.empty())
	{
		// 남은 연산자를 모두 pop
		postfix[index] = s.top();
		index += 1;

		s.pop();
	}

	// printf("%s\n", postfix);

	return index;
}

int calculate(int len)
{
	int result = 0;
	int a = 0;
	int b = 0;
	char cur = '\0';

	stack<int> s;

	for (int i = 0; i < len; i++)
	{
		cur = postfix[i];

		// + 연산자일 경우
		if (cur == '+')
		{
			b = s.top();

			s.pop();

			a = s.top();

			s.pop();

			// 연산 후 스택에 push
			s.push(a + b);
		}
		// * 연산자일 경우
		else if (cur == '*')
		{
			b = s.top();

			s.pop();

			a = s.top();
			
			s.pop();

			// 연산 후 스택에 push
			s.push(a * b);
		}
		// 정수일 경우
		else
		{
			// 스택에 push
			s.push((int)(cur - '0'));
		}
	}

	result = s.top();

	s.pop();

	return result;
}

int main()
{
	// std::cout << "Hello World!\n"; 

	int num = 0;
	int ans = 0;
	int cnt = 0;

	for (int t = 1; t <= TESTCASE; t++)
	{
		for (int i = 0; i < STRING_LENGTH; i++)
		{
			infix[i] = '\0';
			postfix[i] = '\0';
		}

		scanf("%d", &num);

		scanf("%s", &infix);

		// postfix로 수식 변환
		cnt = convert(num);

		// 결과값 계산
		ans = calculate(cnt);

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
