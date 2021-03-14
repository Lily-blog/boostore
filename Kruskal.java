import java.util.*;

public class Main {
	static  class DSU{
		int [] root;
		int [] size;
		public DSU(int n) {
			root = new int[n];
			size = new int[n];
			for(int i = 0;i<n;i++) {
				root[i] = i;
			}
			Arrays.fill(size,1);
		}
		public int find(int x) {
			if(root[x]!=x) {
				root[x] = find(root[x]);
			}
			return root[x];
		}
		public void union(int x,int y) {
			int rootx = find(x);
			int rooty = find(y);
			if(rootx==rooty) return ;
			if(size[rootx]<size[rooty]) {
				root[rootx] = rooty;
				size[rooty]++;
			}else {
				root[rooty] = root[x];
				size[rootx]++;
			}
		}
	}
	static class Edge{
		int weight;
		int x;
		int y;
		public Edge(int w,int a,int b) {
			weight = w;
			x = a;
			y = b;
		}
	}

		   public static void main(String[] args) {
		    Scanner s = new Scanner(System.in);
		   int n = s.nextInt();
		   int m =s.nextInt();
		   Edge[] edges = new Edge[m];
		   for(int i= 0;i<m;i++) {
			   int a = s.nextInt();
			   int b = s.nextInt();
			   int w = s.nextInt();
			   edges[i] = new Edge(w,a,b);
		   }
		   Arrays.sort(edges,(a,b) -> a.weight - b.weight);
		   int min = kruscal(edges);
		   System.out.println(min);
		   }
		   private static int kruscal(Edge[] edges) {
			   DSU dsu =  new DSU(10005);
			   int min = 0;
			   for(Edge e : edges) {
				   int x = e.x;
				   int y = e.y;
				   if(dsu.find(x)!=dsu.find(y)) {
					   min += e.weight;
					   dsu.union(x,y);
				   }
			   }
			   return min;
		   }
}
