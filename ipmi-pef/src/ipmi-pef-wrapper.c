#if HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#if STDC_HEADERS
#include <string.h>
#endif /* STDC_HEADERS */
#if HAVE_UNISTD_H
#include <unistd.h>
#endif	/* HAVE_UNISTD_H */
#ifdef HAVE_ERROR_H
#include <error.h>
#endif
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/resource.h>
#if TIME_WITH_SYS_TIME
#include <sys/time.h>
#include <time.h>
#else /* !TIME_WITH_SYS_TIME */
#if HAVE_SYS_TIME_H
#include <sys/time.h>
#else /* !HAVE_SYS_TIME_H */
#include <time.h>
#endif /* !HAVE_SYS_TIME_H */
#endif /* !TIME_WITH_SYS_TIME */
#include <argp.h>

#include "freeipmi/fiid.h"
#include "freeipmi/ipmi-pef-and-alerting-cmds.h"
#include "freeipmi/ipmi-pef-param-spec.h"
#include "freeipmi/udm/ipmi-pef-and-alerting-cmds-udm.h"

#include "err-wrappers.h"
#include "fiid-wrappers.h"
#include "freeipmi-portability.h"
#include "ipmi-common.h"

#include "common-utils.h"

#include "ipmi-pef-wrapper.h"

#define GET_INT_VALUE_BY_KEY(__cache_record, __key, __i) \
do 							 \
  {							 \
    if (_get_int_value_by_key (__cache_record, 		 \
			       __key, 			 \
			       __i) == -1)      	 \
      {							 \
	return (-1);					 \
      }							 \
  }                                                      \
 while (0)


#define GET_STRING_VALUE_BY_KEY(__cache_record, __key, __s)  \
do 							     \
  {							     \
    if (_get_string_value_by_key (__cache_record, 	     \
				  __key, 		     \
				  __s) == -1)		     \
      {							     \
	return (-1);					     \
      }							     \
  }                                                          \
 while (0)


static int 
_get_value_by_key (char *cache_record, 
		   char *key, 
		   char **value)
{
  char *skey = NULL;
  char *start_pos = NULL;
  char *value_ptr = NULL;
  char *value_end_ptr = NULL;
  
  skey = alloca (strlen (key) + 3);
  strcpy (skey, key);
  strcat (skey, "=");
  
  start_pos = strcasestr (cache_record, skey);
  if (start_pos != cache_record)
    {
      strcpy (skey, "\n");
      strcat (skey, key);
      strcat (skey, "=");
      start_pos = strcasestr (cache_record, skey);
    }
  
  if (start_pos == NULL)
    return (-1);
  
  value_ptr = start_pos + strlen (skey);
  value_end_ptr = strcasestr (value_ptr, "\n");
  if (value_end_ptr == NULL)
    {
      *value = strdup (value_ptr);
      return 0;
    }
  *value = strndup (value_ptr, (value_end_ptr - value_ptr));
  return 0;
}

static int 
_get_int_value_by_key (char *cache_record, 
		       char *key, 
		       int *i)
{
  char *value_ptr = NULL;
  int rv = 0;
  
  if (_get_value_by_key (cache_record, 
			 key, 
			 &value_ptr) == -1)
    {
      return (-1);
    }
  
  rv = str2int (value_ptr, 0, i);
  
  free (value_ptr);
  
  return rv;
}

static int 
_get_string_value_by_key (char *cache_record, 
			  char *key, 
			  char **s)
{
  char *value_ptr = NULL;
  
  if (_get_value_by_key (cache_record, 
			 key, 
			 &value_ptr) == -1)
    {
      return (-1);
    }
  
  *s = value_ptr;
  
  return 0;
}

