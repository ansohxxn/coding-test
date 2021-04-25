#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
	int answer = 0;
	int sum = 0;
	vector <int> s;
	for (int i = 0; i < n; i++) s.push_back(-1);
	for (int i = 0; i < n; i++) s.push_back(1);
    
	do {
		sum = 0;
		answer++;
		for (int i = 0; i < 2 * n; i++) {
			sum += s[i];
			if (sum < 0) { 
				answer--;
				break;
			}
		}
	} while (next_permutation(s.begin(), s.end())); 
	return answer;
}