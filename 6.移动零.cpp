/*
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
请注意 ，必须在不复制数组的情况下原地对数组进行操作。

示例 1:
输入: nums = [0,1,0,3,12]
输出: [1,3,12,0,0]

示例 2:
输入: nums = [0]
输出: [0]

 

提示:
    1 <= nums.length <= 104
    -231 <= nums[i] <= 231 - 1

进阶：你能尽量减少完成的操作次数吗？
*/

// 方法一：创建新数组，进行覆盖。这个方法占用空间大，且题目说了不能用新数组，应在原数组上进行操作
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();    
        int m = 0;
        vector<int> ans(n);     //定义新数组
        for (int i = 0, j = 0; i < n; i++) {    // 将不是 0 的数复制到新数组 ans 中
            if (nums[i] != 0) {
                ans[j] = nums[i];
                j++;
                m++;        //注意这里的 m 其实是加过 1 的，但因为 for 循环退出了，所以 m 没有执行
            }
        }
        for (; m < n; m++) {    //将 0 加到 ans 数组的后面
            ans[m] = 0;     //这里的 m 不需要 + 1
        }
        nums.assign(ans.begin(),ans.end());     //将数组 ans 的数复制到 nums中
    }
};

// 方法二：在原数组上进行操作，进行覆盖，方法和第一种很类似
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int m = 0;
      for (int i = 0,j = 0; i < nums.size(); i++) {
          if (nums[i] != 0) {
              nums[j] = nums[i];
              j++;
              m++;
          }
      }
      for (; m < nums.size(); m++) {
          nums[m] = 0;
      }
    }
};

// 方法三：交换数组，这个方法也是本题的官方题解，是想让我掌握的正确思路
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0,right = 0;
        while (right < nums.size()) {
            if (nums[right] != 0) {
                swap(nums[left],nums[right]);
                left++;
            }
            right++;
        }
    }
};