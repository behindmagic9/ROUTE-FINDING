#include "execute.h"

// Define the function to execute the code
void executeGraphOperations(Graph& g) {
    // Add vertices and edges to the graph
    Vertex vertex1(1, "a");
    g.insert(vertex1);

    Vertex vertex2(2, "b");
    g.insert(vertex2);

    Vertex vertex3(3, "c");
    g.insert(vertex3);

    Vertex vertex4(4, "d");
    g.insert(vertex4);

    Vertex vertex5(5, "e");
    g.insert(vertex5);

    Vertex vertex6(6, "f");
    g.insert(vertex6);

    Vertex vertex7(7, "g");
    g.insert(vertex7);

    Vertex vertex8(8, "h");
    g.insert(vertex8);

    Vertex vertex9(9, "i");
    g.insert(vertex9);

    Vertex vertex10(10, "j");
    g.insert(vertex10);

    Vertex vertex11(11, "k");
    g.insert(vertex11);

    Vertex vertex12(12, "l");
    g.insert(vertex12);

    Vertex vertex13(13, "m");
    g.insert(vertex13);

    Vertex vertex14(14, "n");
    g.insert(vertex14);

    Vertex vertex15(15, "o");
    g.insert(vertex15);

    Vertex vertex16(16, "p");
    g.insert(vertex16);

    Vertex vertex17(17, "q");
    g.insert(vertex17);

    Vertex vertex18(18, "r");
    g.insert(vertex18);

    Vertex vertex19(19, "s");
    g.insert(vertex19);

    Vertex vertex20(20, "t");
    g.insert(vertex20);

    Vertex vertex21(21, "u");
    g.insert(vertex21);

    Vertex vertex22(22, "v");
    g.insert(vertex22);

    Vertex vertex23(23, "w");
    g.insert(vertex23);

    Vertex vertex24(24,"x");
    g.insert(vertex24);

    g.addEdge(4, 3, 3, "PINK");
    g.addEdge(3, 4, 3, "PINK");

    g.addEdge(3, 2, 4, "PINK");
    g.addEdge(2, 3, 4, "PINK");

    g.addEdge(2, 1, 3, "PINK");
    g.addEdge(1, 2, 3, "PINK");

    g.addEdge(1, 5, 2, "PINK");
    g.addEdge(5, 1, 2, "PINK");

    g.addEdge(5, 6, 1, "PINK");
    g.addEdge(6, 5, 1, "PINK");

    g.addEdge(6, 7, 3, "PINK");
    g.addEdge(7, 6, 3, "PINK");

    g.addEdge(7, 8, 4, "PINK");
    g.addEdge(8, 7, 4, "PINK");

    g.addEdge(14, 15, 4, "RED");
    g.addEdge(15, 14, 4, "RED");

    g.addEdge(16, 15, 3, "RED");
    g.addEdge(15, 16, 3, "RED");

    g.addEdge(17, 16, 3, "RED");
    g.addEdge(16, 17, 3, "RED");

    g.addEdge(18, 17, 2, "RED");
    g.addEdge(17, 18, 2, "RED");

    g.addEdge(18, 19, 5, "RED");
    g.addEdge(19, 18, 5, "RED");

    g.addEdge(20, 18, 1, "BLUE");
    g.addEdge(18, 20, 1, "BLUE");

    g.addEdge(18, 24, 1, "BLUE");
    g.addEdge(24, 18, 1, "BLUE");

    g.addEdge(24, 9, 1, "BLUE");
    g.addEdge(9, 24, 1, "BLUE");

    g.addEdge(9, 8, 4, "BLUE");
    g.addEdge(8, 9, 4, "BLUE");

    g.addEdge(23, 22, 4, "VOILET");
    g.addEdge(22, 23, 4, "VOILET");

    g.addEdge(22, 21, 3, "VOILET");
    g.addEdge(21, 22, 3, "VOILET");

    g.addEdge(21, 16, 2, "VOILET");
    g.addEdge(16, 21, 2, "VOILET");

    g.addEdge(16, 1, 1, "VOILET");
    g.addEdge(1, 16, 1, "VOILET");

    g.addEdge(1, 10, 2, "VOILET");
    g.addEdge(10, 1, 2, "VOILET");

    g.addEdge(10, 11, 2, "VOILET");
    g.addEdge(11, 10, 2, "VOILET");

    g.addEdge(11, 12, 4, "VOILET");
    g.addEdge(12, 11, 4, "VOILET");

    g.addEdge(12, 13, 5, "VOILET");
    g.addEdge(13, 12, 5, "VOILET");
}

