import java.io.*;
import java.util.*;

class Solution {
  
  private static class Node {
    int index;
    int data;
  }
  
  private static class Graph {
      int[] visited;
      Map<Integer, List<Node>> adjList;
  }
  
  private static void bfs(Graph g) {
    Queue<Integer> q = new LinkedList<>();
    for(int i=0;i<g.visited.length;i++) {
      g.visited[i] = 0;
    }
    q.add(0);
    
    while(q.isEmpty() == false) {
      int u = q.poll();
      if(g.visited[u] == 0) {
        g.visited[u] = 1;
        System.out.println("Visited " + u);
        List<Node> adjL = g.adjList.get(u);
        for(Node ele: adjL) {
          q.add(ele.index);
        }
      }
    }
    System.out.println();
  }
  
  public static void main(String[] args) {
    int dummy[][] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                      };
    
    Graph g = new Graph();
    g.visited = new int[9];
    g.adjList = new HashMap<>();
    for(int i=0;i<9;i++) {
      List<Node> list = new ArrayList<>();
      for(int j=0;j<9;j++) {
          if(dummy[i][j] != 0) {
            Node n = new Node();
            n.index = j;
            n.data = dummy[i][j];
            list.add(n);
          }
      }
      g.adjList.put(i, list);
    }
    bfs(g);
  }
}
