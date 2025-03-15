#include <string>
#include <vector>
#include <set>

using namespace std;

set<int> s[9];

// N을 a개 이어붙인 숫자를 만드는 함수 (예: 5, 3 -> 555)
int make_num(int N, int a){
    int num = 0;
    for(int i = 0; i < a; i++){
        num = num * 10 + N;
    }
    return num;
}

int solution(int N, int number) {
    if(N == number) return 1;

    for(int i = 1; i <= 8; i++){
        s[i].insert(make_num(N, i));
        
        for(int j = 1; j < i; j++){
            for(int num1 : s[j]){
                for(int num2 : s[i-j]){
                    s[i].insert(num1 + num2);
                    s[i].insert(num1 - num2);
                    s[i].insert(num1 * num2);
                    if(num2 != 0) s[i].insert(num1 / num2);
                }
            }
        }
        
        if(s[i].count(number)) return i;
    }
    return -1;
}
