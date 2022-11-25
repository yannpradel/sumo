#ifndef REFEREE_H
#define REFEREE_H
#include <iostream>
#include <stdio.h>


#include <Person.h>


class Referee : public Person ///referee inherits from person (pt1)
{
    public:
        Referee();
        Referee(int b);
        ~Referee();
        void show(); ///the virtual function from the person class is implemented here (pt3)


        std::string Getcolour() { return m_colour; }
        void Setcolour(std::string val) { m_colour = val; }

        int getValue() const {return m_nb_matches;}
        void show_matches();

    protected:

    private:
        std::string m_colour;
        int m_nb_matches=0;
};

#endif // REFEREE_H
