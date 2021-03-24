#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long calculate(long long a, long long b, char op) {
    if (op == '+')
        return a + b;
    else if (op == '-')
        return a - b;
    else if (op == '*')
        return a * b;
}

long long solution(string expression) {
    long long answer = 0;

    vector<long long> record_operand;
    vector<char> record_operator;
    string temp = "";
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] >= '0' && expression[i] <= '9')
            temp += expression[i];
        else {
            record_operator.push_back(expression[i]);
            record_operand.push_back(stoll(temp));
            temp = "";
        }
    }
    record_operand.push_back(stoll(temp));

    vector<int> perm = { 0, 1, 2 };
    string op = "+-*";
    do {
        vector<long long> temp_operand = record_operand;
        vector<char> temp_operator = record_operator;
        for (int i = 0; i < perm.size(); i++) {
            for (int j = 0; j < temp_operator.size(); ) {
                if (temp_operator[j] == op[perm[i]]) {
                    long long res = calculate(temp_operand[j], temp_operand[j + 1], temp_operator[j]);

                    temp_operand.erase(temp_operand.begin() + j);
                    temp_operand.erase(temp_operand.begin() + j);
                    temp_operand.insert(temp_operand.begin() + j, res);

                    temp_operator.erase(temp_operator.begin() + j);
                }
                else
                    j++;
            }
        }
        answer = max(answer, abs(temp_operand[0]));
    } while (next_permutation(perm.begin(), perm.end()));

    return answer;
}