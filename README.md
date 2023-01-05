# PIO square wave generator standalone
Arduino Script for the Pi Pico for generating a high frequency square wave with the PIO. It is based around the <a href="https://github.com/earlephilhower/arduino-pico">RP2040 library from earlephilhower</a>.

Based on the Source Code from: https://www.digikey.de/en/maker/projects/raspberry-pi-pico-and-rp2040-cc-part-3-how-to-use-pio/123ff7700bc547c79a504858c1bd8110
(modified it slightly for the Arduino IDE and faster Frequencys)

## <b>Warning!!!</b>

Higher Frequency suffer from instability of the output signal, due to the mismatch between requested and clock frequency. The maximum diviation is exaktly one clock tick. Higher Frequency of the core may help with stability. BE aware that, the Flash can only be used on core frequency lower than 133 MHz
