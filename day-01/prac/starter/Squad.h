#ifndef Squad_h
#define Squad_h

#include <string>

namespace SQUAD {

    // -------------------------------------------------------------------
    // Variables
    // -------------------------------------------------------------------

    extern std::string memberName;
    extern int totalHours;
    extern int sessionsAttended;
    extern double quizAverage;

    // -------------------------------------------------------------------
    // Arithmetic Functions
    // -------------------------------------------------------------------

    // Returns the sum of currentTotal and newHours.
    int addHours(int currentTotal, int newHours);

    // Returns currentCount + 1.
    int incrementSessions(int currentCount);

    // Returns total / count as a double.
    // If count is 0, returns 0.0 to avoid division by zero.
    double calculateAverage(double total, int count);

    // Returns hours * factor as a double.
    double scaleHours(int hours, double factor);

    // -------------------------------------------------------------------
    // Boolean Functions
    // -------------------------------------------------------------------

    // Returns true if sessionsAttended >= 5.
    bool isOnFire(int sessionsAttended);

    // Returns true if quizAverage >= 50.0.
    bool isPassing(double quizAverage);

    // Returns true if quizAverage >= 75.0 AND sessionsAttended >= 8.
    bool canTutor(double quizAverage, int sessionsAttended);

    // -------------------------------------------------------------------
    // Overloaded Function
    // -------------------------------------------------------------------

    // Prints "Reminder set for {hours}h" followed by a newline.
    void setReminder(int hours);

    // If unit is "minutes", divides value by 60 (integer division).
    // If unit is "hours", uses value as-is.
    // Then prints in the same format as the single-argument version.
    void setReminder(int value, std::string unit);

    // -------------------------------------------------------------------
    // Report Function
    // -------------------------------------------------------------------

    // Prints a six-line session log in a strict format. See spec.
    void printSessionLog(std::string name, int sessions, int hours, double average);

    // -------------------------------------------------------------------
    // Orchestrator
    // -------------------------------------------------------------------

    // Calls printSessionLog, then prints the results of isOnFire,
    // isPassing and canTutor each on its own line.
    // Returns true if all three booleans are true.
    bool processMember(std::string name, int sessions, int hours, double average);

}

#endif
