/* DIGITAL SIGNATURE(S):
====================
List the author(s) of this code below:
Full name   
--------------------------- ----------------------------
Gurkirat Singh  
+--------------------------------------------------------+
| FILE NAME: C-SortingAlgorithm.c. |
+--------------------------------------------------------+
| 2 0 2 1 ~ Winter |
| PROG |
| 20799 |
| 
| |
| S H E R I D A N C O L L E G E |
| |
| !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! |
+--------------------------------------------------------+
----- I confirm that the following submitted work is my own written code and in my own words.-------
*/

#include <stdio.h>
#include<stdlib.h>
#include<string.h>


int quick = 0;    
int insert = 0;


int removeDuplicates(int arr[], int n);
void insertionSort(int arr[], int n);
void swap(int i, int j);
int partition (int arr[], int low, int high);
void quickSort(int arr[], int low, int high);




#include<stdio.h>



int main(int argc, char *argv[]){

   	  
  FILE *fp,*fp1;
	fp=fopen("numbers.txt","w");
	fp1=fopen("numbers.txt","r");

    int num1=15;
	int num2=5;
	int num3=7;
	int num4=9;
	int num5=20;
	int num6=3;
	int num7=2;
    int num8=1;
	int num9=25;
	int num10=15;
	int num11=30;
	int num12=3;
	int num13=5;
	int num14=7;
	int num15=9;
	int num16=15;
	int num17=4;
	int num18=7;
	
//Storing numbers in the file
	

		fprintf(fp,"%d\n",num1);
		fprintf(fp,"%d\n",num2);
		fprintf(fp,"%d\n",num3);
		fprintf(fp,"%d\n",num4);
		fprintf(fp,"%d\n",num5);
		fprintf(fp,"%d\n",num6);
		fprintf(fp,"%d\n",num7);
        fprintf(fp,"%d\n",num8);
        fprintf(fp,"%d\n",num9);
        fprintf(fp,"%d\n",num10);
	 fprintf(fp,"%d\n",num11);
	 fprintf(fp,"%d\n",num12);
	 fprintf(fp,"%d\n",num13);
	 fprintf(fp,"%d\n",num14);
	 fprintf(fp,"%d\n",num15);
	fprintf(fp,"%d\n",num16);
fprintf(fp,"%d\n",num17);
fprintf(fp,"%d\n",num18);	
		

//Storing values in the array
       int num[18]={num1,num2,num3,num4,num5,num6,num7,num8,num9,num10,num11,num12,num13,num14,num15,num16,num17,num18};
int size = sizeof(num) / sizeof(num[0]); 
	int arr2[18];

  for(int k=0;k<18;k++)       //we took another same array because we cannot sort the same array twice
    {
        arr2[k] = num[k];
    }

	   if(fp1 ==NULL){
		printf("Error opening file!");
		
		}

	   else{

//Reading the values in array stored in file

        for (int i=0; i<=17; i++){
			
			 fscanf(fp1, "%d", &num[i]);
                  }
		
//Printing the values that are read from file

		    printf("The numbers read from the file are: ");
		for (int i=0; i<=17; i++){
			
			 printf(" %d ",num[i]);

			}
		

         fclose(fp1);
		
		 }
    
    insertionSort(num,size );
    int newSize = removeDuplicates(num,size);  

    //Printing in descending using insertion
    printf("\n\nThe elements in the sorted order with insertion sort in descending order are: ");
    for(int i=0;i<newSize;i++)
    {
        printf(" %d ",num[i]);
    }



   printf("\nThe number of comparisions:  %d\n", insert);


    
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    quickSort(arr2,0,size2 - 1);
    int finalSize = removeDuplicates(arr2,size); 
    
    //Printing in descending using Quick

    printf("\nThe elements in the sorted order with quick sort in descending order are: ");
    for(int i=0;i<finalSize;i++)
    {
        printf(" %d ",arr2[i]);
    }
    printf("\nThe number of comparisions:  %d\n", quick);
    
    
       
}


//function for removing duplicates from an array

int removeDuplicates(int arr[], int n) 
{ 
  
  
    int temp[n]; 
    int j = 0; 
    for (int i=0; i<n-1; i++) 
  

        if (arr[i] != arr[i+1]) 
            temp[j++] = arr[i]; 
  

    temp[j++] = arr[n-1]; 

    for (int i=0; i<j; i++) 
        arr[i] = temp[i]; 
  
    return j; 
} 


//Method to sort numbers using Insert sort

void insertionSort(int num[], int no) 
{ 
    int i, key, j; 
    for (i = 1; i < no; i++) { 
        key = num[i]; 
        j = i - 1; 

        while (j >= 0 && num[j] < key) { 
            num[j + 1] = num[j]; 
            j = j - 1; 
            insert++;
        } 
        num[j + 1] = key; 
    } 
} 



//Method to sort numbers using Quick Sort
  
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int p = partition(arr, low, high); 
        
        quickSort(arr, low, p - 1); 
        quickSort(arr, p + 1, high); 
    } 
} 





void swap(int i, int j) 
{ 
    int temp = i; 
    i = j; 
    j = temp; 
}

//function to make partitions during quick sort

int partition (int arr[], int low, int high)  
{ 
    int pivot = arr[high];    
    int i = (low - 1);  
  
    for (int j = low; j <= high- 1; j++) 
    { 
       
        if (arr[j] > pivot) 
        { 
			
            i++;     
            swap(i, j); 
            quick++;
        } 
    } 
    swap(i + 1, pivot); 
    return (i + 1); 
} 
 



