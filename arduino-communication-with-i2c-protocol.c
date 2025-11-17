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

// Entry demonstrating Arduino I2C communication
int main(void) { // Begin main
  printf("Arduino Communication with I2C Protocol\n"); // Title
  ar_i2c_init(100000); // Initialize at 100kHz
  unsigned char v = 0; // Prepare value var
  ar_i2c_write(0x3C, 0x00, 0x77); // Write to device
  ar_i2c_read(0x3C, 0x00, &v); // Read back
  for (int i = 0; i < 3; ++i) { // Emit frames
    printf("{\"i2c_ok\":%d,\"last_val\":0x%02X}\n", ar_i2c_ok, v); // Print status
    usleep(300000); // Delay 300 ms
  } // End loop
  return 0; // Exit success
} // End main

