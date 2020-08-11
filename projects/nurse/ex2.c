 /* triangle.c */

#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
int getrandom_int(){
    return rand();
}

#define ITERMAX 10000
int main(void)
  {
      long iter;
      int yi, xi;
      int y[3], x[3];
      int index;
      int maxlines, maxcols;
      srand(time(0)); 
      /* initialize curses */

      initscr();
      cbreak();
      noecho();

      clear();

      /* initialize triangle */

      maxlines = LINES - 1;
      maxcols = COLS - 1;

      y[0] = 0;
      x[0] = 0;

      y[1] = maxlines;
      x[1] = maxcols / 2;

      y[2] = 0;
      x[2] = maxcols;

      mvaddch(y[0], x[0], '0');
      mvaddch(y[1], x[1], '1');
      mvaddch(y[2], x[2], '2');

      /* initialize yi,xi with random values */

      yi = getrandom_int() % maxlines;
      xi = getrandom_int() % maxcols;

      mvaddch(yi, xi, '.');

      /* iterate the triangle */

      for (iter = 0; iter < ITERMAX; iter++) {
          index = getrandom_int() % 3;

          yi = (yi + y[index]) / 2;
          xi = (xi + x[index]) / 2;

          mvaddch(yi, xi, '*');
          refresh();
        //   usleep(200);
      }

      /* done */

      mvaddstr(maxlines, 0, "Press any key to quit");

      refresh();

      getch();
      endwin();

      exit(0);
}
