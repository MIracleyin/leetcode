//
// Created by 章寅 on 2021/12/22.
//

#ifndef LEETCODE_MYLIB_H
#define LEETCODE_MYLIB_H

#endif //LEETCODE_MYLIB_H

#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <iterator>

using namespace std;

void print2Dvector(vector<vector<int>>& matrix) {
    for (auto vi : matrix){
        cout << "[";
        for (auto vii : vi){
            cout << vii << ' ';
        }
        cout << "]," << "\n";
    }
}

void printMapKeyValue(map<string, int> has) {
    for(auto & ha : has){
        cout << ha.first << " : " << ha.second << endl;
    }
}