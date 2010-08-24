/*
 * Copyright (C) 2003-2010 FreeIPMI Core Team
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#ifndef _IPMI_SENSOR_AND_EVENT_CODE_TABLES_OEM_SPEC_H
#define _IPMI_SENSOR_AND_EVENT_CODE_TABLES_OEM_SPEC_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/*******************************************
 * Dell                                    *
 *******************************************/
  
/*
 * Dell Poweredge R610
 * Dell Poweredge R710
 */

/************************************************
 * Generic Event Reading Type Code Offsets      *
 ************************************************/

#define IPMI_GENERIC_EVENT_READING_TYPE_CODE_OEM_DELL_STATUS_ABSENT              0x00
#define IPMI_GENERIC_EVENT_READING_TYPE_CODE_OEM_DELL_STATUS_STANDBY             0x01
#define IPMI_GENERIC_EVENT_READING_TYPE_CODE_OEM_DELL_STATUS_IPMI_FUNCTION_READY 0x02
#define IPMI_GENERIC_EVENT_READING_TYPE_CODE_OEM_DELL_STATUS_FULLY_READY         0x03
#define IPMI_GENERIC_EVENT_READING_TYPE_CODE_OEM_DELL_STATUS_OFFLINE             0x04
#define IPMI_GENERIC_EVENT_READING_TYPE_CODE_OEM_DELL_STATUS_FAILED              0x05
#define IPMI_GENERIC_EVENT_READING_TYPE_CODE_OEM_DELL_STATUS_ACTIVE              0x06
#define IPMI_GENERIC_EVENT_READING_TYPE_CODE_OEM_DELL_STATUS_BOOTING             0x07
#define IPMI_GENERIC_EVENT_READING_TYPE_CODE_OEM_DELL_STATUS_WRITE_PROTECTED     0x08

/*
 * String arrays for above
 */

extern const char * const ipmi_generic_event_reading_type_code_oem_dell_status[];
extern unsigned int ipmi_generic_event_reading_type_code_oem_dell_status_max_index;

/************************************************
 * Sensor Type Code Offsets OEM Specific        *
 ************************************************/

#define IPMI_SENSOR_TYPE_OEM_DELL_SYSTEM_PERFORMANCE_DEGRADATION_STATUS_GOOD                                   0x00
#define IPMI_SENSOR_TYPE_OEM_DELL_SYSTEM_PERFORMANCE_DEGRADATION_STATUS_DEGRADED_OTHER                         0x01
#define IPMI_SENSOR_TYPE_OEM_DELL_SYSTEM_PERFORMANCE_DEGRADATION_STATUS_DEGRADED_THERMAL_PROTECTION            0x02
#define IPMI_SENSOR_TYPE_OEM_DELL_SYSTEM_PERFORMANCE_DEGRADATION_STATUS_DEGRADED_COOLING_CAPACITY_CHANGE       0x03
#define IPMI_SENSOR_TYPE_OEM_DELL_SYSTEM_PERFORMANCE_DEGRADATION_STATUS_DEGRADED_POWER_CAPACITY_CHANGE         0x04
#define IPMI_SENSOR_TYPE_OEM_DELL_SYSTEM_PERFORMANCE_DEGRADATION_STATUS_DEGRADED_USER_DEFINED_POWER_CAPACITY   0x05
#define IPMI_SENSOR_TYPE_OEM_DELL_SYSTEM_PERFORMANCE_DEGRADATION_STATUS_HALTED_SYSTEM_POWER_EXCEEDS_CAPACITY   0x06
#define IPMI_SENSOR_TYPE_OEM_DELL_SYSTEM_PERFORMANCE_DEGRADATION_STATUS_DEGRADED_SYSTEM_POWER_EXCEEDS_CAPACITY 0x07

