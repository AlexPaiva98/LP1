#include <iostream>

#include "../include/Diary.h"

int main(int argc, char* argv[]){

    Diary diary("diary.md");

    // Add
    for (int x = 0; x < diary.messages_capacity; x++) {
        diary.add("Teste X");
    }

    // Print
    for (int x = 0; x < diary.messages_size; x++) {
        std::cout 
            << diary.messages[x].date.day 
            << "/" 
            <<  diary.messages[x].date.month 
            << "/"
            << diary.messages[x].date.year
            << std::endl;

        std::cout 
            << diary.messages[x].time.hour 
            << ":" 
            <<  diary.messages[x].time.minute 
            << ":"
            << diary.messages[x].time.second
            << " ";
        
        std::cout << diary.messages[x].content << std::endl;
    }

    return 0;

}
