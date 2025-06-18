#pragma once
#include <vector>
#include <queue>
#include <set>
#include "RV.h"

class Dispatcher {
public:
    Dispatcher();
    void setGloballyDisabledSeats(const std::string& input);
    bool tryAssignGroup(int size);
    void deferGroup(int size);
    void dispatchAndReset();

private:
    std::vector<RV*> rvs;
    std::queue<int> deferredGroups;
    std::set<std::string> globallyDisabledSeats;
    int nextGuestId = 1;

    void initializeRVs();
    int availableSeats() const;
};
