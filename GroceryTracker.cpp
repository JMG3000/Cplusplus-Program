/*
Name: Jacob M. Garrett
Date: 4/20/2025
Description: A program to store and retrieve an item list by using a text file. This porgram allows has features to allow
the user to search for a item and return the number in inventory, displaying the inventory in a histiograph format, and it 
backups and reads the data from a .dat file.
*/
#include "GroceryTracker.h"
#include <fstream>
#include <iostream>
#include <iomanip>

//method that opens and loads the data from the text file.
void GroceryTracker::LoadDataFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    std::string item;

    if (!inFile) {
        std::cerr << "Error: Unable to open input file.\n";
        return;
    }

    while (inFile >> item) {
        ++itemFrequency[item];
    }

    inFile.close();
}

//Method that saves the frequency of each item to a backup .dat file.
void GroceryTracker::SaveFrequencyToFile(const std::string& filename) {
    std::ofstream outFile(filename);
    for (const auto& pair : itemFrequency) {
        outFile << pair.first << " " << pair.second << "\n";
    }
    outFile.close();
}

//Method that gets the frequency from the backup file.
int GroceryTracker::GetItemFrequency(const std::string& item) {
    if (itemFrequency.find(item) != itemFrequency.end()) {
        return itemFrequency[item];
    }
    else {
        return 0;
    }
}

//Method that returns a list of all items in the current inventory in the .dat file
void GroceryTracker::PrintAllFrequencies() {
    std::cout << "\nItem Frequencies:\n";
    for (const auto& pair : itemFrequency) {
        std::cout << std::setw(12) << std::left << pair.first << " " << pair.second << "\n";
    }
}

//Method that returns a histiogram of the current .dat file
void GroceryTracker::PrintHistogram() {
    std::cout << "\nItem Histogram:\n";
    for (const auto& pair : itemFrequency) {
        std::cout << std::setw(12) << std::left << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
}

