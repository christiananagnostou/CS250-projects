#pragma once
class Thing
{
private:
	double height;
public:
	void setHeight(double h){ height = h; }
	double getHeight(){ return height; }
	Thing(int h){ height = h; }
	Thing(){ height = 0; }
};

