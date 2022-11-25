#include <iostream>
#include <Wrestler.h>
#include <Match.h>
#include <algorithm>
#include <memory>
Match* finished(Match* a);
void numberWrestler(int& c);
void display_tab(Wrestler wrestlers[3]);

Referee operator+ (const Referee & left, const Referee & right)
{
    return Referee(left.getValue() + right.getValue());
    ///left.getvalue() is returning the number of match judged
    ///the output is the sum of that + an int (pt17)
}

void test(std::unique_ptr<Wrestler> & ptr)
        {
            std::cout << "Function received smart pointer to object " << ptr->Get_name() << std::endl;
        }


void isPositive(Wrestler A){
    if(A.Getratio()>1)
        std::cout << A.Get_name() << " has more win than loss !\n";
    else
        std::cout << A.Get_name() << " has more loss than win...\n";
}

int Wrestler::number_of_wrestlers = 0;

int main()
{

    Referee R(0);
    ///we overload the '=' operator with int (pt17)
    R = R + 4;
    R.show_matches();

    const int number_of_wrestler = 7;
    Wrestler A("Terunofugi");
    Wrestler B("Tobizaru");
    Wrestler C("Takakeisho");
    Wrestler D("Wakatakakage");
    Wrestler E("Ura");
    Wrestler Copy;

    ///copy constructor instance
    Wrestler Copy_E(E);



    std::vector<Wrestler*> wrestlers;
    std::vector<Wrestler> wrestlers_objects;
    wrestlers.push_back(&A);
    wrestlers.push_back(&B);
    wrestlers.push_back(&C);
    wrestlers.push_back(&D);
    wrestlers.push_back(&E);



    Building Y;
    Stable Z;

    ///we create a child class and a parent class (pt10)

    Building *rootBul = &Y;
    rootBul->display_type();

    ///we create a pointer of building and put the adress of the object Y
    ///we then display (it takes the virtual method of the parent object)

    rootBul = &Z;
    rootBul->display_type();

    ///thanks to the virtual function, we can now change the type of rootBull
    ///and still have the child function executed (pt10)




    std::vector<Match*> matches;


    Match* m1 = new Match(&A,&C); ///we pass here two Wrestlers by reference (pt5)

    A.show();
    C.show();

    m1 = finished(m1); ///we pass here a Match object by value(pt5)
    m1->isFinished();

    matches.push_back(m1);

    Match* m2 = new Match(&D,&E); ///here is a pointer of object, we need to use new (pt7)

    D.show();
    E.show();

    m2 = finished(m2);
    m2->isFinished();

    matches.push_back(m2);

    Match* m3 = new Match(&B,&C);

    B.show();
    C.show();

    m3 = finished(m3);
    m3->isFinished();

    matches.push_back(m3);


    for (auto element : matches)
        element->show();

    for (auto elem : wrestlers)
        elem->display_ratio();

    Wrestler Both_Wins = C+E;
    std::cout << "Here is the number of the wins sum of " << C.Get_name() << " and " << E.Get_name() << std::endl;
    std::cout << C.getWins() << " + " << E.getWins() << std::endl;
    std::cout << Both_Wins.getWins() << std::endl;

    if(C==E)
        std::cout << "C and E has the same amount of wins\n";
    else
        std::cout << "C and E has not the same amount of wins\n";

    Copy = C = D;
    Copy = C;
    std::cout << "Name of the copy wrestler : " << Copy.Get_name() << std::endl;

    std::cout << C.Get_name() << D.Get_name() << std::endl << std::endl;

    ///creator by copy

    std::cout << Copy_E.Get_name();
    std::cout << std::endl << std::endl;

    Match* m4 = new Match(&Copy_E,&C);

    Copy_E.show();
    C.show();

    m3 = finished(m3);
    m3->isFinished();

    float f = C.Getratio()+D.Getratio();
    std::cout << f << " is float sum of ratio of " << C.Get_name() << " and " << D.Get_name() << "\n\n\n";

    int x = static_cast<int>(f);
    ///We have a float and we want to make a sum of it but with an int pt(15)

    std::cout << "We want an int sum of ratio : " << x << std::endl << std::endl;

    ///const static pt(15)

    numberWrestler(*const_cast<int*>(&number_of_wrestler));
    std::cout << "real value of number of wrestler : " << number_of_wrestler << std::endl << std::endl;

    ///static member class

    std::cout << "Another real number of wrestler : " << Wrestler::number_of_wrestlers << std::endl;

    ///using a for each algorithm to see if each wrestler is positive or not

    wrestlers_objects.push_back(A);
    wrestlers_objects.push_back(B);
    wrestlers_objects.push_back(C);
    wrestlers_objects.push_back(D);
    wrestlers_objects.push_back(E);

    std::for_each(wrestlers_objects.begin(), wrestlers_objects.end(), isPositive);
    ///a simple for each algorithm (pt19)

    ///smart pointer (pt20)

    std::unique_ptr<Wrestler> p(new Wrestler("Hakuho"));
	test(p);

	 Wrestler w_tab[3]; ///we have an array of pointers of objects (pt8)

     w_tab [0] = A;
     w_tab [1] = B;
     w_tab [2] = C;

    display_tab(w_tab); ///we display them



    delete m1;
    delete m2; ///we need to delete pointer object at the end of the program (pt7)
    delete m3;


    return 0;
}

///we put the match object and then return it (pt13)
Match* finished(Match* match)
{
    match->setFinished(true);
    return match;
    ///we need to return a match because it won't take any changes otherwise (pt5)
}

void numberWrestler(int& a)
{
    std::cout << "we want to have one more wrestler here\n";
    a++;
    std::cout << a << std::endl << std::endl;
}

void display_tab(Wrestler wrestlers[3])
{
    for (int i=0; i<3 ; i++)
        std::cout << wrestlers[i].Get_name() << " is the " << i << " wrestler's name\n";

    ///we display all elements from the array
}
