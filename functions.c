int random_number(int min_num, int max_num, int modifier) {
  rander++;
  int result = 0, low_num = 0, hi_num = 0;

  if (min_num < max_num) {
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

void respawn_enemy(int enemy_number) {
  int mod = enemy_number + score + rander;
  enemies[enemy_number][0] = random_number(2, height - 2, mod);
  enemies[enemy_number][1] = random_number(2, width - 2, mod);

  if(colliding(enemy_number) == 0) {
    respawn_enemy(enemy_number);
  }
}

int colliding(int enemy_number) {
  int left = horizontal_position - spawn_pad;
  int right = horizontal_position + spawn_pad;
  int top = vertical_position - spawn_pad;
  int bottom = vertical_position + spawn_pad;

  if (
    enemies[enemy_number][0] < top || 
    enemies[enemy_number][1] < left || 
    enemies[enemy_number][0] > bottom || 
    enemies[enemy_number][1] > right 
  ) {
    return rander;
  } else {
    return 0;
  }
}

void move_player(int c) {
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
      show_fire = 1;
      for(int y = 0; y < number_of_enemies; y++) {
        if(enemies[y][0] > vertical_position && enemies[y][1] == horizontal_position) {
          score += 100;
          respawn_enemy(y);
        }
      }
      break;
    case 'i':
      fire_direction = 2;
      show_fire = 1;
      for(int y = 0; y < number_of_enemies; y++) {
        if(enemies[y][0] < vertical_position && enemies[y][1] == horizontal_position) {
          score += 100;
          respawn_enemy(y);
        }
      }
      break;
    case 'j':
      fire_direction = 3;
      show_fire = 1;
      for(int y = 0; y < number_of_enemies; y++) {
        if(enemies[y][0] == vertical_position && enemies[y][1] < horizontal_position) {
          score += 100;
          respawn_enemy(y);
        }
      }
      break;
    case 'l':
      fire_direction = 4;
      show_fire = 1;
      for(int y = 0; y < number_of_enemies; y++) {
        if(enemies[y][0] == vertical_position && enemies[y][1] > horizontal_position) {
          score += 100;
          respawn_enemy(y);
        }
      }
      break;
    case 't':
      if(show_debug == 0) {
        show_debug = 1;
      } else {
        show_debug = 0;
      }
      break;
    default:
      break;
  }
}

void move_enemies() {
  for(int y = 0; y < number_of_enemies; y++) {
    enemies[y][2] = random_number(0, jitter, enemies[y][0] + enemies[y][1]);

    if(enemies[y][2] == 1) {
      enemies[y][3] = random_number(1, 4, enemies[y + 1][0] + enemies[y + 1][1]);

      switch (enemies[y][3]) {
        case 1:
          if(enemies[y][0] + 1 < height) {
            enemies[y][0]++;
          }
          break;
        case 2:
          if(enemies[y][0] - 1 > 1) {
            enemies[y][0]--;
          }
          break;
        case 3:
          if(enemies[y][1] + 1 > 1) {
            enemies[y][1]--;
          }
          break;
        case 4:
          if(enemies[y][1] + 1 < width) {
            enemies[y][1]++;
          }
          break;
        default:
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
          break;

      }
    } else {
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
}

int death() {
  for(int y = 0; y < number_of_enemies; y++) {
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

void reset() {
  score = 0; 
  fire_direction = 0;
  show_fire = 0;
  number_of_enemies = 5;
  build_enemies();
}

void build_enemies() {
  for(int y = 0; y < 100; y++) {
    respawn_enemy(y);
  }
}

void change_level() {
  if(number_of_enemies < 100 && (number_of_enemies - 4 < score / 1000)) {
    number_of_enemies++;
  }
}
