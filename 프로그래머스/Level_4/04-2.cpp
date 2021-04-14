#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const string& a, const string& b) {
    if (a.length() < b.length())
        return true;
    else if (a.length() == b.length())
        if (a < b) return true;
    return false;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    vector<string> rwords(words);
    for (int i = 0; i < rwords.size(); i++) 
        reverse(rwords[i].begin(), rwords[i].end());
    
    sort(words.begin(), words.end(), comp);
    sort(rwords.begin(), rwords.end(), comp);

    for (string query : queries) {
        if (query[0] != '?') {
            string start(query);
            for (int i = 0; i < start.length(); ++i)
                if (start[i] == '?')
                    start[i] = 'a';
            auto start_ptr = lower_bound(words.begin(), words.end(), start, comp);

            string end(query);
            for (int i = 0; i < end.length(); ++i)
                if (end[i] == '?')
                    end[i] = 'z';
            auto end_ptr = upper_bound(words.begin(), words.end(), end, comp);
            
            answer.push_back(end_ptr - start_ptr);
        }
        else {
            reverse(query.begin(), query.end());
            string start(query);
            for (int i = 0; i < start.length(); ++i)
                if (start[i] == '?')
                    start[i] = 'a';
            auto start_ptr = lower_bound(rwords.begin(), rwords.end(), start, comp);

            string end(query);
            for (int i = 0; i < end.length(); ++i)
                if (end[i] == '?')
                    end[i] = 'z';
            auto end_ptr = upper_bound(rwords.begin(), rwords.end(), end, comp);

            answer.push_back(end_ptr - start_ptr);
        }
    }

    return answer;
}