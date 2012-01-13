/*****************************************************************************\
 *  $Id: ipmipower_util.c,v 1.37 2010-02-08 22:02:31 chu11 Exp $
 *****************************************************************************
 *  Copyright (C) 2007-2012 Lawrence Livermore National Security, LLC.
 *  Copyright (C) 2003-2007 The Regents of the University of California.
 *  Produced at Lawrence Livermore National Laboratory (cf, DISCLAIMER).
 *  Written by Albert Chu <chu11@llnl.gov>
 *  UCRL-CODE-155698
 *
 *  This file is part of Ipmipower, a remote power control utility.
 *  For details, see http://www.llnl.gov/linux/.
 *
 *  Ipmipower is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by the
 *  Free Software Foundation; either version 3 of the License, or (at your
 *  option) any later version.
 *
 *  Ipmipower is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 *  or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 *  for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with Ipmipower.  If not, see <http://www.gnu.org/licenses/>.
\*****************************************************************************/

#if HAVE_CONFIG_H
#include "config.h"
#endif /* HAVE_CONFIG_H */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#if STDC_HEADERS
#include <string.h>
#include <stdarg.h>
#endif /* STDC_HEADERS */
#if HAVE_UNISTD_H
#include <unistd.h>
#endif /* HAVE_UNISTD_H */
#include <assert.h>
#include <errno.h>

#include "ipmipower_oem.h"
#include "ipmipower_util.h"

#include "freeipmi-portability.h"
#include "cbuf.h"

extern struct ipmipower_arguments cmd_args;

struct oem_power_type_data oem_power_type_data[] =
  { 
    /*
     * OEM_POWER_TYPE_NONE
     */
    {
      "none",
      OEM_POWER_TYPE_SUPPORT_ALL,
    },

    /*
     * OEM_POWER_TYPE_C410X - supports off, on, status
     */
    {
      "C410X",
      OEM_POWER_TYPE_SUPPORT_OFF | OEM_POWER_TYPE_SUPPORT_ON | OEM_POWER_TYPE_SUPPORT_STATUS,
    },

    {
      NULL,
      0,
    },
  };

static int
_power_cmd_to_oem_power_type_support (power_cmd_t cmd)
{
  assert (POWER_CMD_VALID (cmd));

  if (cmd == POWER_CMD_POWER_OFF)
    return (OEM_POWER_TYPE_SUPPORT_OFF);
  else if (cmd == POWER_CMD_POWER_ON)
    return (OEM_POWER_TYPE_SUPPORT_ON);
  else if (cmd == POWER_CMD_POWER_CYCLE)
    return (OEM_POWER_TYPE_SUPPORT_CYCLE);
  else if (cmd == POWER_CMD_POWER_RESET)
    return (OEM_POWER_TYPE_SUPPORT_RESET);
  else if (cmd == POWER_CMD_POWER_STATUS)
    return (OEM_POWER_TYPE_SUPPORT_STATUS);
  else if (cmd == POWER_CMD_PULSE_DIAG_INTR)
    return (OEM_POWER_TYPE_SUPPORT_DIAG_INTR);
  else if (cmd == POWER_CMD_SOFT_SHUTDOWN_OS)
    return (OEM_POWER_TYPE_SUPPORT_SOFT_SHUTDOWN_OS);
  else if (cmd == POWER_CMD_IDENTIFY_ON)
    return (OEM_POWER_TYPE_SUPPORT_IDENTIFY_ON);
  else if (cmd == POWER_CMD_IDENTIFY_OFF)
    return (OEM_POWER_TYPE_SUPPORT_IDENTIFY_OFF);
  else /* cmd == POWER_CMD_IDENTIFY_STATUS */
    return (OEM_POWER_TYPE_SUPPORT_IDENTIFY_STATUS);
}

int
ipmipower_oem_power_cmd_check_support_and_privilege (power_cmd_t cmd,
						     char *errbuf,
						     unsigned int errbuflen)
{
  unsigned int oem_power_type_support_mask;
  char *power_cmd_str;
  int rv = -1;
  
  assert (POWER_CMD_VALID (cmd));
  assert (errbuf);
  assert (errbuflen);
  assert (cmd_args.oem_power_type != OEM_POWER_TYPE_NONE);

  oem_power_type_support_mask = _power_cmd_to_oem_power_type_support (cmd);
  
  power_cmd_str = ipmipower_power_cmd_to_string (cmd);
  
  if (!(oem_power_type_data[cmd_args.oem_power_type].supported_operations & oem_power_type_support_mask))
    {
      snprintf (errbuf,
		errbuflen,
		"'%s' operation not supported by oem power type '%s'",
		power_cmd_str,
		oem_power_type_data[cmd_args.oem_power_type].name);
      rv = 0;
      goto cleanup;
    }
  
  if (cmd_args.oem_power_type == OEM_POWER_TYPE_C410X)
    {
      /* XXX - I'm pretty sure */
      if ((cmd == POWER_CMD_POWER_OFF
	   || cmd == POWER_CMD_POWER_ON)
	  && cmd_args.common.privilege_level == IPMI_PRIVILEGE_LEVEL_ADMIN)
	{
	  snprintf (errbuf,
		    errbuflen,
		    "'%s' requires admin privilege for oem power type '%s'",
		    power_cmd_str,
		    oem_power_type_data[cmd_args.oem_power_type].name);
	  rv = 0;
	  goto cleanup;
	} 
    }

  rv = 1;
 cleanup:
  return (rv);
}