#define IPMI_SENSOR_TYPE_OEM_DELL_LINK_TUNING_GOOD                                                            0x00
#define IPMI_SENSOR_TYPE_OEM_DELL_LINK_TUNING_FAILED_TO_PROGRAM_VIRTUAL_MAC_ADDRESS                           0x01
#define IPMI_SENSOR_TYPE_OEM_DELL_LINK_TUNING_DEVICE_OPTION_ROM_FAILED_TO_SUPPORT_LINK_TUNING_OR_FLEX_ADDRESS 0x02
#define IPMI_SENSOR_TYPE_OEM_DELL_LINK_TUNING_FAILED_TO_GET_LINK_TUNING_OR_FLEX_ADDRESS_DATA                  0x03

#define IPMI_SENSOR_TYPE_OEM_DELL_NON_FATAL_ERROR_PCIE_ERROR 0x00

#define IPMI_SENSOR_TYPE_OEM_DELL_FATAL_IO_ERROR_SUCCESSFUL     0x00
#define IPMI_SENSOR_TYPE_OEM_DELL_FATAL_IO_ERROR_FATAL_IO_ERROR 0x01

#define IPMI_SENSOR_TYPE_OEM_DELL_UPGRADE_SUCCESSFUL 0x00
#define IPMI_SENSOR_TYPE_OEM_DELL_UPGRADE_FAILED     0x01

/*
 * String arrays for above
 */

extern const char * const ipmi_sensor_type_oem_dell_system_performance_degradation_status[];
extern unsigned int ipmi_sensor_type_oem_dell_system_performance_degradation_status_max_index;

extern const char * const ipmi_sensor_type_oem_dell_link_tuning[];
extern unsigned int ipmi_sensor_type_oem_dell_link_tuning_max_index;

extern const char * const ipmi_sensor_type_oem_dell_non_fatal_error[];
extern unsigned int ipmi_sensor_type_oem_dell_non_fatal_error_max_index;

extern const char * const ipmi_sensor_type_oem_dell_fatal_io_error[];
extern unsigned int ipmi_sensor_type_oem_dell_fatal_io_error_max_index;

extern const char * const ipmi_sensor_type_oem_dell_upgrade[];
extern unsigned int ipmi_sensor_type_oem_dell_upgrade_max_index;

/************************************************
 * Sensor Type Code Offsets OEM Extra           *
 ************************************************/

#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_DELL_POST_FATAL_ERROR 0x0F

/* Other Event Macros */

#define IPMI_SENSOR_TYPE_PHYSICAL_SECURITY_INTRUSION_WHILE_SYSTEM_ON  0x01
#define IPMI_SENSOR_TYPE_PHYSICAL_SECURITY_INTRUSION_WHILE_SYSTEM_OFF 0x02

#define IPMI_SENSOR_TYPE_POWER_SUPPLY_EVENT_DATA2_OEM_DELL_PSU_COMMUNICATION_ERROR  0x01
#define IPMI_SENSOR_TYPE_POWER_SUPPLY_EVENT_DATA2_OEM_DELL_OVER_TEMPERATURE_WARNING 0x02
#define IPMI_SENSOR_TYPE_POWER_SUPPLY_EVENT_DATA2_OEM_DELL_OVER_TEMPERATURE_FAULT   0x03
#define IPMI_SENSOR_TYPE_POWER_SUPPLY_EVENT_DATA2_OEM_DELL_UNDER_VOLTAGE_FAULT      0x04
#define IPMI_SENSOR_TYPE_POWER_SUPPLY_EVENT_DATA2_OEM_DELL_OVER_VOLTAGE_FAULT       0x05
#define IPMI_SENSOR_TYPE_POWER_SUPPLY_EVENT_DATA2_OEM_DELL_OVER_CURRENT_FAULT       0x06
#define IPMI_SENSOR_TYPE_POWER_SUPPLY_EVENT_DATA2_OEM_DELL_FAN_FAULT                0x07

#define IPMI_SENSOR_TYPE_POWER_SUPPLY_EVENT_DATA2_OEM_DELL_OFFSET_CONFIGURATION_ERROR_WATTS_SHIFT 4

