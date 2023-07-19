## 0x16. C - SIMPLE SHELL

### DESCRIPTION
***This is a shell implementation project in C, done in fulfilment of sprint 1 :rocket:***
- The program has same output as the `/bin/sh` shell
- Except difference in program name which is `hsh`

### FEATURES
- Displays a prompt `$ ` and waits for a user input.
- Executes the command entered by the user.
- Handles error input by printing an error message in the format
`PROGNAME: ERRNO: COMMAND: not found`
- Implements the `exit` built-in that exits the shell
***USAGE***: `exit`
- Works in both interactive and non-interactive mode

### HOW TO USE
- Clone this repo into your local machine
- `cd simple_shell` change directory to the repo
#### COMPILATION
Compile the file using this command
```C
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
#### RUNNING THE PROGRAM
After compiling, run the exe file created by typing
```C
./hsh
```
- Afterwards input your commands
#### QUITING THE PROGRAM
To quit the program running, type the `exit` built-in command or CTRL + D
```C
$ exit
```

## AUTHORS
1. [John Eric](https://github.com/Vulcanric)
2. [Chidimma Ofodum](https://github.com/ChidimmaOfodum)
