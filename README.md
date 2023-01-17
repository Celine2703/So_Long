SO_LONG 42

Warning, you need to have the library x11 to compile this project.

This graphic project is a 2D game inspired by Among Us where you need to collect bodies in order to reach the exit of the map.

To use this program you have access to different maps in the repository "Maps" or you can add one there by creating a new file.
Your map has to be build as follow:

The extension of the file is ".ber"
0 is an empty space,
1 is a wall,
C is a item to be collected,
E is an exit,
P is the position of the player.
Your map must be a rectangle closed by walls and contain at least 1 E, 1 C and 1 P.
example :
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111

To play, use the keys "Z,Q,S,D" to move your player. You will be able to exit the map only if all the items are collected.

how to run the so_long program :

make
./so_long ./Maps/"name_of_file".ber

BONUS PART

An enemi can be added by putting a Y in the map. This enemi is moving and if you touch it, you loose.

how to run the so_long_bonus program :

make bonus
./so_long_bonus ./Maps/"name_of_file".ber

clear all the created files ( .o etc.) by entering "make fclean".