#define IPMI_SENSOR_TYPE_POWER_SUPPLY_EVENT_DATA3_OEM_DELL_OFFSET_CONFIGURATION_ERROR_ERROR_TYPE_BITMASK 0x0F
#define IPMI_SENSOR_TYPE_POWER_SUPPLY_EVENT_DATA3_OEM_DELL_OFFSET_CONFIGURATION_ERROR_ERROR_TYPE_SHIFT   0

#define IPMI_SENSOR_TYPE_POWER_SUPPLY_EVENT_DATA3_OEM_DELL_OFFSET_CONFIGURATION_ERROR_WATTS_BITMASK 0xF0
#define IPMI_SENSOR_TYPE_POWER_SUPPLY_EVENT_DATA3_OEM_DELL_OFFSET_CONFIGURATION_ERROR_WATTS_SHIFT   4

#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA2_OEM_DELL_SPARE_MODE_BITMASK  0x1    
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA2_OEM_DELL_RAID_MODE_BITMASK   0x2   
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA2_OEM_DELL_MIRROR_MODE_BITMASK 0x4

#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA2_OEM_DELL_MEMORY_CARD_BITMASK 0xF0
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA2_OEM_DELL_MEMORY_CARD_SHIFT   4

#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA2_OEM_DELL_DIMM_COUNTER_BITMASK 0x0F
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA2_OEM_DELL_DIMM_COUNTER_SHIFT   0

#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA2_OEM_DELL_BANK_NUMBER_BITMASK 0x0F
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA2_OEM_DELL_BANK_NUMBER_SHIFT   0

#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA2_OEM_DELL_MEMORY_CARD_MIN 0x00
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA2_OEM_DELL_MEMORY_CARD_MAX 0x07

/* To avoid gcc warnings, add +1 in comparison */
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA2_OEM_DELL_MEMORY_CARD_VALID(__memory_card) \
  (((__memory_card + 1) >= (IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA2_OEM_DELL_MEMORY_CARD_MIN + 1) \
    && (__memory_card) <= IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA2_OEM_DELL_MEMORY_CARD_MAX) ? 1 : 0)

#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA2_OEM_DELL_BANK_NUMBER_MIN 0x00
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA2_OEM_DELL_BANK_NUMBER_MAX 0x07

/* To avoid gcc warnings, add +1 in comparison */
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA2_OEM_DELL_BANK_NUMBER_VALID(__bank_number) \
  (((__bank_number + 1) >= (IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA2_OEM_DELL_BANK_NUMBER_MIN + 1) \
    && (__bank_number) <= IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA2_OEM_DELL_BANK_NUMBER_MAX) ? 1 : 0)

#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA2_OEM_DELL_DIMM_NUMBER_MIN 0x00
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA2_OEM_DELL_DIMM_NUMBER_MAX 0x7F

/* To avoid gcc warnings, add +1 in comparison */
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA2_OEM_DELL_DIMM_NUMBER_VALID(__bank_number) \
  (((__bank_number + 1) >= (IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA2_OEM_DELL_DIMM_NUMBER_MIN + 1) \
    && (__bank_number) <= IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA2_OEM_DELL_DIMM_NUMBER_MAX) ? 1 : 0)

#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA2_OEM_DELL_4_DIMMS_PER_NODE 0x08
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA2_OEM_DELL_6_DIMMS_PER_NODE 0x09
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA2_OEM_DELL_8_DIMMS_PER_NODE 0x0A
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA2_OEM_DELL_9_DIMMS_PER_NODE 0x0B
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA2_OEM_DELL_NO_CARD          0x0F

#define IPMI_SENSOR_TYPE_VERSION_CHANGE_EVENT_DATA2_OEM_DELL_MANAGEMENT_CONTROLLER_FIRMWARE_REVISION 0x02

#define IPMI_SENSOR_TYPE_VERSION_CHANGE_EVENT_DATA3_OEM_DELL_OTHER 0x00
#define IPMI_SENSOR_TYPE_VERSION_CHANGE_EVENT_DATA3_OEM_DELL_CPU   0x01

