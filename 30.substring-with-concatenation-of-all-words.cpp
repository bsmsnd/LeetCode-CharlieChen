/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */

// @lc code=start
// #include "helper.h"
// #include <cstring>

constexpr int NUM_OF_NODES = 26;
constexpr int INVALID_WORD_INDEX = -1;

struct DictTreeNode {
    int wordIndex;
    int occurrences;
    DictTreeNode* nodes[NUM_OF_NODES];
    DictTreeNode() : wordIndex (INVALID_WORD_INDEX) {
        memset(nodes, 0, sizeof(nodes));
    }
    DictTreeNode*& Get(char ch) {
        return nodes[ch - 'a'];
    }
};

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> substrings;
        int realWords = Build(words);
        int wordLength = words[0].length();
        int stringLength = s.length();
        int numOfWords = words.size();
        for (int i = 0; i < wordLength; ++i) {
            // generate indices
            vector<int> wordIndices;
            for (int j = i; j <= stringLength - wordLength; j += wordLength) {
                wordIndices.push_back(GetWordIndex(s, j, wordLength));
            }
            // two-pointer to see if concatenated substring exists
            int leftPointer = 0;
            int rightPointer = 0;
            int matchCount = 0;
            int numOfIndices = wordIndices.size();
            vector<int> actualOccurrences(realWords, 0);
            for (; rightPointer < min(numOfWords, numOfIndices); rightPointer++) {
                if (wordIndices[rightPointer] != INVALID_WORD_INDEX) {
                    if (actualOccurrences[wordIndices[rightPointer]] < requiredOccurrences[wordIndices[rightPointer]]) {
                        matchCount++;
                    }
                    actualOccurrences[wordIndices[rightPointer]]++;
                }
            }
            if (matchCount == numOfWords) {
                substrings.push_back(i);
            }
            while (rightPointer < numOfIndices) {
                if (wordIndices[leftPointer] != INVALID_WORD_INDEX) {
                    if (actualOccurrences[wordIndices[leftPointer]] <= requiredOccurrences[wordIndices[leftPointer]]) {
                        matchCount--;
                    }
                    actualOccurrences[wordIndices[leftPointer]]--;
                }
                leftPointer++;
                if (wordIndices[rightPointer] != INVALID_WORD_INDEX) {
                    if (actualOccurrences[wordIndices[rightPointer]] < requiredOccurrences[wordIndices[rightPointer]]) {
                        matchCount++;
                    }
                    actualOccurrences[wordIndices[rightPointer]]++;
                }
                rightPointer++;
                if (matchCount == numOfWords) {
                    substrings.push_back(i + leftPointer * wordLength);
                }
            }
        }
        return substrings;
    }
protected:
    int Build(const vector<string>& words)
    {
        int repeatWords = 0;
        int numOfWords = words.size();
        requiredOccurrences.resize(numOfWords, 0);
        for (int i = 0; i < numOfWords; i++) {
            DictTreeNode *currentNode = &root;
            for (char ch : words[i]) {
                if (currentNode->Get(ch) == nullptr) {
                    currentNode->Get(ch) = new DictTreeNode();
                }
                currentNode = currentNode->Get(ch);
            }
            if (currentNode->wordIndex == -1) {
                currentNode->wordIndex = i - repeatWords;
                currentNode->occurrences = 1;
            } else {
                repeatWords++;
                currentNode->occurrences++;
            }
            requiredOccurrences[currentNode->wordIndex]++;
        }
        return numOfWords - repeatWords;
    }
    int GetWordIndex(const string& word, int startPos, int wordLength) {
        DictTreeNode *currentNode = &root;
        for (int i = 0; i < wordLength; i++) {
            if (currentNode->Get(word[i + startPos]) == nullptr) {
                return INVALID_WORD_INDEX;
            }
            currentNode = currentNode->Get(word[i + startPos]);
        }
        return currentNode->wordIndex;
    }
private:
    DictTreeNode root;
    vector<int> requiredOccurrences;
};
// @lc code=end

