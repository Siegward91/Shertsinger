#ifndef HOUSE_H
#define HOUSE_H

#include "Resident.h"
#include "PrivilegedResident.h"
#include <vector>

class House {
private:
    int houseNumber;
    std::vector<Resident*> residents;

public:
    House(int number);
    ~House();

    int getHouseNumber() const;

    void addResident(const std::string& name, int age);

    void addPrivilegedResident(const std::string& name, int age, 
                               const std::string& category);

    int getResidentCount() const;

    Resident* getResident(int index) const;

    Resident* findOldestResident() const;

    int countUnderage() const;

    void printInfo() const;
};

#endif
