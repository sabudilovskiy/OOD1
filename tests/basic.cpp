#include "All.hpp"
#include <gtest/gtest.h>
#include <sstream>

struct Student1 : IFioBirthDay{
    std::string GetFIO() override {
        return "SomeFIO1";
    }

    std::string GetBirthDay() override {
        return "BirthDay1";
    }
};

struct Student2 : Student1{
    std::string GetFIO() override {
        return "SomeFIO2";
    }

    std::string GetBirthDay() override {
        return "BirthDay2";
    }
};

TEST(basic_tests, test1){
    std::stringstream ss;
    auto student = Student1{};
    auto adapter = Adapter{student};
    Print(ss, adapter);
    EXPECT_EQ(ss.str(), "SomeFIO1 BirthDay1");
}

TEST(basic_tests, test2){
    std::stringstream ss;
    auto student = Student2{};
    auto adapter = Adapter{student};
    Print(ss, adapter);
    EXPECT_EQ(ss.str(), "SomeFIO2 BirthDay2");
}