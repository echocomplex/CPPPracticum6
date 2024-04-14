#ifndef CPPPRACTICUM6_TASK6_20_H
#define CPPPRACTICUM6_TASK6_20_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

struct grade {
    std::string subject;
    std::string date;
    int mark;
};

struct student {
    std::string number;
    std::string first_name;
    std::string birth_day;
    std::string group;
    grade result;
};

struct Node {
    student unit;
    int index;
    Node* next;
};


class task6_20 {
private:
    Node* list = nullptr;
    Node* last = nullptr;

public:
    task6_20 ();
    task6_20 (std::string path);
    task6_20& operator= (const task6_20 &obj);
    friend std::ostream& operator<< (std::ostream& os, const task6_20& obj);
    void append (student newData);
    void toFile (std::string filename);
    void removeNodeFromIndex (int index);
    std::vector <student> findByDate (std::string date);
    int countStudentsBySubject (std::string subject);
};

#endif // CPPPRACTICUM6_TASK6_20_H