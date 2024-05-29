class Solution {

 public:
  int numSteps(string s) {
    // bstring to int
    if (s == "1") return 0;

    string new_s = "";

    if (s.back() == '0') {
      s.pop_back();
      return 1+numSteps(s);
    } else {
      // carry (the meat)
      while (!s.empty() && s.back() == '1') {
        s.pop_back();
        new_s.insert(0,1,'0');

      }
      
      new_s.insert(0,1,'1');
      if (!s.empty()) {
        s.pop_back();
        new_s = s+new_s;
      }

      return 1+numSteps(new_s);
    }
  return 0;
  }
};