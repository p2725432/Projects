#include <iostream>
using namespace std;

class TimeConverter {
    public:
        void secondsToHours();
        void secondsToMinutes();
        void minutesToHours();
        void hoursToSeconds();
        void minutesToSeconds();
};
//This a set of functions for converting between different units of time.//

void TimeConverter::secondsToHours() {
    int seconds;
    cout << "Enter time in seconds: ";
    cin >> seconds;
    double hours = static_cast<double>(seconds) / 3600;
    cout << seconds << " seconds = " << hours << " hours\n";
} 
//the "static_cast<double>(seconds)" is used to convert the integer seconds to a double value before dividing. Converts seconds into hours.//

void TimeConverter::secondsToMinutes() {
    int seconds;
    cout << "Enter time in seconds: ";
    cin >> seconds;
    double minutes = static_cast<double>(seconds) / 60;
    cout << seconds << " seconds = " << minutes << " minutes\n";
}

//Converts the input value from seconds to minutes by dividing it by 60 and storing the result in a double variable called minutes. The static_cast keyword is used to convert the seconds variable from an int to a double//

void TimeConverter::minutesToHours() {
    int minutes;
    cout << "Enter time in minutes: ";
    cin >> minutes;
    double hours = static_cast<double>(minutes) / 60;
    cout << minutes << " minutes = " << hours << " hours\n";
} 

//Converts the input value from minutes to hours by dividing it by 60 and storing the result in a double variable called minutes. The static_cast keyword is used to convert the seconds variable from an int to a double//

void TimeConverter::hoursToSeconds() {
    int hours;
    cout << "Enter time in hours: ";
    cin >> hours;
    int seconds = hours * 3600;
    cout << hours << " hours = " << seconds << " seconds\n";
}

//The function prompts the user to enter a value for hours, it then calculates the equivalent number of seconds by multiplying the number of hours by 3600 which is the number of seconds in an hour // 


void TimeConverter::minutesToSeconds() {
    int minutes;
    cout << "Enter time in minutes: ";
    cin >> minutes;
    int seconds = minutes * 60;
    cout << minutes << " minutes = " << seconds << " seconds\n";
}

//The function prompts the user to enter a value for hours, it then calculates the equivalent number of seconds by multiplying the number of minutes by 60 which is the number of seconds in an hour // 


int main() {
    TimeConverter tc;
    int choice;

    do {
        cout << "Select an option:\n";
        cout << "1. Convert seconds to hours\n";
        cout << "2. Convert seconds to minutes\n";
        cout << "3. Convert minutes to hours\n";
        cout << "4. Convert hours to seconds\n";
        cout << "5. Convert minutes to seconds\n";
        cout << "6. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                tc.secondsToHours();
                break;
            case 2:
                tc.secondsToMinutes();
                break;
            case 3:
                tc.minutesToHours();
                break;
            case 4:
                tc.hoursToSeconds();
                break;
            case 5:
                tc.minutesToSeconds();
                break;
            case 6:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
//The program presents a menu of options to the user and prompts the user to select an option by typing the corresponding number and then pressing the enter key. The program then uses a switch statement to determine which operation to execute based on the user's choice.//
    return 0;
}
