#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for (int i = 0; i < skill_trees.size(); i++)
    {
        int pos = -1;
        bool impossible = false;
        char impossibleChar = skill[0];
        for (int j = 0; j < skill.length(); j++)
        {
            if (j != skill.length())
                impossibleChar = skill[j + 1];

            for (int k = 0; k < pos; k++)
            {
                if (skill[j] == skill_trees[i][k])
                {
                    impossible = true;
                    break;
                }
            }

            for (int k = pos + 1; k < skill_trees[i].length(); k++)
            {
                if (skill[j] == skill_trees[i][k])
                {
                    pos = k;
                    break;
                }
                else if (impossibleChar == skill_trees[i][k])
                {
                    impossible = true;
                    break;
                }
            }
        }

        if (!impossible)
            answer++;
    }

    return answer;
}