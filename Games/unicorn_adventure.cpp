#include <iostream>
using namespace std;

int main ()
{
	string userChoice;
	int switchChoice;
	char heart;
	char spirit;
	char masterSword;
	char strength;


	cout << "Greetings wanderer! You are walking through the woods when you spy a unicorn off in"
		<< " the distance. What would you like the do? Try to PET the unicorn, try to KILL the"
		<< " the unicorn, or keep WALKING?\n";
	cout << "Enter PET/KILL/WALKING: ";
	cin >> userChoice;

	if(userChoice == "PET")
	{
		switchChoice = 1;
	}
	else if(userChoice == "KILL")
	{
		switchChoice = 2;
	}
	else if(userChoice == "WALKING")
	{
		switchChoice = 3;
	}
	else
	{
		switchChoice = 4;
	}
	

	switch(switchChoice)
	{
		case 1:
			cout << "You have chosen to PET the unicorn.\n";
			cout << "Are you pure of heart? (y/n): ";
			cin >> heart;
			cout << "Are you pure of spirit? (y/n): ";
			cin >> spirit;
			if(((heart == 'y') || (heart == 'Y')) && ((spirit == 'y') || (spirit == 'Y')))
			{
				cout << "You have shown your worthiness. The unicorn accepts your touch and becomes"
					<< " a lifelong companion!\n";
				cout << "THE END\n";
			}
			else
			{
				cout << "How dare you try to touch a unicorn with your unclean hands! The unicorn "
					<< "rears and tramples you under her hooves. You lose!\n";
				cout << "THE END\n";
			}
			break;
		case 2:
			cout << "Do you have the Master Sword? (y/n): ";
			cin >> masterSword;
			cout << "Are you strong? (y/n): ";
			cin >> strength;

			if(((masterSword == 'y') || (masterSword == 'Y')) && 
				((strength == 'y') || (strength == 'Y')))
			{
				cout << "You possess the Master Sword and are strong enough to wield it!\n";
				cout << "You slay the unicorn with a single blow! You keep it's head and drink its blood."
					<< " Congratulations, you will live forever!\n";
				cout << "THE END\n";
			}
			else if(((masterSword == 'y') || (masterSword == 'Y')) && 
				((strength == 'n') || (strength == 'N'))) 
			{
				cout << "You are not strong enough to wield the Master Sword. The unicorn sees you "
					<< "coming and runs you through with its horn. You lose!\n";
				cout << "THE END\n";
			}
			else if(((masterSword == 'n') || (masterSword == 'N')) && 
				((strength == 'y') || (strength == 'Y')))
			{
				cout << "You have proven your strength, but unicorns can only be defeated with the "
					<< "Master Sword. You run away crying in defeat. You lose!\n";
				cout << "THE END\n";
			}
			else {
				cout << "What made you think you could kill a Unicorn with no sword or strength?"
					<< " Go back home and think about your actions.";
				cout << "THE END\n";
				}
			break;
		case 3:
			cout << "You know Unicorns can be dangerous business. You continue through the woods"
				<< " knowing you will live to see another day.\n";
			cout << "THE END\n";
			break;
		default:
			cout << "You cannot do that. You must choose to PET, KILL, or keep WALKING.\n";
	}

	return 0;

}	