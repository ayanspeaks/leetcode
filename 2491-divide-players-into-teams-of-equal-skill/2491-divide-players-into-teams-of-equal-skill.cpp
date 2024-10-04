class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());

        long long chem = 0;
        long long isum = skill[0] + skill[skill.size() - 1];
        int left = 0;
        int right = skill.size() - 1;

        while (left < right) {
            if (skill[left] + skill[right] == isum) {
                chem += (skill[left] * skill[right]);
                left++;
                right--;
            } else {
                return -1;
            }
        }
        return chem;
    }
};