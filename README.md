# Linux-Shell
Shell will execute commands given by
the user. The steps involved will be as follows:
1. User types a command, such as “cp ./OS ../newOS”. The command will be stored in a character
array or a string object.
2. Shell will perform tokenization and separate the command and its arguments.
3. Shell will create a child process and use execvp system call to execute the command.
4. Shell will wait for the command to finish execution.
5. After the command has been executed, shell will ask the user to enter the command again.
6. Shell will exit when the command given by the user is “exit”.
