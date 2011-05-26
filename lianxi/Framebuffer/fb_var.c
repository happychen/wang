

struct fb_var_screeninfo
{
    _u32 xres;                  /*visible resolution*/
    _u32 yres;

    _u32 xres_virtual;          /*virtual resolution*/
    _u32 yres_virtual;
    _u32 xoffset;               /*offset from virtual to visible resolution*/
    _u32 yoffset;

    _u32 bits_per_pixel;        /* guess what*/

    _u32 grayscale;             /* != 0 Gray levels instead of colors*/

    struct fb_bitfield red;     /* bitfield in fb mem if true color*/
    struct fb_bitfield green;   /* else only length is significant */
    struct fb_bitfield blue;    
    struct fb_bitfield transp;  /*transparency */

    _u32 nonstd;                /* != 0 Non standard pixel format */

    _u32 activate;              /* see FB_ACTIVATE_* */

    _u32 height;                /*height of picture in mm */ 
    _u32 width;                 /* width of picture iin mm */

    _u32 accel_flags;           /*acceleration flags (hints)*/

    /*Timing: All values in pixclocks, except pixclock (of course)*/

    _u32 pixclock;              /* pixel clock in ps (pico seconds) */
    _u32 left_margin;           /* time from sync to picture */
    _u32 right _margin;         /* time from picture to sync */
    _u32 upper_margin;          /* time from sync to picture */
    _u32 lower_margin;

    _u32 hsync_len;             /*lenght of horizontal sync */
    _u32 vsync_len;             /* lenght of vertical sync */
    _u32 sync;                  /* see FB_SYNC_* */
    _u32 vmode;                 /* see FB_VMODE_* */
    _u32 reserved[6];           /* Reserved for future compatibility */
};
