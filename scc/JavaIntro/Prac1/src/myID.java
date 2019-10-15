/**
 * A simple program that prints a greeting message
 * File: myID.java
 */

import java.io.*;
import java.util.List;
import java.util.NoSuchElementException;
import java.util.ArrayList;
import java.util.Scanner;

public class myID
{
    public String name;
    public String email;
    public String module;
    public Scanner sUser;

    public myID(Scanner scanner)
    {
        this.sUser = scanner;
        this.setDetails();
    }

    public void setDetails()
    {
        this.name = this.getInputString("Please enter your name: ");
        this.email = this.getInputString("Please enter your email: ");
        this.module = this.getInputString("Please enter your module: ");
    }

    private String getInputString(String prompt)
    {
        String result = "";

        try
        {
            System.out.println(prompt);
            result = this.sUser.nextLine();
        } 
        catch(NoSuchElementException e)
        {
            System.out.println("IO Exception ocurred " + e);
        }

        return result;
    }

    public static List<String> getLines(int number)
    {
        List<String> lines = new ArrayList<String>();
        
        try
        {
            Scanner sfile = new Scanner(new File("scc/JavaIntro/module.txt"));  
            for(int i = 0; i < number; i++)
            {
                if(sfile.hasNext())
                {
                    lines.add(sfile.nextLine());
                }
            }
            sfile.close();
        }
        catch(Exception e)
        {
            System.out.println(e);
        }
        
        return lines;
    }

    public static void main(String[] args)
    {
        Scanner sUser = new Scanner(System.in);
        myID id = new myID(sUser);
        int result;

        while(true)
        {
            System.out.println("\nSelect from the following options:\n[1] print Name\n[2] print Email\n[3] print Module\n[4] print module.txt\n[5]quit program");
            result = sUser.nextInt();
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
                    System.out.println("How many lines?\n");
                    result = sUser.nextInt();
                    for(String line : myID.getLines(result))
                    {
                        System.out.println(line);
                    }
                    
                    break;
                case 5:
                    break;
            }
            if(result == 5)
            {
                break;
            }
            
        }
        sUser.close();
    }
}

