/*
	Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

	Example:

	Input: nums = [3,5,2,1,6,4]
	Output: One possible answer is [3,5,1,6,2,4]
	
	https://leetcode.com/problems/wiggle-sort/description/
	
	*/


class Solution {
public:
    
    void printnums(const vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
    
    void wiggleSort(vector<int>& nums) {
        if (nums.size() < 2) {
            return;
        }
        
        bool greater = true;
        
        for (int i = 1;  i < nums.size(); i++) {
            if (greater) {
                if (nums[i] < nums[i-1]) {
                    swap(nums[i], nums[i-1]);
                }
            }
            else {
                if (nums[i] > nums[i-1]) {
                    swap(nums[i], nums[i-1]);
                }
            }
            greater = !greater;
        }
    }
};