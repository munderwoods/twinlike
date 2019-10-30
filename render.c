void render () {
    mvprintw(vertical_position, horizontal_position, "@");
    mvprintw(0, (width * .5) - 4, "Score: %d", score);

    if(score < 2) {
      mvprintw(height * .5, (width * .5) - 12, "Move: AWSD, Shoot: JIKL");
    }

    if(show_debug == 1) {
      for(int y = 0; y < enemy_number; y++) {
        mvprintw(y, 0, "%d: V%d H%d A%d D%d", y, enemies[y][0], enemies[y][1], enemies[y][2], enemies[y][3]);
      }
    }

    if(death() == 1) {
      mvprintw(height * .5, (width * .5) - 12, "Game Over. Your Score: %d", score);
      reset();
      vertical_position = height * .5;
      horizontal_position = width * .5;
    }

    for(int y = 0; y < enemy_number; y++) {
      // mvhline(enemies[y][0], enemies[y][1], ACS_DIAMOND, 1);
      if(show_debug == 1) {
        mvprintw(enemies[y][0], enemies[y][1], "%d", y);
      } else {
        mvhline(enemies[y][0], enemies[y][1], ACS_DIAMOND, 1);
      }
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
}
