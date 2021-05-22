#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<string> solution(vector<string> s) {
	vector<string> answer(s.size());

	for (int i = 0; i < s.size(); ++i) {
		stack<char> st;
		int count = 0;
		
		for (int j = 0; j < s[i].length(); ++j) {
            st.push(s[i][j]);
			if (st.size() >= 3) {
                char three = st.top(); st.pop();
				char two = st.top(); st.pop();
				char one = st.top(); st.pop();

				if (one == '1' && two == '1' && three == '0') {
					++count;
					continue;
				}
				else {
					st.push(one);
					st.push(two);
					st.push(three);
				}
			}
		}

		if (count == 0) {
			answer[i] = s[i];
			continue;
		}

		int insert_idx = st.size();
		string str = "";
		while (!st.empty() && st.top() == '1') {
			--insert_idx;
			str = st.top() + str;
			st.pop();
		}
		while (!st.empty()) {
			str = st.top() + str;
			st.pop();
		}

		while (count-- > 0) 
			str.insert(insert_idx, "110");
		answer[i] = str;
	}

    return answer;
}