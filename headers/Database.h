#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include "../headers/ProcessorList.h"
#include "RandomNum.h"

//Class Inheritence from the ProcessorList Queue
class Database : public ProcessorList
{
    private:

        int priority_num; //priority of the process
        int p_rate; //rate of process (Process/hour)
        int p_counter = 0; //process counter
        std::string d_name; //paitent name
        bool report_flag; //flag to check for output display
        RandomNum *pushRandom = new RandomNum; //generate new random number for pushing into the priority
        std::set<std::string> names; //set to hold all the names of Process

    public:
        //Constructor
        //Generates new reception class : inheritence of ProcessorList class
        Database(RandomNum *r, int influx_rate, std::string dname, bool flag): //generating reception class
            ProcessorList(r), p_rate(influx_rate), d_name(dname), report_flag(flag) //generating ProcessorList class
        {
            pushRandom = r;
            nameInput(); //calling the nameInput method of the Database class to set the name
        }    

        //Method to update the cpu schedule after every cycle
        //The cycle goes by every 1 sec
        //Input : t = current time of the cycle 
        void update(int t)
        {   
            //for the first cycle of
            //current process will be the rate of the process
            if (t % 60 == 0)
            {
                p_counter = p_rate;
            }
            //flag to check if the counter is 0
            if(p_counter != 0)
            {
                priority_num = pushRandom->rand_priority(); //generate new random priority to the process
                Process *process = new Process(t, priority_num); //generates with new process with current cycle time and priority
                process->pid = setRandonID(); //sets ID for the process
                
                //Condition for low priority process
                if (priority_num <= 10) {
                    lowP_Process.push(*process); //pushesh the process in low priority priority_queue
                }
                //Condition for high priority process
                else
                {
                    highP_Process.push(*process); //pushesh the process in high priority priority_queue
                }
                //If the flag is set true for display then displays the Process information
                if (report_flag)
                {   
                    std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";
                    std::cout <<"Process Started its Job " << std::endl;
                    std::cout << "Process PID : " << process->pid << "\n Priority : "<< process->priority << "\n Arrival Time : " << t << std::endl;
                }
                    p_counter--;
            }
        }

        //Method to input the name from the database
        void nameInput()
        {
            std::ifstream inputlist; //creates with fstream for all the process name
            inputlist.open(".\\data\\ProcessPIDs.txt"); //path of the database
            std::string res_name; //sting name to store inputlist names
            while (!inputlist.eof()) { //loop until the end of the file
                inputlist >> res_name; //takes the name of one line
                names.insert(res_name); //inserts the name in the set
            }
            inputlist.close();
        }

        //Method to set random name
        std::string setRandonID() {
            std::set<std::string>::iterator it = names.begin(); //set iterator pointed at the beginning of the name
            int temp_rand = pushRandom->randIntRange(names.size()); //temp int which is random within the range of the size of the name
            for (int i = 0; i < temp_rand; ++i) 
            {
                ++it; //counter till the end of the random number
            }
            return *it; //returns the iterator
        }
};