/******************************************************************************
 Course Project
 CD and DVD Collection
 CISS 243-A
 
 <description>  Implementation for the CD class
 
 <author> John Carty
 <date> 7 - Oct - 2015
 <revision> NONE
 
 ******************************************************************************/

#include "CD.h"


CD::CD () {
    artistName = "";
}

void CD::setArtist(std::string artist) {
    artistName = artist;
}

void CD::setSongs(std::string sTitle, double sLength) {
    song temp;;
    temp.songTitle = sTitle;
    temp.songLength = sLength;
    songs.appendNode(temp);
    setLength();
}

void CD::setLength() {
    double tempLength = 0;
    int i = 0;
    List<song> temp1 = songs;
    song temp;
    temp = temp1.getNode(i);
    while (temp.songLength > -1) {
        tempLength += temp.songLength;
        i++;
        temp = temp1.getNode(i);
        
    }
    length = tempLength;
}

void CD::getSongs(int i) {
    song temp = songs.getNode(i);
    while (temp.songLength != -1){
        if (i < 1) {
            std::cout << std::setw(18);
            std::cout << std::right << temp.songTitle << std::setw(10) << temp.songLength;
            std::cout << std::endl;
        } else {
            std::cout << std::setw(53);
            std::cout << std::right << temp.songTitle << std::setw(10) << temp.songLength;
            std::cout << std::endl;
        }
        i++;
        temp = songs.getNode(i);
    }
}

std::string CD::getArtist() {
    return artistName;
}

bool CD::operator==(CD &right){
    if (artistName == right.artistName && title == right.title) {
        return true;
    } else {
        return false;
    }
}

bool CD::operator!=(CD &right){
    if (artistName != right.artistName && title != right.title) {
        return true;
    } else {
        return false;
    }
}