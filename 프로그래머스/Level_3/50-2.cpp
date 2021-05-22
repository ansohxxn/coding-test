#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<string> solution(vector<string> s) {
	vector<string> answer(s.size());

	for (int i = 0; i < s.size(); ++i) {
		deque<char> dq;
		int count = 0;
		
		for (int j = 0; j < s[i].length(); ++j) {
			dq.push_back(s[i][j]);
			int n = dq.size();
			if (n >= 3 && dq[n - 3] == '1' && dq[n - 2] == '1' && dq[n - 1] == '0') {
				++count;
				dq.pop_back(); 
				dq.pop_back(); 
				dq.pop_back();
			}
		}

		if (count == 0) {
			answer[i] = s[i];
			continue;
		}

		int insert_idx = dq.size();
		string str = "";
		bool end_111 = false;
		for (int i = dq.size() - 1; i >= 0; --i) {
			if (!end_111 && dq[i] == '1') --insert_idx;
			else end_111 = true;
			str = dq[i] + str;
		}

		while (count-- > 0) 
			str.insert(insert_idx, "110");
		answer[i] = str;
	}

    return answer;
}