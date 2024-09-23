#include <ncurses.h>
#include <list>
#include <iostream>

int main() {
    initscr();          
    noecho();           
    cbreak();          
    std::list<char> charList; 
    char ch;

    while ((ch = getch()) != 'q') {
        if (ch != ERR) {
            clear();
            charList.push_back(ch);  

            printw("Characters entered:\n");  
            for (char c : charList) {
                printw("%c\n", c);  
            }

            refresh();  
        }
    }

    endwin();

    std::cout << "Final List (reversed order):" << std::endl;
    for (auto it = charList.rbegin(); it != charList.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}