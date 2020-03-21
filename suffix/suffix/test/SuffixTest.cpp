#include <suffix.hpp>
#include <string.h>
#include <vector>
#include <cassert>

using namespace suffix_array;
using namespace std;

// Suffix array construction with default std O(nlogn) sort
void test_normal_string() {
  string input = "mississippi$";
  SuffixArray<int> sa(input);
  sa.build_with_sort();
  vector<int> expected = {11, 10, 7, 4, 1, 0, 9, 8, 6, 3, 5, 2};
  assert(expected == sa.return_suffix_array());
}

void test_simple_string() {
  string input = "abcxabcd$";
  SuffixArray<int> sa(input);
  sa.build_with_sort();
  vector<int> expected = {8, 4, 0, 5, 1, 6, 2, 7, 3};
  assert(expected == sa.return_suffix_array());
}

void test_repeated_string() {
  string input = "aaaaaaaaaaaaaaaaaaaa$";
  SuffixArray<int> sa(input);
  sa.build_with_sort();
  vector<int> expected = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  assert(expected == sa.return_suffix_array());
}

void test_complex_string_with_special_char() {
  string input = "ABABBAABB$";
  SuffixArray<int> sa(input);
  sa.build_with_sort();
  vector<int> expected = {9, 5, 0, 6, 2, 8, 4, 1, 7, 3};
  assert(expected == sa.return_suffix_array());
}

// Suffix array construction with radix O(n) sort
void test_radix_normal_string() {
  string input = "mississippi$";
  SuffixArray<int> sa(input);
  sa.build_with_radix_sort();
  vector<int> expected = {11, 10, 7, 4, 1, 0, 9, 8, 6, 3, 5, 2};
  assert(expected == sa.return_suffix_array());
}

void test_radix_simple_string() {
  string input = "abcxabcd$";
  SuffixArray<int> sa(input);
  sa.build_with_radix_sort();
  vector<int> expected = {8, 4, 0, 5, 1, 6, 2, 7, 3};
  assert(expected == sa.return_suffix_array());
}

void test_radix_repeated_string() {
  string input = "aaaaaaaaaaaaaaaaaaaa$";
  SuffixArray<int> sa(input);
  sa.build_with_radix_sort();
  vector<int> expected = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  assert(expected == sa.return_suffix_array());
}

void test_radix_complex_string_with_special_char() {
  string input = "ABABBAABB$";
  SuffixArray<int> sa(input);
  sa.build_with_radix_sort();
  vector<int> expected = {9, 5, 0, 6, 2, 8, 4, 1, 7, 3};
  assert(expected == sa.return_suffix_array());
}

int main() {
  test_normal_string();
  test_simple_string();
  test_repeated_string();
  test_complex_string_with_special_char();
  test_radix_normal_string();
  test_radix_simple_string();
  test_radix_repeated_string();
  test_radix_complex_string_with_special_char();
}
