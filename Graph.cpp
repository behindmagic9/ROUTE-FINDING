#include "Graph.h"

void Graph::insert(const Vertex &newvertex)
{
    if (!checkIfvertexExist(newvertex.get_id()))
    {
        vertices.push_back(newvertex);
        std::cout << "Added succesfully" << std::endl;
    }
    else
    {
        std::cout << "Already exist in the graph " << std::endl;
    }
}

void Graph::addEdge(const int &source, const int &destination, const int &distance, const std::string &color )
{
    auto sourceIt = std::find_if(vertices.begin(), vertices.end(), [&source](const Vertex &v)
                                 { return v.get_id() == source; });

    auto destIt = std::find_if(vertices.begin(), vertices.end(), [&destination](const Vertex &v)
                               { return v.get_id() == destination; });

    if (sourceIt != vertices.end() && destIt != vertices.end())
    {
        Vertex &sourceVertex = *sourceIt;
        if (!sourceVertex.checkIfEdgeexist(destination))
        {
            Edge e(destination, distance, color);
            sourceVertex.edges.push_back(e);
            edgeColors[{source, destination}] = color;       // Store edge color
            edgeDistances[{source, destination}] = distance; // Store edge distance
            std::cout << "Added successfully" << std::endl;
        }
        else
        {
            std::cout << "Edge already exists" << std::endl;
        }
    }
    else
    {
        std::cout << "Either of the vertices does not exist" << std::endl;
    }
}
void Graph::UpdateEdge(const int &source, const int &destination, const int &distance)
{
    if (checkIfvertexExist(source) && checkIfvertexExist(destination))
    {
        for (auto &sourceVertex : vertices)
        {
            if (sourceVertex.get_id() == source)
            {
                for (auto &edge : sourceVertex.edges)
                {
                    if (edge.get_id() == destination)
                    {
                        edge.set_distance(distance);
                        std::cout << "\nUpdated successfully\n"
                                  << std::endl;
                        return; // Exit the function once you've updated the edge
                    }
                }
                std::cout << "\nEdge does not exist between the source and destination\n"
                          << std::endl;
                return; // Exit the function if the destination vertex was not found
            }
        }
    }
    else
    {
        std::cout << "Either of vertex not exist  " << std::endl;
    }
}

void Graph::UpdateVertex(const int &id, const std::string &name)
{
    auto it = std::find_if(vertices.begin(), vertices.end(), [id](const Vertex &vec)
                           { return vec.get_id() == id; });
    if (it != vertices.end())
    {
        it->set_name(name);
    }
}

void Graph::DeleteEdge(const int &source, const int &destination)
{
    if (checkIfvertexExist(source) && checkIfvertexExist(destination))
    {
        for (auto &n : vertices)
        {
            if (n.get_id() == source)
            {
                if (checkIfEdgeExist(source, destination))
                {
                    // update
                    auto it = std::find(n.edges.begin(), n.edges.end(), destination);
                    if (it != n.edges.end())
                    {
                        n.edges.erase(it);
                        std::cout << "\nDeleted successfully\n"
                                  << std::endl;
                    }
                }
                else
                {
                    std::cout << "\nEdge does not exist between the source and destination\n"
                              << std::endl;
                }
                break;
            }
        }
    }
    else
    {
        std::cout << "Either of vertex not exist  " << std::endl;
    }
}
void Graph::DeleteVector(const int &id)
{
    if (checkIfvertexExist(id))
    {
        auto it = std::remove_if(vertices.begin(), vertices.end(), [id](const Vertex &vert)
                                 { return vert.get_id() == id; });
        vertices.erase(it, vertices.end()); // Remove the vertex

        // Remove edges associated with the deleted vertex
        for (auto &vertex : vertices)
        {
            vertex.edges.remove_if([id](const Edge &edge)
                                   { return edge.get_id() == id; });
        }
        std::cout << "\nDeleted Vertex successfully\n"
                  << std::endl;
    }
}

void Graph::print()
{
    std::cout << std::left << std::setw(12) << "ST_ID's" << std::setw(12) << "Stations_Name " << std::setw(12) << " Connected_Stations_ID_List (CONNECTED STATION TO THIS STATION AND RESPECTIVE DISTANCE IN BETWEEN) " << std::endl;
    for (auto &n : vertices)
    {
        std::cout << "----------------------------------------------------------------------" << std::endl;
        std::cout << std::left << std::setw(12) << n.get_id() << std::setw(12) << n.get_name() << std::setw(12) << " ---> ";
        n.printEdgeList();
    }
}
bool Graph::checkIfvertexExist(const int &id)
{
    for (const auto &vec : vertices)
    {
        if (vec.get_id() == id)
            return true;
    }
    return false;
}
bool Graph::checkIfEdgeExist(const int &source, const int &destination)
{

    for (const auto &vert : vertices)
    {
        if (vert.get_id() == source)
        {
            auto it = std::find(vert.edges.begin(), vert.edges.end(), destination);
            if (it != vert.edges.end())
            {
                return true;
            }
        }
    }
    return false;
}

