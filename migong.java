package Fet;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;
public class migong {
	public static void main(String[] args) throws IOException {
		File f=new File("C:\\Users\\gc\\Desktop\\gc.txt");
		FileWriter out = new FileWriter(f);
		int[][] maze = new int[10][10];
		int i = 0, j = 0, count = 0, x = 0, y = 0;
		Random r = new Random();
		int di = Math.abs(r.nextInt() % 4);
		int n = Math.abs(r.nextInt() % 10);

		for (int x1 = 0; x1 < maze.length; x1++) {
			for (int y1 = 0; y1 < maze[x1].length; y1++) {
				maze[x1][y1] = 1;
			}
		}

		while (di < 4) {
			switch (di) {
			case 0:
				i = x;
				j = y + n;
				if (i <= 9 && j <= 9)
					break;
				else {
					j = j - n;
					break;
				}
			case 1:
				i = x;
				j = y - n;
				if (i <= 9 && j >= 0)
					break;
				else {
					j = j + n;
					break;
				}
			case 2:
				i = x + n;
				j = y;
				if (i <= 9 && j <= 9)
					break;
				else {
					i = i - n;
					break;
				}
			case 3:
				i = x - n;
				j = y;
				if (i >= 0 && j <= 9)
					break;
				else {
					i = i + n;
					break;
				}
			}// switch��
			if (di == 0) {
				for (int w0 = y; w0 <= j; w0++)
					maze[i][w0] = 0;
			} else if (di == 1) {
				for (int w1 = y; w1 >= j; w1--)
					maze[i][w1] = 0;
			} else if (di == 2) {
				for (int w2 = x; w2 <= i; w2++)
					maze[w2][j] = 0;
			} else if (di == 3) {
				for (int w3 = x; w3 >= i; w3--) {
					maze[w3][j] = 0;
				}
			} // �ĸ�if����
			
			if (i == 9 && j == 9) {
				maze[9][9] = 0;
				for (int x1 = 0; x1 < maze.length; x1++) {
					for (int y1 = 0; y1 < maze[x1].length; y1++) {
						System.out.print(maze[x1][y1]);
					}
					System.out.println();
				}
				break;
			}
			di = Math.abs(r.nextInt() % 4);
			n = Math.abs(r.nextInt() % 10);
			x = i;
			y = j;
		} // while di<4�߽�
		//out.write("[");
		//out.write("\r\n");
		for (int x1 = 0; x1 < maze.length; x1++) {
			//out.write("[");
			for (int y1 = 0; y1 < maze[x1].length; y1++) {
				out.write((maze[x1][y1]+48));
				//out.write(",");
				if(y1+1==maze.length) {
					//out.write("]");
					//out.write(",");
					out.write("\r\n");					
				}
			}
		}//for�߽�
		//out.write("]");
		out.close();
	

	}// main�߽�

}// migong�߽�/