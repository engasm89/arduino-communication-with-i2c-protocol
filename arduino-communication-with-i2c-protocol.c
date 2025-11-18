/*
 * Course: Arduino Communication With I2c Protocol
 * Platform: Arduino
 * Author: Ashraf S A AlMadhoun
 * 
 * Description:
 * This code demonstrates the core concepts taught in the "Arduino Communication With I2c Protocol" course.
 * It provides a practical implementation that students can study, modify, and
 * use as a foundation for their own projects.
 * 
 * Learning Objectives:
 * - Understand the fundamental principles covered in this course
 * - Practice implementing the concepts with real code
 * - Build a working example that can be extended
 * 
 * Hardware Requirements:
 * - Development board (Arduino)
 * - Components as specified in CIRCUIT.md
 * - USB cable for programming
 * 
 * Pin Connections:
 * Refer to CIRCUIT.md for detailed wiring diagrams and pin assignments.
 * 
 * Usage:
 * 1. Review the code structure and comments
 * 2. Connect hardware according to CIRCUIT.md
 * 3. Upload code to your development board
 * 4. Monitor serial output for debugging
 * 
 * Course Link: https://www.udemy.com/course/arduino-communication-with-i2c-protocol/
 * Repository: https://github.com/engasm89/arduino-communication-with-i2c-protocol
 * 
 * Copyright (c) 2025 Ashraf S A AlMadhoun
 * Licensed under MIT License
 */

#include <stdio.h> // Include I/O for I2C logs
#include <unistd.h> // Include POSIX sleep for timing

// Simulated Arduino I2C ready flag
static int ar_i2c_ok = 0; // Track I2C readiness

// Initialize Arduino I2C master (stub)
int ar_i2c_init(long freq_hz) { // Function to initialize I2C
  (void)freq_hz; // Suppress unused warning
  ar_i2c_ok = 1; // Mark as ready
  printf("Arduino I2C Master init\n"); // Log init
  return ar_i2c_ok; // Return status
} // End ar_i2c_init

// Write a register on an I2C device (stub)
int ar_i2c_write(unsigned char addr, unsigned char reg, unsigned char val) { // I2C write
  if (!ar_i2c_ok) return 0; // Fail if not ready
  printf("Arduino I2C WRITE addr=0x%02X reg=0x%02X val=0x%02X\n", addr, reg, val); // Log
  return 1; // Success
} // End ar_i2c_write

// Read a register from an I2C device (stub)
int ar_i2c_read(unsigned char addr, unsigned char reg, unsigned char *val) { // I2C read
  if (!ar_i2c_ok) return 0; // Fail if not ready
  *val = (unsigned char)(reg + 0x10); // Simulate value
  printf("Arduino I2C READ addr=0x%02X reg=0x%02X val=0x%02X\n", addr, reg, *val); // Log
  return 1; // Success
} // End ar_i2c_read

// Scan common I2C address range and report detected devices
void ar_i2c_scan(void) { // Scanner
  printf("I2C Scan start\n"); // Log start
  for (unsigned char addr = 0x08; addr <= 0x77; ++addr) { // Valid 7-bit range
    unsigned char dummy = 0; // Dummy value
    int ok = ar_i2c_read(addr, 0x00, &dummy); // Attempt a read
    if (ok) { // If read succeeded
      printf("Found device at 0x%02X\n", addr); // Report address
    } // End detection
    usleep(10000); // 10ms between probes
  } // End range
  printf("I2C Scan complete\n"); // Log done
}

// Program entry point demonstrating Arduino I2C communication
int main(void) { // Main function implementation
  printf("Arduino Communication with I2C Protocol\n"); // Title
  ar_i2c_init(100000); // Initialize at 100kHz
  unsigned char v = 0; // Prepare value var
  ar_i2c_write(0x3C, 0x00, 0x77); // Write to device
  ar_i2c_read(0x3C, 0x00, &v); // Read back
  ar_i2c_scan(); // Scan bus for devices
  for (int i = 0; i < 3; ++i) { // Emit frames
    printf("{\"i2c_ok\":%d,\"last_val\":0x%02X}\n", ar_i2c_ok, v); // Print status
    usleep(300000); // Delay 300 ms
  } // End loop
  return 0; // Exit successfully
} // End of main function

