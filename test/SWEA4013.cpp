// KJOSW4013.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS

/*
#include "pch.h"
#include <iostream>
*/

#include <stdio.h>
#include <math.h>

#define MAGNETS 4
#define EDGES 8
#define MAX_K 20
#define INPUTS 2
#define POINT 0
#define LEFT 6
#define RIGHT 2

int k = 0;
int ans = 0;

int matrix[MAGNETS][EDGES] = { 0 };
int info[MAX_K][INPUTS] = { 0 };
int isRotated[MAGNETS] = { 0 };

void clock (int index)
{
	int tmp = matrix[index][EDGES - 1];

	for (int i = EDGES - 1; i > 0 ; i--)
	{
		matrix[index][i] = matrix[index][i - 1];
	}

	matrix[index][0] = tmp;

	return;
}

void counterclock (int index)
{
	int tmp = matrix[index][0];

	for (int i = 0; i < EDGES - 1; i++)
	{
		matrix[index][i] = matrix[index][i + 1];
	}

	matrix[index][EDGES - 1] = tmp;

	return;
}

void simulate (int index, int dir)
{
	int cur_l = 0;
	int cur_r = 0;
	int next_l = 0;
	int next_r = 0;

	/*
	printf("index = %d, dir = %d\n", index, dir);

	for (int row = 0; row < MAGNETS; row++)
	{
		for (int col = 0; col < EDGES; col++)
		{
			printf("%d ", matrix[row][col]);
		}

		printf("\n");
	}
	*/

	// 1번 자석
	if ((index == 0) && (isRotated[index] == 0))
	{
		// 오른쪽으로 진행
		cur_r = matrix[index][RIGHT];
		next_l = matrix[index + 1][LEFT];

		// 시계방향
		if (dir == 1)
		{
			clock(index);

			isRotated[index] = 1;

			if (cur_r != next_l)
			{
				simulate(index + 1, -1);
			}
		}
		// 반시계방향
		else
		{
			counterclock(index);

			isRotated[index] = -1;

			if (cur_r != next_l)
			{
				simulate(index + 1, 1);
			}
		}
	}
	// 2번 자석 & 3번 자석
	else if (((index == 1) || (index == 2)) && (isRotated[index] == 0))
	{
		// 오른쪽으로 진행
		cur_r = matrix[index][RIGHT];
		next_l = matrix[index + 1][LEFT];
		// 왼쪽으로 진행
		cur_l = matrix[index][LEFT];
		next_r = matrix[index - 1][RIGHT];

		// 시계방향
		if (dir == 1)
		{
			clock(index);

			isRotated[index] = 1;

			if (cur_r != next_l)
			{
				simulate(index + 1, -1);
			}

			if (cur_l != next_r)
			{
				simulate(index - 1, -1);
			}
		}
		// 반시계방향
		else
		{
			counterclock(index);

			isRotated[index] = -1;

			if (cur_r != next_l)
			{
				simulate(index + 1, 1);
			}

			if (cur_l != next_r)
			{
				simulate(index - 1, 1);
			}
		}
	}
	// 4번 자석
	else if ((index == 3) && (isRotated[index] == 0))
	{
		// 왼쪽으로 진행
		cur_l = matrix[index][LEFT];
		next_r = matrix[index - 1][RIGHT];

		// 시계방향
		if (dir == 1)
		{
			clock(index);

			isRotated[index] = 1;

			if (cur_l != next_r)
			{
				simulate(index - 1, -1);
			}
		}
		// 반시계방향
		else
		{
			counterclock(index);

			isRotated[index] = -1;

			if (cur_l != next_r)
			{
				simulate(index - 1, 1);
			}
		}
	}

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
		k = 0;
		ans = 0;

		for (int row = 0; row < MAX_K; row++)
		{
			for (int col = 0; col < INPUTS; col++)
			{
				info[row][col] = 0;
			}
		}

		scanf("%d", &k);

		// printf("k = %d\n", k);

		for (int row = 0; row < MAGNETS; row++)
		{
			for (int col = 0; col < EDGES; col++)
			{
				scanf("%d", &matrix[row][col]);
			}
		}

		/*
		for (int row = 0; row < MAGNETS; row++)
		{
			for (int col = 0; col < EDGES; col++)
			{
				printf("%d ", matrix[row][col]);
			}

			printf("\n");
		}
		*/

		for (int row = 0; row < k; row++)
		{
			for (int col = 0; col < INPUTS; col++)
			{
				scanf("%d", &info[row][col]);
			}
		}

		/*
		for (int row = 0; row < k; row++)
		{
			for (int col = 0; col < INPUTS; col++)
			{
				printf("%d ", info[row][col]);
			}
			
			printf("\n");
		}
		*/

		/*
		for (int row = 0; row < EDGES; row++)
		{
			clock(0);

			for (int col = 0; col < EDGES; col++)
			{
				printf("%d ", matrix[0][col]);
			}

			printf("%dth clockwise rotate\n", row + 1);
		}
		*/
		
		/*
		for (int row = 0; row < EDGES; row++)
		{
			counterclock(0);

			for (int col = 0; col < EDGES; col++)
			{
				printf("%d ", matrix[0][col]);
			}

			printf("%dth counterclockwise rotate\n", row + 1);
		}
		*/

		///*
		for (int row = 0; row < k; row++)
		{
			for (int col = 0; col < MAGNETS; col++)
			{
				isRotated[col] = 0;
			}

			// printf("%dth simulation\n", row + 1);

			simulate(info[row][0] - 1, info[row][1]);
		}
		//*/

		/*
		printf("end of simulations\n");

		for (int row = 0; row < MAGNETS; row++)
		{
			for (int col = 0; col < EDGES; col++)
			{
				printf("%d ", matrix[row][col]);
			}

			printf("\n");
		}
		*/

		for (int row = 0; row < MAGNETS; row++)
		{
			if (matrix[row][POINT] == 1)
			{
				ans += (pow(2, row));
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
