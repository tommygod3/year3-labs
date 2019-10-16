using System;
using System.Collections.Generic;  

namespace lab2
{
    class Program
    {
        static List<Customer> customersInRange(Address target, List<Customer> inputCustomers)
        {
            List<Customer> customersInRange = inputCustomers;
            foreach (Customer c in customersInRange.ToArray())
            {
                if (c.address - target > 50)
                {
                    customersInRange.Remove(c);
                }
            }
            return customersInRange;
        }
        static void Main(string[] args)
        {
            List<Customer> customers = new List<Customer>();

            Address tommyAddress = new Address(){streetName = "Loughborough Road", streetNumber = "130b", postCode = "NG2 7JE"};
            Customer customer = new Customer(){name = "Tommy", address = tommyAddress, phoneNumber = "07840144222", dateOfBirth = new DateTime(1998, 05, 09)};
            customer.Save("file.json");

            Customer customerCopy = Customer.Load("file.json");
            
            Console.WriteLine(customerCopy.json());

            Console.WriteLine($"Is {customerCopy.name} valid? {customerCopy.isValid()}");

            Address secondAddress = new Address(){streetName = "Billingdon Road", streetNumber = "12", postCode = "NG2 1YB"};
            Customer customer2 = new Customer(){name = "Bob", address = secondAddress, phoneNumber = "07483910123", dateOfBirth = new DateTime(1988, 01, 19)};

            Address thirdAddress = new Address(){streetName = "Clean Street", streetNumber = "1459", postCode = "NG8 3NS"};
            Customer customer3 = new Customer(){name = "Clive", address = thirdAddress, phoneNumber = "07476372162", dateOfBirth = new DateTime(1956, 11, 11)};

            Address fourthAddress = new Address(){streetName = "Penny Lane", streetNumber = "4", postCode = "L1 4HQ"};
            Customer customer4 = new Customer(){name = "Paul", address = fourthAddress, phoneNumber = "07832713533", dateOfBirth = new DateTime(1943, 06, 29)};


            customers.Add(customer);
            customers.Add(customerCopy);
            customers.Add(customer2);
            customers.Add(customer3);
            customers.Add(customer4);

            Console.WriteLine(customers);


            foreach (Customer c in customers)
            {
                Console.WriteLine(customer.address - c.address);
            }

            foreach (Customer c in customersInRange(tommyAddress, customers))
            {
                Console.WriteLine(c.name);
            }
        }
    }
}
