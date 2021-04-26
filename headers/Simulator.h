#pragma once

#include <vector>
#include "../headers/Database.h"
#include "Processor.h"
#include "RandomNum.h"
#include "Report.h"

class Simulator
{
private:
    int runtime; //Total run time of the simulation
    std::vector<ProcessorList *> threads; //vector containing all the ProcessLists of the simulation
    //Report *m_report; 
    RandomNum *r; // generates new random numebr to pass to the ProcessList
    Database *scheduler_dbase; //ptr for the scheduler databse
    bool flag_output; //bool flag to display the output

public:

    //Constructor of simulation
    Simulator(int pro_num, int time, int rate, bool flag) :
    runtime(time), flag_output(flag)
    {
        r = new RandomNum; //generating new random number
        Database *s_dbase = new Database(r, rate, "Scheduler Database", flag_output); //making a new database ptr for the hospital
        scheduler_dbase = s_dbase; //pointing the hospital database to the member database of the simulator
        threads.push_back(s_dbase); //pushing the database to threads vector

        //Making the Processor 

        //Condition for one Processor 
        if (pro_num == 1) {
            Processor *P1 = new Processor(r, s_dbase, 1, 20, flag_output); //Generating new Processor class
            threads.push_back(P1); //pushing Processor to the threads vector
        }

        //Condition for two Processor 
        if (pro_num == 2) {
            Processor *P1 = new Processor(r, s_dbase, 1, 20, flag_output); //Generating new Processor class
            Processor *P2 = new Processor(r, s_dbase, 1, 20, flag_output); //Generating new Processor class
            threads.push_back(P1); //pushing Processor to the threads vector
            threads.push_back(P2); //pushing Processor to the threads vector
        }

        //Condition for three Processor 
        if (pro_num == 3) {
            Processor *P1 = new Processor(r, s_dbase, 1, 20, flag_output); //Generating new Processor class
            Processor *P2 = new Processor(r, s_dbase, 1, 20, flag_output); //Generating new Processor class
            Processor *P3 = new Processor(r, s_dbase, 1, 20, flag_output); //Generating new Processor class
            threads.push_back(P1); //pushing Processor to the threads vector
            threads.push_back(P2); //pushing Processor to the threads vector
            threads.push_back(P3); //pushing Processor to the threads vector
        }

        //Condition for four Processor 
        if (pro_num == 4) {
            Processor *P1 = new Processor(r, s_dbase, 1, 20, flag_output); //Generating new Processor class
            Processor *P2 = new Processor(r, s_dbase, 1, 20, flag_output); //Generating new Processor class
            Processor *P3 = new Processor(r, s_dbase, 1, 20, flag_output); //Generating new Processor class
            Processor *P4 = new Processor(r, s_dbase, 1, 20, flag_output); //Generating new Processor class
            threads.push_back(P1); //pushing Processor to the threads vector
            threads.push_back(P2); //pushing Processor to the threads vector
            threads.push_back(P3); //pushing Processor to the threads vector
            threads.push_back(P4); //pushing Processor to the threads vector
        }
    }

    //Method to run the simulator 
    void run()
    {
        //cycles untill the end of the run time
        for (int i = 0; i < runtime; ++i)
        {
            //Cycle to update every threads in the ProcessList class
            for (unsigned int j = 0; j < threads.size(); ++j)
            threads[j]->update(i);
        }
    }

    //Method to print the report of the simulation
    void report()
    {
        Report *output = new Report; //generates we report class called output
        output->print_report(); //prints the output of to the terminal
    }

};