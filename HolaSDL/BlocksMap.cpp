#include "Block.h"
#include "Vector2D.h"
#include"Texture.h"
#include "SDL.h"
#include "SDL_image.h"
#include "BlocksMap.h"
#include <iostream>
#include <fstream>

using namespace std;

int fila = 0, columna = 0;
void BlocksMap::LeerFichero(string filename) {
	ifstream lectura; uint color; // x e y(filas y columnas)
	lectura.open(filename);
	if (!lectura.is_open()) throw "No existe el fichero";

		lectura >> fila; // row
		lectura >> columna; // col
		numBloques = 0;
		blocks = new Block **[columna];

		for (uint t = 0; t < columna; t++)
		{
			blocks[t] = new Block*[fila];
		}
		//para colocarlo
		uint margen = 25; // margen a ambos lados 
		int cellW = (w - margen * 2) / columna, cellH = w / 12; int cellWAux = cellW; // tamaño fijo de las celdas, depende de la anchura del mapa
		for (uint i = 0; i < fila; i++) {
			for (uint j = 0; j < columna; j++) {

				Vector2D pos(margen + j * cellWAux, margen + i * cellH);
				//cellWAux += cellW;
				lectura >> color;
				blocks[j][i] = new Block(color, cellW, cellH, pos, textura, i, j);
				if (color != 0)
					numBloques++;
			}
			cellWAux = cellW;
		}
		lectura.close();
}
BlocksMap::~BlocksMap() {
	if (blocks != nullptr) {
		for (int r = 0; r < columna; r++) {
			for (int c = 0; c <fila; c++) {
				delete blocks[r][c];
			}
			delete[] blocks[r];
		}
		delete[] blocks;
	
		blocks = nullptr;
	}
	w = h = columna = fila = 0;
}
void BlocksMap::render() const {	
	for (int i = 0; i < fila; i++) {
		for (int j = 0; j < columna;j++) {
			if (blocks[j][i] != nullptr) {
				blocks[j][i]->render();
			}
		}
	}
}

/* Dados el rectángulo y vector de dirección de la pelota, devuelve un puntero al
   bloque con el que ésta colisiona (nullptr si no colisiona con nadie) y el
   vector normal perpendicular a la superficie de colisión. */
Block* BlocksMap::collides(const SDL_Rect& ballRect, const Vector2D& ballVel, Vector2D& collVector) {
	Vector2D p0 = { (double)ballRect.x,(double)ballRect.y }; // top-left
	Vector2D p1 = { (double)ballRect.x + (double)ballRect.w, (double)ballRect.y }; // top-right
	Vector2D p2 = { (double)ballRect.x,(double)ballRect.y + (double)ballRect.h }; // bottom-left
	Vector2D p3 = { (double)ballRect.x + (double)ballRect.w, (double)ballRect.y + (double)ballRect.h }; // bottom-right
	Block* b = nullptr;
	if (ballVel.getX() < 0 && ballVel.getY() < 0) {
		if ((b = blockAt(p0))) {
			if ((b->getY() + b->getH() - p0.getY()) <= (b->getX() + b->getW() - p0.getX()))
				collVector = { 0,1 }; // Borde inferior mas cerca de p0
			else
				collVector = { 1,0 }; // Borde dcho mas cerca de p0
		}
		else if ((b = blockAt(p1))) {
			collVector = { 0,1 };
		}
		else if ((b = blockAt(p2))) collVector = { 1,0 };
	}
	else if (ballVel.getX() >= 0 && ballVel.getY() < 0) {
		if ((b = blockAt(p1))) {
			if (((b->getY() + b->getH() - p1.getY()) <= (p1.getX() - b->getX())) || ballVel.getX() == 0)
				collVector = { 0,1 }; // Borde inferior mas cerca de p1
			else
				collVector = { -1,0 }; // Borde izqdo mas cerca de p1
		}
		else if ((b = blockAt(p0))) {
			collVector = { 0,1 };
		}
		else if ((b = blockAt(p3))) collVector = { -1,0 };
	}
	else if (ballVel.getX() > 0 && ballVel.getY() > 0) {
		if ((b = blockAt(p3))) {
			if (((p3.getY() - b->getY()) <= (p3.getX() - b->getX()))) // || ballVel.getX() == 0)
				collVector = { 0,-1 }; // Borde superior mas cerca de p3
			else
				collVector = { -1,0 }; // Borde dcho mas cerca de p3
		}
		else if ((b = blockAt(p2))) {
			collVector = { 0,-1 };
		}
		else if ((b = blockAt(p1))) collVector = { -1,0 };
	}
	else if (ballVel.getX() < 0 && ballVel.getY() > 0) {
		if ((b = blockAt(p2))) {
			if (((p2.getY() - b->getY()) <= (b->getX() + b->getW() - p2.getX()))) // || ballVel.getX() == 0)
				collVector = { 0,-1 }; // Borde superior mas cerca de p2
			else
				collVector = { 1,0 }; // Borde dcho mas cerca de p0
		}
		else if ((b = blockAt(p3))) {
			collVector = { 0,-1 };
		}
		else if ((b = blockAt(p0))) collVector = { 1,0 };
	}
	return b;
}
bool BlocksMap::detectCollision(const SDL_Rect destRect, Vector2D &collVector, const Vector2D &vel) {
	if (SDL_HasIntersection(&destRect, &getRect())) {
		Block* block = collides(destRect, vel, collVector);
		if (block != nullptr) {
			if (block->getColor() != 0) {
				ballHitBlock(block);
				puntuacion();
				return true;
			}
		}
	}

}

 /* Devuelve el puntero al bloque del mapa de bloques al que pertenece el punto p.
	En caso de no haber bloque en ese punto (incluido el caso de que p esté fuera
	del espacio del mapa) devuelve nullptr. */

Block* BlocksMap::blockAt(const Vector2D& p) {
	/*
	if (p.getX()>100 && p.getX()<100+mapaW && p.getY()>25 && p.getY()<25+mapaH){

		int i = 0;
		int j = 0;

		int blockH = mapaH / fila;
		int blockW = mapaW / columna;

		i = (p.getY()-40) / blockH;
		j = (p.getX()-100) / blockW;

		return blocks[j][i];
	}
	*/
	for (int i = 0; i < fila; i++) {
		for (int j = 0; j < columna; j++) {
			if (blocks[j][i] != nullptr) {
				if (p.getX() >= blocks[j][i]->getX() && p.getY() >= blocks[j][i]->getY() && p.getX() <= (blocks[j][i]->getX() + blocks[j][i]->getW()) && p.getY() <= (blocks[j][i]->getY() + blocks[j][i]->getH()))
					return blocks[j][i];
			}
		}
	}
	return nullptr;
}
void BlocksMap::ballHitBlock(Block * bloque) {

	int i = bloque->getRow();
	int j = bloque->getCol();
	if (blocks[j][i] != nullptr) {
		delete bloque;
		blocks[j][i] = nullptr;
		numBloques--;
		puntos++;
	}
}
void BlocksMap::puntuacion() {
	
	if (puntos != puntosAnt) {
		system("cls");
		cout<<"Puntuacion: " << puntos;
		puntosAnt = puntos;
	}

}
bool BlocksMap::pasoNivel() {
	bool finish = false;

	if (numBloques <= 0)
		finish = true;

	return finish;
}