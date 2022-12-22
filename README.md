# Space Invaders

Description
------------
- Space Invaders is a 1978 shoot 'em up arcade game developed by Tomohiro
Nishikado.
- This version is ported on a *TM4C123GH6PM* kit and a *Nokia5110* LCD screen.
- It uses a potentiometer to move player *ship* to avoid enemies *missiles* and
cover behind *bunkers*.

Implementation
---------------
- The [`main thread`] has a `Game_Init()` and `Game_Loop()` functions
    - [`Game_Init()`]: 
        1. configures the system to get its clock from the PLL,
        2. initializes the `Nokia5110` LCD, 
        3. configures the `sound` module which uses a 4-bit binary-weighted
           `DAC` and `timer0` to produce an 11KHz sound waves, 
        4. initializes the `ADC` module which is resposible for the detection
           of the `ship` position, 
        5. initializes the buttons for normal and special weapons,
        6. and finally, enabling interrupts.
    - [`Game_Loop()`]: An infinite loop that uses a `binary semaphore` to check
                     if there is an update occurs and calling [`Game_Update()`]
                     function which update the screen.
- The [`background thread`] which is the `Game_Engine()` function that does
  all the work, it:
    1. updates the `ship` position, check if a player `missile` catches and
       enemy, and the same for player `ship` and bunkers,
    2. moves any alive `missile`,
    3. checks if the player fires a missile (either normal or special) and
       fires it,
    4. randomely fires a missile every quarter second towards the ship and a 
       special missile every two seconds.

Tools
-----
1. [TivaC LaunchPad],
2. Potentiometer,
3. Two switches,
4. Two LEDs,
6. [Nokia5110 LCD],
7. Four to six resistors to build a 4-bit `DAC`, 
8. Headphone jack,
9. Headphones.

Dev Tools
----------
1. [`PlatformIO`]
2. [`neovim`]
3. [`VSCode`]
4. [`make`]

The Game
---------
Here is a [video] of the game.

[`main thread`]: https://github.com/Alighorab/Space-Invaders/blob/main/src/SpaceInvaders.c?plain=1#L13-L18
[`Game_Init()`]: https://github.com/Alighorab/Space-Invaders/blob/main/src/SpaceInvaders.c?plain=1#L20-L33
[`Game_Loop()`]: https://github.com/Alighorab/Space-Invaders/blob/main/src/SpaceInvaders.c?plain=1#L109-L118
[`background thread`]: https://github.com/Alighorab/Space-Invaders/blob/main/src/SpaceInvaders.c?plain=1#L120-L150
[`Game_Update()`]: https://github.com/Alighorab/Space-Invaders/blob/main/src/SpaceInvaders.c?plain=1#L152-L213
[TivaC LaunchPad]: https://www.ti.com/tool/EK-TM4C123GXL
[Nokia5110 LCD]: https://www.amazon.eg/-/en/Generic-Nokia-5110-LCD/dp/B0B6RKLWLK
[`PlatformIO`]: https://platformio.org/
[`neovim`]: https://neovim.io/
[`VSCode`]: https://code.visualstudio.com/
[`make`]: https://www.gnu.org/software/make/
[video]: https://youtu.be/dOAMwNEST0U
