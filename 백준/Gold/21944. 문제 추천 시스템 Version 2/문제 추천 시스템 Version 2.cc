#include <bits/stdc++.h>
using namespace std;

set<pair<int, int>> probs[101];  // 각 그룹별 (난이도, 문제 번호)
set<pair<int, int>> every_probs; // 전체 문제
unordered_map<int, pair<int, int>> problem_info; // 문제번호 -> (난이도, 그룹)

void add(int P, int L, int G) {
    pair<int, int> prob = {L, P};
    probs[G].insert(prob);
    every_probs.insert(prob);
    problem_info[P] = {L, G};
}

int recommend(int G, int x) {
    return (x == 1) ? prev(probs[G].end())->second : probs[G].begin()->second;
}

int recommend2(int x) {
    return (x == 1) ? prev(every_probs.end())->second : every_probs.begin()->second;
}

int recommend3(int x, int L) {
    if (x == 1) {
        // NNNNYYYY
        auto it = every_probs.lower_bound({L, 0});
        return (it != every_probs.end()) ? it->second : -1; // 모든 문제가 {L, 0}보다 작은 경우 (NNNNNNNN)
    } else {
        // YYYYNNNN
        auto it = every_probs.upper_bound({L, 0});
        return (it != every_probs.begin()) ? prev(it)->second : -1; // 모든 문제가 {L, 0} 보다 큰 경우 (NNNNNNNN)
    }
}

void solved(int P) {
    int L = problem_info[P].first;
    int G = problem_info[P].second;
    probs[G].erase(probs[G].find({L, P}));
    every_probs.erase(every_probs.find({L, P}));
}

int main() {

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int P, L, G; cin >> P >> L >> G;
        add(P, L, G);
    }

    int M; cin >> M;
    for (int i = 0; i < M; i++) {
        string cmd; cin >> cmd;
        if (cmd == "recommend") {
            int G, x; cin >> G >> x;
            cout << recommend(G, x) << "\n";
        } else if (cmd == "recommend2") {
            int x; cin >> x;
            cout << recommend2(x) << "\n";
        } else if (cmd == "recommend3") {
            int x, L; cin >> x >> L;
            cout << recommend3(x, L) << "\n";
        } else if (cmd == "solved") {
            int P; cin >> P;
            solved(P);
        } else { // add
            int P, L, G; cin >> P >> L >> G;
            add(P, L, G);
        }
    }

    return 0;
}
