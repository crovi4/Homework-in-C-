using System;

namespace WeatherStationData
{
    class Program
    {
        static void Main(string[] args)
        {
            // Create an array to hold the temperature data for 30 days
            int[] temperatures = new int[30];

            // Create an instance of the Random class
            Random rnd = new Random();

            // Fill the array with random temperatures from -20 to +30
            for (int i = 0; i < temperatures.Length; i++)
            {
                temperatures[i] = rnd.Next(-20, 31); // Random number between -20 and +30
            }

            // Print the temperatures
            Console.WriteLine("Average Daily Temperatures for the Month:");
            foreach (var temp in temperatures)
            {
                Console.Write(temp + " "); // Print each temperature followed by a space
            }
            Console.WriteLine(); // New line for better readability

            // 1. Count the number of days when the temperature exceeded +5
            int countAbove5 = 0;
            // 2. Count the number of days when the temperature was below 0
            int countBelow0 = 0;
            // 3. Calculate the average temperature for the month
            decimal sum = 0;

            foreach (var temp in temperatures)
            {
                if (temp > 5) countAbove5++;
                if (temp < 0) countBelow0++;
                sum += temp;
            }
            
            decimal averageTemperature = sum / temperatures.Length;

            Console.WriteLine($"Number of days above +5 degrees: {countAbove5}");
            Console.WriteLine($"Number of days below 0 degrees: {countBelow0}");
            Console.WriteLine($"Average temperature for the month: {averageTemperature:F2} degrees Celsius");

            // 4. Find out which week(s) were the coldest in terms of average temperature
            decimal[] weeklyAverages = new decimal[4]; // For 4 weeks
            for (int week = 0; week < 4; week++)
            {
                decimal weeklySum = 0;
                for (int day = 0; day < 7; day++)
                {
                    weeklySum += temperatures[week * 7 + day];
                }
                weeklyAverages[week] = weeklySum / 7;
            }

            // Determine the coldest week(s)
            decimal coldestAverage = decimal.MaxValue;
            foreach (var avg in weeklyAverages)
            {
                if (avg < coldestAverage)
                {
                    coldestAverage = avg;
                }
            }

            Console.WriteLine($"Coldest week(s) average temperature: {coldestAverage:F2} degrees Celsius");
            Console.Write("Coldest week(s): ");
            for (int week = 0; week < 4; week++)
            {
                if (weeklyAverages[week] == coldestAverage)
                {
                    Console.Write($"Week {week + 1} ");
                }
            }
            Console.WriteLine();

            // 5. Convert the temperature data string to degrees Fahrenheit
            Console.WriteLine("Temperatures in Fahrenheit:");
            foreach (var temp in temperatures)
            {
                decimal fahrenheit = (temp * 9 / 5) + 32; // Convert Celsius to Fahrenheit
                Console.Write(fahrenheit + " "); // Print each temperature in Fahrenheit
            }
            Console.WriteLine(); // New line for readability
        }
    }
}
