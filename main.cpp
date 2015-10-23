// AI N Queens Problem

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <string.h>
#include <sapi.h>

using namespace std;

// Global Variables
HANDLE hconsole;
int colour = 0;
string speak_up = "NULL";
bool debugger_1 = false;
int possible_locations[64];
int possibilities = 0;
int clk = 0;



struct cords
{
	int x, y;
}dat[100];

class data
{
public:
	int chess_board[8][8];
	int deadzone[8][8];
	int queens;
protected: 



private:




} method[100];

class ai : private data
{
public:
	long double iterations;

protected:



private:





}itr;


class rules : public data
{
public:


	void create_board()
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				for (int k = 0; k < 100; k++)
				{
					method[k].chess_board[i][j] = 0;
					method[k].deadzone[i][j] = 0;
					method[k].queens = 0;
				}
			}

		}

		
	}

	void colour(int incolor)
	{
		/*
		10 : Green
		12 : Red
		11 : Blue
		7 : Grey
		15 : White
		
		*/
	
		SetConsoleTextAttribute(hconsole, incolor);
	}
	
	void place_queen(int x, int y,int c_method,int undo = 0)
	{

		if (possibilities == 0 && method[c_method].queens != 0)
		{
			cout << "\nPlacing Queen when Possibilities = 0 and Old board is present\n";

		}
		method[c_method].chess_board[x][y]++;
		method[c_method].queens++;
		if (undo == 1)
		{
//			cout << "undo1";
			method[c_method].chess_board[x][y]--;
			method[c_method].chess_board[x][y]--;
			method[c_method].queens--;
			method[c_method].queens--;

		}
	}

	void find_deadzones(int x, int y, int c_method, int undo = 0)
	{


		// Zone 1
		for (int j = 1; y + j < 8; j++)
		{

			method[c_method].deadzone[x][y + j]++;

			if (undo)
			{
				cout << "UNDO1";
				method[c_method].deadzone[x][y + j]--;
				method[c_method].deadzone[x][y + j]--;

			}
			if (debugger_1)
			{
				colour(7);
				cout << "Deadzone at " << x << " " << y + j << endl;
			}

		}

		// Zone 2
		for (int j = 1; y - j > -1; j++)
		{

			method[c_method].deadzone[x][y - j]++;
			if (undo)
			{
				cout << "UNDO2";
				method[c_method].deadzone[x][y - j]--;
				method[c_method].deadzone[x][y - j]--;

			}
			if (debugger_1)
			{
				colour(7);
				cout << "Deadzone at " << x << " " << y - j << endl;
			}

		}


		// Zone 3
		for (int i = 1; x + i < 8; i++)
		{

			method[c_method].deadzone[x + i][y]++;
			if (undo)
			{
				cout << "UNDO3";
				method[c_method].deadzone[x + i][y]--;
				method[c_method].deadzone[x + i][y]--;

			}
			if (debugger_1)
			{
				colour(7);
				cout << "Deadzone at " << x + i << " " << y << endl;
			}

		}

		// Zone 4
		for (int i = 1; x - i > -1; i++)
		{

			method[c_method].deadzone[x - i][y]++;
			if (undo)
			{
				cout << "UNDO4";

				method[c_method].deadzone[x - i][y]--;
				method[c_method].deadzone[x - i][y]--;

			}
			if (debugger_1)
			{
				colour(7);
				cout << "Deadzone at " << x - i << " " << y << endl;
			}


		}

		// Zone 5
		int a5 = 1;
		int b5 = 1;

		while (  x + a5 < 8 && y + b5 < 8)
		{

			method[c_method].deadzone[x + a5][y + b5]++;
			if (undo)
			{
				cout << "UNDO5";
				method[c_method].deadzone[x + a5][y + b5]--;
				method[c_method].deadzone[x + a5][y + b5]--;

			}
			if (debugger_1)
			{
				colour(7);
				cout << "Deadzone at " << x + a5 << " " << y + b5 << endl;
			}

			a5++;
			b5++;

		}

		// Zone 6
		int a6 = 1;
		int b6 = 1;

		while( x - a6 > -1 && y - b6 > -1)
		{


			method[c_method].deadzone[x - a6][y - b6]++;
			if (undo)
			{
				cout << "UNDO6";
				method[c_method].deadzone[x - a6][y - b6]--;
				method[c_method].deadzone[x - a6][y - b6]--;

			}
			if (debugger_1)
			{
				colour(7);
				cout << "Deadzone at " << x - a6 << " " << y - b6 << endl;
			}

			a6++;
			b6++;

		}


		// Zone 7
		int a7 = 1;
		int b7 = 1;

		while (x - a7 > -1 && y + b7 < 8)
		{


			method[c_method].deadzone[x - a7][y + b7]++;
			if (undo)
			{
				cout << "UNDO7";
				method[c_method].deadzone[x - a7][y + b7]--;
				method[c_method].deadzone[x - a7][y + b7]--;

			}
			if (debugger_1)
			{
				colour(7);
				cout << "Deadzone at " << x - a7 << " " << y + b7 << endl;
			}

			a7++;
			b7++;

		}


		// Zone 8
		int a8 = 1;
		int b8 = 1;

		while (x + a8 < 8 && y - b8 > -1)
		{


			method[c_method].deadzone[x + a8][y - b8]++;
			if (undo)
			{
				cout << "UNDO8";
				method[c_method].deadzone[x + a8][y - b8]--;
				method[c_method].deadzone[x + a8][y - b8]--;

			}
			if (debugger_1)
			{
				colour(7);
				cout << "Deadzone at " << x + a8 << " " << y - b8 << endl;
			}

			a8++;
			b8++;

		}










	}

	void undo(int buffer_x, int buffer_y)
	{
		place_queen(buffer_x,buffer_y, 0 ,1);
		find_deadzones(buffer_x, buffer_y, 0, 1);

	}

	void get_possible_locations(int on_going_method)
	{
		possibilities = 0;
		for (int i = 0; i < 64; i++)
		{
			possible_locations[i] = 0;
		}

		int counter = 0;

		for (int i = 0; i < 8; i++)
		{

			for (int j = 0; j < 8; j++)
			{

				if (method[on_going_method].chess_board[i][j] == 0 && method[on_going_method].deadzone[i][j] == 0)
				{
					possible_locations[counter] = counter;
					possibilities++;
				}
				counter++;
			}
		}
	}

	int brute_force_possibility_generator(int on_going_method)
	{
		int poss = rand() % possibilities;
		int p_count = -1;

		int i = 0;

		while (i<64 && p_count != poss)
		{
			if (possible_locations[i] != 0)
			{
				p_count++;

			}

			i++;

		}
		i--;
		return(i);
	}

	cords get_co_od(int cod)
	{
		cords k;

		k.y = cod % 8;
		int temp;
		temp = cod - k.y;
		k.x = temp / 8;

		return(k);
	}

	void ucd()
	{
		apply.colour(12);
		cout << "Under Cover Debugger CALL:: " << clk << endl;
		clk++;
		apply.colour(7);
	}


