class TopVotedCandidate {
public:
  vector<int> *tim, *ans;  
  TopVotedCandidate(vector<int>& persons, vector<int>& times) {
    unordered_map<int, int> table;
    tim = &times, ans = &persons;
    int maxi = ++table[persons[0]], tmp;    
    for(int i = 1; i != times.size(); i++)
      if( (tmp = ++table[persons[i]]) >= maxi) maxi = tmp;
      else persons[i] = persons[i-1];    
  }    
  int q(int t) {
    return ans->operator[](upper_bound(tim->begin(), tim->end(), t) - tim->begin() - 1);
  }
};


/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */