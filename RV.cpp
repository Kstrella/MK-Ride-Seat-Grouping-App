#include "RV.h"
#include <iostream>

RV::RV(std::string type) : type(type) {}

bool RV::assignGuest(int guestId) {
    for (auto& seat : seats) {
        if (seat.isAvailable()) {
            seat.assign(guestId);
            return true;
        }
    }
    return false;
}

void RV::disableSeat(const std::string& seatId) {
    for (auto& seat : seats) {
        if (seat.getId() == seatId) {
            seat.disable();
            break;
        }
    }
}

void RV::display() const {
    std::cout << type << " RV:\n";
    for (const auto& seat : seats) {
        std::cout << "  Seat " << seat.getId() << ": " << seat.getStatus() << "\n";
    }
}

void RV::resetSeats() {
    for (auto& seat : seats) seat.reset();
}

int RV::availableSeatCount() const {
    int count = 0;
    for (const auto& seat : seats)
        if (seat.isAvailable()) count++;
    return count;
}

std::string RV::getType() const {
    return type;
}
