#include<iostream>
#include<map>
#include<iostream>

using namespace std;

class AbstractCharacter
{
public:
	AbstractCharacter() {};
	virtual ~AbstractCharacter() {};
	virtual void Show() const = 0;
protected:
	char symbol;
	int  width;
	int  height;
	int  ascent;
	int  descent;
	int  pointSize;
};


class RealCharacter :	public AbstractCharacter
{
public:
	RealCharacter(char pSymbol, int pPointSize) {
		symbol = pSymbol;
		width = 100;
		height = 90;
		ascent = 40;
		descent = 0;
		pointSize = pPointSize;
	};

	virtual ~RealCharacter() {};
	void Show()const {
		std::cout << "\n" << "Symbol is:" << symbol << " Size:" << pointSize << std::endl;
	};
};


class RealCharacterFactory
{
public:
	RealCharacterFactory() {};
	RealCharacterFactory(int pPointSize) {
		pointSize = pPointSize;
	};
	virtual ~RealCharacterFactory() {
		for (map<char, const AbstractCharacter*>::const_iterator first = chars.begin(); first != chars.end(); first++)
			delete first->second;
	};

private:
	map< char, const AbstractCharacter* > chars;
	int pointSize;

public:
	const AbstractCharacter& GetChar(char key) {
		map<char, const AbstractCharacter*>::const_iterator result = chars.find(key);
		if (chars.end() == result)
		{
			const RealCharacter* newCharacter = new RealCharacter(key, pointSize);
			chars[key] = newCharacter;
			return *newCharacter;
		}
		return *result->second;
	};
};



int main()
{
	string document = "AFFCCDDZZZ";

	RealCharacterFactory charFactory(30);

	for (string::const_iterator first = document.begin(); first != document.end(); ++first) {
		const AbstractCharacter& characterValue = charFactory.GetChar(*first);
		characterValue.Show();
	}
	return 0;
}