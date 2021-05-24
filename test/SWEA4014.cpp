// KJOSW4014.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

/*
#include "pch.h"
#include <iostream>
*/

#include <stdio.h>

#define MAX_N 20

int n = 0;
int x = 0;
int ans = 0;

int matrix[MAX_N][MAX_N] = { 0 };
int slope[MAX_N][MAX_N] = { 0 };

void check()
{
	int cur = 0;
	int prev = 0;
	int cur_cnt = 0;
	int prev_cnt = 0;
	int isImpossible = 0;

	for (int row = 0; row < MAX_N; row++)
	{
		for (int col = 0; col < MAX_N; col++)
		{
			slope[row][col] = 0;
		}
	}

	// 가로 방향
	for (int row = 0; row < n; row++)
	{
		isImpossible = 0;

		if (isImpossible == 0)
		{
			cur_cnt = 1;
			prev_cnt = 0;

			// 오른쪽으로 탐색
			for (int col = 1; col <= n - 1; col++)
			{
				cur = matrix[row][col];
				prev = matrix[row][col - 1];

				// 같은 경우
				if (cur == prev)
				{
					cur_cnt += 1;
				}
				else
				{
					prev_cnt = cur_cnt;
					cur_cnt = 1;

					// 높아진 경우
					if (cur > prev + 1)
					{
						isImpossible = 1;

						break;
					}
					else if (cur == prev + 1)
					{
						// printf("prev_cnt = %d, x = %d\n", prev_cnt, x);

						if (prev_cnt >= x)
						{
							for (int b = col - x; b < col; b++)
							{
								slope[row][b] += 1;
							}
						}
						else
						{
							isImpossible = 1;

							break;
						}
					}
				}
			}
		}

		if (isImpossible == 0)
		{
			cur_cnt = 1;
			prev_cnt = 0;

			// 왼쪽으로 탐색
			for (int col = n - 2; col >= 0; col--)
			{
				cur = matrix[row][col];
				prev = matrix[row][col + 1];

				// 같은 경우
				if (cur == prev)
				{
					cur_cnt += 1;
				}
				else
				{
					prev_cnt = cur_cnt;
					cur_cnt = 1;

					// 높아진 경우
					if (cur > prev + 1)
					{
						isImpossible = 1;

						break;
					}
					else if (cur == prev + 1)
					{
						// printf("prev_cnt = %d, x = %d\n", prev_cnt, x);

						if (prev_cnt >= x)
						{
							for (int b = col + x; b > col; b--)
							{
								slope[row][b] += 1;
							}
						}
						else
						{
							isImpossible = 1;

							break;
						}
					}
				}
			}
		}

		for (int col = 0; col < n; col++)
		{
			if (slope[row][col] > 1)
			{
				isImpossible = 1;

				break;
			}
		}

		if (isImpossible == 0)
		{
			ans += 1;

			// printf("%dth row\n", row);
		}
	}

	for (int row = 0; row < MAX_N; row++)
	{
		for (int col = 0; col < MAX_N; col++)
		{
			slope[row][col] = 0;
		}
	}

	// 세로 방향
	for (int col = 0; col < n; col++)
	{
		isImpossible = 0;

		if (isImpossible == 0)
		{
			cur_cnt = 1;
			prev_cnt = 0;

			// 아래쪽으로 탐색
			for (int row = 1; row <= n - 1; row++)
			{
				cur = matrix[row][col];
				prev = matrix[row - 1][col];

				// 같은 경우
				if (cur == prev)
				{
					cur_cnt += 1;
				}
				else
				{
					prev_cnt = cur_cnt;
					cur_cnt = 1;

					// 높아진 경우
					if (cur > prev + 1)
					{
						isImpossible = 1;

						break;
					}
					else if (cur == prev + 1)
					{
						// printf("prev_cnt = %d, x = %d\n", prev_cnt, x);

						if (prev_cnt >= x)
						{
							for (int a = row - x; a < row; a++)
							{
								slope[a][col] += 1;
							}
						}
						else
						{
							isImpossible = 1;

							break;
						}
					}
				}
			}
		}

		if (isImpossible == 0)
		{
			cur_cnt = 1;
			prev_cnt = 0;

			// 위쪽으로 탐색
			for (int row = n - 2; row >= 0; row--)
			{
				cur = matrix[row][col];
				prev = matrix[row + 1][col];


				// 같은 경우
				if (cur == prev)
				{
					cur_cnt += 1;
				}
				else
				{
					prev_cnt = cur_cnt;
					cur_cnt = 1;

					// 높아진 경우
					if (cur > prev + 1)
					{
						isImpossible = 1;

						break;
					}
					else if (cur == prev + 1)
					{
						// printf("prev_cnt = %d, x = %d\n", prev_cnt, x);

						if (prev_cnt >= x)
						{
							for (int a = row + x; a > row; a--)
							{
								slope[a][col] += 1;
							}
						}
						else
						{
							isImpossible = 1;

							break;
						}
					}
				}
			}
		}

		for (int row = 0; row < n; row++)
		{
			if (slope[row][col] > 1)
			{
				isImpossible = 1;

				break;
			}
		}

		if (isImpossible == 0)
		{
			ans += 1;

			// printf("%dth col\n", col);
		}
	}

	/*
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; col++)
		{
			printf("%d ", slope[row][col]);
		}

		printf("\n");
	}
	*/

	return;
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
		x = 0;
		ans = 0;

		for (int row = 0; row < MAX_N; row++)
		{
			for (int col = 0; col < MAX_N; col++)
			{
				matrix[row][col] = 0;
			}
		}

		scanf("%d %d", &n, &x);

		// printf("n = %d, x = %d\n", n, x);

		for (int row = 0; row < n; row++)
		{
			for (int col = 0; col < n; col++)
			{
				scanf("%d", &matrix[row][col]);
			}
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

		check();

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
