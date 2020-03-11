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
  std::string input = "mississippi";
//  std::string input = "abcxabcd";


  suffix_array::SuffixArray<int> sa(input);
  sa.build();
  sa.printSuffixArray();

  return 0;
}
