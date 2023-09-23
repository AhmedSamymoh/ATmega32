# ATmega32
My journey with ATmega32 drivers: integrating microcontroller peripherals with clear documentation and modular code for easy hardware interaction.
# ATmega32 Drivers

My ATmega32 drivers journey. Effortlessly integrate microcontroller peripherals. Simplify development with clear documentation and modular code for smooth hardware interaction.

## Project Structure

The project is organized into the following directories:

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
