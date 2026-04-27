#include <iostream>
#include <string>
#include "Squad.h"

namespace SQUAD {

    // -------------------------------------------------------------------
    // Variables
    // -------------------------------------------------------------------

    std::string memberName = "";
    int totalHours = 0;
    int sessionsAttended = 0;
    double quizAverage = 0.0;

    // -------------------------------------------------------------------
    // Arithmetic Functions
    // -------------------------------------------------------------------

    int addHours(int currentTotal, int newHours) {
        // TODO: return the sum of currentTotal and newHours
        return 0;
    }

    int incrementSessions(int currentCount) {
        // TODO: return currentCount + 1
        return 0;
    }

    double calculateAverage(double total, int count) {
        // TODO: if count is 0, return 0.0
        // otherwise return total / count as a double
        return 0.0;
    }

    double scaleHours(int hours, double factor) {
        // TODO: return hours * factor as a double
        return 0.0;
    }

    // -------------------------------------------------------------------
    // Boolean Functions
    // -------------------------------------------------------------------

    bool isOnFire(int sessionsAttended) {
        // TODO: return true if sessionsAttended >= 5
        return false;
    }

    bool isPassing(double quizAverage) {
        // TODO: return true if quizAverage >= 50.0
        return false;
    }

    bool canTutor(double quizAverage, int sessionsAttended) {
        // TODO: return true if quizAverage >= 75.0 AND sessionsAttended >= 8
        return false;
    }

    // -------------------------------------------------------------------
    // Overloaded Function
    // -------------------------------------------------------------------

    void setReminder(int hours) {
        // TODO: print "Reminder set for {hours}h" followed by a newline
    }

    void setReminder(int value, std::string unit) {
        // TODO:
        // if unit is "minutes", convert value to hours by integer dividing by 60
        // if unit is "hours", use value as-is
        // then print "Reminder set for {hours}h" followed by a newline
    }

    // -------------------------------------------------------------------
    // Report Function
    // -------------------------------------------------------------------

    void printSessionLog(std::string name, int sessions, int hours, double average) {
        // TODO: print the six-line session log per the spec
    }

    // -------------------------------------------------------------------
    // Orchestrator
    // -------------------------------------------------------------------

    bool processMember(std::string name, int sessions, int hours, double average) {
        // TODO:
        // 1. call printSessionLog
        // 2. compute the three booleans
        // 3. print each on its own line ("On fire: ", "Passing: ", "Can tutor: ")
        // 4. return true if all three are true, otherwise false
        return false;
    }

}
