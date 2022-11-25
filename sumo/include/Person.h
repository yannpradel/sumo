#ifndef PERSON_H
#define PERSON_H
#include <stdio.h>
#include <iostream>
#include <Stable.h>

class Stable;

class Person ///this class here is absract (pt3)
{
    public:
        Person();
        virtual ~Person();
        virtual void show() = 0; ///this virtual function makes the class abstract (pt3)


        std::string Get_name() { return m_name; }
        void Set_name(std::string val) { m_name = val; }
        int Getage() { return m_age; }
        void Setage(int val) { m_age = val; }
        std::string Get_nationality() { return m_nationality; }
        void Set_nationality(std::string val) { m_nationality = val; }
        std::string Get_division() { return m_division; }
        void Set_division(std::string val) { m_division = val; }
        Stable Getstable() { return m_stable; }
        void Setstable(Stable val) { m_stable = val; }

    protected: ///attribute from abstract class are on protected (pt4)
        std::string m_name;
        int m_age;
        std::string m_nationality;
        std::string m_division;
        Stable m_stable;

    private:

};

#endif // PERSON_H
