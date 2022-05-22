#include <ncurses.h>
int main()
{ int ch;
 initscr(); /* Start curses mode */
 raw(); /* Line buffering disabled */
 keypad(stdscr, TRUE); /* We get F1, F2 etc.. */
 noecho(); /* Don't echo() while we do getch */
 printw("Type any character to see it in bold\n");
  start_color();
 init_pair(1, COLOR_WHITE, COLOR_BLACK);
 init_pair(2, COLOR_GREEN, COLOR_BLACK);
 //init_pair(3, COLOR_RED, COLOR_BLACK);
 printw("%s","Hello!!\n");
 int n=10,i=0;
 while(i<n){
 ch = getch(); /* If raw() hadn't been called
 * we have to press enter before it
 * gets to the program */
 if(ch == KEY_F(1)) /* Without keypad enabled this will */
 printw("F1 Key pressed");/* not get to us either */
 /* Without noecho() some ugly escape
 * charachters might have been printed
 * on screen */
 else if(ch==KEY_BACKSPACE){printw("%s %c","BACKSPACE pressed",ch);}
 else
 { printw("The pressed key is ");
 addch(ch|COLOR_PAIR(2));
 }i++;}
 refresh(); /* Print it on to the real screen */
 getch(); /* Wait for user input */
 endwin(); /* End curses mode */
 return 0;
}
