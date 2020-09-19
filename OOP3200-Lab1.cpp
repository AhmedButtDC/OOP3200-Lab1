//Name:             Ahmed Butt, Muzhda Ehsan
//Student ID:       100770449, 100770164
//Last Modified:    September 19, 2020
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
    //hoenstly, I don't understand the point of these
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

void dateValidation(double dayMonthYear, const int min, const int max, string dMY); //to decrease some repeated code

//main() FUNCTION
int main()
{
    //Declarations
    double tempWorkTicketNumber, tempDay, tempMonth, tempYear; //double for floor() and ceil() purposes
    string tempClientID, tempIssueDiscription;
    int ticketIncrement = 0;
    const int min = 1, dayMax = 31, monthMax = 12, yearMin = 2000, yearMax = 2099;
    const string strDay = "day", strMonth = "month", strYear = "year";
    WorkTicket client[3];   //array of 3 WorkTicket objects (0, 1, and 2)

    try
    {
        do  //do-while loop to increment through each work ticket
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

            cout << "\nEnter a client ID: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');    //for some input buffer issues with getline()  
            getline(cin, tempClientID);
            while (tempClientID.empty() || !regex_search(tempClientID, regex("^[a-zA-Z0-9]*$"))) //check if input is not empty and only includes alphanumeric characters
            {
                cout << "* Invalid input. Client ID must be at least one alphanumeric character. Non-alphanumeric characters are not allowed.\n";
                cout << "\nEnter a client ID: ";
                getline(cin, tempClientID);
            }

            cout << "\nDate\n" << "------------\n";

            cout << "Enter day: ";
            cin >> tempDay;
            dateValidation(tempDay, min, dayMax, strDay);    //check if day input is a whole number within range

            cout << "Enter month: ";
            cin >> tempMonth;
            dateValidation(tempMonth, min, monthMax, strMonth);  //check if month input is a whole number within range

            cout << "Enter year: ";
            cin >> tempYear;
            dateValidation(tempYear, yearMin, yearMax, strYear); //check if year input is a whole number within range

            cout << "\nEnter an issue discription: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');    //for some input buffer issues with getline()  
            getline(cin, tempIssueDiscription);
            while (tempIssueDiscription.empty())    //check if input is at least 1 character long
            {
                cout << "* Invalid input. An issue discription must be at least one character long.\n";
                cout << "\nEnter an issue discription: ";
                getline(cin, tempIssueDiscription);
            }
            cout << "\n\n";

            //SetWorkTicket call for specific client, provided all validated variables
            //for some reason it just accepted the double variables without conversion to int
            client[ticketIncrement].SetWorkTicket(tempWorkTicketNumber, tempClientID, tempDay, tempMonth, tempYear, tempIssueDiscription);

            ticketIncrement++; //increment the ticket

        } while (ticketIncrement != 3); //client array goes from 0-2, so 3 would be out of range

        for (int i = 0; i != ticketIncrement; i++)  //output loop to display all WorkTickets using ShowWorkTicket
        {
            cout << "Client " << (i + 1) << "\n-----------------\n" ;
            cout << client[i].ShowWorkTicket() << "\n\n";
        }
    }
    catch (exception& ia)
    {
        cerr << "* Invalid input." << ia.what();
    }

    return 0;
}
void dateValidation(double dayMonthYear, const int min, const int max, string dMY)
{
    while (cin.fail() || floor(dayMonthYear) != ceil(dayMonthYear) || dayMonthYear < min || dayMonthYear > max) //if not whole number within range
    {
        cout << " Please try again and enter a whole number between " << min << " and " << max << ".\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nEnter " << dMY << ": ";
        cin >> dayMonthYear;
    }
}

bool WorkTicket::SetWorkTicket(int number, string id, int day, int month, int year, string issue)
{
    SetWorkTicketNumber(number);    //changing the default value of work ticket number

    SetClientID(id);    //changing the default value of id

    SetWorkTicketDate(day, month, year);    //changing the default values of work ticket date array
    
    SetIssueDiscription(issue); //changing the default value of issue discription

    return true;    //returning true because lab requirements say so lol
}

string WorkTicket::ShowWorkTicket() //displays the work ticket
{
    stringstream ticket;
    ticket << "Work Ticket Number: " << workTicketNumber << "\n"
        << "Client ID: " << clientID << "\n"
        << "Work Ticket Date: " << workTicketDate[0] << "/" << workTicketDate[1] << "/" << workTicketDate[2] << "\n"
        << "Issue Discription: " << issueDiscription;
    return ticket.str();
}