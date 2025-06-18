#pragma once
#include "RV.h"

class RegularRV : public RV {
public:
    RegularRV(const std::set<std::string>& disabledSeats);
    void configureSeats(const std::set<std::string>& disabledSeats) override;
};
