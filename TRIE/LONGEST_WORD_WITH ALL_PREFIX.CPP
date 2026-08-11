/*
Longest Valid Word with All Prefixes
Difficulty: Medium
Accuracy: 52.2%
Submissions: 12K+
Points: 4

Problem:
Given an array of strings words[], find the longest string such that every prefix of it is also present in words[]. 
If multiple strings have the same maximum length, return the lexicographically smallest one.

If no such string is found, return an empty string.

Examples:
Input: words[] = ["p", "pr", "pro", "probl", "problem", "pros", "process", "processor"]
Output: "pros"
Explanation: "pros" is the longest word with all prefixes ("p", "pr", "pro", "pros") present.

Input: words[] = ["geeks", "gfg", "geeksforgeeks"]
Output: ""
Explanation: No valid strings for all their prefixes present in the words array.

Constraints:
- 1 <= words.length <= 10^5
- 1 <= words[i].length <= 100
- words[i] consists of lowercase English letters
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[26];
    bool flag;

    Node() {
        for (int i = 0; i < 26; i++) links[i] = nullptr;
        flag = false;
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

struct Trie {
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    bool checkAllPrefixes(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) return false;
            node = node->get(ch);
            if (!node->isEnd()) return false; // every prefix must be a complete word
        }
        return true;
    }
};

string completeString(int n, vector<string> &words) {
    Trie trie;
    for (string &w : words) trie.insert(w);

    string longest = "";
    for (string &w : words) {
        if (trie.checkAllPrefixes(w)) {
            if (w.size() > longest.size() || 
               (w.size() == longest.size() && w < longest)) {
                longest = w;
            }
        }
    }
    return longest.empty() ? "" : longest;
}

int main() {
    vector<string> words1 = {"p", "pr", "pro", "probl", "problem", "pros", "process", "processor"};
    cout << completeString(words1.size(), words1) << endl; // Output: "pros"

    vector<string> words2 = {"geeks", "gfg", "geeksforgeeks"};
    cout << completeString(words2.size(), words2) << endl; // Output: ""
}
