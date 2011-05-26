#ifndef _MAIN_N_
#define _MAIN_H_

#define ST_X 100
#define ST_Y 40
#define B_X 29
#define B_Y 24
#define SPACE 30

#define YELLOW 0x00eebb00
#define BLACK 0x00
#define WHITE 0x00ffffff

#define T___ YELLOW 
#define BORD 0x0f
#define X___ 0x00fffff
#define C_W 10
#define C_H 17


typedef unsigned int u32_t;
typedef unsigned char u8_t;
typedef struct
{
    int w;
    int h;
    int bpp;
    void *memo;
    
} fbscr_t;

typedef struct
{
    int dx;
    int dy;
    int dz;
    char button;
}mouse_event;

int init_screen(void);
int restore(int x, int y);
int save_bg(int x, int y);
int draw_cursor(int x, int y);
int print_board(void);
int fb_one_pixel(int x, int y, u32_t color);
int fb_line(int x1, int y1, int x2, int y2, u32_t color);
int fb_circle(int x0, int y0, int r, u32_t color);

int mouse_doing(void);
int get_m_info(int fd, mouse_event *p);
int chess_do(void);

#endif
