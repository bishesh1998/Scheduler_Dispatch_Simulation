#pragma once

#include <cstdlib>
#include <ctime>

class RandomNum
{
public:

    //Emnpty Constructor
    RandomNum() {
        //srand((unsigned int)std::time(0));
        srand((unsigned int)std::time(0)); //psedo random number asigned by seeding the time
    }

    //Constructor
    //Input : Seed for the pseudo random number 
    RandomNum(int seed)
    {
        srand(seed); //psedo RandomNum number asigned by seed provided 
    }

    //Method to generate new RandomNum number by using "n" as the seed 
    //Calls the next_double method to get the RandomNum ratio
    //Returns new RandomNum numnber (will always be less than the inputed number)
    int next_int(int n)
    {
        return int(next_double() * n);
    }
    

    //Method to generate a number integer to with range r
    int randIntRange(int r)
    {
        return int(rand() % r); //returns the RandomNum number
    }

    //Method set the next double integer
    double next_double()
    {
        return double(rand()) / RAND_MAX; //returns the ratio of any RandomNum by the max RandomNum number in the problem (*this will always be less than 1)
    }
    

    //Method to set generate priority number
    //Cases :
    //Case 1 : Generates RandomNum number between 1 - 10
    //Case 2 : Generates RandomNum number between 11 - 15
    //Case 1 : Generates RandomNum number between 16 - 20
    int rand_priority()
    {
        int probability = (rand() % 10) + 1; //Generates RandomNum number for each cases
        if (probability >= 4) //Case 1 : Generates RandomNum number between 1 - 10
        {
            return (rand() % 10) + 1;
        }
        if (probability >= 2) //Case 2 : Generates RandomNum number between 11 - 15
        {
            return (rand() % 5) + 11;
        }
        if (probability == 1) //Case 3 : Generates RandomNum number between 16 - 20
        {
            return (rand() % 5) + 16;
        }
        return 1; //Default will always be 1 priority
    }

};