#define IPMI_SENSOR_TYPE_OEM_DELL_LINK_TUNING_EVENT_DATA2_BLADE_FORMAT_BITMASK 0xC0
#define IPMI_SENSOR_TYPE_OEM_DELL_LINK_TUNING_EVENT_DATA2_BLADE_FORMAT_SHIFT   6

#define IPMI_SENSOR_TYPE_OEM_DELL_LINK_TUNING_EVENT_DATA2_BLADE_FORMAT_SINGLE_HEIGHT               0
#define IPMI_SENSOR_TYPE_OEM_DELL_LINK_TUNING_EVENT_DATA2_BLADE_FORMAT_DOUBLE_HEIGHT               1
#define IPMI_SENSOR_TYPE_OEM_DELL_LINK_TUNING_EVENT_DATA2_BLADE_FORMAT_DOUBLE_HEIGHT_DOUBLE_WEIGHT 2

/* device number, function number, bus/slot number apply to multiple
 * sensor types
 */

#define IPMI_OEM_DELL_EVENT_DATA2_DEVICE_NUMBER_BITMASK   0xF8
#define IPMI_OEM_DELL_EVENT_DATA2_DEVICE_NUMBER_SHIFT     3

#define IPMI_OEM_DELL_EVENT_DATA2_FUNCTION_NUMBER_BITMASK 0x07
#define IPMI_OEM_DELL_EVENT_DATA2_FUNCTION_NUMBER_SHIFT   0

#define IPMI_OEM_DELL_EVENT_DATA3_BUS_SLOT_FLAG_BITMASK   0x80
#define IPMI_OEM_DELL_EVENT_DATA3_BUS_SLOT_FLAG_SHIFT     7

#define IPMI_OEM_DELL_EVENT_DATA3_BUS_SLOT_BITMASK        0x7F
#define IPMI_OEM_DELL_EVENT_DATA3_BUS_SLOT_SHIFT          0

/* option rom macros apply to multiple sensor types */

#define IPMI_OEM_DELL_EVENT_DATA3_OPTION_ROM_BITMASK 0x80
#define IPMI_OEM_DELL_EVENT_DATA3_OPTION_ROM_SHIFT   7

#define IPMI_OEM_DELL_EVENT_DATA3_OPTION_ROM_EMBEDDED 0
#define IPMI_OEM_DELL_EVENT_DATA3_OPTION_ROM_SLOT     1

#define IPMI_OEM_DELL_EVENT_DATA3_OPTION_ROM_SLOT_BITMASK 0x7F
#define IPMI_OEM_DELL_EVENT_DATA3_OPTION_ROM_SLOT_SHIFT   0

/* BIOS Progress and Fatal Error Codes */
/*  
 * 00h and FFh are reserved
 * Progress codes range from 01h to 7Fh
 * Fatal error codes range from 80h to FEh
 * Progress codes less than 3Fh are pre-video activity
 * Progress codes greather than 40h are post-video activity
 * Fatal error codes less than BFh indicate pre-video failure
 * Fatal error codes greater than C0h indicate post-video failure.
 */

#define IPMI_OEM_DELL_BIOS_PROGRESS_CODE_SYSTEM_POWER_ON                          0x01
#define IPMI_OEM_DELL_BIOS_PROGRESS_CODE_CPU_MICROCODE_LOAD                       0x02
#define IPMI_OEM_DELL_BIOS_PROGRESS_CODE_CHIPSET_INITIALIZATION                   0x03
#define IPMI_OEM_DELL_BIOS_PROGRESS_CODE_MEMORY_CONFIGURATION                     0x04
#define IPMI_OEM_DELL_BIOS_PROGRESS_CODE_SHADOW_BIOS                              0x05
#define IPMI_OEM_DELL_BIOS_PROGRESS_CODE_MULTIPROCESSOR_INITIALIZATION            0x06
#define IPMI_OEM_DELL_BIOS_PROGRESS_CODE_POST_PROCESSING_START                    0x07
#define IPMI_OEM_DELL_BIOS_PROGRESS_CODE_SMM_MODE_INITIALIZATION                  0x08
#define IPMI_OEM_DELL_BIOS_PROGRESS_CODE_PCI_BUS_ENUMERATION_VIDEO_INITIALIZATION 0x09
#define IPMI_OEM_DELL_BIOS_PROGRESS_CODE_DISPLAY_SIGN_ON                          0x40
#define IPMI_OEM_DELL_BIOS_PROGRESS_CODE_PCI_CONFIGURATION                        0x41
#define IPMI_OEM_DELL_BIOS_PROGRESS_CODE_GIVE_CONTROL_TO_OS                       0x7F

