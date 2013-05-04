#include "Controller.h"
#include <SFML\Graphics.hpp>
#include "fstreams.h"

int main()
{
	ifstream infd; // in file stream
	fstreams::OpenFile(infd, "board.txt"); // oepn board

	int num_of_levels = 0;
	infd >> num_of_levels; // get num of levels

	bool completed = true; // has the player completed the level?
	
		// --------------------- Create Splash ------------------------
	sf::RenderWindow splash;
	splash.create(sf::VideoMode(576, 730), "Aziz! Lights!", sf::Style::None);
	sf::Sprite BG;
	sf::Texture texture;
	if (texture.loadFromFile("Aziz.png"))
	{
		texture.setSmooth(true);
		BG.setPosition(0,0);
		BG.setTexture(texture);
		splash.draw(BG);
		splash.display();
	}
	sf::sleep(sf::seconds(AZIZ_TIME));
	// ------------------ Close Splash --------------------------
	splash.close();


	for ( int level = 0; level < num_of_levels && completed && !infd.eof(); level++)
	{
		Controller ctrl(infd);
		if (!ctrl.runLevel())
			break;
	}

	return EXIT_SUCCESS;
}