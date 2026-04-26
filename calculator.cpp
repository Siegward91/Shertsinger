#include "calculator.h"
#include <stdexcept>
#include <cmath>
#include <numeric>

double Calculator::add(double a, double b) {
    addToHistory("add(" + std::to_string(a) + ", " + std::to_string(b) + ")");
    return a + b;
}

double Calculator::subtract(double a, double b) {
    addToHistory("subtract(" + std::to_string(a) + ", " + std::to_string(b) + ")");
    return a - b;
}

double Calculator::multiply(double a, double b) {
    addToHistory("multiply(" + std::to_string(a) + ", " + std::to_string(b) + ")");
    return a * b;
}

double Calculator::divide(double a, double b) {
    if (b == 0.0) throw std::invalid_argument("Division by zero");
    addToHistory("divide(" + std::to_string(a) + ", " + std::to_string(b) + ")");
    return a / b;
}

double Calculator::power(double base, double exponent) {
    addToHistory("power(" + std::to_string(base) + ", " + std::to_string(exponent) + ")");
    return std::pow(base, exponent);
}

long long Calculator::factorial(int n) {
    if (n < 0) throw std::invalid_argument("Factorial of negative number is undefined");
    if (n > 20) throw std::overflow_error("Factorial result too large for long long");
    addToHistory("factorial(" + std::to_string(n) + ")");
    long long result = 1;
    for (int i = 2; i <= n; ++i) result *= i;
    return result;
}

double Calculator::average(const std::vector<double>& numbers) {
    if (numbers.empty()) throw std::invalid_argument("Cannot calculate average of empty vector");
    addToHistory("average(vector size " + std::to_string(numbers.size()) + ")");
    double sum = std::accumulate(numbers.begin(), numbers.end(), 0.0);
    return sum / numbers.size();
}

void Calculator::memoryStore(double value) { memory = value; }
void Calculator::memoryClear() { memory = 0.0; }
double Calculator::memoryRecall() const { return memory; }
void Calculator::addToHistory(const std::string& operation) { history.push_back(operation); }
std::vector<std::string> Calculator::getHistory() const { return history; }
void Calculator::clearHistory() { history.clear(); }