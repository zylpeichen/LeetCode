/*给你一个数组，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。

示例 1:
输入: nums = [1,2,3,4,5,6,7], k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右轮转 1 步: [7,1,2,3,4,5,6]
向右轮转 2 步: [6,7,1,2,3,4,5]
向右轮转 3 步: [5,6,7,1,2,3,4]

示例2:
输入：nums = [-1,-100,3,99], k = 2
输出：[3,99,-1,-100]
解释: 
向右轮转 1 步: [99,-1,-100,3]
向右轮转 2 步: [3,99,-1,-100]

提示：
    1 <= nums.length <= 105
    -231 <= nums[i] <= 231 - 1
    0 <= k <= 105

进阶：
    尽可能想出更多的解决方案，至少有 三种 不同的方法可以解决这个问题。
    你可以使用空间复杂度为?O(1) 的?原地?算法解决这个问题吗？
*/

// 方法一：使用额外的数组
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();  
        vector<int> ans(n);  //定义一个新的数组，将移后的数组储存在这里
        for (int i = 0; i < n; i++) {
            ans [(i + k) % n] = nums[i];   //将移动后的数组储存在 ans 中
        }
        nums.assign(ans.begin(),ans.end());   //将 ans 里的所有元素复制到 nums 里面
    }
};

// 方法二：使用反转数组
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();    //因为害怕出现 k > num.size() 的情况，所以要取余
        reverse(nums.begin(),nums.end());   //先把所有的反转 e.g:  1,2,3,4,5  k = 2  反转后：5,4,3,2,1
        reverse(nums.begin(),nums.begin() + k);     //将开始的反转   4,5,3,2,1
        reverse(nums.begin() + k,nums.end());       //将最后的反转   4,5,1,2,3
    }
};
