/**
 * @file House.cpp
 * @brief Реализация класса House
 * @author Я.А. Шерцингер
 */

#include "House.h"
#include <iostream>

House::House(int number) : houseNumber(number) {}

House::~House() {
    for (Resident* r : residents) {
        delete r;
    }
}

int House::getHouseNumber() const { 
    return houseNumber; 
}

void House::addResident(const std::string& name, int age) {
    residents.push_back(new Resident(name, age));
}

void House::addPrivilegedResident(const std::string& name, int age, 
                                   const std::string& category) {
    residents.push_back(new PrivilegedResident(name, age, category));
}

int House::getResidentCount() const { 
    return static_cast<int>(residents.size()); 
}

Resident* House::getResident(int index) const {
    if (index >= 0 && index < static_cast<int>(residents.size())) {
        return residents[index];
    }
    return nullptr;
}

Resident* House::findOldestResident() const {
    if (residents.empty()) return nullptr;
    
    Resident* oldest = residents[0];
    for (Resident* r : residents) {
        if (r->getAge() > oldest->getAge()) {
            oldest = r;
        }
    }
    return oldest;
}

int House::countUnderage() const {
    int count = 0;
    for (Resident* r : residents) {
        if (!r->isAdult()) {
            count++;
        }
    }
    return count;
}

void House::printInfo() const {
    std::cout << "Дом №" << houseNumber 
              << ", жильцов: " << residents.size() << std::endl;
    for (size_t i = 0; i < residents.size(); i++) {
        std::cout << "  " << (i + 1) << ". " 
                  << residents[i]->toString() << std::endl;
    }
}
