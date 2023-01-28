# Pokemon-Victory-Road
Simple Pokemon Game Written in C++

Program structure and framework provided by staff of EC327 course at Boston University. Majority of code written by Marissa Ruiz.

# How to play:
When you run the program, you will see a simple grid with various objects. The objects are identifiable with a character code followed by an ID number. The character codes are C, G, T, and W.

C stands for Pokemon Center. This is where you can go to heal your pokemon. You can purchase potions here with Pokedollars to regain health.

G stands for Pokemon Gym. This is where you will battle other Pokemon trainers. YOu have to purchase battles with Pokedollars. When you complete a battle you will gain experience points and lose health.

T stands for Trainer. These are the players that you can move across the grid. Trainers can battle in Pokemon Gyms and heal at Pokemon Centers. As the trainer moves, it gains Pokedollars and loses health. 

W stands for Wild Pokemon. Wild Pokemon will follow trainers if trainers go directly to their location. When they follow trainers, the trainer gains health because the Pokemon is so cute it improves the trainer's mental health. 

The main goal of the game is to beat all the Pokemon Gyms. When there are no battles left in the Pokemon Gym that means you have beaten the gym.

# Game Commands:
There are various commands you can enter to play the game. Below they are described. 

m = Move command. This will move the selected trainer across the grid. Will prompt you for x and y coordinates of destination

g = Move to gym command. This will move the selected trainer to a specified Pokemon Gym. NOTE: you must use the g command before you can battle

c = Move to center command. This will move the selected trainer to a specified Pokemon Center. NOTE: you must use the c command before you can buy potions.

s = Stop command. Stops trainer.

p = Buy potions command. You can only use this commmand if you are at a Pokemon Center. You must have arrived at center through the c command in order to buy             potions. If you have enough Pokedollars you can buy however many desired potions from a Pokemon Center. Potions will regenerate Trainer's health. 

b = Battle command. You can only use this command if you are in a Pokemon Gym. You must have arrived to the gym through the g command in order to battle. If you have     enough health and Pokedollars you can battle however many desired battles at a Pokemon Gym. After completeing a battle the trainer will gain experience and lose      health and Pokedollars. 

n = New command. This command allows you to create new objects to the game. You can add Pokemon Gyms (code is g), Pokemon Centers (code is c), Trainers (code is t),      and Wild Pokemon (code is w) to the game. They should appear on the grid. 

a = Advance command. This command moves the game forward one step, whether that means traveling one step on the grid, completing a battle, or buying a potion.           Advance command moves time forward in the game and allows user to continuously input commands. 

r = Run command. The run command moves the game forward in stepf of 5, or until there is no other action the game can take. This is like the fast forward button on       the TV. It basically speeds up the advance command so you can get things done faster. This command advances time in steps of 5. 

q = Quit command. This command stops the game and terminates the progam. 

# Game Objects
As mentioned above, there are 4 game objects in this Pokemon Game. There are Pokemon Gyms, Pokemon Centers, Trainers, and Wild Pokemon. Below describes these objects attributes.

PokemonGym: A Pokemon Gym has a certain amount of available battles in them. These battles are fixed for the original two gyms but any added gyms will be assigned a random amount of battles availble. Each gym has its own Pokedollar and health fee for battle. These values are fixed for the original two gyms but then are determined randomly for new gyms. Each gym has a fixed rate of experience gained from each battle. This value is fixed for the original two gyms but then are determined randomly for new gyms. Each gym keeps track of how many trainers are in the gym. 

PokemonCenter: A PokemonCenter has its own fixed fee for potion rate and health gain rate, which is fixed for the original two centers and is determined randomly for any new centers created. Each center has a certain amount of available potion, which are fixed for the original two centers and then are determined randomly for any new centers created. Centers also keep track of how many trainers are at the center. 

Trainers: Trainers are the main component of the game. A trainer has a certain amount of health and Pokedollars that change throughout the game. As they continue to move and battle, their health decreases. When they buy potions and are followed by Wild Pokemon their health increases. With each step the trainer is given a random amount of Pokedollars. When the trainer runs out of health they will faint and dissapear from the grid. They will no longer be moveable on the grid. They each aslo have their own fixed speed for which they move across the grid. This value is fixed for the two original Trainers and then is determined randomly for new trainers. Each Trainer has their own name as well. The original two Trainers already have given names, but any newly created Trainers can be assigned a name of choice. 

WildPokemon: WildPokemon follow Trainers when Trainers land directly on them. When they follow Trainers they increase the Trainers' health because they are so cute. At any given point a Wild Pokemon is either still on the grid or following a Trainer. 

#Random, but important, Rules
-If you use the move command to travel to a gym the gym will not let you complete any battles. You MUST use the move to gym command (g) before battling in a gym. In general, if you want to travel to a Pokemon Gym to battle, use the g command over the m command to get to the gym.

-If you use the move command to travel to a center, the center will not let you buy potions. You MUST use the gym to center command (c) before buying potions. In general, if you want to travel to a Pokemon Center to buy potions, use the c command over the m command to get to the center.

-If you want Wild Pokemon to follow you you must travel to their exact location (ie their location needs to be your destination). If you pass through them while moving they will not follow you (you are not showing them the attention they deserve!!) In general, try to get Wild Pokemon to follow you because they can increase your health and thus increase your chance of beating Pokemon Gyms

# Have Fun!


