#pragma once

#include <queue>
#include <iomanip>
#include "Process.h"
#include "RandomNum.h"

class ProcessorList
{
    public:

        std::priority_queue<Process> lowP_Process; //queue of low priority Process
        std::priority_queue<Process> highP_Process; //queue of high priority Process
        std::vector<Process> finishedProcess; //vector of treated Process ( this will be pushed when the patient is treated and sent back to the room)
        RandomNum *pushRandom; //Generates a new random nummber to push

    //Virtual Method Uptdate
    //Updates the room after every cycle
    virtual void update(int t) = 0;

    //Construtor
    //Input : ptr to Random class
    //Output : Creates a new ProcessorListList class whcih was the element pushRandom with random number
    ProcessorList(RandomNum *RandomNum)
    {
        pushRandom = RandomNum;
    }

};