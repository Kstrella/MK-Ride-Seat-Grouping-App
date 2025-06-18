#include "RegularRV.h"

RegularRV::RegularRV(const std::set<std::string>& disabledSeats)
    : RV("Regular") {
    configureSeats(disabledSeats);
}

void RegularRV::configureSeats(const std::set<std::string>& disabledSeats) {
    seats = {
        Seat("Front-Left"), Seat("Front-Right"),
        Seat("Back-Left"), Seat("Back-Right")
    };
    for (auto& seat : seats)
        if (disabledSeats.count(seat.getId())) seat.disable();
}
