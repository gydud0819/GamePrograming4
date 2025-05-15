#include <iostream>
#include<string>
using namespace std;
class PoketMon
{
private:
	int _number;
	string _name;
public:
	/*PoketMon() = default;
	~PoketMon() = default;*/

	PoketMon(int number, string name)
		: _number(number), _name(name) { }
	
	int get_number() const
	{
		return _number;
	}
	string get_name() const
	{
		return _name;
	}
};