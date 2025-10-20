// ===== ALGORITMOS Y ESTRUCTURAS DE DATOS AVANZADAS (251-350) =====

// 251. Merge Sort
#include <iostream>
using namespace std;
void merge(int arr[], int izq, int medio, int der) {
    int n1 = medio - izq + 1;
    int n2 = der - medio;
    int* L = new int[n1];
    int* R = new int[n2];
    
    for (int i = 0; i < n1; i++) L[i] = arr[izq + i];
    for (int j = 0; j < n2; j++) R[j] = arr[medio + 1 + j];
    
    int i = 0, j = 0, k = izq;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    
    delete[] L;
    delete[] R;
}
void mergeSort(int arr[], int izq, int der) {
    if (izq < der) {
        int medio = izq + (der - izq) / 2;
        mergeSort(arr, izq, medio);
        mergeSort(arr, medio + 1, der);
        merge(arr, izq, medio, der);
    }
}
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);
    cout << "Array ordenado: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}

// 252. Quick Sort
#include <iostream>
using namespace std;
int partition(int arr[], int bajo, int alto) {
    int pivot = arr[alto];
    int i = bajo - 1;
    for (int j = bajo; j <= alto - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[alto]);
    return i + 1;
}
void quickSort(int arr[], int bajo, int alto) {
    if (bajo < alto) {
        int pi = partition(arr, bajo, alto);
        quickSort(arr, bajo, pi - 1);
        quickSort(arr, pi + 1, alto);
    }
}
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Array ordenado: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}

// 253. Heap Sort
#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i) {
    int mayor = i;
    int izq = 2 * i + 1;
    int der = 2 * i + 2;
    
    if (izq < n && arr[izq] > arr[mayor]) mayor = izq;
    if (der < n && arr[der] > arr[mayor]) mayor = der;
    
    if (mayor != i) {
        swap(arr[i], arr[mayor]);
        heapify(arr, n, mayor);
    }
}
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, n);
    cout << "Array ordenado: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}

// 254. Árbol binario de búsqueda
#include <iostream>
using namespace std;
struct Nodo {
    int dato;
    Nodo* izq;
    Nodo* der;
    Nodo(int val) : dato(val), izq(nullptr), der(nullptr) {}
};
class BST {
public:
    Nodo* raiz;
    BST() : raiz(nullptr) {}
    
    Nodo* insertar(Nodo* nodo, int valor) {
        if (nodo == nullptr) return new Nodo(valor);
        if (valor < nodo->dato) nodo->izq = insertar(nodo->izq, valor);
        else if (valor > nodo->dato) nodo->der = insertar(nodo->der, valor);
        return nodo;
    }
    
    bool buscar(Nodo* nodo, int valor) {
        if (nodo == nullptr) return false;
        if (nodo->dato == valor) return true;
        if (valor < nodo->dato) return buscar(nodo->izq, valor);
        return buscar(nodo->der, valor);
    }
    
    void inorden(Nodo* nodo) {
        if (nodo != nullptr) {
            inorden(nodo->izq);
            cout << nodo->dato << " ";
            inorden(nodo->der);
        }
    }
};
int main() {
    BST arbol;
    arbol.raiz = arbol.insertar(arbol.raiz, 50);
    arbol.insertar(arbol.raiz, 30);
    arbol.insertar(arbol.raiz, 20);
    arbol.insertar(arbol.raiz, 40);
    arbol.insertar(arbol.raiz, 70);
    arbol.insertar(arbol.raiz, 60);
    arbol.insertar(arbol.raiz, 80);
    
    cout << "Recorrido inorden: ";
    arbol.inorden(arbol.raiz);
    cout << endl;
    
    cout << "Buscar 40: " << (arbol.buscar(arbol.raiz, 40) ? "Encontrado" : "No encontrado") << endl;
    return 0;
}

// 255. Árbol AVL
#include <iostream>
#include <algorithm>
using namespace std;
struct NodoAVL {
    int dato;
    NodoAVL* izq;
    NodoAVL* der;
    int altura;
    NodoAVL(int val) : dato(val), izq(nullptr), der(nullptr), altura(1) {}
};
class AVL {
public:
    int getAltura(NodoAVL* nodo) {
        return nodo ? nodo->altura : 0;
    }
    
