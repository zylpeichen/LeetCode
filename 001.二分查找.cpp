/*给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，
写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。

示例 1:
输入: nums = [-1,0,3,5,9,12], target = 9
输出: 4
解释: 9 出现在 nums 中并且下标为 4

示例 2:
输入: nums = [-1,0,3,5,9,12], target = 2
输出: -1
解释: 2 不存在 nums 中因此返回 -1

提示：

1.你可以假设 nums 中的所有元素是不重复的。
2.n 将在 [1, 10000]之间。
3.nums 的每个元素都将在 [-9999, 9999]之间。
*/

//考点：二分查找

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;  //定义左边
        int right = nums.size() - 1;  //定义右边
        while (left <= right){   //只有左边小于等于右边的时候才进行循环
            int middle = left + ((right - left) / 2);  //找到中间值
            if (nums[middle] > target){  //如果中间值大于查找值
                right = middle - 1;   //让右边到中间值得左侧
            } else if (nums[middle] < target){   //如果中间值小于查找值
                right = middle - 1;   //让左边到中间值的右侧
            }else {
                return middle;   //如果查找到则直接返回
            }
        }
        return -1;    //查找不到则返回-1
    }
};
