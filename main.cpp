
/*
Name: Jacob M. Garrett
Date: 4/20/2025
Description: A program to store and retrieve an inventory list by using a text file. This porgram allows has features to allow 
Description: A program to store and retrieve an item list by using a text file. This porgram allows has features to allow
the user to search for a item and return the number in inventory, displaying the inventory in a histiograph format, and it
backups and reads the data from a .dat file.
*/
#include <iostream>
#include <string>
#include <limits>
#include "GroceryTracker.h"

//Function that prints out a menu to the screen when called. It is constructed as vois, so there is no return value;
void DisplayMenu() {
    std::cout << "\n====== Corner Grocer Menu ======\n";
    std::cout << "1. Search for item frequency\n";
    std::cout << "2. Display all item frequencies\n";
    std::cout << "3. Display histogram of items\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";
}

//Start of the Main() function to calls the implemented classes, methods, and functions needed to run the program.
int main() {
    // Constructs an GroceryTracker object called tracker
    GroceryTracker tracker;

    //uses the method in the GroceryTracker class file to load the master text file.
    tracker.LoadDataFromFile("CS210_Project_Three_Input_File.txt");

    //uses the method in the GroceryTracker class file to save to the backup file
    tracker.SaveFrequencyToFile("frequency.dat");

    //set the variables choice to int and to have a value of 0 and defines the itemName as a string with no value at load.
    int choice = 0;
    std::string itemName;

    while (true) {

        //Calls the DisplayMenu() function every time the loop runs.
        DisplayMenu();

        // Input validation for menu choice
        while (!(std::cin >> choice)) {
            std::cin.clear(); // Clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard input
            std::cout << "Invalid input. Please enter a number between 1 and 4: ";
        }

        // Discard leftover newline after entering the choice
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        //Input validation 
        switch (choice) {
        
        //Case that allows the user to search for a item and it returns the current value if the item is in the .dat file.
        case 1:
            std::cout << "Enter item name: ";
            std::getline(std::cin, itemName);  // Handles full names and spaces
            std::cout << itemName << " was purchased "
                << tracker.GetItemFrequency(itemName) << " times.\n";
            break;

        //Case that prints the .dat file
        case 2:
            tracker.PrintAllFrequencies();
            break;

        //Case that displays a histiogram
        case 3:
            tracker.PrintHistogram();
            break;

        //Case that provides an exit for the loop to end the program.
        case 4:
            std::cout << "Exiting program. Goodbye!\n";
            return 0;

        default:
            std::cout << "Invalid choice. Please select between 1 and 4.\n";
            break;
        }//End Switch
        
    } //End while loop

    return 0; // End Program
}
