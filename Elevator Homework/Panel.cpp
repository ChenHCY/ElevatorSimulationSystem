//Panel.cpp
#include "Panel.h"

#include <iostream>
using namespace std;

int Panel::Button::count = 0;

void Panel::addButton(string label)
{
	Button temp = {label, false, -1};
	buttons.push_back(temp);
}

void Panel::press(string label)
{
	for(int i = 0; i < buttons.size(); i++)
	{
		if(this->buttons[i].label == label)
		{
			if(!buttons[i].lit)
			{
				this->buttons[i].lit = true;
				this->buttons[i].sequence == ++Button::count;
			}
		}
	}
}

void Panel::clear(string label)
{
	for(int i = 0; i < buttons.size(); i++)
	{
		if(this->buttons[i].label == label)
		{
			if(buttons[i].lit)
			{
				this->buttons[i].lit = false;
			}
		}
	}
}

string Panel::getFirstLit() const
{
	int temp = 1000;
	int indet = 0;
    for(int i = 0; i < buttons.size(); i++)
	{
		if(buttons[i].sequence < temp)
		{
			temp = buttons[i].sequence;
			indet = i;
		}
    }
	return buttons[indet].label;
}

ostream& operator << (ostream& out, const Panel& panel)
{
	for (int i = 0; i < panel.buttons.size(); i++)
	{
		if (panel.buttons[i].lit)
		{
			out << "[" << panel.buttons[i].label << "]";
		}
	 }
	return out;
}

bool Panel::isLit(string label) const
{
    for(int i = 0; i < buttons.size(); i++)
    {
       if(this->buttons[i].label == label)
       {
       	 return buttons[i].lit;
       	 break;
       }
    }
    return false;
}

bool Panel::areAnyLit() const
{
	for(int i = 0; i < buttons.size(); i++)
	{
		if(buttons[i].lit)
		{
			return true;
		}
    }
    return false;
}
