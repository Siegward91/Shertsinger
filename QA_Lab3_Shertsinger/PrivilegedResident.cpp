/**
 * @file PrivilegedResident.cpp
 * @brief Реализация класса льготного жильца
 * @author Я.А. Шерцингер
 */

#include "PrivilegedResident.h"

PrivilegedResident::PrivilegedResident(const std::string& name, 
                                       int residentAge, 
                                       const std::string& category)
    : Resident(name, residentAge), privilegeCategory(category) {}

std::string PrivilegedResident::getPrivilegeCategory() const {
    return privilegeCategory;
}

bool PrivilegedResident::isAdult() const {
    // Для льготников порог снижен до 16 лет
    return age >= 16 || !privilegeCategory.empty();
}

std::string PrivilegedResident::toString() const {
    return fullName + ", Возраст: " + std::to_string(age) 
           + " (Льгота: " + privilegeCategory + ")";
}
