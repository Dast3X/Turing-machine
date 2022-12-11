
# How to use
##Create an object of Tape
```cpp
    Tape [name of the tape]("[any sequence]");

    Tape tp("1111111");
```
##Create object of Turing Machine
```cpp
    TuringMachine tm([max commands of state], [tape]);

    TuringMachine tm(20, tp);
```
(Do not change the name of turing machine it always must be ‘tm’; you can put a big number in [max commands of state], it will not cause problems)
##To add commands to state
```cpp
    STATE[[state]]ADD_INSTRUCTION({'[tape symbol]', '[output]', [direction], [next state] });

    STATE[Q1]ADD_INSTRUCTION({'1', '1', RIGHT, Q2 });
```
##Start program
```cpp
		tp.print_tape();
		cout << "\n\n";
		try
		{
			tm.start();
		}
		catch (const exception& error)
		{
			cout << error.what() << "\n\n\n";
    }
```
##You must use my Enums to work with my program.
```cpp
Direction: STAY RIGHT LEFT
States: Q1 Q2 Q3 Q4 Q5 Q6 Q7 Q8 Q9 Q10 Q11 Q12 Q13 Q14
Stop-State: Qz
```
