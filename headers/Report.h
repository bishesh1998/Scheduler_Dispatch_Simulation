#pragma once

#include <iostream>
#include "Process.h"

//Record Class
//This holds the total stats of the simulation
class Report
{
    private:

        static int total_exe;  //total treatment time
        static int total_wait; //total wait time
        static int total_Process; //total number of Process
        Process *subject = new Process; //new patient names "subject"

    public:
        //Empty Constructor
        Report(){}

        //Method to update the Report
        //Input : Process class ptr
        //output : Adds the data of the input process to the record class
        void update_report(Process *Patient)
        {
            total_wait += Patient->wait; //adding the wait time
            total_exe += Patient->exe; //adding the treatment time
            total_Process += 1; //adding the number of Process
        };

        //Method print
        //prints the report to the terminal
        void print_report()
        {
            std::cout << "~~~~~~~~~~~~ SIMULATION REPORT ~~~~~~~~~~~~~~~~~ " << std::endl;
            std::cout << "Throughput(Total process executed): " << total_Process << std::endl;
            std::cout << "Average Turnaround time: " << (double)total_exe / total_Process << std::endl;
            std::cout << "Average Wait time: " << (double)total_wait / total_Process << std::endl;
            std::cout << "Processor Utilization: " << (double)total_wait /(double)total_exe << std::endl;
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << std::endl;
        };
};

int Report::total_exe = 0;
int Report::total_wait = 0;
int Report::total_Process = 0;
