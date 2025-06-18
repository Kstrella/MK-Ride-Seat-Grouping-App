#pragma once
#include "RV.h"

class LateralTransferRV : public RV {
public:
    LateralTransferRV(const std::set<std::string>& disabledSeats);
    void configureSeats(const std::set<std::string>& disabledSeats) override;
};
