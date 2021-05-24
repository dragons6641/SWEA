#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;


const int MAX = 4000;
const int ELEMENTMAX = 1000;


struct Atom {
    int x;
    int y;
    int dir;
    int energy;
};
//x -> row y -> col UP : col+=1, LEFT: row-1;
int dy[] = {1, -1, 0, 0}; // 0: UP, DOWN, LEFT, RIGHT
int dx[] = {0, 0, -1, 1};

int num, ans;
bool check[MAX + 4][MAX + 4];
int map[MAX + 4][MAX + 4];
Atom atom[MAX + 2];


void go() {

    int turn = 1;

    while (turn <= 4000) {

        int tempEnergy = 0;
        //원소체크 각각 원소 비교

        // 이동

        for (int i = 1; i <= num; ++i) {

            if (atom[i].energy == 0) {
                continue;
            }


            int nextX = dx[atom[i].dir] + atom[i].x;
            int nextY = dy[atom[i].dir] + atom[i].y;
            if (nextX >= 0 && nextX <=4000 && nextY >= 0 && nextY <= 4000) {
//                printf("%d번째 요소 X: %d, Y: %d, Dir: %d, energy: %d\n", i, atom[i].x, atom[i].y, atom[i].dir,
//                       atom[i].energy);
                map[atom[i].x][atom[i].y] -= 1;
                atom[i].x = nextX;
                atom[i].y = nextY;
                map[atom[i].x][atom[i].y] += 1;
                if (map[atom[i].x][atom[i].y] > 1) {
                    check[atom[i].x][atom[i].y] = true;
                }
            }else{
                map[atom[i].x][atom[i].y] -= 1;
                atom[i].energy = 0;
            }

        }


        //충돌체크


        for (int i = 1; i <= num; ++i) {


            if (atom[i].energy == 0) {
                continue;
            }

            int tempX = atom[i].x;
            int tempY = atom[i].y;

            if (check[tempX][tempY]) {
                if (map[tempX][tempY] == 1) {
                    check[tempX][tempY] = false;
                }
                map[tempX][tempY] -= 1;
                tempEnergy += atom[i].energy;
                atom[i].energy = 0;
            }
        }



        ans += tempEnergy;
        turn += 1;

        int cnt =1;
        for (int j = 1; j <= num ; ++j) {
            if( atom[j].energy == 0){
                cnt++;
            }
        }

        if( cnt == num){
            return;
        }

    }

}


int main(int argc, char **argv) {
    int test_case;
    int T;

    //freopen("input.txt", "r", stdin);
    cin >> T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for (test_case = 1; test_case <= T; ++test_case) {
        num = 0;
        scanf("%d", &num);
        memset(atom, 0, sizeof(struct Atom));
        memset(check, 0, sizeof(check));
        memset(map, 0, sizeof(map));
        ans = 0;
        for (int i = 1; i <= num; ++i) {

            scanf("%d %d %d %d", &atom[i].x, &atom[i].y, &atom[i].dir, &atom[i].energy);
            atom[i].x += 1000;
            atom[i].y += 1000;
            atom[i].x *= 2;
            atom[i].y *= 2;
            map[atom[i].x][atom[i].y] += 1;

        }
        go();
        printf("#%d %d\n", test_case, ans);
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
