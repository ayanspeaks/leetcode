class Solution {
public:
    vector<int> addNegabinary(vector<int>& a1, vector<int>& a2) {
  vector<int> res;
  int bit = 0, carry = 0, sz = max(a1.size(), a2.size());
  for (auto bit = 0; bit < sz || carry != 0; ++bit) {
    auto b1 = bit < a1.size() ? a1[a1.size() - bit - 1] : 0;
    auto b2 = bit < a2.size() ? a2[a2.size() - bit - 1] : 0;
    auto sum = b1 + b2 + carry;
    res.push_back(abs(sum) % 2); 
    carry = sum < 0 ? 1 : sum > 1 ? -1 : 0;
  }
  while (res.size() > 1 && res.back() == 0) res.pop_back();
  reverse(begin(res), end(res));
  return res;
}
};