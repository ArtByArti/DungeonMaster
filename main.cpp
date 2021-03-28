#include <SFML/Graphics.hpp>
//#include <Map.h>
using namespace sf;



/////////////////////////////////КЛАСС ИГРОКА///////////////////////////////
class Player{
public:
	float x, y, w, h, dx, dy, speed = 0; // Координаты игрока x и y, высота, ширина, ускорние по x и по y, сама скорость
	int dir=0; // направление перса
	String File; //Файл с расширением
	Image image; //сфмл изображение
	Texture texture; //сфмл текстура
	Sprite sprite; //сфмл спрайт
	Player(String F, int Y, int X, float W, float H){ // Конструктор параметров для класса Player
		File = F;
		w=W; h=H;
		image.loadFromFile("image/"+File); 
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		x=300; y=300;
		sprite.setTextureRect(IntRect(0,0,41,72));
	}
	void update(float time) 
	{
		switch (dir)
		{
			case 0: dx=speed; dy=0; break; // right
			case 1: dx=-speed; dy=0; break; // left
			case 2: dx=0; dy=speed; break; // up
			case 3: dx=0; dy=-speed; break;// down
		}
		x+= dx*time;
		y+= dy*time;
		
		speed =0;
		sprite.setPosition(x, y);
	}
	
};











int main() {
	RenderWindow window(VideoMode(640, 480), "Testoviy ecran");
	//Image map_image;
	//map_image.loadFromFile("image/map.png");
	//Texture map;
	//map.LoadFromImage(map_image);
	//Sprite s_map;
	//s_map.setTexture(map);
	
	Player p("Sprite.png", 300, 300, 41.0, 72.0);
	
	float CurrentFrame=0;
	Clock clock;
 
 while (window.isOpen())
 {
 	float time=clock.getElapsedTime().asMicroseconds();
 	clock.restart();
 	time=time/800;
 	Event event;
 	while (window.pollEvent(event))
	 {
 		if (event.type == Event::Closed)
 			window.close();
	 }
	 
	if (Keyboard::isKeyPressed(Keyboard::Left)){
	CurrentFrame += 0.005*time;
	p.dir = 1; p.speed =0.1;
	if (CurrentFrame > 3) CurrentFrame -= 3;
	p.sprite.setTextureRect(IntRect(57*int(CurrentFrame),226,50,75));
	}
	
	if (Keyboard::isKeyPressed(Keyboard::Right)){
	CurrentFrame += 0.005*time;
	p.dir = 0; p.speed =0.1;
	if (CurrentFrame > 3) CurrentFrame -= 3;
	p.sprite.setTextureRect(IntRect(49*int(CurrentFrame),0,50,70));
	}
	
	if (Keyboard::isKeyPressed(Keyboard::Up)){
	CurrentFrame += 0.005*time;
	p.dir = 3; p.speed =0.1;
	if (CurrentFrame > 3) CurrentFrame -= 3;
	p.sprite.setTextureRect(IntRect(55*int(CurrentFrame),147,56,72));
	}
	
	if (Keyboard::isKeyPressed(Keyboard::Down)){
	CurrentFrame += 0.005*time;
	p.dir = 2; p.speed =0.1;
	if (CurrentFrame > 3) CurrentFrame -= 3;
	p.sprite.setTextureRect(IntRect(55*int(CurrentFrame),73,55,71));
	}
	p.update(time);
	 
	 
	 
	 window.clear();
	 //for (int i=0; i<HEIGHT_MAP; i++)
	 //for (int j=0; j<WIDTH_MAP; j++)
	 //{
	 	//if (TileMap[i][j] == " ") s_map.setTextureRect(IntRect(0, 0, 0, 0));
	 	//if (TileMap[i][j] == "s") s_map.setTextureRect(IntRect(0, 0, 0, 0));
	 	//if (TileMap[i][j] == "0") s_map.setTextureRect(IntRect(0, 0, 0, 0));
	 	
	 	//s_map.setPosition(j*32, i*32);
	 	
	 	//window.draw(s_map);
	 //}
	 
	 
	 window.draw(p.sprite);
	 window.display();
 }
 return 0;
}
