//
//  main.cpp
//  Fusion Personnel System
//
//  Created by Joshua Pare on 5/19/20.
//  Copyright © 2020 Joshua Pare. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <fstream>
#include <iterator>
#include "Menus.hpp"
#include "Account.hpp"
#include "Student.hpp"
#include "Teacher.hpp"
#include "Admin.hpp"
#include "Scheduler.hpp"

// File Streams

std::ifstream teacher_ref ("Teachers.txt");
std::ifstream student_ref ("Students.txt");
std::ifstream admin_ref ("Administrators.txt");
std::ifstream classes_ref ("OfferedClasses.txt");
std::ofstream teacher_out ("Teachersout.txt", std::ios::app);
std::ofstream student_out ("Studentsout.txt", std::ios::app);
std::ofstream admin_out ("Administratorsout.txt", std::ios::app);
std::ofstream classes_out ("OfferedClassesout.txt", std::ios::app);

// System Vectors

std::vector<std::shared_ptr<Teacher>> teachers {};
std::vector<std::shared_ptr<Student>> students {};
std::vector<std::shared_ptr<Admin>> administrators {};

Teacher teachermethods{};
// Admin adminmethods{};       //HAVE NOT YET WRITTEN
// Student studentmethods{};   //HAVE NOT YET WRITTEN


// Load function:

void load_accounts();

// Create and Destroy Functions -----ALLOCATE OUTSIDE MAIN EVENTUALLY--------

void output_teacher();
void find_teacher();

// Main

int main () {
    
    // FUNCTION OBJECTS
    Menus menu{};
    Teacher teachermethods{};
    int selection{};
    Schedule f {"Function", "Function"};
    // FUNCTION OBJECTS
    
    menu.login();
    load_accounts();
   
    do {
        selection = menu.main_menu();
        if (selection==1) {
            int selectionsub1{};
            selectionsub1 = menu.student_main_menu();
        }
        if (selection==2) {
            int selectionsub1{};
            selectionsub1 = menu.teacher_main_menu();
            
            if (selectionsub1 == 1) {
                menu.header("FIND TEACHER");
                
                find_teacher();
            }
            if (selectionsub1 == 2) {
                menu.header("ADD CLASS");
                
                f.add_class();
            }
            if (selectionsub1 == 3) {
                menu.header("LIST CURRENT TEACHERS");
                
                for (size_t t=0; t < teachers.size(); t++) {
                    std::cout << *teachers[t] << std::endl;
                }
            }
            if (selectionsub1 == 4) {
                menu.header("PRINT TEACHER SCHEDULE");
                
                f.print_schedule();
            }
            if (selectionsub1 == 5) {
                menu.header("QUIT");
            }
        }
        if (selection==3) {
            int selectionsub1{};
            selectionsub1 = menu.admin_main_menu();
        }
        if (selection==4) {
            menu.header("SMART SCHEDULER");
            
            std::cin.ignore();
            std::string namebuff{};
            std::string sfirstbuff{};
            std::string slastbuff{};
            std::string tfirstbuff{};
            std::string tlastbuff{};
               
            std::cout << "Welcome to the Smart Scheduler!\n\nPlease enter the teacher to enroll: ";
            getline(std::cin, namebuff);
            std::istringstream ss(namebuff);
            ss >> tfirstbuff;
            ss >> tlastbuff;
               
            std::unique_ptr<Schedule> teacher = std::make_unique<Schedule>(tfirstbuff, tlastbuff);
            std::cout << std::endl;
            teacher->load_schedule();
               
            std::cout << "\nPlease enter the student to enroll: ";
            getline(std::cin, namebuff);
            std::istringstream ss2(namebuff);
            ss2 >> sfirstbuff;
            ss2 >> slastbuff;
               
            std::unique_ptr<Schedule> student = std::make_unique<Schedule>(sfirstbuff, slastbuff);
            std::cout << std::endl;
            student->load_schedule();
            
            std::unique_ptr<Schedule> smart_scheduler = std::make_unique<Schedule>("SCHEDULER", "SMART");
            
            int d = 0;
            while (d<5) {
                for (size_t t=0; t < 11; t++) {
                    if (student->time_table[d][t] == "EMPTY" && teacher->time_table[d][t] == "EMPTY"){
                        smart_scheduler->time_table[d][t] = "AVAILABLE";
                    }
                    else
                        smart_scheduler->time_table[d][t] = "BUSY";
                }
            d++;
            }
            
            smart_scheduler->get_schedule();
            
            std::string time{};
            std::string day{};
            std::string classtitle{};
            int array_day{};
            int array_time{};
            
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
             
             std::cout << "\nPlease enter the name of the class you would like to schedule: ";
             getline(std::cin, classtitle);
             
            array_day = f.day_conversion(day);
            array_time = f.time_conversion(time);
            
            if (smart_scheduler->time_table[array_day][array_time] == "AVAILABLE") {
             
                 std::string file_name = (sfirstbuff+slastbuff+"Schedule.txt");
                 std::vector<std::string> stempstore{};
                 
                 std::ifstream in_file;
                 in_file.open(file_name);
                 
                 while (!in_file.eof()) {
                     std::string lineread{};
                     getline(in_file, lineread);
                     stempstore.push_back(lineread);
                 }
                 in_file.close();
                 
                 // REPLACING WITH CLASS IN VECTOR
                 
                 int vectorlocation{};
                 vectorlocation = (array_day*11) + array_time;
                 
                 stempstore.at(vectorlocation) = classtitle;
                 
                 std::ofstream out_file;
                 out_file.open(file_name);
                 
                 for (size_t t=0; t<stempstore.size(); t++) {
                     out_file << stempstore.at(t) << "\n";
                 }
                 out_file.close();
                 
                 std::cout << "\nClass Added to Student Schedule" << std::endl;
                 
                 //Teacher
                 
                 file_name = (tfirstbuff+tlastbuff+"Schedule.txt");
                 std::vector<std::string> ttempstore{};
                
                 in_file.open(file_name);
                 
                 while (!in_file.eof()) {
                     std::string lineread{};
                     getline(in_file, lineread);
                     ttempstore.push_back(lineread);
                 }
                 in_file.close();
                 
                 // REPLACING WITH CLASS IN VECTOR
                 
                 int tvectorlocation{};
                 vectorlocation = (array_day*11) + array_time;
                 
                 ttempstore.at(tvectorlocation) = classtitle;
                 
                 out_file.open(file_name);
                 
                 for (size_t t=0; t<ttempstore.size(); t++) {
                     out_file << ttempstore.at(t) << "\n";
                 }
                 out_file.close();
                 
                 std::cout << "Class Added to Teacher Schedule" << std::endl;
                 
            } else
                std::cerr << "Invalid Time Slot. Please relaunch Smart Scheduler.\n\n";
        }
        
        if (selection==5) {
            std::cout << "Thank you for using the Buzz LMS system, version c++.";
        }
        } while (selection!=5);
    
    output_teacher();
    
    
    // Closing files
    
    teacher_ref.close();
    student_ref.close();
    admin_ref.close();
    classes_ref.close();
    teacher_out.close();
    student_out.close();
    admin_out.close();
    classes_out.close();
    
    return 0;
}

