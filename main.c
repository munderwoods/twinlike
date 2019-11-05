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

  build_rocks();
  build_enemies();

  while (command != 'q') {
    change_level();
    clear();

    render();

    score++;
    command = 0;

    int command = getch();

    perform_action(command);
    move_enemies();
  }

  endwin();
  nocbreak();
  return 0;
}

