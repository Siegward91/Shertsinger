#ifndef PRIVILEGEDRESIDENT_H
#define PRIVILEGEDRESIDENT_H

#include "Resident.h"

class PrivilegedResident : public Resident {
private:
    std::string privilegeCategory;

public:
    PrivilegedResident(const std::string& name, int residentAge, 
                       const std::string& category);

    std::string getPrivilegeCategory() const;

    bool isAdult() const override;

    std::string toString() const override;
};

#endif
