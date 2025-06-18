#pragma once
#include <vector>
#include <string>
#include <set>
#include "Seat.h"

class RV {
public:
    RV(std::string type);
    virtual ~RV() = default;
    virtual void configureSeats(const std::set<std::string>& disabledSeats) = 0;
    bool assignGuest(int guestId);
    void disableSeat(const std::string& seatId);
    void display() const;
    void resetSeats();
    int availableSeatCount() const;
    std::string getType() const;
    virtual void printSeatLayout(int rvNumber) const;

protected:
    std::vector<Seat> seats;
    std::string type;
};
