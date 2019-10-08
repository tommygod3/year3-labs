/**
 * A simple program that prints a greeting message
 * File: myID.java
 */

import java.io.*;

public class myID
{
   public static void main(String[] args)
   {
      String name = "";
      InputStreamReader isr = null;
      BufferedReader br = null;
      //create streams to process user input
      isr = new InputStreamReader(System.in);
      br = new BufferedReader(isr);
      try {
        //prompt user to enter name
        System.out.println("Please Enter your name");
        //read in the user name from the command prompt
        name = br.readLine();
      } 
      catch(IOException e) {
        System.out.println("IO Exception ocuured " + e);
      }
      System.out.println("Congratulations '" + name +
                          "', you've just ran your 1st Java program.\n");

   }
}

