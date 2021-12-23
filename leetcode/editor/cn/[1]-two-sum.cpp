//给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target 的那 两个 整数，并返回它们的数组下标。 
//
// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。 
//
// 你可以按任意顺序返回答案。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [2,7,11,15], target = 9
//输出：[0,1]
//解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
// 
//
// 示例 2： 
//
// 
//输入：nums = [3,2,4], target = 6
//输出：[1,2]
// 
//
// 示例 3： 
//
// 
//输入：nums = [3,3], target = 6
//输出：[0,1]
// 
//
// 
//
// 提示： 
//
// 
// 2 <= nums.length <= 10⁴ 
// -10⁹ <= nums[i] <= 10⁹ 
// -10⁹ <= target <= 10⁹ 
// 只会存在一个有效答案 
// 
//
// 进阶：你可以想出一个时间复杂度小于 O(n²) 的算法吗？ 
// Related Topics 数组 哈希表 👍 12928 👎 0


#include "include/mylib.h"
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> has;//
        for(int i=0; i < nums.size(); i++){
            cout << has[target - nums[i]] << endl;
            if (has[target - nums[i]] > 0){ // has[target - nums[i]] has[原数字]的位置 在0 后
                return {has[target - nums[i]] - 1, i}; // i 是当前的位置， target-nums[i] 是原数字，has[原数字] 就是原位置 + 1 所以 -1
            }
            else {
                has[nums[i]] = i + 1; // has[num] = pos
            }
        }
        return {0, 1};

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution solution;
    //solution.XXX
    vector<int> nums = {2, 7, 11, 15};
    vector<int> res;
    int target = 18;
    res = solution.twoSum(nums, target);
    for (int ri : res){
        cout << ri << endl;
    }
    return 0;
}