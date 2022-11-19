/*
 * BSD 2-Clause License
 *
 * Copyright (C) 2014-2016, Lazaros Koromilas <lostd@2f30.org>
 * Copyright (C) 2014-2016, Dimitris Papastamos <sin@2f30.org>
 * Copyright (C) 2016-2022, Arun Prakash Jana <engineerarun@gmail.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include <curses.h>
#include <wchar.h>

#define CONTROL(c) ((c)&0x1f)

#ifndef ESC
#define ESC (27)
#endif

#ifndef DEL
#define DEL (127)
#endif

/* Supported actions */
enum action
{
	SEL_BACK = 1,
	SEL_OPEN,
	SEL_NAV_IN,
	SEL_NEXT,
	SEL_PREV,
	SEL_PGDN,
	SEL_PGUP,
	SEL_CTRL_D,
	SEL_CTRL_U,
	SEL_HOME,
	SEL_END,
	SEL_FIRST,
	SEL_JUMP,
	SEL_CDHOME,
	SEL_CDBEGIN,
	SEL_CDLAST,
	SEL_CDROOT,
	SEL_BMOPEN,
	SEL_REMOTE,
	SEL_CYCLE,
	SEL_CYCLER,
	SEL_CTX1,
	SEL_CTX2,
	SEL_CTX3,
	SEL_CTX4,
#ifdef CTX8
	SEL_CTX5,
	SEL_CTX6,
	SEL_CTX7,
	SEL_CTX8,
#endif
	SEL_MARK,
	SEL_BMARK,
	SEL_FLTR,
	SEL_MFLTR,
	SEL_HIDDEN,
	SEL_DETAIL,
	SEL_STATS,
	SEL_CHMODX,
	SEL_ARCHIVE,
	SEL_SORT,
	SEL_REDRAW,
	SEL_SEL,
	SEL_SELMUL,
	SEL_SELALL,
	SEL_SELINV,
	SEL_SELEDIT,
	SEL_CP,
	SEL_MV,
	SEL_CPMVAS,
	SEL_RM,
	SEL_OPENWITH,
	SEL_NEW,
	SEL_RENAME,
	SEL_RENAMEMUL,
	SEL_UMOUNT,
	SEL_HELP,
	SEL_AUTONEXT,
	SEL_EDIT,
	SEL_PLUGIN,
	SEL_SHELL,
	SEL_LAUNCH,
	SEL_PROMPT,
	SEL_LOCK,
	SEL_SESSIONS,
	SEL_EXPORT,
	SEL_TIMETYPE,
	SEL_QUITCTX,
	SEL_QUITCD,
	SEL_QUIT,
	SEL_QUITERR,
#ifndef NOMOUSE
	SEL_CLICK,
#endif
};

/* Associate a pressed key to an action */
struct key
{
	wint_t sym;		 /* Key pressed */
	enum action act; /* Action */
};

// Right
// hot actoins = lyhosk;'
// secondary = []09

// Left
// hot actions = rst
// 				wfpgvb/
// secondary = `zcx
//
// Done
// arrows = ueni
// d = delete
// a = new
// q = quit
// ~ = home
//

static struct key bindings[] = {
	/* Back */
	{KEY_LEFT, SEL_BACK},
	{'n', SEL_BACK},
	/* Inside or select */
	{KEY_ENTER, SEL_OPEN},
	{'\r', SEL_OPEN},
	/* Pure navigate inside */
	{KEY_RIGHT, SEL_NAV_IN},
	{'i', SEL_NAV_IN},
	/* Next */
	{'e', SEL_NEXT},
	{KEY_DOWN, SEL_NEXT},
	/* Previous */
	{'u', SEL_PREV},
	{KEY_UP, SEL_PREV},
	/* HOME */
	{'~', SEL_CDHOME},
	/* Go to/create context N */
	{'1', SEL_CTX1},
	{'2', SEL_CTX2},
	{'3', SEL_CTX3},
	{'4', SEL_CTX4},
#ifdef CTX8
	{'5', SEL_CTX5},
	{'6', SEL_CTX6},
	{'7', SEL_CTX7},
	{'8', SEL_CTX8},
#endif
	/* Copy from selection buffer */
	{'p', SEL_CP},
	{CONTROL('P'), SEL_CP},
	/* Move from selection buffer */
	{'m', SEL_MV},
	{CONTROL('M'), SEL_MV},
	/* Filter */
	{'f', SEL_FLTR},
	/* Toggle filter mode */
	{CONTROL('F'), SEL_MFLTR},
	/* Toggle hide .dot files */
	{'.', SEL_HIDDEN},
	/* Delete from selection buffer */
	{'d', SEL_RM},
	{CONTROL('D'), SEL_RM},
	/* Run command */
	{'w', SEL_SHELL},
#ifndef NOMOUSE
	{KEY_MOUSE, SEL_CLICK},
#endif
	/* Select current file path */
	{' ', SEL_SEL},
	/* Sort toggles */
	{']', SEL_SORT},
	/* Detailed listing */
	{'\\', SEL_DETAIL},
	/* Edit in EDITOR */
	{'/', SEL_EDIT},
	/* Toggle executable status */
	{'*', SEL_CHMODX},
	/* Create archive */
	{'z', SEL_ARCHIVE},
	/* Quit a context */
	{'q', SEL_QUITCTX},
	/* Create a new file */
	{'a', SEL_NEW},
	/* Show rename prompt */
	{'r', SEL_RENAME},
	/* Rename contents of current dir */
	//? {'R', SEL_RENAMEMUL},
	/* Select all files in current dir */
	{'X', SEL_SELINV},
	/* Invert selection in current dir */
	{'A', SEL_SELALL},
	/* Redraw window */
	{ 's',   SEL_REDRAW },
	{ 'h',   SEL_BMOPEN },

