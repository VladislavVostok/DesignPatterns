#include<iostream>
#include<vector>

using namespace std;

class CollectionItem
{
public:
	CollectionItem() {}
	virtual ~CollectionItem() {}
private:
	int numberOfCopies;
public:
	virtual void Show() const = 0;
public:
	int GetNumberOfCopies()const
	{
		return numberOfCopies;
	}
	void SetNumberOfCopies(int value)
	{
		numberOfCopies = value;
	}
};


class Decorator : public CollectionItem
{
public:
	Decorator(CollectionItem* pItem)
	{
		item = pItem;
	}

	virtual ~Decorator() {};

protected:
	CollectionItem* item;

public:
	void Show()const
	{
		item->Show();
	}
};

class CD : public CollectionItem
{
public:
	CD(string pSinger, string pTitle, string pStyle, int pPlayTime, int pNumCopies)
	{
		singer = pSinger;
		title = pTitle;
		style = pStyle;
		playtime = pPlayTime;
		SetNumberOfCopies(pNumCopies);
	}

	virtual ~CD() {	}
private:
	string singer;
	string style;
	string title;
	int playtime;
public:
	void Show() const
	{
		cout << "\n====================\n";
		cout << "\nInformation about CD disk\n";
		cout << "Singer:" << singer << endl;
		cout << "Title of CD:" << title << endl;
		cout << "Style of CD:" << style << endl;
		cout << "Duration of CD:" << playtime << endl;
		cout << "Number of copies:" << GetNumberOfCopies();
		cout << "\n====================\n";
	}
};


class Book : public CollectionItem
{
public:
	Book(string pAuthor, string pTitle, string pStyle, int pNumCopies)
	{
		author = pAuthor;
		title = pTitle;
		style = pStyle;
		SetNumberOfCopies(pNumCopies);
	}
	virtual ~Book() {};
private:
	string author;
	string style;
	string title;
public:
	void Show() const
	{
		cout << "\n====================\n";
		cout << "\nInformation about book\n";
		cout << "Author:" << author << endl;
		cout << "Title:" << title << endl;
		cout << "Style:" << style << endl;
		cout << "Number of copies:" << GetNumberOfCopies();
		cout << "\n====================\n";
	}
};


class Borrowable : 	public Decorator
{
public:
	Borrowable(CollectionItem* item) :Decorator(item) {	}
	virtual ~Borrowable() {};
private:
	vector<string> users;
public:
	void Borrowable::BorrowItem(string name)
	{
		users.push_back(name);
		item->SetNumberOfCopies(item->GetNumberOfCopies() - 1);
	}

	void ReturnItem(string name)
	{
		auto result = std::find(users.begin(), users.end(), name);
		if (result != users.end()) {
			users.erase(result);
			item->SetNumberOfCopies(item->GetNumberOfCopies() + 1);
		}

	}

	void Show() const
	{
		for (auto ptr = users.begin(); ptr != users.end(); ptr++)
		{
			cout << "Member:" << (*ptr) << endl;
		}
	}
};







int main()
{
	Book* book = new Book("Carol Aimes", "25 steps to success", "horror", 10);
	book->Show();

	CD* cd = new CD("Lou Abrams", "Binary Sound", "New Func", 100, 20);
	cd->Show();
	
	cout << "Let's give some books and cd's" << endl;

	Borrowable* borrowIt = new Borrowable(book);

	borrowIt->BorrowItem("Boris Gusev");
	borrowIt->BorrowItem("Tamara Loseva");

	borrowIt->Show();
	cout << endl;
	borrowIt->ReturnItem("Tamara Loseva");
	borrowIt->BorrowItem("Igor Grachev");
	borrowIt->Show();

	delete book;
	delete cd;

	return 0;
}