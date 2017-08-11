#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H
#include <vector>

class GameOfLife
{
public: //Méthodes et opérateurs de la classe
 //Constructeur qui permet de construire un objet de la classe. Il peut y
//avoir différents constructeurs (comme nous verrons dans la suite)
//Il doit porter le même nom que la classe !
 GameOfLife(int numLines, int numCols);

 void initialisation(); //Initialisation du jeu
 void play(); //Mise à jour du statut des cellules lors d’une itération
 int nbAlivedNeighbours(int i, int j); //Nombre de voisins vivants pour (i,j)
 void saveSolution(int it); //Écrit un fichier solution au format Paraview

 private: //Les attributs de la classe
 int _numLines; //Nombre de lignes de la grille
 int _numCols; //Nombre de colonnes de la grille
 //La grille qui contient le statut des cellules 1 si cellule vivante,
 //0 si elle est morte. Elle est définie comme un vecteur de vecteur de int
 std::vector<std::vector<int> > _grid;

};

#endif // GAMEOFLIFE_H
