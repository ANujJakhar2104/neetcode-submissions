#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string encode(vector<string>& strs) {
        string sz = to_string(strs.size()) + "#";
        string str;

        for (string s : strs) {
            int n = s.size();
            sz += to_string(n) + "#";
            str += s;
        }

        sz += str;
        return sz;
    }

    vector<string> decode(string s) {
        vector<int> sz;
        stringstream ss(s);
        string word;
        int x = 0;
        vector<string> ans;
        string temp;

        while (getline(ss, word, '#')) {
            if (x == 0) {
                x = stoi(word);
                continue;
            }

            sz.push_back(stoi(word));
            x -= 1;
            
            if (x == 0) {
                getline(ss, temp, '\0');
                break;
            }
        }

        int i = 0;
        for (int size : sz) {
            ans.push_back(temp.substr(i, size));
            i += size;
        }
        
        return ans;
    }
};