    int getBalance(NodoAVL* nodo) {
        return nodo ? getAltura(nodo->izq) - getAltura(nodo->der) : 0;
    }
    
    NodoAVL* rotarDerecha(NodoAVL* y) {
        NodoAVL* x = y->izq;
        NodoAVL* T2 = x->der;
        x->der = y;
        y->izq = T2;
        y->altura = max(getAltura(y->izq), getAltura(y->der)) + 1;
        x->altura = max(getAltura(x->izq), getAltura(x->der)) + 1;
        return x;
    }
    
    NodoAVL* rotarIzquierda(NodoAVL* x) {
        NodoAVL* y = x->der;
        NodoAVL* T2 = y->izq;
        y->izq = x;
        x->der = T2;
        x->altura = max(getAltura(x->izq), getAltura(x->der)) + 1;
        y->altura = max(getAltura(y->izq), getAltura(y->der)) + 1;
        return y;
    }
    
    NodoAVL* insertar(NodoAVL* nodo, int valor) {
        if (nodo == nullptr) return new NodoAVL(valor);
        
        if (valor < nodo->dato) nodo->izq = insertar(nodo->izq, valor);
        else if (valor > nodo->dato) nodo->der = insertar(nodo->der, valor);
        else return nodo;
        
        nodo->altura = 1 + max(getAltura(nodo->izq), getAltura(nodo->der));
        
        int balance = getBalance(nodo);
        
        // Rotaciones
        if (balance > 1 && valor < nodo->izq->dato) return rotarDerecha(nodo);
        if (balance < -1 && valor > nodo->der->dato) return rotarIzquierda(nodo);
        if (balance > 1 && valor > nodo->izq->dato) {
            nodo->izq = rotarIzquierda(nodo->izq);
            return rotarDerecha(nodo);
        }
        if (balance < -1 && valor < nodo->der->dato) {
            nodo->der = rotarDerecha(nodo->der);
            return rotarIzquierda(nodo);
        }
        
        return nodo;
    }
    
    void preorden(NodoAVL* raiz) {
        if (raiz != nullptr) {
            cout << raiz->dato << " ";
            preorden(raiz->izq);
            preorden(raiz->der);
        }
    }
};
int main() {
    AVL arbol;
    NodoAVL* raiz = nullptr;
    
    raiz = arbol.insertar(raiz, 10);
    raiz = arbol.insertar(raiz, 20);
    raiz = arbol.insertar(raiz, 30);
    raiz = arbol.insertar(raiz, 40);
    raiz = arbol.insertar(raiz, 50);
    raiz = arbol.insertar(raiz, 25);
    
    cout << "Recorrido preorden del árbol AVL: ";
    arbol.preorden(raiz);
    cout << endl;
    
    return 0;
}

// 256. Grafo con lista de adyacencia
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Grafo {
private:
    int V;
    vector<vector<int>> adj;
public:
    Grafo(int vertices) : V(vertices) {
        adj.resize(V);
    }
    
    void agregarArista(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v); // Para grafo no dirigido
    }
    
    void BFS(int inicio) {
        vector<bool> visitado(V, false);
        queue<int> cola;
        
        visitado[inicio] = true;
        cola.push(inicio);
        
        cout << "BFS desde vértice " << inicio << ": ";
        while (!cola.empty()) {
            int v = cola.front();
            cola.pop();
            cout << v << " ";
            
            for (int i : adj[v]) {
                if (!visitado[i]) {
                    visitado[i] = true;
                    cola.push(i);
                }
            }
        }
        cout << endl;
    }
    
    void DFSUtil(int v, vector<bool>& visitado) {
        visitado[v] = true;
        cout << v << " ";
        
        for (int i : adj[v]) {
            if (!visitado[i]) {
                DFSUtil(i, visitado);
            }
        }
    }
    
    void DFS(int inicio) {
        vector<bool> visitado(V, false);
        cout << "DFS desde vértice " << inicio << ": ";
        DFSUtil(inicio, visitado);
        cout << endl;
    }
};
int main() {
    Grafo g(4);
    g.agregarArista(0, 1);
    g.agregarArista(0, 2);
    g.agregarArista(1, 2);
    g.agregarArista(2, 0);
    g.agregarArista(2, 3);
    g.agregarArista(3, 3);
    
    g.BFS(2);
    g.DFS(2);
    
    return 0;
}

