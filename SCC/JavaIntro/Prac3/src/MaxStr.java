import java.util.ArrayList;

public class MaxStr
{
    public static String findMax(ArrayList<String> list)
    {
        String biggest = list.get(0);
        for (String item : list)
        {
            if (item.length() > biggest.length())
            {
                biggest = item;
            }
        }
        return biggest;
    }
}
