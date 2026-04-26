#include <gtest/gtest.h>
#include "calculator.h"
#include <stdexcept>

TEST(CalculatorTest, Addition) {
    Calculator calc;
    EXPECT_DOUBLE_EQ(calc.add(5.0, 3.0), 8.0);
    EXPECT_DOUBLE_EQ(calc.add(-2.0, 7.0), 5.0);
}

TEST(CalculatorTest, Subtraction) {
    Calculator calc;
    EXPECT_DOUBLE_EQ(calc.subtract(10.0, 4.0), 6.0);
    EXPECT_DOUBLE_EQ(calc.subtract(0.0, 5.0), -5.0);
}

TEST(CalculatorTest, Multiplication) {
    Calculator calc;
    EXPECT_DOUBLE_EQ(calc.multiply(3.0, 4.0), 12.0);
    EXPECT_DOUBLE_EQ(calc.multiply(-2.0, 6.0), -12.0);
}

TEST(CalculatorTest, Division) {
    Calculator calc;
    EXPECT_DOUBLE_EQ(calc.divide(10.0, 2.0), 5.0);
    EXPECT_THROW(calc.divide(5.0, 0.0), std::invalid_argument);
}

TEST(CalculatorTest, Power) {
    Calculator calc;
    EXPECT_DOUBLE_EQ(calc.power(2.0, 3.0), 8.0);
    EXPECT_DOUBLE_EQ(calc.power(5.0, 0.0), 1.0);
}

TEST(CalculatorTest, Factorial) {
    Calculator calc;
    EXPECT_EQ(calc.factorial(5), 120);
    EXPECT_EQ(calc.factorial(0), 1);
    EXPECT_THROW(calc.factorial(-3), std::invalid_argument);
}

TEST(CalculatorTest, Average) {
    Calculator calc;
    EXPECT_DOUBLE_EQ(calc.average({ 2.0, 4.0, 6.0 }), 4.0);
    EXPECT_THROW(calc.average({}), std::invalid_argument);
}

TEST(CalculatorTest, MemoryOperations) {
    Calculator calc;
    calc.memoryStore(42.5);
    EXPECT_DOUBLE_EQ(calc.memoryRecall(), 42.5);
    calc.memoryClear();
    EXPECT_DOUBLE_EQ(calc.memoryRecall(), 0.0);
}

TEST(CalculatorTest, History) {
    Calculator calc;
    calc.add(1.0, 2.0);
    calc.subtract(5.0, 3.0);
    auto history = calc.getHistory();
    EXPECT_EQ(history.size(), 2);
    calc.clearHistory();
    EXPECT_TRUE(calc.getHistory().empty());
}

TEST(CalculatorTest, CombinedOperations) {
    Calculator calc;
    double result = calc.add(10.0, 5.0);
    result = calc.divide(result, 3.0);
    EXPECT_DOUBLE_EQ(result, 5.0);
    auto history = calc.getHistory();
    EXPECT_EQ(history.size(), 2);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}