#include <ncurses.h>
#include <unistd.h>

#define DELAY 20000

int main(int argc, char *argv[]) {
 int x = 0, y = 0;
 int max_y = 0, max_x = 0;
 int next_y = 0, next_x = 0;
 int y_direction = 1, x_direction = 1;

 initscr();
 noecho();
 curs_set(FALSE);

 // Global var `stdscr` is created by the call to `initscr()`
 getmaxyx(stdscr, max_y, max_x);

 while(1) {
	 getmaxyx(stdscr, max_y, max_x);

	 clear();
	 mvprintw(y, x, "Your Mum");
	 refresh();
	 clear();
	 mvprintw(y, x, "Your Mum");
	 refresh();

	 usleep(DELAY);

	 next_x = x + x_direction;
	 next_y = y + y_direction;

	 if (next_x >= max_x-7 || next_x < 0) {
		 x_direction*= -1;
	 } else {
		 x+= x_direction;
	 }
	 if (next_y >= max_y || next_y < 0) {
		 y_direction*= -1;
	 } else {
		 y+= y_direction;
	 }
 }

 endwin();
}
