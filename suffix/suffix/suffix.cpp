#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "suffix.hpp"

// Application of a longest common substring problem (DNA Sequencing)
void solve(std::string str1, std::string str2) {

  std::string newStr = str1 + '#' + str2 + '$';
  std::vector<std::string> res(newStr.length(), "");

  suffix_array::SuffixArray<int> suf(newStr);
  suf.build_with_sort();
  suf.build_lcp();

  std::vector<int> sufArr = suf.return_suffix_array();
  std::vector<int> lcpArr = suf.return_lcp_array();

  int l1 = str1.length(), l2 = str2.length();
  int lcs = 0, idx = 0;
  for(int i = 1; i < newStr.length(); i++){
    int p1 = sufArr[i-1], p2 = sufArr[i];
    if (p1 > p2) {
      std::swap(p1,p2);
    }
    if (p1 < l1 && p2 >= l1 && lcpArr[i] <= (l1-p1)) {
      lcs = std::max(lcs,lcpArr[i]);
    }
  }

  if (!lcs) {
    std::cout << "No sequence" << '\n';
  }

  for(int i = 1; i < newStr.length(); i++){
    if (lcpArr[i] == lcs) {
      int p1 = sufArr[i-1], p2 = sufArr[i];
      if (p1 > p2){ 
        std::swap(p1,p2);
      }
      if (p1 < l1 && p2 >= l1 && lcpArr[i] <= (l1-p1)){
        int kk = 0;
        for (int j = sufArr[i]; j < sufArr[i]+lcs; j++) {
          res[idx] += newStr[j];
        }
        idx++;
      }
    }
  }
  
  // Make sure to only output unique strings
  std::cout << res[0] << '\n';
  for(int i = 1; i < idx; i++){
    if(res[i] > res[i-1]) {
      std::cout << res[i] << '\n'; 
    }
  }
}

int main()
{
  std::string s1 = "atgc", s2 = "gctg";
  
  solve(s1, s2);

  return 0;
}
