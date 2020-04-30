#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED

	class Tile {
	public:
		int x;    // the x cordinate of the tile
		int y;	  // the y cordinate of the tile
		int size;
		int state; // |-1 = start point(red) | 0 = green | 1 = black | 2 = white |  
		int highlighted;

		Tile(int ax, int ay, int asize, int  astate, int ahighlighted);

		void setTileColor();
	};
	void drawTile(Tile* tile);

	
#endif