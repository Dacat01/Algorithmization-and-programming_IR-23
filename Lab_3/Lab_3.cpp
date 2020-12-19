

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <list>
#include <iterator>
#include <vector>
using namespace std;


class Tribes
{
public:
    list<int>* adj_list;    // Adjacency list

    int** edge_array;
    int rows_count, columns_count = 2, max_vertex;

    std::vector< int > vertexes_in_graphs;
    std::vector< int > visited_vertexes_in_graphs;
    std::vector< int > pairs;
    list<int> ::iterator it;

    void adj_list_init(int size)
    {
        adj_list = new list<int>[size];
    }


    int maximum_vertex_value(void)                 //Знаходження максимальної вершини графів
    {
        int max = 0;

        for (int i = 0; i < rows_count; i++)
        {
            if (max < edge_array[i][0])
                max = edge_array[i][0];

            if (max < edge_array[i][1])
                max = edge_array[i][1];
        }
        return max + 1;
    }


    void add_to_adjacency_list(int U, int V) {                                  //додати V у список U, і U у список V
        bool check1 = false, check2 = false;

        for (it = adj_list[U].begin(); it != adj_list[U].end(); ++it)           // Чи V вже є у списку U
            if (V == *it)
                check1 = true;

        for (it = adj_list[V].begin(); it != adj_list[V].end(); ++it)           // Чи U вже є у списку V
            if (U == *it)
                check2 = true;

        if (!check1)
            adj_list[U].push_back(V);
        if (!check2)
            adj_list[V].push_back(U);
    }


    int find_start_vertex(void)
    {
        int start_vertex = -1;
        bool stop = false;

        for (int i = 0; i < max_vertex; i++)
        {
            if (std::find(visited_vertexes_in_graphs.begin(), visited_vertexes_in_graphs.end(), i) != visited_vertexes_in_graphs.end())  //Чи елемент в списку суміжності вже був відвіданий (тобто пошук  вершини графа, який ще не був опрацьований)
                continue;
            for (it = adj_list[i].begin(); it != adj_list[i].end(); it++)                   //Чи існують елементи в комірці списку суміжності
            {
                if (*it >= 0)
                {
                    start_vertex = i;
                    stop = true;
                    break;
                }
            }
            if (stop) break;
        }
        return start_vertex;
    }


    int find_all_vertexes_for_graph(void)       //Пошук в ширину
    {
        int current_vertex,
            start_vertex = find_start_vertex();

        std::vector< int > visited;
        std::vector< int > vertex_to_visit_queue;

        if (start_vertex == -1)                 // -1  -  Всі графи знайдені
            return 1;


        vertex_to_visit_queue.push_back(start_vertex);

        while (vertex_to_visit_queue.size() != 0)
        {
            current_vertex = vertex_to_visit_queue[0];
            vertex_to_visit_queue.erase(vertex_to_visit_queue.begin());     //erase() to remove the first element.


            for (it = adj_list[current_vertex].begin(); it != adj_list[current_vertex].end(); it++)
            {
                if (!(std::find(visited.begin(), visited.end(), *it) != visited.end()))
                    vertex_to_visit_queue.push_back(*it);
            }
            visited.push_back(current_vertex);
            visited_vertexes_in_graphs.push_back(current_vertex);    //Вершини графа заносяться у глобальний вектор класу "відвіданих" вершин
        }

        vertexes_in_graphs.push_back(visited.size());                //Заноситься кількість вершин опрацьованого графа 

        find_all_vertexes_for_graph();                               //Рекурсивно знаходимо всі графи у списку суміжності 
    }

    void make_pairs(void) {                                          // Опрацьовує тільки перші 2 графи при утворенні пар


            for (int j = 0; j < vertexes_in_graphs[0]; j++)          // кількість вершин у графі 1
            {
                for (int k = 0; k < vertexes_in_graphs[1]; k++)      // кількість вершин у графі 2
                {
                    // попарно перевіряється кожна з вершин двох графів                                                                    
                    if (visited_vertexes_in_graphs[j] % 2 == 0 && visited_vertexes_in_graphs[vertexes_in_graphs[0] + k] % 2 != 0)
                    {
                        pairs.push_back(visited_vertexes_in_graphs[j]);
                        pairs.push_back(visited_vertexes_in_graphs[vertexes_in_graphs[0] + k]);
                    }
                    else if (visited_vertexes_in_graphs[j] % 2 != 0 && visited_vertexes_in_graphs[vertexes_in_graphs[0] + k] % 2 == 0)
                    {
                        pairs.push_back(visited_vertexes_in_graphs[j]);
                        pairs.push_back(visited_vertexes_in_graphs[vertexes_in_graphs[0] + k]);
                    }
                }
            }

        cout << endl << pairs.size() / 2 << " (Pairs -";
        for (int i = 0; i < pairs.size(); i = i + 2)
        {
            cout << " " << pairs[i] << "/" << pairs[i + 1];
            if (i + 2 == pairs.size())
                cout << ")" << endl;
        }

    }


    void tribe_main (string path) {

        read_file(path);

        max_vertex = maximum_vertex_value();
        adj_list_init(max_vertex);              // Ініціалізація adj_list_init

        for (int i = 0; i < rows_count; i++)    // Заповнення  adj_list
            add_to_adjacency_list(edge_array[i][0], edge_array[i][1]);


        find_all_vertexes_for_graph();          // BFS  
        make_pairs();                           // Складання пар 

        // Видалення масивів ребер 
        for (int i = 0; i < rows_count; ++i) {
            delete[] edge_array[i];
        }
        delete[] edge_array;


    }

    void read_file(string path)
    {

        int counter = 0, position = 0;
        std::string line;
        std::ifstream in(path);

        getline(in, line);
        rows_count = stoi(line);

        // Створення  масивів ребер
        edge_array = new int* [rows_count];
        for (int i = 0; i < rows_count; ++i)
            edge_array[i] = new int[columns_count];


        if (in.is_open())
        {
            while (getline(in, line))
            {
                std::string delimiter = " ";

                while ((position = line.find(delimiter)) != std::string::npos) 
                {
                    edge_array[counter][0] = stoi(line.substr(0, position));
                    line.erase(0, position + delimiter.length());
                }
                edge_array[counter][1] = stoi(line);
                counter++;
            }
            in.close();

        }
    }
};



int main()
{
    Tribes Tribe;

    string path = "Tribes.txt";

    Tribe.tribe_main(path);

}

