/**
 * @file House.h
 * @brief Класс, представляющий дом с жильцами
 * @author Я.А. Шерцингер
 * @version 1.0
 */

#ifndef HOUSE_H
#define HOUSE_H

#include "Resident.h"
#include "PrivilegedResident.h"
#include <vector>

/**
 * @class House
 * @brief Класс для хранения данных о доме и его жильцах
 * 
 * Содержит номер дома и полиморфный список жильцов.
 * Поддерживает добавление обычных и льготных жильцов,
 * поиск самого старшего, подсчёт несовершеннолетних.
 * 
 * \image html house_structure.png "Структура класса House"
 */
class House {
private:
    int houseNumber;                        ///< Номер дома
    std::vector<Resident*> residents;       ///< Список жильцов

public:
    /**
     * @brief Конструктор
     * @param number Номер дома
     */
    House(int number);

    /**
     * @brief Деструктор, освобождает память
     */
    ~House();

    int getHouseNumber() const;
    void addResident(const std::string& name, int age);
    void addPrivilegedResident(const std::string& name, int age, 
                               const std::string& category);
    int getResidentCount() const;
    Resident* getResident(int index) const;

    /**
     * @brief Найти самого старшего жильца
     * 
     * Формула: \f$ maxAge = \max_{i=1}^{n} age_i \f$
     * @return Указатель на самого старшего жильца
     */
    Resident* findOldestResident() const;

    /**
     * @brief Посчитать количество несовершеннолетних
     * @return Количество жильцов младше 18 (обычные) или 16 (льготники)
     */
    int countUnderage() const;

    void printInfo() const;
};

#endif
