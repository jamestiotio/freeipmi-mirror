/*
  Copyright (C) 2003-2009 FreeIPMI Core Team

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2, or (at your option)
  any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software Foundation,
  Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA.

*/

#ifndef _IPMI_FIID_UTIL_H
#define _IPMI_FIID_UTIL_H

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif /* HAVE_CONFIG_H */

#include <stdio.h>
#include <stdlib.h>
#ifdef STDC_HEADERS
#include <string.h>
#endif /* STDC_HEADERS */
#include <errno.h>

#include "freeipmi/fiid/fiid.h"

void set_errno_by_fiid_object (fiid_obj_t obj);

void set_errno_by_fiid_iterator (fiid_iterator_t iter);

int Fiid_obj_packet_valid (fiid_obj_t obj);

int Fiid_obj_template_compare (fiid_obj_t obj, fiid_template_t tmpl);

int Fiid_obj_field_lookup (fiid_obj_t obj, char *field);

#endif /* ipmi-fiid-util.h */

