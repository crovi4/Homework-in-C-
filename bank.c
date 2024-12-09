using System;

class Program
{
    static void Main(string[] args)
    {
        // Prompt the user for the deposit amount
        Console.Write("Enter the deposit amount: ");
        double depositAmount;
        while (!double.TryParse(Console.ReadLine(), out depositAmount) || depositAmount < 0)
        {
            Console.Write("Please enter a valid positive number for the deposit amount: ");
        }

        // Prompt the user for the number of months
        Console.Write("Enter the number of months: ");
        int numberOfMonths;
        while (!int.TryParse(Console.ReadLine(), out numberOfMonths) || numberOfMonths < 0)
        {
            Console.Write("Please enter a valid non-negative integer for the number of months: ");
        }

        // Calculate the final amount after applying interest for each month
        double interestRate = 0.07; // 7% interest rate
        double finalAmount = depositAmount;

        for (int month = 1; month <= numberOfMonths; month++)
        {
            finalAmount += finalAmount * interestRate; // Add interest to the final amount
        }

        // Display the final amount
        Console.WriteLine($"The final amount after {numberOfMonths} months is: {finalAmount:C}");
    }
}
