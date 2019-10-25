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

    mvprintw(vertical_position, horizontal_position, "@");
    mvprintw(0, (width * .5) - 4, "Score: %d", score);

    if(score < 2) {
      mvprintw(height * .5, (width * .5) - 12, "Move: AWSD, Shoot: JIKL");
    }

    if(show_debug == 1) {
      for(int y = 0; enemies[y][0] != 999; y++) {
        mvprintw(y, 0, "%d: %d %d", y, enemies[y][0], enemies[y][1]);
      }
    }

    if(death() == 1) {
      mvprintw(height * .5, (width * .5) - 12, "Game Over. Your Score: %d", score);
      reset();
      vertical_position = height * .5;
      horizontal_position = width * .5;
    }

    for(int y = 0; enemies[y][0] != 999; y++) {
      mvhline(enemies[y][0], enemies[y][1], ACS_DIAMOND, 1);
    }

    if(show_fire > 0) {
      switch (fire_direction) {
        case 1:
          mvvline(vertical_position + 1, horizontal_position, ACS_VLINE, height - vertical_position);
          break;
        case 2:
          mvvline(0, horizontal_position, ACS_VLINE, vertical_position);
          break;
        case 3:
          mvhline(vertical_position, 0, ACS_HLINE, horizontal_position);
          break;
        case 4:
          mvhline(vertical_position, horizontal_position + 1, ACS_HLINE, width - 1);
          break;
        default:
          break;
      }
      show_fire--;
    }

    int c = getch();

    move_enemies();
    move_player(c);
  }

  endwin();
  nocbreak();
  return 0;
}

