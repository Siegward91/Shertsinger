/**
 * @file PrivilegedResident.h
 * @brief Производный класс льготного жильца
 * @author Я.А. Шерцингер
 * @version 1.0
 */

#ifndef PRIVILEGEDRESIDENT_H
#define PRIVILEGEDRESIDENT_H

#include "Resident.h"

/**
 * @class PrivilegedResident
 * @brief Класс жильца, имеющего льготы
 * 
 * Наследуется от Resident. Добавляет категорию льготы
 * и переопределяет метод isAdult().
 * Для льготных категорий порог совершеннолетия снижен до 16 лет.
 */
class PrivilegedResident : public Resident {
private:
    std::string privilegeCategory;  ///< Категория льготы

public:
    /**
     * @brief Конструктор льготного жильца
     * @param name ФИО
     * @param residentAge Возраст
     * @param category Категория льготы
     */
    PrivilegedResident(const std::string& name, int residentAge, 
                       const std::string& category);

    /**
     * @brief Получить категорию льготы
     * @return Строка с категорией
     */
    std::string getPrivilegeCategory() const;

    /**
     * @brief Переопределённая проверка совершеннолетия
     * 
     * Льготники считаются взрослыми с 16 лет.
     * @return true если возраст >= 16 или есть льгота
     */
    bool isAdult() const override;

    /**
     * @brief Строковое представление с указанием льготы
     * @return Строка вида "ФИО, Возраст (Льгота: категория)"
     */
    std::string toString() const override;
};

#endif
