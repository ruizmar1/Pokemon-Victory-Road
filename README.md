# Pokemon-Victory-Road
Simple Pokemon Game Written in C++

Program structure and framework provided by staff of EC327 course at Boston University. Majority of code written by Marissa Ruiz.

# How to play:
When you run the program, you will see a simple grid with various objects. The objects are identifiable with a character code followed by an ID number. The character codes are C, G, T, and W.

C stands for Pokemon Center. This is where you can go to heal your pokemon. You can purchase potions here with Pokedollars to regain health.

G stands for Pokemon Gym. This is where you will battle other Pokemon trainers. YOu have to purchase battles with Pokedollars. When you complete a battle you will gain experience points and lose health.

T stands for Trainer. These are the players that you can move across the grid. Trainers can battle in Pokemon Gyms and heal at Pokemon Centers. As the trainer moves, it gains Pokedollars and loses health. 

W stands for Wild Pokemon. Wild Pokemon will follow trainers if trainers go directly to their location. When they follow trainers, the trainer gains health because the Pokemon is so cute it improves the trainer's mental health. 

The main goal of the game is to beat all the Pokemon Gyms. 

# Game Commands:
There are various commands you can enter to play the game. Below they are described. 

m = Move command. This will move the selected trainer across the grid. Will prompt you for x and y coordinates of destination

g = Move to gym command. This will move the selected trainer to a specified Pokemon Gym. NOTE: you must use the g command before you can battle

c = Move to center command. This will move the selected trainer to a specified Pokemon Center. NOTE: you must use the c command before you can buy potions.

s = Stop command. Stops trainer.

p = Buy potions command. You can only use this commmand if you are at a Pokemon Center. You must have arrived at center through the c command in order to buy             potions. If you have enough Pokedollars you can buy however many desired potions from a Pokemon Center. Potions will regenerate Trainer's health. 

b = Battle command. You can only use this command if you are in a Pokemon Gym. You must have arrived to the gym through the g command in order to battle. If you have     enough health and Pokedollars you can battle however many desired battles at a Pokemon Gym. After completeing a battle the trainer will gain experience and lose      health and Pokedollars. 

n = New command. This command allows you to create new objects to the game. You can add Pokemon Gyms (g), Pokemon Centers (c), Trainers (t), and Wild Pokemon (w) to     the game. They should appear on the grid. 

a = Advance command. This command moves the game forward one step, whether that means traveling one step on the grid, completing a battle, or buying a potion.           Advance command moves time forward in the game and allows user to continuously input commands. 

r = Run command. The run command moves the game forward in stepf of 5, or until there is no other action the game can take. This is like the fast forward button on       the TV. It basically speeds up the advance command so you can get things done faster. This command advances time in steps of 5. 

q = Quit command. This command stops the game and terminates the progam. 

