#include "Seat.h"

Seat::Seat(std::string pos, bool isDisabled)
    : position(pos), disabled(isDisabled), occupied(false) {}

bool Seat::isAvailable() const {
    return !disabled && !occupied;
}

bool Seat::isOccupied() const {
    return occupied;
}

void Seat::assign() {
    if (isAvailable()) occupied = true;
}

void Seat::disable() {
    disabled = true;
}

void Seat::enable() {
    disabled = false;
}

std::string Seat::getPosition() const {
    return position;
}
