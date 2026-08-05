/*
Problem:
Given a pattern and a string s, determine if s follows the same pattern.

Follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s:
- Each letter in pattern maps to exactly one unique word in s.
- Each unique word in s maps to exactly one letter in pattern.
- No two letters map to the same word, and no two words map to the same letter.

Examples:
Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Explanation: 'a' -> "dog", 'b' -> "cat"

Input: pattern = "abba", s = "dog cat cat fish"
Output: false

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
*/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word;
        stringstream ss(s);

        // Split s into words
        while (ss >> word) {
            words.push_back(word);
        }

        if (words.size() != pattern.size()) return false;

        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];

            if (charToWord.count(c) && charToWord[c] != w) return false;
            if (wordToChar.count(w) && wordToChar[w] != c) return false;

            charToWord[c] = w;
            wordToChar[w] = c;
        }

        return true;
    }
};
