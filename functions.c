int random_number(int min_num, int max_num, int modifier) {
  int result = 0, low_num = 0, hi_num = 0;

  if (min_num < max_num)
  {
    low_num = min_num;
    hi_num = max_num + 1;
  } else {
    low_num = max_num + 1;
    hi_num = min_num;
  }

  srand(time(NULL) + modifier);
  result = (rand() % (hi_num - low_num)) + low_num;
  return result;
}

int kill_enemy(int enemy) {
  enemies[enemy][0] = random_number(2, height - 2, enemy + score);
  enemies[enemy][1] = random_number(2, width - 2, enemy + score);

  if(enemies[enemy][0] == vertical_position && enemies[enemy][1] == horizontal_position) {
    kill_enemy(enemy);
  }
}

int move_player(int c) {
  switch (c) {
    case 's':
      if (vertical_position + 1 < LINES) {
        vertical_position++;
      }
      break;
    case 'w':
      if (vertical_position > 0) {
        vertical_position--;
      }
      break;
    case 'a':
      if (horizontal_position > 0) {
        horizontal_position--;
      }
      break;
    case 'd':
      if (horizontal_position + 1 < COLS) {
        horizontal_position++;
      }
      break;
    case 'k':
      fire_direction = 1;
      fire_duration = 1;
      break;
    case 'i':
      fire_direction = 2;
      fire_duration = 1;
      break;
    case 'j':
      fire_direction = 3;
      fire_duration = 1;
      break;
    case 'l':
      fire_direction = 4;
      fire_duration = 1;
      break;
    default:
      break;
  }
}

int move_enemies() {
  for(int y = 0; enemies[y][0] != 999; y++) {
    if(enemies[y][0] < vertical_position) {
      enemies[y][0]++;
    }
    if(enemies[y][0] > vertical_position) {
      enemies[y][0]--;
    }
    if(enemies[y][1] > horizontal_position) {
      enemies[y][1]--;
    }
    if(enemies[y][1] < horizontal_position) {
      enemies[y][1]++;
    }
  }
}

int death() {
  for(int y = 0; enemies[y][0] != 999; y++) {
    if(
      enemies[y][0] > vertical_position - 2 && 
      enemies[y][0] < vertical_position + 2 &&
      enemies[y][1] > horizontal_position - 2 && 
      enemies[y][1] < horizontal_position + 2
    ) {
      return 1;
    }
  }

  return 0;
}

int reset() {
  score = 0; 
  fire_direction = 0;
  fire_duration = 0;
  build_enemies();
}

int build_enemies() {
  for(int y = 0; enemies[y][0] != 999; y++) {
    kill_enemy(y);
  }
}