#define FASTIO ios::sync_with_stdio(false); cout.tie(0); cin.tie(0);

#include<iostream>
#include<vector>
#include<unordered_map>
#include<stdlib.h>

using namespace std;

/**
 * union-find 문제
 * 이름 : id를 저장하는 hash-map -> nameToId (name -> id)
 * root에 해당 집합에 몇 명이 있는지 저장 -> numberOfGroup 배열 (루트 id ->사람 수)
 */

int id;
int F;

vector<int> parent(200'001);
vector<int> numberOfGroup(200'001);
unordered_map<string, int> nameToId;

int findParent(int a){
    if(a == parent[a]) return a;
    return parent[a] = findParent(parent[a]);
}

int unionGroup(int a, int b){ // 병합 + 그룹 내의 사람 수 리턴
    a = findParent(a);
    b = findParent(b);

    if(a==b) return numberOfGroup[a];

    parent[a] = b;
    return numberOfGroup[b] = numberOfGroup[b] + numberOfGroup[a];
}

int makeOrGetIdx(string name){
    if(nameToId.find(name) == nameToId.end()){ // 처음인 경우
        nameToId.insert(make_pair(name, id)); // insert는 pair로 전달해야 한다. 아니면 []도 가능
        return id++;
    }
    return nameToId[name];
}

void init(){
    id = 0;
    nameToId.clear();
    fill_n(numberOfGroup.begin(), 200'001, 1);
    for(int i = 0; i <= 200'001; i++){
        parent[i] = i;
    }
}

int main(){
    FASTIO

    int T;
    cin >> T;
    for(int test_case = 1; test_case <= T;test_case++){ 
        cin >> F;
        init(); //test_case 마다 초기화 해야 함
        for(int i = 0; i < F;i++){
            string name1, name2;
            cin >> name1 >> name2;
            int idx1 = makeOrGetIdx(name1);
            int idx2 = makeOrGetIdx(name2);
            cout << unionGroup(idx1, idx2) << endl;
        }
    }
    return 0;
}