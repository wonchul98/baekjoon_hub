/**
 *  첫째 줄에 N (4 ≤ N ≤ 600)이 주어진다.
 *
 *  둘째 줄에는 각 눈덩이 i (1 ≤ i ≤ N)의 지름을 의미하는 정수 Hi (1 ≤ Hi ≤ 10^9)가 공백으로 구분되어 주어진다.
 */
#define INF 2'000'000'001

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int N, ans = INF;
vector<int> v;

int found_minimum_diff(int i, int j, int A){
    int s = 0;
    int e = N-1;
    int minimum = INF;
    while(s < e){
        if(s == i || s == j) {
            s++;
            continue;
        }else if(e == j || e == i){
            e--;
            continue;
        }
        int sum = v[s] + v[e];
        if(sum >= A){ // 너무 크다
            e--;
            minimum = min(minimum, sum - A);
        }else if(sum < A){ // 너무 작다
            s++;
        }
    }
    return minimum;
}

int main(){
    cin>>N;
    for(int i =0;i < N;i++){
        int input;
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end()); // 정렬

    for(int i =0;i < N;i++){
        for(int j = i+1;j<N;j++){
            // ground_truth를 먼저 만든다. 
            int A = v[i] + v[j];
            ans = min(found_minimum_diff(i, j, A), ans);
        }
    }

    cout << ans << endl;


    return 0;
}