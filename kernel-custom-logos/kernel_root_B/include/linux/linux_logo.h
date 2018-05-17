#ifndef _LINUX_LINUX_LOGO_H
#define _LINUX_LINUX_LOGO_H

/*
 *  Linux logo to be displayed on boot
 *
 *  Copyright (C) 1996 Larry Ewing (lewing@isc.tamu.edu)
 *  Copyright (C) 1996,1998 Jakub Jelinek (jj@sunsite.mff.cuni.cz)
 *  Copyright (C) 2001 Greg Banks <gnb@alphalink.com.au>
 *  Copyright (C) 2001 Jan-Benedict Glaw <jbglaw@lug-owl.de>
 *  Copyright (C) 2003 Geert Uytterhoeven <geert@linux-m68k.org>
 *
 *  Serial_console ascii image can be any size,
 *  but should contain %s to display the version
 */

#include <linux/init.h>


#define LINUX_LOGO_MONO		1	/* monochrome black/white */
#define LINUX_LOGO_VGA16	2	/* 16 colors VGA text palette */
#define LINUX_LOGO_CLUT224	3	/* 224 colors */
#define LINUX_LOGO_GRAY256	4	/* 256 levels grayscale */


struct linux_logo {
	int type;			/* one of LINUX_LOGO_* */
	unsigned int width;
	unsigned int height;
	unsigned int clutsize;		/* LINUX_LOGO_CLUT224 only */
	const unsigned char *clut;	/* LINUX_LOGO_CLUT224 only */
	const unsigned char *data;
};

extern const struct linux_logo logo_linux_mono;
extern const struct linux_logo logo_linux_vga16;
extern const struct linux_logo logo_linux_clut224;
extern const struct linux_logo logo_blackfin_vga16;
extern const struct linux_logo logo_blackfin_clut224;
extern const struct linux_logo logo_dec_clut224;
extern const struct linux_logo logo_mac_clut224;
extern const struct linux_logo logo_parisc_clut224;
extern const struct linux_logo logo_sgi_clut224;
extern const struct linux_logo logo_sun_clut224;
extern const struct linux_logo logo_superh_mono;
extern const struct linux_logo logo_superh_vga16;
extern const struct linux_logo logo_superh_clut224;
extern const struct linux_logo logo_m32r_clut224;
extern const struct linux_logo logo_spe_clut224;

/* Custom logos by Gabriel Marques - snortt@gmail.com */
extern const struct linux_logo debian_ball_black_clut224;
extern const struct linux_logo logo_lncc_clut224;
extern const struct linux_logo powered_by_debian_clut224;
extern const struct linux_logo tux_neo_clut224;
extern const struct linux_logo debian_ball_clut224;
extern const struct linux_logo powered_by_linux_clut224;
extern const struct linux_logo tux_on_fire_clut224;
extern const struct linux_logo debian_logo_blue_clut224;
extern const struct linux_logo sonic_clut224;
extern const struct linux_logo tux_slash_clut224;
extern const struct linux_logo debian_logo_clut224;
extern const struct linux_logo tux_angus_clut224;      
extern const struct linux_logo tux_x_linux_clut224;
extern const struct linux_logo linus_clut224;      
extern const struct linux_logo tux_born_to_frag_clut224;
extern const struct linux_logo tux_yoda_clut224;
extern const struct linux_logo tux_doom_clut224;     
extern const struct linux_logo tux_zombie_clut224;
extern const struct linux_logo tux_dredd_clut224;
extern const struct linux_logo tux_metal_clut224;
/* Custom Logos -- END */

extern const struct linux_logo *fb_find_logo(int depth);
#ifdef CONFIG_FB_LOGO_EXTRA
extern void fb_append_extra_logo(const struct linux_logo *logo,
				 unsigned int n);
#else
static inline void fb_append_extra_logo(const struct linux_logo *logo,
					unsigned int n)
{}
#endif

#endif /* _LINUX_LINUX_LOGO_H */