void load_accounts () {

    // Load Documents

    if (teacher_ref) {
        std::cout << "Teacher Account File Linked." << std::endl;
    } else {
        std::cerr << "Error Loading Teacher Accounts";
    }
    if (student_ref) {
        std::cout << "Student Account File Linked." << std::endl;
    } else {
        std::cerr << "Error Loading Student Accounts";
    }
    if (admin_ref) {
        std::cout << "Administrator Account File Linked." << std::endl;
    } else {
        std::cerr << "Error Loading Administrator Accounts";
    }
    if (classes_ref) {
        std::cout << "Classes Template File Linked." << std::endl;
    } else {
        std::cerr << "Error Loading Classes Template";
    }

    // Load Teachers into Vector
    std::cout << "Loading Teacher Accounts...";
    while (!teacher_ref.eof()) {
        std::string tempfirst{};
        std::string templast{};
        int tempage{};
        std::string tempdep{};
        std::string tempsubject{};

        teacher_ref >> tempfirst >> templast >> tempage >> tempdep >> tempsubject;
        teachers.push_back(std::make_shared<Teacher>(tempdep, tempsubject, tempfirst, templast, tempage));
    }

    std::cout << "Teacher Accounts Loaded" << std::endl;


    // Load Students into Vector
    std::cout << "Loading Student Accounts...";
    while (!student_ref.eof()) {
        std::string tempfirst{};
        std::string templast{};
        int tempage{};
        int tempgradelevel{};

        student_ref >> tempfirst >> templast >> tempage >> tempgradelevel;
        students.push_back(std::make_shared<Student>(tempgradelevel, tempfirst, templast, tempage));
    }

    std::cout << "Student Accounts Loaded" << std::endl;

    // Load Administrator into Vector
    std::cout << "Loading Administrator Accounts...";
    while (!admin_ref.eof()) {
        std::string tempfirst{};
        std::string templast{};
        int tempage{};
        std::string temptitle{};

        admin_ref >> tempfirst >> templast >> tempage >> temptitle;
        administrators.push_back(std::make_shared<Admin>(temptitle, tempfirst, templast, tempage));
    }

    std::cout << "Adminstrator Accounts Loaded" << std::endl;

}


void output_teacher() {

    std::shared_ptr<Teacher> temp = std::make_shared<Teacher>(teachermethods.create_teacher());

teachers.insert(teachers.end(),temp);

//Write to File

    teacher_out << temp->get_first_name() << " ";
    teacher_out << temp->get_last_name() << " ";
    teacher_out << temp->get_age() << " ";
    teacher_out << temp->get_department() << " ";
    teacher_out << temp->get_subject();
    teacher_out << "\n";
}

void find_teacher() {
        std::string lnentry{};
       std::cout << "\nPlease enter the last name of the user you would like to find: ";
       std::cin.ignore();
       getline(std::cin, lnentry);
       std::cout << std::endl;
       
       bool user_found{false};
       for (size_t t=0; t < teachers.size(); t++) {
           if (teachers[t]->get_last_name() == lnentry) {
               std::cout << *teachers[t] << std::endl;
               user_found = true;
           }
       }
       if (!user_found) {
           std::cout << "No user found with that last name.\n" << std::endl;
       }
    }

