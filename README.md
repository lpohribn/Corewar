# Corewar
This is a group project: for 3 people.

Our team: lpohribn, rnovodra, opletsan.

Project of UNIT Factory (école 42).

# General information

• Corewar is a very peculiar game. It’s about bringing “players” together around a “virtual machine”, which will load some “champions” who will fight against one another with the support of “processes”, with the objective being for these champions to stay “alive”.

• The processes are executed sequentially within the same virtual machine and memory space. They can therefore, among other things, write and rewrite on top of each others so to corrupt one another, force the others to execute instructions that can damage them, try to rewrite on the go the coding equivalent of a Côtes du Rhône 1982 (that is one delicious French wine!), etc...

• The game ends when all the processes are dead. The winner is the last player reported to be “alive”.

Wikipedia ("Core War"): https://en.wikipedia.org/wiki/Core_War

# Breakdown of the project’s objectives
This project can be broken down into three distinctive parts:

• The assembler: this is the program that will compile your champions and translate them from the language you will write them in (assembly language) into “Bytecode”.Bytecode is a machine code, which will be directly interpreted by the virtual machine.

• The virtual machine: It’s the “arena” in which your champions will be executed. It offers various functions, all of which will be useful for the battle of the champions. Obviously, the virtual machine should allow for numerous simultaneous processes; we are asking you for a gladiator fight, not a one-man show simulator.

• The champion: This one is a special case. Later, in the championship, you will need to render a super powerful champion, who will scare the staff team to death.
• The visualization: You write flag -v and it shows you beatiful visualization of the game.

#  Usages
![Alt Text](https://github.com/lpohribn/Corewar/blob/master/screen_shot/Screen Shot 2019-02-12 at 3.08.24 PM.png)


# Visualization

