#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <algorithm>
#include <cctype>

using namespace std;

// Задание 1
vector<int>::iterator Find(vector<int>::iterator first, vector<int>::iterator last, int value) {
    while (first != last) {
        if (*first == value) return first;
        ++first;
    }
    return last;
}

// Задание 2
vector<int>::iterator findInSorted(vector<int>::iterator first, vector<int>::iterator last, int value) {
    auto it = lower_bound(first, last, value);
    if (it != last && *it == value) return it;
    return last;
}


vector<string> splitWords(const string& str) {
    vector<string> words;
    string current;
    for (char c : str) {
        if (c == ' ' || c == ',' || c == '.') {
            if (!current.empty()) {
                words.push_back(current);
                current.clear();
            }
        } else {
            current += tolower(c);
        }
    }
    if (!current.empty()) words.push_back(current);
    return words;
}

// Задание 3
int wordsCounter(const string& str) {
    vector<string> words = splitWords(str);
    return words.size();
}

// Задание 4
map<string, int> wordsMapCounter(const string& str) {
    vector<string> words = splitWords(str);
    map<string, int> result;
    for (const auto& word : words) {
        result[word]++;
    }
    return result;
}

// Задание 5
vector<string> uniqueWords(const string& str) {
    map<string, int> wordCount = wordsMapCounter(str);
    vector<string> result;
    for (const auto& pair : wordCount) {
        if (pair.second == 1) {
            result.push_back(pair.first);
        }
    }
    return result;
}

// Задание 6
int diffWordsCounter(const string& str) {
    map<string, int> wordCount = wordsMapCounter(str);
    return wordCount.size();
}

// Задание 7
void reverseNum(list<int>& nums) {
    auto it = nums.begin();
    while (it != nums.end()) {
        nums.insert(it, -(*it));
        ++it;
    }
}

// Задание 8
void plusesDelete(vector<int>& v) {
    v.erase(remove_if(v.begin(), v.end(), [](int x) { return x > 0; }), v.end());
}

// Задание 9
void Sort(list<int>& nums) {
    nums.sort(greater<int>());
}

int main() {
    vector<int> v = {6, 8, 1, 2, 3, 4, 5};
    auto it = Find(v.begin(), v.end(), 2);
    if (it != v.end()) cout << "Found: " << *it << endl;

    vector<int> sorted_v = {1, 2, 3, 4, 5};
    auto sorted_it = findInSorted(sorted_v.begin(), sorted_v.end(), 2);
    if (sorted_it != sorted_v.end()) cout << "Found in sorted: " << *sorted_it << endl;

    string sentence = "Can you can a can, can you?";
    cout << "Words count: " << wordsCounter(sentence) << endl;

    auto wordMap = wordsMapCounter(sentence);
    cout << "Word 'can' appears " << wordMap["can"] << " times" << endl;

    auto unique = uniqueWords(sentence);
    cout << "Unique words: ";
    for (const auto& word : unique) cout << word << " ";
    cout << endl;

    cout << "Different words count: " << diffWordsCounter(sentence) << endl;

    list<int> nums = {1, 5, 4, -3};
    reverseNum(nums);
    cout << "After reverse: ";
    for (int n : nums) cout << n << " ";
    cout << endl;

    vector<int> numbers = {1, 0, -8, -9, 0, 10, 23, -7};
    plusesDelete(numbers);
    cout << "After delete positives: ";
    for (int n : numbers) cout << n << " ";
    cout << endl;

    list<int> to_sort = {1, 5, 4, -3};
    Sort(to_sort);
    cout << "After sorting: ";
    for (int n : to_sort) cout << n << " ";
    cout << endl;

    return 0;
}
