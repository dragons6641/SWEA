// KJOSW1248.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#define MAX_V 10000
#define ROOT 1

/*
#include "pch.h"
#include <iostream>
*/

#include <stdio.h>

typedef struct node {
	// 자신의 노드 번호
	int value = 0;

	// 전체 트리에서의 높이
	int height = 0;

	// 부모 노드 번호
	int parent = 0;

	// 왼쪽 자식 노드 번호
	int left = 0;

	// 오른쪽 자식 노드 번호
	int right = 0;
} NODE;

NODE tree[MAX_V + 1];

// 현재 노드의 높이
int cur_height = 0;

// 서브 트리의 노드 갯수
int cnt = 0;

void inorder_height(int r)
{
	int left = tree[r].left;
	int right = tree[r].right;

	// 높이 증가
	cur_height += 1;

	// 왼쪽 노드에 자식이 있다면
	if (left != 0)
	{
		// 왼쪽 자식 탐색
		inorder_height(left);
	}

	// 높이 기록
	tree[r].height = cur_height;

	// 오른쪽 노드에 자식이 있다면
	if (right != 0)
	{
		// 오른쪽 자식 탐색
		inorder_height(right);
	}

	// 높이 감소
	cur_height -= 1;

	return;
}

int find_ancestor(int x, int y)
{
	int result = 0;

	int height_x = tree[x].height;
	int height_y = tree[y].height;
	int height_diff = 0;

	// x의 높이가 더 높다면
	if (height_x > height_y)
	{
		// 높이 차이 계산
		height_diff = height_x - height_y;

		for (int i = 0; i < height_diff; i++)
		{
			// 부모로 올라가서
			x = tree[x].parent;

			// 높이를 맞춰준다
			height_x -= 1;
		}
	}
	// y의 높이가 더 높다면
	else if (height_x < height_y)
	{
		// 높이 차이 계산
		height_diff = height_y - height_x;

		for (int i = 0; i < height_diff; i++)
		{
			// 부모로 올라가서
			y = tree[y].parent;

			// 높이를 맞춰준다
			height_y -= 1;
		}
	}

	// printf("x = %d, y = %d, height_x = %d, height_y = %d\n", x, y, height_x, height_y);

	// 공통조상 찾을 때까지
	while (1)
	{
		if (x == y)
		{
			return x;
		}

		x = tree[x].parent;
		y = tree[y].parent;
	}

	return ROOT;
}

void inorder_count(int r)
{
	int left = tree[r].left;
	int right = tree[r].right;

	// 왼쪽 노드에 자식이 있다면
	if (left != 0)
	{
		// 왼쪽 자식 탐색
		inorder_count(left);
	}

	// 갯수 세기
	cnt += 1;

	// 오른쪽 노드에 자식이 있다면
	if (right != 0)
	{
		// 오른쪽 자식 탐색
		inorder_count(right);
	}

	return;
}

int main()
{
    // std::cout << "Hello World!\n"; 

	int testcase = 0;

	scanf("%d", &testcase);

	for (int t = 1; t <= testcase; t++)
	{
		// 구조체 배열 초기화
		for (int i = 1; i <= MAX_V; i++)
		{
			tree[i].value = i;
			tree[i].height = 0;
			tree[i].parent = 0;
			tree[i].left = 0;
			tree[i].right = 0;
		}

		// 정점 수
		int v = 0;

		// 간선 수
		int e = 0;

		// 공통 조상 찾을 첫 번째 노드 번호
		int a = 0;

		// 공통 조상 찾을 두 번째 노드 번호
		int b = 0;

		// 공통 조상의 노드 번호
		int ans = 0;

		cnt = 0;

		scanf("%d %d %d %d", &v, &e, &a, &b);

		for (int i = 0; i < e; i++)
		{
			// 부모 노드 번호
			int parent = 0;

			// 자식 노드 번호
			int child = 0;

			scanf("%d %d", &parent, &child);

			// 부모 노드에 자식 기록하기
			if (tree[parent].left != 0)
			{
				tree[parent].right = child;
			}
			else
			{
				tree[parent].left = child;
			}

			// 자식 노드에 부모 기록하기
			tree[child].parent = parent;
		}

		// inorder로 순회하며 height 기록
		inorder_height(ROOT);

		/*
		for (int i = 1; i <= v; i++)
		{
			printf("value = %d, height = %d, parent = %d, left = %d, right = %d\n", tree[i].value, tree[i].height, tree[i].parent, tree[i].left, tree[i].right);
		}
		*/

		// 공통조상 찾기
		ans = find_ancestor(a, b);

		// 서브 트리 갯수 구하기
		inorder_count(ans);

		printf("#%d %d %d\n", t, ans, cnt);
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
