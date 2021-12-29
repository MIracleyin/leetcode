//给定由若干 0 和 1 组成的矩阵 matrix，从中选出任意数量的列并翻转其上的 每个 单元格。翻转后，单元格的值从 0 变成 1，或者从 1 变为 0 
//。 
//
// 回经过一些翻转后，行与行之间所有值都相等的最大行数。 
//
// 
//
// 
// 
//
// 示例 1： 
//
// 
//输入：[[0,1],[1,1]]
//输出：1
//解释：不进行翻转，有 1 行所有值都相等。
// 
//
// 示例 2： 
//
// 
//输入：[[0,1],[1,0]]
//输出：2
//解释：翻转第一列的值之后，这两行都由相等的值组成。
// 
//
// 示例 3： 
//
// 
//输入：[[0,0,0],[0,0,1],[1,1,0]]
//输出：2
//解释：翻转前两列的值之后，后两行由相等的值组成。 
//
// 
//
// 提示： 
//
// 
// 1 <= matrix.length <= 300 
// 1 <= matrix[i].length <= 300 
// 所有 matrix[i].length 都相等 
// matrix[i][j] 为 0 或 1 
// 
// Related Topics 数组 哈希表 矩阵 👍 42 👎 0


#include "include/mylib.h"
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        map<string, int> has;
        for (int i=0; i < matrix.size(); i++){
            string tmp;
            for (int j=0; j < matrix[i].size(); j++){ // 遍历一行，保存成字符串
                tmp += to_string(matrix[i][j]);
            }
            has[tmp]++; // 把所有的行保存下来
        }


        //map<string, int>::iterator iter;
        int res = 0;
        for (auto iter=has.begin(); iter!=has.end(); iter++) {// 遍历所有行
            string rev;
            string tmp = iter->first; // has first 指向 str
            for (int i=0; i<tmp.size(); i++){
                if(tmp[i]=='1') {
                    rev += "0"; // 记录 tmp 的补码
                }
                else
                    rev += '1';
            }
            res=max(res, has[tmp] + has[rev]); // 当前行相同的和相补的，如果比原来的res大 那么更新res
        }
        return res;
    }

};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution solution;
    //solution.XXX
    vector<vector<int>> m = {{0,0,0},{0,0,1},{1,1,0}};
    int res = solution.maxEqualRowsAfterFlips(m);
    cout << res;
    //print2Dvector(m);
    return 0;
}