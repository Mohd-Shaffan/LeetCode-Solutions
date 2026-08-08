class Solution {
public:
    int longestValidParentheses(string str) {
        int left = 0, right = 0;
        int maxLen = 0;

        // 1. Pass 1: Left to Right
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '(') left++;
            else right++;

            if (left == right) {
                maxLen = max(maxLen, 2 * right);
            } else if (right > left) {
                left = right = 0; // Reset boundary
            }
        }

        left = right = 0; // Reset counters for pass 2

        // 2. Pass 2: Right to Left
        for (int i = str.length() - 1; i >= 0; i--) {
            if (str[i] == '(') left++;
            else right++;

            if (left == right) {
                maxLen = max(maxLen, 2 * left);
            } else if (left > right) {
                left = right = 0; // Reset boundary
            }
        }

        return maxLen;
    }
};