protected:



private:





} apply;


std::wstring s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}

int voice()
{
	std::wstring stemp = s2ws(speak_up);
	LPCWSTR result = stemp.c_str();

	ISpVoice * pVoice = NULL;

	if (FAILED(::CoInitialize(NULL)))
		return FALSE;

	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);
	if (SUCCEEDED(hr))
	{
		hr = pVoice->Speak(result, 0, NULL);
		pVoice->Release();
		pVoice = NULL;
	}

	::CoUninitialize();

}

void display_scene(int on_going_method)
{
	apply.colour(7);
	cout << "Chessboard\n\n";

	cout << "0 1 2 3 4 5 6 7\n\n";
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (method[on_going_method].chess_board[i][j] == 0)
			{
				apply.colour(7);
				cout << method[on_going_method].chess_board[i][j] << " ";
			}
			else if (method[on_going_method].deadzone[i][j] != 0)
			{
				apply.colour(12);
				cout << method[on_going_method].chess_board[i][j] << " ";
				apply.colour(7);
			}

			else
			{
				apply.colour(10);
				cout << method[on_going_method].chess_board[i][j] << " ";
				apply.colour(7);
			}
		}
		cout << " " << i << endl;

	}
	apply.colour(11);
	cout << endl << "Queens on board: " << method[on_going_method].queens;
	apply.colour(7);
	cout << "\n\nDeadzone\n\n";
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (method[on_going_method].deadzone[i][j] == 0)
			{
				apply.colour(7);
				cout << method[on_going_method].deadzone[i][j] << " ";
			}
			else
			{
				apply.colour(12);
				cout << method[on_going_method].deadzone[i][j] << " ";
				apply.colour(7);
			}
		}
		cout << endl;

	}


}


