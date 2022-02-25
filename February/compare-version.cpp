//
// Created by sumit Kushwah on 25/02/22.
//

#include "declaration.h"

vector<int> separateRevisions(string version) {
    string temp = "";
    vector<int> ans;
    for (char ch: version) {
        if (ch == '.') {
            ans.push_back(stoi(temp));
            temp.clear();
            continue;
        }
        temp.push_back(ch);
    }
    ans.push_back(stoi(temp));
    return ans;
}

int compareVersion(string version1, string version2) {
    vector<int> first = separateRevisions(version1);
    vector<int> second = separateRevisions(version2);
    int i = 0, j = 0;

    while (i < first.size() && j < second.size()) {
        if (first[i] > second[j]) return 1;
        if (first[i] < second[j]) return -1;
        i++; j++;
    }

    while (i < first.size()) {
        if (first[i] > 0) return 1;
        i++;
    }

    while(j < second.size()) {
        if (second[j] > 0) return -1;
        j++;
    }

    return 0;
}
