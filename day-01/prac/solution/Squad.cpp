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
        return currentTotal + newHours;
    }

    int incrementSessions(int currentCount) {
        return currentCount + 1;
    }

    double calculateAverage(double total, int count) {
        if (count == 0) {
            return 0.0;
        }
        return total / count;
    }

    double scaleHours(int hours, double factor) {
        return hours * factor;
    }

    // -------------------------------------------------------------------
    // Boolean Functions
    // -------------------------------------------------------------------

    bool isOnFire(int sessionsAttended) {
        return sessionsAttended >= 5;
    }

    bool isPassing(double quizAverage) {
        return quizAverage >= 50.0;
    }

    bool canTutor(double quizAverage, int sessionsAttended) {
        return quizAverage >= 75.0 && sessionsAttended >= 8;
    }

    // -------------------------------------------------------------------
    // Overloaded Function
    // -------------------------------------------------------------------

    void setReminder(int hours) {
        std::cout << "Reminder set for " << hours << "h" << std::endl;
    }

    void setReminder(int value, std::string unit) {
        int hours = value;
        if (unit == "minutes") {
            hours = value / 60;
        }
        std::cout << "Reminder set for " << hours << "h" << std::endl;
    }

    // -------------------------------------------------------------------
    // Report Function
    // -------------------------------------------------------------------

    void printSessionLog(std::string name, int sessions, int hours, double average) {
        std::cout << "-----SQUAD MEMBER LOG-----" << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Sessions: " << sessions << std::endl;
        std::cout << "Hours: " << hours << std::endl;
        std::cout << "Average: " << average << std::endl;
        std::cout << "--------------------------" << std::endl;
    }

    // -------------------------------------------------------------------
    // Orchestrator
    // -------------------------------------------------------------------

    bool processMember(std::string name, int sessions, int hours, double average) {
        printSessionLog(name, sessions, hours, average);
        bool fire = isOnFire(sessions);
        bool pass = isPassing(average);
        bool tutor = canTutor(average, sessions);
        std::cout << "On fire: " << fire << std::endl;
        std::cout << "Passing: " << pass << std::endl;
        std::cout << "Can tutor: " << tutor << std::endl;
        return fire && pass && tutor;
    }

}
