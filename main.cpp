#include <iostream>
#include <vector>
#include <string>
#include "Dispatcher.h"

int main() {
    Dispatcher dispatcher;
    std::string input;
    int groupSize;

    std::cout << "Enter globally disabled seat IDs (comma-separated, e.g., Front-Left,Back-Right), or leave blank: ";
    std::getline(std::cin, input);
    dispatcher.setGloballyDisabledSeats(input);

    std::cout << "\nRide Seat Grouping App (Enter 0 to dispatch)\n";

    while (true) {
        std::cout << "\nEnter next party size (1-12) or 0 to dispatch: ";
        std::cin >> groupSize;
        if (groupSize == 0) {
            dispatcher.dispatchAndReset();
            continue;
        }
        if (groupSize < 1 || groupSize > 12) {
            std::cout << "Invalid group size.\n";
            continue;
        }
        if (!dispatcher.tryAssignGroup(groupSize)) {
            std::string choice;
            std::cout << "Not enough space to fit group of " << groupSize << ". Defer to next dispatch? (y/n): ";
            std::cin >> choice;
            if (choice == "y" || choice == "Y") {
                dispatcher.deferGroup(groupSize);
            } else {
                std::cout << "Group not assigned.\n";
            }
        }
    }
    return 0;
}
