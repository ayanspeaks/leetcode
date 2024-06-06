class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        multiset<int>ms;
        for (auto &x : hand) {
            ms.insert(x);
        }
        while (ms.size()) {
            int k = groupSize;
            int i = *(ms.begin());
            ms.erase(ms.find(i));
            --k;
            while (k--) {
                i++;
                if (ms.find(i) == ms.end()) {
                    return false;
                } else {
                    ms.erase(ms.find(i));
                }
            }
        }
        return true;
    }
};