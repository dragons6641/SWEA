// KJOSW5653.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

/*
#include "pch.h"
#include <iostream>
*/

#include <stdio.h>

#define MAX_NM 50
#define MAX_K 300
#define MAX_SIZE (MAX_NM + MAX_K)
#define MAX_X 10
#define DEAD (MAX_X + 1)

typedef struct cell
{
	int life = 0;
	int status = 0;
	int birth = 0;
	int wakeup = 0;
}CELL;

int n = 0;
int m = 0;
int k = 0;
int ans = 0;
int tmp = 0;
int start_pos = 0;

/*
int matrix[MAX_SIZE][MAX_SIZE] = { 0 };
int copy[MAX_SIZE][MAX_SIZE] = { 0 };
*/

CELL matrix[MAX_SIZE][MAX_SIZE];

void simulate_upgrade()
{
	int cnt = 0;
	int birth_cnt = 0;
	int wakeup_cnt = 0;
	int index = 0;
	int cur = 0;

	// i시간 째의 모습 시뮬레이션
	for (int i = 1; i <= k; i++)
	{
		index = (int)(i / 2);

		for (int row = start_pos - index; row < start_pos + index + n; row++)
		{
			for (int col = start_pos - index; col < start_pos + index + m; col++)
			{
				birth_cnt = i - matrix[row][col].birth;
				wakeup_cnt = i - matrix[row][col].wakeup;

				// printf("(%d. %d), life = %d, status = %d, birth_cnt = %d, wakeup_cnt = %d\n", row, col, matrix[row][col].life, matrix[row][col].status, birth_cnt, wakeup_cnt);

				// 비활성 상태
				if (matrix[row][col].status == 1)
				{
					// 활성 상태로 전환
					if (birth_cnt == matrix[row][col].life)
					{
						matrix[row][col].status = 2;
						matrix[row][col].wakeup = i;
					}
					// 아직 비활성 상태
					else
					{

					}
				}
				// 활성 상태
				else if (matrix[row][col].status == 2)
				{
					// 번식
					if (wakeup_cnt == 1)
					{
						// 상
						if ((matrix[row - 1][col].status == 0) && (matrix[row][col].life > matrix[row - 1][col].life))
						{
							matrix[row - 1][col].life = matrix[row][col].life;
						}
						// 하
						if ((matrix[row + 1][col].status == 0) && (matrix[row][col].life > matrix[row + 1][col].life))
						{
							matrix[row + 1][col].life = matrix[row][col].life;
						}
						// 좌
						if ((matrix[row][col - 1].status == 0) && (matrix[row][col].life > matrix[row][col - 1].life))
						{
							matrix[row][col - 1].life = matrix[row][col].life;
						}
						// 우
						if ((matrix[row][col + 1].status == 0) && (matrix[row][col].life > matrix[row][col + 1].life))
						{
							matrix[row][col + 1].life = matrix[row][col].life;
						}
					}
					// 죽음
					if (wakeup_cnt == matrix[row][col].life)
					{
						matrix[row][col].status = -1;
					}
				}
				// 세포가 죽거나 없는 상태
				else
				{

				}
			}
		}

		for (int row = start_pos - index; row < start_pos + index + n; row++)
		{
			for (int col = start_pos - index; col < start_pos + index + m; col++)
			{
				// 번식 중복 처리
				if ((matrix[row][col].life > 0) && (matrix[row][col].status == 0))
				{
					matrix[row][col].status = 1;
					matrix[row][col].birth = i;
				}
			}
		}

		/*
		printf("i = %d\n", i);

		printf("life\n");

		for (int row = start_pos - index; row < start_pos + index + n; row++)
		{
			for (int col = start_pos - index; col < start_pos + index + m; col++)
			{
				printf("%3d ", matrix[row][col].life);
			}

			printf("\n");
		}

		printf("status\n");

		for (int row = start_pos - index; row < start_pos + index + n; row++)
		{
			for (int col = start_pos - index; col < start_pos + index + m; col++)
			{
				printf("%3d ", matrix[row][col].status);
			}

			printf("\n");
		}

		printf("birth\n");

		for (int row = start_pos - index; row < start_pos + index + n; row++)
		{
			for (int col = start_pos - index; col < start_pos + index + m; col++)
			{
				printf("%3d ", matrix[row][col].birth);
			}

			printf("\n");
		}

		printf("wakeup\n");

		for (int row = start_pos - index; row < start_pos + index + n; row++)
		{
			for (int col = start_pos - index; col < start_pos + index + m; col++)
			{
				printf("%3d ", matrix[row][col].wakeup);
			}

			printf("\n");
		}

		printf("\n");
		*/
	}

	return;
}

