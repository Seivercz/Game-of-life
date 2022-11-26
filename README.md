# [Game of life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)

Programming challenge using C++.  
[Canonical Project Structure](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2018/p1204r0.html).  

## Rules to the transitions, occuring on one field used to generate the next

1. Any live cell with fewer than two live neighbours dies, as if by underpopulation.
2. Any live cell with two or three live neighbours lives on to the next generation.
3. Any live cell with more than three live neighbours dies, as if by overpopulation.
4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

### These rules, which compare the behavior of the automaton to real life, can be condensed into the following

1. Any live cell with two or three live neighbours survives.
2. Any dead cell with three live neighbours becomes a live cell.
3. All other live cells die in the next generation. Similarly, all other dead cells stay dead

for more detailed info refer to the [wiki page](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)

## Goals

1. Make a working example with terminal or file input.
2. Make a GUI with manually clickable/randomly generatable field.
3. The game is playable in a sequence with stop/speed up buttons.