void Graph::dijkstrabellman(const std::string &startStation, const std::string &endStation)
{
    // Dijkstra's algorithm
    std::priority_queue<Vertex, std::vector<Vertex>, std::greater<Vertex>> pq;
    std::unordered_set<int> visited;
    int shortestDistance{};

    // Find the vertex corresponding to the start station name
    int startVertex = -1;
    for (const auto &vertex : vertices)
    {
        if (vertex.get_name() == startStation)
        {
            startVertex = vertex.get_id();
            break;
        }
    }

    if (startVertex == -1)
    {
        std::cout << "Start station not found.\n";
        return;
    }

    // Initialize single source
    for (auto &v : vertices)
    {
        if (v.get_id() == startVertex)
            v.set_distance(0);
        else
            v.set_distance(INT_MAX);
        v.set_predecessor(-1);
    }

    pq.push(vertices.at(startVertex - 1));

    while (!pq.empty())
    {
        Vertex current = pq.top();
        pq.pop();

        int u = current.get_id();

        if (visited.find(u) != visited.end())
            continue;

        visited.insert(u);

        for (const auto &edge : current.edges)
        {
            int v = edge.get_id();
            int weight = edge.get_distance();
            int newDistance = current.get_distance() + weight;

            // Relaxing
            if (newDistance < vertices.at(v - 1).get_distance())
            {
                vertices.at(v - 1).set_distance(newDistance);
                vertices.at(v - 1).set_predecessor(u);
                pq.push(vertices.at(v - 1));
            }
        }
    }

    // Bellman-Ford algorithm to check for negative cycles
    for (const auto &current : vertices)
    {
        for (auto &edge : current.edges)
        {
            int v = edge.get_id();
            int w = edge.get_distance();

            if (current.get_distance() != INT_MAX && current.get_distance() + w < (vertices.at(v - 1).get_distance()))
            {
                std::cout << "The graph contains negative cycles." << std::endl;
                return;
            }
        }
    }

    // Printing the results if no negative cycles
    std::cout << "\n>>>> "
              << "Route Finding Please Wait ....... "
              << " >>>>" << std::endl;
    std::cout << "Shortest path from station " << startStation << " to station " << endStation << ":\n";

    // Find the vertex corresponding to the end station name
    int endVertex = -1;
    for (const auto &vertex : vertices)
    {
        if (vertex.get_name() == endStation)
        {
            endVertex = vertex.get_id();
            break;
        }
    }

    if (endVertex == -1)
    {
        std::cout << "End station not found.\n";
        return;
    }

    std::vector<std::string> pathStations;
    std::vector<std::string> pathColors;
    std::string currentLineColor;
    int currentVertex = endVertex; // Initialize with the endVertex

    while (currentVertex != startVertex)
    {
        int prevVertexId = vertices.at(currentVertex - 1).get_predecessor();
        std::string color = edgeColors[{currentVertex, prevVertexId}];
        int edgeDistance = edgeDistances[{currentVertex, prevVertexId}];
        shortestDistance += edgeDistance; // Add edge distance to the shortestDistance

        if (color != currentLineColor)
        {

            currentLineColor = color;
        }

        pathStations.push_back(vertices.at(currentVertex - 1).get_name());
        pathColors.push_back(color);
        currentVertex = prevVertexId;

        if (currentVertex == -1)
        {
            std::cout << "No path exists from station " << startStation << " to station " << endStation << ".\n";
            return;
        }
    }

    if (!pathStations.empty())
    {
        // Print the last segment of the path
        pathStations.push_back(startStation);
        std::reverse(pathStations.begin(), pathStations.end());
        std::reverse(pathColors.begin(), pathColors.end());
        printPathWithColor(pathStations, pathColors, shortestDistance);
        std::cout << std::endl;
        pathStations.clear();
        pathColors.clear();
    }
}

void Graph::printPathWithColor(const std::vector<std::string> &pathStations, const std::vector<std::string> &pathColors, const int &shortestDistance)
{
    if (pathStations.empty() || pathColors.empty())
    {
        return; // No path or colors to print
    }
    std::string prevcolor{};
    std::string currentcolor;
    std::set<std::string> UniqueColors;
    int j{};

    for (int i = 0; i < pathStations.size(); i++)
    {
        if (i == 0)
        {
            std::cout << "----- " << pathColors[0] << " Line -----" << std::endl;
        }
        if (i < pathColors.size() && prevcolor != pathColors[j])
        {
            prevcolor = pathColors[j];

            UniqueColors.insert(pathColors[j]);
            if (i != 0)
            {
                std::cout << "----- " << pathColors[j] << " Line -----" << std::endl;
            }
        }
        if (i != 0)
        {
            j++;
            std::cout << "↓" << std::endl;
        }
        std::cout << pathStations[i] << std::endl;
    }

    // Print distance and number of stations
    std::cout << " >>>>   Distance: " << shortestDistance << "  >>>>\n";
    std::cout << " >>>>   Stations: " << pathStations.size() << "  >>>>\n";
    std::cout << " >>>> Number of lines required : " << UniqueColors.size() - 1 << " >>>>" << std::endl;
};

int getIntegerInput(const std::string &prompt)
{
    int value;
    bool validInput = false;
    while (!validInput)
    {
        std::cout << prompt;
        if (!(std::cin >> value))
        {
            std::cin.clear();                                                   // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
            std::cout << "Invalid input. Please enter an integer.\n";
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear trailing newline
            validInput = true;
        }
    }
    return value;
}

char getCharInput(const std::string &prompt)
{
    char input;
    bool validInput = false;
    while (!validInput)
    {
        std::cout << prompt;
        std::cin >> input;
        if (std::cin.fail() || std::cin.peek() != '\n' || (input < 'A' || (input > 'Z' && input < 'a') || input > 'z'))
        {
            std::cin.clear();                                                   // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
            std::cout << "Invalid input. Please enter a single alphabetical character.\n";
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear trailing newline
            validInput = true;
        }
    }
    return input;
}

std::string getStringInput(const std::string &prompt)
{
    std::string input;
    while (true)
    {
        std::cout << prompt;
        std::getline(std::cin, input);

        // Check if the input is not empty and contains at least one non-space character
        if (!input.empty() && input.find_first_not_of(' ') != std::string::npos)
        {
            return input;
        }
        else
        {
            std::cout << "Invalid input. Please enter a non-empty string.\n";
        }
    }
}