/*
void simulate()
{
	int cnt = 0;
	int index = 0;
	int cur = 0;

	// i시간 째의 모습 시뮬레이션
	for (int i = 1; i <= k; i++)
	{
		index = (int)(i / 2);

		// printf("start_pos = %d, index = %d\n", start_pos, index);
		printf("copy\n");

		for (int row = start_pos - index; row < start_pos + index + n; row++)
		{
			for (int col = start_pos - index; col < start_pos + index + m; col++)
			{
				printf("%3d ", copy[row][col]);
			}

			printf("\n");
		}

		// printf("start_pos = %d, index = %d\n", start_pos, index);
		printf("matrix\n");

		for (int row = start_pos - index; row < start_pos + index + n; row++)
		{
			for (int col = start_pos - index; col < start_pos + index + m; col++)
			{
				printf("%3d ", matrix[row][col]);
			}

			printf("\n");
		}


		for (int row = start_pos - index; row < start_pos + index + n; row++)
		{
			for (int col = start_pos - index; col < start_pos + index + m; col++)
			{
				cur = copy[row][col];

				// 활성 상태 세포
				if ((cur > 0) && (cur <= MAX_X))
				{
					// 세포 없는 곳만 번식
					if (cur == 1)
					{
						//상
						if ((copy[row - 1][col] == 0) || (copy[row - 1][col] < -MAX_X))
						{
							if (-matrix[row][col] - MAX_X < copy[row - 1][col])
							{
								copy[row - 1][col] = (-matrix[row][col] - MAX_X);
							}
						}

						//하
						if ((copy[row + 1][col] == 0) || (copy[row + 1][col] < -MAX_X))
						{
							if (-matrix[row][col] - MAX_X < copy[row + 1][col])
							{
								copy[row + 1][col] = (-matrix[row][col] - MAX_X);
							}
						}

						//좌
						if ((copy[row][col - 1] == 0) || (copy[row][col - 1] < -MAX_X))
						{
							if (-matrix[row][col] - MAX_X < copy[row][col - 1])
							{
								copy[row][col - 1] = (-matrix[row][col] - MAX_X);
							}
						}

						//우
						if ((copy[row][col + 1] == 0) || (copy[row][col + 1] < -MAX_X))
						{
							if (-matrix[row][col] - MAX_X < copy[row][col + 1])
							{
								copy[row][col + 1] = (-matrix[row][col] - MAX_X);
							}
						}
					}
					
					copy[row][col] += 1;

					// 생명력 다하면 죽은 세포로 처리
					if (copy[row][col] > matrix[row][col])
					{
						copy[row][col] = DEAD;
					}
				}
				// 비활성 상태 세포
				else if ((cur < 0) && (cur >= -MAX_X))
				{
					// 활성 상태로 전환
					if (cur == -1)
					{
						copy[row][col] = 1;
					}
					// 비활성 상태 유지
					else
					{
						copy[row][col] += 1;
					}
				}
				// 죽은 세포, 세포가 없을 경우, 새로 번식한 자리일 경우
				else
				{
					continue;
				}
			}
		}

		// 번식 최댓값 처리
		for (int row = start_pos - index; row < start_pos + index + n; row++)
		{
			for (int col = start_pos - index; col < start_pos + index + m; col++)
			{
				if (copy[row][col] < -MAX_X)
				{
					copy[row][col] += MAX_X;
				}

				if (matrix[row][col] == 0)
				{
					matrix[row][col] = copy[row][col];
				}
			}
		}
	}

	return;
}
*/

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
		k = 0;
		ans = 0;
		tmp = 0;
		start_pos = 0;

		/*
		for (int row = 0; row < MAX_SIZE; row++)
		{
			for (int col = 0; col < MAX_SIZE; col++)
			{
				matrix[row][col] = 0;
				copy[row][col] = 0;
			}
		}
		*/

		for (int row = 0; row < MAX_SIZE; row++)
		{
			for (int col = 0; col < MAX_SIZE; col++)
			{
				matrix[row][col].life = 0;
				matrix[row][col].status = 0;
				matrix[row][col].birth = 0;
				matrix[row][col].wakeup = 0;
			}
		}

		if (MAX_K % 2 == 0)
		{
			start_pos = (MAX_K / 2);
		}
		else
		{
			start_pos = (MAX_K / 2) + 1;
		}

		scanf("%d %d %d", &n, &m, &k);

		// printf("n = %d, m = %d, k = %d\n", n, m, k);

		/*
		for (int row = start_pos; row < start_pos + n; row++)
		{
			for (int col = start_pos; col < start_pos + m; col++)
			{
				scanf("%d", &tmp);

				matrix[row][col] = tmp;
				copy[row][col] = (-tmp);
			}
		}
		*/

		for (int row = start_pos; row < start_pos + n; row++)
		{
			for (int col = start_pos; col < start_pos + m; col++)
			{
				scanf("%d", &tmp);

				matrix[row][col].life = tmp;

				if (tmp != 0)
				{
					matrix[row][col].status = 1;
				}
			}
		}

		/*
		for (int row = start_pos; row < start_pos + n; row++)
		{
			for (int col = start_pos; col < start_pos + m; col++)
			{
				printf("%d ", matrix[row][col]);
			}

			printf("\n");
		}

		for (int row = start_pos; row < start_pos + n; row++)
		{
			for (int col = start_pos; col < start_pos + m; col++)
			{
				printf("%d ", copy[row][col]);
			}

			printf("\n");
		}
		*/

		/*
		for (int row = start_pos; row < start_pos + n; row++)
		{
			for (int col = start_pos; col < start_pos + m; col++)
			{
				printf("%d ", matrix[row][col].life);
			}

			printf("\n");
		}

		for (int row = start_pos; row < start_pos + n; row++)
		{
			for (int col = start_pos; col < start_pos + m; col++)
			{
				printf("%d ", matrix[row][col].status);
			}

			printf("\n");
		}
		*/

		// simulate();

		simulate_upgrade();

		/*
		for (int row = 0; row < MAX_SIZE; row++)
		{
			for (int col = 0; col < MAX_SIZE; col++)
			{
				if ((copy[row][col] != 0) && (copy[row][col] != DEAD))
				{
					ans += 1;
				}
			}
		}
		*/

		for (int row = 0; row < MAX_SIZE; row++)
		{
			for (int col = 0; col < MAX_SIZE; col++)
			{
				if (matrix[row][col].status >= 1)
				{
					ans += 1;
				}
			}
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