#define IPMI_OEM_DELL_BIOS_FATAL_ERROR_CODE_NO_MEMORY_DETECTED                      0x80
#define IPMI_OEM_DELL_BIOS_FATAL_ERROR_CODE_MEMORY_DETECTED_BUT_IS_NOT_CONFIGURABLE 0x81
#define IPMI_OEM_DELL_BIOS_FATAL_ERROR_CODE_MEMORY_CONFIGURED_BUT_NOT_USABLE        0x82
#define IPMI_OEM_DELL_BIOS_FATAL_ERROR_CODE_SYSTEM_BIOS_SHADOW_FAILURE              0x83
#define IPMI_OEM_DELL_BIOS_FATAL_ERROR_CODE_CMOS_FAILURE                            0x84
#define IPMI_OEM_DELL_BIOS_FATAL_ERROR_CODE_DMA_CONTROLLER_FAILURE                  0x85
#define IPMI_OEM_DELL_BIOS_FATAL_ERROR_CODE_INTERRUPT_CONTROLLER_FAILURE            0x86
#define IPMI_OEM_DELL_BIOS_FATAL_ERROR_CODE_TIMER_REFRESH_FAILURE                   0x87
#define IPMI_OEM_DELL_BIOS_FATAL_ERROR_CODE_PROGRAMMABLE_INTERVAL_TIMER_ERROR       0x88
#define IPMI_OEM_DELL_BIOS_FATAL_ERROR_CODE_PARITY_ERROR                            0x89
#define IPMI_OEM_DELL_BIOS_FATAL_ERROR_CODE_SIO_FAILURE                             0x8A
#define IPMI_OEM_DELL_BIOS_FATAL_ERROR_CODE_KEYBOARD_CONTROLLER_FAILURE             0x8B
#define IPMI_OEM_DELL_BIOS_FATAL_ERROR_CODE_SMI_INITIALIZATION_FAILURE              0x8C
#define IPMI_OEM_DELL_BIOS_FATAL_ERROR_CODE_SHUTDOWN_TEST_FAILURE                   0xC0
#define IPMI_OEM_DELL_BIOS_FATAL_ERROR_CODE_POST_MEMORY_TEST_FAILURE                0xC1
#define IPMI_OEM_DELL_BIOS_FATAL_ERROR_CODE_RAC_CONFIGURATION_FAILURE               0xC2
#define IPMI_OEM_DELL_BIOS_FATAL_ERROR_CODE_CPU_CONFIGURATION_FAILURE               0xC3
#define IPMI_OEM_DELL_BIOS_FATAL_ERROR_CODE_INCORRECT_MEMORY_CONFIGURATION          0xC4
#define IPMI_OEM_DELL_BIOS_FATAL_ERROR_CODE_GENERAL_FAILURE_AFTER_VIDEO             0xFE

/*******************************************
 * Inventec                                *
 *******************************************/

/*
 * Inventec 5441/Dell Xanadu II
 * Inventec 5442/Dell Xanadu III
 */
/* achu: not official names, named based on use context */

#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA2_OEM_INVENTEC_SBE_WARNING_THRESHOLD  0x00
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA2_OEM_INVENTEC_SBE_CRITICAL_THRESHOLD 0x01
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA2_OEM_INVENTEC_OTHER                  0xFF

