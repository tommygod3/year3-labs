using System;
using System.IO;
using System.Text.Json;

namespace lab2
{
    class Customer
    {
        public string name {get; set;}
        public Address address {get; set;}
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
}