#include "Seat.h"

Seat::Seat(std::string id) : id(id), available(true), guestId(-1) {}

bool Seat::isAvailable() const {
    return available && guestId == -1;
}

void Seat::assign(int guestId) {
    if (isAvailable()) this->guestId = guestId;
}

void Seat::disable() {
    available = false;
}

void Seat::reset() {
    if (available) guestId = -1;
}

std::string Seat::getId() const {
    return id;
}

std::string Seat::getStatus() const {
    if (!available) return "DISABLED";
    if (guestId == -1) return "EMPTY";
    return "GUEST " + std::to_string(guestId);
}