static int 
_read_evt (char *record, pef_event_filter_table_t *evt)
{
  int int_value = 0;
  char *string_value = NULL;
  
  ERR_EINVAL (record && evt);
  
  GET_INT_VALUE_BY_KEY (record, 
			"Filter_Number", 
			&int_value);
  evt->filter_number = int_value;
  GET_INT_VALUE_BY_KEY (record, 
			"Filter_Type", 
			&int_value);
  evt->filter_type = int_value;
  GET_STRING_VALUE_BY_KEY (record, 
			   "Enable_Filter", 
			   &string_value);
  evt->enable_filter = (strcasecmp (string_value, "Yes") == 0) ? 1 : 0;
  free (string_value);
  GET_STRING_VALUE_BY_KEY (record, 
			   "Event_filter_Action_Alert", 
			   &string_value);
  evt->event_filter_action_alert = (strcasecmp (string_value, "Yes") == 0) ? 1 : 0;
  free (string_value);
  GET_STRING_VALUE_BY_KEY (record, 
			   "Event_Filter_Action_Power_Off", 
			   &string_value);
  evt->event_filter_action_power_off = (strcasecmp (string_value, "Yes") == 0) ? 1 : 0;
  free (string_value);
  GET_STRING_VALUE_BY_KEY (record, 
			   "Event_Filter_Action_Reset", 
			   &string_value);
  evt->event_filter_action_reset = (strcasecmp (string_value, "Yes") == 0) ? 1 : 0;
  free (string_value);
  GET_STRING_VALUE_BY_KEY (record, 
			   "Event_Filter_Action_Power_Cycle", 
			   &string_value);
  evt->event_filter_action_power_cycle = (strcasecmp (string_value, "Yes") == 0) ? 1 : 0;
  free (string_value);
  GET_STRING_VALUE_BY_KEY (record, 
			   "Event_Filter_Action_OEM", 
			   &string_value);
  evt->event_filter_action_oem = (strcasecmp (string_value, "Yes") == 0) ? 1 : 0;
  free (string_value);
  GET_STRING_VALUE_BY_KEY (record, 
			   "Event_Filter_Action_Diagnostic_Interrupt", 
			   &string_value);
  evt->event_filter_action_diagnostic_interrupt = (strcasecmp (string_value, "Yes") == 0) ? 1 : 0;
  free (string_value);
  GET_STRING_VALUE_BY_KEY (record, 
			   "Event_Filter_Action_Group_Control_Operation", 
			   &string_value);
  evt->event_filter_action_group_control_operation = (strcasecmp (string_value, "Yes") == 0) ? 1 : 0;
  free (string_value);
  GET_INT_VALUE_BY_KEY (record, 
			"Alert_Policy_Number", 
			&int_value);
  evt->alert_policy_number = int_value;
  GET_INT_VALUE_BY_KEY (record, 
			"Group_Control_Selector", 
			&int_value);
  evt->group_control_selector = int_value;
  GET_INT_VALUE_BY_KEY (record, 
			"Event_Severity", 
			&int_value);
  evt->event_severity = int_value;
  GET_INT_VALUE_BY_KEY (record, 
			"Generator_ID_Byte1", 
			&int_value);
  evt->generator_id_byte1 = int_value;
  GET_INT_VALUE_BY_KEY (record, 
			"Generator_ID_Byte2", 
			&int_value);
  evt->generator_id_byte2 = int_value;
  GET_INT_VALUE_BY_KEY (record, 
			"Sensor_Type", 
			&int_value);
  evt->sensor_type = int_value;
  GET_INT_VALUE_BY_KEY (record, 
			"Sensor_Number", 
			&int_value);
  evt->sensor_number = int_value;
  GET_INT_VALUE_BY_KEY (record, 
			"Event_Trigger", 
			&int_value);
  evt->event_trigger = int_value;
  GET_INT_VALUE_BY_KEY (record, 
			"Event_Data1_Offset_Mask", 
			&int_value);
  evt->event_data1_offset_mask = int_value;
  GET_INT_VALUE_BY_KEY (record, 
			"Event_Data1_AND_Mask", 
			&int_value);
  evt->event_data1_AND_mask = int_value;
  GET_INT_VALUE_BY_KEY (record, 
			"Event_Data1_Compare1", 
			&int_value);
  evt->event_data1_compare1 = int_value;
  GET_INT_VALUE_BY_KEY (record, 
			"Event_Data1_Compare2", 
			&int_value);
  evt->event_data1_compare2 = int_value;
  GET_INT_VALUE_BY_KEY (record, 
			"Event_Data2_AND_Mask", 
			&int_value);
  evt->event_data2_AND_mask = int_value;
  GET_INT_VALUE_BY_KEY (record, 
			"Event_Data2_Compare1", 
			&int_value);
  evt->event_data2_compare1 = int_value;
  GET_INT_VALUE_BY_KEY (record, 
			"Event_Data2_Compare2", 
			&int_value);
  evt->event_data2_compare2 = int_value;
  GET_INT_VALUE_BY_KEY (record, 
			"Event_Data3_AND_Mask", 
			&int_value);
  evt->event_data3_AND_mask = int_value;
  GET_INT_VALUE_BY_KEY (record, 
			"Event_Data3_Compare1", 
			&int_value);
  evt->event_data3_compare1 = int_value;
  GET_INT_VALUE_BY_KEY (record, 
			"Event_Data3_Compare2", 
			&int_value);
  evt->event_data3_compare2 = int_value;
  
  return 0;
}

