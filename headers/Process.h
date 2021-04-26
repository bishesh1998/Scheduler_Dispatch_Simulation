#pragma once

#include "../headers/RandomNum.h"

//process class
class Process
{
	public:

    RandomNum * temp; //random temp number 
    static int p_num; //process number 
    std::string pid; //process pid
    int arrival_time; //check in time 
    int wait; //wait time
    int exe; //execution time
    int priority; //priority 
    int end_time; //execution end time

    //Empty Constructor
    //Sets all string to ""
    //Sets all int value to 0 (except the process numnber)
    Process()
    {
      pid = "";
      arrival_time = -1;
      wait = -1;
      exe = -1;
      priority = -1;
      end_time = -1;
    }

    //Constructor
    //Input : t = check in time , priority = priority number
    Process(int t, int priority_num)
    {
        pid = "";
        arrival_time = t;
        wait = 0;
        exe = 0;
        priority = priority_num;
        p_num++;
    };

    //Operation overide
    //overiding the operator "<" to compare the priority number of the two class
    bool operator<(const Process& other) const
    {
      return priority < other.priority;
    }

    //Operation overide
    //overiding the operator ">" to compare the priority number of the two class
    bool operator>(const Process& other) const
    {
      return priority > other.priority;
    }
};

//setting the initial process number to be 0
int Process::p_num = 0;