// 257. Algoritmo de Dijkstra
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
typedef pair<int, int> pii;
class GrafoPeso {
private:
    int V;
    vector<vector<pii>> adj;
public:
    GrafoPeso(int vertices) : V(vertices) {
        adj.resize(V);
    }
    
    void agregarArista(int u, int v, int peso) {
        adj[u].push_back({v, peso});
        adj[v].push_back({u, peso});
    }
    
    void dijkstra(int origen) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> dist(V, INT_MAX);
        
        pq.push({0, origen});
        dist[origen] = 0;
        
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            
            for (auto& vecino : adj[u]) {
                int v = vecino.first;
                int peso = vecino.second;
                
                if (dist[u] + peso < dist[v]) {
                    dist[v] = dist[u] + peso;
                    pq.push({dist[v], v});
                }
            }
        }
        
        cout << "Distancias mínimas desde " << origen << ":" << endl;
        for (int i = 0; i < V; i++) {
            cout << "Vértice " << i << ": " << dist[i] << endl;
        }
    }
};
int main() {
    GrafoPeso g(9);
    g.agregarArista(0, 1, 4);
    g.agregarArista(0, 7, 8);
    g.agregarArista(1, 2, 8);
    g.agregarArista(1, 7, 11);
    g.agregarArista(2, 3, 7);
    g.agregarArista(2, 8, 2);
    g.agregarArista(2, 5, 4);
    g.agregarArista(3, 4, 9);
    g.agregarArista(3, 5, 14);
    g.agregarArista(4, 5, 10);
    g.agregarArista(5, 6, 2);
    g.agregarArista(6, 7, 1);
    g.agregarArista(6, 8, 6);
    g.agregarArista(7, 8, 7);
    
    g.dijkstra(0);
    return 0;
}

// 258. Tabla Hash con encadenamiento
#include <iostream>
#include <vector>
#include <list>
using namespace std;
class TablaHash {
private:
    int tamano;
    vector<list<pair<int, string>>> tabla;
    
    int hash(int clave) {
        return clave % tamano;
    }
    
public:
    TablaHash(int tam) : tamano(tam) {
        tabla.resize(tamano);
    }
    
    void insertar(int clave, string valor) {
        int indice = hash(clave);
        for (auto& par : tabla[indice]) {
            if (par.first == clave) {
                par.second = valor;
                return;
            }
        }
        tabla[indice].push_back({clave, valor});
    }
    
    string buscar(int clave) {
        int indice = hash(clave);
        for (auto& par : tabla[indice]) {
            if (par.first == clave) {
                return par.second;
            }
        }
        return "No encontrado";
    }
    
    void eliminar(int clave) {
        int indice = hash(clave);
        tabla[indice].remove_if([clave](const pair<int, string>& par) {
            return par.first == clave;
        });
    }
    
    void mostrar() {
        for (int i = 0; i < tamano; i++) {
            cout << "[" << i << "]: ";
            for (auto& par : tabla[i]) {
                cout << "(" << par.first << ", " << par.second << ") ";
            }
            cout << endl;
        }
    }
};
int main() {
    TablaHash th(7);
    
    th.insertar(10, "Diez");
    th.insertar(22, "Veintidos");
    th.insertar(31, "Treinta y uno");
    th.insertar(4, "Cuatro");
    th.insertar(15, "Quince");
    
    cout << "Tabla Hash:" << endl;
    th.mostrar();
    
    cout << "\nBuscar 22: " << th.buscar(22) << endl;
    cout << "Buscar 99: " << th.buscar(99) << endl;
    
    return 0;
}

// 259. Trie (Prefix Tree)
#include <iostream>
#include <unordered_map>
using namespace std;
class TrieNode {
public:
    unordered_map<char, TrieNode*> hijos;
    bool esFinal;
    
