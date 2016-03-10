/******************************************************************************
 Course Project
 CD and DVD Collection
 CISS 243-A
 
 <description>  Implementation file for the DVD class
 
 <author> John Carty
 <date> 7 - Oct - 2015
 <revision> NONE
 
 ******************************************************************************/

#include "DVD.h"


DVD::DVD() {
    year = 0;
}

void DVD::setRoles(std::string actor, std::string character) {
    struct actor temp;
    temp.actorsName = actor;
    temp.charactersName = character;
    roles.appendNode(temp);
}

void DVD::setLength(int l) {
    length = l;
}

void DVD::setYear(int y) {
    year = y;
}

int DVD::getYear() {
    return year;
}

void DVD::getRoles(int i) {
    actor temp = roles.getNode(i);
    while (temp.actorsName != ""){
        if (i < 1) {
            std::cout << std::setw(18);
            std::cout << std::right << temp.actorsName << std::setw(10) << temp.charactersName;
            std::cout << std::endl;
        } else {
            std::cout << std::setw(53);
            std::cout << std::right << temp.actorsName << std::setw(10) << temp.charactersName;
            std::cout << std::endl;
        }
        i++;
        temp = roles.getNode(i);
    }
}

bool DVD::operator==(DVD &right){
    if (title == right.title) {
        return true;
    } else {
        return false;
    }
}

bool DVD::operator!=(DVD &right){
    if (title != right.title) {
        return true;
    } else {
        return false;
    }
}




