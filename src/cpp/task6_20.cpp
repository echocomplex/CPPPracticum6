#include <task6_20.h>

task6_20::task6_20 () {

}

task6_20::task6_20 (std::string path) {
    std::ifstream file (path, std::ios::binary);
    if (file.is_open()) {
        std::string row;
        while (std::getline(file, row)) {
            std::istringstream iss(row);
            std::string word;
            student unit;
            int count = 0;
            while (iss >> word) {
                if (count == 0) { unit.number = word; }
                else if (count == 1) { unit.first_name = word; }
                else if (count == 2) { unit.birth_day = word; }
                else if (count == 3) { unit.group = word; }
                else if (count == 4) { unit.result.subject = word; }
                else if (count == 5) { unit.result.date = word; }
                else { unit.result.mark = std::stoi(word); }
                count++;
            }
            this->append(unit);
        }
    }
    else {
        throw std::runtime_error("File does not exist");
    }
    file.close();
}

task6_20 &task6_20::operator= (const task6_20 &obj) {
    if (this != &obj) {
        this->list = obj.list;
    }
    return *this;
}

std::ostream& operator<< (std::ostream& os, const task6_20& obj) {
    std::string toOut = "";
    Node* last = obj.list;
    while (last != nullptr) {
        std::string row = last->unit.number + " " + last->unit.first_name + " " + last->unit.birth_day + " " + last->unit.group + " " + last->unit.result.subject + " " + last->unit.result.date + " " + std::to_string(last->unit.result.mark) + "\n";
        toOut = toOut + row;
        last = last->next;
    }
    os << toOut;
    return os;
}

void task6_20::append (student newData) {
    Node* newNode = new Node;
    newNode->unit = newData;
    newNode->next = nullptr;
    if (this->list == nullptr) {
        newNode->index = 0;
        this->list = newNode;
        this->last = newNode;
    } 
    else {
        newNode->index = this->last->index + 1;
        this->last->next = newNode;
        this->last = newNode;
    }
}

void task6_20::toFile (std::string filename) {
    if (this->list == nullptr) {
        throw std::logic_error("List have no element!");
    }
    std::string toOut;
    Node* last = this->list;
    while (last != nullptr) {
        std::string row = last->unit.number + " " + last->unit.first_name + " " + last->unit.birth_day + " " + last->unit.group + " " + last->unit.result.subject + " " + last->unit.result.date + " " + std::to_string(last->unit.result.mark) + "\n";
        toOut = toOut + row;
        last = last->next;
    }
    std::ofstream file(filename.c_str(), std::ios::binary);
    file.write(toOut.c_str(), toOut.size());
    file.close();
}

void task6_20::removeNodeFromIndex (int index) {
    if (this->list == nullptr) {
        throw std::logic_error("The list have no element!");
    }
    if (this->last->index < index) {
        throw std::logic_error("The index is greater than the last index of the list");
    }
    if (index < 0) {
        throw std::logic_error("The index is less than 0");
    }
    
    Node* last = this->list;
    std::vector <Node*> toDelete;
    Node* newLast;
    bool deleteStatus = false;
    while (last != nullptr) {
        if (deleteStatus) {
            toDelete.push_back(last);
        }
        else {
            if (last->index + 1 == index) {
                newLast = last;
            }
            else if (last->index == index) {
                deleteStatus = true;
                toDelete.push_back(last);
            }
        }
        last = last->next;
    }
    for (Node* toDel: toDelete) {
        delete toDel;
    }
    newLast->next = nullptr;
    this->last = newLast;
}

std::vector <student> task6_20::findByDate (std::string date) {
    Node* last = this->list;
    std::vector <student> result {};
    while (last != nullptr) {
        if (last->unit.result.date == date) {
            result.push_back(last->unit);
        }
        last = last->next;
    }
    return result;
}

int task6_20::countStudentsBySubject (std::string subject) {
    Node* last = this->list;
    int result = 0;
    while (last != nullptr) {
        if (last->unit.result.subject == subject) {
            result++;
        }
        last = last->next;
    }
    return result;
}