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

#include <iostream>
#include <iomanip>
#include "List.h"
#include "CD.h"
#include "DVD.h"

int mainMenu();
void cdMenu(List<CD> &);
void dvdMenu(List<DVD> &);
void cdOut(List<CD> &);
void dvdOut(List<DVD> &);
void allOut(List<CD> &, List<DVD> &);
void addCD(List<CD> &);
void addDVD(List<DVD> &);
void removeCD(List<CD> &);
void removeDVD(List<DVD> &);
void updateCD(List<CD> &);
void updateDVD(List<DVD> &);
char again();


using namespace std;

int main(int argc, const char * argv[]) {
    
    List<CD> cds;
    List<DVD> dvds;
    int choice = 0;
    char cont;
    
    //switch has the user pick what they want, then
    //runs the function, loops until the user chooses
    //to exit
    do{
        choice = mainMenu();
        
        switch (choice) {
            case 1:
                cdMenu(cds);
                cont = again();
                break;
            case 2:
                dvdMenu(dvds);
                cont = again();
                break;
            case 3:
                cdOut(cds);
                cont = again();
                break;
            case 4:
                dvdOut(dvds);
                cont = again();
                break;
            case 5:
                allOut(cds, dvds);
                cont = again();
                break;
            default:
                return 0;
                break;
        }
    } while (cont == 'y' || cont == 'Y');
    
    
    return 0;
}

//Ask the user if they want to return to the menu
char again() {
    cout << "Return to menu? Y/N ";
    char cont;
    cin >> cont;
    return cont;
}

//menu options for the main menu
int mainMenu() {
    int choice = 0;

    cout << "What would you like to do?" << endl;
    cout << "\t1. Work with CDs" << endl;
    cout << "\t2. Work with DVDs" << endl;
    cout << "\t3. Output CDs" << endl;
    cout << "\t4. Output DVDs" << endl;
    cout << "\t5. Output Both CDs and DVDs" << endl;
    cout << "\t6. Exit Program" << endl;
    cout << "Selection: ";
    cin >> choice;
    
    return choice;
}

//cd menu has the user enter what they want to do, then
//runs the corresponding function
void cdMenu(List<CD> &cds){
    int choice = 0;
    char cont = 'n';
    
    //switch for the menu
    do{
        cout << "Please select from the following:" << endl;
        cout << "\t 1. Show All CDs" << endl;
        cout << "\t 2. Add a CD" << endl;
        cout << "\t 3. Remove a CD" << endl;
        cout << "\t 4. Update a CD" << endl;
        cout << "\t 5. Return to Main Menu" << endl;
        cout << "Selection: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cdOut(cds);
                cont = again();
                break;
            case 2:
                addCD(cds);
                cont = again();
                break;
            case 3:
                removeCD(cds);
                cont = again();
                break;
            case 4:
                updateCD(cds);
                cont = again();
                break;
            default:
                cont = 'n';
                break;
        }
    } while (cont == 'Y' || cont == 'y');
}

//cd menu has the user enter what they want to do, then
//runs the corresponding function
void dvdMenu(List<DVD> &dvds){
    int choice = 0;
    char cont;
    
    do{
        //switch for the menu
        cout << "Please select from the following:" << endl;
        cout << "\t 1. Show All DVDs" << endl;
        cout << "\t 2. Add a DVD" << endl;
        cout << "\t 3. Remove a DVD" << endl;
        cout << "\t 4. Update a DVD" << endl;
        cout << "\t 5. Return to Main Menu" << endl;
        cout << "Selection: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                dvdOut(dvds);
                cont = again();
                break;
            case 2:
                addDVD(dvds);
                cont = again();
                break;
            case 3:
                removeDVD(dvds);
                cont = again();
                break;
            case 4:
                dvdOut(dvds);
                cont = again();
                break;
            default:
                cont = 'n';
                break;
        }
    } while (cont == 'Y' || cont == 'y');
}

//output the contents of the cd list
void cdOut(List<CD> &cds){
    int i = 0;
    cout << setw(15) << left << "Artist" << setw(15) << "CD Name" << setw(5) << "CD Length";
    cout << setw(15) << right << "Song Title" << setw(15) << "Song Length" << endl;
    if (cds.isEmpyty()) {
        cout << "List is empty!" << endl;
        return;
    }
    CD temp = cds.getNode(i);
    while (temp.getArtist() != "") {
        cout << i+1 << "." << setw(13) << left << temp.getArtist() << setw(15) << temp.getTitle() <<setw(5);
        cout << temp.getLength();
        temp.getSongs(i);
        i++;
        temp = cds.getNode(i);
    }
}

//output the contents of the dvd list
void dvdOut(List<DVD> &dvds) {
    int i = 0;
    cout << setw(15) << left << "Title" << setw(15) << "Year" << setw(5) << "DVD Length";
    cout << setw(15) << right << "Actors Name" << setw(15) << "Character Played" << endl;
    if (dvds.isEmpyty()) {
        cout << "List is empty!" << endl;
        return;
    }
    DVD temp = dvds.getNode(i);
    while (temp.getTitle() != "") {
        cout << i+1 << "." << setw(13) << left << temp.getTitle() << setw(15) << temp.getYear() <<setw(5);
        cout << temp.getLength();
        temp.getRoles(i);
        i++;
        temp = dvds.getNode(i);
    }
}

//run both cd and dvd out functions
void allOut(List<CD> &cds, List<DVD> &dvds){
    cdOut(cds);
    dvdOut(dvds);
}

