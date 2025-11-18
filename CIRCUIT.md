# Arduino I2C — Circuit Schematic

- Course: Arduino Communication with I2C Protocol
- Author: Ashraf S A AlMadhoun
- Link: https://www.udemy.com/course/arduino-i2c-itwoc-communication-with-i2c-protocol/?couponCode=JULYMAXDICOUNT

## Connections

- I2C bus: `SDA`, `SCL` with pull-up resistors to VCC, common `GND`.
- Device address e.g., `0x3C`.
- Typical pull-ups: 4.7kΩ to 3.3V or 5V depending on device levels.

## Diagram (ASCII)

```
 SDA <----> Device SDA (pull-up)
 SCL <----> Device SCL (pull-up)
 GND ----- Common ground
 VCC ----- Device supply
```

## Notes

- Ensure voltage level compatibility between controller and devices.
- Keep bus lines short and use proper decoupling capacitors near devices.

