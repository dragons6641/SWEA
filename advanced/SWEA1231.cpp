// KJOSW1231.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#define TESTCASE 10
#define MAX_LENGTH 7
#define MAX_NUM 100

/*
#include "pch.h"
#include <iostream>
*/

#include <stdio.h>
#include <string.h>

typedef struct node {
	int num = 0;
	char ch = '\0';
	int left = 0;
	int right = 0;
} NODE;

int cnt = 0;

NODE tree[MAX_NUM + 1];

void inorder(int cur)
{
	int num = tree[cur].num;
	char ch = tree[cur].ch;
	int left = tree[cur].left;
	int right = tree[cur].right;

	// printf("cur = %d, left = %d, right = %d\n", cur, left, right);

	// 왼쪽 자식 트리가 있으면
	if (left > 0)
	{
		// 왼쪽 자식 트리 탐색
		inorder(left);
	}

	// 알파벳 출력
	printf("%c", ch);

	// 오른쪽 자식 트리가 있으면
	if (right > 0)
	{
		// 오른쪽 자식 트리 탐색
		inorder(right);
	}

	return;
}

int main()
{
    // std::cout << "Hello World!\n"; 

	for (int t = 1; t <= TESTCASE; t++)
	{
		int len = 0;

		char tmp[MAX_LENGTH + 1] = { '\0' };

		cnt = 0;

		for (int i = 1; i <= MAX_NUM; i++)
		{
			tree[i].num = 0;
			tree[i].ch = '\0';
			tree[i].left = 0;
			tree[i].right = 0;
		}

		scanf("%d\n", &cnt);

		// printf("cnt = %d\n", cnt);

		for (int i = 1; i <= cnt; i++)
		{
			// scanf("%d %c %d %d\n", &tree[i].num, &tree[i].ch, &tree[i].left, &tree[i].right);

			scanf("%d ", &tree[i].num);

			// printf("num = %d\n", tree[i].num);

			// 자식 노드 2개
			if ((i * 2) < cnt)
			{
				scanf("%c %d %d\n", &tree[i].ch, &tree[i].left, &tree[i].right);
			}

			// 자식 노드 1개
			else if ((i * 2) == cnt)
			{
				scanf("%c %d\n", &tree[i].ch, &tree[i].left);
			}

			// 자식 노드 0개
			else
			{
				scanf("%c\n", &tree[i].ch);
			}
		}

		/*
		for (int i = 1; i <= cnt; i++)
		{
			printf("%d %c %d %d\n", tree[i].num, tree[i].ch, tree[i].left, tree[i].right);
		}
		*/

		printf("#%d ", t);

		inorder(1);

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
