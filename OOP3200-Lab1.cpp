//Name:             Ahmed Butt
//Student ID:       100770449
//Last Modified:    September 18, 2020
//File:             OOP3200-Lab1.cpp

#include <iostream>
#include <iomanip>	
#include <sstream>
#include <string>
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
    bool SetWorkTicket(int number, string id, int day, int month, int year, string issue);

    //ShowWorkTicket() accessor, display all object's attributes
    string ShowWorkTicket();
};

void dateValidation(double dayMonthYear, const int min, const int max, string dmy);

//main() FUNCTION
int main()
{
    //Declarations
    double tempWorkTicketNumber, tempDay, tempMonth, tempYear; //double for floor() and ceil() purposes
    string tempClientID, tempIssueDiscription;
    int ticketIncrement = 0;
    const int min = 1, dayMax = 31, monthMax = 12, yearMin = 2000, yearMax = 2099;
    WorkTicket client[3];   //array of 3 WorkTicket objects
    //try catch
    try
    {
        //Check if input is a whole number
        do
        {
            cout << "Work Ticket " << (ticketIncrement + 1) << "\n" << "---------------------------------";
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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, tempIssueDiscription);
            cout << "\n\n";

            //SetWorkTicket call for specific client, provided all validated variables
            client[ticketIncrement].SetWorkTicket(tempWorkTicketNumber, tempClientID, tempDay, tempMonth, tempYear, tempIssueDiscription);

            ticketIncrement++; //increment the ticket

        } while (ticketIncrement != 3);
        //output loop to display all WorkTickets using ShowWorkTicket
        for (int i = 0; i != ticketIncrement; i++)
        {
            cout << "Client " << (i + 1) << "\n-----------------\n" ;
            cout << client[i].ShowWorkTicket();
            cout << "\n\n";
        }
    }
    catch (exception& ia)
    {
        cerr << "* Invalid input." << ia.what();
    }

    return 0;
}
void dateValidation(double dayMonthYear, const int min, const int max, string dmy)
{
    while (cin.fail() || floor(dayMonthYear) != ceil(dayMonthYear) || dayMonthYear < min || dayMonthYear > max)
    {
        cout << " Please try again and enter a whole number between " << min << " and " << max << ".\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nEnter " << dmy << ": ";
        cin >> dayMonthYear;
    }
}
bool WorkTicket::SetWorkTicket(int number, string id, int day, int month, int year, string issue)
{
    SetWorkTicketNumber(number);

    SetClientID(id);

    SetWorkTicketDate(day, month, year);

    SetIssueDiscription(issue);

    return true;
}
string WorkTicket::ShowWorkTicket()
{
    stringstream ticket;
    ticket << "Work Ticket Number: " << workTicketNumber << "\n"
        << "Client ID: " << clientID << "\n"
        << "Work Ticket Date: " << workTicketDate[0] << "/" << workTicketDate[1] << "/" << workTicketDate[2] << "\n"
        << "Issue Discription: " << issueDiscription;
    return ticket.str();
}
//alphanumeric