#include <iostream>
#include <lemon/list_graph.h>
#include <plan/common/GraphDisplay.h>
#include <plan/common/ActionNode.h>
#include <plan/common/LiteralNode.h>

using namespace lemon;
using namespace std;

int main()
{     
     // Create a planning graph using the Have Cake / Eat Cake Example

     ListDigraph g;
     ListDigraph::NodeMap<PlanNode> map(g);

     // State 0
     ListDigraph::Node have_cake_0 = g.addNode();
     ListDigraph::Node not_eaten_cake_0 = g.addNode();

     map[have_cake_0] = PlanNode("Have(Cake)", 0);
     map[not_eaten_cake_0] = PlanNode("Not(Eaten(Cake))", 0);
     
     // Action 0
     ListDigraph::Node eat_cake_0 = g.addNode();     
     ListDigraph::Node no_op_0 = g.addNode();     
     ListDigraph::Arc a1 = g.addArc(have_cake_0, no_op_0);
     ListDigraph::Arc a2 = g.addArc(have_cake_0, eat_cake_0);

     map[eat_cake_0] = PlanNode("Eat(Cake)", 0);

     // State 1
     ListDigraph::Node have_cake_1 = g.addNode();
     ListDigraph::Node no_have_cake_1 = g.addNode();
     ListDigraph::Node eaten_cake_1 = g.addNode();
     ListDigraph::Node not_eaten_cake_1 = g.addNode();

     ListDigraph::Arc b = g.addArc(have_cake_0, have_cake_1);
     ListDigraph::Arc c = g.addArc(eat_cake_0, no_have_cake_1);
     ListDigraph::Arc d = g.addArc(eat_cake_0, eaten_cake_1);
     ListDigraph::Arc e = g.addArc(not_eaten_cake_0, not_eaten_cake_1);     
     
     return 0;
}
