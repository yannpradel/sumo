#include "Wrestler.h"

Wrestler::Wrestler(std::string name)
{
    m_name=name;
    number_of_wrestlers++; ///the static state will be incremented every new creation of wrestler (pt16)
}

Wrestler::Wrestler(int a)
{
    m_wins=a;
    number_of_wrestlers++;
}

Wrestler::Wrestler()
{
    number_of_wrestlers++;
}

///copy constructor (pt14)
Wrestler::Wrestler(const Wrestler& wrestler)
{
    m_name = wrestler.m_name;
    m_wins = wrestler.m_wins;
    m_loses = wrestler.m_loses;
    m_ratio = wrestler.m_ratio;
}


Wrestler::~Wrestler()
{
    std::cout << Get_name() << " is destroyed\n"; ///when the wrestler is getting destroyed, a message appears (pt9)
}

///we have a lot of differents methods to make the project more interesting (pt16)

void Wrestler::show()
{
    std::cout << "Here is all information about " << Get_name() << std::endl;
    std::cout << "wins : " << getWins() << " loses : " << getLoses() << std::endl;
}

void Wrestler::win()
{
    m_wins++;
    if(m_loses == 0)
        m_ratio = m_wins;
    else
        m_ratio = float(m_wins/m_loses);

}

void Wrestler::lose()
{
    m_loses++;
    if(m_loses == 0)
        m_ratio = m_wins;
    else
        m_ratio = float(m_wins/m_loses);

}

void Wrestler::display_ratio()
{
    std::cout << "Ratio of " << m_name << " is " << m_ratio << std::endl;
}