//asks the user for all the fields regarding the cd list
//then a temporay instance of the cd class is created to
//to hold the data. cd is then passed into the cd list
void addCD(List<CD> &cds) {
    string artist;
    string albumName;
    string songTitle;
    double songLength = 0;
    char cont;
    CD add;
    
    cout << "Add a CD..." << endl;
    cout << "Artist Name: ";
    cin.ignore(256,'\n');           //an enter command kept getting stuck in the buffer, this fixed it.
    getline(cin, artist);
    cout << "Album Name: ";
    getline(cin, albumName);
    do {
        cout << "Song Title: ";
        getline(cin, songTitle);
        cout << "Song Length: ";
        cin >> songLength;
        cout << "Add another song? Y/N ";
        cin >> cont;
        cin.ignore(256,'\n');           //an enter command kept getting stuck in the buffer, this fixed it.
        add.setSongs(songTitle, songLength);
    } while (cont == 'y' or cont == 'Y');
    
    add.setTitle(albumName);
    add.setArtist(artist);
    
    cds.appendNode(add);
}

//asks the user for all the fields regarding the dvd list
//then a temporay instance of the dvd class is created to
//to hold the data. dvd is then passed into the dvd list
void addDVD(List<DVD> &dvds) {
    string dvdName;
    string actorName;
    string characterName;
    int year = 0;
    int runTime = 0;
    char cont;
    DVD add;
    
    cout << "Add a DVD..." << endl;
    cout << "Movie Name: ";
    cin.ignore(256,'\n');           //an enter command kept getting stuck in the buffer, this fixed it.
    getline(cin, dvdName);
    cout << "Year Released: ";
    cin >> year;
    cout << "Run Time: ";
    cin >> runTime;
    do {
        cin.ignore(256,'\n');           //an enter command kept getting stuck in the buffer, this fixed it.
        cout << "Actors Name: ";
        getline(cin, actorName);
        cout << "Character Played: ";
        getline(cin, characterName);
        cout << "Add another song? Y/N ";
        cin >> cont;

        add.setRoles(actorName, characterName);
    } while (cont == 'y' or cont == 'Y');
    add.setYear(year);
    add.setTitle(dvdName);
    add.setLength(runTime);
    
    dvds.appendNode(add);
    
}

//output the cd list, then ask the user which one
//they want to remove.
void removeCD(List<CD> &cds){
    if (cds.isEmpyty()) {
        cout << "List is empty!" << endl;
        return;
    }
    int remove = 0;
    cdOut(cds);
    cout << "Which would you like to remove? ";
    cin >> remove;
    cds.deleteNode(cds.getNode(remove-1));
}

//output the dvd list, then ask the user which one
//they want to remove.
void removeDVD(List<DVD> &dvds) {
    if (dvds.isEmpyty()) {
        cout << "List is empty!" << endl;
        return;
    }
    int remove = 0;
    dvdOut(dvds);
    cout << "Which would you like to remove? ";
    cin >> remove;
    dvds.deleteNode(dvds.getNode(remove-1));
}

//output the list of cds, then ask the user what they want to
//update. retake all cd info and then replace the node in the
//list
void updateCD(List<CD> &cds) {
    if (cds.isEmpyty()) {
        cout << "List is empty!" << endl;
        return;
    }
    int update = 0;
    string artist;
    string albumName;
    string songTitle;
    double songLength = 0;
    char cont;
    
    CD add;
    cdOut(cds);
    
    cout << "Which would you like to update? ";
    cin >> update;
    cout << "Add a CD..." << endl;
    cout << "Artist Name: ";
    cin.ignore(256,'\n');           //an enter command kept getting stuck in the buffer, this fixed it.
    getline(cin, artist);
    cout << "Album Name: ";
    getline(cin, albumName);
    do {
        cout << "Song Title: ";
        getline(cin, songTitle);
        cout << "Song Length: ";
        cin >> songLength;
        cout << "Add another song? Y/N ";
        cin >> cont;
        cin.ignore(256,'\n');           //an enter command kept getting stuck in the buffer, this fixed it.
        add.setSongs(songTitle, songLength);
    } while (cont == 'y' or cont == 'Y');
    
    add.setTitle(albumName);
    add.setArtist(artist);

    cds.editNode(add, update);
}

//output the list of dvds, then ask the user what they want to
//update. retake all dvd info and then replace the node in the
//list
void updateDVD(List<DVD> &dvds) {
    if (dvds.isEmpyty()) {
        cout << "The list is empty!";
        return;
    }
    int update = 0;
    string dvdName;
    string actorName;
    string characterName;
    int year = 0;
    int runTime = 0;
    char cont;
    
    DVD add;
    dvdOut(dvds);
    
    cout << "Which would yuu like to update? ";
    cin >> update;
    
    cout << "Movie Name: ";
    cin.ignore(256,'\n');           //an enter command kept getting stuck in the buffer, this fixed it.
    getline(cin, dvdName);
    cout << "Year Released: ";
    cin >> year;
    cout << "Run Time: ";
    cin >> runTime;
    do {
        cin.ignore(256,'\n');           //an enter command kept getting stuck in the buffer, this fixed it.
        cout << "Actors Name: ";
        getline(cin, actorName);
        cout << "Character Played: ";
        getline(cin, characterName);
        cout << "Add another song? Y/N ";
        cin >> cont;
        
        add.setRoles(actorName, characterName);
    } while (cont == 'y' or cont == 'Y');
    add.setYear(year);
    add.setTitle(dvdName);
    add.setLength(runTime);
    
    dvds.editNode(add, update);
}