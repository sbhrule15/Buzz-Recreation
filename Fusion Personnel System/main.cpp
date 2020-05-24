//
//  main.cpp
//  Fusion Personnel System
//
//  Created by Joshua Pare on 5/19/20.
//  Copyright © 2020 Joshua Pare. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <fstream>
#include <iterator>
#include "Account.hpp"
#include "Student.hpp"
#include "Teacher.hpp"
#include "Admin.hpp"

// File Streams

std::ifstream teacher_ref ("Teachers.txt");
std::ifstream student_ref ("Students.txt");
std::ifstream admin_ref ("Administrators.txt");
std::ifstream classes_ref ("OfferedClasses.txt");
std::ofstream teacher_out ("Teachersout.txt", std::ios::app);
std::ofstream student_out ("Studentsout.txt", std::ios::app);
std::ofstream admin_out ("Administratorsout.txt", std::ios::app);
std::ofstream classes_out ("OfferedClassesout.txt", std::ios::app);



std::vector<std::shared_ptr<Teacher>> teachers {};
std::vector<std::shared_ptr<Student>> students {};
std::vector<std::shared_ptr<Admin>> administrators {};



// Menu functions:

int main_menu ();
void login();
void load_accounts();

// Create and Destroy Functions

Teacher create_teacher();
void output_teacher();

// Main

int main () {
    
    login();
    load_accounts();
    
    output_teacher();
    
    teacher_ref.close();
    student_ref.close();
    admin_ref.close();
    classes_ref.close();
    
    return 0;
}


int main_menu () {
    
    int menu_selection{};
    
    std::cout << "==================MAIN MENU===================" << std::endl;
    
    return menu_selection;
    
}

void login() {
    std::string usernameentry{};
    std::string passwordentry{};
    std::string username{"JPare"};
    std::string password{"Aida2019$"};
    bool access{false};

    do {
        std::cout << "====================LOGIN====================" << std::endl;
        std::cout << "\nPlease enter your username and password:\n" << std::endl;

        std::cout << "\tUsername: ";
        getline(std::cin, usernameentry);

        std::cout << "\tPassword: ";
        getline(std::cin, passwordentry);

        if (username == usernameentry && password == passwordentry) {
            std::cout << "Welcome " << usernameentry << "." << std::endl;
            access = true;
        } else {
            std::cerr << "Credentials invalid. Please try again.";
            access =  false;
            }
    } while (access == false);
}

void load_accounts () {

    // Load Documents

    if (teacher_ref) {
        std::cout << "Teacher Accounts Loaded." << std::endl;
    } else {
        std::cerr << "Error Loading Teacher Accounts";
    }
    if (student_ref) {
        std::cout << "Student Accounts Loaded." << std::endl;
    } else {
        std::cerr << "Error Loading Student Accounts";
    }
    if (admin_ref) {
        std::cout << "Administrator Accounts Loaded." << std::endl;
    } else {
        std::cerr << "Error Loading Administrator Accounts";
    }
    if (classes_ref) {
        std::cout << "Classes Template Loaded." << std::endl;
    } else {
        std::cerr << "Error Loading Classes Template";
    }

    // Load Teachers into Vector

    while (!teacher_ref.eof()) {
        std::string tempfirst{};
        std::string templast{};
        int tempage{};
        std::string tempdep{};
        std::string tempsubject{};

        teacher_ref >> tempfirst >> templast >> tempage >> tempdep >> tempsubject;
        teachers.push_back(std::make_shared<Teacher>(tempdep, tempsubject, tempfirst, templast, tempage));
    }

    std::cout << "Teacher Accounts Copied to Main" << std::endl;


    // Load Students into Vector

    while (!student_ref.eof()) {
        std::string tempfirst{};
        std::string templast{};
        int tempage{};
        int tempgradelevel{};

        student_ref >> tempfirst >> templast >> tempage >> tempgradelevel;
        students.push_back(std::make_shared<Student>(tempgradelevel, tempfirst, templast, tempage));
    }

    std::cout << "Student Accounts Copied to Main" << std::endl;

    // Load Administrator into Vector

    while (!admin_ref.eof()) {
        std::string tempfirst{};
        std::string templast{};
        int tempage{};
        std::string temptitle{};

        admin_ref >> tempfirst >> templast >> tempage >> temptitle;
        administrators.push_back(std::make_shared<Admin>(temptitle, tempfirst, templast, tempage));
    }

    std::cout << "Adminstrator Accounts Copied to Main" << std::endl;

}

Teacher create_teacher () {
    std::string tempfirst{};
    std::string templast{};
    int tempage{};
    std::string tempdep{};
    std::string tempsubject{};
        
    std::cout << "\n==========CREATE TEACHER==========\n";
    std::cout << "Please enter the following information about the teacher: ";
    
    std::cout << "\n\tFirst Name: ";
    getline(std::cin, tempfirst);
    
    std::cout << "\tLast Name: ";
    getline(std::cin, templast);
    
    std::cout << "\tAge: ";
    std::cin >> tempage;
    
    std::cout << "\tDepartment (Humanities, STEM, English, or Electives): ";
    std::cin.ignore();
    getline(std::cin, tempdep);
    
    std::cout << "\tSubject Area: ";
    getline(std::cin, tempsubject);
    
    std::cout << "\nCreating Teacher...";
    Teacher ptr {tempdep, tempsubject, tempfirst, templast, tempage};
    
    return ptr;
    
}

void output_teacher() {

std::shared_ptr<Teacher> temp = std::make_shared<Teacher>(create_teacher());

teachers.insert(teachers.end(),temp);

//Write to File

    teacher_out << temp->get_first_name() << " ";
    teacher_out << temp->get_last_name() << " ";
    teacher_out << temp->get_age() << " ";
    teacher_out << temp->get_department() << " ";
    teacher_out << temp->get_subject();
    teacher_out << "\n";
}


// Old Code
    
//    std::unique_ptr<Account> JP = std::make_unique<Teacher>("Electives", "Music", "Joshua", "Pare", 24);
//    std::unique_ptr<Account> JY = std::make_unique<Teacher>("STEM", "Science", "Justine", "Yoon", 30);
//    std::unique_ptr<Account> CD = std::make_unique<Teacher>("STEM", "Math", "Costanza", "Davis", 23);
//    std::unique_ptr<Account> DG = std::make_unique<Teacher>("Humanities", "English", "Danielle", "Greenburg", 32);
//
//    std::cout << *JP << std::endl;
//    std::cout << *JY << std::endl;
//    std::cout << *CD << std::endl;
//    std::cout << *DG << std::endl;
    