#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA3_OEM_INVENTEC_5441_DIMM_CPU0_CH0_DIM1 0x01
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA3_OEM_INVENTEC_5441_DIMM_CPU0_CH0_DIM0 0x02
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA3_OEM_INVENTEC_5441_DIMM_CPU0_CH1_DIM1 0x03
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA3_OEM_INVENTEC_5441_DIMM_CPU0_CH1_DIM0 0x04
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA3_OEM_INVENTEC_5441_DIMM_CPU0_CH2_DIM1 0x05
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA3_OEM_INVENTEC_5441_DIMM_CPU0_CH2_DIM0 0x06
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA3_OEM_INVENTEC_5441_DIMM_CPU1_CH0_DIM0 0x11
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA3_OEM_INVENTEC_5441_DIMM_CPU1_CH1_DIM0 0x12
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA3_OEM_INVENTEC_5441_DIMM_CPU1_CH2_DIM0 0x13

#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA3_OEM_INVENTEC_5442_DIMM_CPU0_CH0_DIM1 0x01
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA3_OEM_INVENTEC_5442_DIMM_CPU0_CH0_DIM0 0x02
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA3_OEM_INVENTEC_5442_DIMM_CPU0_CH1_DIM1 0x03
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA3_OEM_INVENTEC_5442_DIMM_CPU0_CH1_DIM0 0x04
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA3_OEM_INVENTEC_5442_DIMM_CPU0_CH2_DIM1 0x05
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA3_OEM_INVENTEC_5442_DIMM_CPU0_CH2_DIM0 0x06
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA3_OEM_INVENTEC_5442_DIMM_CPU1_CH0_DIM1 0x11
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA3_OEM_INVENTEC_5442_DIMM_CPU1_CH0_DIM0 0x12
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA3_OEM_INVENTEC_5442_DIMM_CPU1_CH1_DIM1 0x13
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA3_OEM_INVENTEC_5442_DIMM_CPU1_CH1_DIM0 0x14
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA3_OEM_INVENTEC_5442_DIMM_CPU1_CH2_DIM1 0x15
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA3_OEM_INVENTEC_5442_DIMM_CPU1_CH2_DIM0 0x16

#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_EVENT_DATA3_OEM_INVENTEC_PORT80_CODE_EXTENDED_MEMORY_TEST 0x3A
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_EVENT_DATA3_OEM_INVENTEC_PORT80_CODE_SETUP_MENU           0x87
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_EVENT_DATA3_OEM_INVENTEC_PORT80_CODE_OPTION_ROM_SCAN      0x78

