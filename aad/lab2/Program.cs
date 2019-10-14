using System;
using System.IO;
using System.Text.Json;
using System.Text.Json.Serialization;

namespace lab2
{
    class Customer
    {
        public string name {get; set;}
        public string address {get; set;}
        public string phoneNumber {get; set;}
        public DateTime dateOfBirth {get; set;}
        public static Customer Load(string filename)
        {
            using (StreamReader reader = new StreamReader(filename))
            {
                string json = reader.ReadToEnd();
                return JsonSerializer.Deserialize<Customer>(json);
            }
        }

        public void Save(string filename)
        {
            using (StreamWriter writer = new StreamWriter(filename))
            {
                string json = this.json();
                writer.Write(json);
            }
        }
        public string json()
        {
            return JsonSerializer.Serialize<Customer>(this);
        }

        public bool isValid()
        {
            if(this.dateOfBirth < new DateTime(1880, 01, 01))
            {
                return false;
            }
            return true;
        }
    }

    class Address
    {
        
    }


    class Program
    {
        static void Main(string[] args)
        {
            Customer[] customers = new Customer[10];
            Console.WriteLine(customers);

            Customer customer = new Customer(){name = "Tommy", address = "130b Loughborough Road", phoneNumber = "07840144222", dateOfBirth = new DateTime(1998, 05, 09)};
            customer.Save("file.json");

            Customer customer2 = Customer.Load("file.json");
            
            string json = customer2.json();
            Console.WriteLine(json);

            Console.WriteLine($"Is {customer2.name} valid? {customer2.isValid()}");


            customers[0] = customer;
            customers[1] = customer2;

            Console.WriteLine(customers);

            foreach(Customer cus in customers)
            {
                Console.WriteLine(cus);
            }
        }
    }
}
