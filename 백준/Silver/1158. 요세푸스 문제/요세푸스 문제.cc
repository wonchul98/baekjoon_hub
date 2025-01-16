#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> people;
    for (int i = 1; i <= N; i++) {
        people.push_back(i);
    }

    vector<int> result;
    int idx = 0;

    while (!people.empty()) {
        // K번째 사람의 인덱스 계산
        idx = (idx + K - 1) % people.size();
        result.push_back(people[idx]);
        people.erase(people.begin() + idx); // 제거
    }

    // 출력
    cout << "<";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) {
            cout << ", ";
        }
    }
    cout << ">" << endl;

    return 0;
}
