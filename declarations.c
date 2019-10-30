int score = 0; 
int command = 0; 
int width = 0; 
int height = 0; 
int vertical_position = 0, horizontal_position = 0;
int fire_direction = 0;
int show_fire = 0;
int show_debug = 0;
int jitter = 2;
int rander = 0;
int spawn_pad = 15;
int number_of_enemies = 5;
int enemies[100][4];

void render();

int random_number(int min_num, int max_num, int modifier);
void respawn_enemy(int enemy);
void move_player(int c);
void move_enemies();
int death();
void build_enemies();
void reset();
void change_level();
int colliding(int enemy);
