#include "Dispatcher.h"
#include "ADAFullTransferRV.h"
#include "LateralTransferRV.h"
#include "RegularRV.h"
#include <iostream>
#include <sstream>

Dispatcher::Dispatcher() {
    initializeRVs();
}

void Dispatcher::initializeRVs() {
    for (auto* rv : rvs) delete rv;
    rvs.clear();
    rvs.push_back(new ADAFullTransferRV(globallyDisabledSeats));
    rvs.push_back(new LateralTransferRV(globallyDisabledSeats));
    rvs.push_back(new RegularRV(globallyDisabledSeats));
    rvs.push_back(new RegularRV(globallyDisabledSeats));
}

void Dispatcher::setGloballyDisabledSeats(const std::string& input) {
    std::stringstream ss(input);
    std::string seatId;
    while (std::getline(ss, seatId, ',')) {
        if (!seatId.empty()) {
            globallyDisabledSeats.insert(seatId);
        }
    }
}

bool Dispatcher::tryAssignGroup(int size) {
    if (size > availableSeats()) return false;

    int assigned = 0;
    for (auto* rv : rvs) {
        while (assigned < size && rv->assignGuest(nextGuestId)) {
            assigned++;
            nextGuestId++;
        }
        if (assigned == size) return true;
    }

    return assigned == size;
}

void Dispatcher::deferGroup(int size) {
    deferredGroups.push(size);
}

void Dispatcher::dispatchAndReset() {
    std::cout << "\n=== DISPATCHING RVs ===\n";
    for (auto* rv : rvs) rv->display();

    initializeRVs();
    for (auto size = deferredGroups.size(); size-- > 0;) {
        int group = deferredGroups.front();
        deferredGroups.pop();
        if (!tryAssignGroup(group)) {
            deferredGroups.push(group);
        }
    }
    std::cout << "\nRVs Reset for Next Dispatch.\n";
}

int Dispatcher::availableSeats() const {
    int total = 0;
    for (auto* rv : rvs) total += rv->availableSeatCount();
    return total;
}
