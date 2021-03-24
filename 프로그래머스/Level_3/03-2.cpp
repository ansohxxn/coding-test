#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int solution(int N, int number) {
    int const min = 9;
	vector<set<int>> v(min);

	for (int i = 1; i < min; i++) {
        // 1 열 (행과 동일한 5, 55, 555 등등)
        int result = 0;
        for (int j = 0; j < i; j++){
		      result = result * 10 + N;
	      }
		v[i].insert(result);
        
    // 1열이 아닌 그 외의 열
		for (int j = 1; j < i; j++) {
			for (int k = 1; k < i; k++) {
				if (j + k == i) {
					for (auto a : v[j]) {
						for (auto b : v[k]) {
							v[i].insert(a + b);
							v[i].insert(a * b);
							if (a > b) v[i].insert(a - b);
							if (a < b) v[i].insert(b - a);
							if (b > 0) v[i].insert(a / b);
							if (a > 0) v[i].insert(b / a);
						}
					}
				}
			}
		}
	}
    
    // 최소값 도출
	for (int i = 1; i < min; i++) {
		for (auto j : v[i]) if (j == number) {
			return i;
		}
	}
	
	return -1;
}