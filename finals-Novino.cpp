/******************************************************************************
Problem 04
Programmed by: Jolly Novino
Date Accomplished: 07/09/2022

//This program counts number of bombs or scan the area if safe.

*******************************************************************************/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>


using namespace std;
void displayWelcomeMessage();
void displaySystemMenu();
void viewReservations();
void makeReservation();
void generateReport();
void reservationSummary();
int getLineCount();

int main()
{
    displayWelcomeMessage();
    displaySystemMenu();

    string choice;
    bool isValidChoice = false;

    do {
        cout << "Please enter your choice: ";
        cin >> choice;

        transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

        if (choice == "e") {
            cout << "Thank You!";
            return 0;
        }

        if (choice != "v" && choice != "m" && choice != "r") {
            cout << "Invalid selection, please try again" << endl;
            continue;
        }

        if (choice == "v") {
            viewReservations();
            return 0;
        }

        if (choice == "m") {
            makeReservation();
            return 0;
        }

        if (choice == "r") {
            generateReport();
            return 0;
        }

        isValidChoice = true;

    } while (!isValidChoice);
    
 

    return 0;
}

void displayWelcomeMessage() {
    cout << "Welcome to Small Restaurant Reservation System!" << endl;
    cout << "Programmed by: Jolly Novino" << endl;
}

void displaySystemMenu() {
    cout << "System Menu" << endl;
    cout << "[V] - View Reservation" << endl;
    cout << "[M] - Make Reservation" << endl;
    cout << "[R] - Show Report" << endl;
    cout << "[E] - Exit Program" << endl;
} 

void viewReservations() {
    fstream iFile;
    iFile.open("reservations.txt", ios::in);
    if (!iFile)
    {
        cout << "File not created!";
        return;
    }

    string line;
    while (getline(iFile, line))
    {
        cout << line << endl;
    }
    iFile.close();
}

int getLineCount() {
    fstream iFile;
    int count = 0;
    iFile.open("reservations.txt", ios::in);
    if (!iFile)
    {
        cout << "File not created!";
        return 0;
    }

    string line;
    while (getline(iFile, line))
    {
        count++;
    }
    iFile.close();

    return count;
}

void makeReservation() {
    string firstName, lastName;
    string reservationDate;
    string reservationTime;
    int noOfAdults;
    int noOfChildren;

    cout << "Enter Name: ";
    cin >> firstName >> lastName;

    cout << "Date (dd-mmm-yyyy): ";
    cin >> reservationDate;

    cout << "Time (hh:mm:AM/PM): ";
    cin >> reservationTime;

    cout << "No. of Adults: ";
    cin >> noOfAdults;

    cout << "No. of Children: ";
    cin >> noOfChildren;

    fstream iFile;
    iFile.open("reservations.txt", ios::app);

    if (!iFile)
    {
        cout << "File not created!";
        return;
    }

    int lineCount = getLineCount();
    iFile << "\n";
    iFile << lineCount + 1 << " " << reservationDate << " " << reservationTime << " " << firstName << lastName << " " << noOfAdults << " " << noOfChildren;
    iFile.close();
}

void generateReport() {
    cout << "\n";
    cout << "Reservation Report" << endl;
    cout << "==================" << endl;

    viewReservations();
    reservationSummary();
}

void reservationSummary() {
    fstream iFile;
    string id;
    string date;
    string time;
    string firstName;
    string lastName;
    int noOfAdults;
    int noOfChildren;
    

    iFile.open("reservations.txt", ios::in);
    if (!iFile)
    {
        cout << "File not created!";
        return;
    }

    string line;
    int totalAdults = 0;
    int totalChildren = 0;

    while (!iFile.eof())
    {
        iFile >> id >> date >> time >> firstName >> lastName >> noOfAdults >> noOfChildren;

        totalAdults += noOfAdults;
        totalChildren += noOfChildren;
    }
    cout << "\n";
    cout << "Total # of adults: " << totalAdults << endl;
    cout << "Total # of children: " << totalChildren << endl;
    cout << "Grand Total: " << (totalAdults * 500) + (totalAdults * 300) << endl;

    iFile.close();
}