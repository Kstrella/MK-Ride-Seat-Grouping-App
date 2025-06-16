#ifndef SEAT_H
#define SEAT_H
#include <string>

class Seat {
private:
    bool disabled;
    bool occupied;
    std::string position;

public:
    Seat(std::string pos, bool isDisabled = false);
    bool isAvailable() const;
    bool isOccupied() const;
    void assign();
    void disable();
    void enable();
    std::string getPosition() const;
};

#endif
