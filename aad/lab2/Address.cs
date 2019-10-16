using System;
using System.Text.RegularExpressions;
using System.Collections.Generic;
namespace lab2
{
    class Address
    {
        public string streetName {get; set;}
        public string streetNumber {get; set;}
        public string postCode {get; set;}
        public Dictionary<string, string> getPostCodeDict()
        {
            Dictionary<string, string> postCodeDict = new Dictionary<string, string>();
            Match match = Regex.Match(this.postCode, @"(?<firstString>\D+)(?<firstNumber>\d+) (?<lastNumber>\d)(?<lastString>\D\D)");
            postCodeDict.Add("firstString", match.Groups["firstString"].Value);
            postCodeDict.Add("firstNumber", match.Groups["firstNumber"].Value);
            postCodeDict.Add("lastString", match.Groups["lastString"].Value);
            postCodeDict.Add("lastNumber", match.Groups["lastNumber"].Value);
            return postCodeDict;
        }
        public static int operator- (Address a, Address b)
        {
            Dictionary<string, string> aPostCodeDict = a.getPostCodeDict();
            Dictionary<string, string> bPostCodeDict = b.getPostCodeDict();

            if (aPostCodeDict["firstString"] == bPostCodeDict["firstString"])
            {
                if (aPostCodeDict["firstNumber"] == bPostCodeDict["firstNumber"])
                {
                    int aNumber = Int32.Parse(aPostCodeDict["lastNumber"]);
                    int bNumber = Int32.Parse(bPostCodeDict["lastNumber"]);
                    int difference = aNumber - bNumber;
                    if (difference < 0)
                    {
                        difference = -difference;
                    }
                    return difference * 5;
                }
                else
                {
                    int aNumber = Int32.Parse(aPostCodeDict["firstNumber"]);
                    int bNumber = Int32.Parse(bPostCodeDict["firstNumber"]);
                    int difference = aNumber - bNumber;
                    if (difference < 0)
                    {
                        difference = -difference;
                    }
                    return difference * 20;
                }

            }
            return 100;
        }
    }
}