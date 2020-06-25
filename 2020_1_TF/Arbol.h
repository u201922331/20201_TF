#pragma once
#ifndef __ARBOL_H__
#define __ARBOL_H__

#include <functional>

template<typename T>
class Arbol {
	struct Nodo {
		Nodo(T elem) : elem(elem), der(nullptr), izq(nullptr) {}

		T elem;
		Nodo* der;
		Nodo* izq;
	};

	Nodo* root;
	int repeticiones;
public:
	Arbol() : root(nullptr) {}
	~Arbol() { Borrar(root); }

	bool Busqueda(T elem) { return Busqueda(root, elem); }

	void Borrar() { Borrar(root); }
	void Agregar(T elem) { Agregar(root, elem); }
	void Remover(T elem) {
		// 1. Buscar elemento a eliminar
		Nodo* aux = root;
		Nodo* auxParent = nullptr;
		bool izquierdo;

		while (aux != nullptr) {
			if (elem == aux->elem)
				break;
			else if (elem < aux->elem) {
				auxParent = aux;
				izquierdo = true;
				aux = aux->izq;
			}
			else {
				auxParent = aux;
				izquierdo = false;
				aux = aux->der;
			}
		}
		// Si no se encontro el elemento a eliminar
		if (aux == nullptr) return;

		// 2. Eliminar en caso no exista hijo izquierdo
		if (aux->izq == nullptr) {
			if (auxParent == nullptr)
				root = aux->der;
			else if (izquierdo)
				auxParent->izq = aux->der;
			else
				auxParent->der = aux->der;
			delete aux;
			return;
		}

		// 3. En caso existiera el hijo izquierdo, buscamos dicho subárbol
		Nodo* aux2 = aux->izq;
		Nodo* aux2Parent = aux;
		izquierdo = true;

		while (aux2->der != nullptr) {
			aux2Parent = aux2;
			izquierdo = false;
			aux2 = aux2->der;
		}
		aux->elem = aux2->elem;
		if (izquierdo)
			aux2Parent->izq = aux2->izq;
		else
			aux2Parent->der = aux2->izq;
		delete aux2;
	}

	void Preorden(std::function<void(T)> proc) { Preorden(root, proc); }
	void Posorden(std::function<void(T)> proc) { Posorden(root, proc); }
	void Inorden(std::function<void(T)> proc) { Inorden(root, proc); }

	int Coincidencias(T elem) {
		repeticiones = 0;

		Coincidencias(root, elem);

		return repeticiones;
	}

private:
	void Balance() {
		Nodo* aux;
	}

	void Coincidencias(Nodo* nodo, T elem) {
		if (nodo != nullptr) {
			if (nodo->elem == elem) ++repeticiones;

			Coincidencias(nodo->izq, elem);
			Coincidencias(nodo->der, elem);
		}
	}

	bool Busqueda(Nodo* nodo, T elem) {
		if (nodo != nullptr) {
			if (elem == nodo->elem)
				return true;
			else if (elem < nodo->elem)
				return Busqueda(nodo->izq, elem);
			else if (elem > nodo->elem)
				return Busqueda(nodo->der, elem);
		}
		return false;
	}

	void Borrar(Nodo* nodo) {
		if (nodo != nullptr) {
			Borrar(nodo->izq);
			Borrar(nodo->der);

			delete nodo; nodo = nullptr;
		}
	}
	void Agregar(Nodo*& nodo, T elem) {
		if (nodo == nullptr)
			nodo = new Nodo(elem);
		else if (elem <= nodo->elem)
			Agregar(nodo->izq, elem);
		else if (elem > nodo->elem)
			Agregar(nodo->der, elem);
	}

	void Preorden(Nodo* nodo, std::function<void(T)> proc) {
		if (nodo != nullptr) {
			proc(nodo->elem);
			Preorden(nodo->izq, proc);
			Preorden(nodo->der, proc);
		}
	}
	void Posorden(Nodo* nodo, std::function<void(T)> proc) {
		if (nodo != nullptr) {
			Posorden(nodo->izq, proc);
			Posorden(nodo->der, proc);
			proc(nodo->elem);
		}
	}
	void Inorden(Nodo* nodo, std::function<void(T)> proc) {
		if (nodo != nullptr) {
			Inorden(nodo->izq, proc);
			proc(nodo->elem);
			Inorden(nodo->der, proc);
		}
	}

};

#endif