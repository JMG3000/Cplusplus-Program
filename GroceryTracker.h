/*
Name: Jacob M. Garrett
Date: 4/20/2025
Description: A program to store and retrieve an item list by using a text file. This porgram allows has features to allow
the user to search for a item and return the number in inventory, displaying the inventory in a histiograph format, and it
backups and reads the data from a .dat file.
*/
#pragma once
#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <map>
#include <string>

class GroceryTracker {
private:
    std::map<std::string, int> itemFrequency;

public:
    void LoadDataFromFile(const std::string& filename);
    void SaveFrequencyToFile(const std::string& filename);
    int GetItemFrequency(const std::string& item);
    void PrintAllFrequencies();
    void PrintHistogram();
};

#endif
