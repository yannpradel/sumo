#ifndef MATCH_H
#define MATCH_H
#include <iostream>
#include <stdio.h>
#include <vector>
#include <Wrestler.h>
#include <Referee.h>

class Referee;
class Match
{
    public:
        Match(Wrestler* A, Wrestler* B);
        ~Match();

        void show();

        std::vector<Wrestler*> Getwrestlers() { return m_wrestlers; }
        void Setwrestlers(std::vector<Wrestler*> val) { m_wrestlers = val; }
        Referee Getreferee() { return m_referee; }
        void Setreferee(Referee val) { m_referee = val; }

        void setFinished(bool a){m_finished = a;}
        void isFinished();

    protected:

    private:
        std::vector<Wrestler*> m_wrestlers;
        Referee m_referee;
        bool m_finished=false;
};

#endif // MATCH_H
