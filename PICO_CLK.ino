#include <hardware/pio.h>
#include "PICO_CLK.pio.h"                                     // precompiled PIO programm

void setup() {
  static const uint8_t led_pin = 22;
  static const double pio_clk_freq = 8192000;
  PIO pio = pio0;                                             // Select an PIO Instance (0 or 1)
  uint8_t sm = pio_claim_unused_sm(pio, true);                   // Get the a free state machine in PIO 0
  uint8_t offset = pio_add_program(pio, &clk_program);         // Add PIO programm to the memory and return with the memory offset
  double div = (double)clock_get_hz(clk_sys) / (pio_clk_freq * 2);  // Caltulate the clock divider for the PIO
  clk_program_init(pio, sm, offset, led_pin, div);          // Initialize the programm with the helper function of the .pio file
  pio_sm_set_enabled(pio, sm, true);                          // Start the PIO programm in the state machine
}

void loop() {
  // Do Nothing
}
