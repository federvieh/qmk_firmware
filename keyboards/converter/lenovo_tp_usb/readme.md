# Converter for Lenovo Thinkpad USB Keyboard with trackpoint

Using QMK to replace the controller on [this keyboard](https://www.lenovo.com/us/en/p/accessories-and-software/keyboards-and-mice/keyboards/0b47190) with a Teensy 3.2.

## Hardware
### Keyboard Matrix (ANSI)
|---+----+--------+-----+----+----+------+----+----+----+----+-------+------+-------+------+------+-----------+----------------|
|   |    |      0 | 1   | 2  | 3  | 4    | 5  | 6  | 7  | 8  |     9 |   10 | 11    | 12   | 13   | 14        | 15             |
|   |    |      6 | 9   | 12 | 13 | 15   | 16 | 17 | 18 | 19 |    20 |   21 | 22    | 23   | 24   | 25        | 26             |
|---+----+--------+-----+----+----+------+----+----+----+----+-------+------+-------+------+------+-----------+----------------|
| 0 | 14 |        | ESC | h  | F4 |      | g  |    | '" | F6 |       | LALT |       | UP   |      | F5        |                |
| 1 | 11 |        | `~  | 6  | F2 | F1   | 5  | F8 | -_ | =  | LCTRL |      |       |      | HOME | F9        | Delete forward |
| 2 | 10 |        | q   | u  | e  | w    | r  | o  | p  | i  |       |      |       |      |      |           |                |
| 3 |  8 |        | 1   | 7  | 3  | 2    | 4  | 9  | 0  | 8  |       |      | F12   | END  | F11  | F10       | Insert         |
| 4 |  7 |        | a   | j  | d  | s    | f  | l  | ;: | k  |       |      |       | Fn   |      | \ PIPE    | PrtScr         |
| 5 |  5 | RSHIFT | z   | m  | c  | x    | v  | .  |    | ,  | RCTRL |      |       |      |      | RETURN    | PgUp           |
| 6 |  4 |        |     | n  |    |      | b  |    | /? |    |       | RALT | RIGHT | LEFT | DOWN | SPACE     | PgDown         |
| 7 |  3 | LSHIFT | TAB | y  | F3 | CAPS | t  | F7 | [  | ]  |       |      | WIN   |      |      | DEL/BKSPC |                |
|---+----+--------+-----+----+----+------+----+----+----+----+-------+------+-------+------+------+-----------+----------------|

### Pins
When setting matrix pins, you need to use the MCU definitions instead of what is printed on the PCB. Sourced from <https://www.pjrc.com/teensy/schematic32.gif>. The following table can be used to convert between the two.

|--------+-----+-----------------------------|
|  PCB   | MCU | Notes                       |
|--------+-----+-----------------------------|
| 0      | B16 | Row 0                       |
| 1      | B17 | Row 1                       |
| 2      | D0  | Row 2                       |
| 3      | A12 | Row 3                       |
| 4      | A13 | Row 4                       |
| 5      | D7  | Row 5                       |
| 6      | D4  | Row 6                       |
| 7      | D2  | Row 7                       |
| 8      | D3  | Col 0                       |
| 9      | C3  | Col 1                       |
| 10     | C4  | Col 2                       |
| 11     | C6  | Col 3                       |
| 12     | C7  | Col 4                       |
| 13/LED | C5  | LED                         |
| 14/A0  | D1  | Col 5                       |
| 15/A1  | C0  | Col 6                       |
| 16/A2  | B0  | Col 7                       |
| 17/A3  | B1  | Col 8                       |
| 18/A4  | B3  | Col 9  (also SDA0)          |
| 19/A5  | B2  | Col 10 (also SCL0)          |
| 20/A6  | D5  | Col 11                      |
| 21/A7  | D6  | Col 12                      |
| 22/A8  | C1  | Col 13                      |
| 23/A9  | C2  | Col 14                      |
| 24     | A5  | Col 15                      |
| 25     | B19 |                             |
| 26/A15 | E1  |                             |
| 27/A16 | C9  |                             |
| 28/A17 | C8  |                             |
| 29/A18 | C10 | SCL1                        |
| 30/A19 | C11 | SDA1                        |
| 31/A20 | E0  |                             |
| 32     | B18 |                             |
| 33     | A4  |                             |
|--------+-----+-----------------------------|