    TrieNode() : esFinal(false) {}
};
class Trie {
private:
    TrieNode* raiz;
    
public:
    Trie() {
        raiz = new TrieNode();
    }
    
    void insertar(string palabra) {
        TrieNode* actual = raiz;
        for (char c : palabra) {
            if (actual->hijos.find(c) == actual->hijos.end()) {
                actual->hijos[c] = new TrieNode();
            }
            actual = actual->hijos[c];
        }
        actual->esFinal = true;
    }
    
    bool buscar(string palabra) {
        TrieNode* actual = raiz;
        for (char c : palabra) {
            if (actual->hijos.find(c) == actual->hijos.end()) {
                return false;
            }
            actual = actual->hijos[c];
        }
        return actual->esFinal;
    }
    
    bool empiezaCon(string prefijo) {
        TrieNode* actual = raiz;
        for (char c : prefijo) {
            if (actual->hijos.find(c) == actual->hijos.end()) {
                return false;
            }
            actual = actual->hijos[c];
        }
        return true;
    }
};
int main() {
    Trie trie;
    
    trie.insertar("gato");
    trie.insertar("gatos");
    trie.insertar("perro");
    trie.insertar("perros");
    
    cout << "Buscar 'gato': " << (trie.buscar("gato") ? "Sí" : "No") << endl;
    cout << "Buscar 'gat': " << (trie.buscar("gat") ? "Sí" : "No") << endl;
    cout << "Empieza con 'gat': " << (trie.empiezaCon("gat") ? "Sí" : "No") << endl;
    cout << "Empieza con 'rat': " << (trie.empiezaCon("rat") ? "Sí" : "No") << endl;
    
    return 0;
}

// 260. Union-Find (Disjoint Set)
#include <iostream>
#include <vector>
using namespace std;
class UnionFind {
private:
    vector<int> padre;
    vector<int> rango;
    
public:
    UnionFind(int n) {
        padre.resize(n);
        rango.resize(n, 0);
        for (int i = 0; i < n; i++) {
            padre[i] = i;
        }
    }
    
    int encontrar(int x) {
        if (padre[x] != x) {
            padre[x] = encontrar(padre[x]); // Compresión de ruta
        }
        return padre[x];
    }
    
    void unir(int x, int y) {
        int raizX = encontrar(x);
        int raizY = encontrar(y);
        
        if (raizX != raizY) {
            if (rango[raizX] < rango[raizY]) {
                padre[raizX] = raizY;
            } else if (rango[raizX] > rango[raizY]) {
                padre[raizY] = raizX;
            } else {
                padre[raizY] = raizX;
                rango[raizX]++;
            }
        }
    }
    
    bool conectados(int x, int y) {
        return encontrar(x) == encontrar(y);
    }
};
int main() {
    UnionFind uf(5);
    
    uf.unir(0, 1);
    uf.unir(2, 3);
    uf.unir(1, 2);
    
    cout << "0 y 3 conectados: " << (uf.conectados(0, 3) ? "Sí" : "No") << endl;
    cout << "0 y 4 conectados: " << (uf.conectados(0, 4) ? "Sí" : "No") << endl;
    
    return 0;
}

// 261. Segment Tree
#include <iostream>
#include <vector>
using namespace std;
class SegmentTree {
private:
    vector<int> tree;
    int n;
    
    void construir(vector<int>& arr, int nodo, int inicio, int fin) {
        if (inicio == fin) {
            tree[nodo] = arr[inicio];
        } else {
            int medio = (inicio + fin) / 2;
            construir(arr, 2*nodo, inicio, medio);
            construir(arr, 2*nodo+1, medio+1, fin);
            tree[nodo] = tree[2*nodo] + tree[2*nodo+1];
        }
    }
    
    void actualizarUtil(int nodo, int inicio, int fin, int idx, int valor) {
        if (inicio == fin) {
            tree[nodo] = valor;
        } else {
            int medio = (inicio + fin) / 2;
            if (idx <= medio) {
                actualizarUtil(2*nodo, inicio, medio, idx, valor);
            } else {
                actualizarUtil(2*nodo+1, medio+1, fin, idx, valor);
            }
            tree[nodo] = tree[2*nodo] + tree[2*nodo+1];
        }
    }
    