void game()
{
	int on_going_method = 0;

	int pos_x, pos_y;
	int buffer_x, buffer_y;


	while (true)
	{
		cout << "Input Position of Queen: ";
		cin >> pos_x >> pos_y;
		cout << endl;

		if (pos_x > 7 || pos_y > 7)
		{
			apply.undo(buffer_x,buffer_y);
		}
		else
		{

			buffer_x = pos_x;
			buffer_y = pos_y;
			apply.place_queen(pos_x, pos_y, on_going_method, 0);
			apply.find_deadzones(pos_x, pos_y, on_going_method);
		}
		display_scene(on_going_method);

	}

}


int main()
{
	string k = "Queen queen queen";

	hconsole = GetStdHandle(STD_OUTPUT_HANDLE);

   
	ai overall;
	overall.iterations = 0;
	apply.create_board();

	// Method 0
	// Randomly Place a queen
	// Brute Force
	
	int r1 = rand() % 8;
	int r2 = rand() % 8;
	cin >> r1;  // Input first two to randomize
	cin >> r2;
	int on_going_method = 0;
	bool method_working = true;
	int old_queens = 0;

	bool reached_solution = false;

	while (reached_solution != true)
	{


		for (int on_going_method = 0; on_going_method < 100; on_going_method++)
		{
			int r1 = rand() % 8;
			int r2 = rand() % 8;

			//		int old_queens = method[on_going_method].queens;

			bool method_working = true;
			//		cin.get();
			//		cin >> r1 >> r2;
			while (method_working)
			{
				if (possibilities == 0 && method[on_going_method].queens != 0)
				{
					cout << "\nCall going to place queen from MAIN when possibility = 0 & not a new board\n";

				}
				overall.iterations++;
				apply.place_queen(r1, r2, on_going_method);
				apply.find_deadzones(r1, r2, on_going_method);
				apply.get_possible_locations(on_going_method);
//  			cout << endl << possibilities << endl;
				if (possibilities == 0)
				{
					method_working = false;
				}
				else
				{

					dat[on_going_method] = apply.get_co_od(apply.brute_force_possibility_generator(on_going_method));

					r1 = dat[on_going_method].x;
					r2 = dat[on_going_method].y;
				}
				/*
				0  1  2  3  4  5  6  7
				8  9  10 11 12 13 14 15
				16 17 18 19 20 21 22 23
				24 25 26 27 28 29 30 31
				32 33 34 35 36 37 38 39

				*/ 

			}

			itr.iterations++;
			int new_queens = method[on_going_method].queens;

			if (new_queens > old_queens)
			{
				display_scene(on_going_method);
				cout << "Overall ITR: " << overall.iterations << " Chessboards Used: " << itr.iterations<<endl;
				cin.get();
				old_queens = method[on_going_method].queens;
			}

		}

		apply.create_board();

	}
//	game();




	string ray,ogm,rest;
		ray = char (on_going_method);
		ogm = "On going method is ";
		rest = ogm + ray;
	speak_up = rest;
	voice();








	return (0);
}

