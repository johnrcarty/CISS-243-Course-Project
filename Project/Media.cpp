/******************************************************************************
 Course Project
 CD and DVD Collection
 CISS 243-A
 
 <description>  Provides a menu for the user to select if they want to work
 with cds or dvds. The program will then keep a list of the
 users cd and dvd collection and allow them to add, remove,
 update, or outout the contents.
 
 <author> John Carty
 <date> 7 - Oct - 2015
 <revision> NONE
 
 ******************************************************************************/

#include "Media.h"
#include "CD.h"

Media::Media(){
    title = "";
    length = 0;
}

void Media::setTitle(std::string t) {
    title = t;
}

std::string Media::getTitle() {
    return title;
}

double Media::getLength() {
    return length;
}