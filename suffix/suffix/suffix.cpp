#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "suffix.hpp"

int main()
{
  std::string input = "mississippi$";
//  std::string input = "abcxabcd";
//  std::string input = "ABABBAABB$";
//  std::string input = "aaaaaaaaaaaaaaaaaaaa";


  suffix_array::SuffixArray<int> sa(input);
  sa.build_with_radix_sort();
  sa.print_suffix_array();

  return 0;
}
