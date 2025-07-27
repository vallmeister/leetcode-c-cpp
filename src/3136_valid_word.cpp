#include <iostream>
#include <string>
#include <cctype>

class Solution {
public:
    bool isValid(std::string word) {
        if (word.length() < 3) {
            return false;
        }
        bool has_vowel = false;
        bool has_consonant = false;

        for (char c : word) {
            if (!std::isalpha(c) && !std::isdigit(c)) {
                return false;
            }
            has_vowel |= is_vowel(c);
            has_consonant |= is_consonant(c);
        }

        return has_vowel && has_consonant;
    }

    bool is_vowel(char c) {
        c = std::tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    bool is_consonant(char c) {
        c = std::tolower(c);
        return !is_vowel(c) && 'a' <= c && c <= 'z';
    }
};