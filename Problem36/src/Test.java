import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Created by lvyang on 12/27/16.
 */
public class Test {
    public static void main(String[] args){
        Map<String,Object> map=new HashMap<>();
        List<String> l=new ArrayList<>();
        l.add("lvyang");
        map.put("1",l);
        List<String> a= (List<String>) map.get("1");
        a.add("John");
        List<String> b= (List<String>) map.get("1");
        System.out.println("flag");
    }
}
