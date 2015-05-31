
#include <stdio.h>
#include "blynkDependency.h"

#ifdef WIZNET_WIZ550WEB
	#include "gpioHandler.h"
	#include "userHandler.h"
#elif defined WIZNET_W5500_EVB
	#include "board.h"
	#include "adcHandler.h"
#endif

uint8_t digitalRead(uint8_t pin)
{
	uint8_t val = pin;
#ifdef WIZNET_WIZ550WEB
	val = get_IO_Status(pin);
#elif defined WIZNET_W5500_EVB
	val	= Chip_GPIO_GetPinState(LPC_GPIO, dio_ports[pin], dio_pins[pin]);
#else
	printf("digital pin %d read\r\n", pin);
#endif
	return val;
}

void digitalWrite(uint8_t pin, uint8_t val)
{
#ifdef WIZNET_WIZ550WEB
	IOdata.ios[pin] = val;
	if(val == HIGH) 	IO_On(pin);
	else if(val == LOW)	IO_Off(pin);
	write_IOstorage(&IOdata, sizeof(IOdata));
#elif defined WIZNET_W5500_EVB
	if(val == HIGH) 	Chip_GPIO_SetPinState(LPC_GPIO, dio_ports[pin], dio_pins[pin], true); 	// High
	else if(val == LOW)	Chip_GPIO_SetPinState(LPC_GPIO, dio_ports[pin], dio_pins[pin], false);	// Low
#else
	printf("digital pin %d write val %d\r\n", pin, val);
#endif
}

uint16_t analogRead(uint8_t pin)
{
	uint8_t analog_pin = 0;
	uint16_t val = 0;
	if(pin > 14) analog_pin = pin - 14;
#ifdef WIZNET_WIZ550WEB
	//printf("analog_pin = %d\r\n", analog_pin);
	val = get_ADC_val(analog_pin);
#elif defined WIZNET_W5500_EVB
	printf("analog_pin = %d\r\n", analog_pin);
	if(analog_pin == A0) analog_pin = AIN;
	printf("changed analog_pin = %d\r\n", analog_pin);
	val = get_ADC_val(analog_pin);
#else
	printf("analog pin %d read\r\n", analog_pin);
#endif
	return val;
}

void analogWrite(uint8_t pin, uint8_t val)
{
#ifdef WIZNET_WIZ550WEB
	printf("Analog Write: Not supported yet. pin %d, val %d", pin, val);
#elif defined WIZNET_W5500_EVB
	printf("Analog Write: Not supported yet. pin %d, val %d", pin, val);
#else
	printf("analog pin %d write val %d\r\n", pin, val);
#endif
}

// Pin mode (dir) defines
// 0: Input
// 1: Output
// 2: Input Pull-up
void pinMode(uint8_t pin, pinmode_dir dir)
{
#ifdef WIZNET_WIZ550WEB
	if(dir == INPUT) 				IOdata.io[pin] = Input;
	else if(dir == INPUT_PULLUP)	IOdata.io[pin] = Input;
	else if(dir == OUTPUT)			IOdata.io[pin] = Output; // Output
	IO_Init(pin);
	write_IOstorage(&IOdata, sizeof(IOdata));
#elif defined WIZNET_W5500_EVB
	if(dir == INPUT) 				Chip_GPIO_SetPinDIRInput(LPC_GPIO, dio_ports[pin], dio_pins[pin]);	// Input
	else if(dir == INPUT_PULLUP) 	Chip_GPIO_SetPinDIRInput(LPC_GPIO, dio_ports[pin], dio_pins[pin]);	// Input
	else if(dir == OUTPUT)			Chip_GPIO_SetPinDIROutput(LPC_GPIO, dio_ports[pin], dio_pins[pin]); // Output
#else
	printf("pinmode setting: pin %d dir %d\r\n", pin, dir);
#endif
}

// Virtual Pin Read / Write functions; Not fully supported yet
uint16_t virtualRead(uint8_t pin)
{
	printf("virtual pin %d read\r\n", pin);
	return pin;
}

void virtualWrite(uint8_t pin, uint16_t val)
{
	printf("virtual pin %d write val %d\r\n", pin, val);
}
