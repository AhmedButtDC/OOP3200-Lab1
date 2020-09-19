//Name:             Ahmed Butt
//Student ID:       100770449
//Last Modified:    September 18, 2020
//File:             OOP3200-Lab1.cpp

#include <iostream>
#include <iomanip>	
#include <sstream>
#include <cmath>
#include <limits>
#include <stdexcept>
#include <stdio.h>
#include <ctype.h>
#include <cctype>
#include <regex>

using namespace std;

//CLASS DECLARATION
class WorkTicket
{
private:

    //Variables and thier default vaulues
    int workTicketNumber = 0;
    string clientID = "";
    int workTicketDate[3] = { 1, 1, 2000 };
    string issueDiscription = "";

public:

    //Gets; all returning values of variables that hold WorkTicket information
    int GetWorkTicketNumber() { return workTicketNumber; }
    string GetClientID() { return clientID; }
    int GetWorkTicketDate() { return workTicketDate[0], workTicketDate[1], workTicketDate[2]; }
    string GetIssueDiscription() { return issueDiscription; }

    //Sets; all change values of the variables that hold WorkTicket information
    void SetWorkTicketNumber(int number) { workTicketNumber = number; }
    void SetClientID(string id) { clientID = id; }
    void SetWorkTicketDate(int day, int month, int year) { workTicketDate[0] = day; workTicketDate[1] = month; workTicketDate[2] = year; }
    void SetIssueDiscription(string issue) { issueDiscription = issue; }

    //SetWorkTicket() mutator, sets all attributes of object to parameters if parameters valid...
    //clientID and issueDiscription must be at least one character, return bool
    void SetWorkTicket(int number, string id, int day, int month, int year, string issue)
    {
        //Check if input is a whole number
        SetWorkTicketNumber(number);

        //Check if input is at least 1 alpha-numeric character
        SetClientID(id);

        //Check if day, month, and year inputs are whole numbers
        SetWorkTicketDate(day, month, year);

        //Check if input is at least 1 character
        SetIssueDiscription(issue);
    }

    //ShowWorkTicket() accessor, display all object's attributes
    string ShowWorkTicket()
    {
        
    }
};

void dateValidation(double dayMonthYear, const int min, const int max, string dmy);

//main() FUNCTION
int main()
{
    //Declarations
    double tempWorkTicketNumber, tempDay, tempMonth, tempYear; //double for floor() and ceil() purposes
    string tempClientID, tempIssueDiscription;
    int ticketIncrement = 1;
    const int min = 1, dayMax = 31, monthMax = 12, yearMin = 2000, yearMax = 2099;
    WorkTicket client[3];   //array of 3 WorkTicket objects
    //try catch

    //Check if input is a whole number
    do
    {
        cout << "Work Ticket " << ticketIncrement << "\n" << "---------------------------------";
        cout << "\nEnter a work ticket number: ";
        cin >> tempWorkTicketNumber;
        while (cin.fail() || floor(tempWorkTicketNumber) != ceil(tempWorkTicketNumber) || tempWorkTicketNumber < min) // if input not a whole number
        {
            cout << "* Invalid input. Please try again and enter a whole number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nEnter a work ticket number: ";
            cin >> tempWorkTicketNumber;
        }

        //Check if input only includes alphanumeric characters
        cout << "\nEnter a client ID: ";
        cin >> tempClientID;

        cout << "\nDate\n" << "------------\n";

        //Check if day input is a whole number within range
        cout << "Enter day: ";
        cin >> tempDay;
        dateValidation(tempDay, min, dayMax, "day");

        //Check if month input is a whole number within range
        cout << "Enter month: ";
        cin >> tempMonth;
        dateValidation(tempMonth, min, monthMax, "month");

        //Check if year input is a whole number within range
        cout << "Enter year: ";
        cin >> tempYear;
        dateValidation(tempYear, yearMin, yearMax, "year");

        //Check if input is at least 1 character long
        cout << "\nEnter an issue discription: ";
        cin >> tempIssueDiscription;
        cout << "\n\n";
        cin.clear(); //for some input buffer problems...
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        //SetWorkTicket call for specific client, provided all validated variables
        client[0].SetWorkTicket(tempWorkTicketNumber, tempClientID, tempDay, tempMonth, tempYear, tempIssueDiscription);

        //call ShowWorkTicket

        ticketIncrement++; //increment the ticket

    } while (ticketIncrement != 4);
    //output loop to display all WorkTickets

    return 0;
}
void dateValidation(double dayMonthYear, const int min, const int max, string dmy)
{
    while (cin.fail() || floor(dayMonthYear) != ceil(dayMonthYear) || dayMonthYear < min || dayMonthYear > max)
    {
        cout << "* Invalid input. Please try again and enter a whole number between" << min << " and " << max << ".\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nEnter " << dmy << ": ";
        cin >> dayMonthYear;
    }
}
//trycatch
//alphanumeric
//output loop