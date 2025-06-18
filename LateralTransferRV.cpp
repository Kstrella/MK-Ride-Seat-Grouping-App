#include "LateralTransferRV.h"

LateralTransferRV::LateralTransferRV(const std::set<std::string>& disabledSeats)
    : RV("Lateral Transfer") {
    configureSeats(disabledSeats);
}

void LateralTransferRV::configureSeats(const std::set<std::string>& disabledSeats) {
    seats = {
        Seat("Front-Left-LT"), Seat("Front-Right-LT"),
        Seat("Back-Left"), Seat("Back-Right")
    };
    for (auto& seat : seats)
        if (disabledSeats.count(seat.getId())) seat.disable();
}
