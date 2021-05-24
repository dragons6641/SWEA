/*
SofTech 숫자야구게임
*/

/*
#define N          4
#define MIN_M 0
#define MAX_M 9
#define START_LEVEL 0

typedef struct 
{
	int strike;
	int ball;
} Result;

// API
extern Result query(int guess[]);

int numCnt = 0;
bool ans = false;
int numList[N] = { 0, };
int outputList[N] = { 0, };
bool visit[N] = { 0, };

void init(void)
{
	numCnt = 0;
	ans = false;
	
	for (register int i = 0; i < N; i++)
	{
		numList[i] = 0;
		outputList[i] = 0;
		visit[i] = false;
	}

	return;
}

void findNum(void)
{
	int resultCnt = 0;
	int inputCnt1 = 0;
	int inputCnt2 = 0;
	int inputList1[N] = { 1, 2, 3, 4 };
	int inputList2[N] = { 6, 7, 8, 9 };
	int resultList[MAX_M + 1] = { 0, };
	Result ret;

	ret = query(inputList1);
	resultList[resultCnt++] = ret.strike + ret.ball;
	inputCnt1 += ret.strike + ret.ball;
	inputList1[0] = 0;

	ret = query(inputList1);
	resultList[resultCnt++] = ret.strike + ret.ball;
	inputCnt1 += ret.strike + ret.ball;
	inputList1[1] = 1;

	ret = query(inputList1);
	resultList[resultCnt++] = ret.strike + ret.ball;
	inputCnt1 += ret.strike + ret.ball;
	inputList1[2] = 2;

	ret = query(inputList1);
	resultList[resultCnt++] = ret.strike + ret.ball;
	inputCnt1 += ret.strike + ret.ball;
	inputList1[3] = 3;

	ret = query(inputList1);
	resultList[resultCnt++] = ret.strike + ret.ball;
	inputCnt1 += ret.strike + ret.ball;


	ret = query(inputList2);
	resultList[resultCnt++] = ret.strike + ret.ball;
	inputCnt2 += ret.strike + ret.ball;
	inputList2[0] = 5;

	ret = query(inputList2);
	resultList[resultCnt++] = ret.strike + ret.ball;
	inputCnt2 += ret.strike + ret.ball;
	inputList2[1] = 6;

	ret = query(inputList2);
	resultList[resultCnt++] = ret.strike + ret.ball;
	inputCnt2 += ret.strike + ret.ball;
	inputList2[2] = 7;

	ret = query(inputList2);
	resultList[resultCnt++] = ret.strike + ret.ball;
	inputCnt2 += ret.strike + ret.ball;
	inputList2[3] = 8;

	ret = query(inputList2);
	resultList[resultCnt++] = ret.strike + ret.ball;
	inputCnt2 += ret.strike + ret.ball;

	for (register int i = 0; i <= 4; i++)
	{
		if (inputCnt1 - (resultList[i] * 4) > 0)
		{
			numList[numCnt++] = i;
		}
	}

	for (register int i = 5; i <= 9; i++)
	{
		if (inputCnt2 - (resultList[i] * 4) > 0)
		{
			numList[numCnt++] = i;
		}
	}

	int inputList1[N + 1] = { 1, 2, 3, 4, 0 };
	int inputList2[N + 1] = { 6, 7, 8, 9, 5 };
	Result resultList[MAX_M + 1] = { {0, 0}, };

	for (register int i = 0; i <= N; i++)
	{
		resultList[i] = query(inputList1);

		int tmp = inputList1[0];
		
		for (register int j = 0; j < N; j++)
		{
			inputList1[j] = inputList1[j + 1];
		}

		inputList1[N] = tmp;

		// int debug = 1;
	}

	for (register int i = 0; i <= N; i++)
	{
		resultList[i + 5] = query(inputList2);

		int tmp = inputList2[0];

		for (register int j = 0; j < N; j++)
		{
			inputList2[j] = inputList2[j + 1];
		}

		inputList2[N] = tmp;

		// int debug = 1;
	}

	return;
}

void dfs(int level)
{
	// 순열 만들었으면
	if (level == N)
	{
		// 맞는지 물어본다
		Result ret = query(outputList);

		if (ret.strike == N)
		{
			ans = true;
		}

		return;
	}

	// 숫자 목록에서 하나씩 꺼내서 만든다
	for (register int i = 0; i < N; i++)
	{
		if (visit[i])
		{
			continue;
		}

		visit[i] = true;
		outputList[level] = numList[i];

		dfs(level + 1);

		if (ans)
		{
			return;
		}

		visit[i] = false;
	}

	return;
}

void doUserImplementation(int guess[]) 
{
	// Implement a user's implementation function
	//
	// The array of guess[] is a return array that
	// is your guess for what digits[] would be.

	// 1. 자릿수 찾기
	for (register int i = MIN_M; i < MAX_M; i++)
	{
		for (register int j = 0; j < N; j++)
		{
			outputList[j] = i;
		}

		Result ret = query(outputList);

		if (ret.strike > 0)
		{
			numList[cnt++] = i;
		}

		if (cnt == N)
		{
			break;
		}
	}

	// 마지막 수는 물어볼 필요가 없다!
	if (cnt == N - 1)
	{
		numList[cnt++] = MAX_M;
	}

	init();

	findNum();

	// 해당 숫자들로 순열을 만들자
	dfs(START_LEVEL);

	for (register int i = 0; i < N; i++)
	{
		guess[i] = outputList[i];
	}

	return;
}
*/

#define N 4
typedef struct {
	int strike;
	int ball;
} Result;
// API
extern Result query(int guess[]);
#define MAXN (10*9*8*7)
static int data[MAXN][6];//쿼리 실패한 결과 저장용
//[0]~[3] : 시도한 숫자,  [4]:스트라이크개수,  [5]:볼개수
static int datacnt;//data배열에 저장된 개수
static int *num;
static int used[10];//사용여부(서로다른 숫자 선택하기 위해)
int isPossible(void) {
	for (int i = 0; i < datacnt; i++) {
		int strike = 0, ball = 0;
		for (int j = 0; j <= 3; j++) {
			if (data[i][j] == num[j]) strike++;//같은 자리 같은 숫자이므로 스트라이크 개수 증가
			else if (used[data[i][j]]) ball++;//같은 자리는 아니지만 해당 숫자 존재 볼 개수 증가
		}
		if ((data[i][4] != strike) || (data[i][5] != ball)) return 0;//답 후보 아님
	}
	return 1;//답 후보
}
int DFS(int n) {
	if (n >= N) {//서로다른 4개 숫자 고르기 성공
		if (isPossible()) {//답후보인지 확인
			Result ret = query(num);
			if (ret.strike == 4) return 1;//성공
			//답 아니면 정보 저장(답후보 체크할때 사용)
			for (int i = 0; i <= 3; i++) data[datacnt][i] = num[i];
			data[datacnt][4] = ret.strike;
			data[datacnt][5] = ret.ball;
			datacnt++;
		}
		return 0;//답 후보 아니면 무시
	}
	for (int i = 0; i <= 9; i++) {
		if (used[i]) continue;//이미 선택된 숫자
		used[i] = 1;//표시
		num[n] = i;//선택된 숫자 저장
		if (DFS(n + 1) == 1) return 1;//성공 했으면 정지
		used[i] = 0;//표시 제거
	}
	return 0;
}
void doUserImplementation(int guess[]) {
	//사용할 변수 초기화
	datacnt = 0;
	num = guess;
	for (int i = 0; i < 10; i++) used[i] = 0;
	//숫자야구숫자 찾기
	DFS(0);
}
