#include <bits/stdc++.h>

using namespace std;

int N;
string S, T;

void solution() {
    int s = 0, e = S.length() - 1;

    while (s <= e) { 
        if (S[s] < S[e]) {
            T.push_back(S[s]);
            s++;
        } else if (S[s] > S[e]) {
            T.push_back(S[e]);
            e--;
        } else { // S[s] == S[e]인 경우
            int tempS = s, tempE = e;
            bool front = true;
            while (tempS < tempE && S[tempS] == S[tempE]) {
                tempS++;
                tempE--;
            }

            if (tempS < tempE && S[tempS] > S[tempE]) {
                front = false; 
            }

            if (front) {
                T.push_back(S[s]);
                s++;
            } else {
                T.push_back(S[e]);
                e--;
            }
        }
    }
}

string printAns() {
    string ret;
    for (int i = 0; i < T.length(); i++) {
        ret.push_back(T[i]);
        if (i % 80 == 79) { 
            ret.push_back('\n');
        }
    }
    return ret;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        S.push_back(c);
    }
    solution();
    cout << printAns() << endl;
    return 0;
}
