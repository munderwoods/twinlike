#include "links.c"
int main(void) {
  initscr();
  curs_set (0);
  noecho();
  cbreak();
  keypad(stdscr, TRUE);

  width = COLS;
  height = LINES;
  vertical_position = height * .5;
  horizontal_position = width * .5;

  build_enemies();

  while (c != 'q') {
    clear();

    score++;
    c = 0;

    render();

    int c = getch();

    move_enemies();
    move_player(c);
  }

  endwin();
  nocbreak();
  return 0;
}