#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_TIMER_COUNT_READ_WRITE_ERROR           0x0000
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_MASTER_PIC_ERROR                       0x0001
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_SLAVE_PIC_ERROR                        0x0002
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_CMOS_BATTERY_ERROR                     0x0003
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_CMOS_DIAGNOSTIC_STATUS_ERROR           0x0004
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_CMOS_CHECKSUM_ERROR                    0x0005
/* achu: Inventec 5441 lists "Config Error", while Inventec 5442 lists "Configuration Error"
 * We'll just keep "Config Error"
 */
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_CMOS_CONFIG_ERROR                      0x0006
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_KEYBOARD_LOCK_ERROR                    0x0008
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_NO_KEYBOARD_ERROR                      0x0009
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_KBC_BAT_TEST_ERROR                     0x000A
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_CMOS_MEMORY_SIZE_ERROR                 0x000B
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_RAM_READ_WRITE_TEST_ERROR              0x000C
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_FDD_0_ERROR                            0x000E
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_FLOPPY_CONTROLLER_ERROR                0x0010
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_CMOS_DATE_TIME_ERROR                   0x0012
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_NO_PS2_MOUSE_ERROR                     0x0014
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_REFRESH_TIMER_ERROR                    0x0040
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_DISPLAY_MEMORY_ERROR                   0x0041
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_POST_THE_INS_KEY_ERROR                 0x0043
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_DMAC_PAGE_REGISTER_ERROR               0x0044
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_DMAC1_CHANNEL_REGISTER_ERROR           0x0045
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_DMAC2_CHANNEL_REGISTER_ERROR           0x0046
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_PMM_MEMORY_ALLOCATION_ERROR            0x0047
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_PASSWORD_CHECK_ERROR                   0x0048
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_ADM_MODULE_ERROR                       0x004A
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_LANGUAGE_MODULE_ERROR                  0x004B
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_KBC_INTERFACE_ERROR                    0x004C
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_HDD_0_ERROR                            0x004D
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_HDD_1_ERROR                            0x004E
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_HDD_2_ERROR                            0x004F
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_HDD_3_ERROR                            0x0050
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_HDD_4_ERROR                            0x0051
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_HDD_5_ERROR                            0x0052
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_HDD_6_ERROR                            0x0053
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_HDD_7_ERROR                            0x0054
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_ATAPI_0_ERROR                          0x0055
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_ATAPI_1_ERROR                          0x0056
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_ATAPI_2_ERROR                          0x0057
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_ATAPI_3_ERROR                          0x0058
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_ATAPI_4_ERROR                          0x0059
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_ATAPI_5_ERROR                          0x005A
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_ATAPI_6_ERROR                          0x005B
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_ATAPI_7_ERROR                          0x005C
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_ATA_SMART_FEATURE_ERROR                0x005D
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_NON_CRITICAL_PASSWORD_CHECK_ERROR      0x005E
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_DUMMY_BIOS_ERROR                       0x00FF
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_USB_HC_NOT_FOUND                       0x8101
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_USB_DEVICE_INIT_ERROR                  0x8102
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_USB_DEVICE_DISABLED                    0x8103
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_USB_OHCI_EMUL_NOT_SUPPORTED            0x8104
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_USB_EHCI_64BIT_DATA_STRUCTURE_ERROR    0x8105
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_SMBIOS_NOT_ENOUGH_SPACE_IN_F000        0x8301
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_AP_APPLICATION_PROCESSOR_FAILED_BIST   0x0110
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_CPU1_THERMAL_FAILURE_DUE_TO_PROCHOT    0x0120
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_CPU2_THERMAL_FAILURE_DUE_TO_PROCHOT    0x0121
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_CPU3_THERMAL_FAILURE_DUE_TO_PROCHOT    0x0122
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_CPU4_THERMAL_FAILURE_DUE_TO_PROCHOT    0x0123
/* BSP = Baseboard Service Processor */
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_PROCESSOR_FAILED_BIST_BSP              0x0150
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_CPU1_PROCESSOR_MISSING_MICROCODE       0x0160
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_CPU2_PROCESSOR_MISSING_MICROCODE       0x0161
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_CPU3_PROCESSOR_MISSING_MICROCODE       0x0162
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_CPU4_PROCESSOR_MISSING_MICROCODE       0x0163
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_L2_CACHE_SIZE_MISMATCH                 0x0192
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_CPUID_PROCESSOR_STEPPING_ARE_DIFFERENT 0x0193
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_CPUID_PROCESSOR_FAMILY_ARE_DIFFERENT   0x0194
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_FRONT_SIDE_BUS_MISMATCH                0x0195
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_CPUID_PROCESSOR_MODEL_ARE_DIFFERENT    0x0196
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_PROCESSOR_SPEEDS_MISMATCHED            0x0197
/* QPI Mismatch only for Inventec 5442 */
/* QPI = Quickpath Interconnect */
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_QPI_MISMATCHED                         0x0198
#define IPMI_SENSOR_TYPE_SYSTEM_FIRMWARE_PROGRESS_OEM_INVENTEC_POST_ERROR_CODE_UNDEFINED_BIOS_ERROR                   0xFFFF

/*******************************************
 * Quanta                                  *
 *******************************************/

/*
 * Quanta S99Q/Dell FS12-TY
 */

