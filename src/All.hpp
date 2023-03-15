#pragma once


#include <xstring>

namespace meta {
    template<typename T>
    concept CStream = requires(T t) {
        { t << std::string{}};
    };
}

struct IFioBirthDay{
    virtual std::string GetFIO() = 0;
    virtual std::string GetBirthDay() = 0;
};


struct IAll{
    virtual std::string GetAll() = 0;
};

struct Adapter : IAll{
    IFioBirthDay& i_fio_birth_day;
    Adapter(IFioBirthDay& i_fio_birth_day) : i_fio_birth_day(i_fio_birth_day){
    }
    std::string GetAll() override{
        return i_fio_birth_day.GetFIO() + " " + i_fio_birth_day.GetBirthDay();
    }
};

template<meta::CStream Stream>
void Print(Stream& stream, IAll& i_all){
    stream << i_all.GetAll();
}
