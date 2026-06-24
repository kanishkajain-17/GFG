class Solution {
public:
    bool topoDFS(vector<vector<int>>& adj, int u,
                 vector<int>& state, stack<int>& st) {
        state[u] = 1; // visiting

        for (int v : adj[u]) {
            if (state[v] == 1)
                return false; // cycle
            if (state[v] == 0) {
                if (!topoDFS(adj, v, state, st))
                    return false;
            }
        }

        state[u] = 2; // visited
        st.push(u);
        return true;
    }

    string findOrder(vector<string>& words) {
        int V = 26;
        vector<vector<int>> adj(V);
        vector<bool> visited(V, false);

        // mark present characters
        for (auto &w : words)
            for (char c : w)
                visited[c - 'a'] = true;

        // build graph
        for (int i = 0; i < words.size() - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];
            int len = min(s1.length(), s2.length());

            bool mismatchFound = false;

            for (int j = 0; j < len; j++) {
                if (s1[j] != s2[j]) {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    mismatchFound = true;
                    break;
                }
            }

            // 🔴 PREFIX INVALID CASE
            if (!mismatchFound && s1.length() > s2.length())
                return "";
        }

        vector<int> state(V, 0);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (visited[i] && state[i] == 0) {
                if (!topoDFS(adj, i, state, st))
                    return "";
            }
        }

        string ans = "";
        while (!st.empty()) {
            ans += char(st.top() + 'a');
            st.pop();
        }
        return ans;
    }
};