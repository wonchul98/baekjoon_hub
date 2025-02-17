#include <bits/stdc++.h>
using namespace std;

int mmap[3][3];

bool isFinished(int turn) {
    for (int i = 0; i < 3; i++) {
        if (mmap[i][0] == turn && mmap[i][1] == turn && mmap[i][2] == turn) return true; // 가로 체크
        if (mmap[0][i] == turn && mmap[1][i] == turn && mmap[2][i] == turn) return true; // 세로 체크
    }
    if (mmap[0][0] == turn && mmap[1][1] == turn && mmap[2][2] == turn) return true; // 왼쪽 대각선 체크
    if (mmap[0][2] == turn && mmap[1][1] == turn && mmap[2][0] == turn) return true; // 오른쪽 대각선 체크
    return false;
}

int minimax(int turn) {
    if (isFinished(3 - turn)) return -1; // 상대방이 이겼다면 -1 반환

    int minValue = 2; // -1(패배), 0(무승부), 1(승리)

    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            if (mmap[y][x] == 0) {
                mmap[y][x] = turn;

                int result = minimax(3 - turn); // 상대방 턴
                minValue = min(minValue, result); // 상대방이 최선의 선택

                mmap[y][x] = 0; 
            }
        }
    }

    if (minValue == 2) return 0; 
    return -minValue; 
}

int whosNext() {
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (mmap[i][j] == 1) cnt1++;
            else if (mmap[i][j] == 2) cnt2++;
        }
    }
    return (cnt1 == cnt2) ? 1 : 2;
}

int main() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> mmap[i][j];
        }
    }

    int cur = whosNext();
    int res = minimax(cur);

    if (res == 1) cout << "W" << endl;  
    else if (res == -1) cout << "L" << endl;
    else cout << "D" << endl; 

    return 0;
}
