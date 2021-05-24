// KJOSW1767.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_N 12

int n = 0;
int cores = 0;
int ans = MAX_N * MAX_N;
int max_connected = 0;
int cur_row = 0;
int cur_col = 0;
int cur_dir = 0;

int matrix[MAX_N][MAX_N] = { -1 };
int core[MAX_N][2] = { -1 };

void backtrack(int cur, int cnt, int dir, int cur_connected)
{
	int available = 0;

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

	// 종료조건
	if (cur == cores)
	{
		// printf("%d %d %d %d\n", cnt, ans, cur_connected, max_connected);

		if (cur_connected > max_connected)
		{
			max_connected = cur_connected;
			ans = cnt;
		}
		else if ((cur_connected == max_connected) && cnt < ans)
		{
			ans = cnt;
		}

		return;
	}

	cur_row = core[cur][0];
	cur_col = core[cur][1];
	cur_dir = 0;

	//printf("%d %d %d %d\n", cur_row, cur_col, cnt, cur_dir);

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

	// 사이드
	if ((cur_row == 0) || (cur_row == n - 1) || (cur_col == 0) || (cur_col == n - 1))
	{
		// printf("%d %d %d %d\n", cur_row, cur_col, cnt, cur_dir);

		backtrack(cur + 1, cnt, cur_dir, cur_connected + 1);

		// 초기화
		cur_row = core[cur][0];
		cur_col = core[cur][1];

		// printf("side end %d %d\n", cur_row, cur_col);

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

		return;
	}

	// 가운데
	else
	{
		// 위쪽
		if (cur_row - 1 >= 0)
		{
			cur_dir = 12;

			for (int row = 0; row < cur_row; row++)
			{
				if (matrix[row][cur_col] != 0)
				{
					cur_dir = 0;

					break;
				}
			}

			if (cur_dir != 0)
			{
				available += 1;

				for (int row = 0; row < cur_row; row++)
				{
					matrix[row][cur_col] = 2;
				}

				// printf("%d %d %d %d\n", cur_row, cur_col, cnt, cur_dir);

				backtrack(cur + 1, cnt + cur_row, cur_dir, cur_connected + 1);

				// 초기화
				cur_row = core[cur][0];
				cur_col = core[cur][1];

				for (int row = 0; row < cur_row; row++)
				{
					if (matrix[row][cur_col] == 2)
					{
						matrix[row][cur_col] = 0;
					}
				}
			}
		}

		// 아래쪽
		if (cur_row + 1 <= n - 1)
		{
			cur_dir = 6;

			for (int row = cur_row + 1; row < n; row++)
			{
				if (matrix[row][cur_col] != 0)
				{
					cur_dir = 0;

					break;
				}
			}

			if (cur_dir != 0)
			{
				available += 1;

				for (int row = cur_row + 1; row < n; row++)
				{
					matrix[row][cur_col] = 2;
				}

				// printf("%d %d %d %d\n", cur_row, cur_col, cnt, cur_dir);

				backtrack(cur + 1, cnt + n - cur_row - 1, cur_dir, cur_connected + 1);

				// 초기화
				cur_row = core[cur][0];
				cur_col = core[cur][1];

				for (int row = cur_row + 1; row < n; row++)
				{
					if (matrix[row][cur_col] == 2)
					{
						matrix[row][cur_col] = 0;
					}
				}
			}
		}

		// 왼쪽
		if (cur_col - 1 >= 0)
		{
			cur_dir = 9;

			for (int col = 0; col < cur_col; col++)
			{
				if (matrix[cur_row][col] != 0)
				{
					cur_dir = 0;

					break;
				}
			}

			if (cur_dir != 0)
			{
				available += 1;

				for (int col = 0; col < cur_col; col++)
				{
					matrix[cur_row][col] = 2;
				}

				// printf("%d %d %d %d\n", cur_row, cur_col, cnt, cur_dir);

				backtrack(cur + 1, cnt + cur_col, cur_dir, cur_connected + 1);

				// 초기화
				cur_row = core[cur][0];
				cur_col = core[cur][1];

				for (int col = 0; col < cur_col; col++)
				{
					if (matrix[cur_row][col] == 2)
					{
						matrix[cur_row][col] = 0;
					}
				}
			}
		}

		// 오른쪽
		if (cur_col + 1 <= n - 1)
		{
			cur_dir = 3;

			for (int col = cur_col + 1; col < n; col++)
			{
				if (matrix[cur_row][col] != 0)
				{
					cur_dir = 0;

					break;
				}
			}

			if (cur_dir != 0)
			{
				available += 1;

				for (int col = cur_col + 1; col < n; col++)
				{
					matrix[cur_row][col] = 2;
				}

				// printf("%d %d %d %d\n", cur_row, cur_col, cnt, cur_dir);

				backtrack(cur + 1, cnt + n - cur_col - 1, cur_dir, cur_connected + 1);

				// 초기화
				cur_row = core[cur][0];
				cur_col = core[cur][1];

				for (int col = cur_col + 1; col < n; col++)
				{
					if (matrix[cur_row][col] == 2)
					{
						matrix[cur_row][col] = 0;
					}
				}
			}
		}
	}

	//printf("center end %d %d\n", cur_row, cur_col);

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

	// 연결 못하는 경우
	if (available == 0)
	{
		// printf("%d %d %d %d\n", cur_row, cur_col, cnt, cur_dir);

		backtrack(cur + 1, cnt, cur_dir, cur_connected);

		// 초기화
		cur_row = core[cur][0];
		cur_col = core[cur][1];
	}

	return;
}

int main()
{
	int t = 0;

	scanf("%d", &t);

	// printf("%d\n", t);

	for (int i = 0; i < t; i++)
	{
		n = 0;
		ans = MAX_N * MAX_N;
		max_connected = 0;
		cur_row = 0;
		cur_col = 0;
		cur_dir = 0;

		matrix[MAX_N][MAX_N] = { -1 };
		core[MAX_N][2] = { -1 };

		scanf("%d", &n);

		// printf("%d\n", n);

		cores = 0;

		for (int row = 0; row < n; row++)
		{
			for (int col = 0; col < n; col++)
			{
				scanf("%d", &matrix[row][col]);

				if (matrix[row][col] == 1)
				{
					// printf("%d %d %d\n", row, col, cores);

					core[cores][0] = row;
					core[cores][1] = col;

					cores += 1;
				}
			}
		}

		// printf("%d\n", cores);

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
		for (int row = 0; row < cores; row++)
		{
			for (int col = 0; col < 2; col++)
			{
				printf("%d ", core[row][col]);
			}

			printf("\n");
		}
		*/

		backtrack(0, 0, 0, 0);

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
