import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static StringBuilder sb = new StringBuilder();
	public static int N, M, R;
	public static int[][] map = new int[100][100];
	public static void printMap() {
		for(int i = 0; i < N;i++) {
			for(int j = 0; j <  M ; j++) {
				sb.append(map[i][j]).append(" ");
			}
			sb.append("\n");
		}
		System.out.println(sb);
	}
	public static void move(int inst) {
		int[][] newMap = new int[100][100];
		switch(inst) {
		case 1:{
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					newMap[i][j] = map[N-i-1][j];
				}
			}
			break;
		}
		case 2:{
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					newMap[i][j] = map[i][M-1-j];
				}
			}
			break;
		}
		case 3:{
			for (int i = 0; i < M; i++) {
				for (int j = 0; j < N; j++) {
					newMap[i][j] = map[N-1-j][i];
				}
			}
			int temp = N;
			N = M;
			M = temp;
			break;
		}
		case 4:{
			for (int i = 0; i < M; i++) {
				for (int j = 0; j < N; j++) {
					newMap[i][j] = map[j][M-1-i];
				}
			}
			int temp = N;
			N = M;
			M = temp;
			break;
		}
		case 5:{
			int dist1 = N /2 ;
			int dist2 = M /2 ;
			for(int i = 0; i < N;i++) {
				for(int j = 0 ; j < M;j++) {
					if(i < N /2) {
						if(j < M /2 ) {
							newMap[i][j] = map[i + dist1][j];
						}else {
							newMap[i][j] = map[i][j - dist2];
						}
					}else {
						if (j < M /2) {
							newMap[i][j] = map[i][j + dist2];
						}else {
							newMap[i][j] = map[i-dist1][j];
						}
					}
				}
			}
			break;
		}
		case 6:{
			int dist1 = N /2 ;
			int dist2 = M /2 ;
			for(int i = 0; i < N;i++) {
				for(int j = 0 ; j < M;j++) {
					if(i < N /2) {
						if(j < M /2 ) {
							newMap[i][j] = map[i][j + dist2];
						}else {
							newMap[i][j] = map[i + dist1][j];
						}
					}else {
						if (j < M /2) {
							newMap[i][j] = map[i - dist1][j];
						}else {
							newMap[i][j] = map[i][j - dist2];
						}
					}
				}
			}
			break;
		}
		}
		map = newMap;
		//printMap();
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < R;i++) {
			int inst = Integer.parseInt(st.nextToken());
			move(inst);
		}
		printMap();
	}
}
