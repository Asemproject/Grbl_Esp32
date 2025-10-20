#pragma once
// clang-format off

/*
4axis_external_driver.h
Adapted for Wemos D1 R32 (ESP32) to match CNC Shield V3 physical pinout
(Arduino D2..D13, A0..A5) mapping for Wemos D1 R32.

Notes:
 - D2..D7 mapped to X/Y/Z step & dir
 - D8 mapped to steppers enable (GPIO12) — WARNING: GPIO12 is a boot-strap pin.
   Remove R1 (pull-up on EN) on the CNC Shield or move STEPPERS_DISABLE_PIN if you
   experience boot issues.
 - 4th axis (A) mapped to D9/D10 to avoid conflict with D11 (spindle) where possible.
 - Limit pins use ESP32 ADC pins (A2..A5) where appropriate (input-only pins).
*/



#define MACHINE_NAME "Test Drive - Demo Only No I/O!"
// This is the CPU Map for the ESP32 CNC SHIELD Controller

#define X_STEP_PIN GPIO_NUM_26
#define Y_STEP_PIN GPIO_NUM_25
#define Z_STEP_PIN GPIO_NUM_17

#define X_DIRECTION_PIN GPIO_NUM_16
#define Y_DIRECTION_PIN GPIO_NUM_27
#define Z_DIRECTION_PIN GPIO_NUM_14

#define STEPPERS_DISABLE_PIN GPIO_NUM_22

//#define COOLANT_FLOOD_PIN GPIO_NUM_34
//#define COOLANT_MIST_PIN GPIO_NUM_21

// SD card pins (SPI di pin non-konflik)
#define SD_CS_PIN    GPIO_NUM_21
#define SD_MISO_PIN  GPIO_NUM_33
#define SD_MOSI_PIN  GPIO_NUM_32
#define SD_SCK_PIN   GPIO_NUM_18

#define SPINDLE_PWM_PIN GPIO_NUM_19
#define SPINDLE_PWM_CHANNEL 0
#define SPINDLE_PWM_BASE_FREQ 5000 // Hz
#define SPINDLE_PWM_BIT_PRECISION 8
#define SPINDLE_PWM_OFF_VALUE 0
#define SPINDLE_PWM_MAX_VALUE 255

#ifndef SPINDLE_PWM_MIN_VALUE
#define SPINDLE_PWM_MIN_VALUE 1
#endif

#define SPINDLE_PWM_RANGE (SPINDLE_PWM_MAX_VALUE-SPINDLE_PWM_MIN_VALUE)

//#define SPINDLE_ENABLE_PIN GPIO_NUM_16
//#define SPINDLE_DIR_PIN GPIO_NUM_16

#define X_LIMIT_PIN GPIO_NUM_13
#define Y_LIMIT_PIN GPIO_NUM_5
#define Z_LIMIT_PIN GPIO_NUM_23
#define LIMIT_MASK B111

#define PROBE_PIN GPIO_NUM_36

//#define CONTROL_SAFETY_DOOR_PIN GPIO_NUM_39
#define CONTROL_RESET_PIN GPIO_NUM_2
#define CONTROL_FEED_HOLD_PIN GPIO_NUM_4
#define CONTROL_CYCLE_START_PIN GPIO_NUM_35
