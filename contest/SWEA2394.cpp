// KJOSW2394.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define MAX_R 8
#define MAX_N 200
#define MAX_C 100000

int n = 0;
int m = 0;
int r = 0;
int a = 0;
int b = 0;
int c = 0;
int ans = MAX_C + 1;
int result = 0;
int tmp = 0;

int matrix[MAX_N + 1][MAX_N + 1] = { MAX_C + 1 };
int visit_list[MAX_R] = { 0 };
// int visit_matrix[MAX_R][MAX_R] = { MAX_C + 1 };

void swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void dijkstra(int start)
{
	int dist[MAX_N + 1];
	int isVisited[MAX_N + 1] = { 0 };

	int min_value = MAX_C + 1;
	int next = 0;

	memcpy(dist, matrix[start], sizeof(matrix[start]));

	/*
	printf("before dijkstra\n");

	for (int i = 1; i <= n; i++)
	{
		printf("%d ", dist[i]);
	}

	printf("\n");
	*/

	for (int i = 1; i <= n; i++)
	{
		min_value = MAX_C + 1;

		for (int j = 1; j <= n; j++)
		{
			if ((isVisited[j] == 0) && (dist[j] < min_value))
			{
				min_value = dist[j];
				next = j;
			}
		}

		isVisited[next] = 1;

		for (int j = 1; j <= n; j++)
		{
			if (dist[j] > dist[next] + matrix[next][j])
			{
				dist[j] = dist[next] + matrix[next][j];
			}
		}
	}

	/*
	printf("after dijkstra\n");

	for (int i = 1; i <= n; i++)
	{
		printf("%d ", dist[i]);
	}

	printf("\n");
	*/

	memcpy(matrix[start], dist, sizeof(dist));

	return;
}

void permutation(int nn, int rr)
{
	if (rr == 0)
	{
		result = 0;

		for (int j = 0; j < r - 1; j++)
		{
			result += matrix[visit_list[j]][visit_list[j + 1]];

			// printf("start = %d, end = %d, result = %d\n", visit_list[j], visit_list[j + 1], result);
		}

		// printf("result = %d, ans = %d\n", result, ans);

		if (result < ans)
		{
			ans = result;
		}

		return;
	}

	for (int i = nn - 1; i >= 0; i--) 
	{
		swap(&visit_list[i], &visit_list[nn - 1]);

		permutation(nn - 1, rr - 1);

		swap(&visit_list[i], &visit_list[nn - 1]);
	}
}

int main()
{
    // std::cout << "Hello World!\n"; 

	int t = 0;

	scanf("%d", &t);

	// printf("t = %d\n", t);

	for (int i = 0; i < t; i++)
	{
		n = 0;
		m = 0;
		r = 0;
		a = 0;
		b = 0;
		c = 0;
		ans = MAX_C + 1;
		result = 0;
		tmp = 0;

		for (int j = 0; j < MAX_R; j++)
		{
			visit_list[j] = 0;
		}
		
		for (int aa = 1; aa <= MAX_N; aa++)
		{
			for (int bb = 1; bb <= MAX_N; bb++)
			{
				if (aa != bb)
				{
					matrix[aa][bb] = MAX_C + 1;
				}
				
				else
				{
					matrix[aa][bb] = 0;
				}
			}
		}

		/*
		for (int aa = 0; aa < MAX_R; aa++)
		{
			for (int bb = 0; bb < MAX_R; bb++)
			{
				if (aa != bb)
				{
					visit_matrix[aa][bb] = MAX_C + 1;
				}

				else
				{
					visit_matrix[aa][bb] = 0;
				}
			}
		}
		*/

		scanf("%d %d %d", &n, &m, &r);

		// printf("n = %d, m = %d, r = %d\n", n, m, r);

		for (int j = 0; j < r; j++)
		{
			scanf("%d", &visit_list[j]);
		}

		/*
		printf("visit_list = ");

		for (int j = 0; j < r; j++)
		{
			printf("%d ", visit_list[j]);
		}

		printf("\n");
		*/

		for (int j = 0; j < m; j++)
		{
			scanf("%d %d %d", &a, &b, &c);

			matrix[a][b] = c;
			matrix[b][a] = c;
		}

		/*
		for (int aa = 1; aa <= n; aa++)
		{
			for (int bb = 1; bb <= n; bb++)
			{
				printf("%d ", matrix[aa][bb]);
			}

			printf("\n");
		}
		*/

		/*
		for (int aa = 0; aa < r; aa++)
		{
			for (int bb = 0; bb < aa; bb++)
			{
				// printf("start = %d, end = %d\n", visit_list[aa], visit_list[bb]);

				tmp = dijkstra(visit_list[aa], visit_list[bb]);
				visit_matrix[aa][bb] = tmp;
				visit_matrix[bb][aa] = tmp;
			}
		}
		*/

		for (int j = 0; j < r; j++)
		{
			dijkstra(visit_list[j]);
		}

		/*
		for (int aa = 0; aa < r; aa++)
		{
			for (int bb = 0; bb < r; bb++)
			{
				// printf("%d ", visit_matrix[aa][bb]);
				printf("%d ", matrix[visit_list[aa]][visit_list[bb]]);
			}

			printf("\n");
		}
		*/

		permutation(r, r);

		printf("#%d %d\n", i + 1, ans);
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
