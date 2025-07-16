#pragma warning(disable : 4996) // Disable warning for using unsafe functions like ctime()

#include <ctime>     // For time-related functions
#include <iostream>  // For input/output

using namespace std;

int main() {
    time_t t = time(0); // Get the current time in seconds since 1970 (epoch)

    // Convert to local time string
    char* dt = ctime(&t);
    cout << "Local date and time is: " << dt << "\n";

    // Convert to UTC (GMT) time structure
    tm* gmtm = gmtime(&t);
    dt = asctime(gmtm); // Convert tm struct to readable string
    cout << "UTC date and time is: " << dt;

    return 0;
}