    int consultarUtil(int nodo, int inicio, int fin, int l, int r) {
        if (r < inicio || fin < l) return 0;
        if (l <= inicio && fin <= r) return tree[nodo];
        
        int medio = (inicio + fin) / 2;
        int sumaIzq = consultarUtil(2*nodo, inicio, medio, l, r);
        int sumaDer = consultarUtil(2*nodo+1, medio+1, fin, l, r);
        return sumaIzq + sumaDer;
    }
    
public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        construir(arr, 1, 0, n-1);
    }
    
    void actualizar(int idx, int valor) {
        actualizarUtil(1, 0, n-1, idx, valor);
    }
    
    int consultar(int l, int r) {
        return consultarUtil(1, 0, n-1, l, r);
    }
};
int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree st(arr);
    
    cout << "Suma del rango [1, 3]: " << st.consultar(1, 3) << endl;
    
    st.actualizar(1, 10);
    cout << "Suma del rango [1, 3] después de actualizar: " << st.consultar(1, 3) << endl;
    
    return 0;
}

// 262. KMP String Matching
#include <iostream>
#include <vector>
using namespace std;
vector<int> computeLPS(string patron) {
    int m = patron.length();
    vector<int> lps(m, 0);
    int len = 0;
    int i = 1;
    
    while (i < m) {
        if (patron[i] == patron[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
void KMPSearch(string texto, string patron) {
    int n = texto.length();
    int m = patron.length();
    
    vector<int> lps = computeLPS(patron);
    
    int i = 0; // índice para texto
    int j = 0; // índice para patrón
    
    while (i < n) {
        if (patron[j] == texto[i]) {
            j++;
            i++;
        }
        
        if (j == m) {
            cout << "Patrón encontrado en índice " << i - j << endl;
            j = lps[j - 1];
        } else if (i < n && patron[j] != texto[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}
int main() {
    string texto = "ABABDABACDABABCABCABCABCABC";
    string patron = "ABABCABCABCABC";
    
    KMPSearch(texto, patron);
    
    return 0;
}

// 263. Longest Common Subsequence (LCS)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int LCS(string X, string Y) {
    int m = X.length();
    int n = Y.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i-1] == Y[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}
string printLCS(string X, string Y) {
    int m = X.length();
    int n = Y.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i-1] == Y[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    string lcs = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i-1] == Y[j-1]) {
            lcs = X[i-1] + lcs;
            i--;
            j--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    return lcs;
}
int main() {
    string X = "AGGTAB";
    string Y = "GXTXAYB";
    
    cout << "Longitud del LCS: " << LCS(X, Y) << endl;
    cout << "LCS: " << printLCS(X, Y) << endl;
    
    return 0;
}

// 264. Edit Distance (Levenshtein)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int editDistance(string str1, string str2) {
    int m = str1.length();
    int n = str2.length();
    
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    
    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min({dp[i][j-1],    // Insertar
                                   dp[i-1][j],    // Eliminar
                                   dp[i-1][j-1]}); // Reemplazar
            }
        }
    }
    return dp[m][n];
}
int main() {
    string str1 = "sunday";
    string str2 = "saturday";
    
    cout << "Distancia de edición: " << editDistance(str1, str2) << endl;
    
    return 0;
}

// 265. 0/1 Knapsack Problem
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int knapsack(int W, vector<int>& pesos, vector<int>& valores, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (pesos[i-1] <= w) {
                dp[i][w] = max(valores[i-1] + dp[i-1][w - pesos[i-1]], dp[i-1][w]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    return dp[n][W];
}
int main() {
    vector<int> valores = {60, 100, 120};
    vector<int> pesos = {10, 20, 30};
    int W = 50;
    int n = valores.size();
    
    cout << "Valor máximo: " << knapsack(W, pesos, valores, n) << endl;
    
    return 0;
}

// 266. Coin Change Problem
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int coinChange(vector<int>& monedas, int cantidad) {
    vector<int> dp(cantidad + 1, cantidad + 1);
    dp[0] = 0;
    
    for (int i = 1; i <= cantidad; i++) {
        for (int moneda : monedas) {
            if (moneda <= i) {
                dp[i] = min(dp[i], dp[i - moneda] + 1);
            }
        }
    }
    
    return dp[cantidad] > cantidad ? -1 : dp[cantidad];
}
int main() {
    vector<int> monedas = {1, 3, 4};
    int cantidad = 6;
    
    int resultado = coinChange(monedas, cantidad);
    if (resultado != -1) {
        cout << "Mínimo número de monedas: " << resultado << endl;
    } else {
        cout << "No es posible formar la cantidad" << endl;
    }
    
    return 0;
}

// 267. Fibonacci con programación dinámica
#include <iostream>
#include <vector>
using namespace std;
long long fibonacciDP(int n) {
    if (n <= 1) return n;
    
    vector<long long> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    return dp[n];
}
// Versión optimizada en espacio
long long fibonacciOptimizado(int n) {
    if (n <= 1) return n;
    
    long long prev2 = 0;
    long long prev1 = 1;
    long long current;
    
    for (int i = 2; i <= n; i++) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    
    return current;
}
int main() {
    int n = 10;
    
    cout << "Fibonacci(" << n << ") con DP: " << fibonacciDP(n) << endl;
    cout << "Fibonacci(" << n << ") optimizado: " << fibonacciOptimizado(n) << endl;
    
    return 0;
}

// 268. Longest Increasing Subsequence
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) return 0;
    
    int n = nums.size();
    vector<int> dp(n, 1);
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    return *max_element(dp.begin(), dp.end());
}
// Versión optimizada O(n log n)
int lengthOfLISOptimized(vector<int>& nums) {
    vector<int> tails;
    
    for (int num : nums) {
        auto it = lower_bound(tails.begin(), tails.end(), num);
        if (it == tails.end()) {
            tails.push_back(num);
        } else {
            *it = num;
        }
    }
    
    return tails.size();
}
int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    
    cout << "Longitud LIS (O(n^2)): " << lengthOfLIS(nums) << endl;
    cout << "Longitud LIS (O(n log n)): " << lengthOfLISOptimized(nums) << endl;
    
    return 0;
}

