int score = 0; 
int c = 0; 
int width = 0; 
int height = 0; 
int vertical_position = 0, horizontal_position = 0;
int fire_direction = 0;
int fire_duration = 0;
int enemies[6][2] = {{0,0}, {0,0}, {0,0}, {0,0}, {0,0}, {999,999}};

int random_number(int min_num, int max_num, int modifier);
void respawn_enemy(int enemy);
void move_player(int c);
void move_enemies();
int death();
void build_enemies();
