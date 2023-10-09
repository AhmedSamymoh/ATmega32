# ATmega32 Drivers
My ATmega32 drivers journey. Integrate microcontroller peripherals smoothly. Simplify development with clear documentation and modular code for smooth hardware interaction.

<div style="text-align: right; padding-right: 30px;">
  <img src="Apps/Supplementary/ATmega32-pinout.jpg" alt="Pin Diagram" width="300">
</div>

## Layered Architecture

The driver is structured into the following layers:

### [MCAL (Microcontroller Abstraction Layer)](MCAL/)

- [DIO](MCAL/DIO/): General-Purpose Digital Input/Output module.
- [EXTI](MCAL/EXTI/): External Interrupt module.

### [HAL (Hardware Abstraction Layer)](HAL/)

- [KEYPAD](HAL/KEYPAD/): Keypad control module.
- [LCD](HAL/LCD/): Character LCD display control module.
- [SEVEN_SEGMENTS](HAL/SEVEN_SEGMENTS/): Seven-segment display control module.

### Application Layer

- [main.c](main.c): Main application code file.
- [STD_TYPES.h](STD_TYPES.h): Header file for standard data types.
- [BIT_MATH.h](BIT_MATH.h): Header file for bitwise manipulation functions.

## Contributing

Contributions to this project are welcome! Please feel free to open issues or pull requests to help improve and expand the drivers.

## License

This project is licensed under the MIT License.
