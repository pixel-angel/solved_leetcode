class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        string ans = "";
        // index wise add karenge
        // some observations:
        // 1. we need to count how many charcters to skip to add the next onw to
        // ans
        // 2. if row = 1st or last (nth) toh usme diagonal element nhi aate
        //  toh unke liye skip would be simply (number of diagonal elements +
        //  n-1) and diagonal elements=n-2
        //  =(2*n-3) skip i.e. (2*n-2) th char.
        // 3.ab for any ith row between 1st and last uske 2 letters add hoenge.
        // ek diagonal aur ek column waala
        //  for diagonal it would be (n-i  +  n-1-i) skip i.e. 2*(n-i)th char
        // and column wise its (joh abhi add kra uske aage ke hisaab se)
        // diagonally = i-2 and col wise =i-1 that is last char (2*(n-i)) se
        // (2*i-3) skip  i.e. 2*(i-1) th char.

        // edge case
        if (numRows == 1 || numRows == n)
            return s;

        for (int i = 1; i <= numRows; i++) {
            // starting index=i-1
            int sidx = i - 1;
            // ans+=s[sidx];
            if (i == 1 || i == numRows) {
                for (int j = sidx; j < n; j += 2 * (numRows - 1))
                    ans += s[j];
            } else {
                int down = 2*(numRows-i);
                int up = 2*(i-1), j = sidx;
                bool toggle=true;
                while (j < n) {
                    ans += s[j];
                    if (toggle) j += down;
                    else j += up;
                    toggle = !toggle;
                }
            }
        }
        return ans;
    }
};