/**
 * A simple program that prints a greeting message
 * File: myID.java
 */

import java.io.*;

public class myID
{
    public String name;
    public String email;
    public String module;

    public myID()
    {
        this.setDetails();
    }

    public void setDetails()
    {
        this.name = myID.getInputString("Please enter your name: ");
        this.email = myID.getInputString("Please enter your email: ");
        this.module = myID.getInputString("Please enter your module: ");
    }

    private static String getInputString(String prompt)
    {
        String result = "";
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        try
        {
            System.out.println(prompt);
            result = br.readLine();
        } 
        catch(IOException e)
        {
            System.out.println("IO Exception ocurred " + e);
        }
        return result;
    }

    public static void main(String[] args)
    {
        myID id = new myID();

        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        int result;

        while(true)
        {
            System.out.println("\nSelect from the following options:\n[1] print Name\n[2] print Email\n[3] print Module\n[4] quit program");
            try
            {
                result = Integer.parseInt(br.readLine());
                switch(result)
                {
                    case 1:
                        System.out.println(id.name);
                        break;
                    case 2:
                        System.out.println(id.email);
                        break;
                    case 3:
                        System.out.println(id.module);
                        break;
                    case 4:
                        break;
                }
                if(result == 4)
                {
                    break;
                }
            }
            catch(IOException e)
            {
                System.out.println("IO Exception ocurred " + e);
            }
        }   
    }
}