static int 
_fread_record (FILE *fp, char **cache_record)
{
  char *record;
  
  record = NULL;
  
  while (1)
    {
      char *line = NULL;
      size_t n = 0;
      
      if (getline (&line, &n, fp) == -1)
	{
	  return (-1);
	}
      else 
	{
	  char *lineptr = line;
	  char *tmp_lineptr = line;
	  line = strdupa (stripwhite (tmp_lineptr));
	  free (lineptr);
	}
      if (strlen (line) == 0)
	{
	  *cache_record = NULL;
	  if (record)
	    {
	      *cache_record = strdup (record);
	    }
	  return 0;
	}
      
      {
	char *l_record = NULL;
	int len = 0;
	
	if (record)
	  {
	    len = strlen (record) + strlen (line) + 2;
	    l_record = alloca (len);
	    strcpy (l_record, record);
	    strcat (l_record, line);
	    strcat (l_record, "\n");
	    record = l_record;
	  }
	else 
	  {
	    len = strlen (line) + 2;
	    l_record = alloca (len);
	    strcpy (l_record, line);
	    strcat (l_record, "\n");
	    record = l_record;
	  }
      }
    }
  
  return 0;
}

static int 
_get_record_count (FILE *fp, int *count)
{
  char *cache_record = NULL;
  int rcount = 0;
  
  while (1)
    {
      cache_record = NULL;
      if (_fread_record (fp, &cache_record) == -1)
	{
	  *count = rcount;
	  return 0;
	}
      rcount++;
      free (cache_record);
    }
  
  return (-1);
}

int 
get_pef_info (ipmi_device_t dev, pef_info_t *pef_info)
{
  fiid_obj_t obj_cmd_rs = NULL;
  uint64_t val;
  int rv = -1;
  
  ERR_EINVAL (dev && pef_info);
  
  FIID_OBJ_CREATE (obj_cmd_rs, tmpl_cmd_get_pef_capabilities_rs);
  
  if (ipmi_cmd_get_pef_capabilities (dev, obj_cmd_rs) != 0)
    goto cleanup;
  
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "pef_version_major", &val);
  pef_info->pef_version_major = val;
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "pef_version_minor", &val);
  pef_info->pef_version_minor = val;
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "action_support.alert", &val);
  pef_info->alert_action_support = val;
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "action_support.power_down", &val);
  pef_info->power_down_action_support = val;
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "action_support.reset", &val);
  pef_info->reset_action_support = val;
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "action_support.power_cycle", &val);
  pef_info->power_cycle_action_support = val;
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "action_support.oem_action", &val);
  pef_info->oem_action_support = val;
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "action_support.diagnostic_interrupt", &val);
  pef_info->diagnostic_interrupt_action_support = val;
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "oem_event_record_filtering_supported", &val);
  pef_info->oem_event_record_filtering_support = val;
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "number_of_eft_entries", &val);
  pef_info->eft_entries_count = val;
  
  if (pef_info->alert_action_support)
    {
      FIID_OBJ_DESTROY_NO_RETURN (obj_cmd_rs);
      
      FIID_OBJ_CREATE (obj_cmd_rs, 
		       tmpl_cmd_get_pef_configuration_parameters_number_of_event_filters_rs);
      if (ipmi_cmd_get_pef_configuration_parameters_number_of_event_filters (dev, 
									     IPMI_GET_PEF_PARAMETER, 
									     SET_SELECTOR, 
									     BLOCK_SELECTOR, 
									     obj_cmd_rs) != 0)
	goto cleanup;
      FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "number_of_event_filters", &val);
      pef_info->num_event_filters = val;
      FIID_OBJ_DESTROY_NO_RETURN (obj_cmd_rs);
      
      FIID_OBJ_CREATE (obj_cmd_rs, 
		       tmpl_cmd_get_pef_configuration_parameters_number_of_alert_policy_entries_rs);
      if (ipmi_cmd_get_pef_configuration_parameters_number_of_alert_policy_entries (dev, 
										    IPMI_GET_PEF_PARAMETER, 
										    SET_SELECTOR, 
										    BLOCK_SELECTOR, 
										    obj_cmd_rs) != 0)
	goto cleanup;
      FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "number_of_alert_policy_entries", &val);
      pef_info->num_alert_policies = val;
      FIID_OBJ_DESTROY_NO_RETURN (obj_cmd_rs);
      
      FIID_OBJ_CREATE (obj_cmd_rs, 
		       tmpl_cmd_get_pef_configuration_parameters_number_of_alert_strings_rs);
      if (ipmi_cmd_get_pef_configuration_parameters_number_of_alert_strings (dev, 
									     IPMI_GET_PEF_PARAMETER, 
									     SET_SELECTOR, 
									     BLOCK_SELECTOR, 
									     obj_cmd_rs) != 0)
	goto cleanup;
      FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "number_of_alert_strings", &val);
      pef_info->num_alert_strings = val;
    }
  
  rv = 0;
  
 cleanup:
  FIID_OBJ_DESTROY_NO_RETURN(obj_cmd_rs);
  return (rv);
}

