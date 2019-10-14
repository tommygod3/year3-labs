import java.util.Map;
import java.util.HashMap;

public class Prac2
{

    public static Long biggestLongInArray(Long[] array)
    {
        Long biggest = array[0];

        for(Long value : array)
        {
            if(value > biggest)
            {
                biggest = value;
            }
        }

        return biggest;
    }

    public static void main(String[] args)
    {
        // Basic:
        Long[] salariesList = {24000l, 34000l, 40000l, 21000l, 18000l};
        String[] profession = {"Nurse", "Teacher", "Architect", "Bus Driver", "Postman"};

        int underTax = 0;
        for(Long salary : salariesList)
        {
            if(salary < 20000)
            {
                underTax++;
            }
        }
        System.out.println("Under tax salaries: " + underTax);

        Long biggestSalary = Prac2.biggestLongInArray(salariesList);
        for(int i = 0; i < salariesList.length; i++)
        {
            if(salariesList[i] == biggestSalary)
            {
                System.out.println("Highest earner: " + profession[i]);
                System.out.println(profession[i] + "'s salary: " + biggestSalary);
            }
        }





        // Map:
        Map<String, Long> salaries = new HashMap<String, Long>();
        salaries.put("Nurse", 24000l);
        salaries.put("Teacher", 34000l);
        salaries.put("Architect", 40000l);
        salaries.put("Driver", 21000l);
        salaries.put("Postman", 18000l);
        String biggestProfession = "";
        Long biggest = 0l;
        for(Map.Entry mapElement : salaries.entrySet())
        {
            String key = (String)mapElement.getKey();
            Long value = (Long)mapElement.getValue();

            if(value < 20000l)
            {
                System.out.println(key + " under tax range.");
            }
            if(value > biggest)
            {
                biggest = value;
                biggestProfession = key;
            }
        }

        System.out.println("Highest earning profession: " + biggestProfession);
        System.out.println(biggestProfession + "'s salary: " + biggest);

        System.out.println("Nurse salary: " + salaries.get("Nurse"));
    }
}