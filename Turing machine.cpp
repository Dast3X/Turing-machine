#include <iostream>
#include <vector>
#include <tuple>
#define STATE tm.commands
#define ADD_INSTRUCTION .push_back

using namespace std;

enum Constants
{
	INPUT,
	CHANGE,
	DIRECTION,
	NEXT_STATE
};


enum Direction
{
	STAY,
	RIGHT,
	LEFT
};
enum States
{
	Q1,Q2,Q3,
	Q4,Q5,Q6,
	Q7,Q8,Q9,
	Q10,Q11,Q12,
	Q13,Q14,Qz
};

class TuringMachine;
int tape_index = 1;
int current_state = Q1;

class Tape
{
public:
	Tape() {}
	Tape(string str)
	{
		tape.push_back(' ');
		for (const auto& i : str)
			tape.push_back(i);
		for (size_t i = 0; i < 50; i++)
		{
			tape.push_back(' ');
		}


	}
	void print_tape()
	{
		for (const auto& i : tape)
			cout << i;
	}
	char operator[](int index)
	{
		return tape[index];
	}

	int size() { return tape.size(); }
	vector<char> tape;
};

class TuringMachine
{
public:
	TuringMachine(int q, Tape tape)
	{
		for (int i = 0; i < q; i++)
			commands.push_back(vector<tuple<char, char, int, int>>());
		this->tape = tape;
		qs = q;
	}

	void start()
	{
		int iteration = 0;
			for (int i = 0; i < commands[current_state].size(); i++)
			{
				if (current_state == Qz)
				{
					cout << "\n Result:";
					tape.print_tape();
					return;
				}
				if (tape[tape_index] == get<INPUT>(commands[current_state][i]))
				{
					iteration++;
					change(get<CHANGE>(commands[current_state][i]));
					move(get<DIRECTION>(commands[current_state][i]));
					next_state(get<NEXT_STATE>(commands[current_state][i]));
					tape.print_tape();
					cout << "\n";
					i = -1;
				}
				if (current_state == Qz)
				{
					cout << "\nResult:";
					tape.print_tape();
					return;
				}

			}
			throw exception("Missing instruction");
	}

	void move(int direction)
	{
		if (direction == RIGHT)
		{
			++tape_index;
		}
		else if (direction == LEFT)
		{
			--tape_index;
		}
		else if (direction == STAY)
		{
			return;
		}
		else
		{
			throw exception("incorrect direction");
		}
	}
	void change(char change)
	{
		tape.tape[tape_index] = change;
	}
	void next_state(int state)
	{
		current_state = state;
	}
	vector<vector<tuple<char, char, int, int>>> commands;
	Tape tape;
	int qs;
};


