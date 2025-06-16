# MK Ride Seat Grouping App
This project is a C++ application designed using Object-Oriented Programming (OOP) principles to manage and optimize ride seat assignments for parties of 1–12 guests. The ride dispatches 4 RVs at a time, each with 4 seats (2 in the front and 2 in the back). The application uses class inheritance and modular design with separate files for each RV type to ensure clean, maintainable code.
Key Features:
Party Grouping Logic: Users input a party size (1–12), and the app intelligently assigns seats across the dispatched RVs, providing a clear seat map indicating where each guest should sit.


RV Types:


Regular RV: Supports 4 guests (2 front, 2 back).


Lateral Transfer RV: Supports 4 guests with front seats accessible via lateral transfer.


ADA Full Transfer RV: Supports 3 guests — 1 wheelchair-accessible front seat and 2 standard back seats.


Seat Disabling Feature: Certain seats can be dynamically disabled (e.g., due to possible issues with the specific seat). Disabled seats are automatically skipped during guest assignment, ensuring guest safety and experience without manual intervention.


Extensible Class Design:


Base RV class with polymorphic behavior for seat configuration and assignment.


Derived classes like RegularRV, LateralTransferRV, and ADAFullTransferRV implement seat behavior specific to their type.


Encapsulation ensures each RV manages its own seat state and reporting.


Objective:
To assist ride operators by providing a reliable, easy-to-use tool that visually displays how to group incoming guest parties into the available RVs while accounting for accessibility needs and seat restrictions.
