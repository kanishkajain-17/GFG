class Solution
{
public:
    void computeLPS(string pattern, vector<int>& lps) {
        int M = pattern.length();
        int len = 0;
        lps[0] = 0;

        int i = 1;
        while (i < M) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    vector<int> search(string pat, string txt) {
        // 🔴 GFG passes parameters reversed
        string text = pat;
        string pattern = txt;

        int N = text.length();
        int M = pattern.length();
        vector<int> result;

        if (M > N) return result;

        vector<int> lps(M, 0);
        computeLPS(pattern, lps);

        int i = 0, j = 0;

        while (i < N) {
            if (pattern[j] == text[i]) {
                i++;
                j++;
            }

            if (j == M) {
                result.push_back(i - j);  // 0-based index
                j = lps[j - 1];
            }
            else if (i < N && pattern[j] != text[i]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }

        return result;
    }
};