/**
 * 수의 각 자리 숫자 중에서 홀수의 개수를 종이에 적는다.
수가 한 자리이면 더 이상 아무것도 하지 못하고 종료한다.
수가 두 자리이면 2개로 나눠서 합을 구하여 새로운 수로 생각한다.
수가 세 자리 이상이면 임의의 위치에서 끊어서 3개의 수로 분할하고, 3개를 더한 값을 새로운 수로 생각한다.
 * 
 */
#define INF 987654321

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int min_odd_num = INF;
int max_odd_num = 0;

vector<int> intToVector(int a){
    vector<int> rs;
    int b = 10;
    while(true){
        int q = a / b;
        int r = a % b;
        rs.push_back(r);
        if(q == 0) break;
        a /= b;
    }
    reverse(rs.begin(), rs.end());
    return rs;
}

int vectorToInt(vector<int> v, int s, int e){
    int ret = 0;
    int multiplier = 1;
    for(int i = e - 1; i >= s; --i){
        ret += v[i] * multiplier;
        multiplier *= 10; 
    }
    return ret;
}

int countOddNumInVector(vector<int> v){
    int cnt = 0;
    for(int i =0; i < v.size();i++){
        if(v[i] % 2 != 0) cnt+=1;
    }
    return cnt;
}

void recur(vector<int> v, int odd_num){
    int next_num;
    vector<int> next_num_vector;
    odd_num += countOddNumInVector(v); 
    if(v.size() == 1){
        max_odd_num = max(odd_num, max_odd_num);
        min_odd_num = min(odd_num, min_odd_num);
        return;
    }else if(v.size() == 2){
        next_num = v[0] + v[1];
        next_num_vector = intToVector(next_num);
        recur(next_num_vector, odd_num);
    }else{ // 크기가 3 이상
        for(int i = 1; i < v.size()-1;i++){
            for(int j = i + 1; j < v.size();j++){
                int num1, num2, num3;
                num1 = vectorToInt(v, 0, i);
                num2 = vectorToInt(v, i, j);
                num3 = vectorToInt(v, j, v.size());
                next_num = num1 + num2 + num3;
                next_num_vector = intToVector(next_num);
                recur(next_num_vector, odd_num);
            }
        }
    }
}

int main(){
    int input;
    cin >> input;
    recur(intToVector(input), 0);
    cout << min_odd_num <<" " << max_odd_num << endl;
    return 0;
}