int 
get_event_filter_table (ipmi_device_t dev, int filter, pef_event_filter_table_t *evt)
{
  fiid_obj_t obj_cmd_rs = NULL;
  uint64_t val;
  int rv = -1;
  
  ERR_EINVAL (dev && evt);
  
  FIID_OBJ_CREATE (obj_cmd_rs, tmpl_cmd_get_pef_configuration_parameters_event_filter_table_rs);
  
  if (ipmi_cmd_get_pef_configuration_parameters_event_filter_table (dev,
								    IPMI_GET_PEF_PARAMETER,
								    filter,
								    BLOCK_SELECTOR,
								    obj_cmd_rs) != 0)
    goto cleanup;
  
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "filter_number", &val);
  evt->filter_number = val;
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "filter_configuration.type", &val);
  evt->filter_type = val;
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "filter_configuration.filter", &val);
  evt->enable_filter = val;
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "event_filter_action.alert", &val);
  evt->event_filter_action_alert = val;
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "event_filter_action.power_off", &val);
  evt->event_filter_action_power_off = val;
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "event_filter_action.reset", &val);
  evt->event_filter_action_reset = val;
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "event_filter_action.power_cycle", &val);
  evt->event_filter_action_power_cycle = val;
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "event_filter_action.oem", &val);
  evt->event_filter_action_oem = val;
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "event_filter_action.diagnostic_interrupt", &val);
  evt->event_filter_action_diagnostic_interrupt = val;
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "event_filter_action.group_control_operation", &val);
  evt->event_filter_action_group_control_operation = val;
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "alert_policy_number.policy_number", &val);
  evt->alert_policy_number = val;
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "alert_policy_number.group_control_selector", &val);
  evt->group_control_selector = val;
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "event_severity", &val);
  evt->event_severity = val;
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "generator_id_byte1", &val);
  evt->generator_id_byte1 = val;
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "generator_id_byte2", &val);
  evt->generator_id_byte2 = val;
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "sensor_type", &val);
  evt->sensor_type = val;
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "sensor_number", &val);
  evt->sensor_number = val;
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "event_trigger", &val);
  evt->event_trigger = val;
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "event_data1_offset_mask", &val);
  evt->event_data1_offset_mask = val;
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "event_data1_AND_mask", &val);
  evt->event_data1_AND_mask = val;
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "event_data1_compare1", &val);
  evt->event_data1_compare1 = val;
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "event_data1_compare2", &val);
  evt->event_data1_compare2 = val;
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "event_data2_AND_mask", &val);
  evt->event_data2_AND_mask = val;
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "event_data2_compare1", &val);
  evt->event_data2_compare1 = val;
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "event_data2_compare2", &val);
  evt->event_data2_compare2 = val;
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "event_data3_AND_mask", &val);
  evt->event_data3_AND_mask = val;
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "event_data3_compare1", &val);
  evt->event_data3_compare1 = val;
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "event_data3_compare2", &val);
  evt->event_data3_compare2 = val;
  
  rv = 0;
  
 cleanup:
  FIID_OBJ_DESTROY_NO_RETURN (obj_cmd_rs);
  return (rv);
}

