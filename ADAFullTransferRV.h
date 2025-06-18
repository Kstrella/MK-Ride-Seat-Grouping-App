#pragma once
#include "RV.h"

class ADAFullTransferRV : public RV {
public:
    ADAFullTransferRV(const std::set<std::string>& disabledSeats);
    void configureSeats(const std::set<std::string>& disabledSeats) override;
};
