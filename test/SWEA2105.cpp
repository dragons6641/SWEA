// KJOSW2105.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

/*
#include "pch.h"
#include <iostream>
*/

#include <stdio.h>

#define MAX_N 20
#define MAX_INPUT 100

int n = 0;
int ans = 0;
int tmp_1 = 0;
int tmp_2 = 0;
int max_ans = 0;

int matrix[MAX_N][MAX_N] = { 0 };
int isVisited[MAX_INPUT + 1] = { 0 };
int isInput[MAX_INPUT + 1] = { 0 };

int solve()
{
	int a = 0;
	int b = 0;
	int cur = 0;
	int isAlready = 0;

	for (int sum = (max_ans / 2); sum >= 2; sum--)
	{
		for (int row = 0; row < n; row++)
		{
			// printf("%dth row\n", row);

			for (int col = 1; col < n - 1; col++)
			{
				// printf("%dth col\n", col);

				for (int a = (max_ans / 2) - 1; a >= 1; a--)
				{
					isAlready = 0;

					for (int j = 1; j <= MAX_INPUT; j++)
					{
						isVisited[j] = 0;
					}

					b = sum - a;

					if ((b >= 1) && ((col + a) <= (n - 1)) && ((col - b) >= 0) && ((row + a + b) <= n - 1))
					{
						/*
						printf("%dth row, %dth col\n", row, col);
						printf("(%d, %d)\n", a, b);
						*/

						// printf("(%d, %d) = %d\n", row, col, matrix[row][col]);

						// 5시방향
						if (!isAlready)
						{
							for (int x = 1; x <= a; x++)
							{
								cur = matrix[row + x][col + x];

								// printf("(%d, %d) = %d\n", row + x, col + x, cur);

								if (isVisited[cur] == 1)
								{
									isAlready = 1;
									break;
								}
								else
								{
									isVisited[cur] = 1;
								}
							}
						}

						// 7시방향
						if (!isAlready)
						{
							for (int y = 1; y <= b; y++)
							{
								cur = matrix[row + a + y][col + a - y];

								// printf("(%d, %d) = %d\n", row + a + y, col + a - y, cur);

								if (isVisited[cur] == 1)
								{
									isAlready = 1;
									break;
								}
								else
								{
									isVisited[cur] = 1;
								}
							}
						}

						// 11시방향
						if (!isAlready)
						{
							for (int x = 1; x <= a; x++)
							{
								cur = matrix[row + a + b - x][col + a - b - x];

								// printf("(%d, %d) = %d\n", row + a + b - x, col + a - b - x, cur);

								if (isVisited[cur] == 1)
								{
									isAlready = 1;
									break;
								}
								else
								{
									isVisited[cur] = 1;
								}
							}
						}

						// 1시방향
						if (!isAlready)
						{
							for (int y = 1; y <= b; y++)
							{
								cur = matrix[row + b - y][col - b + y];

								// printf("(%d, %d) = %d\n", row + b - y, col - b + y, cur);

								if (isVisited[cur] == 1)
								{
									isAlready = 1;
									break;
								}
								else
								{
									isVisited[cur] = 1;
								}
							}
						}

						// printf("\n");

						if (!isAlready)
						{
							return (sum * 2);
						}
					}	
				}
			}
		}
	}

	return -1;
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
		ans = 0;
		tmp_1 = 0;
		tmp_2 = 0;
		max_ans = 0;

		matrix[MAX_N][MAX_N] = { 0 };
		isVisited[MAX_INPUT + 1] = { 0 };
		isInput[MAX_INPUT + 1] = { 0 };

		for (int row = 0; row < MAX_N; row++)
		{
			for (int col = 0; col < MAX_N; col++)
			{
				matrix[row][col] = 0;
			}
		}

		for (int j = 1; j <= MAX_INPUT; j++)
		{
			isVisited[j] = 0;
			isInput[j] = 0;
		}

		scanf("%d", &n);

		// printf("n = %d\n", n);

		for (int row = 0; row < n; row++)
		{
			for (int col = 0; col < n; col++)
			{
				scanf("%d", &matrix[row][col]);

				if (isInput[matrix[row][col]] == 0)
				{
					isInput[matrix[row][col]] = 1;
					tmp_2 += 1;
				}
			}
		}

		tmp_1 = (n - 1) * 2;

		if ((tmp_2 % 2) == 1)
		{
			tmp_2 -= 1;
		}

		if (tmp_1 < tmp_2)
		{
			max_ans = tmp_1;
		}
		else
		{
			max_ans = tmp_2;
		}

		/*
		for (int row = 0; row < n; row++)
		{
			for (int col = 0; col < n; col++)
			{
				printf("%d ", matrix[row][col]);
			}

			printf("\n");
		}
		*/

		/*
		for (int j = 1; j <= MAX_INPUT; j++)
		{
			printf("%d ", isVisited[j]);
		}

		printf("\n");
		//*/

		/*
		for (int j = 1; j <= MAX_INPUT; j++)
		{
			printf("%d ", isInput[j]);
		}

		printf("\n");
		*/

		// printf("min(%d, %d) = %d\n", tmp_1, tmp_2, max_ans);  

		if (tmp_1 == (n * n))
		{
			ans = max_ans;
		}
		else
		{
			ans = solve();
		}

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
