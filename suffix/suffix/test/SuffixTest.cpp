#include <suffix.hpp>
#include <string.h>
#include <vector>

using namespace suffix_array;
using namespace std;

void test1() {
  string input = "mississippi";
  SuffixArray<int> sa(input);
  sa.build();
  vector<int> expected = {10, 7, 4, 1, 0, 9, 8, 6, 3, 5, 2};
  assert(expected == sa.returnSuffixArray());
}

void test2() {
  string input = "abcxabcd";
  SuffixArray<int> sa(input);
  sa.build();
  vector<int> expected = {4, 0, 5, 1, 6, 2, 7, 3};
  assert(expected == sa.returnSuffixArray());
}

int main() {
  test1();
  test2();
}
