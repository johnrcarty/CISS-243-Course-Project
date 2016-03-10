/******************************************************************************
 Course Project
 CD and DVD Collection
 CISS 243-A
 
 <description>  Pulls from the base class of Media, allows the user to create
                a data type that keeps the nessecary info for a CD.
 
 <author> John Carty
 <date> 7 - Oct - 2015
 <revision> NONE
 
 ******************************************************************************/

#ifndef CD_H
#define CD_H

#include "Media.h"
#include "List.h"
#include <iomanip>


class CD : public Media {
    
    private:
        struct song {
            std::string songTitle;
            double songLength;
            
            song(){
                songTitle = "";
                songLength = -1;
            }
            
            double operator+=(song &right) {
                return songLength += right.songLength;
            }
            
        };
    
        List<song> songs;
        std::string artistName;
    
    
    public:
        CD();
    
        void setArtist(std::string);    
        void setSongs(std::string, double);
        void setLength();
    
        void getSongs(int);
    
        bool operator == (CD &);
        bool operator != (CD &);
    
        std::string getArtist();
        
};


#endif /* CD_H */

