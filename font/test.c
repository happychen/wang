#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <linux/fb.h>
#include <ctype.h>

#include "font_8x16.c"

typedef unsigned int u32_t;
typedef char u8_t;
typedef struct
{
    int fd;
    struct fb_var_screeninfo fb_var;
    unsigned int w;
    unsigned int h;
    unsigned int bpp;
    void *fb_mem;
}info_t, *pinfo_t;

int fb_init(pinfo_t fb)
{
    int fd;
    if ((fd = open("/dev/fb0", O_RDWR)) < 0) 
    {
        perror("open /dev/fb0 error:");
        return (-1);
    }
    if (ioctl(fd, FBIOGET_VSCREENINFO, &(fb->fb_var)) == -1) 
    {
        perror("ioctl error:");
        return (-1);
    }
    fb->fd = fd;
    fb->w = fb->fb_var.xres;
    fb->h = fb->fb_var.yres;
    fb->bpp = fb->fb_var.bits_per_pixel;

    fb->fb_mem = mmap(NULL, (fb->w)*(fb->h)*(fb->bpp)/8, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (fb->fb_mem == MAP_FAILED) 
    {
        perror("mmap error:");
        return (-1);
    }
    return 0;
}

void fb_drawpixel(pinfo_t fb, int x, int y, u32_t color)
{
    int i;
    u32_t *p = (u32_t *)fb->fb_mem;

    i = x + y*fb->fb_var.xres;
    p[i] = color;
    return;
}
void fb_close(pinfo_t fb)
{
    close(fb->fd);
    munmap(fb->fb_mem, (fb->w)*(fb->h)*(fb->bpp)/8);
    return ;
}

void print_letter(const pinfo_t fb, int x, int y, char ch)
{
    int i, j;
    int n;
    int index;
    u8_t mask;
    n = toascii(ch);
    index = n * 16;

    for (i = 0; i < 16; i++) 
    {
        mask = fontdata_8x16[index + i];
        for (j = 0; j < 8; j++) 
        {
            if (((mask >> (7-j)) & 0x01) != 0) 
            {
                fb_drawpixel(fb, x+j, y+i, 0xffff00ff);
            }
        }
    }

    return ;
}
int main(int argc, const char *argv[])
{
    info_t fb;
    fb_init(&fb);

    fb_drawpixel(&fb, 500, 400, 0xff00ff00);
    print_letter(&fb, 600, 300, 'Q');
    
    fb_close(&fb);
    return 0;
}
