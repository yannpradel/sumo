#ifndef WRESTLER_H
#define WRESTLER_H
#include <iostream>
#include <stdio.h>

#include <memory>
#include <Person.h>


class Wrestler : public Person ///wrestler inherits from person (pt1)
{
    public:  ///all the constructor, destructor and methods are on public, the static int too (pt4)
        Wrestler(std::string name);
        Wrestler(int a);
        Wrestler();
        Wrestler(const Wrestler &a);
        ~Wrestler();
        void show(); ///the virtual function from the person class is implemented here (pt3)
        void win();
        void lose();
        void display_ratio();

        static int number_of_wrestlers; ///static states (pt16)


        int Getweight() { return m_weight; }
        void Setweight(int val) { m_weight = val; }
        std::string GetfavTechnique() { return m_favTechnique; }
        void SetfavTechnique(std::string val) { m_favTechnique = val; }
        int Getheight() { return m_height; }
        void Setheight(int val) { m_height = val; }
        std::string Getrank() { return m_rank; }
        void Setrank(std::string val) { m_rank = val; }
        float Getratio() { return m_ratio; }
        void Setratio(float val) { m_ratio = val; }
        float getWins(){return m_wins;}
        float getLoses(){return m_loses;}
        void setPositive(int a){m_positive=a;}


        ///we put a const object by reference (pt6)
        ///first overload operator, if we add two Wrestler, there wins will be add together(pt11)
        Wrestler operator+ (const Wrestler & first) const
        {
            return Wrestler(m_wins + first.m_wins);
        }


        ///second one, if two wrestler are equal, it means that they have the amount of wins(pt11)
        bool operator==(const Wrestler & first) const
        {
            if(m_wins == first.m_wins)
                return 1;
            else
                return 0;
        }


        ///overload the = operator, if we create a wrestler and make it equal to another one,
        ///it will takes name, wins, lose and ratio (pt12)
        Wrestler& operator= (const Wrestler& wrestler)
        {
            m_name = wrestler.m_name;
            m_wins = wrestler.m_wins;
            m_loses = wrestler.m_loses;
            m_ratio = wrestler.m_ratio;

            return *this;
        }




    protected:

        ///attributes are on private (pt4)

    private:
        int m_weight;
        std::string m_favTechnique;
        int m_height;
        std::string m_rank;
        float m_wins=6;
        float m_loses=5;
        float m_ratio=0;
        int m_positive=0;
};

#endif // WRESTLER_H
