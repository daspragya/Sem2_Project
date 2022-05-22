#include <ncurses.h>
#include<stdlib.h>
#include<string.h>

/*THE BACKSPACE IS NOT GETTING ACCESSED SO INSTEAD OF BACKSPACE I'VE USED ENTER FOR SAME STUFF.
MEANING, ENTER WORKS LIKE BACKSPACE*/

void addtext(char ch, int *i, char *a, char *chs)
{if(ch=='\n'){*i=*i-2;chs[*i+1]='\0';mvaddch(1,*i+1,a[*i+1]|COLOR_PAIR(1));}
 else if(('A'<=ch && ch<='Z') | ('a'<=ch && ch<='z') | ('0'<=ch && ch<='9') | ch=='!' | ch==',' | ch==' '| ch=='.')
 	{if(a[*i]==chs[*i]){mvaddch(1,*i,ch|COLOR_PAIR(2));}
 	 else{mvaddch(1,*i,ch|COLOR_PAIR(3));}}
 else{*i=*i-1;mvprintw(2,*i,"%c",ch);}}

int wpm();

void check(char *a, char *chs, int n, int mis)
{
	for(int i=0;i<n-1;i++)
	{if(a[i]!=chs[i]){mis++;}mvprintw(2,0,"Mistakes:%d",mis);}
}

int main()
{initscr();
 raw();
 keypad(stdscr,TRUE);
 noecho();
 start_color();
 init_pair(1, COLOR_WHITE, COLOR_BLACK);
 init_pair(2, COLOR_GREEN, COLOR_BLACK);
 init_pair(3, COLOR_RED, COLOR_BLACK);
 attron(COLOR_PAIR(1)|A_BOLD);
 printw("%s","Hello!!\n");
 char a[]="This is a test text to check your speed!";
 int n=sizeof(a)/sizeof(a[0]);
 printw("%s",a);addch('\n');refresh();
 attroff(COLOR_PAIR(1)|A_BOLD);
 char chs[n]; int ch;
 int i=0;
 while(i<n-1)
 {ch=getch();chs[i]=ch;addtext(ch,&i,a,chs);i++;}
 check(a,chs,n,0);
 getch();
 endwin();
}
