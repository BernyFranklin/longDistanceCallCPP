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
// Define callValid function
bool callLengthValid (int inputValue);

// Start main
int main(int argc, const char * argv[]) {
    // Define variables and constants
    // Weekend rate is $0.15/min
    const double WEEKEND_RATE = 0.15;
    // Evening rate is $0.25/min
    const double EVENING_RATE = 0.25;
    // Usual rate is $0.40/min
    const double DAY_RATE = 0.40;
    
    char day1;            // 1st char for day of week
    char day2;            // 2nd char for day of week
    int hour;             // Hour input for start time
    char separator;       // Char separator for ':' entered by user
    int minute;           // Minute inpput for start time
    int lengthOfCall;     // Length of call input
    char again;           // Used for additional calls
    int timeStarted;      // Time started in 24 hour format
    double billingRate;   // Billing rate used
    double costOfCall;    // Computed cost of the call
    
    // Function variables
    bool dayCheck;    // Used for dayChecker()
    bool timeCheck;   // Used for timeChecker()
    bool callCheck;   // Used for callValid()
    
    // Welcome message
    cout << "===============================================" << endl;
    cout << " Welcome to the Long Distance Call Calculator! " << endl;
    cout << "===============================================" << endl;
    
    // Start input
    do {
        cout << endl;   // Blank line
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
        } while (!dayCheck);   // Loop if day invalid

        cout << endl;   // Blank line
        
        // Loop for checking call time
        do {
            // Ask for call time
            cout << "Enter the time the call was started (00:00 - 23:59): ";
            // Collect 3 part time input
            cin >> hour >> separator >> minute;
            // call timeChecker()
            timeCheck = timeChecker(hour, separator, minute);
        } while (!timeCheck);   // Loop if time is invalid
        
        // Convert time to 24 hr time by multiplying hours by 100 ie 17 becomes 1700
        timeStarted = hour*100 + minute;
        
        cout << endl;   // Blank line
        
        // Loop to check length isn't negative
        do {
            // Ask for call length
            cout << "Enter the length of the call in minutes: ";
            // Input call length
            cin >> lengthOfCall;
            // Check if numeric and positive
            callCheck = callLengthValid(lengthOfCall);
        } while (!callCheck);
        
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
        cout << endl;                                       // Blank line
        cout << setiosflags(ios::fixed | ios::showpoint);   // Show decimal
        cout << setprecision(2);                            // 2 places past decimal
        cout << "Total cost of call is: $" << costOfCall << endl;
        
        // Loop control
        cout << "Enter another call (Y/N)? ";
        cin >> again;
        again = toupper(again);
    } while (again == 'Y');
    
    // Closing message
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
    else {
        cout << "Invalid day of week..." << endl;
        cout << "Please try again..." << endl << endl;
        dayOfWeek = false;
    }
    return dayOfWeek;
}   // End of Day checker function

// Time checker function
bool timeChecker (int hr, char sep, int min) {
    bool isValid = true;   // Assume tiem is valid unless proven otherwise
    if (!cin) {
        cout << "Input for time must be numeric..." << endl;
        cout << "Please try again.." << endl << endl; cin.clear();
        cin.ignore(10000, '\n');
        isValid = false;
        return isValid;
    }
    // Hrs must be between 0-23
    if (!(hr >= 0 && hr <= 23)) {
        cout << "Hour must be between 0 - 23" << endl;
        isValid = false;
    }
    // Sep must be semicolon
    if (sep != ':') {
        cout << "Hours and Minutes must be separated by a semicolon" << endl;
        isValid = false;
    }
    // Min must be between 0-59
    if (!(min >= 0 && min <= 59)) {
        cout << "Minutes must be between 0 - 59" << endl;
        isValid = false;
    }
    // If flag set add
    if (!isValid)
        cout << "Please try again..." << endl << endl;
        
    return isValid;
}   // End of time checker function

// Call Length Validator
bool callLengthValid (int inputValue) {
    // Assume good input
    bool isValid = true;
    // Is input numeric?
    if (!cin) {
        cout << "Input for call length must be numeric..." << endl;
        cout << "Please try again..." << endl << endl; cin.clear();
        cin.ignore(10000, '\n');   // buffer cleared
        isValid = false;
    }   // End of numeric check
    else if (inputValue < 0) {
        cout << "Input must be positive integer..." << endl;
        cout << "Please try again..." << endl << endl;
        isValid = false;
    }   // End of negative check
    return isValid;
}   // End of call length validator
