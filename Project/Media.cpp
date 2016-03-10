/******************************************************************************
 Course Project
 CD and DVD Collection
 CISS 243-A
 
 <description>  Implementation of the Media class
 
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