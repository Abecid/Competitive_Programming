/*
Text Editor
*/

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

const int INF = 1e9+7;
const int p = 101;

int ctoi(char c) {
    /*
    Maps the given character c to an integer for hashing. Feel free to change
    this if you want but MAKE SURE NOTHING IS EVER MAPPED TO ZERO.
   
    This expression returns 1 for 'a', 2 for 'b', 3 for 'c', and so on.
    */
    return c - 32;
    // return c - 'a' + 1;
}

long long compute_hash(string const& s) {
    // const int p = 31;
    const int m = INF;
    long long hash_value = 0;
    for (char c : s) {
        hash_value = (p * hash_value + ctoi(c)) % m;
    }
    return hash_value;
}

long long rk_index(char c, int index, int size) {
    // const int p = 31;
    return ctoi(c) * pow(p, size - index);
}

long long rk_hash(string const& s) {
    // const int p = 31;
    const int m = INF;
    long long hash_value = 0;
    int index = 1;
    for (char c:s) {
        hash_value += rk_index(c, index, s.size());
        // hash_value += ctoi(c) * pow(p, s.size() - index);
        index++;
    }
    return hash_value % m;
}

long long next_hash(long long hash_value, char prev, char next, string const& s) {
    // const int p = 31;
    const int m = INF;
    return ( (hash_value - rk_index(prev, 1, s.size())) * p + ctoi(next) ) % m;
}

long long next_hash_remove_last_char(long long hash_value, char last) {
    // const int p = 31;
    const int m = INF;
    return ( (hash_value - last) / p ) % m;
}

string substring(string const& s, int start, int end) {
    return s.substr(start, end - start + 1);
}

int main() {
  string A, B;
  int n;

  getline(cin, A);
  getline(cin, B);
  cin >> n;

  int max_pattern_size = A.size() - n + 1;
  if(max_pattern_size > B.size()) {
    max_pattern_size = B.size();
  }

  string pattern = "";
  string s = "";

  while(max_pattern_size-- > 0) {
    int s_hash = 0;
    
    int matches = 0;
    // substring
    
    if(s.size() == 0) {
        s = substring(B, 0, max_pattern_size);
        s_hash = rk_hash(s);
    }
    else {
        s_hash = next_hash_remove_last_char(s_hash, s.back());
        s = substring(B, 0, max_pattern_size);
    }
    int s2_hash = 0;
    // for loop, check with A
    for(int j=0; j< A.size()-max_pattern_size+1; j++) {
        string s2 = substring(A, j, j+max_pattern_size);
        if(j == 0)
            s2_hash = rk_hash(s2);
        else {
            s2_hash = next_hash(s2_hash, A[j-1], A[j+max_pattern_size-1], s2);
        }
        if(s_hash == s2_hash) {
            matches++;
        }
    }
    if(matches >= n) {
        pattern = s;
        cout << pattern << endl;
        return 0;
    }
    
  }

  cout << "IMPOSSIBLE" << endl;

  return 0;
}
