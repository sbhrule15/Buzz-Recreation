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
#include "Menus.hpp"
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

// Main

int main () {
    Menus menu{};
    Teacher teachermethods{};
    int selection{};
    
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
        }
        if (selection==3) {
            int selectionsub1{};
            selectionsub1 = menu.admin_main_menu();
        }
        if (selection==4) {
    //        int selectionsub1{};
    //        selectionsub1 = menu.enrollment_main_menu{};
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

