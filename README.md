==============================
Electronics design Task#2
==============================

Concept and Design of a CAN enabled right RPM BLDC motor drive unit with the components described below. 

Design goals:
===============
The final product would be a single unit boxed in a 3D printed plastic enclosure (as small as possible)
WIll contain the voltage regulator+Microcontroller+MCP2515 CAN Module+Magnetic encoder.
The unit will be powered by an 18V battery series unit. The 18V will be fed directly to the ESC.
Another connection from the 18V will be fed to the step down 5V voltage regulator.
The 18V will be fed to an ESC. The ESC's trottle (twisted pair) will be powered from the 5V voltage regulator output.
The 18V DC power channel (Live and GND) will be available as input and output in/from the unit.
The CAN module will communicate to the microcontroller over SPI.
The CAN bus wires will be input and output in/from the unit.



Expectations of the task:
==============================
Design Research 
microcontroller programming. 
Wiring diagram (not professional, rough on paper/MS PAINT will do)
Enclosure design.
Input / Output connection terminal selection.
PCB design of mating board.
Wiring and assembly instruction documentation.
Bill of Material documentation.
You will prepare the plan without real device. 
For further testing, The microcontroller may be shipped to you for research 



Components to be considered:
==============================
Power Supply:SLA Power supply (18V) 
- How 18V battery will be made is irrelevant to this task.
- https://www.powerstream.com/minimoto-batteries.htm

24V to 5V Voltage regulator (Can also work as 18V->5V regulator)
- (https://www.amazon.com/BANKEE-Converter-Voltage-Regulator-Transformer/dp/B08NZV88MC/ref=sr_1_34_sspa)

Microcontroller:
Either -  
https://github.com/leaflabs/maplemini - (5V)
OR
https://www.aliexpress.com/item/1400682373.html (5V)

MCP2515 CAN Module - over SPI- (5V) 
- https://circuitdigest.com/microcontroller-projects/arduino-can-tutorial-interfacing-mcp2515-can-bus-module-with-arduino


AS5048 Magnetic Encoder PWM SPI:
- https://www.ebay.com/itm/AS5048-Magnetic-Encoder-PWM-SPI-Interface-14-Bit-Precision-For-Brushless-Motor/153636871434?hash=item23c5789d0a:g:oOMAAOSwd-5ddaWQ
How to implement:
https://forum.arduino.cc/index.php?topic=155238.0

Motor ESC (T-motor F45A 3-6S 32bit)
https://store-en.tmotor.com/goods.php?id=737 (for F80 PRO KV2200 motor )

