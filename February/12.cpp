#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string> wordList) {
    if (beginWord == endWord) return 0;
    unordered_map<string, int> umap;
    for (int i = 0; i < wordList.size(); i++) {
        umap[wordList[i]] = i;  
    }
    
    if (umap.find(endWord) == umap.end()) return 0;
    int ans = INT_MAX;
    for (int i = 0; i < beginWord.size(); i++) {
        if (beginWord[i] != endWord[i]) {
            string temp = beginWord;
            temp[i] = endWord[i];
            if (umap.find(temp) != umap.end()) {
                wordList.erase(wordList.begin() + umap[temp]);
                ans = min(ans, 1 + ladderLength(temp, endWord, wordList));
            }
        }
    }
    
    return ans == INT_MAX ? 0: ans;
}

int main() {
    vector<string> wordList;
    wordList.push_back("hot");
    wordList.push_back("dot");
    wordList.push_back("dog");
    wordList.push_back("lot");
    wordList.push_back("log");
    wordList.push_back("cog");
    string beginWord = "hit";
    string endWord = "cog";
    cout << ladderLength(beginWord, endWord, wordList) << endl;
    return 0;
}
