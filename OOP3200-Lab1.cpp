//Name:     Ahmed Butt
//ID:       100770449
//Date:     September 18, 2020
//File:     OOP3200-Lab1.cpp

#include <iostream> 		// cin, cout
#include <iomanip>			// fixed, setprecision()
#include <sstream> 			// stringstream
#include <cmath>			// sqrt()
#include <limits>			// INT_MAX
#include <stdexcept>		// out_of_range

using namespace std;

//CLASS DECLARATION
class WorkTicket
{
    //Variables and thier default vaulues
    int workTicketNumber = 0;
    string clientID = "";
    int workTicketDate[3] = { 1, 1, 2000 };
    string issueDiscription = "";

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
        SetWorkTicketNumber(number);
        SetClientID(id);
        SetWorkTicketDate(day, month, year);
        SetIssueDiscription(issue);
    }

    //ShowWorkTicket() accessor, display all object's attributes
    string ShowWorkTicket()
    {
        
    }
};

//main() FUNCTION
int main()
{
    //array of 3 WorkTicket objects
    //input loop to enter info, called SetWorkTicket() after input validation
    //output loop to display all WorkTickets
}