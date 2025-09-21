// To input arrays at compile time

class Array{
	public static void main(String args[]){
		int n[] = {1, 2, 3};
		for (int i = 0; i < n.length ; i++){ // here we can use n.length or 3 (n.length gives the length of the array)
			System.out.print(n[i]);
		}
	}
}

// output -> 
// 1 2 3 

// To input arrays at runtime

import java.util.Scanner;
class Array{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);

		System.out.print("Enter the number of elements in array : ");
		int n = sc.nextInt();

		int x[] = new int[n];

		System.out.println("Enter " + n + " elements:");
		for (int i = 0; i < x.length ; i++){
			x[i] = sc.nextInt();
			System.out.print(x[i]);
		}

	}
}


// output ->
// Enter the number of elements in array: 5
// Enter 5 elements:
// 10 20 30 40 50
// Array elements are: 10 20 30 40 50



// To find the sum of elements of array

import java.util.Scanner;
class Arraysum{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);

		System.out.print("Enter the number of elements in array : ");
		int n = sc.nextInt();

		int x[] = new int[n];
		int sum = 0; 

		System.out.print("Enter " + n + "elements : ");

		for (int i = 0; i < x.length ; i++){
			x[i] = sc.nextInt();
		}

		for (int j = 0 ; j < x.length ; j++){
			sum += x[j];
		}

		// Instead of writing two for loops we can write as
		// for (int i = 0; i < x.length ; i++){
				// x[i] = sc.nextInt();
				// sum += x[i];
	// }

		System.out.print("The sum of array is : " + sum);

	}
}


// output ->>
// Enter the number of elements in array : 5
// Enter 5 elements : 10 20 30 40 50
// The sum of array is : 150


// Copying the elements of one array to another

import java.util.Scanner;
class Arraycopy{
	public static void main(String args[]){

		Scanner sc = new Scanner(System.in);

		System.out.print("Enter the number of elements in array: ");
		int n = sc.nextInt();

		int a[] = new int[n];
		int b[] = new int[a.length];

		System.out.print("Enter " + n + "elements : ");
		for (int i = 0; i < a.length; i++){
			a[i] = sc.nextInt();
			b[i] = a[i];
		}

		System.out.print("The first array is: ");
        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i] + " ");
        }

		System.out.print("The second array is :");
		for (int i = 0; i < b.length ; i++){
			System.out.print(b[i] + " ");
		}
	}
}


// output -> 

// Enter the number of elements in array: 4
// Enter 4 elements: 5 10 15 20
// The first array is: 5 10 15 20 
// The second array is: 5 10 15 20



// To reverse an array
import java.util.Scanner;
class Arrayreverse{
	public static void main(String args[]){

		Scanner sc = new Scanner(System.in);

		System.out.print("Enter the number of elements in array : ");
		int n = sc.nextInt();

		int a[] = new int[n];

		System.out.print("Enter " + n + "elements");

		for (int i = 0; i < a.length ; i++){
			a[i] = sc.nextInt();
		}

		System.out.print("The original array is : ");
		for(int i = 0; i < a.length ; i++){
			System.out.print(a[i] + " ");
		}

		System.out.print("The reversed array is : ");
		for (int i = a.length - 1 ; i >= 0; i--){
			System.out.print(a[i] + " ");
		}


	}
}

// output ->>

// Enter the number of elements in array : 5
// Enter 5 elements
// 10 20 30 40 50
// The original array is : 10 20 30 40 50
// The reversed array is : 50 40 30 20 10


// To check whether an element is present or not
import java.util.Scanner;
class Arraysearch{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);

		System.out.print("Enter the number of elements in array : ");
		int n = sc.nextInt();
		int a[] = new int[n];

		System.out.print("Enter " + n + "elements");
		for(int i = 0; i < a.length ; i++){
			a[i] = sc.nextInt();
		}

		System.out.print("The array is : ");
		for(int i = 0; i < a.length ; i++){
			System.out.print(a[i] + " ");
		}

		System.out.print("Enter the element to search : ");
		int tosearch = sc.nextInt();

		int i;
		for (i = 0; i < n; i++){
			if(a[i] == tosearch){
				System.out.print("Element" + tosearch + "is found in array");
			}

		}
		if(i == n){
			System.out.print("Element" + tosearch + "is not found in array");
		}

}
}


// with boolean
// 		boolean found = false;
// 		for(int i = 0; i < n ; i++){
// 			if(a[i] == tosearch){
// 				found = true;
// 				break;
// 			}
// 		}

// 		if(found){
// 			System.out.print("Element " + tosearch + "is present in array");
// 		}
// 		else{
// 			System.out.print("Element" + tosearch + "is not present in array");
// 		}
// 	}
// }



// output ->> 

// Enter the number of elements in array: 5
// Enter 5 elements:
// 10 20 30 40 50
// The array is: 10 20 30 40 50 
// Enter the element to search: 30
// Element 30 is present in the array.


