#include <iostream>
#include <set>

using namespace std;

int main() {
  set<string> S;
  set<pair<int,string>> C;
  string str;
  int cas = 1;
  while (cin >> str) {
    if (str != "END" and str != "QUIT") {
      pair<set<string>::iterator, bool> res = S.insert(str);
      if (res.second) {
        C.erase({str.size(), str});
      }
      else {
        S.erase(res.first);
        C.insert({str.size(), str});
      }
    }
    else {
      cout << "GAME #" << cas << endl;
      cout << "HAS:" << endl;
      for (string x : S) cout << x << endl;
      cout << endl;
      cout << "HAD:" << endl;      
      for (auto x : C) cout << x.second << endl;
      if (str == "END") cout << endl;
      S = set<string>();
      C = set<pair<int,string>>();
      ++cas;
    }
  }

}
