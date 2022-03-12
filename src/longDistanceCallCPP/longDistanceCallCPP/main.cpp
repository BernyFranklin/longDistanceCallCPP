/*
 * longDistanceCallCPP Version1.0
 * Frank Bernal
 * CIS 054 C/C++ programming
 * Input: day of week, time of call, call length
 * Output: cost of call
 * 12 Mar 2022
*/

// Used for cin cout
#include <iostream>
// Used for toupper()
#include <cstring>
// Used for 2 places past decimal
# include <iomanip>

// Used to omit "std::" from cin cout
using namespace std;

// Define dayChecker function
bool dayChecker (char charOne, char charTwo);
// Define timeChecker function
bool timeChecker (int hr, char sep, int min);

// Start main
int main(int argc, const char * argv[]) {
    // Define variables and constants
    // Weekend rate is $0.15/min
    const double WEEKEND_RATE = 0.15;
    // Evening rate is $0.25/min
    const double EVENING_RATE = 0.25;
    // Usual rate is $0.40/min
    const double DAY_RATE = 0.40;
    // 1st char for day of week
    char day1;
    // 2nd char for day of week
    char day2;
    // Hour input for start time
    int hour;
    // Char separator for ':' entered by user
    char separator;
    // Minute inpput for start time
    int minute;
    // Length of call input
    int lengthOfCall;
    // Used for additional calls
    char again;
    // Time started in 24 hour format
    int timeStarted;
    // Billing rate used
    double billingRate;
    // Computed cost of the call
    double costOfCall;
    
    // Function variables
    bool dayCheck;  // Used for dayChecker()
    bool timeCheck;   // Used for timeChecker()
    
    // Welcome message
    cout << "===============================================" << endl;
    cout << " Welcome to the Long Distance Call Calculator! " << endl;
    cout << "===============================================" << endl;
    // Start  input
    do {
        
        //Loop for checking day
        do {
            
            // Input day of the week
            cout << "Enter the day (Mo Tu We Th Fr Sa Su): ";
            // 2 char input
            cin >> day1 >> day2;
            // Convert toupper()
            day1 = toupper(day1);
            day2 = toupper(day2);
            // Call day checker
            dayCheck = dayChecker(day1, day2);
        
            if (!dayCheck) {
                cout << "Invalid day of week..." << endl;
                cout << "Please try again..." << endl << endl;
            }
            else;
                
        } while (!dayCheck);   // End of Day check
        
        // Input the time the call was started
        cout << endl;   // Blank line
        do {   // Start check for valid time format
            cout << "Enter the time the call was started (ex: 14:35): ";
            // Collect 3 part time input
            cin >> hour >> separator >> minute;
            // call timeChecker()
            timeCheck = timeChecker(hour, separator, minute);
            
            if (!timeCheck) {
                cout << "Incorrect time format..." << endl;
                cout << "Please try again..." << endl << endl;
            } else;
            
        } while (!timeCheck);
        // Convert time to 24 hr time
        timeStarted = hour*100 + minute;
        
        // Input length of call
        cout << endl;
        cout << "Enter the length of the call in minutes: ";
        cin >> lengthOfCall;
        
        // Process for billing rate and then cost
        // Test for weekend
        if ((day1 == 'S') && (day2 == 'A' || day2 == 'U'))
            billingRate = WEEKEND_RATE;
        // Weekday
        else {
            // Test for time of day
            // Day time?
            if (timeStarted >= 800 && timeStarted <= 1800)
                billingRate = DAY_RATE;
            // Night time
            else
                billingRate = EVENING_RATE;
        }   // End of time of day
        
        // Calculate cost
        costOfCall = lengthOfCall * billingRate;
        
        // Output
        cout << endl;
        cout << setiosflags(ios::fixed | ios::showpoint);
        cout << setprecision(2);
        cout << "Total cost of call is: $" << costOfCall << endl;
        
        // Loop control
        cout << "Enter another call (Y/N)? ";
        cin >> again;
        again = toupper(again);
    } while (again == 'Y');
    
    // End message
    cout << endl;
    cout << "=======================================================" << endl;
    cout << " Thank you for using the Long Distance Call Calculator " << endl;
    cout << "=======================================================" << endl;
    return 0;
}   // End of main

// Day checker function
bool dayChecker (char charOne, char charTwo) {
    bool dayOfWeek;   // Flag for valid day
    if (charOne == 'M' && charTwo == 'O')  // Monday
        dayOfWeek = true;
    else if (charOne == 'T' && (charTwo == 'U' || charTwo == 'H'))  // Tues or Thurs
        dayOfWeek = true;
    else if (charOne == 'W' && charTwo == 'E')   // Wednesday
        dayOfWeek = true;
    else if (charOne == 'F' && charTwo == 'R')   // Friday
        dayOfWeek = true;
    else if (charOne == 'S' && (charTwo == 'A' || charTwo == 'U'))   // Sat or Sun
        dayOfWeek = true;
    else
        dayOfWeek = false;
    return dayOfWeek;
}   // End of Day checker function

// Time checker function
bool timeChecker (int hr, char sep, int min) {
    bool isValid = true;   // Assume tiem is valid unless proven otherwise
    if (!(hr >= 0 && hr <= 23) ||
        sep != ':' ||
        !(min >= 0 && min <= 59))   // Hrs not between 0-23
        isValid = false;
    return isValid;
}
