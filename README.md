# [42] so_long

## I. General

## II. Map parsing

You will have to complete the following checks :

- Map is rectangular
- Contains at least 1 collectible/exit/player
- Map is completely closed
- Map file has a `.ber` extension

You can either use a linked list or a `char **` to store your map data. I advice you to preferably use a `char **` because it seems easier to refer to a location of your map with something like `map[x][y]`

To know if your map is rectangular, after store your map data in a `char **`. You should juste calculate the length of each row and if the length is different than the first row, then you know your map hasn't a valid format and you can already print the error and exit your program.

At the same time you also can check if all the required points are present in your map. When you are parsing each line, if you encounter an exit, player or collectible set to 1 a flag for each points. There can be multiple collectible and exit but make sure that you encounter only once a player. 

To check for borders, parse first and last row/column. If you see something else than a `1` you can exit your program. 

Finally for the `.ber` check, simply search if you find that part in the initial parameter that the program takes. 

Do not forgot to check that you do not find anything else than the allowed characters in the map file :`01ECP`


## III. Player movements and updates

For each input, depending on the direction you selected, you can simply swap the `P` value in your `map[x][y]` with the value located in your new player position. That will work only if your new position is an empty space (`0`). In the case the player goes to a collectible position, make sure to put a `0` in the old player position instead of swapping elements  from old player position to new player position. If you are just swapping, it will render a collectible or exit texture on your image.

![%5B42%5D%20so_long%20d64193e59be3436f9887b9ca685d3919/Capture_decran_2021-07-05_a_18.20.09.png](%5B42%5D%20so_long%20d64193e59be3436f9887b9ca685d3919/Capture_decran_2021-07-05_a_18.20.09.png)

Before updating the player position, you will have to check if his new position is valid or if the player is going into a wall. If it's potential new position is a wall, do not update his actual position and do not increment his number of moves.

You can also force the player to collect every items before exiting. To implement that, you can almost reused the system that check if the new player position is a wall. Just replace the characater checked `1` by `E` . Then, if there is still a collectible in the map you don't let the player goes to the exit.

## IV. Render

## V. Bonus

I didn't go super deep in the bonus, so I did very basic function for all of them. You can make a lot of sprites animation and make a complex pattern for enemy patrol if you want to.

1. Sprites animation

    For sprites animation, I used just two differents textures for player and ennemy. Based on the direction they are going, I will use one or the other. You can complete it a bit more by adding textures if they are going up or down too. To store them, just re-use the function you made to save textures.

    You can also make animated borders, exit and collectible. In your render loop, just implement a cycle that will make sure to use different textures (If a sprites has 4 different textures, they will have to use the texture 0, then 1, etc...) 

2. Enemy patrols

    To put an enemy, you can use the same structure that your player has. The only difference will be his movement. There is many ways to build a movement pattern for your enemy.

    In my case, I did a kind of dumb pattern. I decided that the enemy will try to go in the same direction 4 times and then select another direction after the 4 moves attempt. Make sure to apply the rules of your player to your enemy (he doesn't have to go in walls, etc..). It results in a clunky pattern because sometimes, my enemy will be just next to a wall and try to go in the wall direction for 4 consecutive moves.

    Also, you are free to add new rules. For exemple, I make sure that my enemy can't go into an exit, take collectible (I considered them as a wall for him).

    To handle correctly the situation where the player and the enemy goes in contact make sure to save their current and old position at any time. With my system, the player position will be updated but his old position will be set to 0, making the enemy disappear. That's why I'm storing the old position of my player and ennemy. Even if it will make the enemy disappear, my program knows that they have swapped position, then I instantly exit my program. 

3. Movement count display on screen

    To display text on your image, the mlx library has the `mlx_string_put`function. For a very basic movement count, you juste have to transform the int storing the player movements via `itoa` and display where you want on the screen.

## VI. Ressources
