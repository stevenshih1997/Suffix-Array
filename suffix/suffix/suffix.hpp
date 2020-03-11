#pragma once

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

namespace suffix_array {
  
  template<typename T>
  class SuffixArray {
    public:
      SuffixArray(std::string strIn): N(strIn.size()), sufA(strIn.size()), rank(strIn.size()), tmp(strIn.size()), txt(std::move(strIn)) {};
      void build();    
      void printSuffixArray();
      std::vector<T> returnSuffixArray();

    private:
      T N;
      T k;
      std::vector<T> sufA;
      std::vector<T> rank;
      std::vector<T> tmp;
      std::string txt;
  };

  template<typename T>
  std::vector<T> SuffixArray<T>::returnSuffixArray() { return sufA; }

  template<typename T>
  void SuffixArray<T>::printSuffixArray() {
    for (auto& e : sufA) {
      std::cout << e << ' ';
    }
    std::cout << '\n';
  }

  // Concise O(n(logn)^2) 
  // TODO: Overload sort to be counting/radix sort to reduce runtime to O(nlogn)
  template<typename T>
  void SuffixArray<T>::build() {
     auto cmp = [this](T i, T j) -> bool {
      if (rank[i] != rank[j]) {
        return rank[i] < rank[j];
      }
      i += k;
      j += k;
      return (i < N && j < N) ? (rank[i] < rank[j]) : i > j;
    };

    for (T i = 0; i < N; ++i) {
      sufA[i] = i;
      rank[i] = txt[i];
    }

    for (k = 1; tmp[N-1] != N - 1; k << 1) {
      std::sort(sufA.begin(), sufA.end(), cmp); // Costs O(nlogn)

      for (T i = 0; i < N - 1; ++i) {
        tmp[i+1] = tmp[i] + cmp(sufA[i], sufA[i+1]);
      }

      for (T i = 0; i < N; ++i) {
        rank[sufA[i]] = tmp[i];
      }
//      if (tmp[N - 1] == N - 1) break; //break vs for loop?
    }

  }
}

