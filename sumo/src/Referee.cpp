#include "Referee.h"

Referee::Referee(int b)
{
    m_nb_matches=b;
}

Referee::Referee()
{

}

Referee::~Referee()
{
    //dtor
}

void Referee::show()
{
    std::cout << "Here is all information about " << Get_name();
}

void Referee::show_matches()
{
    std::cout << "This referee has done " << m_nb_matches << " matches\n\n";
}




