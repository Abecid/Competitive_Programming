#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

const int INF = 1e9 + 7;
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

long long rk_index(char c, int index, int size) {
  // const int p = 31;
  return ctoi(c) * pow(p, size - index);
}

long long rk_hash(string const &s) {
  // const int p = 31;
  const int m = INF;
  long long hash_value = 0;
  int index = 1;
  for (char c : s) {
    hash_value += rk_index(c, index, s.size());
    // hash_value += ctoi(c) * pow(p, s.size() - index);
    index++;
  }
  return hash_value % m;
}

long long next_hash(long long hash_value, char prev, char next,
                    string const &s) {
  // const int p = 31;
  const int m = INF;
  return ((hash_value - rk_index(prev, 1, s.size())) * p + ctoi(next)) % m;
}

vector<int> prefix_occurrences(const string &text, const string &pattern) {
  vector<int> pi(pattern.size(), 0);
  for (int i = 1, j = 0; i < pattern.size(); ++i) {
    while (j > 0 && pattern[i] != pattern[j]) {
      j = pi[j - 1];
    }
    if (pattern[i] == pattern[j]) {
      ++j;
    }
    pi[i] = j;
  }

  vector<int> occurrences(text.size(), 0);
  for (int i = 0, j = 0; i < text.size(); ++i) {
    while (j > 0 && text[i] != pattern[j]) {
      j = pi[j - 1];
    }
    if (text[i] == pattern[j]) {
      ++j;
    }
    occurrences[i] = j;
    if (j == pattern.size()) {
      j = pi[j - 1];
    }
  }

  return occurrences;
}

int main() {
  string A, B;
  int n;

  getline(cin, A);
  getline(cin, B);
  cin >> n;

  int pattern_length = A.size() - n + 1;
  if (pattern_length > B.size()) {
    pattern_length = B.size();
  }

  while(pattern_length > 0) {
  // for (pattern_length; pattern_length >= 1; pattern_length--) {
    // cout << "Pattern Size:" << pattern_length << endl;
    string pattern = B.substr(0, pattern_length);
    vector<int> occurrences = prefix_occurrences(A, pattern);
    int count = 0;
    for (int x : occurrences) {
      if (x == pattern_length) {
        ++count;
      }
    }
    // cout << "matches: " << count << endl;
    if (count >= n) {
      cout << pattern << endl;
      return 0;
    }
    pattern_length--;
  }

  cout << "IMPOSSIBLE" << endl;

  return 0;
}