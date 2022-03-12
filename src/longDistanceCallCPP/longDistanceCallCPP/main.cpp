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
    
    // Welcome message
    cout << "===============================================" << endl;
    cout << " Welcome to the Long Distance Call Calculator! " << endl;
    cout << "===============================================" << endl;
    // Start  input
    do {
        // Input day of the week
        cout << "Enter the day (Mo Tu We Th Fr Sa Su): ";
        // 2 char input
        cin >> day1 >> day2;
        // Convert toupper()
        day1 = toupper(day1);
        day2 = toupper(day2);
        
        // Input the time the call was started
        cout << "Enter the time the call was started (ex: 14:35): ";
        // Collect 3 part time input
        cin >> hour >> separator >> minute;
        // Convert time to 24 hr time
        timeStarted = hour*100 + minute;
        
        // Input length of call
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
}
