#include "Match.h"

Match::Match(Wrestler* A, Wrestler* B)
{
    ///the value of A and B are getting changed thanks to reference (pt5)
    if(A->Get_name() < B->Get_name())
    {
        A->win();
        B->lose();
    }
    else
    {
        A->lose();
        B->win();
    }
    m_wrestlers.push_back(A);
    m_wrestlers.push_back(B);
}

Match::~Match()
{
    std::cout << "Match is deleted\n";
}

void Match::isFinished()
{
    if(m_finished==true)
        std::cout << "Match is over\n";
    else
        std::cout << "Match is not over\n";
}

void Match::show()
{
    std::cout << "-------------- We have " << m_wrestlers[0]->Get_name() << " against " << m_wrestlers[1]->Get_name() << " ---------------\n\n";
}
