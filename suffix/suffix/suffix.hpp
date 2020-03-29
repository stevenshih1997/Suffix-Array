#pragma once

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>

namespace suffix_array {
  
  template<typename T>
  class SuffixArray {
    public:
      SuffixArray(std::string strIn): N(strIn.size()), sufA(strIn.size()), rank(strIn.size()), cLookup(strIn.size()), lcpA(strIn.size()), tmpSuf(strIn.size()), tmpRank(strIn.size()), txt(std::move(strIn)) {};
      void build_with_sort();    
      void build_with_radix_sort();    
      void print_suffix_array();
      void print_rank_array();
      void build_lcp();
      std::vector<T> return_suffix_array();
      std::vector<T> return_lcp_array();

    private:
      T N;
      T k;
      T c[1000005];
      std::vector<T> sufA;
      std::vector<T> rank;
      std::vector<T> cLookup;
      std::vector<T> lcpA;
      std::vector<T> tmpSuf;
      std::vector<T> tmpRank;
      std::string txt;
      void counting_sort(T k);
  };

  template<typename T>
  std::vector<T> SuffixArray<T>::return_suffix_array() { return sufA; }

  template<typename T>
  std::vector<T> SuffixArray<T>::return_lcp_array() { return lcpA; }

  template<typename T>
  void SuffixArray<T>::print_suffix_array() { for (auto& e : sufA) std::cout << e << ' '; std::cout << '\n'; }

  template<typename T>
  void SuffixArray<T>::print_rank_array() { for (auto& e : rank) std::cout << e << ' '; std::cout << '\n'; }
  
  template<typename T>
  void SuffixArray<T>::build_lcp() {
    int l=0;
    std::vector<T> tempLcp(N, 0);
    cLookup[sufA[0]] = -1;
    for(int i = 1; i < N; i++) cLookup[sufA[i]] = sufA[i-1];

    for(int i=0; i<N; i++) {
      if(cLookup[i]==-1) {
        tempLcp[i] = 0;
      } else {
        while (txt[i+l]==txt[cLookup[i]+l]) l++;
        tempLcp[i] = l;
        l = std::max(l-1, 0);
      }
    }
    for (int i = 0; i < N; i++) lcpA[i] = tempLcp[sufA[i]];
  }

  // Concise O(n(logn)^2) 
  template<typename T>
  void SuffixArray<T>::build_with_sort() {
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

    for (k = 1; k < N; k <<= 1) {
      std::sort(sufA.begin(), sufA.end(), cmp); // Costs O(nlogn)

      for (T i = 0; i < N - 1; ++i) {
        tmpSuf[i+1] = tmpSuf[i] + cmp(sufA[i], sufA[i+1]);
      }

      for (T i = 0; i < N; ++i) {
        rank[sufA[i]] = tmpSuf[i];
      }
      if (tmpSuf[N - 1] == N - 1) break;
    }

  }

  template<typename T>
  void SuffixArray<T>::counting_sort(T k) {
    int i, sum, maxi = std::max(1000005, N);
    memset(c, 0, sizeof(c)); // clear frequency table

    for (i = 0; i < N; i++){ // count the freq of each integer rank
      c[i + k < N ? rank[i + k] : 0]++;
    }
    for (i = sum = 0; i < maxi; i++) {
      int t = c[i]; c[i] = sum; sum += t; 
    }
    for (i = 0; i < N; i++){ // shuffle the suffix array if needed
      tmpSuf[c[sufA[i]+k < N ? rank[sufA[i]+k] : 0]++] = sufA[i];
    }
    for (i = 0; i < N; i++){
      sufA[i] = tmpSuf[i];
    }
  }
  
  // O(nlogn) using radix sort
  template<typename T>
  void SuffixArray<T>::build_with_radix_sort() {
    int i, r;
    for (i = 0; i < N; ++i) rank[i] = txt[i];
    for (i = 0; i < N; ++i) sufA[i] = i;

    for (k = 1; k < N; k <<= 1) { 
      SuffixArray<T>::counting_sort(k);
      SuffixArray<T>::counting_sort(0);

      tmpRank[sufA[0]] = r = 0;

      for (i = 1; i < N; i++){
        // if same pair => same rank r; otherwise,increase rank
        tmpRank[sufA[i]] = (rank[sufA[i]] == rank[sufA[i-1]] && rank[sufA[i]+k] == rank[sufA[i-1]+k]) ? r : ++r;           
      }

      for (i = 0; i < N; i++){
        rank[i] = tmpRank[i];
      }
      if (rank[sufA[N-1]] == N-1) break;
    } 
  }
}