int main()
{

	Tape tp("1111111");
	TuringMachine tm(20, tp);

	STATE[Q1]ADD_INSTRUCTION({'1', '1', RIGHT, Q2 });
	STATE[Q1]ADD_INSTRUCTION({'=', '=', RIGHT, Q5 });
	STATE[Q1]ADD_INSTRUCTION({' ', '1', RIGHT, Q13 });

	STATE[Q2]ADD_INSTRUCTION({'1', '$', RIGHT, Q3 });
	STATE[Q2]ADD_INSTRUCTION({'$', '$', RIGHT, Q1 });
	STATE[Q2]ADD_INSTRUCTION({'=', '=', RIGHT, Q5 });
	STATE[Q2]ADD_INSTRUCTION({' ', ' ', LEFT,  Qz });

	STATE[Q3]ADD_INSTRUCTION({'1', '1', RIGHT, Q3 });
	STATE[Q3]ADD_INSTRUCTION({'$', '$', RIGHT, Q3 });
	STATE[Q3]ADD_INSTRUCTION({'=', '=', RIGHT, Q7 });
	STATE[Q3]ADD_INSTRUCTION({' ', '=', RIGHT, Q1 });

	STATE[Q4]ADD_INSTRUCTION({'1', '1', RIGHT, Q4 });
	STATE[Q4]ADD_INSTRUCTION({'$', '$', RIGHT, Q4 });
	STATE[Q4]ADD_INSTRUCTION({',', 'a', RIGHT, Q4 });
	STATE[Q4]ADD_INSTRUCTION({'=', '=', RIGHT, Q4 });
	STATE[Q4]ADD_INSTRUCTION({'a', 'a', RIGHT, Q4 });
	STATE[Q4]ADD_INSTRUCTION({' ', ' ', LEFT,  Q12 });

	STATE[Q5]ADD_INSTRUCTION({'1', '1', RIGHT, Q5 });
	STATE[Q5]ADD_INSTRUCTION({'$', '$', RIGHT, Q5 });
	STATE[Q5]ADD_INSTRUCTION({',', ',', RIGHT, Q5 });
	STATE[Q5]ADD_INSTRUCTION({'=', '=', RIGHT, Q5 });
	STATE[Q5]ADD_INSTRUCTION({' ', ' ', LEFT,  Q6 });

	STATE[Q6]ADD_INSTRUCTION({',', ' ', LEFT,  Q8 });

	STATE[Q7]ADD_INSTRUCTION({'1', '1', RIGHT, Q7 });
	STATE[Q7]ADD_INSTRUCTION({',', 'a', RIGHT, Q7 });
	STATE[Q7]ADD_INSTRUCTION({' ', ' ', STAY,  Q1 });

	STATE[Q8]ADD_INSTRUCTION({'1', '1', LEFT,  Q8 });
	STATE[Q8]ADD_INSTRUCTION({'$', '1', LEFT,  Q8 });
	STATE[Q8]ADD_INSTRUCTION({',', ',', LEFT,  Q8 });
	STATE[Q8]ADD_INSTRUCTION({'=', '=', LEFT,  Q8 });
	STATE[Q8]ADD_INSTRUCTION({'a', 'a', LEFT,  Q8 });
	STATE[Q8]ADD_INSTRUCTION({' ', ' ', RIGHT, Qz });

	STATE[Q9]ADD_INSTRUCTION({'1', '1', RIGHT, Q9 });
	STATE[Q9]ADD_INSTRUCTION({',', ',', RIGHT, Q9 });
	STATE[Q9]ADD_INSTRUCTION({' ', ' ', STAY,  Q1 });

	STATE[Q10]ADD_INSTRUCTION({'1', '1', LEFT,  Q10 });
	STATE[Q10]ADD_INSTRUCTION({'$', '$', LEFT,  Q10 });
	STATE[Q10]ADD_INSTRUCTION({',', ',', LEFT,  Q10 });
	STATE[Q10]ADD_INSTRUCTION({'=', '=', LEFT,  Q10 });
	STATE[Q10]ADD_INSTRUCTION({'a', 'a', LEFT,  Q10 });
	STATE[Q10]ADD_INSTRUCTION({' ', ' ', RIGHT, Q1  });

	STATE[Q11]ADD_INSTRUCTION({'1', '1', RIGHT, Q11 });
	STATE[Q11]ADD_INSTRUCTION({',', ',', RIGHT, Q11 });
	STATE[Q11]ADD_INSTRUCTION({'a', 'a', RIGHT, Q11 });
	STATE[Q11]ADD_INSTRUCTION({' ', ',', STAY,  Q10 });

	STATE[Q12]ADD_INSTRUCTION({'1', '1', LEFT,  Q12 });
	STATE[Q12]ADD_INSTRUCTION({',', ',', LEFT,  Q12 });
	STATE[Q12]ADD_INSTRUCTION({'=', '=', RIGHT, Q11 });
	STATE[Q12]ADD_INSTRUCTION({'a', ',', RIGHT, Q9  });

	STATE[Q13]ADD_INSTRUCTION({'1', '$', RIGHT, Q13 });
	STATE[Q13]ADD_INSTRUCTION({'$', '$', RIGHT, Q1  });
	STATE[Q13]ADD_INSTRUCTION({'=', '=', RIGHT, Q5  });
	STATE[Q13]ADD_INSTRUCTION({' ', '1', RIGHT, Q4  });

  //STATE[Q1]ADD_INSTRUCTION({'0','0',RIGHT,Q1});
  //STATE[Q1]ADD_INSTRUCTION({'1','1',RIGHT,Q1});
  //STATE[Q1]ADD_INSTRUCTION({'2','2',RIGHT,Q1});
  //STATE[Q1]ADD_INSTRUCTION({'3','3',RIGHT,Q1});
  //STATE[Q1]ADD_INSTRUCTION({'4','4',RIGHT,Q1});
  //STATE[Q1]ADD_INSTRUCTION({'5','5',RIGHT,Q1});
  //STATE[Q1]ADD_INSTRUCTION({'6','6',RIGHT,Q1});
  //STATE[Q1]ADD_INSTRUCTION({'7','7',RIGHT,Q1});
  //STATE[Q1]ADD_INSTRUCTION({'8','8',RIGHT,Q1});
  //STATE[Q1]ADD_INSTRUCTION({'9','9',RIGHT,Q1});
  //STATE[Q1]ADD_INSTRUCTION({' ',' ',LEFT,Q2});
  // 
  //STATE[Q2]ADD_INSTRUCTION({'0','7',STAY,Qz});
  //STATE[Q2]ADD_INSTRUCTION({'1','8',STAY,Qz});
  //STATE[Q2]ADD_INSTRUCTION({'2','9',STAY,Qz});
  //STATE[Q2]ADD_INSTRUCTION({'3','0',LEFT,Q3});
  //STATE[Q2]ADD_INSTRUCTION({'4','1',LEFT,Q3});
  //STATE[Q2]ADD_INSTRUCTION({'5','2',LEFT,Q3});
  //STATE[Q2]ADD_INSTRUCTION({'6','3',LEFT,Q3});
  //STATE[Q2]ADD_INSTRUCTION({'7','4',LEFT,Q3});
  //STATE[Q2]ADD_INSTRUCTION({'8','5',LEFT,Q3});
  //STATE[Q2]ADD_INSTRUCTION({'9','6',LEFT,Q3});
  //		
  //STATE[Q3]ADD_INSTRUCTION({'0','1',STAY,Qz});
  //STATE[Q3]ADD_INSTRUCTION({'1','2',STAY,Qz});
  //STATE[Q3]ADD_INSTRUCTION({'2','3',STAY,Qz});
  //STATE[Q3]ADD_INSTRUCTION({'3','4',STAY,Qz});
  //STATE[Q3]ADD_INSTRUCTION({'4','5',STAY,Qz});
  //STATE[Q3]ADD_INSTRUCTION({'5','6',STAY,Qz});
  //STATE[Q3]ADD_INSTRUCTION({'6','7',STAY,Qz});
  //STATE[Q3]ADD_INSTRUCTION({'7','8',STAY,Qz});
  //STATE[Q3]ADD_INSTRUCTION({'8','9',STAY,Qz});
  //STATE[Q3]ADD_INSTRUCTION({'9','0',LEFT,Q3});
  //STATE[Q3]ADD_INSTRUCTION({' ','1',STAY,Qz});

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

}


