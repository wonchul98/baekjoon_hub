import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
public class Main {
	public static boolean[] plus = new boolean[30];
	public static boolean[] minus = new boolean[30];
	public static boolean[] visited = new boolean[15];
	public static int N;
	public static int ans;
	public static void recur(int row, int col) {
		//System.out.printf("recur(%d,%d)\n", row, col);
		if(row == N-1) {
			ans++;
			return;
		}
		visited[col] = true;
		plus[row+col] = true;
		minus[row-col+N] = true;
		for(int i = 0; i < N;i++) {
			if(visited[i] || plus[row + 1 + i] || minus[row + 1 - i + N]) continue;
			recur(row+1, i);
		}
		visited[col] = false;
		plus[row+col] = false;
		minus[row-col+N] = false;
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		for(int i = 0; i < N;i++) {
			recur(0,i);			
		}
		System.out.println(ans);
	}
}
