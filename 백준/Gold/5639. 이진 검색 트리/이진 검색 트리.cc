#include<iostream>
#include<vector>

using namespace std;

vector<int> v;

void recur(int startIdx, int endIdx){
    if(startIdx > endIdx) return;
    if(v.empty()) return;
    if(startIdx == endIdx) {
        cout << v[startIdx] <<"\n";
        return;
    }
    int head = v[startIdx];
    int midIdx;
    for(int i = startIdx; i <= endIdx;i++){
        if(v[i] <= head) midIdx = i;
    }
    recur(startIdx + 1, midIdx);
    recur(midIdx+1, endIdx);
    cout << head << "\n";
}

int main(){
    int input;
    while(cin >> input){
        v.push_back(input);
    }
    recur(0, v.size()-1);
    return 0;
}