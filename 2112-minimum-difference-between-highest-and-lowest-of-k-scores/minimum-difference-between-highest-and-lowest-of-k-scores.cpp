class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int min=INT_MAX;
        for(int i=0; i<nums.size()-k+1; i++){
            int lowest=nums[i];
            int highest=nums[i+k-1];
            int diff=highest-lowest;
            min=std::min(min,diff);
        }
        return min;
    }
};