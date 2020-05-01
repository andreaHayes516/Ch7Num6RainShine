/************************************************
** Author: Andrea Hayes
** Date: April 30, 2020
** Purpose: Create program to track weather data
** Input: File, Weather, Day, Month
** Processing: Report for data file
** Output: Report for each month and three month period
           how many days for each weather type. Also 
           month with most rainy days
*************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;
int main() {
    const int MONTHS = 3, DAYS = 30;
    char type[MONTHS][DAYS];
    string monthNames[MONTHS] = { "June", "July", "August" };
    int count=0,highest, totalS[MONTHS], totalC[MONTHS], totalR[MONTHS],totalOfR=0, totalOfS=0, totalOfC=0;
    ifstream inputFile;

    inputFile.open("../RainOrShine.txt"); // Open file

    if (!inputFile) // If file does not open
    {
        cout << "Could not open file.";
        return 1;
    }

    for (int i = 0; i < MONTHS; i++) {
        for (int j = 0; j < DAYS; j++) {
            inputFile >> type[i][j];
           // cout << i << " " << j << " " << type[i][j] << endl; Display array to make sure it's pulling from file correctly.
        }
    }

    inputFile.close();

    // Get rainy days
    for (int i = 0; i < MONTHS; i++)
    {
        totalR[i] = 0;
        for (int j = 0; j < DAYS; j++)
        {
            if (type[i][j] == 'R')
                totalR[i]++;
        }
    }
    // Get cloudy days
    for (int i = 0; i < MONTHS; i++)
    {
        totalC[i] = 0;
        for (int j = 0; j < DAYS; j++)
        {
            if (type[i][j] == 'C')
                totalC[i]++;
        }
    }

    // Get sunny days
    for (int i = 0; i < MONTHS; i++)
    {
        totalS[i] = 0;
        for (int j = 0; j < DAYS; j++)
        {
            if (type[i][j] == 'S')
                totalS[i]++;
        }
    }
    for (int i = 0; i < MONTHS; i++) {
        totalOfR += totalR[i];
        totalOfS += totalS[i];
        totalOfC += totalC[i];
    }
    // Disply Rainy, Cloudy and Sunny
    for (int i = 0; i < MONTHS; i++)
    {
        cout << monthNames[i] << " " << "Rainy:" << totalR[i] << endl;
    }
    cout << "Total number of rainy days: " << totalOfR << endl;
    cout << endl;

    for (int i = 0; i < MONTHS; i++)
    {
        cout << monthNames[i] << " " << "Cloudy:" << totalC[i] << endl;
    }
    cout << "Total number of cloudy days: " << totalOfC << endl;
    cout << endl;

    for (int i = 0; i < MONTHS; i++)
    {
        cout << monthNames[i] << " " << "Sunny:" << totalS[i] << endl;
   }
    
    cout << "Total number of sunny days: " << totalOfS << endl;
    

    // Get month with most rainy days
    int biggestMonth = 0;
    highest = totalR[0];
    for (int i = 0; i < MONTHS; i++)
    {
        if (totalR[i] > highest)
        {
            highest = totalR[i];
            biggestMonth = i;
        }
    }
    
    cout << endl;
    cout << "Month with most rainy days: " << monthNames[biggestMonth] << endl;

    return 0;
}