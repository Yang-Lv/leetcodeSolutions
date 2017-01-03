import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Created by lvyang on 1/3/17.
 */
public class Solution {
    private void update_dict(char c, Map<String, Object> dict, String key) {
        List<Character> list = null;
        if (!dict.containsKey(key)) {
            list = new ArrayList<>();
            list.add(c);
            dict.put(key, list);
        } else {
            list = (List<Character>) dict.get(key);
            if (list.contains(c)) {
                System.exit(-1);
            } else {
                list.add(c);
            }
        }
    }

    private void backTrack_dict(char c,Map<String,Object> dict,String key){
        List<Character> list= (List<Character>) dict.get(key);
        list.remove(new Character(c));
    }

    private void init(char[][] board, Map<String, Object> dict, List<String> cands) {
        List<Character> list = null;
        for (int i = 0; i < board.length; i++)
            for (int j = 0; j < board[i].length; j++) {
                if (board[i][j] != '.') {
                    int id = i / 3 * 3 + j / 3;
                    //3*3 block
                    update_dict(board[i][j], dict, id + "");
                    //row
                    update_dict(board[i][j], dict, "row" + i);
                    //col
                    update_dict(board[i][j], dict, "col" + j);
                } else {
                    cands.add(i + "\t" + j);
                }
            }
    }

    private boolean isValid(char c, int i, int j, Map<String, Object> dict) {
        List<Character> list = null;
        //verify 3*3 block
        int id = i / 3 * 3 + j / 3;
        if (dict.containsKey(id + "")) {
            list = (List<Character>) dict.get(id + "");
            if (list.contains(c)) return false;
        }
        //verify row
        if (dict.containsKey("row" + i)) {
            list = (List<Character>) dict.get("row" + i);
            if (list.contains(c)) return false;
        }
        //verify col
        if (dict.containsKey("col" + j)) {
            list = (List<Character>) dict.get("col" + j);
            if (list.contains(c)) return false;
        }
        return true;
    }

    private boolean solve(char[][] board, Map<String, Object> dict, List<String> cands, int k) {
        if (k == cands.size()) {
            return true;
        }
        String[] t = cands.get(k).split("\\t");
        int i = t[0].charAt(0) - '0';
        int j = t[1].charAt(0) - '0';
        boolean flag=false;
        for (char c = '1'; c <= '9'; c++) {
            board[i][j] = c;
            if (isValid(c, i, j, dict)) {
                //update dict
                update_dict(c,dict,(i/3*3+j/3)+"");
                update_dict(c,dict,"row"+i);
                update_dict(c,dict,"col"+j);
                flag=solve(board,dict,cands,k+1);
                if(flag) return true;
                else{
                    //back trace
                    backTrack_dict(c,dict,(i/3*3+j/3)+"");
                    backTrack_dict(c,dict,"row"+i);
                    backTrack_dict(c,dict,"col"+j);
                }
            }else{
                board[i][j]='.';
            }
        }
        return false;
    }

    public void solveSudoku(char[][] board) {
        if (board == null || board.length == 0) {
            return;
        }
        //对borad数组进行预处理，构建初始Map
        Map<String, Object> dict = new HashMap<>();
        List<String> cands = new ArrayList<>();
        init(board, dict, cands);
        solve(board, dict, cands, 0);
    }
    public static void main(String[] args){
        char[][] board={{'5','3','.','.','7','.','.','.','.'},
                        {'6','.','.','1','9','5','.','.','.'},
                        {'.','9','8','.','.','.','.','6','.'},
                        {'8','.','.','.','6','.','.','.','3'},
                        {'4','.','.','8','.','3','.','.','1'},
                        {'7','.','.','.','2','.','.','.','6'},
                        {'.','6','.','.','.','.','2','8','.'},
                        {'.','.','.','4','1','9','.','.','5'},
                        {'.','.','.','.','8','.','.','7','9'}};
        new Solution().solveSudoku(board);
        for (char[] s:board) {
            for (char c:s) {
                System.out.print(c+",");
            }
            System.out.println("\n");
        }
    }
}
