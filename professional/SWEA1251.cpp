// KJOSW1251.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#define MAX_N 1000
#define INF 1000000000000000000

/*
#include "pch.h"
#include <iostream>

#include <stdio.h>

int n = 0;
int cnt = 0;
long long ans = INF;

int island_x[MAX_N + 1] = { -1 };
int island_y[MAX_N + 1] = { -1 };
int isVisited[MAX_N + 1] = { 0 };

long long calc_len(int a1, int b1, int a2, int b2)
{
	long long result = 0;
	long long len_diff = 0;

	// x좌표
	if (a1 > a2)
	{
		len_diff = a1 - a2;
	}
	else
	{
		len_diff = a2 - a1;
	}

	result += (len_diff * len_diff);

	// y좌표
	if (b1 > b2)
	{
		len_diff = b1 - b2;
	}
	else
	{
		len_diff = b2 - b1;
	}

	result += (len_diff * len_diff);

	// 거리의 제곱 return
	return result;
}

void backtrack(int index, long long length)
{
	// 이미 최솟값을 초과했다면
	if (length > ans)
	{
		// backtrack
		return;
	}

	// 연결된 섬의 개수 증가
	cnt += 1;

	// 방문 표시
	isVisited[index] = 1;

	// printf("index = %d, length = %lld, ans = %lld, cnt = %d, n = %d\n", index, length, ans, cnt, n);

	for (int i = 1; i <= n; i++)
	{
		// 아직 방문하지 않은 정점이 있다면
		if (isVisited[i] == 0)
		{
			backtrack(i, length + calc_len(island_x[index], island_y[index], island_x[i], island_y[i]));
		}
	}

	// 모든 섬이 연결되었다면 최솟값 갱신
	if ((cnt == n) && (length < ans))
	{
		ans = length;
	}

	// 연결된 섬의 개수 감소
	cnt -= 1;

	// 방문 표시 복구
	isVisited[index] = 0;

	// backtrack
	return;
}

int main()
{
    // std::cout << "Hello World!\n"; 

	int testcase = 0;

	scanf("%d", &testcase);

	for (int t = 1; t <= testcase; t++)
	{
		long double e = 0;

		n = 0;
		ans = INF;

		scanf("%d", &n);

		// x좌표
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &island_x[i]);
		}

		// y좌표
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &island_y[i]);
		}

		scanf("%lf", &e);

		// 백트래킹
		for (int i = 1; i <= n; i++)
		{
			backtrack(i, 0);
		}

		// printf("#%d %llf\n", t, long double(ans * e));
		printf("#%d %lld\n", t, long long(ans * e));
		// printf("#%d %llf\n", t, (long double)(ans) * e);
		// printf("#%d %lld\n", t, ans);

	}

	return 0;
}
*/

// 나중에 다시 공부하자!
#include <cstdio>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

struct Edge
{
	ll start,end,cost;
	bool operator < (const Edge &other) const { return cost<other.cost; }
};

ll t,n,m,ans,p[1001],x[1001],y[1001];
double E;
ll Find(ll x) { return x==p[x]?x:p[x]=Find(p[x]); }
void Union(ll x,ll y) { p[Find(x)]=Find(y); }
ll dist(ll x1,ll y1,ll x2,ll y2)
{
	ll a=abs(x1-x2),b=abs(y1-y2);
	return a*a+b*b;
}

int main()
{
	scanf("%lld",&t);
	for(ll k=1;k<=t;k++)
	{
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++) scanf("%lld",&x[i]);
		for(ll i=1;i<=n;i++) scanf("%lld",&y[i]);
		scanf("%lf",&E);
		for(ll i=1;i<=n;i++) p[i]=i;
		vector<Edge> a;
		for(ll i=1;i<=n;i++) for(ll j=i+1;j<=n;j++)
			a.push_back({i,j,dist(x[i],y[i],x[j],y[j])});
		sort(a.begin(),a.end());
		m=a.size(),ans=0;
		for(ll i=0;i<m;i++)
		{
			Edge e=a[i];
			ll x=Find(e.start),y=Find(e.end);
			if(x!=y) Union(e.start,e.end),ans+=e.cost;
		}
		printf("#%lld %.0f\n",k,ans*E);
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
