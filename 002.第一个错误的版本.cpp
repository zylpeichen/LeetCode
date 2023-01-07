/*你是产品经理，目前正在带领一个团队开发新的产品。
不幸的是，你的产品的最新版本没有通过质量检测。
由于每个版本都是基于之前的版本开发的，所以错误的版本之后的所有版本都是错的。

假设你有 n 个版本 [1, 2, ..., n]，你想找出导致之后所有版本出错的第一个错误的版本。
你可以通过调用 bool isBadVersion(version) 接口来判断版本号 version 是否在单元测试中出错。
实现一个函数来查找第一个错误的版本。你应该尽量减少对调用 API 的次数。

示例 1：
输入：n = 5, bad = 4
输出：4
解释：
调用 isBadVersion(3) -> false 
调用 isBadVersion(5) -> true 
调用 isBadVersion(4) -> true
所以，4 是第一个错误的版本。

示例 2：
输入：n = 1, bad = 1
输出：1
*/

//考点：二分查找

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;  //定义左右边界
        while (left < right ) {   //条件为左边界必须小于右边界
            int middle = left + ((right - left) / 2);  //定义中间值
            if (isBadVersion(middle)){  //当中间值是错误版本，则将右边界换位中间值
                right = middle;
            } else {                //当中间值是不是错误版本，则将左边界换位中间值的后一个
                left = middle + 1;
            }
        }
        return left;      //找到后返回左边界的值
    }
};
