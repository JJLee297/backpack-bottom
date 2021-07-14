import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		int[] run1 = {2, 5, 1, 3, 5, 0}; 
		int[] arr = {0, 3, 5, 0, 1, 4};
		int[] ovr = {0, 3, 5, 0, 1, 4};
		int[][] mat; 
		mat = new int[4][3];
		mat[0][0] = 20; 
		mat[0][1] = 21; 
		mat[0][2] = 22; 
		mat[1][0] = 23; 
		mat[1][1] = 24; 
		mat[1][2] = 25; 
		mat[2][0] = 26; 
		mat[2][1] = 27; 
		mat[2][2] = 28; 
		mat[3][0] = 29; 
		mat[3][1] = 30; 
		mat[3][2] = 31; 
		overwriteMat(mat, ovr, 0, 1);
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 3; ++j) {
				System.out.print(mat[i][j] + " ");
			}
			System.out.print("\n"); 
		}
 		
	}

	private static int[] subArray(int[] arr, int start) {
		int[] test; 
		test = new int[arr.length - start]; 
		for (int i = 0; i < arr.length - start; ++i) {
			test[i] = arr[start + i];
		}
		return test; 
	}
	public static void overwrite(int[] arr, int[] ovr, int start) {
		  for (int i = 0; i < ovr.length; ++i) {
			  if (start + i > arr.length - 1) 
				  break; 
			  arr[start + i] = ovr[i]; 
		  }
	  }
	public static void overwriteMat(int[][] mat,int[] ovr, int srow, int scol) {
		  int row = srow;
		  int col = scol; 
		  for (int i = 0; i < ovr.length; ++i) {
			  mat[row][col] = ovr[i];
			  ++col; 
			  if (col >= mat[0].length) {
				  col = 0;
				  ++row; 
			  }
			  if (row >= mat.length) {
				  break; 
			  }
			  
		  }
	  }
}
