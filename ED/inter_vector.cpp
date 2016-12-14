/*

Usando la clase SET de la STL, diseñar una función que determine la intersección
de dos conjuntos c1 y c2 (VECTORES)

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main(){
	std::vector<int> v1{2,3,4,5,7,11};
	std::vector<int> v1{2,3,4,5,7,11};
	std::sort(v1.begin(),v1.end());
	std::sort(v2.begin(),v2.end());
	
	std::vector<int> v_interseccion;
	//set<int> intersect;
	
	std::set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(), std::back_inserter(v_interseccion));
	//set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(), std::inserter(intersect,intersect.begin()));

	for(int n:v_interseccion)
		std::cout << n << '';
}