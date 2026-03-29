class Solution {
public:
    bool checkequal(int a[26], int b[26]) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i])
                return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int c[26] = {0};

        // freq of s1
        for (char ch : s1) {
            c[ch - 'a']++;
        }

        int windowsize = s1.length();
        int count[26] = {0};

        // first window
        int i = 0;
        while (i < windowsize && i < s2.length()) {
            count[s2[i] - 'a']++;
            i++;
        }

        if (checkequal(c, count)) return true;

        // sliding window
        while (i < s2.length()) {
            count[s2[i] - 'a']++; // add new char

            count[s2[i - windowsize] - 'a']--; // remove old char

            if (checkequal(c, count)) return true;

            i++;
        }

        return false;
    }
};