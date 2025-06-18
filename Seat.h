#pragma once
#include <string>

class Seat {
public:
    Seat(std::string id);
    bool isAvailable() const;
    void assign(int guestId);
    void disable();
    void reset();
    std::string getId() const;
    std::string getStatus() const;
    std::string getDisplaySymbol() const;


private:
    std::string id;
    bool available;
    int guestId;
};
