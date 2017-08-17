#ifndef GRAPH_H
#define GRAPH_H
#include <unordered_map>
#include <queue>
#include <vector>
#include <functional>

#include<ostream>

#include "Vertex.h"
using namespace std;
class Graph
{
	unordered_map<int, Vertex> _vertices;

public:

	void addVertex(Vertex vertex)
	{
		_vertices[vertex.getId()] = vertex;
	}

	//MA #12 TODO: IMPLEMENT!
	unordered_map<Vertex, int> computeShortestPath(Vertex *start)
	{
		//holds known distances
		unordered_map<Vertex, int> distances;

		//underlying heap
		priority_queue<Vertex, vector<Vertex>, PathWeightComparer> dijkstra_queue{};

		//reset start's path weight
		start->setPathWeight(0);

		//make sure that the starting vertex is in the graph
		
		if (start->getId()) {
			
		
			//push on starting vertex
			dijkstra_queue.push(start->getId());
			
			//while queue not empty
			while (!dijkstra_queue.empty() )
			{
				Vertex tmp = dijkstra_queue.top();
			    dijkstra_queue.pop();
			    
			    int id = tmp.getId();
			   
				auto myedges = tmp.getEdges();
                   
                  /* for (auto i = myedges.begin(); i != myedges.end(); ++i){
                		 auto  tl = i ;
          
                		  if (distances.at(id) > distances.at(tl->getId()) + tl->getPathWeight())
                    		{
                    		 distances.at(id) = distances.at(tl->getId()) + tl->getPathWeight();
                    	  
                    		 dijkstra_queue.push(tl->getId());
                    		}
					
                   } */
                 
			}		
		}
		return distances;
	}
};

#endif
