/*
 * $Id$
 * 
 *                This source code is part of
 * 
 *                 G   R   O   M   A   C   S
 * 
 *          GROningen MAchine for Chemical Simulations
 * 
 *                        VERSION 3.2.0
 * Written by David van der Spoel, Erik Lindahl, Berk Hess, and others.
 * Copyright (c) 1991-2000, University of Groningen, The Netherlands.
 * Copyright (c) 2001-2004, The GROMACS development team,
 * check out http://www.gromacs.org for more information.

 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * If you want to redistribute modifications, please consider that
 * scientific software is very special. Version control is crucial -
 * bugs must be traceable. We will be happy to consider code for
 * inclusion in the official distribution, but derived work must not
 * be called official GROMACS. Details are found in the README & COPYING
 * files - if they are missing, get the official version at www.gromacs.org.
 * 
 * To help us fund GROMACS development, we humbly ask that you cite
 * the papers on the package - you can find them in the top README file.
 * 
 * For more info, check our website at http://www.gromacs.org
 * 
 * And Hey:
 * Gallium Rubidium Oxygen Manganese Argon Carbon Silicon
 */

#ifndef _gentop_eemprops_h
#define _gentop_eemprops_h
	
#include <stdio.h>
#include "atomprop.h"
#include "grompp.h"

typedef struct gmx_eemprops *gmx_eemprops_t;
	
enum { eqgNone, eqgYang, eqgBultinck, eqgRappe,
       eqgSMp, eqgSMpp, eqgSMs, eqgSMps, eqgSMg, eqgSMpg, eqgNR };

/* File argument maybe NULL, in which case the default eemprops.dat
 * is opened from the library. If eemtype != -1 eemprops with eemtype
 * equal to eemtype will be read.
 */
extern gmx_eemprops_t read_eemprops(char *fn,int eemtype,gmx_atomprop_t aps);

extern void write_eemprops(FILE *fp,gmx_eemprops_t eem);

extern int name2eemtype(char *name);

extern char *get_eemtype_name(int eem);

extern char *get_eemtype_reference(int eem);

extern int eem_get_numprops(gmx_eemprops_t eem,int eemtype);

extern int eem_get_index(gmx_eemprops_t eem,int atomicnumber,int eemtype);

extern int eem_get_elem_index(gmx_eemprops_t eem,int atomicnumber,int eemtype);

extern int eem_get_row(gmx_eemprops_t eem,int index);

extern real eem_get_j00(gmx_eemprops_t eem,int index);

extern real eem_get_zeta(gmx_eemprops_t eem,int index);

extern int eem_get_elem(gmx_eemprops_t eem,int index);

extern real eem_get_chi0(gmx_eemprops_t eem,int index);

extern char *eem_get_opts(gmx_eemprops_t eem,int index);

extern void eem_set_props(gmx_eemprops_t eem,int index,real J0,real zeta,real chi0);

extern gmx_eemprops_t copy_eem(gmx_eemprops_t eem_dst,gmx_eemprops_t eem_src);
/* Copies src to dst. If dst is NULL space is allocated. A pointer
 * to dst is returned.
 */

#endif