// Array elements even sum and odd sum
import java.util.Scanner;
class Arrayevenoddsum{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);

		System.out.print("Enter the number of elements in array :");
		int n = sc.nextInt();
		int a[] = new int[n];

		System.out.print("Enter " + n + "elements");
		for(int i = 0; i < a.length ; i++){
			a[i] = sc.nextInt();
		}

		System.out.print("The array is :");
		for(int i = 0; i < a.length; i++){
			System.out.print(a[i] + " ");
		}

		int evensum = 0;
		int oddsum = 0;

		for(int i = 0; i < a.length; i++){
			if(a[i] % 2 == 0){
				evensum += a[i];
			}
			else{
				oddsum += a[i];
			}
		}

		System.out.print("Even sum is " + evensum);
		System.out.print("Odd sum is " + oddsum);
	}
}


// output ->>
// Enter the number of elements in array: 6
// Enter 6 elements:
// 1 2 3 4 5 6
// The array is: 1 2 3 4 5 6
// Sum of even numbers = 12
// Sum of odd numbers = 9


// To check how many times a element is repeated
import java.util.Scanner;
class Arrayrepeated{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);

		System.out.print("Enter the number of elements in array : ");
		int n = sc.nextInt();

		int a[] = new int[n];

		System.out.print("Enter " + n + "elements");

		for(int i = 0; i < a.length ; i++){
			a[i] = sc.nextInt();
		}

		System.out.print("The array is :");
		for(int i = 0; i < a.length ; i++){
			System.out.print(a[i] + " ");
		}

		System.out.print("Enter the element to search : ");
		int tosearch = sc.nextInt();

		int count = 0;
		for(int i = 0; i < a.length; i++){
			if(a[i] == tosearch){
				count++;
			}
		}

		System.out.print("The element" + tosearch + "repeated" + count + "times");
	}
}

// output ->>
// Enter the number of elements in array: 6
// Enter 6 elements:
// 5 2 7 5 3 5
// The array is: 5 2 7 5 3 5
// Enter the element to search: 5
// The element 5 is repeated 3 time(s).



// For single Dimensional array (at compile time)
class Singledimen{
	public static void main(String args[]){
		int arr[] = {1,1,2,2};

		System.out.print("Array elements are");
		for(int i = 0; i < arr.length; i++){
			System.out.print(arr[i] + " ");
		}
	}
}


// output ->>
// Array elements are 1 1 2 2 


// At runtime
import java.util.*;
class Singledimen{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);

		System.out.print("Enter the number of rows : ");
		int n = sc.nextInt();


		int a[] = new int[n];

		System.out.print("Enter " + n + "elements :");
		for(int i = 0; i < n ; i++){
			a[i] = sc.nextInt();
		}

		System.out.print("Array is ");
		for(int i = 0; i < n; i++){
			System.out.print(a[i] + " ");
		}
	}
}

// output ->>
// Enter the number of rows : 5
// Enter 5 elements :
// 10 20 30 40 50
// Array is 10 20 30 40 50 


// Multidimensional array(at compile time)
class Multidimensional{
	public static void main(String args[]){
		int a[][] = new int[2][3];

		a[0][0] = 1;
		a[0][1] = 2;
		a[0][2] = 3;
		a[1][0] = 4;
		a[1][1] = 5;
		a[1][2] = 6;


		System.out.print("The Multidimensional array is");
		for(int i = 0; i < 2 ; i++){
			for(int j = 0; j < 3; j++){
				System.out.print(a[i][j] + " ");
			}
			System.out.println();
		}
	}
}


// output ->>

// The Multidimensional array is:
// 1 2 3 
// 4 5 6 


// Multidimensional(At runtime)
import java.util.*;
class Multidimensional{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);

		System.out.print("Enter number of rows : ");
		int r = sc.nextInt();

		System.out.print("Enter the number of columns : ");
		int c = sc.nextInt();

		int a[][] = new int[r][c];

		System.out.print("Enter the elements :");
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				a[i][j] = sc.nextInt();
			}
		}

		System.out.print("The Array is :");
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c ; j++){
				System.out.print(a[i][j] + " ");
			}
		}
	}
	System.out.println(" ");
}


// output ->>
// Enter number of rows : 2
// Enter the number of columns : 3
// Enter the elements:
// 1 2 3
// 4 5 6
// The Array is:
// 1 2 3 
// 4 5 6 



// Sum of rows and columns in array 
import java.util.Scanner;
class Arraysumrowscolum {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of rows : ");
        int r = sc.nextInt();

        System.out.print("Enter the number of columns : ");
        int c = sc.nextInt();

        int a[][] = new int[r][c];


        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                a[i][j] = sc.nextInt();
            }
        }

        System.out.println("Array is:");
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                System.out.print(a[i][j] + " ");
            }
            System.out.println();
        }

        for (int i = 0; i < r; i++) {
            int rowsum = 0;
            for (int j = 0; j < c; j++) {
                rowsum += a[i][j];
            }
            System.out.println("Sum of row " + (i + 1) + rowsum);
        }

        for (int j = 0; j < c; j++) {
            int colsum = 0;
            for (int i = 0; i < r; i++) {
                colsum += a[i][j];
            }
            System.out.println("Sum of column " +(j + 1)+ colsum);
        }
    }
}

// output ->>
// Enter the number of rows : 2
// Enter the number of columns : 3
// Enter the elements of the array:
// 1 2 3
// 4 5 6
// Array is:
// 1 2 3 
// 4 5 6 
// Sum of row 1 = 6
// Sum of row 2 = 15
// Sum of column 1 = 5
// Sum of column 2 = 7
// Sum of column 3 = 9



