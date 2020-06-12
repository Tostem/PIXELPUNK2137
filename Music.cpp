#include "Music.h"
#include <iostream>
using namespace std;
void Music::music()
{
	if (isItOn == false)
	{
		menu_rain.openFromFile("rain_sound.wav");
		menu_rain.play();
		menu_rain.setLoop(true);
		cout << isItOn;
	}

}

void Music::on(bool& on)
{
	isItOn = on;

}