#pragma once

#include "../headers/ProcessorList.h"
#include "../headers/Report.h"

//Class Inheritence from the ProcessorList Queue
class Processor : public ProcessorList
{
public:

    Process * subject = new Process; //ptr for new process
    ProcessorList * P_list; //ProcessorList class ptr pidd P_list

    int min_exe_time; //mininum exe time
    int max_exe_time; //maximum exe time
    int exe_time; //total exe time
    int start_exe_time = -1; //time when exe start (Default is -1)
    int end_exe_time = -1; //time when exe end (Default is -1)
    bool flag_output; //bool flag to check for report display

    //Constructor
    //Generates new Processor class : inheritence of ProcessorList class
    Processor(RandomNum *r, ProcessorList *N,
    int min_t, int max_t, bool flag) :
    ProcessorList(r), P_list(N), min_exe_time(min_t),
    max_exe_time(max_t), flag_output(flag) {}

    //Virtual Method Uptdate
    //Updates the processor after every cycle
    //Input : t = current cycle time
    void update(int t)
    {
        if (subject->end_time != -1) //checking if the subject process has been exeed or not (where -1 is the condition when t he process has been exeed)
        {
            if (subject->end_time == t) { //checking if the process exe in the current cycle time

                if (flag_output) //flag to check to display the report
                {
                    //**MAKE THIS BETTER**
                    std::cout << "__________________________________________________________________________________________________________________ " << std:: endl;
                    std::cout << "## Processor finished exe \n PID : " << subject->pid << "\n Priority : " << subject->priority << "\n End Time : " << t <<"\n "<< std::endl;
                }

                Report *pushReport = new Report; //creating new record for pushing data to the report
                pushReport->update_report(subject); //pushing the exeed process to the finishedProcess vector
                P_list->finishedProcess.push_back(*subject); //calling method update_report to push the Process record

                subject->end_time = -1; //update the status of the process as "completed exe"

            }

            return;
        }

        //condition if the high priority queue is empty
        if (highP_Process.empty())
        {
            ProcessorList *P1_list; //creating a new ProcessorList class

            //checks if the current ProcessorList's high queue is empty
            //if empty the Processor exes the low priority queue
            if (P_list->highP_Process.empty()) 
            {
                //if the low priority is also empty
                //Processor does nothing and the cycle ends
                if (lowP_Process.empty())
                {
                    ProcessorList *P2_list; //new ProcessorList class for temp. holding 

                    if (P_list->lowP_Process.empty())
                    {
                        return;
                    }

                    P2_list = P_list;
                    Process *p = new Process; //new process class callled p

                    *p = P2_list->lowP_Process.top(); //pushing the new process to the low priority queue
                    P2_list->lowP_Process.pop(); //poping the bottom process of the queue

                    int exeTime = max_exe_time - min_exe_time; //exe time range of the Processor

                    //generating a new RandomNum number which is within the range of the exe time
                    exe_time = min_exe_time + pushRandom->next_int(exeTime);
                    start_exe_time = t; //current cycle time is the starting time
                    end_exe_time = t + exeTime; // current cycle + total exe time is the ending time

                    //pushing the value of the data to the new Process member
                    p->exe = exe_time;
                    p->end_time = end_exe_time;
                    p->wait = start_exe_time - p->arrival_time;

                    //Prints the stats
                    if (flag_output)
                    {
                        std::cout << "-------------------------------------------------------------------------------- " << std::endl;
                        std::cout << "^^ Processor starting exe \n Pid : " << p->pid << "\n Priority :" << p->priority << "\n Start Time : " << t << std::endl << std::endl;
                    }

                    *subject = *p; // the subject process is the new process
                }
                return;
            }

            //condition if the high priority is not empty
            P1_list = P_list; //new process list
            Process *p = new Process; //new process for output
            *p = P1_list->highP_Process.top(); //temp data hold
            P1_list->highP_Process.pop();

            //generating a new random number which is within the range of the exe time
            int exeTime = max_exe_time - min_exe_time;
            exe_time = min_exe_time + pushRandom->next_int(exeTime);
            start_exe_time = t; //current cycle time is the starting time
            end_exe_time = t + exeTime; // current cycle + total exe time is the ending time

            //pushing the value of the data to the new Process member
            p->exe = exe_time;
            p->end_time = end_exe_time;
            p->wait = start_exe_time - p->arrival_time;

            //Prints the stats of the process
            if (flag_output)
            {   
                std::cout << "-------------------------------------------------------------------------------- " << std::endl;
                std::cout << "^^ Processor starting exe \n PID : " << p->pid << "\n Priority :" << p->priority << "\n Start Time : " << t << std::endl << std::endl;
            }
            *subject = *p; // the subject process is the new process
        }

        else if (exe_time < t - start_exe_time) //checks if the exe time is valid
        {
            Process *p = new Process; //new process for output
            *p = lowP_Process.top();  //temp data hold
            lowP_Process.pop();

            //Prints the stats
            if (flag_output)
            {
                std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ " << std::endl << std:: endl;
                std::cout << "Process Ended" << std::endl;
                std::cout << "PID : " << p->pid << "\n End Time : " << t << std::endl;
            }
        }
    }
};