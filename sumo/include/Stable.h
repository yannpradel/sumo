#ifndef STABLE_H
#define STABLE_H

#include <iostream>
#include <stdio.h>

#include <Building.h>


class Stable : public Building
{
    public:
        Stable();
        ~Stable();
        void display_type();

        std::string Getname() { return m_name; }
        void Setname(std::string val) { m_name = val; }
        std::string Getichimon() { return m_ichimon; }
        void Setichimon(std::string val) { m_ichimon = val; }
        int GetyearOpened() { return m_yearOpened; }
        void SetyearOpened(int val) { m_yearOpened = val; }

    protected:

    private:
        std::string m_name;
        std::string m_ichimon;
        int m_yearOpened;
};

#endif // STABLE_H
