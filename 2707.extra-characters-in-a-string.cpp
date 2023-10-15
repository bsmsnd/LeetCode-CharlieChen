/*
 * @lc app=leetcode id=2707 lang=cpp
 *
 * [2707] Extra Characters in a String
 */

// @lc code=start
// #define DEBUG_ON_LOCAL_MACHINE

#ifdef DEBUG_ON_LOCAL_MACHINE
#include "helper.h"
#include <algorithm>
#endif

struct WordTreeNode {
    WordTreeNode *children[26];
    bool isWord;
    WordTreeNode() : isWord(false) {
        memset(children, 0, sizeof(children));
    }
};

class Solution {
public:
    void GetWordStatus(vector<vector<bool>> &isWordExist, int N, const string &s) {
        auto isWordInDictionary = [this](const string& word) -> bool {
            WordTreeNode *current = &this->root;
            for (char c: word) {
                uint32_t idx = c - 'a';
                if (current->children[idx] == nullptr) {
                    return false;
                }
                current = current->children[idx];
            }
            return current->isWord;
        };
        for (uint32_t i = 0; i < N; i++) {
            for (uint32_t j = i; j < N; j++) {
                string subStr = s.substr(i, j - i + 1);
                isWordExist[i][j] = isWordInDictionary(subStr);
            }
        }
    }

    void BuildTree(const vector<string>& dictionary)
    {
        auto buildTree = [this](const string& word) {
            WordTreeNode *current = &this->root;
            for (char c: word) {
                uint32_t idx = c - 'a';
                if (current->children[idx] == nullptr) {
                    current->children[idx] = new WordTreeNode();
                }
                current = current->children[idx];
            }
            current->isWord = true;
        };
        for_each(dictionary.begin(), dictionary.end(), buildTree);
    }

    int GetMinExtraChars(const string &s, uint32_t beginPos, uint32_t endPos, vector<vector<int>> &minExtraCharacters, const vector<vector<bool>> &isWordExist) {
        if (minExtraCharacters[beginPos][endPos] != -1) {
            return minExtraCharacters[beginPos][endPos];
        }
        if (isWordExist[beginPos][endPos]) {
            return minExtraCharacters[beginPos][endPos] = 0;
        }
        int minValue = endPos - beginPos + 1;
        for (uint32_t i = beginPos; i < endPos; i++) {
            minValue = min(minValue, GetMinExtraChars(s, beginPos, i, minExtraCharacters, isWordExist) + GetMinExtraChars(s, i + 1, endPos, minExtraCharacters, isWordExist));
        }
        return minExtraCharacters[beginPos][endPos] = minValue;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        const uint32_t N = s.size();
        const uint32_t M = dictionary.size();
        vector<vector<bool>> isWordExist(N);
        for_each(isWordExist.begin(), isWordExist.end(),
            [&N](vector<bool>& v) {
                v.resize(N, false);
            }
        );
        BuildTree(dictionary);
        GetWordStatus(isWordExist, N, s);

        vector<vector<int>> minExtraCharacters(N);
        // initialize the minExtraCharacters vector
        for_each(minExtraCharacters.begin(), minExtraCharacters.end(),
            [&N](vector<int>& v) {
                v.resize(N, -1);
            }
        );
        int answer = GetMinExtraChars(s, 0, s.size() - 1, minExtraCharacters, isWordExist);
        return answer;
    }
    WordTreeNode root;
};


#ifdef DEBUG_ON_LOCAL_MACHINE
int main()
{
    Solution sol;
    vector<string> dictionary = {"leet","code","leetcode"};
    cout << sol.minExtraChar("leetscode", dictionary) << endl;
}
#endif
// @lc code=end

