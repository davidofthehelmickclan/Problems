# Problems

How to use Rocks:
Rocks will open a file labeled input.txt.
It will read the rocks included and work out whether you can split all rocks into 2 equal groups and whether you can create 2 equal groups out of any rocks in the group.
The format of the input.txt should have a group of rocks be whitespace seperated on one line.
If multiple lines are included it will take each line as a seperate group and output the resualts for each group.

How to use Chess:
Upon running the program you will be at a menu.
The letters in front of the options is what you need to input to select that option. It is undercase only.
The options are to find posible moves for a piece, plot a route for a piece between two point, and quit.
Choosing quit will cause you to exit the program.
For either of the other options you will then recieve a menu to select what type of piece to check.
Then you will be asked to input a starting position in standard chess format. a1 is the lowerleft for the white player, a8 is the upperleft.
If you had selected possible moves you would then recieve all possible locations the piece can legally move to.
If you had selected plot a route then you will be asked to input a destination in standard chess format.
From here you will either recieve a list of spaces taking you from start to destination or fail if there is no such path.
Note: In the unlikely event that a route of 8 moves or less can't be found for the knight you will be asked if you wish to search routes of up to 16 moves.
To select that simply imput y. Otherwise input n.
In the likly immpossible situation that a route can't be found in 16 moves you will be asked if you wish to search up to 64 moves.
Input is same as above.
