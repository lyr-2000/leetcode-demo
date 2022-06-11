/*
 * @lc app=leetcode.cn id=79 lang=java
 *
 * [79] 单词搜索
 *
 * https://leetcode-cn.com/problems/word-search/description/
 *
 * algorithms
 * Medium (39.21%)
 * Likes:    225
 * Dislikes: 0
 * Total Accepted:    22.6K
 * Total Submissions: 57.6K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 给定一个二维网格和一个单词，找出该单词是否存在于网格中。
 * 
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * 
 * 示例:
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * 给定 word = "ABCCED", 返回 true.
 * 给定 word = "SEE", 返回 true.
 * 给定 word = "ABCB", 返回 false.
 * 
 */

// @lc code=start
class Solution {
    boolean[][] visiting = null;
    String str = null;
    int[][] direct = new int[][]{
        {-1,0},
        {0,-1},
        {0,1},
        {1,0}
    };
    char[][] board = null;

    public boolean exist(char[][] board, String str) {
        if(board== null) return false;
        int size = board.length*board[0].length;
        if(size<str.length()) return false;

        this.str = str;
        this.board = board;
        visiting = new boolean[board.length][board[0].length];
        for(int i=0;i<board.length;++i)
        {
            for(int j=0;j<board[0].length;++j)
            {
                boolean b = dfs(i,j,0);
                if(b) return true;
            }
        }
        return false;
    }

    private boolean dfs(int i,int j,int pos)
    {
        boolean b = str.charAt(pos)==board[i][j];
        if(pos==str.length()-1)
        {
            return b;
        }

        if(!b) return false;
        if(pos>=str.length()) return false;
        visiting[i][j] = true;
        for(int[] dir:direct)
        {
            int x = i+dir[0];
            int y = j+dir[1];
            if(unInArea(x, y)||visiting[x][y]) continue;
            b = dfs(x,y,pos+1);
            if(b) return true;
        }
        visiting[i][j] = false;

        return false;




    }

    private boolean unInArea(int i,int j)
    {
        if(i<0||i>=this.board.length) return true;
        if(j<0||j>=this.board[0].length) return true;
        return false;
    }


}
// @lc code=end

