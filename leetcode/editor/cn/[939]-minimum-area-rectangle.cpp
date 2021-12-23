//给定在 xy 平面上的一组点，确定由这些点组成的矩形的最小面积，其中矩形的边平行于 x 轴和 y 轴。 
//
// 如果没有任何矩形，就返回 0。 
//
// 
//
// 示例 1： 
//
// 输入：[[1,1],[1,3],[3,1],[3,3],[2,2]]
//输出：4
// 
//
// 示例 2： 
//
// 输入：[[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
//输出：2
// 
//
// 
//
// 提示： 
//
// 
// 1 <= points.length <= 500 
// 0 <= points[i][0] <= 40000 
// 0 <= points[i][1] <= 40000 
// 所有的点都是不同的。 
// 
// Related Topics 几何 数组 哈希表 数学 排序 👍 104 👎 0


#include "include/mylib.h"
using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_map<int, int>> p2p;
        int res=INT_MAX, n = points.size(); // 初始化 res 正无穷
        for (int i = 0; i < n; i++){
            p2p[points[i][0]][points[i][1]]=1; // 不太理解，
        }

        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                if ( points[i][0] == points[j][0] || points[i][1] == points[j][1] ) continue; // 跳过对角线是平行的情况
                // A[x0][y0] B[x1][y1] 确定对角线  那么 判断 是否存在 C[x0][y1] 与 D[x1][y0] 同时存在
                if (p2p[points[i][0]][points[j][1]]==1 && p2p[points[j][0]][points[i][1]]){ // 如果存在点
                    int area = abs((points[i][0] - points[j][0]) * (points[i][1] - points[j][1])); // 计算 area
                    res = res < area ? res:area; // 如果area 比 之前的 res 还要小，那么res 为新的 area
                }
            }
        }
        if (res == INT_MAX) return 0; // 如果 res 一直为 max 则无矩形存在
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution solution;
    //solution.XXX
    vector<vector<int>> points = {{1,1}, {1,3}, {3,1}, {3,3}, {2,2}};
    int res = -1;
    res = solution.minAreaRect(points);

    for (vector vi : points){
        for (int vii : vi){
            //cout << vii << "\t";
        }
        //cout << endl;
    }
    cout << res << endl;
    return 0;
}