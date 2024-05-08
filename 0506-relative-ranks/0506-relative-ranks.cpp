class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
          unordered_map<int, int> umap;
        unordered_map<int, string> umapS;
        vector<string> FinalScore(0);
        for (int i = 0; i < score.size(); i++) {
            umap[i] = score[i];
        }
        sort(score.begin(), score.end());
        
        for (int i = score.size() - 1; i >= 0; i--) {
            if (i == score.size() - 1) {
                umapS[score[i]] = "Gold Medal";
            }
            else if (i == score.size() - 2) {
                umapS[score[i]] = "Silver Medal";
            }
            else if (i == score.size() - 3) {
                umapS[score[i]] = "Bronze Medal";
            }
            else {
                umapS[score[i]] = to_string(score.size() - i);
            }
        }
        for (int i = 0; i < score.size(); i++) {
            FinalScore.push_back(umapS[umap[i]]);
        }
        return FinalScore;
    }
};