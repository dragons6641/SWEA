// KJOSW1219.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#define TESTCASE 10
#define V 100
#define E 2

/*
#include "pch.h"
#include <iostream>
*/

#include <stdio.h>
#include <stack>

using namespace std;

int matrix[V][E] = { -1 };

int dfs()
{
	int cur = 0;
	int next = 0;

	stack<int> s;

	s.push(0);

	while (!s.empty())
	{
		cur = s.top();

		s.pop();

		if (cur == V - 1)
		{
			return 1;
		}

		for (int i = 0; i < E; i++)
		{
			next = matrix[cur][i];

			if (next != -1)
			{
				s.push(next);
			}
		}
	}

	return 0;
}

int main()
{
    // std::cout << "Hello World!\n"; 

	int n = 0;
	int m = 0;
	int ans = 0;

	for (int t = 1; t <= TESTCASE; t++)
	{
		int start_V = 0;
		int end_V = V - 1;

		for (int row = 0; row < V; row++)
		{
			for (int col = 0; col < E; col++)
			{
				matrix[row][col] = -1;
			}
		}

		scanf("%d %d", &n, &m);

		for (int i = 0; i < m; i++)
		{
			scanf("%d %d", &start_V, &end_V);

			if (matrix[start_V][0] == -1)
			{
				matrix[start_V][0] = end_V;
			}
			else
			{
				matrix[start_V][1] = end_V;
			}
		}

		ans = dfs();

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
