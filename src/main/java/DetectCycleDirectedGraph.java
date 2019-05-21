import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

public class DetectCycleDirectedGraph {

    public static final int WHITE = 0;
    public static final int GRAY = 1;
    public static final int BLACK = 2;

    public static class Graph {
        List<List<Integer>> adjList;
        boolean visited[];

        Graph(int size) {
            visited = new boolean[size];
            adjList = new ArrayList<>();

            for(int i=0;i<size;i++)
                adjList.add(i, new LinkedList<>());
        }

        private Graph() {}

        void addEdge(int u, int v) {
            List<Integer> temp = adjList.get(u);
            temp.add(v);
        }
    }

    private static boolean dfsRecIsCyclic(Graph g, int[] colors, int u) {
        if(colors[u] == WHITE)
            colors[u] = GRAY;

        Iterator<Integer> iter = g.adjList.get(u).iterator();
        while(iter.hasNext()) {
            int v = iter.next();
            if(colors[v] == BLACK)
                continue;

            if(colors[v] == GRAY)
                return true;

            if(dfsRecIsCyclic(g, colors, v))
                return true;
        }

        colors[u] = BLACK;
        return false;
    }

    public static boolean dfs(Graph g, int size) {
        int colors[] = new int[size];

        for(int i=0; i<size; i++) {
            if(dfsRecIsCyclic(g, colors, i))
                return true;
        }

        return false;
    }

    public static void main(String []args) {
        Graph g1 = new Graph(5);
        g1.addEdge(0, 1);
        g1.addEdge(0, 2);
        g1.addEdge(1, 2);
        g1.addEdge(2, 0);
        g1.addEdge(2, 3);
        g1.addEdge(3, 3);

        if(dfs(g1, 5))
            System.out.println("Graph has cycle");
        else
            System.out.println("Graph has no cycle");

        Graph g2 = new Graph(5);
        g2.addEdge(0, 1);
        g2.addEdge(0, 2);
        g2.addEdge(1, 3);
        g2.addEdge(1, 4);

        if(dfs(g2, 5))
            System.out.println("Graph has cycle");
        else
            System.out.println("Graph has no cycle");

        Graph graph = new Graph(7);
        graph.addEdge(1, 2);
        graph.addEdge(1, 3);
        graph.addEdge(2, 3);
        graph.addEdge(4, 1);
        graph.addEdge(4, 5);
        graph.addEdge(5, 6);
        graph.addEdge(6, 4);

        if(dfs(graph, 7))
            System.out.println("Graph has cycle");
        else
            System.out.println("Graph has no cycle");

    }
}
