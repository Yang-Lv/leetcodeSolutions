import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Created by lvyang on 12/27/16.
 */
public class Solution {
    public int getFlag(int i,int j){
        return i/3*3+j/3;
    }
    public boolean isValidSudoku(char[][] board){
        Map<String,Object> map=new HashMap<>();
        List<String> list=null;
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    //judge 3*3
                    String k=(i/3*3+j/3)+"";
                    if(!map.containsKey(k)){
                        list=new ArrayList<>();
                        list.add(board[i][j]+"");
                        map.put(k,list);
                    }else{
                        list= (List<String>) map.get(k);
                        if(!list.contains(board[i][j]+"")){
                            list.add(board[i][j]+"");
                        }else{
                            return false;
                        }
                    }
                    //judge row and col
                    if(!map.containsKey("row"+i)){
                        list=new ArrayList<>();
                        list.add(board[i][j]+"");
                        map.put("row"+i,list);
                    }else{
                        list= (List<String>) map.get("row"+i);
                        if(list.contains(board[i][j]+""))
                            return false;
                        else
                            list.add(board[i][j]+"");
                    }
                    if(!map.containsKey("col"+j)){
                        list=new ArrayList<>();
                        list.add(board[i][j]+"");
                        map.put("col"+j,list);
                    }else{
                        list= (List<String>) map.get("col"+j);
                        if(list.contains(board[i][j]+""))
                            return false;
                        else
                            list.add(board[i][j]+"");
                    }
                }
            }
        return true;
    }
    public static void main(String[] args){
        char[][] board={{'.','.','4','.','.','.','6','3','.'},
                        {'.','.','.','.','.','.','.','.','.'},
                        {'5','.','.','.','.','.','.','9','.'},
                        {'.','.','.','5','6','.','.','.','.'},
                        {'.','.','.','.','.','.','.','.','.'},
                        {'4','.','3','.','.','.','.','.','1'},
                        {'.','.','.','7','.','.','.','.','.'},
                        {'.','.','.','5','.','.','.','.','.'},
                        {'.','.','.','.','.','.','.','.','.'}};
        System.out.println(new Solution().isValidSudoku(board));
    }
}
