/*
 * @lc app=leetcode id=68 lang=cpp
 *
 * [68] Text Justification
 */

// @lc code=start
// #include "helper.h"
// #include <_types/_uint32_t.h>

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> rows;
        const int N = words.size();
        int i = 0;
        while (i < N) {
            // pick words
            int sumOfLength = words[i].length();
            int j = i + 1;
            while (j < N && sumOfLength + words[j].length() + 1 <= maxWidth) {
                sumOfLength += (words[j++].length() + 1);                
            }
            string currentRow = "";
            
            // LAST ROW
            if (j == N) {
                for (int k = i; k < j - 1; k++) {
                    currentRow += (words[k] + ' ');                    
                }
                currentRow += words[j - 1];
                while (currentRow.length() < maxWidth) {
                    currentRow += ' ';
                }
                rows.push_back(currentRow);                
                i = j;
                break;
            }

            // NOT YET LAST ROW
            int numOfWords = j - i;
            int extraSpace = maxWidth - sumOfLength;
            for (int k = i ; k < j - 1; k++) {
                currentRow += (words[k] + ' ');
                int extraSpacePerSeparation = extraSpace / (j - k - 1);
                if (extraSpacePerSeparation * (j - k - 1) < extraSpace) {
                    extraSpacePerSeparation++;
                }
                extraSpace -= extraSpacePerSeparation;
                while(extraSpacePerSeparation--) {
                    currentRow += ' ';
                }
            }
            currentRow += words[j - 1];
            while (currentRow.length() < maxWidth) {
                currentRow += ' ';
            }
            rows.push_back(currentRow);
            i = j;
        }
        return rows;
    }
};
// @lc code=end

