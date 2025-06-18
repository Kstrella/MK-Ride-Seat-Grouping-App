#include "ADAFullTransferRV.h"

ADAFullTransferRV::ADAFullTransferRV(const std::set<std::string>& disabledSeats)
    : RV("ADA Full Transfer") {
    configureSeats(disabledSeats);
}

void ADAFullTransferRV::configureSeats(const std::set<std::string>& disabledSeats) {
    seats = { Seat("Front-Wheelchair"), Seat("Back-Left"), Seat("Back-Right") };
    for (auto& seat : seats)
        if (disabledSeats.count(seat.getId())) seat.disable();
}
