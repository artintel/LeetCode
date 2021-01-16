/*
 * @Author: Mayc
 * @Date: 2021-01-16 09:09:19
 * @LastEditTime: 2021-01-16 09:09:31
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\牛客编程字节原题1\source_code.cpp
 * @这是一个漂亮的注释头
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool flag = false;;
void auto_check(const string& s) {
    int n = s.size();
     string temp;
    temp += s[0];
    temp += s[1];
    int index = 1;
    if (s[1] == s[0]) flag = true;
    for (int i = 2; i < n; i++) {
        if ( flag == false) {
            temp += s[i];
            index++;
            if (temp[index] == temp[index - 1]) flag = true;
        }
        else {
            if ( s[i] == temp[index] ) {
                continue;
            }
            else if( s[i] != temp[index] && temp[index] != temp[index - 1] ){
                temp += s[i];
                index++;
                flag = false;
            }
            else {
                temp += s[i];
                index++;
                continue;
            }
        }
    }
    flag = false;
    for (char elem : temp) {
        cout << elem;
    }
    cout << endl;
}

int main() {
    int n;
    string s;
    cin >> n;
    while (n--) {
        cin >> s;
        auto_check(s);
        s = "";
    }
    return 0;
}