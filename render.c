void render () {
    mvprintw(vertical_position, horizontal_position, "@");
    mvprintw(0, (width * .5) - 4, "Score: %d", score);

    if(score < 2) {
      mvprintw(height * .5, (width * .5) - 12, "Move: AWSD, Shoot: JIKL");
    }

    if(show_debug == 1) {
      for(int y = 0; y < number_of_enemies; y++) {
        mvprintw(y, 0, "%d: V%d H%d A%d D%d", y, enemies[y][0], enemies[y][1], enemies[y][2], enemies[y][3]);
      }
    }

    if(death() == 1) {
      mvprintw(height * .5, (width * .5) - 12, "Game Over. Your Score: %d", score);
      reset();
      vertical_position = height * .5;
      horizontal_position = width * .5;
    }

    for(int y = 0; y < number_of_rocks; y++) {
      if(show_debug == 1) {
        mvprintw(rocks[y][0], rocks[y][1], "%d", y);
      } else {
        mvhline(rocks[y][0], rocks[y][1], ACS_CKBOARD, 1);
      }
    }

    for(int y = 0; y < number_of_enemies; y++) {
      if(show_debug == 1) {
        mvprintw(enemies[y][0], enemies[y][1], "%d", y);
      } else {
        mvhline(enemies[y][0], enemies[y][1], ACS_DIAMOND, 1);
      }
    }

    if(show_fire > 0) {
      int end;
      switch (fire_direction) {
        case 1:
          end = height - 1;
          for(int y = vertical_position; y <= end; y++) {
            if(on_rock(y, horizontal_position) == 1) {
              end = y - vertical_position - 1;
              break;
            }
          }
          mvvline(vertical_position + 1, horizontal_position, ACS_VLINE, end);
          break;
        case 2:
          end = 0;
          for(int y = vertical_position; y >= 0; y--) {
            if(on_rock(y, horizontal_position) == 1) {
              end = y + 1;
              break;
            }
          }
          mvvline(end, horizontal_position, ACS_VLINE, vertical_position - end);
          break;
        case 3:
          end = 0;
          for(int y = horizontal_position; y >= 0; y--) {
            if(on_rock(vertical_position, y) == 1) {
              end = y + 1;
              break;
            }
          }
          mvhline(vertical_position, end, ACS_HLINE, horizontal_position - end);
          break;
        case 4:
          end = width - 1;
          for(int y = horizontal_position; y <= end; y++) {
            if(on_rock(vertical_position, y) == 1) {
              end = y - horizontal_position - 1;
              break;
            }
          }
          mvhline(vertical_position, horizontal_position + 1, ACS_HLINE, end);
          break;
        default:
          break;
      }
      show_fire--;
    }
}
