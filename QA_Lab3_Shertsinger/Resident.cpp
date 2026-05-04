#include "Resident.h"

Resident::Resident() : fullName(""), age(0) {}

Resident::Resident(const std::string& name, int residentAge) 
    : fullName(name), age(residentAge) {}

Resident::~Resident() {}

std::string Resident::getFullName() const { 
    return fullName; 
}

int Resident::getAge() const { 
    return age; 
}

void Resident::setAge(int newAge) { 
    age = newAge; 
}

bool Resident::isAdult() const { 
    return age >= 18; 
}

std::string Resident::toString() const {
    return fullName + ", Возраст: " + std::to_string(age);
}
