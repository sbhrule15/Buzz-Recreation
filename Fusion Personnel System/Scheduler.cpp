//
//  Scheduler.cpp
//  Scheduler
//
//  Created by Joshua Pare on 5/25/20.
//  Copyright © 2020 Joshua Pare. All rights reserved.
//

#include "Scheduler.hpp"


void Schedule::load_schedule(){
    std::ifstream schedule_input;
    schedule_input.open(schedule_file);
    
    if (schedule_input) {
        std::cout << "File Opened Successfully." << std::endl;
    } else {
        std::cerr << "Error Opening File.\n";
    }
    
    int d = 0;
    while (d<5) {
        
        for (size_t t=0; t < 11; t++) {
            std::string buff{};
            getline(schedule_input, buff);
            time_table[d][t] = buff;
           }
        d++;
    }
    
    std::cout << "Schedule Imported." << std::endl;
    
    schedule_input.close();
}



void Schedule::element_access (int l, std::string time) {
    std::cout   << std::setfill(' ') << std::left << std::setw(7) << time;
    for (size_t t=0; t < 5; t++) {
        std::cout << std::setw(30) << time_table[t][l];
    }
    std::cout << std::endl;
}

void Schedule::get_schedule() {
    std::cout << std::endl;
    std::cout << std::left << lastname << "," << firstname << std::setw(150) << std::setfill('=') << "=" << std::endl << std::endl;
        
        std::cout   << std::setfill(' ') << std::left << std::setw(7) << " "
                    << std::setw(30) << "Monday"
                    << std::setw(30) << "Tuesday"
                    << std::setw(30) << "Wednesday"
                    << std::setw(30) << "Thursday"
                    << std::setw(30) << "Friday" << std::endl;
    // HEADER
        
        std::cout   << std::setfill('-') << std::left << std::setw(150) << "     " << std::endl;

    // RETURN ARRAY VALUES
        
        element_access(0, "7:30 |");
        element_access(1, "8:30 |");
        element_access(2, "9:30 |");
        element_access(3, "10:30|");
        element_access(4, "11:30|");
        element_access(5, "12:30|");
        element_access(6, "1:30 |");
        element_access(7, "2:30 |");
        element_access(8, "3:30 |");
        element_access(9, "4:30 |");
        element_access(10,"5:30 |");
}

void Schedule::print_schedule(){
    
    std::cin.ignore();
    std::string namebuff{};
       std::string firstbuff{};
       std::string lastbuff{};
       
       std::cout << "Please enter the name of the teacher you would like to load the schedule of: " << std::endl;
       std::cout << "Name:";
       getline(std::cin, namebuff);
       std::istringstream ss(namebuff);
       ss >> firstbuff;
       ss >> lastbuff;
       
       std::unique_ptr<Schedule> sch = std::make_unique<Schedule>(firstbuff, lastbuff);
        std::cout << std::endl;
       sch->load_schedule();
        std::cout << std::endl;
       sch->get_schedule();
    
}

int Schedule::time_conversion(std::string time){
    if (time == "7:30")
        return 0;
    if (time == "8:30")
        return 1;
    if (time == "9:30")
        return 2;
    if (time == "10:30")
        return 3;
    if (time == "11:30")
        return 4;
    if (time == "12:30")
        return 5;
    if (time == "1:30")
        return 6;
    if (time == "2:30")
        return 7;
    if (time == "3:30")
        return 8;
    if (time == "4:30")
        return 9;
    if (time == "5:30")
        return 10;
    else throw time;
}

int Schedule::day_conversion(std::string day){
    
    if (day == "Monday")
        return 0;
    if (day == "Tuesday")
        return 1;
    if (day == "Wednesday")
        return 2;
    if (day == "Thursday")
        return 3;
    if (day == "Friday")
        return 4;
    else throw day;
}

void Schedule::add_class() {
    std::cin.ignore();
     std::string namebuff{};
     std::string firstbuff{};
     std::string lastbuff{};
     int array_day{};
     int array_time{};
     
     std::cout << "Please enter the user's name:" << std::endl;
     std::cout << "Name:";
     getline(std::cin, namebuff);
     std::istringstream ss(namebuff);
     ss >> firstbuff;
     ss >> lastbuff;
     
     std::unique_ptr<Schedule> sch = std::make_unique<Schedule>(firstbuff, lastbuff);
     std::cout << std::endl;
     sch->load_schedule();
     
     std::string time{};
     std::string day{};
     std::string classtitle{};
    
     do {
         std::cout << "\nPlease enter the day you would like to add the class:";
         getline(std::cin, day);
             if (day != "Monday" && day != "Tuesday" && day != "Wednesday" && day != "Thursday" && day!= "Friday") {
                 std::cerr << "Invalid Day. Please Try Again.\n" << std::endl;
             }
     } while (day != "Monday" && day != "Tuesday" && day != "Wednesday" && day != "Thursday" && day!= "Friday");
     
     do {
         std::cout << "\nPlease enter the time you would like to add the class:";
         getline(std::cin, time);
             if (time != "7:30" && time != "8:30" && time != "9:30" && time != "10:30" && time != "11:30" && time != "12:30" && time != "1:30" && time != "2:30" && time != "3:30" && time != "4:30" && time != "5:30") {
                 std::cerr << "Invalid Time. Please Try Again.\n" << std::endl;
             }
     } while (time != "7:30" && time != "8:30" && time != "9:30" && time != "10:30" && time != "11:30" && time != "12:30" && time != "1:30" && time != "2:30" && time != "3:30" && time != "4:30" && time != "5:30");
     
     std::cout << "Please enter the name of the class you would like to schedule: ";
     getline(std::cin, classtitle);
     
     array_day = day_conversion(day);
     array_time = time_conversion(time);
     
     if (sch->time_table[array_day][array_time] == "EMPTY") {
         std::string file_name = (firstbuff+lastbuff+"Schedule.txt");
         std::vector<std::string> tempstore{};
         
         std::ifstream in_file;
         in_file.open(file_name);
         
         while (!in_file.eof()) {
             std::string lineread{};
             getline(in_file, lineread);
             tempstore.push_back(lineread);
         }
         in_file.close();
         
         // REPLACING WITH CLASS IN VECTOR
         
         int vectorlocation{};
         vectorlocation = (array_day*11) + array_time;
         
         tempstore.at(vectorlocation) = classtitle;
         
         std::ofstream out_file;
         out_file.open(file_name);
         
         for (size_t t=0; t<tempstore.size(); t++) {
             out_file << tempstore.at(t) << "\n";
         }
         out_file.close();
         
         std::cout << "Class Added to Schedule" << std::endl;
         
     } else {
         std::cout << "This slot is already full." << std::endl;
     }
}