int 
set_event_filter_table (ipmi_device_t dev, pef_event_filter_table_t *evt)
{
  fiid_obj_t obj_cmd_rs = NULL;
  int rv = -1;
  
  ERR_EINVAL (dev && evt);
  
  FIID_OBJ_CREATE (obj_cmd_rs, tmpl_cmd_set_pef_configuration_parameters_rs);
  
  if (ipmi_cmd_set_pef_configuration_parameters_event_filter_table (dev, 
								    evt->filter_number, 
								    evt->filter_type, 
								    evt->enable_filter, 
								    evt->event_filter_action_alert, 
								    evt->event_filter_action_power_off, 
								    evt->event_filter_action_reset, 
								    evt->event_filter_action_power_cycle, 
								    evt->event_filter_action_oem, 
								    evt->event_filter_action_diagnostic_interrupt, 
								    evt->event_filter_action_group_control_operation, 
								    evt->alert_policy_number, 
								    evt->group_control_selector, 
								    evt->event_severity, 
								    evt->generator_id_byte1, 
								    evt->generator_id_byte2, 
								    evt->sensor_type, 
								    evt->sensor_number, 
								    evt->event_trigger, 
								    evt->event_data1_offset_mask, 
								    evt->event_data1_AND_mask, 
								    evt->event_data1_compare1, 
								    evt->event_data1_compare2, 
								    evt->event_data2_AND_mask, 
								    evt->event_data2_compare1, 
								    evt->event_data2_compare2, 
								    evt->event_data3_AND_mask, 
								    evt->event_data3_compare1, 
								    evt->event_data3_compare2, 
								    obj_cmd_rs) != 0)
    goto cleanup;
  
  rv = 0;
  
 cleanup:
  FIID_OBJ_DESTROY_NO_RETURN (obj_cmd_rs);
  return (rv);
}

int 
get_number_of_event_filters (ipmi_device_t dev, int *num_event_filters)
{
  fiid_obj_t obj_cmd_rs = NULL;
  uint64_t val;
  int rv = -1;
  
  FIID_OBJ_CREATE (obj_cmd_rs, 
		   tmpl_cmd_get_pef_configuration_parameters_number_of_event_filters_rs);
  if (ipmi_cmd_get_pef_configuration_parameters_number_of_event_filters (dev, 
									 IPMI_GET_PEF_PARAMETER, 
									 SET_SELECTOR, 
									 BLOCK_SELECTOR, 
									 obj_cmd_rs) != 0)
    goto cleanup;
  FIID_OBJ_GET_CLEANUP (obj_cmd_rs, "number_of_event_filters", &val);
  *num_event_filters = val;
  
  rv = 0;
  
 cleanup:
  FIID_OBJ_DESTROY_NO_RETURN (obj_cmd_rs);
  return (rv);
}

int 
get_evt_list (FILE *fp, pef_event_filter_table_t **evt_list, int *count)
{
  pef_event_filter_table_t *l_evt_list = NULL;
  int l_count;
  char *record = NULL;
  int i;
  int rv;
  
  if (!(fp && evt_list && count))
    return (-1);
  
  if (_get_record_count (fp, &l_count) != 0)
    return (-1);
  
  l_evt_list = (pef_event_filter_table_t *) calloc (l_count, 
						    sizeof (pef_event_filter_table_t));
  
  fseek (fp, 0, SEEK_SET);
  
  for (i = 0; i < l_count; i++)
    {
      _fread_record (fp, &record);
      rv = _read_evt (record, (l_evt_list + i));
      free (record);
      if (rv != 0)
	{
	  free (l_evt_list);
	  return (-1);
	}
    }
  
  *evt_list = l_evt_list;
  *count = l_count;
  
  return 0;
}

