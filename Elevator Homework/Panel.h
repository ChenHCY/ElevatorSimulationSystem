#ifndef Panel_h
#define Panel_h

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Panel
{
	struct Button
	{
		string label;
		bool lit;
		int sequence;
		static int count;
    };
	
vector<Button> buttons;
public:
	void addButton(string);
	void press(string);
	void clear(string);
	string getFirstLit() const;
	bool isLit(string) const;
	bool areAnyLit() const;
	friend ostream& operator<<(ostream&, const Panel&);
};

#endif 
