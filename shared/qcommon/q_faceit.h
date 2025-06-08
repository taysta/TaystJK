#ifndef TAYSTJK_Q_FACEIT_H
#define TAYSTJK_Q_FACEIT_H

//restrict cl_timenudge
#define FACEIT_MIN_TN 0
#define FACEIT_MAX_TN 0

//restrict snaps
#define FACEIT_MIN_SNAPS 20
#define FACEIT_MAX_SNAPS 60

// restrict rate
#define FACEIT_MIN_RATE 25000
#define FACEIT_MAX_RATE 90000

// restrict cl_maxpackets
#define FACEIT_MIN_PACKETS 60
#define FACEIT_MAX_PACKETS 100

// restrict cg_fov, cg_thirdpersonrange
#define FACEIT_MIN_FOV 80
#define FACEIT_MAX_FOV 100

#define FACEIT_MIN_TPR 80
#define FACEIT_MAX_TPR 100

// force cl_fovAspectAdjust 1
#define FACEIT_FOVASPECTADJUST

// force 512 cl_commandSize
#define FACEIT_COMMANDSIZE

// disable cl_idrive
#define FACEIT_IDRIVE

// force com_renderfps 0
#define FACEIT_RENDERFPS

// disable built in scripts
#define FACEIT_LOWJUMP
#define FACEIT_FLIPKICK
#define FACEIT_DUCK

#endif //TAYSTJK_Q_FACEIT_H