#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA3_OEM_QUANTA_S99Q_DIMM_A0 0x01
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA3_OEM_QUANTA_S99Q_DIMM_A1 0x02
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA3_OEM_QUANTA_S99Q_DIMM_A2 0x03
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA3_OEM_QUANTA_S99Q_DIMM_B0 0x04
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA3_OEM_QUANTA_S99Q_DIMM_B1 0x05
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA3_OEM_QUANTA_S99Q_DIMM_B2 0x06
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA3_OEM_QUANTA_S99Q_DIMM_C0 0x07
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA3_OEM_QUANTA_S99Q_DIMM_C1 0x08
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA3_OEM_QUANTA_S99Q_DIMM_C2 0x09
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA3_OEM_QUANTA_S99Q_DIMM_D0 0x0A
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA3_OEM_QUANTA_S99Q_DIMM_D1 0x0B
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA3_OEM_QUANTA_S99Q_DIMM_D2 0x0C
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA3_OEM_QUANTA_S99Q_DIMM_E0 0x0D
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA3_OEM_QUANTA_S99Q_DIMM_E1 0x0E
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA3_OEM_QUANTA_S99Q_DIMM_E2 0x0F
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA3_OEM_QUANTA_S99Q_DIMM_F0 0x10
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA3_OEM_QUANTA_S99Q_DIMM_F1 0x11
#define IPMI_SENSOR_TYPE_MEMORY_EVENT_DATA3_OEM_QUANTA_S99Q_DIMM_F2 0x12

#define IPMI_SENSOR_TYPE_CRITICAL_INTERRUPT_OEM_QUANTA_EVENT_DATA2_DEVICE_NUMBER_BITMASK   0xF8
#define IPMI_SENSOR_TYPE_CRITICAL_INTERRUPT_OEM_QUANTA_EVENT_DATA2_DEVICE_NUMBER_SHIFT     3

#define IPMI_SENSOR_TYPE_CRITICAL_INTERRUPT_OEM_QUANTA_EVENT_DATA2_FUNCTION_NUMBER_BITMASK 0x07
#define IPMI_SENSOR_TYPE_CRITICAL_INTERRUPT_OEM_QUANTA_EVENT_DATA2_FUNCTION_NUMBER_SHIFT   0

#define IPMI_SENSOR_TYPE_CRITICAL_INTERRUPT_OEM_QUANTA_EVENT_DATA3_QPI0_ERROR           0
#define IPMI_SENSOR_TYPE_CRITICAL_INTERRUPT_OEM_QUANTA_EVENT_DATA3_QPI1_ERROR           1
#define IPMI_SENSOR_TYPE_CRITICAL_INTERRUPT_OEM_QUANTA_EVENT_DATA3_QPI2_ERROR           2
#define IPMI_SENSOR_TYPE_CRITICAL_INTERRUPT_OEM_QUANTA_EVENT_DATA3_QPI3_ERROR           3
#define IPMI_SENSOR_TYPE_CRITICAL_INTERRUPT_OEM_QUANTA_EVENT_DATA3_MISCELLANEOUS_ERROR 23
#define IPMI_SENSOR_TYPE_CRITICAL_INTERRUPT_OEM_QUANTA_EVENT_DATA3_IOH_CORE_ERROR      24

#define IPMI_OEM_QUANTA_EVENT_DATA

/*******************************************
 * Supermicro                              *
 *******************************************/

/*
 * Supermicro X8DTH, X8DTG, X8DTU
 */
/* achu: not official names, named based on use context */
#define IPMI_SENSOR_TYPE_OEM_SUPERMICRO_CPU_TEMP_LOW           0x00
#define IPMI_SENSOR_TYPE_OEM_SUPERMICRO_CPU_TEMP_MEDIUM        0x01
#define IPMI_SENSOR_TYPE_OEM_SUPERMICRO_CPU_TEMP_HIGH          0x02
#define IPMI_SENSOR_TYPE_OEM_SUPERMICRO_CPU_TEMP_OVERHEAT      0x04
#define IPMI_SENSOR_TYPE_OEM_SUPERMICRO_CPU_TEMP_NOT_INSTALLED 0x07
#ifdef __cplusplus
}
#endif

#endif
