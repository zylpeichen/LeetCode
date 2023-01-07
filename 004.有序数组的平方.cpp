/*
给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

示例 1：
输入：nums = [-4,-1,0,3,10]
输出：[0,1,9,16,100]
解释：平方后，数组变为 [16,1,0,9,100]
排序后，数组变为 [0,1,9,16,100]

示例 2：
输入：nums = [-7,-3,2,3,11]
输出：[4,9,9,49,121]

提示：
    1 <= nums.length <= 104
    -104 <= nums[i] <= 104
    nums 已按 非递减顺序 排序

进阶：
    请你设计时间复杂度为 O(n) 的算法解决本问题
*/

// 方法一:暴力排序法
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for (int i = 0;i < nums.size(); i++) {
            nums[i] = nums[i] * nums[i];
        }
        sort(nums.begin(),nums.end());  // 快速排序
        return nums;
    }
};

// 方法二:双指针法
// 思路：平方之后最大的不是在最前就是在最后，所以我们定义 i 和 j，
//一个代表最前，一个代表最后，然后进行比较，大的赋给新建的数组 ans 
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        for (int i = 0,j = nums.size() - 1,pos = nums.size() - 1;i <= j;) {
            if (nums[i] * nums[i] > nums[j] * nums[j]) {
                ans[pos] = nums[i] * nums[i],i++;
            } else {
                ans[pos] = nums[j] * nums[j],j--;
            }
            pos--;
        }
        return ans;
    }
};
