//
// Created by Kylian Lee on 2021/06/22.
//

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int solution(string a, string b);

int main() {
  int caseNum;
  string a, b;
  cin >> caseNum;
  for (int i = 0; i < caseNum; ++i) {
    cin >> a >> b;
    if(a == b)
      cout << 0 << endl;
    else if (a.length() >= b.length())
      cout << solution(a, b) << endl;
    else
      cout << solution(b, a) << endl;
  }
  return 0;
}

int solution(string a, string b){
  set<string> check;
  int len = b.length();
  vector<vector<string>> v(len + 1);
  for (int i = 1; i <= len; ++i) {
    for (int j = 0; j <= len - i; ++j) {
      string s = b.substr(j, i);
      if(check.find(s) == check.end()){
        check.insert(s);
        v[i].push_back(s);
//        cout << s << endl;
      }
    }
  }
  for (int i = len; i > 0; --i) {
    for (int j = 0; j < v[i].size(); ++j) {
      string s = v[i][j];
      int pos = a.find(s);
      if(pos != string::npos){
        return a.length() - s.length() + len - s.length();
      }
    }
  }
  return a.length() + len;
}