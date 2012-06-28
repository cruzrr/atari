/*
 * proto/TS6.c
 * An implementation of the TS6 IRC protocol.
 *
 * See doc/TS6.txt for more info on TS6.
 * Copyright (C) 2012 cruzrr
 *
 * This software is free software; rights to this code are
 * stated in doc/LICENSE.
 */

#include "TS6.h"
#include <atari.h>
#include <atari/mod.h>
#include <atari/protomod.h>

void mod_init()
{
	struct atari_mod_info modinfo;
	struct atari_proto_settings protosettings;
	struct atari_proto_handlers protohandlers;
	struct atari_proto_cmodes   protocmodes;

	/* fill in some information about the module. */
	modinfo.name	= "proto/TS6";
	modinfo.ver	= "0.1";
	modinfo.author	= "cruzrr";

	atari_register_mod(modinfo);

	/* protocol settings */
	protocmodes.b		= 2;
	protocmodes.q		= 2;
	protocmodes.e		= 2;
	protocmodes.I		= 2;
	protocmodes.j		= 2;
	protocmodes.l		= 2;
	protocmodes.k		= 2;
	protocmodes.f		= 2;
	protocmodes.n		= 1;
	protocmodes.t		= 1;
	protocmodes.i		= 1;
	protocmodes.P		= 1;
	protocmodes.L		= 1;
	protocmodes.Q		= 1;
	protocmodes.s		= 1;
	protocmodes.C		= 1;
	protocmodes.F		= 1;
	protocmodes.z		= 1;
	protocmodes.g		= 1;
	protocmodes.c		= 1;
	protocmodes.m		= 1;
	protocmodes.p		= 1;
	protocmodes.r		= 1;

	protosettings.name	= "TS6 IRCd";
	protosettings.op	= 'o';
	protosettings.voice	= 'v';
	protosettings.mute	= 'q';
	protosettings.banexcept	= 'e';
	protosettings.iexcept	= 'I';
	protosettings.god	= 'S';
	protosettings.deaf	= 'D';
	protosettings.cmodes	= protocmodes;

	atari_proto_loadsettings(protosettings);

	/* fill in the protocol handlers */
	protohandlers.euid	= _ts6_euid;
	protohandlers.ping	= _ts6_ping;
	protohandlers.sjoin	= _ts6_sjoin;
	protohandlers.quit	= _ts6_quit;
	protohandlers.join	= _ts6_join;
	protohandlers.nick	= _ts6_nick;
	protohandlers.chghost	= _ts6_chghost;
	protohandlers.error	= _ts6_error;
	protohandlers.privmsg	= _ts6_privmsg;
	protohandlers.notice	= _ts6_notice;
	protohandlers.part	= _ts6_part;
	protohandlers.mode	= _ts6_mode;
	protohandlers.sid	= _ts6_sid;
	protohandlers.squit	= _ts6_squit;
	protohandlers.away	= _ts6_away;
	protohandlers.kill	= _ts6_kill;
	protohandlers.save	= _ts6_save;
	protohandlers.encap	= _ts6_encap;
	protohandlers.kick	= _ts6_kick;
	protohandlers.tb	= _ts6_tb;
	protohandlers.motd	= _ts6_motd;
	protohandlers.admin	= _ts6_admin;
	protohandlers.tmode	= _ts6_tmode;
	protohandlers.mlock	= _ts6_mlock;
	protohandlers.ban	= _ts6_ban;

	atari_proto_loadhandlers(protohandlers);
}
