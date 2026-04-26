#pragma once
#include <string>
#include <vector>

class Calculator {
public:
    double add(double a, double b);
    double subtract(double a, double b);
    double multiply(double a, double b);
    double divide(double a, double b);
    double power(double base, double exponent);
    long long factorial(int n);
    double average(const std::vector<double>& numbers);
    void memoryStore(double value);
    void memoryClear();
    double memoryRecall() const;
    void addToHistory(const std::string& operation);
    std::vector<std::string> getHistory() const;
    void clearHistory();

private:
    double memory = 0.0;
    std::vector<std::string> history;
};