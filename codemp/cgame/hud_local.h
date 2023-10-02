#if !defined( HUD_LOCAL_H )
#define HUD_LOCAL_H
#define MAX_OBITUARY 16

extern vec4_t       hud_mod_colors[MOD_MAX];
extern const char	*hud_mod_icons[MOD_MAX];

typedef struct {
    qhandle_t	icon_death; // for generic kill message
	qhandle_t	icon_mod[MOD_MAX];				// means of death icons
} hud_media_t;

extern hud_media_t hud_media;

// get all the required assets
void hud_initmedia( void );
void hud_initobituary( void );
void hud_drawobituary( void );

#endif
