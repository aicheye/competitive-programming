/*
 * @lc app=leetcode id=1352 lang=cpp
 *
 * [1352] Product of the Last K Numbers
 */

// @lc code=start

#include <vector>
using namespace std;

class ProductOfNumbers {
public:
  vector<int> psa;
  int zero;

  ProductOfNumbers() {
    zero = -1;
    psa = vector<int>();
    psa.push_back(1);
  }

  void add(int num) {
    if (num == 0) {
      zero = psa.size() - 1;
      psa.push_back(1);
      return;
    }
    psa.push_back(psa.back() * num);
  }

  int getProduct(int k) {
    if (zero >= ((int)psa.size()) - 1 - k) {
      return 0;
    }
    return psa.back() / psa[psa.size() - 1 - k];
  }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
// @lc code=end
