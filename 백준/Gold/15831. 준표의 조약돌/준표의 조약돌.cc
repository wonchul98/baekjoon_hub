#include<iostream>
#include<vector>

using namespace std;

int N, b, w; // 조약돌의 수, 흑 돌의 수, 백 돌의 수
string input;
int bCount, wCount; // 0으로 자동 초기화
int ans;

bool isSatisfied(){
    if(bCount <= b && wCount >= w) return true;
    return false;
}

int main(){
    cin >> N >> b >> w;
    cin >> input;
    int s = 0, e = 0;
    if(input[0] == 'W') wCount++;
    else bCount++;
    while(true){ //e가 끝 idx까지 가고, 조건을 만족하면 종료
        // cout << "s: " << s << " e: " << e << endl;
        // cout << "wCount: " << wCount << " bCount: " << bCount << endl;
        // cout << "ans: " << ans << endl;
        if(bCount > b){ // b가 많으면 s를 오른쪽
            // cout << "type2" << endl;
            if(input[s] == 'W') wCount--;
            else bCount--;
            s++;
        } else if(wCount < w){ // w가 부족하면 e를 오른쪽
            // cout << "type1" << endl;
            e++;
            if(e == input.size()) break;
            if(input[e] == 'W') wCount++;
            else bCount++;
        }else{ // 만족
            // cout << "type3!!!!!!!11" << endl;
            ans = max(ans, e - s + 1); // 길이 갱신

            e++;
            if(e == input.size()) break;
            // cout << "ans: " << ans << endl;
            if(input[e] == 'W') wCount++;
            else bCount++;
        }
    }
    cout << ans << endl;
    return 0;
}