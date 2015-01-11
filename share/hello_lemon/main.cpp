#include <iostream>
#include <lemon/list_graph.h>
#include <lemon/graph_to_eps.h>
#include<lemon/math.h>

using namespace lemon;
using namespace std;

int main()
{
     typedef ListDigraph::Node Node;
     typedef ListDigraph::NodeIt NodeIt;
     typedef ListDigraph::Arc Arc;
     typedef dim2::Point<int> Point;

     ListDigraph g;
     ListDigraph::Node u = g.addNode();
     ListDigraph::Node v = g.addNode();
     ListDigraph::Node p = g.addNode();
     ListDigraph::Arc a = g.addArc(u, v);
     ListDigraph::Arc b = g.addArc(u, p);
     cout << "Hello World! This is LEMON library here." << endl;
     cout << "We have a directed graph with " << countNodes(g) << " nodes "
          << "and " << countArcs(g) << " arc." << endl;

     cout << endl << endl;

     int cnt = 0;
     for (ListDigraph::NodeIt n(g); n != INVALID; ++n)
          cnt++;
     std::cout << "Number of nodes: " << cnt << std::endl;

     ListDigraph::NodeMap<Point> coords(g);
     ListDigraph::NodeMap<double> sizes(g);
     ListDigraph::NodeMap<int> colors(g);
     ListDigraph::NodeMap<int> shapes(g);
     ListDigraph::ArcMap<int> acolors(g);
     ListDigraph::ArcMap<int> widths(g);

     coords[u]=Point(50,50);  sizes[u]=1; colors[u]=1; shapes[u]=0;
     coords[v]=Point(50,70);  sizes[v]=2; colors[v]=2; shapes[v]=2;
     coords[p]=Point(70,70);  sizes[p]=1; colors[p]=3; shapes[p]=0;     

     acolors[a]=0; widths[a]=1;
     acolors[b]=0; widths[b]=1;
     
     Palette palette;
     Palette paletteW(true);

     IdMap<ListDigraph,Node> id(g);

     graphToEps(g, "graph.eps")
          .coords(coords)
          .title("Sample EPS figure")
          .copyright("(c) 2003-2010 LEMON Project")
          .absoluteNodeSizes().absoluteArcWidths()
          .nodeScale(2).nodeSizes(sizes)
          .nodeShapes(shapes)
          .nodeColors(composeMap(palette, colors))
          .arcColors(composeMap(palette, acolors))
          .arcWidthScale(.4).arcWidths(widths)
          .nodeTexts(id).nodeTextSize(3)
          .drawArrows().arrowWidth(2).arrowLength(2)
          .run();

     return 0;
}
