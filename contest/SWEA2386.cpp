// KJOSW2386.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_N 100000

int main()
{
	// std::cout << "Hello World!\n"; 

	int t = 0;

	scanf("%d", &t);

	// printf("t = %d\n", t);

	for (int i = 0; i < t; i++)
	{
		int n = 0;
		int index = 0;
		int ans = 0;

		int num_list[MAX_N] = { 0 };
		int check[MAX_N] = { 0 };

		scanf("%d", &n);

		// printf("n = %d\n", n);

		for (int j = 0; j < n; j++)
		{
			int cur = 0;
			int isEqual = 0;

			scanf("%d", &cur);

			/*
			printf("cur = %d\n", cur);
			printf("index = %d\n", index);
			*/

			for (int k = 0; k < index; k++)
			{
				if (num_list[k] == cur)
				{
					isEqual = 1;

					if (check[k] == 1)
					{
						check[k] = 0;
					}
					else
					{
						check[k] = 1;
					}

					break;
				}
			}

			if (!isEqual)
			{
				num_list[index] = cur;
				check[index] = 1;

				index += 1;
			}

			/*
			num_list[j] = cur;
			ans += 1;

			for (int k = 0; k < j; k++)
			{
				if (num_list[k] == cur)
				{
					num_list[j] = 0;
					num_list[k] = 0;
					ans -= 2;

					break;
				}
			}
			*/

			/*
			for (int k = 0; k < n; k++)
			{
				printf("%d ", num_list[k]);
			}

			printf("\n");

			for (int k = 0; k < n; k++)
			{
				printf("%d ", check[k]);
			}

			printf("\n");
			*/
		}

		for (int j = 0; j < index; j++)
		{
			if (check[j] == 1)
			{
				ans += 1;
			}
		}

		printf("#%d %d\n", i + 1, ans);
	}
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
