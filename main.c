#ifdef _WIN32
#   include <curses.h>
#else
#   include <ncurses.h>
#endif

#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "intro.h"
#include "pass.h"
#include "wordParse.h"

int main(int argc, char * argv[]){

    if(argc > 1 && !strcmp(argv[1], "--help")){
        printf("Usage: %s [--DIFFICULTY]\n\n[--DIFFICULTY] is an optional argument"
                " that uses built in words instead\nof words specifed in the config"
                " file. Options are:\n\n"
                "--veryEasy,\t10 words, 5 letters per word (default)\n\n"
                "--easy,\t\t11 words, 7 letters per word\n\n"
                "--average,\t14 words, 9 letters per word\n\n"
                "--hard,\t\t7 words, 11 letters per word\n\n"
                "--veryHard,\t13 words, 12 letters per word\n\n"
                , argv[0]);
        exit(0);
    }

    FILE *fp = NULL;

    if(argc > 1){
        if(!strcmp(argv[1], "--easy")) {
           setEasy();
        } 
        else if(!strcmp(argv[1], "--average")) {
           setAverage();
        } 
        else if(!strcmp(argv[1], "--hard")) {
           setHard();
        } 
        else if(!strcmp(argv[1], "--veryHard")) {
           setVeryHard();
        } 
        else {
            setVeryEasy();
        }
    }
    else {    

        fp = fopen("FalloutTerminal.cfg", "r");

        readWordsFromFile(fp);
    }


    srand ( (unsigned)time(NULL) );
    initscr();
    noecho();
    refresh();
    attron(A_BOLD);
    nodelay(stdscr, 1);
    if(has_colors() == 1){
        /* Colors */
        start_color();
        init_pair(1,COLOR_GREEN,COLOR_BLACK);
        attron(COLOR_PAIR(1));
    }



    intro();
    pass();

    if(fp != NULL) {
        fclose(fp);
    }

    return 0;
}

