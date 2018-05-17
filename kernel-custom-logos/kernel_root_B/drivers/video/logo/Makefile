# Makefile for the Linux logos

obj-$(CONFIG_LOGO)			+= logo.o
obj-$(CONFIG_LOGO_LINUX_MONO)		+= logo_linux_mono.o
obj-$(CONFIG_LOGO_LINUX_VGA16)		+= logo_linux_vga16.o
obj-$(CONFIG_LOGO_LINUX_CLUT224)	+= logo_linux_clut224.o
obj-$(CONFIG_LOGO_BLACKFIN_CLUT224)	+= logo_blackfin_clut224.o
obj-$(CONFIG_LOGO_BLACKFIN_VGA16)	+= logo_blackfin_vga16.o
obj-$(CONFIG_LOGO_DEC_CLUT224)		+= logo_dec_clut224.o
obj-$(CONFIG_LOGO_MAC_CLUT224)		+= logo_mac_clut224.o
obj-$(CONFIG_LOGO_PARISC_CLUT224)	+= logo_parisc_clut224.o
obj-$(CONFIG_LOGO_SGI_CLUT224)		+= logo_sgi_clut224.o
obj-$(CONFIG_LOGO_SUN_CLUT224)		+= logo_sun_clut224.o
obj-$(CONFIG_LOGO_SUPERH_MONO)		+= logo_superh_mono.o
obj-$(CONFIG_LOGO_SUPERH_VGA16)		+= logo_superh_vga16.o
obj-$(CONFIG_LOGO_SUPERH_CLUT224)	+= logo_superh_clut224.o
obj-$(CONFIG_LOGO_M32R_CLUT224)		+= logo_m32r_clut224.o

# Custom logos - Gabriel Marques - snortt@gmail.com
obj-$(CONFIG_LOGO_DEBIAN_BALL_BLACK_CLUT224)	+= debian_ball_black_clut224.o
obj-$(CONFIG_LOGO_DEBIAN_BALL_CLUT224) += debian_ball_clut224.o
obj-$(CONFIG_LOGO_DEBIAN_LOGO_BLUE_CLUT224) += debian_logo_blue_clut224.o
obj-$(CONFIG_LOGO_DEBIAN_LOGO_CLUT224) += debian_logo_clut224.o
obj-$(CONFIG_LOGO_LINUS_CLUT224) += linus_clut224.o
obj-$(CONFIG_LOGO_LNCC_CLUT224) += logo_lncc_clut224.o
obj-$(CONFIG_LOGO_POWERED_DEBIAN_CLUT224) += powered_by_debian_clut224.o
obj-$(CONFIG_LOGO_POWERED_LINUX_CLUT224) += powered_by_linux_clut224.o
obj-$(CONFIG_LOGO_SONIC_CLUT224) += sonic_clut224.o
obj-$(CONFIG_LOGO_TUX_ANGUS_CLUT224) += tux_angus_clut224.o
obj-$(CONFIG_LOGO_BORN_TO_FRAG_CLUT224) += tux_born_to_frag_clut224.o
obj-$(CONFIG_LOGO_TUX_DOOM_CLUT224) += tux_doom_clut224.o
obj-$(CONFIG_LOGO_TUX_DREDD_CLUT224) += tux_dredd_clut224.o
obj-$(CONFIG_LOGO_TUX_METAL_CLUT224) += tux_metal_clut224.o
obj-$(CONFIG_LOGO_TUX_NEO_CLUT224) += tux_neo_clut224.o
obj-$(CONFIG_LOGO_TUX_FIRE_CLUT224) += tux_on_fire_clut224.o
obj-$(CONFIG_LOGO_TUX_SLASH_CLUT224) += tux_slash_clut224.o;
obj-$(CONFIG_LOGO_TUX_X_LINUX_CLUT224) += tux_x_linux_clut224.o
obj-$(CONFIG_LOGO_TUX_YODA_CLUT224) += tux_yoda_clut224.o
obj-$(CONFIG_LOGO_TUX_ZOMBIE_CLUT224) += tux_zombie_clut224.o
# Custom logos - END



obj-$(CONFIG_SPU_BASE)			+= logo_spe_clut224.o

# How to generate logo's

# Use logo-cfiles to retrieve list of .c files to be built
logo-cfiles = $(notdir $(patsubst %.$(2), %.c, \
              $(wildcard $(srctree)/$(src)/*$(1).$(2))))


# Mono logos
extra-y += $(call logo-cfiles,_mono,pbm)

# VGA16 logos
extra-y += $(call logo-cfiles,_vga16,ppm)

# 224 Logos
extra-y += $(call logo-cfiles,_clut224,ppm)

# Gray 256
extra-y += $(call logo-cfiles,_gray256,pgm)

pnmtologo := scripts/pnmtologo

# Create commands like "pnmtologo -t mono -n logo_mac_mono -o ..."
quiet_cmd_logo = LOGO    $@
	cmd_logo = $(pnmtologo) \
			-t $(patsubst $*_%,%,$(notdir $(basename $<))) \
			-n $(notdir $(basename $<)) -o $@ $<

$(obj)/%_mono.c: $(src)/%_mono.pbm $(pnmtologo) FORCE
	$(call if_changed,logo)

$(obj)/%_vga16.c: $(src)/%_vga16.ppm $(pnmtologo) FORCE
	$(call if_changed,logo)

$(obj)/%_clut224.c: $(src)/%_clut224.ppm $(pnmtologo) FORCE
	$(call if_changed,logo)

$(obj)/%_gray256.c: $(src)/%_gray256.pgm $(pnmtologo) FORCE
	$(call if_changed,logo)

# Files generated that shall be removed upon make clean
clean-files := *.o *_mono.c *_vga16.c *_clut224.c *_gray256.c
