/**
 * @file Resident.h
 * @brief Базовый класс жильца дома
 * @author Я.А. Шерцингер
 * @version 1.0
 */

#ifndef RESIDENT_H
#define RESIDENT_H

#include <string>

/**
 * @class Resident
 * @brief Базовый класс, представляющий жильца дома
 * 
 * Хранит ФИО и возраст жильца. Является базовым классом
 * для иерархии наследования. Содержит виртуальные методы
 * для полиморфного поведения.
 * \image html image.png "Иерархия классов"
 */
class Resident {
protected:
    std::string fullName;  ///< Фамилия, имя, отчество жильца
    int age;               ///< Возраст жильца в годах

public:
    Resident();
    Resident(const std::string& name, int residentAge);
    virtual ~Resident();

    std::string getFullName() const;
    int getAge() const;
    void setAge(int newAge);

    /**
    * @brief Проверить, является ли жилец совершеннолетним
    * 
    * Совершеннолетие определяется по формуле:
    * \f[
    * \mathbf{isAdult = (age >= 18)}
    * \f]
    * 
    * @return true если возраст >= 18, иначе false
    */
    virtual bool isAdult() const;

    virtual std::string toString() const;
};

#endif
