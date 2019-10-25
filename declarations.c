int score = 0; 
int c = 0; 
int width = 0; 
int height = 0; 
int vertical_position = 0, horizontal_position = 0;
int fire_direction = 0;
int fire_duration = 0;
int enemies[6][2] = {{10,10}, {15,15}, {8,8}, {7,7}, {13,13}, {999,999}};

int random_number(int min_num, int max_num, int modifier);
int kill_enemy(int enemy);
int move_player(int c);
int move_enemies();
int death();
int build_enemies();
