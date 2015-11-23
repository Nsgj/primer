#pragma once
#include <string>
class Screen
{
public:
	typedef std::string::size_type pos;
	Screen()=default;
	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht*wd, c){}

	char get() const{
		return contents[cursor];
	}
	inline char get(pos, pos) const;
	Screen &move(pos , pos );
	~Screen();
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
};

