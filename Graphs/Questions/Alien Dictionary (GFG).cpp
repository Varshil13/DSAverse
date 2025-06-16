/*
Alien Dictionary (GFG) - Explanation

Problem:
Given a sorted dictionary of an alien language, find the order of characters in the language.

Approach:
1. Build a directed graph:
    - For each pair of adjacent words, compare characters one by one.
    - The first different character between two words defines the order: 
      e.g., for ["xyz", "abc"], 'x' comes before 'a' (edge: x -> a).
    - If words are like ["xyz", "xyt"], compare until a difference is found: z -> t.
    - If one word is a prefix of another (e.g., ["abcde", "abcd"]), and the longer word comes first, it's invalid.

2. Topological Sort:
    - Perform Kahn's algorithm (BFS-based topological sort) on the graph.
    - If a cycle is detected (not all nodes are included in the result), return "" (invalid order).

Edge Cases:
- Prefix case: If a longer word comes before its prefix, return "".
- Cycle detection: If topological sort doesn't include all seen characters, return "".

Summary:
- Build adjacency list from word pairs.
- Topologically sort the graph to get the character order.
- Handle invalid cases as described above.
*/


class Solution {
private:

// to perform topological sort using Kahn's algorithm
    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        return topo;
    }

public:
    string findOrder(vector<string>& dict) {

        int N = dict.size();
        //create a boolean array to track seen characters
        bool seen[26] = {false};
        for (auto& word : dict) {
            for (char ch : word) {
                seen[ch - 'a'] = true;
            }
        }
        // Create an adjacency list for the graph
        // 26 characters in the alphabet
        vector<int> adj[26];
        // Build the graph based on the dictionary
        // Compare adjacent words to find the order of characters
        for (int i = 0; i < N - 1; i++) {
            string& s1 = dict[i];
            string& s2 = dict[i + 1];
            int len = min(s1.size(), s2.size());
            bool foundDiff = false;

            for (int ptr = 0; ptr < len; ptr++) {
                if (s1[ptr] != s2[ptr]) {
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    foundDiff = true;
                    break;
                }
            }

            // Handle prefix case like ["abc", "ab"]
            if (!foundDiff && s1.size() > s2.size()) {
                return "";
            }
        }
        // Perform topological sort on the graph
        // to get the order of characters
        vector<int> topo = topoSort(26, adj);

        // Check for cycles
        if (topo.size() < count(seen, seen + 26, true)) {
            return "";
        }
        // Build the result string from the topological sort
        // Only include characters that were seen in the input
        string ans = "";
        for (auto ch : topo) {
            if (seen[ch]) {
                ans += (char)(ch + 'a');
            }
        }

        return ans;
    }
};
