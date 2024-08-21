class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;

        for (char c : s) {
            freq[c]++;
        }

        priority_queue<pair<int, char>> maxHeap;
        for (auto& it : freq) {
            maxHeap.push({it.second, it.first});
        }

        string result = "";
        pair<int, char> prev(-1, ' '); 

        while (!maxHeap.empty()) {
            auto curr = maxHeap.top();
            maxHeap.pop();
            result += curr.second;

            if (prev.first > 0) {
                maxHeap.push(prev);
            }

            curr.first--;
            prev = curr;
        }

        if (result.length() != s.length()) {
            return "";
        }
        return result;
    }
};
