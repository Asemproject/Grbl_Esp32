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

#define MACHINE_NAME            "External 4 Axis Driver Board V2 (CNC Shield V3 map)"

#ifdef N_AXIS
    #undef N_AXIS
#endif
#define N_AXIS 4

// ======= STEP / DIRECTION (CNC Shield D2..D7) =======
// Mapping based on common Wemos D1 R32 UNO-form mapping:
// D2 -> GPIO16, D3 -> GPIO17, D4 -> GPIO21, D5 -> GPIO22, D6 -> GPIO23, D7 -> GPIO19

#define X_STEP_PIN              GPIO_NUM_16   // D2
#define X_DIRECTION_PIN         GPIO_NUM_22   // D5

#define Y_STEP_PIN              GPIO_NUM_17   // D3
#define Y_DIRECTION_PIN         GPIO_NUM_23   // D6

#define Z_STEP_PIN              GPIO_NUM_21   // D4
#define Z_DIRECTION_PIN         GPIO_NUM_19   // D7

// 4th axis (A) - map to D10/D9 to avoid using D11/D12 which may be used by spindle/SPI
#define A_STEP_PIN              GPIO_NUM_26   // D10
#define A_DIRECTION_PIN         GPIO_NUM_27   // D9

// Steppers enable = CNC Shield D8 -> Wemos D1 R32 GPIO12 (BOOT STRAP PIN)
// If you have R1 (pull-up on EN) on the CNC Shield, this will pull GPIO12 HIGH at boot.
// Recommended: remove R1 on CNC Shield OR change this pin to a safe GPIO and jumper to D8.
#define STEPPERS_DISABLE_PIN    GPIO_NUM_12   // D8  <-- WARNING: boot-strap pin

// ======= SPINDLE =======
// On CNC Shield default: SPINDLE PWM often on D11, enable on D13
#define SPINDLE_TYPE            SpindleType::HUANYANG // keep your selected type
#define SPINDLE_OUTPUT_PIN      GPIO_NUM_25   // D11 (PWM)
#define SPINDLE_ENABLE_PIN      GPIO_NUM_32   // D13

// If you prefer to avoid GPIO12 on D8 and want STEPPERS_DISABLE mapped to safe pin (no PCB mod):
// uncomment the next line and wire a jumper from GPIO33 to the CNC Shield D8.
// #define STEPPERS_DISABLE_PIN  GPIO_NUM_33   // alternative safe pin (use a jumper to D8)

// ======= VFD / RS485 =======
// Original pins could conflict with axis pins. Commented out by default.
// If you need VFD RS485, pick UART1 pins that are free and not used by axis.
/*
#define VFD_RS485_TXD_PIN       GPIO_NUM_17
#define VFD_RS485_RXD_PIN       GPIO_NUM_4
#define VFD_RS485_RTS_PIN       GPIO_NUM_16
*/

// ======= LIMIT SWITCHES =======
// Use ADC/input-only pins for limit inputs (A2..A5 and A0..A3)
#define X_LIMIT_PIN             GPIO_NUM_34   // A2
#define Y_LIMIT_PIN             GPIO_NUM_35   // A3
#define Z_LIMIT_PIN             GPIO_NUM_36   // A0

#if (N_AXIS != 3)
    #define A_LIMIT_PIN         GPIO_NUM_39   // A1
#endif

// ======= PROBE & COOLANT =======
#define PROBE_PIN               GPIO_NUM_14   // A4 (safe GPIO)
#define COOLANT_MIST_PIN        GPIO_NUM_33   // use available safe pin (D12 alternative)

// ======= SD CARD (SPI MODE) =======
// CNC Shield uses D11..D13 for some functions - be careful if using SD card and shield simultaneously.
// Adjust wiring if you need both.
#define SD_CARD_MOSI_PIN        GPIO_NUM_23
#define SD_CARD_MISO_PIN        GPIO_NUM_19
#define SD_CARD_SCK_PIN         GPIO_NUM_18
#define SD_CARD_CS_PIN          GPIO_NUM_5

// Aktifkan dukungan SD card di Grbl_ESP32 (comment out if SPI pins conflict with your setup)
#define USE_SD_CARD

// End of file
