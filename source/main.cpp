//////////////////////////////////////////////////////////////////////////////////
// Lab 7
// CS475W
// Group Members : 1. Bishesh Tuladhar
//                 2. Xavier Betancourt
// 
// CPU Scheduler Dispatch Simulation
/////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "../headers/Simulator.h"
#include "../headers/RandomNum.h"


int main ()
        
{

    std::cout << "____________________________________________________________________________________ \n\n";

    std::cout << "Assumptions : \n\n";
    std::cout << "1. Enter the data requested from the simulator. \n";
    std::cout << "2. Simulation runs for 60 secs \n";
    std::cout << "3. All processes have priority number \n";
    std::cout << "4. Low priority : 1-10 and High Priority : 11-20 \n";
    std::cout << "5. Simulation inputs process PID from the random text file \n";

    std::cout << "------------------------------------------------------------------------------------- \n\n";
    std::cout << "Data Entry : \n\n";
    
    int procs, nurses, runtime, patRate; //Input for the simulation class
    std::string user_flag; //string to ask user for output flag
    bool output_flag = false; //bool flag for the output

    patRate = 10; //Process entry rate
    std::cout << "Amount of Processor(MAX 4 processor) :";
    std::cin >> procs;


    runtime = 60;
    
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";
    std::cout << "Do you want to dispaly the text output of the simulation [Y/N] :";
    std::cin >> user_flag;

    //setting the output bool flag
    if (user_flag == "Y" || user_flag == "y")
    {
        output_flag = true;
    }

    Simulator sim(procs, runtime, patRate, output_flag); //generating new simulator class

    sim.run(); //running the simulation

    sim.report(); //displaying the report of the simulation
    
    std::cout <<"Enter any key to exit:";
    char e;
    std::cin>>e;
    return 0; 
}
