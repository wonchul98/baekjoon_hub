#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <cmath>

using namespace std;

int getMid(int s, int e) {
    return (s + e) / 2;
}

bool check(bitset<50> b, int s, int e) {
    // printf("check(%d, %d)\n", s, e);
    if (s > e) return true;
    
    int mid = getMid(s, e);
    int left = getMid(s, mid - 1);
    int right = getMid(mid + 1, e);

    if (b[mid] == 0) {
        if ((left >= s && b[left] == 1) || (right <= e && b[right] == 1)) {
            return false;
        }
    }
    if(e-s == 2) return true;
    return check(b, s, mid - 1) && check(b, mid + 1, e);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for (long long n : numbers) {
        bitset<50> b(n);

        int e = 0;
        for (int i = 0; i < 50; i++) {
            if (b[i] == 1) {
                e = i;
            }
        }

        long long p = 1;
        while (e >= p) {
            p *= 2;
        }
        e = p - 2;


        if (check(b, 0, e)) {
            answer.push_back(1);
        } else {
            answer.push_back(0);
        }
    }
    
    return answer;
}
