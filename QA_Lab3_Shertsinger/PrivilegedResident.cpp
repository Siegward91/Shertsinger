#include "PrivilegedResident.h"

PrivilegedResident::PrivilegedResident(const std::string& name, 
                                       int residentAge, 
                                       const std::string& category)
    : Resident(name, residentAge), privilegeCategory(category) {}

std::string PrivilegedResident::getPrivilegeCategory() const {
    return privilegeCategory;
}

bool PrivilegedResident::isAdult() const {
    return age >= 16 || !privilegeCategory.empty();
}

std::string PrivilegedResident::toString() const {
    return fullName + ", Возраст: " + std::to_string(age) 
           + " (Льгота: " + privilegeCategory + ")";
}
