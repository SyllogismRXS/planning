#include <iostream>
#include <lemon/list_graph.h>

using namespace lemon;
using namespace std;

int main()
{
     ListDigraph g;
     ListDigraph::Node u = g.addNode();
     ListDigraph::Node v = g.addNode();
     ListDigraph::Node p = g.addNode();
     ListDigraph::Arc a = g.addArc(u, v);
     cout << "Hello World! This is LEMON library here." << endl;
     cout << "We have a directed graph with " << countNodes(g) << " nodes "
          << "and " << countArcs(g) << " arc." << endl;

     cout << endl << endl;

     int cnt = 0;
     for (ListDigraph::NodeIt n(g); n != INVALID; ++n)
          cnt++;
     std::cout << "Number of nodes: " << cnt << std::endl;

     return 0;
}
