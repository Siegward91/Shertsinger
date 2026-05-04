#ifndef RESIDENT_H
#define RESIDENT_H

#include <string>

class Resident {
protected:
    std::string fullName;
    int age;

public:
    Resident();
    Resident(const std::string& name, int residentAge);
    virtual ~Resident();

    std::string getFullName() const;
    int getAge() const;
    void setAge(int newAge);

    virtual bool isAdult() const;
    virtual std::string toString() const;
};

#endif
