// KJOSW1230.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#define TESTCASE 10
#define MAX_PRINT 10

/*
#include "pch.h"
#include <iostream>
*/

/*
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
		list<int> ::iterator cur_iter;
		list<int> ::iterator next_iter;

		// 암호문의 길이
		scanf("%d", &msg_len);

		// printf("msg_len = %d\n", msg_len);

		// 암호문 입력
		// printf("START!\n\n");

		for (int i = 0; i < msg_len; i++)
		{
			scanf("%d", &cur_int);

			// printf("i = %d, cur_int = %d\n", i, cur_int);

			lt.push_back(cur_int);
		}

		// printf("END!\n\n");

		// fflush(stdin);

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

				for (cur_iter = lt.begin(); cur_iter != lt.end(); cur_iter++)
				{
					iter_cnt += 1;

					if (iter_cnt > x)
					{
						// printf("iter_cnt = %d\n", iter_cnt);

						break;
					}
				}

				for (int j = 0; j < y; j++)
				{
					scanf("%d", &s);

					// printf("s = %d\n", s);

					lt.insert(cur_iter, s);
				}
			}

			// 삭제
			else if (cur_ch == 'D')
			{
				scanf("%d %d", &x, &y);

				// printf("x = %d, y = %d\n", x, y);

				iter_cnt = 0;

				for (cur_iter = lt.begin(); cur_iter != lt.end(); cur_iter++)
				{
					iter_cnt += 1;

					if (iter_cnt > x)
					{
						// printf("iter_cnt = %d\n", iter_cnt);

						next_iter = cur_iter;
						next_iter++;

						break;
					}
				}

				for (int j = 0; j < y; j++)
				{
					lt.erase(cur_iter);

					cur_iter = next_iter;
					next_iter++;
				}
			}

			// 추가
			else if (cur_ch == 'A')
			{
				scanf("%d %d", &y, &s);

				// printf("y = %d, s = %d\n", y, s);

				for (int j = 0; j < y; j++)
				{
					scanf("%d", &s);

					// printf("s = %d\n", s);

					lt.insert(cur_iter, s);
				}

				for (int j = 0; j < y; j++)
				{
					scanf("%d", &s);

					// printf("s = %d\n", s);

					lt.push_back(s);
				}
			}
		}

		printf("#%d ", t);

		iter_cnt = 0;

		for (cur_iter = lt.begin(); cur_iter != lt.end(); cur_iter++)
		{
			printf("%d ", *cur_iter);

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
*/

// 나중에 공부하자!
#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlist {
	struct list* head;
	//    node* tail;
}linkedlist;

typedef struct list {
	int data;
	struct list* next;
}node;

void insertNode(linkedlist* l, int data, int flag) {//맨뒤에 삽입 flag=-1, else flag=정수
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	newNode->next = NULL;


	if (l->head == NULL)// && l->tail == NULL)
	{
		l->head = newNode;
		//        l->tail = newNode;
	}
	else {
		if (flag == -1) {
			node* ptr = l->head;
			while (ptr->next != NULL) {
				ptr = ptr->next;
			}
			ptr->next = newNode;
			//            l->tail->next = newNode;
			//            l->tail = newNode;
		}
		else if (flag == 0) {
			newNode->next = l->head;
			l->head = newNode;
		}
		else {
			node* ptr = l->head;
			for (int i = 0; i < flag - 1; i++) {
				ptr = ptr->next;
			}
			newNode->next = ptr->next;
			ptr->next = newNode;
		}
	}
}
void deleteNode(linkedlist* l, int flag) {
	node* ptr = l->head;
	for (int i = 0; i < flag - 1; i++) {
		ptr = ptr->next;
	}
	ptr->next = ptr->next->next;

}
void addNode(linkedlist* l, int data) {
	node* ptr = l->head;
	while (ptr->next != NULL) {
		ptr = ptr->next;
	}
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	newNode->next = NULL;

	ptr->next = newNode;
}
int main(void)
{
	setbuf(stdout, NULL);
	for (int test_case = 1; test_case <= 10; test_case++) {
		int n;
		scanf("%d", &n);
		linkedlist *l = (linkedlist*)malloc(sizeof(linkedlist));
		l->head = NULL;
		//    l->tail = NULL;

		for (int i = 0; i < n; i++) {
			int temp;
			scanf("%d", &temp);
			insertNode(l, temp, -1);
		}
		int k;
		scanf("%d\n", &k);
		for (int i = 0; i < k; i++) {
			char c;
			scanf("%c ", &c);
			//            scanf("%c", &c);
			if (c == 'I') {
				int a, b;
				scanf("%d %d ", &a, &b);
				for (int j = 0; j < b; j++) {
					int d;
					scanf("%d ", &d);
					insertNode(l, d, a + j);
				}
			}
			else if (c == 'D') {
				int a, b;
				scanf("%d %d ", &a, &b);
				for (int j = 0; j < b; j++) {
					deleteNode(l, a);
				}
			}
			else if (c == 'A') {
				int a;
				scanf("%d ", &a);
				for (int j = 0; j < a; j++) {
					int d;
					scanf("%d ", &d);
					addNode(l, d);
				}
			}
			else {
				printf("error\n");
			}
		}
		printf("#%d", test_case);
		node* ptr = l->head;
		for (int i = 0; i < 10; i++) {
			printf(" %d", ptr->data);
			ptr = ptr->next;
		}
		printf("\n");
	}
	return 0;
}


// 출처: https://ddoublej.tistory.com/185 [컴퓨터공부하기]

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