// 269. Maximum Subarray (Kadane's Algorithm)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maxSubArray(vector<int>& nums) {
    int maxSoFar = nums[0];
    int maxEndingHere = nums[0];
    
    for (int i = 1; i < nums.size(); i++) {
        maxEndingHere = max(nums[i], maxEndingHere + nums[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    
    return maxSoFar;
}
// Versión que devuelve los índices
pair<int, pair<int, int>> maxSubArrayWithIndices(vector<int>& nums) {
    int maxSoFar = nums[0];
    int maxEndingHere = nums[0];
    int start = 0, end = 0, s = 0;
    
    for (int i = 1; i < nums.size(); i++) {
        if (maxEndingHere < 0) {
            maxEndingHere = nums[i];
            s = i;
        } else {
            maxEndingHere += nums[i];
        }
        
        if (maxSoFar < maxEndingHere) {
            maxSoFar = maxEndingHere;
            start = s;
            end = i;
        }
    }
    
    return {maxSoFar, {start, end}};
}
int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    
    cout << "Suma máxima del subarray: " << maxSubArray(nums) << endl;
    
    auto resultado = maxSubArrayWithIndices(nums);
    cout << "Suma: " << resultado.first << ", Índices: [" 
         << resultado.second.first << ", " << resultado.second.second << "]" << endl;
    
    return 0;
}

// 270. Matrix Chain Multiplication
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int matrixChainOrder(vector<int>& p) {
    int n = p.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for (int l = 2; l <= n; l++) {
        for (int i = 0; i < n - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            
            for (int k = i; k < j; k++) {
                int q = dp[i][k] + dp[k+1][j] + p[i] * p[k+1] * p[j+1];
                if (q < dp[i][j]) {
                    dp[i][j] = q;
                }
            }
        }
    }
    
    return dp[0][n-1];
}
int main() {
    vector<int> p = {1, 2, 3, 4, 5}; // Matrices de tamaños 1x2, 2x3, 3x4, 4x5
    
    cout << "Mínimo número de multiplicaciones: " << matrixChainOrder(p) << endl;
    
    return 0;
}
