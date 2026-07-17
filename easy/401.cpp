class Solution {
public:
    vector<int> r = {32,16,8,4,2,1};

    // choose hours
    void choosehour(int need, vector<int> &hrs, int idx, int sum) {
        if (need == 0) {
            if (sum < 12)
                hrs.push_back(sum);
            return;
        }

        if (idx == 6) return;

        choosehour(need - 1, hrs, idx + 1, sum + r[idx]);
        choosehour(need, hrs, idx + 1, sum);
    }

    // choose minutes
    void choosemin(int need, vector<int> &mins, int idx, int sum) {
        if (need == 0) {
            if (sum < 60)
                mins.push_back(sum);
            return;
        }

        if (idx == 6) return;

        choosemin(need - 1, mins, idx + 1, sum + r[idx]);
        choosemin(need, mins, idx + 1, sum);
    }

    vector<string> readBinaryWatch(int turnedOn) {

        vector<string> ans;

        for (int h = 0; h <= min(4, turnedOn); h++) {

            int m = turnedOn - h;
            if (m > 6) continue;

            vector<int> hrs, mins;

            choosehour(h, hrs, 2, 0);
            choosemin(m, mins, 0, 0);

            for (int hours : hrs) {
                for (int minutes : mins) {

                    string s = to_string(hours) + ":";

                    if (minutes < 10)
                        s += "0";

                    s += to_string(minutes);

                    ans.push_back(s);
                }
            }
        }

        return ans;
    }
};