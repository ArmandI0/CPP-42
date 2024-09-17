#ifndef WrongAnimal_hpp
#define WrongAnimal_hpp
#include <iostream>

class WrongAnimal
{
	protected:
		std::string _type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &Copy);
		virtual ~WrongAnimal();

		WrongAnimal& operator=(const WrongAnimal &ToCopy);

		std::string gettype() const;
		void makeSound() const;
};

#endif