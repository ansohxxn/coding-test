#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

int solution(std::vector<int> a) {
    int max = 0;
    set<int> elements;
    unordered_map<int, vector<int>> index_storage;

    for (int i = 0; i < a.size(); ++i) {
        elements.insert(a[i]);
        index_storage[a[i]].push_back(i);
    }

    vector<bool> included(a.size(), false);
    for (auto& element : elements) {
        vector<int> indexArray(index_storage[element]);
        if (max > 2 * indexArray.size()) continue;
        int count = 0;
        for (int j = 0; j < indexArray.size(); ++j) {
            bool before = false;
            if (j == 0)
                before = indexArray[j] - 1 >= 0;
            else
                before = (included[indexArray[j] - 1] == false) && (indexArray[j] - 1 != indexArray[j - 1]);

            bool after = false;
            if (j == indexArray.size() - 1)
                after = indexArray[j] + 1 < a.size();
            else if (indexArray[j] + 1 < a.size())
                after = (included[indexArray[j] + 1] == false) && (indexArray[j] + 1 != indexArray[j + 1]);

            if (before || after) {
                count += 2;
                if (before) {
                    included[indexArray[j]] = true;
                    included[indexArray[j] - 1] = true;
                    continue;
                }
                else if (after) {
                    included[indexArray[j]] = true;
                    included[indexArray[j] + 1] = true;
                }
            }
        }

        max = max < count ? count : max;

        fill(included.begin(), included.end(), false);
    }

    return max;
}