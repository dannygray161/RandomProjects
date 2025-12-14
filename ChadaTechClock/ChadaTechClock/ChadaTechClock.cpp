#define _CRT_SECURE_NO_WARNINGS // To suppress error about line 174 for testing/scenario purposes
#include <iostream>
#include <string>
#include <iomanip>      // For setfill() and setw()
#include <sstream>      // For stringstream, to format numbers
#include <chrono>       // For getting the system time
#include <ctime>        // For time_t and tm struct
#include <limits>       // For numeric_limits, to clear input errors

using namespace std;

/**
 * @class ChadaClock
 * Holds the core time data (h, m, s) in 24-hour format
 * and provides methods to add time and get formatted output.
 */
class ChadaClock {
private:
    // Internal time is stored in 24-hour format
    int hours;
    int minutes;
    int seconds;

public:
    // Constructor
    ChadaClock(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    // --- Public Methods ---

    /**
     * Adds one hour, wraps around from 23 to 0.
     */
    void addHour() {
        hours = (hours + 1) % 24;
    }

    /**
     * Adds one minute, wraps from 59 to 0 and calls addHour().
     */
    void addMinute() {
        minutes = (minutes + 1) % 60;
        if (minutes == 0) {
            addHour(); // Handle cascading hour increment
        }
    }

    /**
     * Adds one second, wraps from 59 to 0 and calls addMinute().
     */
    void addSecond() {
        seconds = (seconds + 1) % 60;
        if (seconds == 0) {
            addMinute(); // Handle cascading minute increment
        }
    }

    // --- Getter Methods (const) ---

    int getHour24() const {
        return hours;
    }

    int getMinute() const {
        return minutes;
    }

    int getSecond() const {
        return seconds;
    }

    /**
     * @return int - The hour in 12-hour format.
     * Handles 0 (midnight) and 12 (noon) correctly.
     */
    int getHour12() const {
        int h12 = hours % 12;
        return (h12 == 0) ? 12 : h12; // 0 and 12 should both display as 12 in 12hr format.
    }

    /**
     * @return string - "AM" or "PM"
     */
    string getAMPM() const {
        return (hours < 12) ? "AM" : "PM";
    }
};

// --- Helper Functions (to keep main() clean) ---

/**
 * Helper function to format an integer as a 2-digit string
 * (e.g., 7 -> "07")
 */
string twoDigit(int n) {
    stringstream ss;
    ss << setfill('0') << setw(2) << n;
    return ss.str();
}

/**
 * @brief Helper function to center a string within a given width.
 * @param text The string to center.
 * @param width The total width to center within.
 * @return A new string with padding on both sides.
 */
string center(string text, const int width) {
    int len = text.length();
    if (len >= width) {
        return text.substr(0, width); // Truncate if text is too long
    }

    int padLeft = (width - len) / 2;
    int padRight = width - len - padLeft;

    // Return a new string with padding
    return string(padLeft, ' ') + text + string(padRight, ' ');
}
/**
 * Displays both clocks simultaneously, per functional requirements.
 * Uses the getter methods from the ChadaClock object and the
 * center() helper function for clean, dynamic padding.
 * I had to watch several tutorials to figure out how to use this right. 
 * Many errors on the way to this functional project
 */
void displayClocks(const ChadaClock& clock) {
 //this is much cleaner than commented out version below. I didnt like the earlier one, but left it in here for posterity.
    // --- Define Box Properties ---
    const string border = "**************************";
    const int contentWidth = 24; // Width inside the border (26 stars - 2)

    // --- Get Time Components ---
    string h12 = twoDigit(clock.getHour12());
    string h24 = twoDigit(clock.getHour24());
    string min = twoDigit(clock.getMinute());
    string sec = twoDigit(clock.getSecond());
    string ampm = clock.getAMPM();

    // --- Format Time Strings ---
    string time12_str = h12 + ":" + min + ":" + sec + " " + ampm;
    string time24_str = h24 + ":" + min + ":" + sec;

    // --- Create Centered Content ---
    string title12 = center("12-Hour Clock", contentWidth);
    string title24 = center("24-Hour Clock", contentWidth);
    string blank = center("", contentWidth); // Just a blank line
    string time12 = center(time12_str, contentWidth);
    string time24 = center(time24_str, contentWidth);

    // --- Print The Clocks ---
    cout << border << "   " << border << endl;
    cout << "*" << title12 << "*" << "   " << "*" << title24 << "*" << endl;
    cout << "*" << blank << "*" << "   " << "*" << blank << "*" << endl;
    cout << "*" << time12 << "*" << "   " << "*" << time24 << "*" << endl;
    cout << "*" << blank << "*" << "   " << "*" << blank << "*" << endl;
    cout << border << "   " << border << endl;
}

/**
 * Displays both clocks simultaneously, per functional requirements.
 * Uses the getter methods from the ChadaClock object.
 */
//void displayClocks(const ChadaClock& clock) {
//    // Get all time components
//    string h12 = twoDigit(clock.getHour12()); // 12hr
//    string h24 = twoDigit(clock.getHour24()); // 24hr
//    string min = twoDigit(clock.getMinute());
//    string sec = twoDigit(clock.getSecond());
//    string ampm = clock.getAMPM();
//
//    // Clear the screen for a cleaner look (not a requirement, but 'professional' look)
//    // #ifdef _WIN32
//    // system("cls");
//    // #else
//    // system("clear");
//    // #endif
//
//    // Print clocks side-by-side as requested
//    cout << "**************************" << "   " << "**************************" << endl;
//    cout << "* 12-Hour Clock     *" << "   " << "* 24-Hour Clock     *" << endl;
//    cout << "* *" << "   " << "* *" << endl;
//    cout << "* " << h12 << ":" << min << ":" << sec << " " << ampm << "      *" << "   "
//        << "* " << h24 << ":" << min << ":" << sec << "         *" << endl;
//    cout << "* *" << "   " << "* *" << endl;
//    cout << "**************************" << "   " << "**************************" << endl;
//}

/**
 * Displays the user menu per requirements
 */
void displayMenu() {
    cout << "\n**************************" << endl;
    cout << "* 1 - Add One Hour         *" << endl;
    cout << "* 2 - Add One Minute       *" << endl;
    cout << "* 3 - Add One Second       *" << endl;
    cout << "* 4 - Exit Program         *" << endl;
    cout << "**************************" << endl;
    cout << "Enter your choice: ";
}

/**
 * Asks for and returns the user's timezone offset from UTC.
 * This is more because I wanted to know if I could do it. Not a requirement. Just a feature to stand out in the interview.
 */
int getTimezoneOffset() {
    int offset;
    cout << "Welcome to Chada Tech Clocks!" << endl;
    cout << "Please enter your timezone offset from UTC (e.g., -5 for EST, -6 for CST): ";

    // Basic input validation
    while (!(cin >> offset)) {
        cout << "Invalid input. Please enter a number (e.g., -5): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return offset;
}

/**
 * Gets the current system time (UTC), applies the user's offset,
 * and returns a new ChadaClock object.
 * STAND OUT FEATURE FOR INTERVIEW -- had to do research into chrono, hadn't seen it yet that I recall.
 */
ChadaClock getInitialTime(int timezoneOffset) {
    // Get current time from the system
    auto now = chrono::system_clock::now();
    time_t utc_time = chrono::system_clock::to_time_t(now);

    // Apply the user's timezone offset (in seconds)
    time_t local_time_t = utc_time + (timezoneOffset * 3600); // 3600 seconds in an hour

    // Convert to a tm struct. Use gmtime to avoid double-offsetting
    // (localtime would use the system's local timezone)
	tm* gmt = gmtime(&local_time_t); 
    //FIXME: No error checking for gmtime failure, but unlikely in this context.
	/*
        *instead of changing the variable, and potentially the behaviour or portability of the code, I asked copilot
	    *its opinion on how to handle gmtime failure, and it suggested in this use case, I could just proceed, 
        *as the likelihood of failure is low.
    */

    // Create and return the clock object
    return ChadaClock(gmt->tm_hour, gmt->tm_min, gmt->tm_sec);
}

/**
 * Handles the user's menu choice based on the flowchart.
 * Modifies the clock object by reference.
 */
void handleUserChoice(int choice, ChadaClock& clock) {
    switch (choice) {
    case 1: // Add Hour
        clock.addHour();
        break;
    case 2: // Add Minute
        clock.addMinute();
        break;
    case 3: // Add Second
        clock.addSecond();
        break;
    case 4: // Exit
        cout << "Exiting program. Goodbye." << endl;
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
        // Clear cin buffer in case of bad non-numeric input
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        break;
    }
    cout << endl; // Add a space before the next loop
}

// --- Main Program ---

int main() {
    // 1. Get user input for timezone 
    int offset = getTimezoneOffset();

    // 2. Get initial time based on real-time + offset 
    // This replaces the "Get User Input for Initial Time" from the flowchart, as a stand out feature for interview.
    ChadaClock clock = getInitialTime(offset);

    int choice = 0;

    // 3. Main program loop (follows flowchart)
    while (choice != 4) {
        // 4. Display Time
        displayClocks(clock);

        // 5. Display Menu
        displayMenu();

        // 6. Get User Input (for menu)
        cin >> choice;

        // 7. Handle Choice (Add Hour, Add Minute, Add Second, Exit)
        handleUserChoice(choice, clock);
    }

    return 0;
}