class Solution {
public:
    string reverseWords(string s) {
        stack<string> str;
        string help = "";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (!help.empty()) { // Khali space push na ho
                    str.push(help);
                    help = "";
                }
            } else {
                help += s[i];
            }
        }
        
        // Loop ke baad bacha hua last word push karna
        if (!help.empty()) {
            str.push(help);
        }

        help = "";
        while (!str.empty()) {
            help += str.top();
            str.pop(); // Brackets correct kiye
            if (!str.empty()) {
                help += ' '; // Aakhri word ke baad extra space na aaye
            }
        }

        return help;
    }
};