    /* File details */
	// { 'f',            SEL_STATS },
	// { CONTROL(']'),   SEL_SHELL },
	/* Page down */
	// { KEY_NPAGE,      SEL_PGDN },
	/* Page up */
	// { KEY_PPAGE,      SEL_PGUP },
	/* Ctrl+D */
	// { CONTROL('D'),   SEL_CTRL_D },
	/* Ctrl+U */
	// { CONTROL('U'),   SEL_CTRL_U },
	/* First entry */
	// { KEY_HOME,       SEL_HOME },
	// { 'g',            SEL_HOME },
	// { CONTROL('A'),   SEL_HOME },
	/* Last entry */
	// { KEY_END,        SEL_END },
	// { 'G',            SEL_END },
	// { CONTROL('E'),   SEL_END },
	/* Go to first file */
	// { '\'',           SEL_FIRST },
	/* Jump to an entry number/offset */
	// { 'J',            SEL_JUMP },
	/* Initial directory */
	// { '@',            SEL_CDBEGIN },
	/* Last visited dir */
	// { '-',            SEL_CDLAST },
	/* Go to / */
	// { '`',            SEL_CDROOT },
	/* Leader key */
	// { 'b',            SEL_BMOPEN },
	// { CONTROL('_'),   SEL_BMOPEN },
	/* Connect to server over SSHFS */
	// { 'c',            SEL_REMOTE },
	/* Cycle contexts in forward direction */
	// { '\t',           SEL_CYCLE },
	/* Cycle contexts in reverse direction */
	{KEY_BTAB, SEL_CYCLER},
	/* Mark a path to visit later */
	{',', SEL_MARK},
	/* Create a bookmark */
	{'B', SEL_BMARK},
	// { CONTROL('F'),   SEL_STATS },
	// { CONTROL('T'),   SEL_SORT },
	// {'+', SEL_SEL},
	/* Toggle select multiple files */
	{'m', SEL_SELMUL},
	/* List, edit selection */
	{'E', SEL_SELEDIT},
	/* Copy/move from selection buffer and rename */
	{'w', SEL_CPMVAS},
	{CONTROL('W'), SEL_CPMVAS},
	/* Open in a custom application */
	{'o', SEL_OPENWITH},
	{CONTROL('O'), SEL_OPENWITH},
	/* Disconnect a SSHFS mount point */
	{'k', SEL_UMOUNT},
	/* Show help */
	{'?', SEL_HELP},
	/* Toggle auto-advance on file open */
	{CONTROL('J'), SEL_AUTONEXT},
	/* Run a plugin */
	{';', SEL_PLUGIN},
	/* Launcher */
	{'=', SEL_LAUNCH},
	/* Show command prompt */
	{']', SEL_PROMPT},
	/* Lock screen */
	{'0', SEL_LOCK},
	/* Manage sessions */
	// {'s', SEL_SESSIONS},
	/* Export list */
	{'>', SEL_EXPORT},
	/* Set time type */
	{'T', SEL_TIMETYPE},
	/* Change dir on quit */
	{CONTROL('G'), SEL_QUITCD},
	/* Quit */
	// { CONTROL('Q'),   SEL_QUIT },
	/* Quit with an error code */
	// { 'Q',            SEL_QUITERR },
};
