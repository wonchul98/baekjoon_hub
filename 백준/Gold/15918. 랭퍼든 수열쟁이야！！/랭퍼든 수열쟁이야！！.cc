#include<iostream>
#include<vector>

using namespace std;

int n, x, y, ans; // (2 ≤ n ≤ 12, 1 ≤ x < y ≤ 2n, 1 ≤ y-x-1 ≤ n)
int visited[25];
vector<int> v(25, 0);
int left_num;

bool inRange(int a){
    return a <= 2 * n;
}

void recur(int idx){ // idx자리에 뭘 넣을지 판단
    if(v[idx] != 0 && left_num > 0) recur(idx+1); //이미 있는 경우 다음 인덱스 판단
    for(int i = 1; i <= n;i++){
        if(visited[i] || !inRange(idx+i+1) || v[idx] != 0 || v[idx + i + 1] != 0) continue;
        if(left_num == 1){ // 넣으면 정답이 된다. 
            ans++;
            return;
        }
        visited[i] = true;
        left_num--;
        v[idx] = i;
        v[idx+i+1] = i;
        recur(idx+1);
        v[idx] = 0;
        v[idx+i+1] = 0;
        visited[i] = false;
        left_num++;
    }
}

int main(){
    cin >> n >> x >> y;
    left_num = n - 1; // 사용해야 하는 수
    v[x] = y - x - 1;
    v[y] = y - x - 1;
    visited[y-x-1] = true;
    recur(1);
    cout << ans << endl;
    return 0;  
}