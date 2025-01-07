import java.util.Scanner;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int t = 0; t < T; t++) {
            int N = sc.nextInt();
            int K = sc.nextInt();
            int[] time = new int[N];
            int[] pre = new int[N];
            ArrayList<Integer>[] suc = new ArrayList[N];
            for (int i = 0; i < N; i++) {
                time[i] = sc.nextInt();
                suc[i] = new ArrayList<>();
            }
            for (int i = 0; i < K; i++) {
                int X = sc.nextInt();
                int Y = sc.nextInt();
                suc[X - 1].add(Y - 1);
                pre[Y - 1]++;
            }
            int W = sc.nextInt() - 1;

            int[] result = new int[N];
            Queue<Integer> Q = new LinkedList<>();
            for (int i = 0; i < N; i++) {
                if (pre[i] == 0) Q.add(i);
            }

            while (pre[W] > 0) {
                int u = Q.poll();
                for (int next : suc[u]) {
                    result[next] = Math.max(result[next], result[u] + time[u]);
                    if (--pre[next] == 0) Q.add(next);
                }
            }
            System.out.println(result[W] + time[W]);
        }
        sc.close();
    }
}
