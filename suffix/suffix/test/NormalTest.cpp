#include <suffix.hpp>
#include <string.h>
#include <sstream>
#include <fstream>
#include <vector>
#include <cassert>

using namespace suffix_array;
using namespace std;

void test_large_input() {
  stringstream input;
  ifstream stream("BigTest.txt");

  if(stream.is_open())
  {
    while(stream.peek() != EOF)
    {
      input << (char) stream.get();
    }
    stream.close();
  };
  SuffixArray<int> sa(input.str());
  sa.build_with_sort();
  assert(1000002 == sa.return_suffix_array().size());
}

int main() {
  test_large_input();
}
