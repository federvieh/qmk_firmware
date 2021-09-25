# Converter for Lenovo Thinkpad USB Keyboard with trackpoint

The aim of this project is to replace the controller on
[this keyboard](https://www.lenovo.com/us/en/p/accessories-and-software/keyboards-and-mice/keyboards/0b47190) with a Teensy 3.2.
The keyboard consists of the following parts:
 * keyboard controller (the part we are going to replace)
 * keyboard PCB is actually a flexible printed circuit (FPC) with 30 pins / 1 mm pitch
 * the trackpoint is a connected through a flexible flat cable (FFC) with 4 pins / 1 mm pitch

## Hardware
### Used components
 * Teensy 3.2
 * FFC/FPC 30 pin adapter board 1mm pitch (for connecting the keyboard FPC)
 * FFC/FPC 4 pin adapter board 1mm pitch (for connecting the trackpoints FFC)

The author ordered their FFC/FPC connector boards from Aliexpress. The board's pin labeling on the top and bottom side did not
match. When looking from the back (i.e. the connected FPC is facing away from the viewer) onto the top of the board the leftmost
pin is labeled "1" on the top side and "30" on the bottom side.

### Keyboard Matrix (ANSI)
|-----+--------+--------+--------+-----+----+----+------+----+----+----+----+-------+------+-------+------+------+-----------+----------------|
|     |        |    Col |      0 | 1   | 2  | 3  | 4    | 5  | 6  | 7  | 8  |     9 |   10 |    11 | 12   |   13 | 14        | 15             |
|     |        | Bottom |      6 | 9   | 12 | 13 | 15   | 16 | 17 | 18 | 19 |    20 |   21 |    22 | 23   |   24 | 25        | 26             |
| Row | Bottom |    Top |     25 | 22  | 19 | 18 | 16   | 15 | 14 | 13 | 12 |    11 |   10 |     9 | 8    |    7 | 6         | 5              |
|-----+--------+--------+--------+-----+----+----+------+----+----+----+----+-------+------+-------+------+------+-----------+----------------|
|   0 |     14 |     17 |        | ESC | h  | F4 |      | g  |    | '" | F6 |       | LALT |       | UP   |      | F5        |                |
|   1 |     11 |     20 |        | `~  | 6  | F2 | F1   | 5  | F8 | -_ | =  | LCTRL |      |       |      | HOME | F9        | Delete forward |
|   2 |     10 |     21 |        | q   | u  | e  | w    | r  | o  | p  | i  |       |      |       |      |      |           |                |
|   3 |      8 |     23 |        | 1   | 7  | 3  | 2    | 4  | 9  | 0  | 8  |       |      |   F12 | END  |  F11 | F10       | Insert         |
|   4 |      7 |     24 |        | a   | j  | d  | s    | f  | l  | ;: | k  |       |      |       | Fn   |      | \ PIPE    | PrtScr         |
|   5 |      5 |     26 | RSHIFT | z   | m  | c  | x    | v  | .  |    | ,  | RCTRL |      |       |      |      | RETURN    | PgUp           |
|   6 |      4 |     27 |        |     | n  |    |      | b  |    | /? |    |       | RALT | RIGHT | LEFT | DOWN | SPACE     | PgDown         |
|   7 |      3 |     28 | LSHIFT | TAB | y  | F3 | CAPS | t  | F7 | [  | ]  |       |      |   WIN |      |      | DEL/BKSPC |                |
|-----+--------+--------+--------+-----+----+----+------+----+----+----+----+-------+------+-------+------+------+-----------+----------------|

### Pins
When setting matrix pins in config.h, you need to use the MCU definitions instead of what is printed on the PCB. Sourced from
<https://www.pjrc.com/teensy/schematic32.gif>.

The following table shows the usage in this project. The first column refers the label on the PCB, the second to the label on the
bottom side of the connector board, the third to the label on the top side of the connector board, the fourth the MCU definition,
and the fifth the pin's function in this project.

|--------+------------------+---------------+-----+--------------------|
| PCB    | Connector bottom | Connector top | MCU | Usage              |
|--------+------------------+---------------+-----+--------------------|
| 0      |               14 |            17 | B16 | Row 0              |
| 1      |               11 |            20 | B17 | Row 1              |
| 2      |               10 |            21 | D0  | Row 2              |
| 3      |                8 |            23 | A12 | Row 3              |
| 4      |                7 |            24 | A13 | Row 4              |
| 5      |                5 |            26 | D7  | Row 5              |
| 6      |                4 |            27 | D4  | Row 6              |
| 7      |                3 |            28 | D2  | Row 7              |
| 8      |                6 |            25 | D3  | Col 0              |
| 9      |                9 |            22 | C3  | Col 1              |
| 10     |               12 |            19 | C4  | Col 2              |
| 11     |               13 |            18 | C6  | Col 3              |
| 12     |               15 |            16 | C7  | Col 4              |
| 13/LED |                  |               | C5  | LED                |
| 14/A0  |               16 |            15 | D1  | Col 5              |
| 15/A1  |               17 |            14 | C0  | Col 6              |
| 16/A2  |               18 |            13 | B0  | Col 7              |
| 17/A3  |               19 |            12 | B1  | Col 8              |
| 18/A4  |               20 |            11 | B3  | Col 9  (also SDA0) |
| 19/A5  |               21 |            10 | B2  | Col 10 (also SCL0) |
| 20/A6  |               22 |             9 | D5  | Col 11             |
| 21/A7  |               23 |             8 | D6  | Col 12             |
| 22/A8  |               24 |             7 | C1  | Col 13             |
| 23/A9  |               25 |             6 | C2  | Col 14             |
| 24     |               26 |             5 | A5  | Col 15             |
| 25     |                  |               | B19 |                    |
| 26/A15 |                  |               | E1  |                    |
| 27/A16 |                  |               | C9  |                    |
| 28/A17 |                  |               | C8  |                    |
| 29/A18 |                  |               | C10 | SCL1               |
| 30/A19 |                  |               | C11 | SDA1               |
| 31/A20 |                  |               | E0  |                    |
| 32     |                  |               | B18 |                    |
| 33     |                  |               | A4  |                    |
|--------+------------------+---------------+-----+--------------------|

# TODOs / Open topics
 - Connect the trackpoint
