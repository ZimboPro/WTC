#ifndef		GAMEELEMENT_HPP
# define	GAMEELEMENT_HPP

class GameElement {
	public:
		GameElement();
		GameElement(int y, int x, int type);
		GameElement(GameElement const & src);
		~GameElement();
		GameElement & operator=(GameElement const & src);
		bool operator==(GameElement const & rhs);
		int getX();
		int getY();
		int getType();
		void setX( int x);
		void setY( int y);
		void setType(int type);
	private:
		int _type;
		int _y;
		int _x;
};

#endif
